#ifndef KNU_OOP_K28_COMPARATOR_H
#define KNU_OOP_K28_COMPARATOR_H

/**
 * @brief
 * Functional interface for compare 2 objects.
 * @tparam  T   Class or primitive.
 */
template<class T>
class Comparator {
public:
    /**
     * @brief
     * Method which compare 2 objects.
     * @param   a   First object.
     * @param   b   Second object.
     * @return      If a == b -> 0, if a > b -> 1, else -> -1.
     */
    virtual int compare(T &a, T& b) = 0;
};

#endif