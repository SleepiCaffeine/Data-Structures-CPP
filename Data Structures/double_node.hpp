/**
 * @file double_node.hpp
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic double_node class
 * @version 0.3
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */

#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

/*!
 * @class double_node 
 * @brief double_node class.
 * 
 * @details A Node class, that has a pointer to a node in front and behind. It has all of the functionalities of the node class, however it does NOT inherit it.
 * 
 * @fn get_data()
 * @fn set_data(T dt)
 * @fn get_next()
 * @fn set_next(double_node<T>* const nd)
 * @fn get_prev()
 * @fn set_prev(double_node<T>* const nd)
 * @tparam T typename
 */
template <typename T>
class double_node {

protected:  
    double_node<T>* next;   /**< Pointer to the next node [double_node<T>]*/
    double_node<T>* prev;   /**< Pointer to the previous node [double_node<T>*]*/
    T data;                 /**< Data which is stored in the Node [T]*/

public:
    /**
     * Creates a new double_node that points to NULL in both ways and has NULL data.
     * @brief Default constructor.
     * @see double_node(const T dt)
     * @see double_node(double_node<T>* const nd)
     * @see double_node(double_node<T>& const nd)
     * @see double_node(double_node<T>* const nd, const T dt)
     */
    double_node() 
        : next{nullptr}, prev{nullptr} { };

    /**
     * Creates a new double_node that points to NULL in both ways, and has data.
     * @brief Constructor.
     * @param dt double_node data 
     * @see double_node()
     * @see double_node(double_node<T>* const nd)
     * @see double_node(double_node<T>& const nd) 
     * @see double_node(double_node<T>* const nd, const T dt)
     */
    double_node(const T dt)
        : double_node{nullptr, nullptr, dt} { };

    /**
     * Creates a new double_node that points to NULL in both ways, and has data.
     * @brief Constructor.
     * @param dt double_node data 
     * @see double_node()
     * @see double_node(const T dt)
     * @see double_node(double_node<T>& const nd)  
     * @see double_node(double_node<T>* const nd, const T dt)
     */
    double_node(double_node<T>* const nd)
        : next{nd}, prev{nullptr} { }

   /**
    * Creates a new double_node object that points to a double_node, and has data.
    * @note The parameter node will NOT point back to this node
    * @brief Constructor.
    * @param nd double_node to which it will point
    * @param dt double_node data
    * @see double_node()
    * @see double_node(const T dt)
    * @see double_node(double_node<T>* const nd)
    * @see double_node(double_node<T>& const nd
    */
    double_node(double_node<T>* const nd, const T dt)
        : next{nd}, data{dt} { }
    
/** 
    * Construct a new double_node object from another double_node object.
    * @brief Copy constructor.
    * @param nd double_node object which will be copied
    * @see double_node()
    * @see double_node(const T dt)
    * @see double_node(double_node<T>* nd)
    * @see double_node(double_node<T>* const nd, const T dt
    */
    double_node(const double_node<T>& nd);

/**
    * @brief Get the pointer to the next double_node 
    * @return double_node object to which the current double_node object points to 
    * @see set_next(double_node<T>* const nd)
    */
    double_node<T>* get_next() const;

    /**
     * @brief Set the pointer to the next Node
     * @param *nd double_node object to which the current double_node object will point to
     * @see get_next()
     */
    void set_next(double_node<T>* const nd);

    /**
     * @brief Get the pointer to the node behind the current double_node
     * @return double_node object which points to this double_node
     * @see set_prev(double_node<T>* const nd)
     */
    double_node<T>* get_prev() const;

    /**
     * @brief Set the pointer to the node behind the current double_node
     * @param *nd double_node object which points to the current double_node object
     * @see get_prev()
     */
    void set_prev(double_node<T>* const nd);

        /**
     * @brief Get the double node's data
     * @return double_node data
     * @see setData(const T dt)
     */
    T get_data() const;

    /**
     * @brief Set the current double node's data
     * @param dt new double_node data
     * @see getData() 
     */
    void set_data(const T dt);
};

template <typename T>
double_node<T>::double_node(const double_node<T>& nd)
    : next{nd.get_next()}, prev{nd.get_prev()}, data{nd.get_data()} { }

template <typename T>
void double_node<T>::set_prev(double_node<T>* const nd) {
    prev = nd;
}

template <typename T>
double_node<T>* double_node<T>::get_prev() const {
    return prev;
}

template <typename T>
void double_node<T>::set_next(double_node<T>* const nd) {
    next = nd;
}

template <typename T>
double_node<T>* double_node<T>::get_next() const {
    return next;
}

template <typename T>
T double_node<T>::get_data() const {
    return data;
}

template <typename T>
void double_node<T>::set_data(const T dt) {
    data = dt;
}

#endif // DOUBLE_NODE_H