/**
 * @file bst.hpp
 * @author Vakaris Michejenko (sleepicaffeine@gmail.com)
 * @brief  A header that defines a dynamic binary search tree class
 * @version 0.1
 * @date 2023-06-21
 * @copyright Copyright (c) 2023
 * @link https://github.com/SleepiCaffeine
*/

#ifndef BST_HPP
#define BST_HPP

/*!
 * @class bst_node
 * @brief Binary Search Tree Node class.
 * 
 * @details A Node class tailored to work with binary search trees.
 * 
 * @tparam T typename
 */
template <class T>
class bst_node {
public:
  bst_node<T>* left;    /**< Pointer to the left branch of this node*/
  bst_node<T>* right;   /**< Pointer to the right branch of this node.*/
  bst_node<T>* parent;  /**< Pointer to the parent node of this node.*/
  T data;               /**< Data that this node contains.*/

  /**
   * Creates a new bst_node object, that points to null in every direction, and has no data value.
   * @brief Default Constructor.
   * @see bst_node(T dt)
   */
  bst_node()
    : bst_node{T()} { }

  /**
   * Creates a new bst_node object, that points to null in every direction, and has provided data value.
   * @brief Constructor.
   * @see bst_node()
   */
  bst_node(T dt) 
    : left{nullptr}, right{nullptr}, parent{nullptr}, data{dt} { }
};

/*!
 * @class bst
 * @brief Binary Search Tree class.
 * 
 * @details A non-linear, hierarchical data structure class, a very simple and common data structure. Supports insertion, deletion, searching, and dynamic types.
 * 
 * @see bst_node<T>* insert(T dt)
 * @see bst_node<T>* insert(bst_node<T>* nd, T data)
 *
 * @see bst_node<T>* find(bst_node<T>* nd, T dt)
 * @see bst_node<T>* find(T dt)
 *
 * @see bst_node<T>* min(bst_node<T>* nd)
 * @see bst_node<T>* min()
 *
 * @see bst_node<T>* max(bst_node<T>* nd)
 * @see bst_node<T>* max()
 *
 * @see bst_node<T>* successor(bst_node<T>* nd)
 * @see bst_node<T>* successor(T dt)
 *
 * @see bst_node<T>* predecessor(bst_node<T>* nd)
 * @see bst_node<T>* predecessor(T dt)
 *
 * @see bst_node<T>* remove(bst_node<T>* nd, T dt)
 * @see bst_node<T>* remove(T dt)
 *
 * @see bst_node<T>* get_root()
 * 
 * @tparam T typename
 */
template <class T>
class bst {
private:
  bst_node<T>* root;  /**< Pointer to the root node of this tree*/

public:
  /**
   * Creates a new bst object, that has a nullptr root.
   * @brief Default Constructor.
   * @see bst(T dt)
   */
  bst()
    : root{nullptr} { }

  /**
   * Creates a new bst object, that has a root with the provided data value.
   * @brief Constructor.
   * @see bst()
   */
  bst(T dt)
    : root{new bst_node<T>(dt)} { }
  
  /**
   * @brief Inserts a node with the provided data value into the tree, starting from the root.
   * @param dt Node data value to be inserted.
   * @return The newly inserted node [nullptr if no node was inserted].
   * @see bst_node<T>* insert(bst_node<T>* nd, T data).
   */
  bst_node<T>* insert(T dt);

  /**
   * @brief Inserts a node with the provided data value into the tree, starting from the provided node.
   * @note This function is used recursively for other purposes! Keep in mind, the value will be inserted from the provided node. This may break the list! Look at bst_node::insert(T dt).
   * @param nd Node from which to search for a valid place to insert the node.
   * @param dt Node data value to be inserted.
   * @return The newly inserted node [nullptr if no node was inserted].
   * @see insert(T dt)
   */
  bst_node<T>* insert(bst_node<T>* nd, T data);

  /**
   * @brief Returns the node which contains the provided data value, starting from the provided node.
   * @note This function is used recursively for other purposes! Keep in mind, the data value will be looked for from the provided node. This may not find the node! Look at bst_node::find(T dt).
   * @param nd Node from which to search for the desired value.
   * @param dt Node data value to be found.
   * @return The found node [nullptr if no node was found or didn't exist].
   * @see find(T dt)
   */
  bst_node<T>* find(bst_node<T>* nd, T dt);

