#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Book.h"

using namespace std;

int main() {
    LinkedList<Book> kek;
    kek.remove(-1);
    cout << kek;

    return 0;
}
