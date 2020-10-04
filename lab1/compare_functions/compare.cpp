#include "compare.h"

int compare_book_by_name(Book &obj1, Book &obj2) {
    if (obj1.getName() == obj2.getName()) return 0;
    else return obj1.getName() > obj2.getName();
}

int compare_book_by_date(Book &book1, Book &book2){
    return book1.getDate() > book2.getDate();
}

