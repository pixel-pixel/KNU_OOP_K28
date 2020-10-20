#ifndef KNU_OOP_K28_MERGESORT_H
#define KNU_OOP_K28_MERGESORT_H

#include "Sort.h"

/**
 * @brief
 * Class implements Sort interface. It sort array by Marge sort.
 * @tparam  T   Class or primitive with override relational operators or have it own Comparator.
 */
template<class T>
class MergeSort : public Sort<T> {
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
    /**
     * @brief
     * Method for sort arrays by Merge sort by Comparator or relational operators(if point on Comparator == nullptr);
     * @param   arr         Array which we want to sort.
     * @param   size        Size of our array.
     * @param   comparator  Functional interface for compare 2 objects. DefaultComparator if not init.
     */
    void sort(T *arr, int size, Comparator<T> *comparator = new DefaultComparator<T>) override {
        sort_temp(arr, 0, size - 1, comparator);
    }
};


#endif
