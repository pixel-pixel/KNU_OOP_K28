#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Book.h"
#include "Sorts.h"

using namespace std;

int main() {
    LinkedList<Book> kek;
    kek.add(new Book("kek", 16, "wf"));
    kek.add(new Book("lol", 12, "wf"));
    kek.add(new Book("lyk", 1, "wf"));
    kek.add(new Book("lyl", 17, "wf"));
    kek.add(new Book("kyk", 4, "wf"));
    kek.sort_by(quick_sort);
    cout << kek;

    return 0;
}
