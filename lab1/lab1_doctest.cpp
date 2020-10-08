#define DOCTEST_CONFIG_IMPLEMENT

#include "utils/doctest.h"
#include "utils/utils.h"

#include "lists/ArrayList.h"
#include "lists/LinkedList.h"
#include "lists/VectorList.h"

#include "sorts/BubbleSort.h"
#include "sorts/InsertionSort.h"
#include "sorts/MergeSort.h"
#include "sorts/QuickSort.h"

#include "comparators/ReverseComparator.h"
#include "list_generators/ListGenerator.h"

#include "lab_classes/Book.h"
#include "lab_classes/Character.h"
#include "lab_classes/Series.h"

TEST_CASE ("Integer Lists") {
#define TYPE int

    List<TYPE> *list;
    std::stringstream ss;

    TYPE zero = 0;
    TYPE one = 1;
    TYPE two = 2;
    TYPE three = 3;
    TYPE four = 4;
    TYPE five = 5;
    TYPE six = 6;
    TYPE seven = 7;
    TYPE eight = 8;

            SUBCASE("ArrayList") {
        list = new ArrayList<TYPE>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<TYPE>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<TYPE>;
    }

            CHECK(list->get_size() == 0);
    ListGenerator::random_int(10, list);

            CHECK(list->get_size() == 10);
            CHECK( list->to_string() != "[]");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

    CHECK(list->find(zero) == -1);

    list->add(four);
    list->add(two);
    list->add(one);
            CHECK( list->to_string() == to_list_string(&four, &two, &one));

    list->add(three, 1);
            CHECK( list->to_string() == to_list_string(&four,&three, &two, &one));

    list->add(five, -1); //when index < 0 -> index = last
    list->add(six, 2);
    list->add(seven, 0);
    list->add(eight, -5);
            CHECK( list->to_string() == to_list_string(&seven, &four, &three, &six, &two, &one, &five, &eight));

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
            CHECK( list->to_string() == to_list_string(&four, &three, &two, &one, &five));

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == four);
            CHECK(list->get(2) == two);
            CHECK(list->get(-1) == five);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(four) == 0);
            CHECK(list->find(two) == 2);
            CHECK(list->find(five) == 4);
            CHECK(list->find(eight) == -1);

            CHECK_THROWS_AS(list->add(zero, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Double Lists") {
#define TYPE double

    List<TYPE> *list;
    std::stringstream ss;

    TYPE zero = 0.1;
    TYPE one = 1.1;
    TYPE two = 2.2;
    TYPE three = 3.3;
    TYPE four = 4.4;
    TYPE five = 5.5;
    TYPE six = 6.6;
    TYPE seven = 7.7;
    TYPE eight = 8.8;

            SUBCASE("ArrayList") {
        list = new ArrayList<TYPE>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<TYPE>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<TYPE>;
    }

            CHECK(list->get_size() == 0);
    ListGenerator::random_double(10, list);

            CHECK(list->get_size() == 10);
            CHECK( list->to_string() != "[]");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

    CHECK(list->find(zero) == -1);

    list->add(four);
    list->add(two);
    list->add(one);
            CHECK( list->to_string() == to_list_string(&four, &two, &one));

    list->add(three, 1);
            CHECK( list->to_string() == to_list_string(&four,&three, &two, &one));

    list->add(five, -1); //when index < 0 -> index = last
    list->add(six, 2);
    list->add(seven, 0);
    list->add(eight, -5);
            CHECK( list->to_string() == to_list_string(&seven, &four, &three, &six, &two, &one, &five, &eight));

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
            CHECK( list->to_string() == to_list_string(&four, &three, &two, &one, &five));

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == four);
            CHECK(list->get(2) == two);
            CHECK(list->get(-1) == five);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(four) == 0);
            CHECK(list->find(two) == 2);
            CHECK(list->find(five) == 4);
            CHECK(list->find(eight) == -1);

            CHECK_THROWS_AS(list->add(zero, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("String lists") {
#define TYPE std::string

    List<TYPE> *list;
    std::stringstream ss;

    TYPE zero = "0";
    TYPE one = "a";
    TYPE two = "b";
    TYPE three = "c";
    TYPE four = "d";
    TYPE five = "e";
    TYPE six = "f";
    TYPE seven = "g";
    TYPE eight = "h";

            SUBCASE("ArrayList") {
        list = new ArrayList<TYPE>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<TYPE>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<TYPE>;
    }

            CHECK(list->get_size() == 0);
    ListGenerator::random_string(10, list);

            CHECK(list->get_size() == 10);
            CHECK( list->to_string() != "[]");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find(zero) == -1);

    list->add(four);
    list->add(two);
    list->add(one);
            CHECK( list->to_string() == to_list_string(&four, &two, &one));

    list->add(three, 1);
            CHECK( list->to_string() == to_list_string(&four,&three, &two, &one));

    list->add(five, -1); //when index < 0 -> index = last
    list->add(six, 2);
    list->add(seven, 0);
    list->add(eight, -5);
            CHECK( list->to_string() == to_list_string(&seven, &four, &three, &six, &two, &one, &five, &eight));

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
            CHECK( list->to_string() == to_list_string(&four, &three, &two, &one, &five));

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == four);
            CHECK(list->get(2) == two);
            CHECK(list->get(-1) == five);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(four) == 0);
            CHECK(list->find(two) == 2);
            CHECK(list->find(five) == 4);
            CHECK(list->find(eight) == -1);

            CHECK_THROWS_AS(list->add(zero, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Vector Lists") {
#define TYPE std::vector<int>

    List<TYPE> *list;
    std::stringstream ss;

    TYPE zero = {};
    TYPE one = {1};
    TYPE two = {2, 2};
    TYPE three = {3, 3, 3};
    TYPE four = {4, 4, 4, 4};
    TYPE five = {5, 5, 5, 5, 5};
    TYPE six = {6, 6, 6, 6, 6, 6};
    TYPE seven = {7, 7, 7, 7, 7, 7, 7};
    TYPE eight = {8, 8, 8, 8, 8, 8, 8, 8};

            SUBCASE("ArrayList") {
        list = new ArrayList<TYPE>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<TYPE>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<TYPE>;
    }

            CHECK(list->get_size() == 0);
    ListGenerator::random_vector_int(10, list);

            CHECK(list->get_size() == 10);
            CHECK( list->to_string() != "[]");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find(zero) == -1);

    list->add(four);
    list->add(two);
    list->add(one);
            CHECK( list->to_string() == to_list_string(&four, &two, &one));

    list->add(three, 1);
            CHECK( list->to_string() == to_list_string(&four,&three, &two, &one));

    list->add(five, -1); //when index < 0 -> index = last
    list->add(six, 2);
    list->add(seven, 0);
    list->add(eight, -5);
            CHECK( list->to_string() == to_list_string(&seven, &four, &three, &six, &two, &one, &five, &eight));

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
            CHECK( list->to_string() == to_list_string(&four, &three, &two, &one, &five));

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == four);
            CHECK(list->get(2) == two);
            CHECK(list->get(-1) == five);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(four) == 0);
            CHECK(list->find(two) == 2);
            CHECK(list->find(five) == 4);
            CHECK(list->find(eight) == -1);

            CHECK_THROWS_AS(list->add(zero, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Book lists") {
#define TYPE Book
    
    List<TYPE> *list;
    std::stringstream ss;

    TYPE zero("0");
    TYPE one("1one", 111, "The first");
    TYPE two("2two", 222);
    TYPE three("3Three", 333, "three3", "1992.12.12");
    TYPE four("4four", 444, "four4", "0444.04.04", "4our");
    TYPE five("5fiVE", 5);
    TYPE six("6SIX", 666, "sssix", "2006.06.16");
    TYPE seven("7Seven", 77);
    TYPE eight("8Eight", 888);

            SUBCASE("ArrayList") {
        list = new ArrayList<TYPE>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<TYPE>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<TYPE>;
    }

            CHECK(list->get_size() == 0);
    ListGenerator::random_book(10, list);

            CHECK(list->get_size() == 10);
            CHECK( list->to_string() != "[]");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

    CHECK(list->find(zero) == -1);

    list->add(four);
    list->add(two);
    list->add(one);
            CHECK( list->to_string() == to_list_string(&four, &two, &one));

    list->add(three, 1);
            CHECK( list->to_string() == to_list_string(&four,&three, &two, &one));

    list->add(five, -1); //when index < 0 -> index = last
    list->add(six, 2);
    list->add(seven, 0);
    list->add(eight, -5);
            CHECK( list->to_string() == to_list_string(&seven, &four, &three, &six, &two, &one, &five, &eight));

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
            CHECK( list->to_string() == to_list_string(&four, &three, &two, &one, &five));

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == four);
            CHECK(list->get(2) == two);
            CHECK(list->get(-1) == five);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(four) == 0);
            CHECK(list->find(two) == 2);
            CHECK(list->find(five) == 4);
            CHECK(list->find(eight) == -1);

            CHECK_THROWS_AS(list->add(zero, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Character lists") {
#define TYPE Character

    List<TYPE> *list;
    std::stringstream ss;

    TYPE zero("0Zero");
    TYPE one("1One");
    TYPE two("2Two");
    TYPE three("3Three");
    TYPE four("4Four");
    TYPE five("5Five");
    TYPE six("6Six");
    TYPE seven("7Seven");
    TYPE eight("8Eight");

            SUBCASE("ArrayList") {
        list = new ArrayList<TYPE>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<TYPE>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<TYPE>;
    }

            CHECK(list->get_size() == 0);
    ListGenerator::random_character(10, list);

            CHECK(list->get_size() == 10);
            CHECK( list->to_string() != "[]");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find(zero) == -1);

    list->add(four);
    list->add(two);
    list->add(one);
            CHECK( list->to_string() == to_list_string(&four, &two, &one));

    list->add(three, 1);
            CHECK( list->to_string() == to_list_string(&four,&three, &two, &one));

    list->add(five, -1); //when index < 0 -> index = last
    list->add(six, 2);
    list->add(seven, 0);
    list->add(eight, -5);
            CHECK( list->to_string() == to_list_string(&seven, &four, &three, &six, &two, &one, &five, &eight));

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
            CHECK( list->to_string() == to_list_string(&four, &three, &two, &one, &five));

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == four);
            CHECK(list->get(2) == two);
            CHECK(list->get(-1) == five);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(four) == 0);
            CHECK(list->find(two) == 2);
            CHECK(list->find(five) == 4);
            CHECK(list->find(eight) == -1);

            CHECK_THROWS_AS(list->add(zero, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Series lists") {
#define TYPE Series

    List<TYPE> *list;
    std::stringstream ss;

    Book bookZero("0");
    Book bookOne("1one", 111, "The first");
    Book bookTwo("2two", 222);
    Book bookThree("3Three", 333, "three3", "1992.12.12");
    Book bookFour("4four", 444, "four4", "0444.04.04", "4our");
    Book bookFive("5fiVE", 5);
    Book bookSix("6SIX", 666, "sssix", "2006.06.16");
    Book bookSeven("7Seven", 77);
    Book bookEight("8Eight", 888);

    TYPE zero;
    TYPE one;
    one.add_book(bookOne);
    TYPE two;
    two.add_book(bookOne);
    two.add_book(bookTwo);
    TYPE three;
    three.add_book(bookOne);
    three.add_book(bookTwo);
    three.add_book(bookThree);
    TYPE four;
    four.add_book(bookOne);
    four.add_book(bookTwo);
    four.add_book(bookThree);
    four.add_book(bookFour);
    TYPE five;
    five.add_book(bookOne);
    five.add_book(bookTwo);
    five.add_book(bookThree);
    five.add_book(bookFour);
    five.add_book(bookFive);
    TYPE six;
    six.add_book(bookOne);
    six.add_book(bookTwo);
    six.add_book(bookThree);
    six.add_book(bookFour);
    six.add_book(bookFive);
    six.add_book(bookSix);
    TYPE seven;
    seven.add_book(bookOne);
    seven.add_book(bookTwo);
    seven.add_book(bookThree);
    seven.add_book(bookFour);
    seven.add_book(bookFive);
    seven.add_book(bookSix);
    seven.add_book(bookSeven);
    TYPE eight;
    eight.add_book(bookOne);
    eight.add_book(bookTwo);
    eight.add_book(bookThree);
    eight.add_book(bookFour);
    eight.add_book(bookFive);
    eight.add_book(bookSix);
    eight.add_book(bookSeven);
    eight.add_book(bookEight);

            SUBCASE("ArrayList") {
        list = new ArrayList<TYPE>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<TYPE>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<TYPE>;
    }

            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find(zero) == -1);

    list->add(four);
    list->add(two);
    list->add(one);
            CHECK( list->to_string() == to_list_string(&four, &two, &one));

    list->add(three, 1);
            CHECK( list->to_string() == to_list_string(&four,&three, &two, &one));

    list->add(five, -1); //when index < 0 -> index = last
    list->add(six, 2);
    list->add(seven, 0);
    list->add(eight, -5);
            CHECK( list->to_string() == to_list_string(&seven, &four, &three, &six, &two, &one, &five, &eight));

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
            CHECK( list->to_string() == to_list_string(&four, &three, &two, &one, &five));

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == four);
            CHECK(list->get(2) == two);
            CHECK(list->get(-1) == five);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(four) == 0);
            CHECK(list->find(two) == 2);
            CHECK(list->find(five) == 4);
            CHECK(list->find(eight) == -1);

            CHECK_THROWS_AS(list->add(zero, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<TYPE>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<TYPE>, new ReverseComparator<TYPE>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}