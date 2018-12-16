#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#define N 10

//Прототипы функций

void choose_sort(LONGLONG *size, int *index, int n);
void insert_sort(LONGLONG *size, int *index, int n);
void bubble_sort(LONGLONG *size, int *index, int n);
void counting_sort(int *a, int n);
void quick_sort(LONGLONG *a, int *size, int first, int last);
void merge_sort(LONGLONG *size, int *index, int left, int right);
int file_counter(const wchar_t *sDir);
int file_reader(const wchar_t *sDir, LONGLONG *size);
void output(int *a, int n);

void main() {
    int mode = 0, n = 0, i;
	int *index;
	LONGLONG *size;

    setlocale(LC_ALL, "Russian");

	do {
		n = file_counter(L"c:\\Program Files\\Application Verifier\\");
	} while (n < 1);

	size = (LONGLONG*)malloc(n * sizeof(LONGLONG));
	index = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		index[i] = i;
	}
	
	file_reader(L"c:\\Program Files\\Application Verifier\\", size);

    printf("Выберите алгоритм сортировки ");

    do {
        scanf("%d", &mode);
    } while ((mode < 1) || (mode > 6));

    if (mode == 1) choose_sort(size, index, n);
    if (mode == 2) insert_sort(size, index, n);
    if (mode == 3) bubble_sort(size, index, n);
    if (mode == 4) counting_sort(size, n);
    if (mode == 5) quick_sort(size, index, 0, n - 1);
    if (mode == 6) merge_sort(size, index, 0, n - 1);

    output(index, n);
}

//Сортировки

void choose_sort(LONGLONG *size, int *index, int n) {
	int i, j, min, minindx, temp;
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
    int i, j, temp, swap;
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

void counting_sort(int *a, int n) {
    int *count;
    int i, j, d, min = a[0], max = a[0], index = 0;
    for (i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    d = (max - min) + 1;
    count = (int*)malloc(d * sizeof(int));
    for (i = 0; i < d; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[(a[i] - min)]++;
    }
    for (i = 0; i < d; i++) {
        for (j = 0; j < count[i]; j++) {
            a[index++] = i + min;
        }
    }
    free(count);
}

void quick_sort(LONGLONG *size, int *index, int first, int last) {
    int left = first, right = last, middle = size[index[(left + right) / 2]];
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

int file_counter(const wchar_t *sDir)
{
	int n = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Path not found: [%s]\n", sDir);
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

int file_reader(const wchar_t *sDir, LONGLONG *size)
{
	int i = 0;
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Path not found: [%s]\n", sDir);
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
			wprintf(L"File: %s Size: %d\n", sPath, fileSize);

			size[i++] = fileSize;
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return 0;
}

void output(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

