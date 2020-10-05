#ifndef KNU_OOP_K28_CREATE_H
#define KNU_OOP_K28_CREATE_H

#include <string>
#include <vector>

/**
 * @brief
 * Function for Lists constructor which create random int.
 * @param   index   Index need for random.
 * @return          Random int [0..99].
 */
int create_int_random(int);

/**
 * @brief
 * Function for Lists constructor which create random double.
 * @param   index   Index need for random.
 * @return          Random double [0..99].
 */
double create_double_random(int);

/**
 * @brief
 * Function for Lists constructor which create random std::string.
 * @param   index   Index need for random.
 * @return          Random std::string. Length: [0..99].
 */
std::string create_string_random(int);

/**
 * @brief
 * Function for Lists constructor which create random std::vector<int>.
 * @param   index   Index need for random.
 * @return          Random std::vector<int>. Size: [0..20], number: [0..99].
 */
std::vector<int> create_vector_int_random(int);

#endif //KNU_OOP_K28_CREATE_H
