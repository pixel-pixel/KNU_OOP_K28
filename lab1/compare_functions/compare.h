#ifndef KNU_OOP_K28_COMPARE_H
#define KNU_OOP_K28_COMPARE_H

#include "../lab_classes/Book.h"

template <class T>
int compare_reverse(T &a, T &b){
    if(a == b) return 0;
    else return a < b;
};

int compare_book_by_name(Book &, Book &);

int compare_book_by_date(Book &, Book &);



#endif
