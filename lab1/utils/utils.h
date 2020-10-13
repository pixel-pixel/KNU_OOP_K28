#ifndef KNU_OOP_K28_UTILS_H
#define KNU_OOP_K28_UTILS_H

#include <vector>
#include <ostream>
#include <sstream>

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

template <class T>
std::string to_list_string(T *a,
                           T *b = nullptr,
                           T *c = nullptr,
                           T *d = nullptr,
                           T *e = nullptr,
                           T *f = nullptr,
                           T *g = nullptr,
                           T *h = nullptr,
                           T *i = nullptr,
                           T *j = nullptr){
    std::stringstream ss;

    ss << '[' << *a;
    if(b != nullptr) ss << ", " << *b;
    if(c != nullptr) ss << ", " << *c;
    if(d != nullptr) ss << ", " << *d;
    if(e != nullptr) ss << ", " << *e;
    if(f != nullptr) ss << ", " << *f;
    if(g != nullptr) ss << ", " << *g;
    if(h != nullptr) ss << ", " << *h;
    if(i != nullptr) ss << ", " << *i;
    if(j != nullptr) ss << ", " << *j;
    ss << ']';

    return ss.str();
}

#endif //KNU_OOP_K28_UTILS_H
