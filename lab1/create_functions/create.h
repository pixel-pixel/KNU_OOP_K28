#ifndef KNU_OOP_K28_CREATE_H
#define KNU_OOP_K28_CREATE_H

#include <string>
#include <vector>

int create_int_random(int);

double create_double_random(int);

std::string create_string_random(int);

template <typename T>
std::vector<T> create_vector_random(int);

#endif //KNU_OOP_K28_CREATE_H
