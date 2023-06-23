/**
 * @file sl_list.hpp
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic singly-linked list class
 * @version 0.3
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "node.hpp"
#include <cstddef>

/*!
 * @class sl_list
 * @brief Singly-Linked List (sl_list) Class.
 * 
 * @details A Singly-linked list data structure class, which supports insertion, removal, and dynamic types. Due to being Singly-linked it can only be used with node<T>. See node.h on how to use them.
 * 
 * @fn get_head()
 * @fn set_head(node<T>* const nd)
 * 
 * @fn push_front(node<T>* const nd)
 * @fn push_front(const T dt)
 * @fn push_back(node<T>* const nd)
 * @fn push_back(const T dt)
 * @fn insert_node(node<T>* const nd)
 * @fn insert_node(const T dt)
 * 
 * @fn pop_front()
 * @fn pop_back()
 * 
 * @fn size()
 * @tparam T class
 */
template <class T>
class sl_list {

private:
    node<T>* head;      /**< Pointer to the head node [node<T>*]*/         
    unsigned int len;   /**< List's length [unsigned int]*/

public:
    /**
     * Creates a new sl-list with a head and tail that points to NULL, and has a length of 0
     * @brief Default constructor. 
     * @see sl_list(const sl_list& list)
     */
    sl_list() 
        : head{nullptr}, len{0} { }

    /**
     * Constructs a new sl-list from another sl_list object
     * @brief Copy constructor.
     * @see sl_list()
     */
    sl_list(const sl_list& list);

    /**
     * Adds a node with the provided value to the end of the list
     * @param T node data
     * @returns The list's new tail
     * @see push_back(node<T>* const nd)
     * @see push_front(T dt)
     * @see push_front(node<T>* const nd)
     * */     
    node<T>* push_back(T dt);

    /**
     * Adds a node with the to the end of the list
     * @param nd Node to be added
     * @returns Thelist's new tail
     * @see push_back(T dt)
     * @see push_front(T dt)
     * @see push_front(node<T>* const nd)
     * */  
    node<T>* push_back(node<T>* const nd);

    /**
     * Adds a node with the provided value to the front of the list
     * @param T node data
     * @returns The list's new head
     * @see push_front(node<T>* const nd)
     * @see push_back(T dt)
     * @see push_back(node<T>* const nd)
     * */  
    node<T>* push_front(T dt);

    /**
     * Adds a node with the to the front of the list
     * @param nd Node to be added
     * @returns The list's new head
     * @see push_front(T dt)
     * @see push_back(T dt)
     * @see push_back(node<T>* const nd)
     * */  
    node<T>* push_front(node<T>* const nd);

    /**
     * Removes a node from the end of the list
     * @returns The list's last node
     * @see pop_front()
     * */  
    node<T>* pop_back();

    /**
     * Removes a node from the front of the list
     * @returns The list's new head
     * @see pop_back()
     * */  
    node<T>* pop_front();

    /**
     * Returns the head of the sl_list
     * @returns Head node
     * @see set_head(T dt)
     * @see set_head(node<T>* const nd)
     * */  
    node<T>* get_head() const; 

    /**
     * Sets the provided node to be the list's head
     * @note This may ruin the list, be careful. If you want to swap values, look at sl_list<T>::set_head(T dt)
     * @param nd Node to be the new head
     * @see set_head(T dt)
     * @see get_head()
    */
    void set_head(node<T>* const nd);

    /**
     * Changes the head's data to the provided data value
     * @param dt The head's new data
     * @see set_head(node<T>* const nd)
     * @see get_head()
    */
    void set_head(T dt);

    /**
     * Inserts the Node into the index provided
     * @param nd Node to be inserted
     * @param idx Index where the Node will be inserted
     * @return Pointer to the Node that is behind the inserted Node
     */
    node<T>* insert_node(node<T>* const nd, unsigned int idx);

    /** 
     * Inserts a value into the index provided
     * @param dt Value to be inserted into the list
     * @param idx Index where the Node will be inserted
     * @return Pointer to the Node that is behind the inserted Node 
     */
    node<T>* insert_node(T dt, unsigned int idx);

    /**
     * Returns the length of the sl_list
     * @return Length of the singly-linked list
     * @see length()
     */
    unsigned int size() {
        return len;
    }
};

template <class T>
sl_list<T>::sl_list(const sl_list& list) {
    len = list.len;
    head = list.head;
};

template <class T>
node<T>* sl_list<T>::push_front(T dt) {
    // Delagate action to more precise function
    return push_front(new node<T>(dt));
}

template <class T>
node<T>* sl_list<T>::push_front(node<T>* const nd) {
    // Create new node to insert
    node<T>* newNode = new node<T>();

    // Make new head
    newNode->set_data(nd->get_data());
    newNode->set_next(head);

    // Replace old head with new
    head = newNode;
    ++len;

    return head;
}

template <class T>
node<T>* sl_list<T>::push_back(T dt) {
    // Delagate action to more precise function
    return push_back(new node<T>(dt));
}

template <class T>
node<T>* sl_list<T>::push_back(node<T>* const nd) {
    // Set pointer node
    node<T>* currNode = head;
    node<T>* newTail = new node<T>(nd->get_next(), nd->get_data());
    // Traverse the list
    while (currNode->get_next() != nullptr)
        currNode = currNode->get_next();

    // Add the Node to the end
    currNode->set_next(newTail);
    ++len;

    // Return the new "tail"
    return newTail;
}

template <class T>
node<T>* sl_list<T>::pop_back() {
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
node<T>* sl_list<T>::pop_front() {
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
node<T>* sl_list<T>::insert_node(node<T>* const nd, unsigned int idx) {
    // Delegate to push_front, since that's already implemented
    if (idx == 0) {
        this->push_front(nd);
        return head;
    }   

    // Out of range check
    else if (idx >= this->size()) {
        throw std::invalid_argument("linked list out of range. Use push_back() instead.\n");
    }

    // Set pointer node
    node<T>* currentNode = head;

    // Travel to desired index
    unsigned int counter = 0;
    while (counter < idx - 1) {
        currentNode = currentNode->get_next();
        ++counter;
    }

    // Save tyhe next node
    node<T>* nextAfter = currentNode->get_next();
    // Insert node
    currentNode->set_next(nd);
    // Re-link list
    nd->set_next(nextAfter);
    ++len;
    return currentNode;
}

template <class T>
node<T>* sl_list<T>::insert_node(const T dt, unsigned int idx) {
    return insert_node(new node<T>(dt), idx);
}

template <class T>
node<T>* sl_list<T>::get_head() const {
    return head;
}

template <class T>
void sl_list<T>::set_head(node<T>* const nd) {
    pop_front();
    push_front(nd);
}

template <class T> 
void sl_list<T>::set_head(T dt) {
    head->set_data(dt);
}

#endif // SINGLY_LINKED_LIST_H