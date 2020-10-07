#ifndef KNU_OOP_K28_MERGESORT_H
#define KNU_OOP_K28_MERGESORT_H

#include "Sort.h"

template <class T>
class MergeSort : public Sort<T>{
private:
    void merge(T *arr, int l, int m, int r, Comparator<T> *comparator) {
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

        if (comparator == nullptr) {
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
        } else {
            while (i < n1 && j < n2) {
                if (comparator->compare(L[i], R[j]) <= 0) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
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

    void sort_temp(T *arr, int l, int r, Comparator<T> *comparator) {
        if (l < r) {
            int m = l + (r - l) / 2;

            sort_temp(arr, l, m, comparator);
            sort_temp(arr, m + 1, r, comparator);

            merge(arr, l, m, r, comparator);
        }
    }

public:
    void sort(T *arr, int size, Comparator<T> *comparator) override {
        sort_temp(arr, 0, size - 1, comparator);
    }
};


#endif
