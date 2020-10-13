#include "BookByNameComparator.h"

int BookByNameComparator::compare(Book &a, Book &b) {
    return a.getName() > b.getName();
}