#ifndef KNU_OOP_K28_REVERSECOMPARATOR_H
#define KNU_OOP_K28_REVERSECOMPARATOR_H

#include "Comparator.h"

/**
 * @brief
 * Class implements the Comparator interface and compare object reverse.
 * @tparam  T   Class or primitive with override relational and equality operators.
 */
template <class T>
class ReverseComparator : public Comparator<T>{
public:
    /**
     * @brief
     * Method which compare 2 objects reverse by relational and equality operators of objects.
     * @param   a   First object.
     * @param   b   Second object.
     * @return      if a == b -> 0, if a > b -> 1, else -> -1.
     */
    int compare(T &a, T &b) override {
        if(a == b) return 0;
        else return a < b;
    }
};

#endif
