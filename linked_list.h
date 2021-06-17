#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

template<typename T>
struct node {
    explicit node(T k): key(k), next(nullptr), prev(nullptr), ref_counter(0) {};
    T key;
    node<T>* next;
    node<T>* prev;
    size_t ref_counter;
};



namespace linked_list {
/**__________________________________________________________________________________________________________________**/
/**----------------------------------------------DECLARATION---------------------------------------------------------**/
/**^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^**/
    template<typename T>
    class List {
     public:
        explicit List(): size_(0), head(nullptr), tail(nullptr) {};
        void push_back(T k);
        void push_front(T k);
        void pop_back();
        void pop_front();
        T& front();
        T& back();
        size_t size();
        bool empty();
        void clear();
//        void swap(List<T> &other);
        T& operator [] (const int index);

        class Iterator {
         friend class List;
         public:
            Iterator(): cur(nullptr), list(nullptr) {};
            explicit Iterator(node<T> *p, List<T> *l);
            ~Iterator();
            void remove();
            Iterator& operator = (Iterator const &rhs);
            Iterator& operator++ (int);
            Iterator& operator++ ();
            Iterator& operator+= (int n);
            Iterator operator+ (int n);
            Iterator& operator-- (int);
            Iterator& operator-- ();
            Iterator& operator-= (int n);
            Iterator operator- (int n);
            T& operator* ();

         private:
            node<T> *cur;
            List<T> *list;
            void acquire(node<T> *p);
            void release(node<T> *p);
            void move(int n);
        };
        void insert(T k, List<T>::Iterator &iter);
        void remove(List<T>::Iterator &iter);
        Iterator begin();
     private:
        size_t size_;
        node<T>* head;
        node<T>* tail;
    };



/**__________________________________________________________________________________________________________________**/
/**----------------------------------------------IMPLEMENTATION------------------------------------------------------**/
/**^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^**/

