#include <iostream>
#include "linked_list.h"
#include <vector>

void push_back_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "PUSH_BACK_TEST\n";
    std::cout << "my_list.push_back(rand() % 100) X 15\n";
    size_t size = my_list.size();
    std::cout << "Original size: " << size << "\n";
    for (int i = 0; i < 15; i++) {
        my_list.push_back(rand() % 100);
    }
    std::cout << "Expected size: " << size + 15 << "\n";
    std::cout << "Real size: " << my_list.size() << "\n";
    std::cout << ((size + 15 == my_list.size()) ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    std::cout << "===================================================================|\n";
}

void push_front_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "PUSH_FRONT_TEST\n";
    std::cout << "my_list.push_front(rand() % 100) X 15\n";
    size_t size = my_list.size();
    std::cout << "Original size: " << size << "\n";
    for (int i = 0; i < 15; i++) {
        my_list.push_front(rand() % 100);
    }
    std::cout << "Expected size: " << size + 15 << "\n";
    std::cout << "Real size: " << my_list.size() << "\n";
    std::cout << ((size + 15 == my_list.size()) ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    std::cout << "===================================================================|\n";
}

void pop_back_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "POP_BACK_TEST\n";
    std::cout << "my_list.pop_back() X 15\n";
    size_t size = my_list.size();
    std::cout << "Original size: " << size << "\n";
    for (int i = 0; i < 15; i++) {
        my_list.pop_back();
    }
    std::cout << "Expected size: " << size - 15 << "\n";
    std::cout << "Real size: " << my_list.size() << "\n";
    std::cout << ((size - 15 == my_list.size()) ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    std::cout << "===================================================================|\n";
}

void pop_front_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "POP_FRONT_TEST\n";
    std::cout << "my_list.pop_front() X 15\n";
    size_t size = my_list.size();
    std::cout << "Original size: " << size << "\n";
    for (int i = 0; i < 15; i++) {
        my_list.pop_front();
    }
    std::cout << "Expected size: " << size - 15 << "\n";
    std::cout << "Real size: " << my_list.size() << "\n";
    std::cout << ((size - 15 == my_list.size()) ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    std::cout << "===================================================================|\n";
}

void insert_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "INSERT_TEST\n";
    size_t size = my_list.size();
    std::cout << "Original size: " << size << "\n";
    std::cout << "________________________________" << "\n";

    for (int i = 0; i < 15; i++) {
        my_list.push_back(0);
    }
    int size_after_push = my_list.size();
    std::cout << "my_list.push_back(0) X 15" << "\n";
    auto iter_5 = my_list.begin();
    iter_5 += 5;
    for (int i = 0; i < 5; i++) {
        my_list.insert(1, iter_5);
    }
    std::cout << "my_list.insert(1, iter_5) X 5" << "\n";
    std::cout << "________________________________" << "\n";



    std::cout << "Expected size: " << size_after_push + 5 << "\n";
    std::cout << "Real size: " << my_list.size() << "\n";
    std::string expected_str = "0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 \n";
    std::cout << "Expected data: " << expected_str;

    auto tmp_iter = my_list.begin();
    std::string real_str;
    for (int i = 0; i < my_list.size(); i++) {
        real_str += std::to_string(*tmp_iter) + ' ';
        tmp_iter++;
    }
    real_str += "\n";
    std::cout << "Real data:     " << real_str;

    if (size_after_push + 5 == my_list.size() and expected_str == real_str) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "===================================================================|\n";
}

void remove_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "REMOVE_TEST\n";
    size_t size = my_list.size();
    std::string initial_str;
    auto tmp_iter = my_list.begin();
    for (int i = 0; i < my_list.size(); i++) {
        initial_str += std::to_string(*tmp_iter) + ' ';
        tmp_iter++;
    }
    std::cout << "________________________________" << "\n";
    auto iter_5 = my_list.begin();
    iter_5 += 5;
    for (int i = 0; i < 5; i++) {
        my_list.remove(iter_5);
//        iter_5.remove();
    }
    std::cout << "my_list.remove(iter_5) X 5\n";

    std::cout << "________________________________" << "\n";

    std::cout << "Original size: " << size << "\n";
    std::cout << "Expected size: " << size - 5 << "\n";
    std::cout << "Real size: " << my_list.size() << "\n";
    std::cout << "Initial data: " << initial_str << "\n";

    std::string final_str;
    auto tmp_iter2 = my_list.begin();
    for (int i = 0; i < my_list.size(); i++) {
        final_str += std::to_string(*tmp_iter2) + ' ';
        tmp_iter2++;
    }
    std::cout << "Final data:   " << final_str << "\n";
    std::cout << ((size - 5 == my_list.size()) ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    std::cout << "===================================================================|\n";
}

