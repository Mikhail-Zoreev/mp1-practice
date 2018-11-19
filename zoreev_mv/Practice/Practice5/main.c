#include <stdio.h>
#include <locale.h>
#define N 10
#define K 5

int min = 0, max = 0;

//Сортировки

void choose_sort(int a[], int n) {
    int i, j, min, minindx;
    for (i = 0; i < n; i++) {
        min = a[i];
        minindx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                minindx = j;
            }
        }
        a[minindx] = a[i];
        a[i] = min;
    }
}

void insert_sort(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
            while ((j >= 0) && (a[j] > temp)) {
                a[j + 1] = a[j];
                a[j] = temp;
                j--;
            }
    }
}

void bubble_sort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

/*void  counting_sort(int a[], int n) {
    int count[K] = { 0 }, i, j, indx = 0;
    for (i = 0; i < n; i++) {
        count[a[i]]++;
    }
    for (i = 0; i < K; i++) {
        for (j = 0; j < count[i]; j++) {
            a[indx++] = i;
        }
    }
}*/

void counting_sort(int a[], int n) {
    int count[K] = { 0 }, i, j, min = a[0], max = a[0], index = 0;
    for (i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    for (i = 0; i < n; i++) {
        count[(a[i] - min)]++;
    }
    for (i = 0; i < (max - min); i++) {
        for (j = 0; j < count[i]; j++) {
            a[index++] = i + min;
        }
    }
}

// Ввод-вывод

void input(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void output(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void main() {
    int a[N], mode;
    setlocale(LC_ALL, "Russian");
    
    input(a, N);
    
    printf("Выберите алгоритм сортировки ");

    do {
        scanf("%d", &mode);
    } while ((mode < 0) || (mode > 4));

    if (mode == 1) choose_sort(a, N);
    if (mode == 2) insert_sort(a, N);
    if (mode == 3) bubble_sort(a, N);
    if (mode == 4) counting_sort(a, N);

    output(a, N);
}