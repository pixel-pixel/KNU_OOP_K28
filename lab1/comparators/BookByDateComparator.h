#ifndef KNU_OOP_K28_BOOKBYDATECOMPARATOR_H
#define KNU_OOP_K28_BOOKBYDATECOMPARATOR_H

#include "Comparator.h"
#include "../lab_classes/Book.h"

/**
 * @brief
 * Class implements the Comparator interface and compare Books by date.
 */
class BookByDateComparator : public Comparator<Book> {
public:
    /**
     * @brief
     * Method which compare 2 Books by name.
     * @param   a   First Book.
     * @param   b   Second Book.
     * @return      if a.date == b.date -> 0, if a.date > b.date -> 1, else -> -1.
     */
    int compare(Book &a, Book &b) override;
};

#endif