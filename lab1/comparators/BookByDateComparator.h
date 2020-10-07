#ifndef KNU_OOP_K28_BOOKBYDATECOMPARATOR_H
#define KNU_OOP_K28_BOOKBYDATECOMPARATOR_H

#include "Comparator.h"
#include "../lab_classes/Book.h"

class BookByDateComparator : public Comparator<Book> {
public:
    int compare(Book &a, Book &b) override;
};


#endif
