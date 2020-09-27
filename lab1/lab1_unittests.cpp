//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//
//#include <sstream>
//
//#include "libs/doctest.h"
//#include "lists/ArrayList.h"
//#include "lists/LinkedList.h"
//#include "sorts/sorts.h"
//#include "compare_functions/compare.h"
//
//TEST_CASE ("Integer list tests") {
//    std::stringstream ss;
//
//            SUBCASE("ArrayList") {
//        ArrayList<int> list;
//                CHECK(list.get_size() == 0);
//
//        list.add(4);
//        list.add(2);
//        list.add(1);
//        ss << list;
//                CHECK(ss.str() == "[4, 2, 1]");
//        ss.str("");
//
//        list.add(3, 1);
//        ss << list;
//                CHECK(ss.str() == "[4, 3, 2, 1]");
//        ss.str("");
//
//        list.add(5, -1); //when index < 0 -> index = last
//        list.add(6, 2);
//        list.add(7, 0);
//        list.add(8, -5);
//        ss << list;
//                CHECK(ss.str() == "[7, 4, 3, 6, 2, 1, 5, 8]");
//        ss.str("");
//
//                CHECK(list.get_size() == 8);
//
//        list.remove(0);
//        list.remove(-1);
//        list.remove(2);
//        ss << list;
//                CHECK(ss.str() == "[4, 3, 2, 1, 5]");
//        ss.str("");
//
//                CHECK(list.get_size() == 5);
//
//                CHECK(list.get(0) == 4);
//                CHECK(list.get(2) == 2);
//                CHECK(list.get(-1) == 5);
//                CHECK_THROWS_AS(list.get(10), std::out_of_range);
//
//                CHECK(list.find(4) == 0);
//                CHECK(list.find(2) == 2);
//                CHECK(list.find(5) == 4);
//                CHECK(list.find(8) == -1);
//
//                CHECK_THROWS_AS(list.add(0, 10), std::out_of_range);
//                CHECK_THROWS_AS(list.remove(10), std::out_of_range);
//
//                SUBCASE("Bubble sort") {
//            list.sort(bubble_sort);
//            ss << list;
//                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//            ss.str("");
//
//            list.sort(bubble_sort, compare_int_reverse);
//            ss << list;
//                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//            ss.str("");
//        }
//
//                SUBCASE("Insertion sort") {
//            list.sort(insertion_sort);
//            ss << list;
//                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//            ss.str("");
//
//            list.sort(insertion_sort, compare_int_reverse);
//            ss << list;
//                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//            ss.str("");
//        }
//
//                SUBCASE("Merge sort") {
//            list.sort(merge_sort);
//            ss << list;
//                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//            ss.str("");
//
//            list.sort(merge_sort, compare_int_reverse);
//            ss << list;
//                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//            ss.str("");
//        }
//
//                SUBCASE("Quick sort") {
//            list.sort(quick_sort);
//            ss << list;
//                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//            ss.str("");
//
//            list.sort(quick_sort, compare_int_reverse);
//            ss << list;
//                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//            ss.str("");
//        }
//
//        list.clear();
//        ss << list;
//                CHECK(list.get_size() == 0);
//                CHECK(ss.str() == "[]");
//    }
//
//            SUBCASE("LinkedList") {
//        //LinkedList<int> linkedlist;
//        //CHECK(linkedlist.get_size() == 0);
////
////        linkedlist.add(4);
////        linkedlist.add(2);
////        linkedlist.add(1);
////        ss << linkedlist;
////                CHECK(ss.str() == "[4, 2, 1]");
////        ss.str("");
////
////        linkedlist.add(3, 1);
////        ss << linkedlist;
////                CHECK(ss.str() == "[4, 3, 2, 1]");
////        ss.str("");
////
////        linkedlist.add(5, -1); //when index < 0 -> index = last
////        linkedlist.add(6, 2);
////        linkedlist.add(7, 0);
////        linkedlist.add(8, -5);
////        ss << linkedlist;
////                CHECK(ss.str() == "[7, 4, 3, 6, 2, 1, 5, 8]");
////        ss.str("");
////
////                CHECK(linkedlist.get_size() == 8);
////
////        linkedlist.remove(0);
////        linkedlist.remove(-1);
////        linkedlist.remove(2);
////        ss << linkedlist;
////                CHECK(ss.str() == "[4, 3, 2, 1, 5]");
////        ss.str("");
////
////                CHECK(linkedlist.get_size() == 5);
////
////                CHECK(linkedlist.get(0) == 4);
////                CHECK(linkedlist.get(2) == 2);
////                CHECK(linkedlist.get(-1) == 5);
////                CHECK_THROWS_AS(linkedlist.get(10), std::out_of_range);
////
////                CHECK(linkedlist.find(4) == 0);
////                CHECK(linkedlist.find(2) == 2);
////                CHECK(linkedlist.find(5) == 4);
////                CHECK(linkedlist.find(8) == -1);
////
////                CHECK_THROWS_AS(linkedlist.add(0, 10), std::out_of_range);
////                CHECK_THROWS_AS(linkedlist.remove(10), std::out_of_range);
////
////                SUBCASE("Bubble sort") {
////            linkedlist.sort(bubble_sort);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
////            ss.str("");
////
////            linkedlist.sort(bubble_sort, compare_int_reverse);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
////            ss.str("");
////        }
////
////                SUBCASE("Insertion sort") {
////            linkedlist.sort(insertion_sort);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
////            ss.str("");
////
////            linkedlist.sort(insertion_sort, compare_int_reverse);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
////            ss.str("");
////        }
////
////                SUBCASE("Merge sort") {
////            linkedlist.sort(merge_sort);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
////            ss.str("");
////
////            linkedlist.sort(merge_sort, compare_int_reverse);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
////            ss.str("");
////        }
////
////                SUBCASE("Quick sort") {
////            linkedlist.sort(quick_sort);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[1, 2, 3, 4, 5]");
////            ss.str("");
////
////            linkedlist.sort(quick_sort, compare_int_reverse);
////            ss << linkedlist;
////                    CHECK(ss.str() == "[5, 4, 3, 2, 1]");
////            ss.str("");
////        }
////
////        linkedlist.clear();
////        ss << linkedlist;
////                CHECK(linkedlist.get_size() == 0);
////                CHECK(ss.str() == "[]");
//    }
//
//
//}
//
//
