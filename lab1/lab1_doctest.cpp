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

#include "library/Book.h"
#include "library/Character.h"
#include "library/Series.h"

TEST_CASE ("Integer Lists") {
    List<int> *list;
    std::stringstream ss;

    int zero = 0;
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int six = 6;
    int seven = 7;
    int eight = 8;

            SUBCASE("ArrayList") {
        list = new ArrayList<int>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<int>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<int>;
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

    list->sort(new ReverseComparator<int>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<int>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<int>, new ReverseComparator<int>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<int>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<int>, new ReverseComparator<int>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<int>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<int>, new ReverseComparator<int>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<int>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<int>, new ReverseComparator<int>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Double Lists") {
    List<double> *list;
    std::stringstream ss;

    double zero = 0.1;
    double one = 1.1;
    double two = 2.2;
    double three = 3.3;
    double four = 4.4;
    double five = 5.5;
    double six = 6.6;
    double seven = 7.7;
    double eight = 8.8;

            SUBCASE("ArrayList") {
        list = new ArrayList<double>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<double>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<double>;
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

    list->sort(new ReverseComparator<double>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<double>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<double>, new ReverseComparator<double>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<double>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<double>, new ReverseComparator<double>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<double>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<double>, new ReverseComparator<double>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<double>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<double>, new ReverseComparator<double>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("String lists") {
    List<std::string> *list;
    std::stringstream ss;

    std::string zero = "0";
    std::string one = "a";
    std::string two = "b";
    std::string three = "c";
    std::string four = "d";
    std::string five = "e";
    std::string six = "f";
    std::string seven = "g";
    std::string eight = "h";

            SUBCASE("ArrayList") {
        list = new ArrayList<std::string>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<std::string>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<std::string>;
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

    list->sort(new ReverseComparator<std::string>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<std::string>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<std::string>, new ReverseComparator<std::string>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<std::string>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<std::string>, new ReverseComparator<std::string>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<std::string>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<std::string>, new ReverseComparator<std::string>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<std::string>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<std::string>, new ReverseComparator<std::string>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Vector Lists") {
    List<std::vector<int>> *list;
    std::stringstream ss;

    std::vector<int> zero = {};
    std::vector<int> one = {1};
    std::vector<int> two = {2, 2};
    std::vector<int> three = {3, 3, 3};
    std::vector<int> four = {4, 4, 4, 4};
    std::vector<int> five = {5, 5, 5, 5, 5};
    std::vector<int> six = {6, 6, 6, 6, 6, 6};
    std::vector<int> seven = {7, 7, 7, 7, 7, 7, 7};
    std::vector<int> eight = {8, 8, 8, 8, 8, 8, 8, 8};

            SUBCASE("ArrayList") {
        list = new ArrayList<std::vector<int>>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<std::vector<int>>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<std::vector<int>>;
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

    list->sort(new ReverseComparator<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Book lists") {
    List<Book> *list;
    std::stringstream ss;

    Book zero("0");
    Book one("1one", 111, "The first");
    Book two("2two", 222);
    Book three("3Three", 333, "three3", "1992.12.12");
    Book four("4four", 444, "four4", "0444.04.04", "4our");
    Book five("5fiVE", 5);
    Book six("6SIX", 666, "sssix", "2006.06.16");
    Book seven("7Seven", 77);
    Book eight("8Eight", 888);

            SUBCASE("ArrayList") {
        list = new ArrayList<Book>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<Book>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<Book>;
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

    list->sort(new ReverseComparator<Book>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<Book>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<Book>, new ReverseComparator<Book>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<Book>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<Book>, new ReverseComparator<Book>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<Book>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<Book>, new ReverseComparator<Book>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<Book>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<Book>, new ReverseComparator<Book>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Character lists") {
    List<Character> *list;
    std::stringstream ss;

    Character zero("0Zero");
    Character one("1One");
    Character two("2Two");
    Character three("3Three");
    Character four("4Four");
    Character five("5Five");
    Character six("6Six");
    Character seven("7Seven");
    Character eight("8Eight");

            SUBCASE("ArrayList") {
        list = new ArrayList<Character>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<Character>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<Character>;
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

    list->sort(new ReverseComparator<Character>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<Character>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<Character>, new ReverseComparator<Character>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<Character>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<Character>, new ReverseComparator<Character>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<Character>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<Character>, new ReverseComparator<Character>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<Character>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<Character>, new ReverseComparator<Character>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}

TEST_CASE ("Series lists") {
    List<Series> *list;
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

    Series zero;
    Series one;
    one.add_book(bookOne);
    Series two;
    two.add_book(bookOne);
    two.add_book(bookTwo);
    Series three;
    three.add_book(bookOne);
    three.add_book(bookTwo);
    three.add_book(bookThree);
    Series four;
    four.add_book(bookOne);
    four.add_book(bookTwo);
    four.add_book(bookThree);
    four.add_book(bookFour);
    Series five;
    five.add_book(bookOne);
    five.add_book(bookTwo);
    five.add_book(bookThree);
    five.add_book(bookFour);
    five.add_book(bookFive);
    Series six;
    six.add_book(bookOne);
    six.add_book(bookTwo);
    six.add_book(bookThree);
    six.add_book(bookFour);
    six.add_book(bookFive);
    six.add_book(bookSix);
    Series seven;
    seven.add_book(bookOne);
    seven.add_book(bookTwo);
    seven.add_book(bookThree);
    seven.add_book(bookFour);
    seven.add_book(bookFive);
    seven.add_book(bookSix);
    seven.add_book(bookSeven);
    Series eight;
    eight.add_book(bookOne);
    eight.add_book(bookTwo);
    eight.add_book(bookThree);
    eight.add_book(bookFour);
    eight.add_book(bookFive);
    eight.add_book(bookSix);
    eight.add_book(bookSeven);
    eight.add_book(bookEight);

            SUBCASE("ArrayList") {
        list = new ArrayList<Series>;
    }
            SUBCASE("LinkedList") {
        list = new LinkedList<Series>;
    }
            SUBCASE("VectorList") {
        list = new VectorList<Series>;
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

    list->sort(new ReverseComparator<Series>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Bubble sort
    list->sort(new BubbleSort<Series>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new BubbleSort<Series>, new ReverseComparator<Series>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Insertion sort
    list->sort(new InsertionSort<Series>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new InsertionSort<Series>, new ReverseComparator<Series>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Merge sort
    list->sort(new MergeSort<Series>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new MergeSort<Series>, new ReverseComparator<Series>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    //Quick sort
    list->sort(new QuickSort<Series>);
            CHECK( list->to_string() == to_list_string(&one, &two, &three, &four, &five));

    list->sort(new QuickSort<Series>, new ReverseComparator<Series>);
            CHECK( list->to_string() == to_list_string(&five, &four, &three, &two, &one));
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
            CHECK(list->to_string() == to_list_string(&five, &four, &three, &two, &one));

    list->clear();
            CHECK(list->get_size() == 0);
            CHECK( list->to_string() == "[]");
}