void operators_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "OPERATORS_TEST\n";
    while (my_list.size() > 0) {
        my_list.pop_back();
    }
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    auto iter = my_list.begin();

    std::string initial_str;
    for (int i = 0; i < 10; i++) {
       initial_str += std::to_string(*iter) + ' ';
       iter++;
    }
    std::cout << "Data in list: " << initial_str << '\n';

    std::cout << "___________________________\n";
    std::cout << "OPERATOR ++ |||||||||||||||\n";
    iter = my_list.begin();
    std::cout << "*iterator = " << *iter << "\n";
    iter++;
    std::cout << "iterator++;\n";
    std::cout << "*iterator = " << *iter << "\n";
    ++iter;
    std::cout << "++iterator;\n";
    std::cout << "*iterator = " << *iter << "\n";
    if (*iter == 3) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "___________________________\n";
    std::cout << "___________________________\n";
    std::cout << "OPERATOR -- |||||||||||||||\n";
    std::cout << "*iterator = " << *iter << "\n";
    iter--;
    std::cout << "iterator--;\n";
    std::cout << "*iterator = " << *iter << "\n";
    --iter;
    std::cout << "--iterator;\n";
    std::cout << "*iterator = " << *iter << "\n";
    if (*iter == 1) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "___________________________\n";
    std::cout << "___________________________\n";
    std::cout << "OPERATOR += |||||||||||||||\n";
    std::cout << "*iterator = " << *iter << "\n";
    iter += 5;
    std::cout << "iterator += 5;\n";
    std::cout << "*iterator = " << *iter << "\n";
    if (*iter == 6) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "___________________________\n";
    std::cout << "___________________________\n";
    std::cout << "OPERATOR -= |||||||||||||||\n";
    std::cout << "*iterator = " << *iter << "\n";
    iter -= 5;
    std::cout << "iterator -= 5;\n";
    std::cout << "*iterator = " << *iter << "\n";
    if (*iter == 1) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "___________________________\n";
    std::cout << "___________________________\n";
    std::cout << "OPERATOR + |||||||||||||||\n";
    std::cout << "*iterator1 = " << *iter << "\n";
    auto iter2 = iter + 5;
    std::cout << "auto iterator2 = iterator1 + 5;\n";
    std::cout << "*iterator1 = " << *iter << "\n";
    std::cout << "*iterator2 = " << *iter2 << "\n";
    if (*iter == 1 and *iter2 == 6) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "___________________________\n";
    std::cout << "___________________________\n";
    std::cout << "OPERATOR - |||||||||||||||\n";
    iter += 5;
    iter2 -= 3;
    std::cout << "*iterator1 = " << *iter << "\n";
    std::cout << "*iterator2 = " << *iter2 << "\n";
    iter2 = iter - 5;
    std::cout << "iterator2 = iterator1 - 5;\n";
    std::cout << "*iterator1 = " << *iter << "\n";
    std::cout << "*iterator2 = " << *iter2 << "\n";
    if (*iter == 6 and *iter2 == 1) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "___________________________\n";

    std::cout << "___________________________\n";
    std::cout << "OPERATOR = AND OPERATOR * |\n";

    linked_list::List<int>::Iterator iterator = my_list.begin();
    std::cout << "linked_list::List<int>::Iterator iterator = my_list.begin();\n";
    std::cout << "std::cout << *iterator << '\\n'; // " << *iterator << "\n";
    if (*iterator == 1) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    std::cout << "___________________________\n";
    std::cout << "===================================================================|\n";
}


int main() {
    linked_list::List<int> my_list;
    push_back_test(my_list);
    pop_back_test(my_list);
    push_front_test(my_list);
    pop_front_test(my_list);
    insert_test(my_list);
    remove_test(my_list);
    operators_test(my_list);
    return 0;
}
