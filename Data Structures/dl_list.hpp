/**
 * @file dl_list.hpp
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic Doubly-linked list class
 * @version 0.3
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "double_node.hpp"
#include <cstddef>
#include <stdexcept>

/*!
 * @class dl_list
 * @brief Doubly-Linked List (dl_list) Class.
 * 
 * @details A Doubly-linked list data structure class, which supports insertion, removal, and dynamic types. Due to being Doubly-linked it can only be used with double_node<T>. See double_node.h on how to use them.
 * 
 * @fn get_head()
 * @fn set_head(double_node<T>* const nd)
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
 * @fn size()
 * @tparam T class
 */
template <class T>
class dl_list {

private:
    double_node<T>* head;      /**< Pointer to the head (or root) node [double_node<T>*]*/         
    unsigned int len;          /**< List's length [unsigned int]*/

public:
    /**
     * Creates a new sl-list with a head and tail that points to NULL, and has a length of 0
     * @brief Default constructor. 
     * @see dl_list(const double_node<T>& nd)
     */
    dl_list() 
        : head{nullptr}, tail{nullptr}, len{0} {}

    /**
     * Constructs a new sl-list from another dl_list object
     * @brief Copy constructor.
     * @see dl_list()
     */
    dl_list(const dl_list& list);

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
     * Returns the length of the dl list
     * @return Length of the list
     */
    unsigned int size() {return len;}
};

template <class T>
dl_list<T>::dl_list(const dl_list& list) {
    len = list.len;
    double_node<T>* newNd = new double_node<T>(*(list.get_head()));
    head = newNd;
};

template <class T>
double_node<T>* dl_list<T>::push_front(T dt) {
    return push_front(new double_node<T>(dt));
}

template <class T>
double_node<T>* dl_list<T>::push_front(double_node<T>* const nd) {
    // Create new node to insert
    double_node<T>* newNode = new double_node<T>();

    // Make new head
    newNode->set_data(nd->get_data());
    newNode->set_next(head);
    
    // Replace old head with new
    head = newNode;
    ++len;

    return head;
}

template <class T>
double_node<T>* dl_list<T>::push_back(T dt) {
    return push_back(new double_node<T>(dt));
}

template <class T>
double_node<T>* dl_list<T>::push_back(double_node<T>* const nd) {
    // Set pointer node
    double_node<T>* currNode = head;

    double_node<T>* newTail = new double_node<T>(nd->get_data());
    // Traverse the list
    while (currNode->get_next() != nullptr)
        currNode = currNode->get_next();

    // Add the Node to the end
    currNode->set_next(newTail);
    newTail->set_prev(currNode);
    ++len;

    // Return the new "tail"
    return newTail;
}

template <class T>
double_node<T>* dl_list<T>::pop_back() {
    // Error case
    if (len <= 0) {
        throw std::invalid_argument("Invalid removal. List length is 0.\n");
    }

    else if (len == 1) {
        --len;
        delete head;
        return nullptr;
    }

    // Set pointer node
    node<T>* currNode = head;

    // Traversing until the second-to-last list Node
    while (currNode->get_next()->get_next() != nullptr)
        currNode = currNode->get_next();

    // Set last list member to null
    delete(currNode->get_next());
    currNode->set_next(nullptr);
    --len;

    // Return the new last member
    return currNode;
}

template <class T>
double_node<T>* dl_list<T>::pop_front() {
    // Self-explanatory
    if (head == nullptr)
         return nullptr;

    // Move over head by one node, and return it
    node<T>* temp = head;
    head = head->get_next();
    delete temp;
    return head;
}

template <class T>
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

    return currentNode;
}

template <class T>
double_node<T>* dl_list<T>::insert_node(const T dt, unsigned int idx) {
    return insert_node(new double_node<T>(dt), idx);
}

template <class T>
double_node<T>* dl_list<T>::get_head() const {
    return head;
}

template <class T>
void dl_list<T>::set_head(double_node<T>* const nd) {
    head = nd;
}

template <class T> 
void dl_list<T>::set_head(T dt) {
    this->pop_front();
    this->push_front(dt);
}

#endif // DOUBLY_LINKED_LIST_H