//
// Created by andrew on 14.09.20.
//

#ifndef KNU_OOP_K28_SORTS_H
#define KNU_OOP_K28_SORTS_H

template<class T>
void bubble_sort(T *arr, int size) {
    T temp;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<class T>
void insertion_sort(T *arr, int size) {
    T key;
    int j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

template<class T>
void merge(T *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template<class T>
void merge_sort_temp(T *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort_temp(arr, l, m);
        merge_sort_temp(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

template<class T>
void merge_sort(T *arr, int size) {
    merge_sort_temp(arr, 0, size - 1);
}

template<class T>
int partition(T *arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<class T>
void quick_sort_temp(T *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort_temp(arr, low, pi - 1);
        quick_sort_temp(arr, pi + 1, high);
    }
}

template<class T>
void quick_sort(T *arr, int size) {
    quick_sort_temp(arr, 0, size - 1);
}

#endif //KNU_OOP_K28_SORTS_H
