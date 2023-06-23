/**
 * @file stack.hpp
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic node class
 * @version 0.3
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
 */
#ifndef STACK_H
#define STACK_H
#include "sl_list.hpp"

/*!
 * @class stack  
 * @brief stack class.
 * 
 * @details A standard stack [LIFO] data structure. Made using SLL in sl_list.hpp. Supports synamic types, popping, pushing, inserting.
 * 
 * @fn push(T dt)
 * @fn pop()
 * @fn top()
 * @fn empty()
 * @fn insert(node<T>* nd, T dt)
 * @tparam T class
 */
template <class T>
class stack {
private:
  sl_list<T> item_list;   /**< Singly-Linked list to store the stack items*/
public:
  /**
   * Creates a new stack object, with an empty Singly-Linked list
   * @brief Default constructor 
   */
  stack()
    : item_list{sl_list<T>()} { }

  /**
   * @brief Inserts a value onto the top of the stack, and returns it
   * @param dt Data to append to the stack
   * @return Node pointer to the top of the stack 
   */
  node<T>* push(const T dt);

  /**
   * @brief Removes a value from the top of the stack, and returns the new top
   * @return Node pointer to the top of the stack 
   */
  node<T>* pop();

  /**
   * @brief Function to determine if the stack is empty
   * 
   * @return true if it's empty
   * @return false if it's NOT empty
   */
  bool empty();
  
  /**
   * @brief Returns the length/size of the stack
   * @return The size of the stack
   */
  unsigned int size() {return item_list.size();}

  /**
   * @brief Returns node pointer to the top of the stack
   * @return Stack's top node pointer
   */
  node<T>* top();
};

template <class T>
node<T>* stack<T>::push(const T dt) {
  return item_list.push_front(dt);
}

template <class T>
node<T>* stack<T>::pop() {
   return item_list.pop_front();
}

template <class T>
bool stack<T>::empty() {
  return size() == 0;
}

template <class T>
node<T>* stack<T>::top() {
  return item_list.get_head();
}

#endif // STACK_H