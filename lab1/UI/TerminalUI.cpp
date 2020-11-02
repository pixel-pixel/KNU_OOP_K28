#include "TerminalUI.h"

void TerminalUI::start() {
    int type_in_list;
    std::cout << msg_type_in_list << std::endl;
    scanf("%d", &type_in_list);

    switch (type_in_list) {
        case 1:
            work_with_int_list();
            break;
        case 2:
            work_with_double_list();
            break;
        case 3:
            work_with_string_list();
            break;
        case 4:
            work_with_vector_list();
            break;
        case 5:
            work_with_Book_list();
            break;
        default:
            work_with_Character_list();
    }

}

void TerminalUI::work_with_int_list() {
    List<int> *list;

    int list_type;
    std::cout << msg_list_type << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
        case 1:
            list = new ArrayList<int>;
            break;
        case 2:
            list = new LinkedList<int>;
            break;
        default:
            list = new ArrayList<int>;
    }
    int command;

    while (true){
        int alpha;
        int beta;

        std::cout << msg_what_you_want << std::endl;
        scanf("%d", &command);

        switch (command) {
            case 1:
                std::cout << msg_count_of_random_objects << std::endl;
                scanf("%d", &alpha);

                generator.random_int(alpha, list);
                break;

            case 2:
                std::cout << msg_add_object << std::endl;
                scanf("%d", &alpha);

                std::cout << msg_add_object_index << std::endl;
                scanf("%d", &beta);

                list->add(alpha, beta);
                break;

            case 3:
                std::cout << msg_remove << std::endl;
                scanf("%d", &alpha);

                list->remove(alpha);
                break;

            case 4:
                std::cout << msg_get_object << std::endl;
                scanf("%d", &alpha);

                std::cout << "obj: " << list->get(alpha) << std::endl;
                break;

            case 5:
                std::cout << msg_find << std::endl;
                scanf("%d", &alpha);

                std::cout << "index: " << list->find(alpha) << std::endl;
                break;

            case 6:
                std::cout << msg_clear_the_list << std::endl;

                list->clear();
                break;

            case 7:
                Sort<int> *sort;
                Comparator<int> *comparator;

                std::cout << msg_sorts << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        sort = new BubbleSort<int>;
                        break;
                    case 2:
                        sort = new InsertionSort<int>;
                        break;
                    case 3:
                        sort = new MergeSort<int>;
                        break;
                    default:
                        sort = new QuickSort<int>;
                }

                std::cout << msg_comparators << std::endl;
                scanf("%d", &beta);

                switch (beta) {
                    case 1:
                        comparator = new DefaultComparator<int>;
                        break;
                    default:
                        comparator = new ReverseComparator<int>;
                }

                list->sort(sort, comparator);
                break;

            case 8:
                std::cout << msg_print << std::endl << *list << std::endl;
                break;

            default:
                return;
        }
    }
}

void TerminalUI::work_with_double_list() {
    List<double> *list;

    int list_type;
    std::cout << msg_list_type << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
        case 1:
            list = new ArrayList<double>;
            break;
        case 2:
            list = new LinkedList<double>;
            break;
        default:
            list = new ArrayList<double>;
    }
    int command;

    while (true){
        int alpha;
        double beta;

        std::cout << msg_what_you_want << std::endl;
        scanf("%d", &command);

        switch (command) {
            case 1:
                std::cout << msg_count_of_random_objects << std::endl;
                scanf("%d", &alpha);

                generator.random_double(alpha, list);
                break;

            case 2:
                std::cout << msg_add_object << std::endl;
                scanf("%lf", &beta);

                std::cout << msg_add_object_index << std::endl;
                scanf("%d", &alpha);

                list->add(beta, alpha);
                break;

            case 3:
                std::cout << msg_remove << std::endl;
                scanf("%d", &alpha);

                list->remove(alpha);
                break;

            case 4:
                std::cout << msg_get_object << std::endl;
                scanf("%d", &alpha);

                std::cout << "obj: " << list->get(alpha) << std::endl;
                break;

            case 5:
                std::cout << msg_find << std::endl;
                scanf("%lf", &beta);

                std::cout << "index: " << list->find(beta) << std::endl;
                break;

            case 6:
                std::cout << msg_clear_the_list << std::endl;

                list->clear();
                break;

            case 7:
                Sort<double> *sort;
                Comparator<double> *comparator;

                std::cout << msg_sorts << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        sort = new BubbleSort<double>;
                        break;
                    case 2:
                        sort = new InsertionSort<double>;
                        break;
                    case 3:
                        sort = new MergeSort<double>;
                        break;
                    default:
                        sort = new QuickSort<double>;
                }

                std::cout << msg_comparators << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        comparator = new DefaultComparator<double>;
                        break;
                    default:
                        comparator = new ReverseComparator<double>;
                }

                list->sort(sort, comparator);
                break;

            case 8:
                std::cout << msg_print << std::endl << *list << std::endl;
                break;

            default:
                return;
        }
    }
}

