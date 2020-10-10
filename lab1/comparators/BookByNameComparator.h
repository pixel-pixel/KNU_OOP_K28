#ifndef KNU_OOP_K28_BOOKBYNAMECOMPARATOR_H
#define KNU_OOP_K28_BOOKBYNAMECOMPARATOR_H

#include "Comparator.h"
#include "../lab_classes/Book.h"

/**
 * @brief
 * Class implements the Comparator interface and compare Books by name.
 */
class BookByNameComparator : public Comparator<Book>{
public:
    /**
     * @brief
     * Method which compare 2 Books by name.
     * @param   a   First Book.
     * @param   b   Second Book.
     * @return      if a.name == b.name -> 0, if a.name > b.name -> 1, else -> -1.
     */
    int compare(Book &a, Book &b) override;
};

#endif