#ifndef KNU_OOP_K28_QUICKSORT_H
#define KNU_OOP_K28_QUICKSORT_H

#include <algorithm>
#include "Sort.h"

/**
 * @brief
 * Class implements Sort interface. It sort array by Quick sort.
 * @tparam  T   Class or primitive with override relational operators or have it own Comparator.
 */
template<class T>
class QuickSort : public Sort<T> {
private:
    int partition(T *arr, int low, int high, Comparator<T> *comparator) {
        T pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (comparator->compare(pivot, arr[j]) == 1) {
                i++;
                std::swap(arr[i], arr[j]);
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
    /**
     * @brief
     * Method for sort arrays by Quick sort by Comparator or relational operators(if point on Comparator == nullptr);
     * @param   arr         Array which we want to sort.
     * @param   size        Size of our array.
     * @param   comparator  Functional interface for compare 2 objects. DefaultComparator if not init.
     */
    void sort(T *arr, int size, Comparator<T> *comparator = new DefaultComparator<T>) override {
        sort_temp(arr, 0, size - 1, comparator);
    }
};


#endif
