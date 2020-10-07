#ifndef KNU_OOP_K28_QUICKSORT_H
#define KNU_OOP_K28_QUICKSORT_H

#include <algorithm>
#include "Sort.h"

template <class T>
class QuickSort : public Sort<T>{
private:
    int partition(T *arr, int low, int high, Comparator<T> *comparator) {
        T pivot = arr[high];
        int i = (low - 1);

        if (comparator == nullptr) {
            for (int j = low; j <= high - 1; j++) {
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
        } else {
            for (int j = low; j <= high - 1; j++) {
                if (comparator->compare(pivot, arr[j]) == 1) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
        }

        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }


    void sort_temp(T *arr, int low, int high, Comparator<T> *comparator) {
        if (low < high) {
            int pi = partition(arr, low, high, comparator);

            sort_temp(arr, low, pi - 1, comparator);
            sort_temp(arr, pi + 1, high, comparator);
        }
    }

public:
    void sort(T *arr, int size, Comparator<T> *comparator) override {
        sort_temp(arr, 0, size - 1, comparator);
    }
};


#endif
