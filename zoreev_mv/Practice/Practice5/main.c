#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#define PATH_BUFFER 2048

//Прототипы функций

void choose_sort(LONGLONG *size, int *index, int n);
void insert_sort(LONGLONG *size, int *index, int n);
void bubble_sort(LONGLONG *size, int *index, int n);
void counting_sort(LONGLONG *size, int *index, int n);
void quick_sort(LONGLONG *size, int *index, int first, int last);
void merge_sort(LONGLONG *size, int *index, int left, int right);
int file_counter(const wchar_t *sDir);
int file_reader(const wchar_t *sDir, LONGLONG *size, char **name);
void printer(LONGLONG *size, wchar_t **name, int *index, int n, int mode);

void main() {
    int mode = 0, n = 0, i;
	int *index;
	LONGLONG *size;
    char *s_path = (char*)malloc(PATH_BUFFER*sizeof(char));
    wchar_t  *path = (wchar_t*)malloc((PATH_BUFFER)*sizeof(wchar_t));
    wchar_t  **name;

    setlocale(LC_ALL, "Russian");

    printf("Введите директорию\n");

	do {
        fgets(s_path, PATH_BUFFER, stdin);
        s_path[strlen(s_path) - 1] = '\0';
        swprintf(path, PATH_BUFFER, L"%hs", s_path);
		n = file_counter(path);
        if (n == 0) printf("Path is empty\n");
	} while (n < 1);

	size = (LONGLONG*)malloc(n * sizeof(LONGLONG));
	index = (int*)malloc(n * sizeof(int));
    name = (wchar_t**)malloc(n * sizeof(wchar_t*));
	for (i = 0; i < n; i++) {
		index[i] = i;
        name[i] = (wchar_t*)malloc(256 * sizeof(char));
        memset(name[i],0,256);
	}
	
	file_reader(path, size, name);

    do {
        printf("Для выбора соритровки введите цифру:\n");
        printf("Сортировка выбором      1\n");
        printf("Сортировка вставками    2\n");
        printf("Сортировка пузырьком    3\n");
        printf("Сортировка подсчётом    4\n");
        printf("Быстрая сортировка      5\n");
        printf("Сортировка слиянием     6\n");

        do {
            scanf("%d", &mode);
        } while ((mode < 1) || (mode > 6));

        system("cls");

        if (mode == 1) choose_sort(size, index, n);
        if (mode == 2) insert_sort(size, index, n);
        if (mode == 3) bubble_sort(size, index, n);
        if (mode == 4) counting_sort(size, index, n);
        if (mode == 5) quick_sort(size, index, 0, n - 1);
        if (mode == 6) merge_sort(size, index, 0, n - 1);

        printf("Чтобы сортировать по возрастанию введите    1\n");
        printf("Чтобы сортированть по убыванию введите      2\n"); 

        do {
            scanf("%d", &mode);
        } while ((mode != 1) && (mode != 2));

        system("cls");

        printer(size, name, index, n, mode);

        printf("\nЧтобы выбрать другую соритровку введите    1\n");
        printf("Чтобы выйти из программы введите           2\n");

        do {
            scanf("%d", &mode);
        } while ((mode != 1) && (mode != 2));

        system("cls");
         
    } while (mode != 2);

    free(index);
    free(size);
    free(s_path);
    free(*name);
    free(name);
}

//Сортировки

void choose_sort(LONGLONG *size, int *index, int n) {
	int i, j, minindx;
    LONGLONG min, temp;
	for (i = 0; i < n; i++) {
		min = size[index[i]];
		minindx = i;
		for (j = i + 1; j < n; j++) {
			if (size[index[j]] < min) {
				min = size[index[j]];
				minindx = j;
			}
		}
		temp = index[minindx];
		index[minindx] = index[i];
		index[i] = temp;
	}
}

void insert_sort(LONGLONG *size, int *index, int n) {
    int i, j, swap;
    LONGLONG temp;
    for (i = 1; i < n; i++) {
        temp = size[index[i]];
		swap = index[i];
        j = i - 1;
            while ((j >= 0) && (size[index[j]] > temp)) {
                index[j + 1] = index[j];
                index[j] = swap;
                j--;
            }
    }
}

void bubble_sort(LONGLONG *size, int *index, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (size[index[j - 1]] > size[index[j]]) {
                temp = index[j];
                index[j] = index[j - 1];
                index[j - 1] = temp;
            }
        }
    }
}

void counting_sort(LONGLONG *size, int *index, int n) {
    int *count;
    LONGLONG i, j, d, min = size[index[0]], max = size[index[0]], k = 0, s = 0;
    for (i = 1; i < n; i++) {
        if (size[i] > max) max = size[i];
        if (size[i] < min) min = size[i];
    }
    d = (max - min) + 1;
    if (d > 1024 * 1024 * 1024 * 2 / sizeof(int)) {
        system("cls");
        printf("Критическая ошибка выделения памяти\n");
        printf("Работа программы будет прекращена\n");
        exit;
    }
    count = (int*)malloc(d * sizeof(int));
    for (i = 0; i < d; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[(size[i] - min)]++;
    }
    for (i = 0; i < d; i++) {
        k = 0;
        for (j = 0; j < count[i]; j++) {
            while (size[k] != i + min) {
                k++;
            }
            index[s++] = k;
            k++;
        }
    }
    free(count);
}

void quick_sort(LONGLONG *size, int *index, int first, int last) {
    int left = first, right = last;
    LONGLONG middle = size[index[(left + right) / 2]];
    if (first < last) {
        do {
            while (size[index[left]] < middle) left++;
            while (size[index[right]] > middle) right--;
            if (left <= right) {
                int temp = index[left];
                index[left] = index[right];
                index[right] = temp;
                left++;
                right--;
            } 
        } while (left <= right);
        quick_sort(size, index, first, right);
        quick_sort(size, index, left, last);
    }
}

void merge_sort(LONGLONG *size,int *index, int left, int right) {
    int i = 0, j = 0, k = 0, length = (right - left + 1), middle;
    int *temp;
    if (left >= right) return;
    middle = (left + right) / 2;
    merge_sort(size, index, left, middle);
    merge_sort(size, index, middle + 1, right);
    temp = (int*)malloc(length * sizeof(int));
    i = left;
    j = middle + 1;
    while ((i <= middle) && (j <= right)) {
        if (size[index[i]] < size[index[j]]) {
            temp[k++] = index[i++];
        }
        else {
            temp[k++] = index[j++];
        }
    }
    while (i <= middle) {
            temp[k++] = index[i++];
    }
    while (j <= right) {
        temp[k++] = index[j++];
    }
    for (i = left; i <= right; i++) {
        index[i] = temp[i - left];
    }
    free(temp);
}

// Ввод-вывод

int file_counter(wchar_t *sDir)
{
	int n = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Путь не найден: [%s]\n", sPath);
		return -1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			n++;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return n;
}

int file_reader(const wchar_t *sDir, LONGLONG *size, char **name)
{
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Путь не найден: [%s]\n", sDir);
		return 1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;

			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(name[i], L"%s", fdFile.cFileName);
			size[i++] = fileSize;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return 0;
}

void printer(LONGLONG *size, wchar_t **name, int *index, int n, int mode) {
    int i = 0;
    if (mode == 1) {
        for (i = 0; i < n; i++) {
            wprintf(L"%s Размер: %lli\n", name[index[i]], size[index[i]]);
        }
    }
    else {
        for (i = n-1; i >= 0; i--) {
            wprintf(L"%s Размер: %lli\n", name[index[i]], size[index[i]]);
        }
    }
}