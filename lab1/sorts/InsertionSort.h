#ifndef KNU_OOP_K28_INSERTIONSORT_H
#define KNU_OOP_K28_INSERTIONSORT_H

#include "Sort.h"

/**
 * @brief
 * Class implements Sort interface. It sort array by Insertion sort.
 * @tparam  T   Class or primitive with override relational operators or have it own Comparator.
 */
template <class T>
class InsertionSort : public Sort<T>{
public:
    /**
     * @brief
     * Method for sort arrays by Insertion sort by Comparator or relational operators(if point on Comparator == nullptr);
     * @param   arr         Array which we want to sort.
     * @param   size        Size of our array.
     * @param   comparator  Functional interface for compare 2 objects.
     */
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
