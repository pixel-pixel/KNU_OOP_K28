cmake_minimum_required(VERSION 3.17)
project(KNU_OOP_K28)

set(CMAKE_CXX_STANDARD 14)

add_executable(KNU_OOP_K28 lab1/lab1_main.cpp lab2/lab2_main.cpp lab3/lab3_main.cpp project/project_main.cpp lab1/lists/List.h lab1/lists/LinkedList.h lab1/lists/ArrayList.h lab1/library/Book.h lab1/lists/VectorList.h lab1/lab1_doctest.cpp lab1/library/Book.cpp lab1/library/Character.cpp lab1/library/Character.h lab1/library/Series.cpp lab1/library/Series.h main.cpp lab1/utils/utils.h lab1/comparators/Comparator.h lab1/comparators/ReverseComparator.h lab1/comparators/BookByDateComparator.cpp lab1/comparators/BookByDateComparator.h lab1/comparators/BookByNameComparator.cpp lab1/comparators/BookByNameComparator.h lab1/list_generators/ListGenerator.cpp lab1/list_generators/ListGenerator.h lab1/sorts/Sort.h lab1/sorts/BubbleSort.h lab1/sorts/InsertionSort.h lab1/sorts/MergeSort.h lab1/sorts/QuickSort.h lab1/utils/doctest.h lab1/comparators/DefaultComparator.h)