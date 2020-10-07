#ifndef KNU_OOP_K28_INSERTIONSORT_H
#define KNU_OOP_K28_INSERTIONSORT_H

#include "Sort.h"

template <class T>
class InsertionSort : public Sort<T>{
public:
    void sort(T *arr, int size, Comparator<T> *comparator) override {
        T key;
        int j;

        if (comparator == nullptr) {
            for (int i = 1; i < size; i++) {
                key = arr[i];
                j = i;
                while (j > 0 && arr[j - 1] > key) {
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[j] = key;
            }
        } else {
            for (int i = 1; i < size; i++) {
                key = arr[i];
                j = i;
                while (j > 0 && comparator->compare(arr[j - 1], key) == 1) {
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[j] = key;
            }
        }
    }
};


#endif
