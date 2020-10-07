#define DOCTEST_CONFIG_IMPLEMENT

#include "../utils/doctest.h"
#include "../utils/utils.h"

#include "lists/ArrayList.h"
#include "lists/LinkedList.h"
#include "lists/VectorList.h"

#include "sorts/BubbleSort.h"
#include "sorts/InsertionSort.h"
#include "sorts/MergeSort.h"
#include "sorts/QuickSort.h"

#include "comparators/ReverseComparator.h"
#include "list_generators/ListGenerator.h"

TEST_CASE ("Integer Lists") {
    List<int> *list;
    std::stringstream ss;

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
    ss << *list;
            CHECK(ss.str() != "[]");
    ss.str("");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find(0) == -1);

    list->add(4);
    list->add(2);
    list->add(1);
    ss << *list;
            CHECK(ss.str() == "[4, 2, 1]");
    ss.str("");

    list->add(3, 1);
    ss << *list;
            CHECK(ss.str() == "[4, 3, 2, 1]");
    ss.str("");

    list->add(5, -1); //when index < 0 -> index = last
    list->add(6, 2);
    list->add(7, 0);
    list->add(8, -5);
    ss << *list;
            CHECK(ss.str() == "[7, 4, 3, 6, 2, 1, 5, 8]");
    ss.str("");

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
    ss << *list;
            CHECK(ss.str() == "[4, 3, 2, 1, 5]");
    ss.str("");

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == 4);
            CHECK(list->get(2) == 2);
            CHECK(list->get(-1) == 5);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(4) == 0);
            CHECK(list->find(2) == 2);
            CHECK(list->find(5) == 4);
            CHECK(list->find(8) == -1);

            CHECK_THROWS_AS(list->add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort------------------------------------------------------------------
    list->sort();
    ss << *list;
            CHECK(ss.str() == "[1, 2, 3, 4, 5]");
    ss.str("");

    list->sort(new ReverseComparator<int>);
    ss << *list;
            CHECK(ss.str() == "[5, 4, 3, 2, 1]");
    ss.str("");

    //Bubble sort
    list->sort(new BubbleSort<int>);
    ss << *list;
            CHECK(ss.str() == "[1, 2, 3, 4, 5]");
    ss.str("");

    list->sort(new BubbleSort<int>, new ReverseComparator<int>);
    ss << *list;
            CHECK(ss.str() == "[5, 4, 3, 2, 1]");
    ss.str("");

    //Insertion sort
    list->sort(new InsertionSort<int>);
    ss << *list;
            CHECK(ss.str() == "[1, 2, 3, 4, 5]");
    ss.str("");

    list->sort(new InsertionSort<int>, new ReverseComparator<int>);
    ss << *list;
            CHECK(ss.str() == "[5, 4, 3, 2, 1]");
    ss.str("");

    //Merge sort
    list->sort(new MergeSort<int>);
    ss << *list;
            CHECK(ss.str() == "[1, 2, 3, 4, 5]");
    ss.str("");

    list->sort(new MergeSort<int>, new ReverseComparator<int>);
    ss << *list;
            CHECK(ss.str() == "[5, 4, 3, 2, 1]");
    ss.str("");

    //Quick sort
    list->sort(new QuickSort<int>);
    ss << *list;
            CHECK(ss.str() == "[1, 2, 3, 4, 5]");
    ss.str("");

    list->sort(new QuickSort<int>, new ReverseComparator<int>);
    ss << *list;
            CHECK(ss.str() == "[5, 4, 3, 2, 1]");
    ss.str("");
    //--------------------------------------------------------------------------

            CHECK(list->get_size() == 5);
    ss << *list;
            CHECK(ss.str() == "[5, 4, 3, 2, 1]");
    ss.str("");

    list->clear();
    ss << *list;
            CHECK(list->get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("Double Lists") {
    List<double> *list;
    std::stringstream ss;

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
    ss << *list;
            CHECK(ss.str() != "[]");
    ss.str("");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find(0) == -1);

    list->add(4.4);
    list->add(2.2);
    list->add(1.1);
    ss << *list;
            CHECK(ss.str() == "[4.4, 2.2, 1.1]");
    ss.str("");

    list->add(3.3, 1);
    ss << *list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    list->add(5.5, -1); //when index < 0 -> index = last
    list->add(6.6, 2);
    list->add(7.7, 0);
    list->add(8.8, -5);
    ss << *list;
            CHECK(ss.str() == "[7.7, 4.4, 3.3, 6.6, 2.2, 1.1, 5.5, 8.8]");
    ss.str("");

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
    ss << *list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1, 5.5]");
    ss.str("");

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == 4.4);
            CHECK(list->get(2) == 2.2);
            CHECK(list->get(-1) == 5.5);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find(4.4) == 0);
            CHECK(list->find(2.2) == 2);
            CHECK(list->find(5.5) == 4);
            CHECK(list->find(8.8) == -1);

            CHECK_THROWS_AS(list->add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort---------------------------------------------------------------------------------
    list->sort();
    ss << *list;
            CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
    ss.str("");

    list->sort(new ReverseComparator<double>);
    ss << *list;
            CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    //Bubble sort
    list->sort(new BubbleSort<double>);
    ss << *list;
            CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
    ss.str("");

    list->sort(new BubbleSort<double>, new ReverseComparator<double>);
    ss << *list;
            CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    //Insertion sort
    list->sort(new InsertionSort<double>);
    ss << *list;
            CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
    ss.str("");

    list->sort(new InsertionSort<double>, new ReverseComparator<double>);
    ss << *list;
            CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    //Merge sort
    list->sort(new MergeSort<double>);
    ss << *list;
            CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
    ss.str("");

    list->sort(new MergeSort<double>, new ReverseComparator<double>);
    ss << *list;
            CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    //Quick sort
    list->sort(new QuickSort<double>);
    ss << *list;
            CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
    ss.str("");

    list->sort(new QuickSort<double>, new ReverseComparator<double>);
    ss << *list;
            CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
    ss.str("");
    //-------------------------------------------------------------------------------------------

    list->clear();
    ss << *list;
            CHECK(list->get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("String lists") {
    List<std::string> *list;
    std::stringstream ss;

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
    ss << *list;
            CHECK(ss.str() != "[]");
    ss.str("");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find("k") == -1);

    list->add("d");
    list->add("b");
    list->add("a");
    ss << *list;
            CHECK(ss.str() == "[d, b, a]");
    ss.str("");

    list->add("c", 1);
    ss << *list;
            CHECK(ss.str() == "[d, c, b, a]");
    ss.str("");

    list->add("e", -1); //when index < 0 -> index = last
    list->add("f", 2);
    list->add("g", 0);
    list->add("h", -5);
    ss << *list;
            CHECK(ss.str() == "[g, d, c, f, b, a, e, h]");
    ss.str("");

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
    ss << *list;
            CHECK(ss.str() == "[d, c, b, a, e]");
    ss.str("");

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == "d");
            CHECK(list->get(2) == "b");
            CHECK(list->get(-1) == "e");
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find("d") == 0);
            CHECK(list->find("b") == 2);
            CHECK(list->find("e") == 4);
            CHECK(list->find("h") == -1);

            CHECK_THROWS_AS(list->add("j", 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort-------------------------------------------------------------------------------------------
    list->sort();
    ss << *list;
            CHECK(ss.str() == "[a, b, c, d, e]");
    ss.str("");

    list->sort(new ReverseComparator<std::string>);
    ss << *list;
            CHECK(ss.str() == "[e, d, c, b, a]");
    ss.str("");

    //Bubble sort
    list->sort(new BubbleSort<std::string>);
    ss << *list;
            CHECK(ss.str() == "[a, b, c, d, e]");
    ss.str("");

    list->sort(new BubbleSort<std::string>, new ReverseComparator<std::string>);
    ss << *list;
            CHECK(ss.str() == "[e, d, c, b, a]");
    ss.str("");

    //Insertion sort
    list->sort(new InsertionSort<std::string>);
    ss << *list;
            CHECK(ss.str() == "[a, b, c, d, e]");
    ss.str("");

    list->sort(new InsertionSort<std::string>, new ReverseComparator<std::string>);
    ss << *list;
            CHECK(ss.str() == "[e, d, c, b, a]");
    ss.str("");

    //Merge sort
    list->sort(new MergeSort<std::string>);
    ss << *list;
            CHECK(ss.str() == "[a, b, c, d, e]");
    ss.str("");

    list->sort(new MergeSort<std::string>, new ReverseComparator<std::string>);
    ss << *list;
            CHECK(ss.str() == "[e, d, c, b, a]");
    ss.str("");

    //Quick sort
    list->sort(new QuickSort<std::string>);
    ss << *list;
            CHECK(ss.str() == "[a, b, c, d, e]");
    ss.str("");

    list->sort(new QuickSort<std::string>, new ReverseComparator<std::string>);
    ss << *list;
            CHECK(ss.str() == "[e, d, c, b, a]");
    ss.str("");
    //------------------------------------------------------------------------------------------------------

    list->clear();
    ss << *list;
            CHECK(list->get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("Vector lists") {
    List<std::vector<int>> *list;
    std::stringstream ss;

            SUBCASE("ArrayList") {
        list = new ArrayList<std::vector<int>>;
    }
            SUBCASE("LinkedList") {
        list = new ArrayList<std::vector<int>>;
    }
            SUBCASE("LinkedList") {
        list = new ArrayList<std::vector<int>>;
    }

            CHECK(list->get_size() == 0);

    ListGenerator::random_vector_int(10, list);
            CHECK(list->get_size() == 10);
    ss << *list;
            CHECK(ss.str() != "[]");
    ss.str("");

    list->clear();
            CHECK(list->get_size() == 0);

            CHECK_THROWS_AS(list->get(0), std::out_of_range);
            CHECK_THROWS_AS(list->get(10), std::out_of_range);
            CHECK_THROWS_AS(list->get(-1), std::out_of_range);

            CHECK_THROWS_AS(list->remove(0), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(-1), std::out_of_range);

            CHECK(list->find({0}) == -1);

    list->add({4, 4, 4, 4});
    list->add({2, 2});
    list->add({1});
    ss << *list;
            CHECK(ss.str() == "[{4, 4, 4, 4}, {2, 2}, {1}]");
    ss.str("");

    list->add({3, 3, 3}, 1);
    ss << *list;
            CHECK(ss.str() == "[{4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}]");
    ss.str("");

    list->add({5, 5, 5, 5, 5}, -1); //when index < 0 -> index = last
    list->add({6, 6, 6, 6, 6, 6}, 2);
    list->add({7, 7, 7, 7, 7, 7, 7}, 0);
    list->add({8, 8, 8, 8, 8, 8, 8, 8}, -5);
    ss << *list;
            CHECK(ss.str() ==
                  "[{7, 7, 7, 7, 7, 7, 7}, {4, 4, 4, 4}, {3, 3, 3}, {6, 6, 6, 6, 6, 6}, {2, 2}, {1}, {5, 5, 5, 5, 5}, {8, 8, 8, 8, 8, 8, 8, 8}]");
    ss.str("");

            CHECK(list->get_size() == 8);

    list->remove(0);
    list->remove(-1);
    list->remove(2);
    ss << *list;
            CHECK(ss.str() == "[{4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}, {5, 5, 5, 5, 5}]");
    ss.str("");

            CHECK(list->get_size() == 5);

            CHECK(list->get(0) == std::vector<int>{4, 4, 4, 4});
            CHECK(list->get(2) == std::vector<int>{2, 2});
            CHECK(list->get(-1) == std::vector<int>{5, 5, 5, 5, 5});
            CHECK_THROWS_AS(list->get(10), std::out_of_range);

            CHECK(list->find({4, 4, 4, 4}) == 0);
            CHECK(list->find({2, 2}) == 2);
            CHECK(list->find({5, 5, 5, 5, 5}) == 4);
            CHECK(list->find({8, 8, 8, 8, 8, 8, 8, 8}) == -1);

            CHECK_THROWS_AS(list->add({0}, 10), std::out_of_range);
            CHECK_THROWS_AS(list->remove(10), std::out_of_range);

    //Default sort-------------------------------------------------------------------------------------------------
    list->sort();
    ss << *list;
            CHECK(ss.str() == "[{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}]");
    ss.str("");

    list->sort(new ReverseComparator<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{5, 5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}]");
    ss.str("");

    //Bubble sort
    list->sort(new BubbleSort<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}]");
    ss.str("");

    list->sort(new BubbleSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{5, 5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}]");
    ss.str("");

    //Insertion sort
    list->sort(new InsertionSort<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}]");
    ss.str("");

    list->sort(new InsertionSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{5, 5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}]");
    ss.str("");

    //Merge sort
    list->sort(new MergeSort<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}]");
    ss.str("");

    list->sort(new MergeSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{5, 5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}]");
    ss.str("");

    //Quick sort
    list->sort(new QuickSort<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}]");
    ss.str("");

    list->sort(new QuickSort<std::vector<int>>, new ReverseComparator<std::vector<int>>);
    ss << *list;
            CHECK(ss.str() == "[{5, 5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}]");
    ss.str("");
    //-----------------------------------------------------------------------------------------------------

list->

clear();

ss << *
list;
CHECK(list->get_size() == 0);
CHECK(ss.str() == "[]");
}


