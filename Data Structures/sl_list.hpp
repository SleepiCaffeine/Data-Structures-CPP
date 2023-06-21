/**
 * @file sl_list.h
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic singly-linked list class
 * @version 0.2
 * @date 2023-06-20
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
 * @fn get_tail()
 * @fn set_tail(node<T>* const nd)
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
 * @fn length()
 * @fn size()
 * @fn upadate_len()
 * @tparam T typename
 */
template <typename T>
class sl_list {

private:
    node<T>* head;      /**< Pointer to the head (or root) node [node<T>*]*/         
    node<T>* tail;      /**< Pointer to the tail node [node<T>*]*/
    unsigned int len;   /**< List's length [unsigned int]*/

public:
    /**
     * Creates a new sl-list with a head and tail that points to NULL, and has a length of 0
     * @brief Default constructor. 
     * @see ~sl_list()
     * @see sl_list(node<T>* const nd)
     * @see sl_list(const node<T>& nd)
     * @see sl_list(node<T>* const hnd, node<T>* const tnd)
     */
    sl_list() 
        : sl_list{nullptr, nullptr} {}

    /**
     * Creates a new sl-list with a head node
     * @brief Constructor.
     * @see sl_list()
     * @see ~sl_list()
     * @see sl_list(const node<T>& nd)
     * @see sl_list(node<T>* const hnd, node<T>* const tnd)
     */
    sl_list(node<T>* const nd)
        : head{nd}, len{1} {
            // If the head is the only node
            if (nd->get_next() == nullptr) {
                tail = nullptr;
                return;
            }

            // Traverse the list to get the correct length
            node<T>* currNode = new node<T>(*nd);
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
     * @see sl_list()
     * @see ~sl_list()
     * @see sl_list(node<T>* const nd)
     * @see sl_list(const node<T>& nd)
     */
    sl_list(node<T>* const hnd, node<T>* const tnd)
        : head{hnd}, tail{tnd}, len{1} {
            // Added to avoid any future issues with poor definitions
            if (hnd == nullptr || tnd == nullptr) {
                head = nullptr;
                tail = nullptr;
                len = 0;
                return;
            }

            // Traverse the list until we reach the tail to get the correct length
            node<T>* currNode = new node<T>(*hnd);
            while(currNode != tnd) {
                ++len;
                currNode = currNode->get_next();
            }
        }

    /**
     * Constructs a new sl-list from another sl_list object
     * @brief Copy constructor.
     * @see sl_list()
     * @see ~sl_list()
     * @see sl_list(node<T>* const nd)
     * @see sl_list(const node<T>& nd)
     */
    sl_list(const sl_list& list);

    /**
     * Destroys the sl_list object
     * @brief Destructor.
     * @see sl_list()
     * @see sl_list(node<T>* const nd)
     * @see sl_list(const node<T>& nd)
     * @see sl_list(node<T>* const hnd, node<T>* const tnd)
     */
    ~sl_list();

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
     * @returns The list's new tail
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
     * @note This may ruin the list, be careful. If you want to swap values, look at void sl_list<T>::set_head(T dt)
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
     * Returns the tail of the sl_list
     * @returns Tail node
     * @see set_tail(T dt)
     * @see set_tail(node<T>* const nd)
     * */  
    node<T>* get_tail() const;

    /**
     * Sets the tail of the sl_list to the provided node
     * @note This may ruin the list, be careful. If you want to swap values, look at void sl_list<T>::set_tail(T dt) 
     * @param nd Node to be set as the tail node
     * @see set_tail(T dt)
     * @see get_tail()
     * */ 
    void set_tail(node<T>* const nd);

    /**
     * Sets the data of the tail of the sl_list to the provided data value
     * @param dt The new data value the tail will store
     * @see set_tail(node<T>* const nd)
     * @see get_tail()
     * */ 
    void set_tail(T dt);

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
     * @see size()
     */
    unsigned int length() {
        update_len();
        return len;
    }

    /**
     * Returns the length of the sl_list
     * @return Length of the singly-linked list
     * @see length()
     */
    unsigned int size() {
        update_len();
        return len;
    }

    /**
     * Updates the length of the sl_list (Mainly kept to avoid bugs, will later implement other features to avoid using this)
     */
    void update_len() {
        len = 0;
        node<T>* currNode = new node<T>(*(this->get_head()));
        while (currNode != nullptr) {
            currNode = currNode->get_next();
            ++len;
        }
    }
};

template <typename T>
sl_list<T>::~sl_list() {
    while (head)
        head = head->get_next();

    delete head;
}

template <typename T>
sl_list<T>::sl_list(const sl_list& list) {
    len = list.length();

    if (list.get_head() == nullptr)
        return;
    
    // Recreate the head
    node<T>* newHead = new node<T>();
    newHead->set_data(list.get_head()->get_data());
    head = newHead;

    // Deep-copy the remaining chain
    node<T>* currNode = head;
    node<T>* sourceNode = list.get_head()->get_next();

    while(sourceNode->get_next() != nullptr) {
        // Create a new Node in the list
        currNode->set_next(new node<T>());
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
    tail = new node<T>(*sourceNode);
};

template <typename T>
node<T>* sl_list<T>::push_front(T dt) {
     // If the list has a length of 0, set the list's head and tail to the same node
    if (!len) {
        node<T>* newNode = new node<T>(dt);
        head = newNode;
        tail = newNode;
        ++len;
        return head;
    }

    if (len == 1) {
        tail = head;
        head = new node<T>(dt);
        head->set_next(tail);
        ++len;
        return head;
    }

    // Create a new head object with the provided data and pointing to the head itself
    head = new node<T>(head, dt);
    ++len;
    return head;
}

template <typename T>
node<T>* sl_list<T>::push_front(node<T>* const nd) {
    // If the list has a length of 0, set the list's head and tail to the same node
    if (!len) {
        head = nd;
        tail = nullptr;
        ++len;
        return head;
    }

    if (len == 1) {
        tail = head;
        head = new node<T>(*nd);
        head->set_next(tail);
        ++len;
        return head;
    }

    // Swap head and nd
    auto oldHead = head;
    nd->set_next(oldHead);
    head = nd;
    ++len;
    return nd;
}

template <typename T>
node<T>* sl_list<T>::push_back(T dt) {
    // If the list is empty, set both the head and tail to be the inserted node
    if (!len) {
        head = new node<T>(dt);
        tail = nullptr;
        ++len;
        return head;
    }

    else if (len == 1) {
        tail = new node<T>(dt);
        head->set_next(tail);
        ++len;
        return tail;
    }

    node<T>* currNode = head;
    node<T>* newTail = new node<T>(dt);
    node<T>* oldTail = new node<T>(newTail, tail->get_data());
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
node<T>* sl_list<T>::push_back(node<T>* const nd) {
    // If the list is empty, then set both the head and the tail to the parameter node
    if (!len) {
        head = new node<T>(*nd);
        tail = nullptr;
        ++len;
        return head;
    }

    else if (len == 1) {
        tail = new node<T>(*nd);
        head->set_next(tail);
        ++len;
        return tail;
    }

    node<T>* currNode = head;
    node<T>* oldTail = new node<T>(nd, tail->get_data());
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
node<T>* sl_list<T>::pop_back() {
    if (len <= 0) {
        len = 0;
        return nullptr;
    }

    else if (len == 1) {
        --len;
        head = nullptr;
        tail = nullptr;
        return nullptr;
    }

    node<T>* currNode = head;

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
node<T>* sl_list<T>::pop_front() {
    if (len <= 0) {
        len = 0;
        return nullptr;
    }

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

template <typename T>
node<T>* sl_list<T>::insert_node(node<T>* const nd, unsigned int idx) {
    if (idx == 0) {
        this->push_front(nd);
        return head;
    }

    else if (idx >= this->size()) {
        throw std::invalid_argument("Provided index exceeds list length. Use push_back().\n");
    }

    node<T>* currentNode = head;
    unsigned int counter = 0;
    while (counter < idx - 1) {
        currentNode = currentNode->get_next();
        ++counter;
    }
    node<T>* nextAfter = currentNode->get_next();
    currentNode->set_next(nd);
    nd->set_next(nextAfter);

    ++len;

    return nd;
}

template <typename T>
node<T>* sl_list<T>::insert_node(const T dt, unsigned int idx) {
    if (idx == 0) {
        this->push_front(dt);
        return head;
    }

    else if (idx >= this->size()) {
        throw std::invalid_argument("Provided index exceeds list length. Use push_back().\n");
    }

    node<T>* currentNode = head;
    unsigned int counter = 0;
    while (counter < idx - 1) {
        currentNode = currentNode->get_next();
        ++counter;
    }

    currentNode->set_next(new node<T>(currentNode->get_next(), dt));
    ++len;

    return currentNode->get_next();
}

template <typename T>
node<T>* sl_list<T>::get_head() const {
    return head;
}

template <typename T>
void sl_list<T>::set_head(node<T>* const nd) {
    head = nd;
}

template <typename T> 
void sl_list<T>::set_head(T dt) {
    this->pop_front();
    this->push_front(dt);
}

template <typename T>
node<T>* sl_list<T>::get_tail() const {
    return tail;
}

template <typename T>
void sl_list<T>::set_tail(node<T>* const nd) {
    this->pop_back();
    this->push_back(nd);
}

template <typename T>
void sl_list<T>::set_tail(T dt) {
    this->pop_back();
    this->push_back(dt);
}

#endif // SINGLY_LINKED_LIST_H