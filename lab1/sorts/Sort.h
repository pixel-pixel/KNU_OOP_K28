#ifndef KNU_OOP_K28_SORT_H
#define KNU_OOP_K28_SORT_H

#include "../comparators/Comparator.h"

template <class T>
class Sort {
public:
    virtual void sort(T* arr, int size, Comparator<T> *comparator = nullptr) = 0;
};


#endif
