#include "utils/doctest.h"
#include "utils/utils.h"

#include "library/Series.h"
#include "lists/ArrayList.h"
#include "list_generators/ListGenerator.h"
#include "UI/TerminalUI.h"


namespace lab1 {
    /**
     * @brief
     * Function which run unit tests.
     */
    int doctest() {
        doctest::Context context;
        return context.run();
    }

    /**
     * @brief
     * Lab1 main function.
     */
    int main() {
        doctest();
        TerminalUI terminalUi;
        terminalUi.start();

//        Book a("War and God", 2000, "about war and Gods", "1995.11.07", "lev Tolstoi");
//        Book b("Kozaki", 129, "about us", "2020", "Sergii", "Andrii");
//        Book c("ARF", 127, "none");
//        Book d("lol", 1);
//
//        Character andrii("Andrii", "Andr");
//        andrii.add_role(Character::Role(&a, Character::Role::MAIN));
//        andrii.add_role(Character::Role(&c, Character::Role::MINOR));
//        andrii.add_role(Character::Role(&d, Character::Role::EPISODIC));
//
//        Series ser0(andrii);
//        ser0.add_book(d);
//        ser0.add_book(b);
//        ser0.add_book(c);
//        std::cout << ser0 << std::endl;
//
//        Series ser;
//        ser.add_book(a);
//        ser.add_book(c);
//        ser.add_book(d);
//
//        Series ser2;
//        ser2.add_book(a);
//        ser2.add_book(b);
//
//        Series ser3;
//        ser3.add_book(d);
//
//        LinkedList<Series> list;
//        list.add(ser);
//        list.add(ser2);
//        list.add(ser3, 0);
//
//        list.sort();
//        std::cout << list << std::endl;
//        return 0;
    }
}