    template<typename T>
    void List<T>::push_back(const T k) {
        size_++;
        auto tmp = new node<T>(k);
        if (!head) {
            head = tmp;
            tail = tmp;
        } else {
            tmp->prev = tail;
            tail->next = tmp;
            tail->ref_counter++;
            tmp->ref_counter++;
            tail = tmp;
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::push_front(const T k) {
        size_++;
        auto tmp = new node<T>(k);
        if (!head) {
            head = tmp;
            tail = tmp;
        } else {
            tmp->next = head;
            head->prev = tmp;
            head->ref_counter++;
            tmp->ref_counter++;
            head = tmp;
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::pop_back() {
        if (tail) {
            size_--;
            if (tail->prev) {
                tail->prev->next = nullptr;
                tail->ref_counter--;
            } else {
                if (tail->ref_counter == 0) {
                    delete tail;
                }
                head = nullptr;
                tail = nullptr;
                return;
            }
            auto tmp = tail;
            tail = tail->prev;
            if (tmp->ref_counter <= 0) {
                if (tmp->prev) {
                    tmp->prev->ref_counter--;
                }
                delete tmp;
            }
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::pop_front() {
        if (head) {
            size_--;
            if(head->next) {
                head->next->prev = nullptr;
                head->ref_counter--;
            } else {
                if (head->ref_counter == 0) {
                    delete head;
                }
                head = nullptr;
                tail = nullptr;
                return;
            }
            auto tmp = head;
            head = head->next;
            if (tmp->ref_counter <= 0) {
                if (tmp->next) {
                    tmp->next->ref_counter--;
                }
                delete tmp;
            }
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    size_t List<T>::size() {
        return size_;
    }

/**------------------------------------------------------------------------------------------------------------------**/
    template<typename T>
    typename List<T>::Iterator List<T>::begin() {
        return Iterator(head, this);
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::insert(T k, List<T>::Iterator &iter) {
        if (iter.cur == head) {
            push_front(k);
        } else {
            auto tmp = new node<T>(k);
            iter.cur->prev->next = tmp;
            tmp->next = iter.cur;
            tmp->ref_counter++;
            tmp->prev = iter.cur->prev;
            iter.cur->prev = tmp;
            tmp->ref_counter++;
            size_++;
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::remove(List<T>::Iterator &iter) {
        iter.remove();
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    T &List<T>::front() {
        return head->key;
    }

    template<typename T>
    T &List<T>::back() {
        return tail->key;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    bool List<T>::empty() {
        return (size_ == 0 && head == nullptr && tail == nullptr);
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::clear() {
        while (!empty()) {
            pop_front();
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    T &List<T>::operator[](const int index) {
        auto iter = begin();
        if (index >= 0) {
            iter += index;
        } else {
            iter += size();
            iter += index + 1;
        }
        return *iter;
    }

/**------------------------------------------------------------------------------------------------------------------**/

//    template<typename T>
//    void List<T>::swap(List<T> &other) {
//        node<T> *head_tmp = head;
//        node<T> *tail_tmp = tail;
//        size_t size_tmp = size_;
//        head = other.head;
//        tail = other.tail;
//        other.head = head_tmp;
//        other.tail = tail_tmp;
//        size_ = other.size_;
//        other.size_ = size_tmp
//    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::Iterator::move(int n) {
        if (n < 0) {
            while (n < 0) {
                n++;
                if (cur->prev) {
                    auto tmp = cur->prev;
                    acquire(tmp);
                    release(cur);
                    cur = tmp;
                } else break;
            }
        } else if (n > 0) {
            while (n > 0) {
                n--;
                if (cur->next) {
                    auto tmp = cur->next;
                    acquire(tmp);
                    release(cur);
                    cur = tmp;
                } else break;
            }
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::Iterator::remove() { ///Wanna some spaghetti?
        auto prev = cur->prev;
        auto next = cur->next;

        if (prev) {
            prev->next = next;
            cur->ref_counter--;
        }
        if (next) {
            next->prev = prev;
            cur->ref_counter--;
        }
        if (next) {
            if (list->size_ > 0) {
                list->size_--;
            }
            release(cur);
            acquire(next);
            cur = next;
            if (!cur->prev) {
                list->head = cur;
            }
        } else if (prev) {
            if (list->size_ > 0) {
                list->size_--;
            }
            release(cur);
            acquire(prev);
            cur = prev;
            if (!cur->next) {
                list->tail = cur;
            }
        } else {
            if (cur) {
                if (list->size_ > 0) {
                    list->size_--;
                }
                release(cur);
            }
            cur = nullptr;
            list->head = cur;
            list->tail = cur;
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::Iterator::acquire(node<T> *p) {
        if (p) {
            p->ref_counter++;
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    void List<T>::Iterator::release(node<T> *p) {
        if (p) {
            p->ref_counter--;
            if (p->ref_counter <= 0) {
                if (p->prev && p->next) {
                    delete p;
                } else if (p->prev) {
                    p->prev->ref_counter--;
                    delete p;
                } else if (p->next) {
                    p->next->ref_counter--;
                    delete p;
                } else {
                    if (list->tail == list->head && list->head == p && list->size() == 1) {
                        list->size_--;
                        list->tail = nullptr;
                        list->head = nullptr;
                    }
                    delete p;
                }
            }
        }
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    List<T>::Iterator::Iterator(node<T> *p, List<T> *l): cur(p), list(l) {
        acquire(p);
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator = (const List::Iterator &rhs) {
        auto tmp = cur;
        cur = rhs.cur;
        acquire(cur);
        release(tmp);
        list = rhs.list;
        return *this;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    T &List<T>::Iterator::operator*() {
        return cur->key;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator++(int) {
        if (cur->next) {
            auto tmp = cur->next;
            acquire(tmp);
            release(cur);
            cur = tmp;
        }
        return *this;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator--(int) {
        if (cur->prev) {
            auto tmp = cur->prev;
            acquire(tmp);
            release(cur);
            cur = tmp;
        }
        return *this;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator+=(int n) {
        move(n);
        return *this;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator-=(int n) {
        move(-n);
        return *this;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator List<T>::Iterator::operator+(int n) {
        Iterator tmp;
        tmp = *this;
        tmp += n;
        return tmp;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator List<T>::Iterator::operator-(int n) {
        auto tmp = *this;
        tmp -= n;
        return tmp;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    List<T>::Iterator::~Iterator() {
        release(cur);
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator++() {
        if (cur->next) {
            auto tmp = cur->next;
            acquire(tmp);
            release(cur);
            cur = tmp;
        }
        return *this;
    }

/**------------------------------------------------------------------------------------------------------------------**/

    template<typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator--() {
        if (cur->prev) {
            auto tmp = cur->prev;
            acquire(tmp);
            release(cur);
            cur = tmp;
        }
        return *this;
    }

/**------------------------------------------------------------------------------------------------------------------**/
}

#endif //LINKED_LIST_LINKED_LIST_H
