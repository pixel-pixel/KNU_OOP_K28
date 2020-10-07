#ifndef KNU_OOP_K28_BUBBLESORT_H
#define KNU_OOP_K28_BUBBLESORT_H

#include "Sort.h"

template <class T>
class BubbleSort : public Sort<T>{
public:
private:
    void sort(T *arr, int size, Comparator<T> *comparator) override {
        T temp;

        if (comparator == nullptr) {
            for (int i = 1; i < size; i++) {
                for (int j = 0; j < size - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        } else {
            for (int i = 1; i < size; i++) {
                for (int j = 0; j < size - i; j++) {
                    if (comparator->compare(arr[j], arr[j + 1]) == 1) {
                        temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
    }
};


#endif
