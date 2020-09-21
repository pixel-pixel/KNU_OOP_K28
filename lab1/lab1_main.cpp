#include <iostream>
#include <string>
#include "lists/LinkedList.h"
#include "lists/ArrayList.h"
#include "lab_classes/Book.h"
#include "sorts/Sorts.h"
#include "lists/VectorList.h"
#include "compare_functions/compare_book.h"

using namespace std;

int main() {
    VectorList<Book> kek;
    kek.add(new Book("e", 16, "wf"));
    kek.add(new Book("c", 12, "wf"));
    kek.add(new Book("a", 1, "wf"));
    kek.add(new Book("b", 17, "wf"));
    kek.add(new Book("d", 4, "wf"), 4);
    kek.sort(bubble_sort, compare_book_by_name);
    cout << kek;

    return 0;
}
