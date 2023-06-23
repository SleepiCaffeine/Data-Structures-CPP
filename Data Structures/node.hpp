/**
 * @file node.hpp
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic node class
 * @version 0.3
 * @date 2023-06-24
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
        return data;
    }

    /**
     * @brief Set the current node's data.
     * @param dt new node data.
     */
    void set_data(const T dt) {
        data = dt;
    }

    /**
     * @brief Get the pointer to the next node.
     * @return node object to which the current node object points to next.
     */
    node<T>* get_next() const {
        return next;
    }

    /**
     * @brief Set the pointer to the next node.
     * @param nd new node object to which the current node object will point to next.
     */
    void set_next(node<T>* const nd) {
        next = nd;
    }
};

#endif // NODE_H