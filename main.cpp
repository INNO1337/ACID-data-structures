#include <iostream>
#include "linked_list.h"
#include <vector>

int cnt = 0;
int trues = 0;
int falses = 0;

void statistic(bool e) {
    cnt++;
    if (e) {
        trues++;
    } else {
        falses++;
    }
}

void list_constructor_test() {
    std::cout << "===================================================================|\n";
    std::cout << "LIST_CONSTRUCTOR_TEST\n\n";
    linked_list::List<int> list1;
    std::cout << "linked_list::List<int> list1;\n";
    linked_list::List<float> list2;
    std::cout << "linked_list::List<float> list2;\n";
    linked_list::List<char> list3;
    std::cout << "linked_list::List<char> list3;\n";
    linked_list::List<std::string> list4;
    std::cout << "linked_list::List<std::string> list4;\n";
    for (int i = 0; i < 10; i++) {
        list1.push_back(i + 1);
    }
    std::cout << "_______________________________/\n";
    std::cout << "list1.push_back(i); X 10, where i from 1 to 10\n";
    auto it1 = list1.begin();
    std::string str1;
    for (int i = 0; i < list1.size(); i++) {
        str1 += std::to_string(*it1) + ' ';
        it1++;
    }
    std::cout << "DATA IN LIST1: " << str1 << '\n';
    std::cout << (str1.size() == 21 ? "====> TRUE <====\n" : "====> FALSE <====\n");
    statistic(str1.size() == 21);
    std::cout << "_______________________________|\n";

    std::cout << "_______________________________/\n";
    for (int i = 0; i < 10; i++) {
        list2.push_back(static_cast<float>(i + 1.01));
    }
    std::cout << "list2.push_back(static_cast<float>(i + 1.01)); X 10, where i from 0 to 9\n";
    auto it2 = list2.begin();
    std::string str2;
    for (int i = 0; i < list2.size(); i++) {
        str2 += std::to_string(*it2) + ' ';
        it2++;
    }
    std::cout << "DATA IN LIST2: " << str2 << '\n';
    std::cout << (str2.size() > 21 ? "====> TRUE <====\n" : "====> FALSE <====\n");
    statistic(str2.size() > 21);
    std::cout << "_______________________________|\n";

    std::cout << "_______________________________/\n";
    for (int i = 0; i < 10; i++) {
        char ascii_sym = static_cast<char>(65 + i);
        list3.push_back(ascii_sym);
    }
    std::cout << "list3.push_back(static_cast<char>(65 + i)); X 10, where i from 0 to 9\n";
    auto it3 = list3.begin();
    std::string str3;
    for (int i = 0; i < list3.size(); i++) {
        str3 += *it3;
        str3 += ' ';
        it3++;
    }
    std::cout << "DATA IN LIST3: " << str3 << '\n';
    std::cout << (str3.size() >= 20 ? "====> TRUE <====\n" : "====> FALSE <====\n");
    statistic(str3.size() >= 20);
    std::cout << "_______________________________|\n";

    std::cout << "_______________________________/\n";
    for (int i = 0; i < 10; i++) {
        std::string tmp_str = "STRING" + std::to_string(i+1);
        list4.push_back(tmp_str);
    }
    std::cout << "list4.push_back(\"STRING\" + std::to_string(i)); X 10, where i from 1 to 10\n";
    auto it4 = list4.begin();
    std::string str4;
    for (int i = 0; i < list4.size(); i++) {
        str4 += *it4;
        str4 += ' ';
        it4++;
    }
    std::cout << "DATA IN LIST4: " << str4 << '\n';
    std::cout << (str4.size() > 70 ? "====> TRUE <====\n" : "====> FALSE <====\n");
    statistic(str4.size() > 70);
    std::cout << "_______________________________|\n";

    std::cout << "===================================================================|\n\n\n";
}

