#ifndef KNU_OOP_K28_COMPARATOR_H
#define KNU_OOP_K28_COMPARATOR_H

template<class T>
class Comparator {
public:
    virtual int compare(T &a, T& b) = 0;
};

#endif