  /**
   * @brief Returns the node which contains the provided data value, starting from the root.
   * @param dt Node data value to be inserted.
   * @return The found node [nullptr if no node was found or didn't exist].
   * @see find(bst_node<T>* nd, T dt)
   */
  bst_node<T>* find(T dt);

  /**
   * @brief Returns the smallest data value in the tree, starting from the provided node.
   * @param nd Node from which the minimum data value is looked for.
   * @return The node with the smallest data value.
   * @see min(bst_node<T>* nd)
   */
  bst_node<T>* min(bst_node<T>* nd);

  /**
   * @brief Returns the smallest data value in the tree, starting from the root.
   * @return Node with the smallest data value.
   * @see min(bst_node<T>* nd)
   */
  bst_node<T>* min();

  /**
   * @brief Returns the largest data value in the tree, starting from the provided node.
   * @param nd Node from which the maximum data value is looked for .
   * @return The node with the largest data value.
   * @see max()
   */
  bst_node<T>* max(bst_node<T>* nd);

  /**
   * @brief Returns the largest data value in the tree, starting from the root.
   * @return Node with the largest data value.
   * @see min(bst_node<T>* nd)
   */
  bst_node<T>* max();

  /**
   * @brief Returns the [successor](https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/) of the provided node.
   * @param nd Node who's successor is looked for.
   * @return Pointer to the successor.
   */
  bst_node<T>* successor(bst_node<T>* nd);

  /**
   * @brief Returns the [successor](https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/) of the node, which contains the provided data value.
   * @param dt The data value of the node who's successor is looked for.
   * @return Pointer to the successor.
   */
  bst_node<T>* successor(T dt);

  /**
   * @brief Returns the [predecessor](https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/) of the provided node.
   * @param nd Node who's predecessor is looked for.
   * @return Pointer to the predecessor.
   */
  bst_node<T>* predecessor(bst_node<T>* nd);

  /**
   * @brief Returns the [predecessor](https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/) of the node, which contains the provided data value.
   * @param dt The data value of the node who's predecessor is looked for.
   * @return Pointer to the predecessor.
   */
  bst_node<T>* predecessor(T dt);

  /**
   * @brief Removes the node that contains the provided data value from the provided node.
   * @param nd Node from which to look for the node to be removed
   * @param dt The data value of the node which is being deleted
   * @return The deleted node
   */
  bst_node<T>* remove(bst_node<T>* nd, T dt);

  /**
   * @brief Removes the node that contains the provided data value from the root.
   * @param dt The data value of the node which is being deleted
   * @return The deleted node
   */
  bst_node<T>* remove(T dt);

  /**
   * @brief Returns pointer to the root of this tree.
   * @return The pointer to the root.
   */
  bst_node<T>* get_root() const {return root;}
};

template <class T>
bst_node<T>* bst<T>::insert(bst_node<T>* nd, T dt) {
  // If a point where the node should be inserted has been reached
  if (nd == nullptr)
    nd = new bst_node<T>(dt);

  // If the node should be right of the current node,
  // And update the parent status of the nodes (there might've been a divorce)
  else if (nd->data < dt) {
    nd->right = insert(nd->right, dt);
    nd->right->parent = nd;
  }

  // Opposite is true for the left side
  else {
    nd->left = insert(nd->left, dt);
    nd->left->parent = nd;
  }

  // This point will only be reached when nd == nullptr,
  // In which case, the newly creted node is returned
  return nd;
}

template <class T>
bst_node<T>* bst<T>::insert(T dt) {
  // Traverses the whole list until a suitable position is found
  // And updates the root to hold the updated tree
  bst_node<T>* inserted_node = insert(root, dt);
  root = inserted_node;
  return inserted_node;
} 

template <class T>
bst_node<T>* bst<T>::find(bst_node<T>* nd, T dt) {
  // Found it :)
  if (nd->data == dt)
    return nd;

  // If we've reached a dead end, return null
  else if (nd == nullptr)
    return nullptr;

  // If we can go left, then do so 
  else if (dt > nd->data)
    return find(nd->right, dt);
  
  // Go right I guess...
  else
    return find(nd->left, dt);
}

template <class T>
bst_node<T>* bst<T>::find(T dt) {
  // Search from the root
  return find(root, dt);
}

