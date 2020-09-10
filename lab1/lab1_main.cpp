#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Book.h"

using namespace std;

int main() {
    LinkedList<Book> kek;
    kek.add(new Book("kek", 15, "huinya"));
    kek.add(new Book("kel", 15, "huinya"));
    kek.add(new Book("lol", 15, "huinya"));
    kek.remove(-1);
    cout << kek;

    return 0;
}