void TerminalUI::work_with_string_list() {
    List<std::string> *list;

    int list_type;
    std::cout << msg_list_type << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
        case 1:
            list = new ArrayList<std::string>;
            break;
        case 2:
            list = new LinkedList<std::string>;
            break;
        default:
            list = new ArrayList<std::string>;
    }
    int command;

    while (true){
        int alpha;
        char beta[20];

        std::cout << msg_what_you_want << std::endl;
        scanf("%d", &command);

        switch (command) {
            case 1:
                std::cout << msg_count_of_random_objects << std::endl;
                scanf("%d", &alpha);

                generator.random_string(alpha, list);
                break;

            case 2:
                std::cout << msg_add_object << std::endl;
                scanf("%s", beta);

                std::cout << msg_add_object_index << std::endl;
                scanf("%d", &alpha);

                list->add(beta, alpha);
                break;

            case 3:
                std::cout << msg_remove << std::endl;
                scanf("%d", &alpha);

                list->remove(alpha);
                break;

            case 4:
                std::cout << msg_get_object << std::endl;
                scanf("%d", &alpha);

                std::cout << "obj: " << list->get(alpha) << std::endl;
                break;

            case 5:
                std::cout << msg_find << std::endl;
                scanf("%s", beta);

                std::cout << "index: " << list->find(beta) << std::endl;
                break;

            case 6:
                std::cout << msg_clear_the_list << std::endl;

                list->clear();
                break;

            case 7:
                Sort<std::string> *sort;
                Comparator<std::string> *comparator;

                std::cout << msg_sorts << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        sort = new BubbleSort<std::string>;
                        break;
                    case 2:
                        sort = new InsertionSort<std::string>;
                        break;
                    case 3:
                        sort = new MergeSort<std::string>;
                        break;
                    default:
                        sort = new QuickSort<std::string>;
                }

                std::cout << msg_comparators << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        comparator = new DefaultComparator<std::string>;
                        break;
                    default:
                        comparator = new ReverseComparator<std::string>;
                }

                list->sort(sort, comparator);
                break;

            case 8:
                std::cout << msg_print << std::endl << *list << std::endl;
                break;

            default:
                return;
        }
    }
}

void TerminalUI::work_with_vector_list() {
    List<std::vector<int>> *list;

    int list_type;
    std::cout << msg_list_type << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
        case 1:
            list = new ArrayList<std::vector<int>>;
            break;
        case 2:
            list = new LinkedList<std::vector<int>>;
            break;
        default:
            list = new ArrayList<std::vector<int>>;
    }
    int command;

    while (true){
        int alpha;
        std::vector<int> *beta;

        std::cout << msg_what_you_want << std::endl;
        scanf("%d", &command);

        switch (command) {
            case 1:
                std::cout << msg_count_of_random_objects << std::endl;
                scanf("%d", &alpha);

                generator.random_vector_int(alpha, list);
                break;

            case 2:
                std::cout << msg_add_object << std::endl;
                beta = create_int_vector();

                std::cout << msg_add_object_index << std::endl;
                scanf("%d", &alpha);

                list->add(*beta, alpha);
                delete beta;
                break;

            case 3:
                std::cout << msg_remove << std::endl;
                scanf("%d", &alpha);

                list->remove(alpha);
                break;

            case 4:
                std::cout << msg_get_object << std::endl;
                scanf("%d", &alpha);

                std::cout << "obj: " << list->get(alpha) << std::endl;
                break;

            case 5:
                std::cout << msg_find << std::endl;
                beta = create_int_vector();

                std::cout << "index: " << list->find(*beta) << std::endl;
                delete beta;
                break;

            case 6:
                std::cout << msg_clear_the_list << std::endl;

                list->clear();
                break;

            case 7:
                Sort<std::vector<int>> *sort;
                Comparator<std::vector<int>> *comparator;

                std::cout << msg_sorts << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        sort = new BubbleSort<std::vector<int>>;
                        break;
                    case 2:
                        sort = new InsertionSort<std::vector<int>>;
                        break;
                    case 3:
                        sort = new MergeSort<std::vector<int>>;
                        break;
                    default:
                        sort = new QuickSort<std::vector<int>>;
                }

                std::cout << msg_comparators << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        comparator = new DefaultComparator<std::vector<int>>;
                        break;
                    default:
                        comparator = new ReverseComparator<std::vector<int>>;
                }

                list->sort(sort, comparator);
                break;

            case 8:
                std::cout << msg_print << std::endl << *list << std::endl;
                break;

            default:
                return;
        }
    }
}

