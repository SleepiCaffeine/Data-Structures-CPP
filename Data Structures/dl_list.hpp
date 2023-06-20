/**
 * @file dl_list.h
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic Doubly-linked list class
 * @version 0.1
 * @date 2023-06-20
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "double_node.hpp"
#include <cstddef>
#include <stdexcept>
#include <iostream>

/*!
 * @class dl_list
 * @brief Doubly-Linked List (dl_list) Class.
 * 
 * @details A Doubly-linked list data structure class, which supports insertion, removal, and dynamic types. Due to being Doubly-linked it can only be used with double_node<T>. See double_node.h on how to use them.
 * 
 * @fn get_head()
 * @fn set_head(double_node<T>* const nd)
 * @fn get_tail()
 * @fn set_tail(double_node<T>* const nd)
 * 
 * @fn push_front(double_node<T>* const nd)
 * @fn push_front(const T dt)
 * @fn push_back(double_node<T>* const nd)
 * @fn push_back(const T dt)
 * @fn insert_node(double_node<T>* const nd)
 * @fn insert_node(const T dt)
 * 
 * @fn pop_front()
 * @fn pop_back()
 * 
 * @fn get_data()
 * @fn set_data(T dt)
 * 
 * @fn length()
 * @fn size()
 * @fn update_len()
 * @tparam T typename
 */
template <typename T>
class dl_list {

private:
    double_node<T>* head;      /**< Pointer to the head (or root) node [double_node<T>*]*/         
    double_node<T>* tail;      /**< Pointer to the tail node [double_node<T>*]*/
    unsigned int len;          /**< List's length [unsigned int]*/

public:
    /**
     * Creates a new sl-list with a head and tail that points to NULL, and has a length of 0
     * @brief Default constructor. 
     * @see ~dl_list()
     * @see dl_list(double_node<T>* const nd)
     * @see dl_list(const double_node<T>& nd)
     * @see dl_list(double_node<T>* const hnd, double_node<T>* const tnd)
     */
    dl_list() 
        : head{nullptr}, tail{nullptr}, len{0} {}

    /**
     * Creates a new sl-list with a head node
     * @brief Constructor.
     * @see dl_list()
     * @see ~dl_list()
     * @see dl_list(const double_node<T>& nd)
     * @see dl_list(double_node<T>* const hnd, double_node<T>* const tnd)
     */
    dl_list(double_node<T>* const nd)
        : head{nd}, len{1} {
            // If the head is the only node
            if (nd->get_next() == nullptr) {
                tail = nd;
                return;
            }

            // Traverse the list to get the correct length
            double_node<T>* currNode = new double_node<T>(*nd);
            while(currNode->get_next() != nullptr) {
                ++len;
                currNode = currNode->get_next();
            }

            // Set the tail to be the end node
            tail = currNode;
        }

    /**
     * Creates a new sl-list with a head node, and a tail node
     * @brief Constructor.
     * @see dl_list()
     * @see ~dl_list()
     * @see dl_list(double_node<T>* const nd)
     * @see dl_list(const double_node<T>& nd)
     */
    dl_list(double_node<T>* const hnd, double_node<T>* const tnd)
        : head{hnd}, tail{tnd}, len{1} {
            // If the head is null
            if (head == nullptr) {
                tail = nullptr;
                len = 0;
                return;
            }

            // Traverse the list until we reach the tail to get the correct length
            double_node<T>* currNode = new double_node<T>(*hnd);
            while(currNode != tnd) {
                ++len;
                currNode = currNode->get_next();
            }
        }

    /**
     * Constructs a new sl-list from another dl_list object
     * @brief Copy constructor.
     * @see dl_list()
     * @see ~dl_list()
     * @see dl_list(double_node<T>* const nd)
     * @see dl_list(const double_node<T>& nd)
     */
    dl_list(const dl_list& list);

    /**
     * Destroys the dl_list object
     * @brief Destructor.
     * @see dl_list()
     * @see dl_list(double_node<T>* const nd)
     * @see dl_list(const double_node<T>& nd)
     * @see dl_list(double_node<T>* const hnd, double_node<T>* const tnd)
     */
    ~dl_list();

    /**
     * Adds a node with the provided value to the end of the list
     * @param T node data
     * @returns The new list's tail
     * @see push_back(double_node<T>* const nd)
     * @see push_front(T dt)
     * @see push_front(double_node<T>* const nd)
     * */     
    double_node<T>* push_back(T dt);

    /**
     * Adds a node with the to the end of the list
     * @param nd Node to be added
     * @returns The new list's tail
     * @see push_back(T dt)
     * @see push_front(T dt)
     * @see push_front(double_node<T>* const nd)
     * */  
    double_node<T>* push_back(double_node<T>* const nd);

    /**
     * Adds a node with the provided value to the front of the list
     * @param T node data
     * @returns The new list's head
     * @see push_front(double_node<T>* const nd)
     * @see push_back(T dt)
     * @see push_back(double_node<T>* const nd)
     * */  
    double_node<T>* push_front(T dt);

