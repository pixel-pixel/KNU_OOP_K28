#ifndef KNU_OOP_K28_COMPARE_H
#define KNU_OOP_K28_COMPARE_H

#include "../lab_classes/Book.h"

/**
 * @brief
 * Function for compare elements reverse.
 * @tparam  T   Class or primitive with override at least operator <.
 * @return      If a < b -> 1, else -> 0.
 */
template <class T>
int compare_reverse(T &a, T &b){
    if(a == b) return 0;
    else return a < b;
};

/**
 * @brief
 * Function for compare Books by name.
 * @return      If a.name > b.name -> 1, else -> 0.
 */
int compare_book_by_name(Book &a, Book &b);

/**
 * @brief
 * Function for compare Books by date.
 * @return      If a.date > b.date -> 1, else -> 0.
 */
int compare_book_by_date(Book &a, Book &b);

#endif
