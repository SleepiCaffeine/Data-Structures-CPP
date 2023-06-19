#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H


/*!
 * @class double_node 
 * @brief double_node class.
 * 
 * @details A Node class, that has a pointer to a node in front and behind. This is an extention of the Node class.
 * 
 * @fn get_data()
 * @fn set_data(T dt)
 * @fn get_next()
 * @fn set_next(double_node<T>* const nd)
 * @fn get_behind()
 * @fn set_behind(double_node<T>* const nd)
 * @tparam T typename
 */
template <typename T>
class double_node {

protected:
    double_node<T>* next;
    double_node<T>* behind;
    T data;

public:
    /**
     * Creates a new double_node that points to NULL in both ways and has NULL data.
     * @brief Default constructor.
     * @see double_node(const T dt)    
     * @see double_node(double_node<T>* const nd, const T dt)
     * @see double_node(double_node<T>& const const nd)
     * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd, const T dt)
     */
    double_node() 
        : next{nullptr}, behind{nullptr} { };

    /**
     * Creates a new double_node that points to NULL in both ways, and has data.
     * @brief Constructor.
     * @param dt double_node data 
     * @see double_node()    
     * @see double_node(double_node<T>* const nd, const T dt)
     * @see double_node(double_node<T>& const nd)
     * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd)
     * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd, const T dt)
     */
    double_node(const T dt)
        : double_node{nullptr, nullptr, dt} { };

   /**
    * Creates a new double_node object that points to a double_node, and has data.
    * @note The parameter node will NOT point back to this node
    * @brief Constructor.
    * @param nd double_node to which it will point
    * @param dt double_node data
    * @see double_node(const T dt)
    * @see double_node()
    * @see double_node(double_node<T>& const nd)
    * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd)
    * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd, const T dt)
    */
    double_node(double_node<T>* const nd, const T dt)
        : next{nd}, data{dt} { };

    /**
     * Creates a new double_node object that points to 2 double_nodes, but has no data.
     * @note The 2 nodes provided as parameters will NOT point to this new node. You will have to either do this manually or use a DLL 
     * 
     * @param nnd double_node to which it will point
     * @param bnd double_node which will point to it
     * @see double_node(const T dt)
     * @see double_node()
     * @see double_node(double_node<T>* const nd, const T dt)
     * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd, const T dt)
     */
    double_node(double_node<T>* const nnd, double_node<T>* const bnd)
        : next{nnd}, behind{bnd} {}

    
    /**
     * Creates a new double_node object that points to 2 double_nodes, and has data
     * @note The 2 nodes provided as parameters will NOT point to this new node. You will have to either do this manually or use a DLL 
     * 
     * @param nnd double_node to which it will point
     * @param bnd double_node which will point to it
     * @param dt double_node data 
     * @see double_node(const T dt)
     * @see double_node()
     * @see double_node(double_node<T>& const nd)
     * @see double_node(double_node<T>* const nd, const T dt)
     * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd)
     */
    double_node(double_node<T>* const nnd, double_node<T>* const bnd, const T dt)
        : next{nnd}, behind{bnd}, data{dt}  {}
    
/** 
    * Construct a new double_node object from another double_node object.
    * @brief Copy constructor.
    * @param nd double_node object which will be copied
    * @see double_node(const T dt)
    * @see double_node()
    * @see double_node(double_node<T>* const nd, const T dt)
    * @see double_node(double_node<T>* const nnd, double_node<T>* bnd)
    * @see double_node(double_node<T>* const nnd, double_node<T>* const bnd, const T dt)
    */
    double_node(const double_node<T>& nd);

/**
    * @brief Get the pointer to the next double_node 
    * @return double_node object to which the current double_node object points to 
    * @see set_next(Node<T>* const nd)
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
     * @see set_behind(double_node<T>* const nd)
     */
    double_node<T>* get_behind() const;

    /**
     * @brief Set the pointer to the node behind the current double_node
     * @param *nd double_node object which points to the current double_node object
     * @see get_behind()
     */
    void set_behind(double_node<T>* const nd);

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
double_node<T>::double_node(const double_node<T>& nd) {
    next = new double_node<T>();
    behind = new double_node<T>();

    next = nd.get_next();
    behind = nd.get_behind();
    data = nd.get_data();
}

template <typename T>
void double_node<T>::set_behind(double_node<T>* const nd) {
    this->behind = nd;
}

template <typename T>
double_node<T>* double_node<T>::get_behind() const {
    return this->behind;
}

template <typename T>
void double_node<T>::set_next(double_node<T>* const nd) {
    this->next = nd;
}

template <typename T>
double_node<T>* double_node<T>::get_next() const {
    return this->next;
}

template <typename T>
T double_node<T>::get_data() const {
    return this->data;
}

template <typename T>
void double_node<T>::set_data(const T dt) {
    this->data = dt;
}

#endif // DOUBLE_NODE_H