    /**
     * Adds a node with the to the front of the list
     * @param nd Node to be added
     * @returns The new list's head
     * @see push_front(T dt)
     * @see push_back(T dt)
     * @see push_back(double_node<T>* const nd)
     * */  
    double_node<T>* push_front(double_node<T>* const nd);

    /**
     * Removes a node from the end of the list
     * @returns The new list's tail
     * @see pop_front()
     * */  
    double_node<T>* pop_back();

    /**
     * Removes a node from the front of the list
     * @returns The new list's head
     * @see pop_back()
     * */  
    double_node<T>* pop_front();

    /**
     * Returns the head of the dl_list
     * @returns Head node
     * @see set_head(T dt)
     * @see set_head(double_node<T>* const nd)
     * */  
    double_node<T>* get_head() const; 

    /**
     * Sets the provided node to be the list's head
     * @note This may ruin the list, be careful. If you want to swap values, look at void dl_list<T>::set_head(T dt)
     * @param nd Node to be the new head
     * @see set_head(T dt)
     * @see get_head()
    */
    void set_head(double_node<T>* const nd);

    /**
     * Changes the head's data to the provided node
     * @param dt The new head's data
     * @see set_head(double_node<T>* const nd)
     * @see get_head()
    */
    void set_head(T dt);

    /**
     * Returns the tail of the dl_list
     * @returns Tail node
     * @see set_tail(T dt)
     * @see set_tail(double_node<T>* const nd)
     * */  
    double_node<T>* get_tail() const;

    /**
     * Sets the tail of the dl_list to the provided node
     * @note This may ruin the list, be careful. If you want to swap values, look at void dl_list<T>::set_tail(T dt) 
     * @param nd Node to be set as the tail node
     * @see set_tail(T dt)
     * @see get_tail()
     * */ 
    void set_tail(double_node<T>* const nd);

    /**
     * Sets the data of the tail of the dl_list to the provided data value
     * @param dt The new data value the tail will store
     * @see set_tail(double_node<T>* const nd)
     * @see get_tail()
     * */ 
    void set_tail(T dt);

    /**
     * Inserts the Node into the index provided
     * @param nd Node to be inserted
     * @param idx Index where the Node will be inserted
     * @return Pointer to the Node that is behind the inserted Node
     */
    double_node<T>* insert_node(double_node<T>* const nd, unsigned int idx);

    /** 
     * Inserts a value into the index provided
     * @param dt Value to be inserted into the list
     * @param idx Index where the Node will be inserted
     * @return Pointer to the Node that is behind the inserted Node 
     */
    double_node<T>* insert_node(T dt, unsigned int idx);
    
    /**
     * Returns the length of the sl list
     * @return Length of LL
     * @see size()
     */
    unsigned int length() {
        update_len();
        return len;}

    /**
     * Returns the length of the sl list
     * @return Length of LL
     * @see length()
     */
    unsigned int size() {
        update_len();
        return len;}

    /**
     * Updates the length of the sl_list (Mainly kept to avoid bugs, will later implement other features to avoid using this)
     */
    void update_len() {
        len = 0;
        double_node<T>* currNode = new double_node<T>(*(this->get_head()));
        while (currNode != nullptr) {
            currNode = currNode->get_next();
            ++len;
        }
    }
};

template <typename T>
dl_list<T>::~dl_list() {
    while (head)
        head = head->get_next();

    delete head;
}

