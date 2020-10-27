#ifndef KNU_OOP_K28_DEFAULTCOMPARATOR_H
#define KNU_OOP_K28_DEFAULTCOMPARATOR_H

#include "Comparator.h"

/**
 * @brief
 * Class implements the Comparator interface and compare object by operators.
 * @tparam  T   Class or primitive with override relational and equality operators.
 */
template<class T>
class DefaultComparator : public Comparator<T>{
public:

    /**
     * @brief
     * Method which compare 2 objects by relational and equality operators of objects.
     * @param   a   First object.
     * @param   b   Second object.
     * @return      if a == b -> 0, if a > b -> 1, else -> -1.
     */
    int compare(T &a, T &b) override {
        return a > b;
    }
};


#endif
