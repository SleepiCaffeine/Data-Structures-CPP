/**
 * @file node.h
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic node class
 * @version 0.21
 * @date 2023-06-21
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */

#ifndef NODE_H
#define NODE_H
/*!
 * @class node  
 * @brief node class.
 * 
 * @details A standard Node data structure that is used as a base unit in many other data structures. Supports insertion, removal, and dynamic types.
 * 
 * @fn get_data()
 * @fn set_data(T dt)
 * @fn get_next()
 * @fn set_next(Node<T>* nd)
 * @fn forward()
 * @tparam T typename
 */
template <typename T>
class node {
private:
    node<T>* next;  /**< Pointer to the next node [node<T>*]*/
    T data;         /**< Data which is stored in the Node [T]*/

public:
    /**
     * Creates a new node that points to NULL both ways, but has NULL data.
     * @brief Default constructor.
     */
    node()
        : next{nullptr}, data{} { }

    /**
     * Creates a new node that points to NULL both ways, and has data.
     * @brief Constructor.
     * @param dt node data.
     */
    node(const T dt)
        : next{nullptr}, data{dt} { }

    /**
     * Creates a new node that points to a node forward, but not backward, and has data.
     * @brief Constructor.
     * @param nd node to which it will point.
     * @param dt node data.
     */
    node(node<T>* const nd, const T dt)
        : next{nd}, data{dt} { }

    /**
     * Creates a new node that points to a node in both ways, and has data.
     * @brief Constructor.
     * @param nnd node to which it points to next.
     * @param dt node data.
     */
    node(node<T>* const nnd, node<T>*, const T dt)
        : next{nnd}, data{dt} { }

    /**
     * Construct a new node from another node object.
     * @brief Copy constructor.
     * @param nd node to copy from.
     */
    node(const node<T>& nd)
        : next{nd.next}, data{nd.data} { }


    /**
     * @brief Get the node's data.
     * @return node data.
     */
    T get_data() const {
        return this->data;
    }

    /**
     * @brief Set the current node's data.
     * @param dt new node data.
     */
    void set_data(const T dt) {
        this->data = dt;
    }

    /**
     * @brief Get the pointer to the next node.
     * @return node object to which the current node object points to next.
     */
    node<T>* get_next() const {
        return this->next;
    }

    /**
     * @brief Set the pointer to the next node.
     * @param nd new node object to which the current node object will point to next.
     */
    void set_next(node<T>* const nd) {
        this->next = nd;
    }

    /**
     * @brief Set current node to the next node.
     */
    void forward() {
        if (this->next) {
            this->data = next->get_data();
            this->next = next->get_next();
        }
    }
};

#endif // NODE_H