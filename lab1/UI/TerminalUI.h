#ifndef KNU_OOP_K28_TERMINALUI_H
#define KNU_OOP_K28_TERMINALUI_H

#include <iostream>
#include "../lists/List.h"
#include "../lists/ArrayList.h"
#include "../lists/LinkedList.h"
#include "../lists/VectorList.h"
#include "../list_generators/ListGenerator.h"
#include "../library/Book.h"
#include "../library/Character.h"
#include "../library/Series.h"
#include "../sorts/BubbleSort.h"
#include "../sorts/InsertionSort.h"
#include "../sorts/MergeSort.h"
#include "../sorts/QuickSort.h"
#include "../comparators/ReverseComparator.h"

class TerminalUI {
private:
    const char *msg_type_in_list = "---Choose type in List...\n"
                                   "(new List<...>)\n"
                                   "[1] int\n"
                                   "[2] double\n"
                                   "[3] std::string\n"
                                   "[4] std::vector<int>\n"
                                   "[5] Book\n"
                                   "[6] Character\n"
                                   "[7] Series";

    const char *msg_list_type = "---Choose type of List---\n"
                                "(List *list = new ...)\n"
                                "[1] ArrayList\n"
                                "[2] LinkedList\n"
                                "[3] VectorList";

    const char *msg_what_you_want = "---Choose what you want---\n"
                                    "(list...())\n"
                                    "[1] Generate random objects\n"
                                    "[2] Add object\n"
                                    "[3] Remove object\n"
                                    "[4] Get object by index\n"
                                    "[5] Get index of object(find object)\n"
                                    "[6] Clear the list\n"
                                    "[7] Sort list\n"
                                    "[8] Print the list\n"
                                    "[-1] Exit";

    const char *msg_sorts = "---Choose sort---\n"
                            "[1] BubbleSort\n"
                            "[2] InsertionSort\n"
                            "[3] MergeSort\n"
                            "[4] QuickSort";

    const char *msg_comparators = "---Choose comparator---\n"
                                  "[1] Default\n"
                                  "[2] Reverse";

    const char *msg_count_of_random_objects = "Enter count of random objects you want to add:";

    const char *msg_add_object = "Enter the object:";

    const char *msg_add_object_index = "Enter an index of this object(-1 -> push to end):";

    const char *msg_remove = "Enter the index of object(-1 -> remove last):";

    const char *msg_get_object = "Enter the index of object you want(-1 -> the last):";

    const char *msg_find = "Enter the object witch index you want:";

    const char *msg_clear_the_list = "Now List is empty.";

    const char *msg_print = "Your list:";

    ListGenerator generator;

    void work_with_int_list();

    void work_with_double_list();

    void work_with_string_list();

    void work_with_vector_list();
//
//    void work_with_Book_list(int list_type);
//
//    void work_with_Character_list(int list_type);



public:
    void start();


};


#endif
