#include "BookByDateComparator.h"

int BookByDateComparator::compare(Book &a, Book &b) {
    return a.getDate() > b.getDate();
}