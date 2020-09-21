#include "compare_book.h"

int compare_book_by_name(Book &obj1, Book &obj2){
    if(obj1.getName() == obj2.getName()) return 0;
    else return obj1.getName() > obj2.getName();
}

