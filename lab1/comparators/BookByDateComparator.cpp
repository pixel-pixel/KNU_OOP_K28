#include "BookByDateComparator.h"

/**
     * @brief
     * Method which compare 2 Books by name.
     * @param   a   First Book.
     * @param   b   Second Book.
     * @return      if a.date == b.date -> 0, if a.date > b.date -> 1, else -> -1.
     */
int BookByDateComparator::compare(Book &a, Book &b) {
    return a.getDate() > b.getDate();
}