void front_and_back_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "FRONT_AND_BACK_TEST\n";
    if (my_list.size() > 0) {
        int tmp = my_list.size();
        for (int i = 0; i < tmp; i++) {
            my_list.pop_back();
        }
    }
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 10, where i from 1 to 10\n";
    int v1 = my_list.front();
    int v2 = my_list.back();
    std::cout << "my_list.front(); //value: " << v1 << '\n';
    std::cout << "my_list.back();  //value: " << v2 << '\n';
    std::cout << "- - - - - - - - - - - -\n";
    my_list.front() = 123;
    my_list.back() = 321;
    std::cout << "my_list.front() = 123;\n";
    std::cout << "my_list.back() = 321;\n";
    std::cout << "- - - - - - - - - - - -\n";
    int v3 = my_list.front();
    int v4 = my_list.back();
    std::cout << "my_list.front(); //value: " << v3 << '\n';
    std::cout << "my_list.back();  //value: " << v4 << '\n';


    std::cout << ( v1 == 1 && v2 == 10 && v3 == 123 && v4 == 321 ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(v1 == 1 && v2 == 10 && v3 == 123 && v4 == 321);
    std::cout << "===================================================================|\n\n\n";
}

void empty_test() {
    std::cout << "===================================================================|\n";
    std::cout << "EMPTY_TEST\n";
    linked_list::List<int> list;
    std::cout << "linked_list::List<int> list;\n";
    bool isEmpty1 = list.empty();
    std::cout << "list.empty(); //" << list.empty() << "\n";
    list.push_back(1);
    std::cout << "list.push_back(1);\n";
    bool isEmpty2 = list.empty();
    std::cout << "list.empty(); //" << list.empty() << "\n";

    std::cout << (isEmpty1 && !isEmpty2 ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(isEmpty1 && !isEmpty2);
    std::cout << "===================================================================|\n\n\n";
}

void clear_test() {
    std::cout << "===================================================================|\n";
    std::cout << "CLEAR TEST\n";
    linked_list::List<int> my_list;
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 10, where i from 1 to 10\n";
    my_list.clear();
    std::cout << "my_list.clear();\n";
    std::cout << "my_list.empty(); //" << my_list.empty() << '\n';

    std::cout << (my_list.empty() ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(my_list.empty());
    std::cout << "===================================================================|\n\n\n";
}

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
    std::cout << (size + 15 == my_list.size() ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    std::cout << "===================================================================|\n\n\n";
    statistic(size + 15 == my_list.size());
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
    std::cout << (size + 15 == my_list.size() ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(size + 15 == my_list.size());
    std::cout << "===================================================================|\n\n\n";
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
    std::cout << (size - 15 == my_list.size() ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(size - 15 == my_list.size());
    std::cout << "===================================================================|\n\n\n";
}

void pop_front_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "POP_FRONT_TEST\n";
    my_list.clear();
    for (int i = 0; i < 15; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 15, where i from 1 to 10\n";
    std::cout << "my_list.pop_front() X 15\n";
    size_t size = my_list.size();
    std::cout << "Original size: " << size << "\n";
    for (int i = 0; i < 15; i++) {
        my_list.pop_front();
    }
    std::cout << "Expected size: " << size - 15 << "\n";
    std::cout << "Real size: " << my_list.size() << "\n";
    std::cout << (size - 15 == my_list.size() ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(size - 15 == my_list.size());
    std::cout << "===================================================================|\n\n\n";
}

void insert_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "INSERT_TEST\n";
    my_list.clear();
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

    if (size_after_push + 5 == my_list.size() && expected_str == real_str) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    statistic(size_after_push + 5 == my_list.size() && expected_str == real_str);
    std::cout << "===================================================================|\n\n\n";
}

void remove_test(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "REMOVE_TEST\n";
    my_list.clear();
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 10, where i from 1 to 10\n";
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
    std::cout << (size - 5 == my_list.size() ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(size - 5 == my_list.size());
    std::cout << "===================================================================|\n\n\n";
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
    statistic(*iter == 3);
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
    statistic(*iter == 1);
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
    statistic(*iter == 6);
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
    statistic(*iter == 1);
    std::cout << "___________________________\n";
    std::cout << "___________________________\n";
    std::cout << "OPERATOR + |||||||||||||||\n";
    std::cout << "*iterator1 = " << *iter << "\n";
    auto iter2 = iter + 5;
    std::cout << "auto iterator2 = iterator1 + 5;\n";
    std::cout << "*iterator1 = " << *iter << "\n";
    std::cout << "*iterator2 = " << *iter2 << "\n";
    if (*iter == 1 && *iter2 == 6) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    statistic(*iter == 1 && *iter2 == 6);
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
    if (*iter == 6 && *iter2 == 1) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    statistic(*iter == 6 && *iter2 == 1);
    std::cout << "___________________________\n";

    std::cout << "___________________________\n";
    std::cout << "OPERATOR = AND OPERATOR * |\n";

    linked_list::List<int>::Iterator iterator = my_list.begin();
    std::cout << "linked_list::List<int>::Iterator iterator = my_list.begin();\n";
    std::cout << "std::cout << *iterator << '\\n'; // " << *iterator << "\n";
    if (*iterator) {
        std::cout << "====> TRUE <====\n";
    } else {
        std::cout << "====> FALSE <====\n";
    }
    statistic(*iterator);
    std::cout << "___________________________\n";
    std::cout << "===================================================================|\n\n\n";
}

void consistency_test1(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "CONSISTENCY_TEST1\n";
    if (my_list.size() > 0) {
        int tmp = my_list.size();
        for (int i = 0; i < tmp; i++) {
            my_list.pop_back();
        }
    }
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 10, where i from 1 to 10\n";
    auto iter = my_list.begin();
    std::cout << "auto iter = my_list.begin();\n";
    for (int i = 0; i < 9; i++) {
        my_list.pop_front();
    }
    std::cout << "my_list.pop_front(); X 9 (so the only element in list left)\n\n";
    std::cout << "my_list.size(): " << my_list.size() << '\n';
    auto tmp_iter = my_list.begin();
    std::cout << "Element value: " << *tmp_iter << '\n';
    std::cout << "________________________________________\n";
    std::cout << "DATA that we can still get via iter++: \n";
    std::string data;
    for (int i = 0; i < 10; i++) {
        data += std::to_string(*iter) + ' ';
        iter++;
    }
    std::cout << data << '\n';
    std::cout << (data.size() >= 21 ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(data.size() >= 21);
    std::cout << "________________________________________\n";
    std::cout << "===================================================================|\n\n\n";
}

void consistency_test2(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "CONSISTENCY_TEST2\n";
    if (my_list.size() > 0) {
        int tmp = my_list.size();
        for (int i = 0; i < tmp; i++) {
            my_list.pop_back();
        }
    }
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 10, where i from 1 to 10\n";
    auto iter = my_list.begin();
    iter += 9;
    std::cout << "auto iter = my_list.begin();\n";
    std::cout << "iter += 9;\n";
    for (int i = 0; i < 9; i++) {
        my_list.pop_back();
    }
    std::cout << "my_list.pop_back(); X 9 (so the only element in list left)\n\n";
    std::cout << "my_list.size(): " << my_list.size() << '\n';
    auto tmp_iter = my_list.begin();
    std::cout << "Element value: " << *tmp_iter << '\n';
    std::cout << "________________________________________\n";
    std::cout << "DATA that we can still get via iter--: \n";
    std::string data;
    for (int i = 0; i < 10; i++) {
        data += std::to_string(*iter) + ' ';
        iter--;
    }
    std::cout << data << '\n';
    std::cout << (data.size() >= 21 ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(data.size() >= 21);
    std::cout << "________________________________________\n";
    std::cout << "===================================================================|\n\n\n";
}

void consistency_test3(linked_list::List<int> &my_list) {
    std::cout << "===================================================================|\n";
    std::cout << "CONSISTENCY_TEST3\n";
    if (my_list.size() > 0) {
        int tmp = my_list.size();
        for (int i = 0; i < tmp; i++) {
            my_list.pop_back();
        }
    }
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 10, where i from 1 to 10\n";
    auto iter = my_list.begin();
    iter += 3; // 1 2 3 4 5 6 7 8 9 10
    std::cout << "auto iter = my_list.begin();\n";
    std::cout << "iter += 3; //iter value = " << *iter << "\n\n";
    auto iter1 = my_list.begin();
    iter1 += 3;
    std::cout << "auto iter1 = my_list.begin();\n";
    std::cout << "iter1 += 3; //iter1 value = " << *iter1 << "\n\n";
    auto iter2 = my_list.begin();
    iter2 += 4;
    std::cout << "auto iter2 = my_list.begin();\n";
    std::cout << "iter2 += 4; //iter2 value = " << *iter2 << "\n\n";
    auto iter3 = my_list.begin();
    iter3 += 5;
    std::cout << "auto iter3 = my_list.begin();\n";
    std::cout << "iter3 += 5; //iter3 value = " << *iter3 << "\n\n";
    auto iter4 = my_list.begin();
    iter4 += 6;
    std::cout << "auto iter4 = my_list.begin();\n";
    std::cout << "iter4 += 6; //iter4 value = " << *iter4 << '\n';
    std::cout << "- - - - - - - - - - - - - - -\n";
    for (int i = 0; i < 4; i++) {
        my_list.remove(iter);
    }
    std::cout << "my_list.remove(iter); X 4 (so the elements 4, 5, 6, 7 \"removed\", \n"
              << "but have iterators pointing on them)\n\n";

    auto new_iter = my_list.begin();
    std::cout << "Elements we can get with new iterator (not \"removed\" elements):\n";
    for (int i = 0; i < my_list.size(); i++) {
        std::cout << *new_iter << ' ';
        new_iter++;
    }

    std::cout << "\n\n\"Removed\" elements we can still reach with iter1++:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << *iter1 << ' ';
        iter1++;
    }
    std::cout << *iter1 << "\n\n";

    std::cout << "- - - - - - - - - - - - - - -\n";

    iter1++;
    std::cout << "iter1++; //iter1 value = " << *iter1 << "\n\n";

    std::cout << "If iter1 get \"non-removed\" elements, for example 8,\n"
              << "it can`t get back to \"removed\" ones via iter1--:\n";

    std::string data = "8 3 2 1 ";
    std::string data_res;
    for (int i = 0; i < 4; i++) {
        data_res += std::to_string(*iter1) + ' ';
        iter1--;
    }
    std::cout << data_res << "\n\n";

    std::cout << (data == data_res ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(data == data_res);
    std::cout << "________________________________________\n";
    std::cout << "===================================================================|\n\n\n";
}

void indexing_operator_test() {
    std::cout << "===================================================================|\n";
    std::cout << "INDEXING OPERATOR TEST\n\n";
    linked_list::List<int> my_list;
    for (int i = 0; i < 10; i++) {
        my_list.push_back(i+1);
    }
    std::cout << "my_list.push_back(i); X 10, where i from 1 to 10\n";
    std::cout << "- - - - - - - - - - - - - - - -\n";
    std::cout << "i from 0 to 9\n";

    for (int i = 0; i < my_list.size(); i++) {
        std::cout << "->   my_list[" << i << "] // value: " << my_list[i] << "\n";
    }
    std::cout << "- - - - - - - - - - - - - - - -\n";
    std::cout << "i from -1 to -10\n";
    for (int i = -1; i > (-1 * my_list.size() - 1); i--) {
        std::cout << "->   my_list[" << i << "] // value: " << my_list[i] << "\n";
    }
    std::cout << "- - - - - - - - - - - - - - - -\n";
    std::cout << "my_list[4] // value: " << my_list[4] << "\n";
    my_list[4] = 123;
    std::cout << "my_list[4] = 123;\n";
    std::cout << "my_list[4] // value: " << my_list[4] << "\n\n";


    std::cout << (my_list[4] == 123 ? "====> TRUE <====" : "====> FALSE <====") << "\n";
    statistic(my_list[4] == 123);
    std::cout << "===================================================================|\n\n\n";
}

int main() {
    linked_list::List<int> my_list;
    list_constructor_test();
    front_and_back_test(my_list);
    empty_test();
    clear_test();
    push_back_test(my_list);
    pop_back_test(my_list);
    push_front_test(my_list);
    pop_front_test(my_list);
    insert_test(my_list);
    remove_test(my_list);
    operators_test(my_list);
    consistency_test1(my_list);
    consistency_test2(my_list);
    consistency_test3(my_list);
    indexing_operator_test();

    printf("__________________________________\n");
    printf("| Number of tests in total | %3d |\n", cnt);
    printf("|--------------------------|-----|\n");
    printf("| Tests passed successfully| %3d |\n", trues);
    printf("|--------------------------|-----|\n");
    printf("| Tests failed             | %3d |\n", falses);
    printf("|__________________________|_____|\n");
    if (cnt == trues) {
        printf("       TESTS SUCCEEDED!\n\n");
    } else {
        printf("         TESTS FAILED!\n\n");
    }


    return 0;
}
