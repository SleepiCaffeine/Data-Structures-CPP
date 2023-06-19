/**
 * @file linkedList-doc.h
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines multiple dynamic LinkedList classes
 * @version 0.2
 * @date 2023-06-19
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <cstddef>

#ifndef LL_DEF
#define LL_DEF
/*!
 * @class LL 
 * @brief Base linked list class.
 * 
 * @details A base linked_list class, which acts like a Singly-Linked List. Supports insertion, removal, and dynamic types.
 * 
 * @fn get_head()
 * @fn set_head(C* const nd)
 * @fn get_tail()
 * @fn set_tail(C* const nd)
 * 
 * @fn push_front(C* const nd)
 * @fn push_front(const T dt)
 * @fn push_back(C* const nd)
 * @fn push_back(const T dt)
 * @fn insert_node(C* const nd)
 * @fn insert_node(const T dt)
 * 
 * @fn pop_front()
 * @fn pop_back()
 * 
 * @fn length()
 * @fn size()
 * @tparam T typename
 */
template <class C, typename T>
struct linked_list {

private:
    C* head;
    C* tail;
    unsigned int len;

public:
    /**
     * Creates a new Singly linked-list with a head and tail that points to NULL, and has a length of 0
     * @brief Default constructor.
     * @see linked_list(std::nullptr_t)    
     * @see linked_list(C* const nd)
     * @see linked_list(C* const nd)
     */
    linked_list() 
        : linked_list(nullptr) {}

    linked_list(std::nullptr_t)
        : head{nullptr}, tail{nullptr}, len{0} { }
    
    linked_list(C* const nd)
        : head{nd}, len{1} {
            if (nd->get_next() == nullptr) {
                tail = nd;
                return;
            }

            C* currNode = new C(*nd);
            while(currNode->get_next() != nullptr) {
                ++len;
                currNode = currNode->get_next();
            }
            tail = currNode;
        }

    linked_list(C* const hnd, C* const tnd)
        : head{hnd}, tail{tnd}, len{1} {
            if (head == nullptr) {
                tail = nullptr;
                len = 0;
                return;
            }

            C* currNode = new C(*hnd);
            while(currNode != tnd) {
                ++len;
                currNode = currNode->get_next();
            }
        }

    // Deep-Copy constructor
    linked_list(const linked_list& list);

    // Destructor
    ~linked_list();

    // Param:     
    C* push_back(T dt);
    C* push_back(C* const nd);

    C* push_front(T dt);
    C* push_front(C* const nd);

    C* pop_back();
    C* pop_front();

    C* get_head() const;  /* hehehe */
    void set_head(C* const nd);
    void set_head(T dt);

    C* get_tail() const;
    void set_tail(C* const nd);
    void set_tail(T dt);

    /**
     * @brief Inserts the Node into the index provided
     * @param nd Node to be inserted
     * @param idx Index where the Node will be inserted
     * @return Pointer to the Node that is behind the inserted Node
     */
    C* insert_node(C* const nd, unsigned int idx);

    /** 
     * @brief Inserts a value into the index provided
     * @param dt Value to be inserted into the list
     * @param idx Index where the Node will be inserted
     * @return Pointer to the Node that is behind the inserted Node 
     */
    C* insert_node(T dt, unsigned int idx);

    /**
     * @brief Returns the length of the linked list
     * @return Length of LL 
     */
    unsigned int length() const {return len;}

    /**
     * @brief Returns the length of the linked list
     * @return Length of LL 
     */
    unsigned int size() const {return len;}
};

template <class C, typename T>
linked_list<C, T>::~linked_list() {
    while (head)
        head = head->get_next();

    delete head;
}

template <class C, typename T>
linked_list<C, T>::linked_list(const linked_list& list) {
    len = list.length();

    if (list.get_head() == nullptr)
        return;
    
    // Recreate the head
    C* newHead = new C();
    newHead->set_data(list.get_head()->get_data());
    head = newHead;

    // Deep-copy the remaining chain
    C* currNode = head;
    C* sourceNode = list.get_head()->get_next();

    while(sourceNode->get_next() != nullptr) {
        // Create a new Node in the list
        currNode->set_next(new C());
        // Set its value to source value
        currNode->get_next()->set_data(sourceNode->get_data());
        // Set the destination to null
        currNode->get_next()->set_next(nullptr);
        // Move over by one Node in the list
        currNode = currNode->get_next();
        // Move over by one Node in the source
        sourceNode = sourceNode->get_next();
    }

    currNode->set_next(tail);
    tail = new C(*sourceNode);
};

