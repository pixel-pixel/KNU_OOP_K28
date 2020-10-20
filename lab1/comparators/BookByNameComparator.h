#ifndef KNU_OOP_K28_BOOKBYNAMECOMPARATOR_H
#define KNU_OOP_K28_BOOKBYNAMECOMPARATOR_H

#include "Comparator.h"
#include "../library/Book.h"

/**
 * @brief
 * Class implements the Comparator interface and compare Books by name.
 */
class BookByNameComparator : public Comparator<Book>{
public:
    /**
     * @brief
     * Method which compare 2 Books by name.
     */
    int compare(Book &a, Book &b) override;
};

#endif