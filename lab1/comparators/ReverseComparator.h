#ifndef KNU_OOP_K28_REVERSECOMPARATOR_H
#define KNU_OOP_K28_REVERSECOMPARATOR_H

#include "Comparator.h"

template <class T>
class ReverseComparator : public Comparator<T>{
public:
    int compare(T &a, T &b) override {
        if(a == b) return 0;
        else return a < b;
    }
};

#endif
