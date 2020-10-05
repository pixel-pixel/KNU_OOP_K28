#ifndef KNU_OOP_K28_UTILS_H
#define KNU_OOP_K28_UTILS_H

#include <vector>
#include <ostream>

template <class T>
std::ostream &operator<<(std::ostream &out, std::vector<T> &vect){
    out << '{';
    if (vect.size() != 0) {
        for (int i = 0; i < vect.size() - 1; i++) {
            out << vect[i] << ", ";
        }
        out << vect[vect.size() - 1];
    }
    out << '}';
}

#endif //KNU_OOP_K28_UTILS_H