template <typename T>
dl_list<T>::dl_list(const dl_list& list) {
    len = list.length();

    if (list.get_head() == nullptr)
        return;
    
    // Recreate the head
    double_node<T>* newHead = new double_node<T>();
    newHead->set_data(list.get_head()->get_data());
    head = newHead;

    // Deep-copy the remaining chain
    double_node<T>* currNode = head;
    double_node<T>* sourceNode = list.get_head()->get_next();

    while(sourceNode->get_next() != nullptr) {
        // Create a new Node in the list
        currNode->set_next(new double_node<T>());
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
    tail = new double_node<T>(*sourceNode);
};

template <typename T>
double_node<T>* dl_list<T>::push_front(T dt) {
     // If the list has a length of 0, create a node for the head, and set the tail to nullptr
    if (!len) {
        head = new double_node<T>(dt);
        tail = nullptr;
        ++len;
        return head;
    }

    if (len == 1) {
        tail = head;
        head = new double_node<T>(dt);
        head->set_next(tail);
        tail->set_prev(head);
        ++len;
        return head;
    }
    // Create a new head object with the provided data and pointing to the head itself
    head = new double_node<T>(head, dt);
    ++len;
    return head;
}

template <typename T>
double_node<T>* dl_list<T>::push_front(double_node<T>* const nd) {
    // If the list has a length of 0, create a node for the head, and set the tail to nullptr
    if (!len) {
        head = new double_node<T>(*nd);
        tail = nullptr;
        ++len;
        return head;
    }

    if (len == 1) {
        tail = head;
        head = new double_node<T>(*nd);
        head->set_next(tail);
        tail->set_prev(head);
        ++len;
        return head;
    }

    // Swap head and provided node
    auto oldHead = new double_node<T>(*head);
    oldHead->set_prev(nd);
    nd->set_next(oldHead);
    head = new double_node<T>(*nd);

    ++len;
    return head;
}

template <typename T>
double_node<T>* dl_list<T>::push_back(T dt) {
    // If the list is empty, set both the head and tail to be the inserted node
    if (!len) {
        head = new double_node<T>(dt);
        tail = nullptr;
        ++len;
        return head;
    }

    if (len == 1) {
        tail = new double_node<T>(dt);
        head->set_next(tail);
        tail->set_prev(head);
        ++len;
        return head;
    }

    double_node<T>* currNode = head;
    double_node<T>* newTail = new double_node<T>(dt);
    double_node<T>* oldTail = new double_node<T>(newTail, tail->get_prev(), tail->get_data());
    newTail->set_prev(oldTail);
    tail = newTail;

    // Traverse the list
    while (currNode->get_next()->get_next() != nullptr)
        currNode = currNode->get_next();

    // Add the Node to the end
    currNode->set_next(oldTail);
    ++len;

    return tail;
}

template <typename T>
double_node<T>* dl_list<T>::push_back(double_node<T>* const nd) {
    // If the list is empty, then set both the head and the tail to the parameter node
    if (!len) {
        head = new double_node<T>(*nd);
        tail = nullptr;
        ++len;
        return head;
    }

    else if (len == 1) {
        tail = new double_node<T>(*nd);
        head->set_next(tail);
        tail->set_prev(head);
        ++len;
        return tail;
    }

    double_node<T>* currNode = head;
    double_node<T>* oldTail = new double_node<T>(*tail);
    oldTail->set_next(nd);

    nd->set_prev(oldTail);
    tail = nd;

    // Traverse the list
    while (currNode->get_next()->get_next() != nullptr)
        currNode = currNode->get_next();

    // Add the Node to the end
    currNode->set_next(oldTail);
    ++len;

    // Return the tail
    return tail;
}

template <typename T>
double_node<T>* dl_list<T>::pop_back() {
    if (len <= 0) {
        len = 0;
        return nullptr;
    }

    else if (len == 1) {
        --len;
        head = nullptr;
        return nullptr;
    }

    double_node<T>* currNode = head;

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

template <typename T>
double_node<T>* dl_list<T>::pop_front() {
    if (len <= 0) {
        len = 0;
        return nullptr;
    }

    else if (len == 1) {
        --len;
        delete head;
        delete tail;
        return nullptr;
    }

    head = head->get_next();
    head->set_prev(nullptr);
    --len;
    return head;
}

template <typename T>
double_node<T>* dl_list<T>::insert_node(double_node<T>* const nd, unsigned int idx) {
    if (idx == 0) {
        this->push_front(nd);
        return head;
    }

    else if (idx >= this->size()) {
        throw std::invalid_argument("Provided index exceeds list length. Use push_back().\n");
    }

    double_node<T>* currentNode = head;
    unsigned int counter = 0;
    while (counter < idx - 1) {
        currentNode = currentNode->get_next();
        ++counter;
    }
    double_node<T>* nextAfter = currentNode->get_next();
    currentNode->set_next(nd);
    nd->set_prev(currentNode);

    nd->set_next(nextAfter);
    nextAfter->set_prev(nd);

    ++len;

    return nd;
}

template <typename T>
double_node<T>* dl_list<T>::insert_node(const T dt, unsigned int idx) {
    if (idx == 0) {
        this->push_front(dt);
        return head;
    }

    else if (idx >= this->size())
        throw std::invalid_argument("Provided index exceeds list length. Use push_back().\n");

    double_node<T>* currentNode = head;
    unsigned int counter = 0;
    while (counter < idx - 1) {
        currentNode = currentNode->get_next();
        ++counter;
    }
    auto insertedNode = new double_node<T>(currentNode->get_next(), dt);

    currentNode->set_next(insertedNode);
    insertedNode->set_prev(currentNode);
    ++len;

    return currentNode->get_next();
}

template <typename T>
double_node<T>* dl_list<T>::get_head() const {
    return head;
}

template <typename T>
void dl_list<T>::set_head(double_node<T>* const nd) {
    head = nd;
}

template <typename T> 
void dl_list<T>::set_head(T dt) {
    this->pop_front();
    this->push_front(dt);
}

template <typename T>
double_node<T>* dl_list<T>::get_tail() const {
    return tail;
}

template <typename T>
void dl_list<T>::set_tail(double_node<T>* const nd) {
    this->pop_back();
    this->push_back(nd);
}

template <typename T>
void dl_list<T>::set_tail(T dt) {
    this->pop_back();
    this->push_back(dt);
}

#endif // DOUBLY_LINKED_LIST_H