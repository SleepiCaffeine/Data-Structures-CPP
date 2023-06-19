#include "node.h"

template <typename T>
class DoubleNode {
private:
    DoubleNode<T>* next;   /**< Pointer to the next DoubleNode (DoubleNode<T>*) */
    DoubleNode<T>* prev;   /**< Pointer to the previous DoubleNode (DoubleNode<T>*) */
    T data;                /**< Data which is stored in the (T)*/ 

public:
    /**
     * Creates a new DoubleNode that points to NULL and has NULL data.
     * @brief Default constructor.
     */
    DoubleNode()
        : next{nullptr}, prev{nullptr} {}

    /**
     * Creates a new DoubleNode that points to NULL and has data.
     * @brief Constructor.
     * @param dt DoubleNode data.
     */
    DoubleNode(const T dt)
        : next{nullptr}, prev{nullptr}, data{dt} {}

    DoubleNode(DoubleNode<T>* nd, const T dt)
        : next{nd}, prev{nullptr}, data{dt} { }

    /**
     * Creates a new DoubleNode that points to a node, is pointed to by a DoubleNode and has data.
     * @brief Constructor.
     * @param prv previous DoubleNode to which it will point.
     * @param nd Node to which it will point.
     * @param dt DoubleNode data.
     */
    DoubleNode(DoubleNode<T>* const nnd, DoubleNode<T>* const prv, const T dt)
        : next{nnd}, prev{prv}, data{dt} {}

    /**
     * Construct a new DoubleNode from another DoubleNode object.
     * @brief Copy constructor.
     * @param nd DoubleNode to copy from.
     */
    DoubleNode(const DoubleNode<T>& nd)
        : next{nd.next}, prev{nd.prev}, data{nd.data} {}

    /**
     * @brief Get the DoubleNode's data.
     * @return DoubleNode data.
     */
    T get_data() const {
        return this->data;
    }

    /**
     * @brief Set the current DoubleNode's data.
     * @param dt new DoubleNode data.
     */
    void set_data(const T dt) {
        this->data = dt;
    }

    /**
     * @brief Get the pointer to the next DoubleNode.
     * @return DoubleNode object to which the current DoubleNode object points to next.
     */
    DoubleNode<T>* get_next() const {
        return this->next;
    }

    /**
     * @brief Set the pointer to the next DoubleNode.
     * @param nd new DoubleNode object to which the current DoubleNode object will point to next.
     */
    void set_next(DoubleNode<T>* const nd) {
        this->next = nd;
    }

    /**
     * @brief Get the pointer to the previous DoubleNode.
     * @return DoubleNode object to which the current DoubleNode object points to.
     */
    DoubleNode<T>* get_behind() const {
        return prev;
    }
    
    /**
     * @brief Set the pointer to the previous DoubleNode.
     * @param prv new DoubleNode object to which the current DoubleNode object will point to.
     * @tparam U Type of the object being set as behind (can be either Node or DoubleNode).
     */
    template <typename U>
    void set_behind(U* const prv) {
        prev = dynamic_cast<DoubleNode<T>*>(prv);
        if (!prev) {
            // prv is not a DoubleNode, so try casting to Node
            Node<T>* node = dynamic_cast<Node<T>*>(prv);
            if (node)
                prev = new DoubleNode<T>(node, node->get_data());
       }
    }

    /**
     * @brief Move the current node to the previous node.
     */
    void backward() {
        if (this->prev) {
            this->next = prev->get_next();
            this->data = prev->get_data();
            this->prev = prev->get_behind();
        }
    }
};