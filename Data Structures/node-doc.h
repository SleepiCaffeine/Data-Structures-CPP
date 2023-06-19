/**
 * @file node-doc.h
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic Node struct
 * @version 0.1
 * @date 2023-06-15
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */

#ifndef NODE_H
#define NODE_H
/*!
 * @class node  
 * @brief node struct.
 * 
 * @details A standard Node data structure that is used as a base unit in many other data structures. Supports insertion, removal, and dynamic types.
 * 
 * @fn get_data()
 * @fn set_data(T dt)
 * @fn get_next()
 * @fn set_next(node<T>* nd)
 * @fn forward()
 * @tparam T typename
 */
template <class T>
class Node {
private:
    Node* next;  /**< Pointer to the next Node (Node<T>*)*/
    T data;      /**< Data which is stored in the node (T)*/
public:
    /**
     * Creates a new node that points to NULL and has NULL data.
     * @brief Default constructor.
     * @see Node(const T dt)    
     * @see Node(Node<T>* const nd, const T dt)
     * @see Node(Node<T>& const nd)
     */
    Node() 
        : next{nullptr} { };

    /**
     * Creates a new node that points to NULL and has data.
     * @brief Constructor.
     * @param dt node data 
     * @see Node()    
     * @see Node(Node<T>* const nd, const T dt)
     * @see Node(Node<T>& const nd)
     */
    Node (const T dt)
        : Node{nullptr, dt} { };

   /**
    * Creates a new node that points to a node, and has data.
    * @brief Constructor.
    * @param nd node to which it will point
    * @param dt node data
    * @see Node(const T dt)
    * @see Node()
    * @see Node(Node<T>& const nd)
    */
    Node(Node<T>* const nd, const T dt)
        : next{nd}, data{dt} { };
    
/** 
    * Construct a new node from another node object.
    * @brief Copy constructor.
    * @param nd node to which it will point
    * @see Node(const T dt)
    * @see Node()
    * @see Node(Node<T>* const nd, const T dt)
    */
    Node(const Node<T>& nd);

    /**
     * @brief Get the node's data
     * @return node data
     * @see setData(const T dt)
     */
    T get_data() const;

    /**
     * @brief Set the current node's data
     * @param dt new node data
     * @see getData() 
     */
    void set_data(const T dt);

    /**
     * @brief Get the pointer to the next node 
     * @return node object to which the current node object points to 
     * @see setNext(Node<T>* const nd)
     */
    Node<T>* get_next() const;

    /**
     * @brief Set the pointer to the next node
     * @param *nd new node object to which the current node object will point to
     * @see getNext()
     */
    void set_next(Node<T>* const nd);

    /**
     * @brief Set current node to the next node
     */
    void forward();
};


template <typename T>
Node<T>::Node(const Node<T>& nd) {
    this->next = new Node<T>();
    this->next = nd.get_next();
    this->data = nd.get_data();
}

template <typename T>
T Node<T>::get_data() const {
    return this->data;
}

template <typename T>
void Node<T>::set_data(const T dt) {
    this->data = dt;
}

template <typename T>
Node<T>* Node<T>::get_next() const {
    return this->next;
}

template <typename T>
void Node<T>::set_next(Node<T>* const nd) {
    this->next = nd;
}

template <typename T>
void Node<T>::forward() {
    data = next->get_data();
    next = next->get_next();
}
#endif // NODE_H