template <class T>
bst_node<T>* bst<T>::min(bst_node<T>* nd) {
  // If the procided node was null
  if (nd == nullptr)
    return nullptr;

  // If we've hit a leaf node - return it
  if (nd->left == nullptr)
    return nd;

  // Otherwise keep searching
  return min(nd->left);
}

template <class T>
bst_node<T>* bst<T>::min() {
  // Search from the top
  return min(root);
}

template <class T>
bst_node<T>* bst<T>::max(bst_node<T>* nd) {
  // If the procided node was null
  if (nd == nullptr)
    return nullptr;

  // If we've hit a leaf node - return it
  if (nd->right == nullptr)
    return nd;

  // Otherwise keep searching
  return max(nd->right);
}

template <class T>
bst_node<T>* bst<T>::max() {
  // Search from the top
  return max(root);
}

template <class T>
bst_node<T>* bst<T>::successor(bst_node<T>* nd) {
  // If the node has a right sub-tree - find the smallest value within that sub-tree
  if (nd->right != nullptr)
    return min(nd->right);

  else {
    bst_node<T>* parent_node = nd->parent;
    bst_node<T>* curr_node = nd;

    // While we can still traverse ancestors
    // And while traversing, we're going UP in data value
    while ((parent_node != nullptr) &&
           (curr_node == parent_node->right)) {

      // Move up by 1 level
      curr_node = parent_node;
      parent_node = curr_node->parent;
    }
    
    // Either we hit nullptr
    // Or the first ancestor, which is smaller than the original node!
    return parent_node;
  }
}

template <class T>
bst_node<T>* bst<T>::successor(T dt) {
  // Get the node which we're trying to find the successor of
  bst_node<T>* who_to_find = find(root, dt);

  // Should be pretty clear...
  // ...otherwise, what are you doing here?
  return successor(who_to_find);
}

template <class T>
bst_node<T>* bst<T>::predecessor(bst_node<T>* nd) {
  // If the node has a left sub-tree - find the largest value within that sub-tree
  if (nd->left != nullptr)
    return max(nd->left);

  else {
    bst_node<T>* parent_node = nd->parent;
    bst_node<T>* curr_node = nd;

    // While we can still traverse ancestors
    // And while traversing, we're going DOWN in data value
    while ((parent_node != nullptr) &&
           (curr_node == parent_node->left)) {
      
      // Move up by 1 level
      curr_node = parent_node;
      parent_node = curr_node->parent;
    }

    // Either we hit nullptr
    // Or the first ancestor, which is larger than the original node!
    return parent_node;
  }
}

template <class T>
bst_node<T>* bst<T>::predecessor(T dt) {
  // Node which to find
  bst_node<T>* who_to_find = find(root, dt);

  // Welp, good luck figuring this out
  return predecessor(who_to_find);
}

template <class T>
bst_node<T>* bst<T>::remove(bst_node<T>* nd, T dt) {
  // If the node doesn't exist
  if (nd == nullptr)
    return nullptr;

  // If the desired node has been reached 
  if (nd->data == dt) {
    // If the node is a leaf node
    if (nd->left == nullptr && nd->right == nullptr)
      nd = nullptr;

    // If the node only has a right child
    else if (nd->left == nullptr && nd->right != nullptr) {
      // Move the child one level up
      nd->right->parent = nd->parent;

      // Move over
      nd = nd->right;
    }

    // If the node only has a left child
    else if (nd->left != nullptr && nd->right == nullptr) {
      // Move the child one level up
      nd->left->parent = nd->parent;
      
      // Move over
      nd = nd->left;
    }

    else {
      // Get the desired node's successor
      bst_node<T>* curr_succ = successor(dt);
      // Set the current node's data to the desired node's successor data
      nd->data = curr_succ->data;
      // Keep looking down right
      nd->right = remove(nd->right, curr_succ->data);
    }
  }

  // If the desired node is on the right side, look there ig...
  else if (nd->data < dt)
    nd->right = remove(nd->right, dt);

  // If all else fails, go left, since it's the only one left
  else
    nd->left = remove(nd->left, dt);

  // Return the deleted node
  return nd;
}

template <class T>
bst_node<T>* bst<T>::remove(T dt) {
  bst_node<T>* deleted_node = remove(root, dt);
  root = deleted_node;
  return deleted_node;
}

#endif // BST_HPP