void TerminalUI::work_with_Book_list() {
    List<Book> *list;

    int list_type;
    std::cout << msg_list_type << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
        case 1:
            list = new ArrayList<Book>;
            break;
        case 2:
            list = new LinkedList<Book>;
            break;
        default:
            list = new ArrayList<Book>;
    }
    int command;

    while (true){
        int alpha;
        Book *beta;

        std::cout << msg_what_you_want << std::endl;
        scanf("%d", &command);

        switch (command) {
            case 1:
                std::cout << msg_count_of_random_objects << std::endl;
                scanf("%d", &alpha);

                generator.random_book(alpha, list);
                break;

            case 2:
                std::cout << msg_add_object << std::endl;
                beta = create_Book();

                std::cout << msg_add_object_index << std::endl;
                scanf("%d", &alpha);

                list->add(*beta, alpha);
                delete beta;
                break;

            case 3:
                std::cout << msg_remove << std::endl;
                scanf("%d", &alpha);

                list->remove(alpha);
                break;

            case 4:
                std::cout << msg_get_object << std::endl;
                scanf("%d", &alpha);

                std::cout << "obj: " << list->get(alpha) << std::endl;
                break;

            case 5:
                std::cout << msg_find << std::endl;
                beta = create_Book();

                std::cout << "index: " << list->find(*beta) << std::endl;
                delete beta;
                break;

            case 6:
                std::cout << msg_clear_the_list << std::endl;

                list->clear();
                break;

            case 7:
                Sort<Book> *sort;
                Comparator<Book> *comparator;

                std::cout << msg_sorts << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        sort = new BubbleSort<Book>;
                        break;
                    case 2:
                        sort = new InsertionSort<Book>;
                        break;
                    case 3:
                        sort = new MergeSort<Book>;
                        break;
                    default:
                        sort = new QuickSort<Book>;
                }

                std::cout << msg_comparators << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        comparator = new DefaultComparator<Book>;
                        break;
                    default:
                        comparator = new ReverseComparator<Book>;
                }

                list->sort(sort, comparator);
                break;

            case 8:
                std::cout << msg_print << std::endl << *list << std::endl;
                break;

            default:
                delete list;
                return;
        }
    }

}

void TerminalUI::work_with_Character_list() {
    List<Character> *list;

    int list_type;
    std::cout << msg_list_type << std::endl;
    scanf("%d", &list_type);

    switch (list_type) {
        case 1:
            list = new ArrayList<Character>;
            break;
        case 2:
            list = new LinkedList<Character>;
            break;
        default:
            list = new ArrayList<Character>;
    }
    int command;

    while (true){
        int alpha;
        Character *beta;

        std::cout << msg_what_you_want << std::endl;
        scanf("%d", &command);

        switch (command) {
            case 1:
                std::cout << msg_count_of_random_objects << std::endl;
                scanf("%d", &alpha);

                generator.random_character(alpha, list);
                break;

            case 2:
                std::cout << msg_add_object << std::endl;
                beta = create_Character();

                std::cout << msg_add_object_index << std::endl;
                scanf("%d", &alpha);

                list->add(*beta, alpha);
                delete beta;
                break;

            case 3:
                std::cout << msg_remove << std::endl;
                scanf("%d", &alpha);

                list->remove(alpha);
                break;

            case 4:
                std::cout << msg_get_object << std::endl;
                scanf("%d", &alpha);

                std::cout << "obj: " << list->get(alpha) << std::endl;
                break;

            case 5:
                std::cout << msg_find << std::endl;
                beta = create_Character();

                std::cout << "index: " << list->find(*beta) << std::endl;
                delete beta;
                break;

            case 6:
                std::cout << msg_clear_the_list << std::endl;

                list->clear();
                break;

            case 7:
                Sort<Character> *sort;
                Comparator<Character> *comparator;

                std::cout << msg_sorts << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        sort = new BubbleSort<Character>;
                        break;
                    case 2:
                        sort = new InsertionSort<Character>;
                        break;
                    case 3:
                        sort = new MergeSort<Character>;
                        break;
                    default:
                        sort = new QuickSort<Character>;
                }

                std::cout << msg_comparators << std::endl;
                scanf("%d", &alpha);

                switch (alpha) {
                    case 1:
                        comparator = new DefaultComparator<Character>;
                        break;
                    default:
                        comparator = new ReverseComparator<Character>;
                }

                list->sort(sort, comparator);
                break;

            case 8:
                std::cout << msg_print << std::endl << *list << std::endl;
                break;

            default:
                return;
        }
    }

}

std::vector<int> *TerminalUI::create_int_vector() {
    auto *vector = new std::vector<int>;
    int count;
    int temp;

    std::cout << msg_vector_size << std::endl;
    scanf("%d", &count);

    for(int i = 0; i < count; i++){
        std::cout << msg_vector_object << i << ":" << std::endl;
        scanf("%d", &temp);
        vector->push_back(temp);
    }
    return vector;
}

Book *TerminalUI::create_Book() {
    char name[20];
    int pages;

    std::cout << msg_book_name << std::endl;
    scanf("%s", name);

    std::cout << msg_book_pages << std::endl;
    scanf("%d", &pages);

    return new Book(name, pages);
}

Character *TerminalUI::create_Character() {
    char name[20];

    std::cout << msg_character_name << std::endl;
    scanf("%s", name);

    return new Character(name);
}


