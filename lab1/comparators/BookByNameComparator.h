#ifndef KNU_OOP_K28_BOOKBYNAMECOMPARATOR_H
#define KNU_OOP_K28_BOOKBYNAMECOMPARATOR_H

#include "Comparator.h"
#include "../lab_classes/Book.h"

class BookByNameComparator : public Comparator<Book>{
public:
    int compare(Book &a, Book &b) override;
};


#endif
