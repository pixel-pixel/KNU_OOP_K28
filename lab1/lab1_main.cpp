#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Book.h"
#include "Sorts.h"

using namespace std;

int main() {
    LinkedList<Book> kek;
    kek.add(new Book("e", 16, "wf"));
    kek.add(new Book("c", 12, "wf"));
    kek.add(new Book("a", 1, "wf"));
    kek.add(new Book("b", 17, "wf"));
    kek.add(new Book("d", 4, "wf"));
    kek.sort(quick_sort, compare_book_by_name);
    cout << kek;

    return 0;
}