template <class C, typename T>
C* linked_list<C, T>::push_front(T dt) {
    if (!len) {
        C* newNode = new C(dt);
        head = newNode;
        tail = newNode;
        ++len;
        return head;
    }

    head = new C(head, dt);
    ++len;
    return head;
}


template <class C, typename T>
C* linked_list<C ,T>::push_front(C* const nd) {
    if (!len) {
        head = nd;
        tail = nd;
        ++len;
        return head;
    }

    auto oldHead = head;
    nd->set_next(oldHead);
    head = nd;
    ++len;
    return nd;
}

template <class C, typename T>
C* linked_list<C, T>::push_back(T dt) {
    // If the list is empty, set both the head and tail to be the inserted node
    if (!len) {
        C* newNode = new C(dt);
        head = newNode;
        tail = newNode;
        ++len;
        return tail;
    }

    C* newTail = new C(dt);
    C* oldTail = new C(tail->get_data());
    oldTail->set_next(newTail);

    C* currNode = head;

    // Traverse the list
    while (currNode->get_next()->get_next() != nullptr)
        currNode = currNode->get_next();

    // Add the Node to the end
    currNode->set_next(oldTail);
    ++len;

    tail = new C(nullptr, dt);
    return tail;
}

template <class C, typename T>
C* linked_list<C, T>::push_back(C* const nd) {
    // If the list is empty, then set both the head and the tail to the parameter node
    if (!len) {
        head = nd;
        tail = nd;
        ++len;
        return tail;
    }

    C* currNode = head;
    C* oldTail = new C(tail->get_data());
    oldTail->set_next(nd);

    // Traverse the list
    while (currNode->get_next() != tail)
        currNode->get_next();

    // Add the Node to the end
    currNode->set_next(oldTail);
    tail = new C(nd->get_next(), nd->get_data());
    ++len;
    // Return the tail
    return tail;
}

template <class C, typename T>
C* linked_list<C, T>::pop_back() {
    if (len == 1) {
        --len;
        delete head;
        delete tail;
        return nullptr;
    }

    C* currNode = head;

    // Traversing until the second-to-last list Node
    while (currNode->get_next()->get_next() != nullptr)
        currNode = currNode->get_next();

    // Set last list member to null
    currNode->set_next(nullptr);
    tail = currNode;

    --len;

    // Return the new last member
    return tail;
}

template <class C, typename T>
C* linked_list<C, T>::pop_front() {
    if (len == 1) {
        --len;
        delete head;
        delete tail;
        return nullptr;
    }

    head = head->get_next();
    --len;
    return head;
}

template <class C, typename T>
C* linked_list<C, T>::insert_node(C* const nd, unsigned int idx) {
    C* currentNode = head;
    unsigned int counter = 0;
    while (counter < idx - 1) {
        currentNode = currentNode->get_next();
        ++counter;
    }
    C* nextAfter = currentNode->get_next();
    currentNode->set_next(nd);
    nd->set_next(nextAfter);

    ++len;

    return nd;
}

template <class C, typename T>
C* linked_list<C, T>::insert_node(const T dt, unsigned int idx) {
    C* currentNode = head;
    unsigned int counter = 0;
    while (counter < idx - 1) {
        currentNode = currentNode->get_next();
        ++counter;
    }

    currentNode->set_next(new C(currentNode->get_next(), dt));
    ++len;

    return currentNode->get_next();
}

template <class C, typename T>
C* linked_list<C, T>::get_head() const {
    return head;
}

template <class C, typename T>
void linked_list<C, T>::set_head(C* const nd) {
    this->head = nd;
}

template <class C, typename T> 
void linked_list<C, T>::set_head(T dt) {
    this->pop_front();
    this->push_front(dt);
}

template <class C, typename T>
C* linked_list<C, T>::get_tail() const {
    return tail;
}

template <class C, typename T>
void linked_list<C, T>::set_tail(C* const nd) {
    this->pop_back();
    this->push_back(nd);
}

template <class C, typename T>
void linked_list<C, T>::set_tail(T dt) {
    this->pop_back();
    this->push_back(dt);
}

#endif // LL_DEF

#endif // LINKED_LIST_H