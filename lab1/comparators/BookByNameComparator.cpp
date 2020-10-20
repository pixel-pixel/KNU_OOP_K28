#include "BookByNameComparator.h"

/**
     * @brief
     * Method which compare 2 Books by name.
     * @param   a   First Book.
     * @param   b   Second Book.
     * @return      if a.name == b.name -> 0, if a.name > b.name -> 1, else -> -1.
     */
int BookByNameComparator::compare(Book &a, Book &b) {
    return a.getName() > b.getName();
}