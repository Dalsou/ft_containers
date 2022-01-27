#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include <iterator>

namespace ft {

    template <class T>
    class rbtree_iterator {

        public:

        /* ------------------------ ALIASES ----------------------- */
            typedef T                               value_type;
            typedef value_type*                     node_ptr;
            typedef typename T::value_type const    data_type;
            typedef data_type&                      reference;
            typedef const data_type&                const_reference;
            typedef data_type*                      pointer;
            typedef const data_type*                const_pointer;
            typedef typename std::ptrdiff_t         difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;
            node_ptr                                node;

        private :
        /* ------------------------ ATTRIBUTES ----------------------- */
            node_ptr                                root;
            node_ptr                                NIL;

        public :

        /* ------------------------ CONSTRUCTORS ----------------------- */

            ~rbtree_iterator() {}

            rbtree_iterator(node_ptr node, node_ptr root, node_ptr NIL) :
            node(node), root(root), NIL(NIL) {}

            rbtree_iterator() : node(), root(), NIL() {}

            rbtree_iterator(const rbtree_iterator& src) :
            node(src.node), root(src.root), NIL(src.NIL) {}

            operator rbtree_iterator<value_type const>() const {
                return rbtree_iterator<value_type const>(node, root, NIL);
            }

            rbtree_iterator& operator=(const rbtree_iterator &op) {
                if (this != &op) {
                    node = op.node;
                    root = op.root;
                    NIL = op.NIL;
                }
                return *this;
            }

        /* ------------------------ OPERATORS ----------------------- */

            bool operator==(const rbtree_iterator& op) const {
                return node == op.node;
            }

            bool operator!=(const rbtree_iterator& op) const {
                return node != op.node;
            }

            reference operator*() {
                return node->data;
            }

            const_reference operator*() const {
                return (node->data);
            }

            pointer operator->() {
                return &(operator*());
            }

            const_pointer operator->() const {
                return &(operator*());
            }

        /* ------------------------ INCREMENT ----------------------- */

            rbtree_iterator& operator++() {
                if (node != this->NIL)
                    node = this->_next();
                return *this;
            }

            rbtree_iterator operator++(int) {
                rbtree_iterator tmp(*this);

                ++(*this);
                return tmp;
            }

        /* ------------------------ DECREMENT ----------------------- */

            rbtree_iterator& operator--() {
                if (node != this->NIL)
                    node = this->_prev();
                else
                    node = this->_max(root);
                return *this;
            }

            rbtree_iterator operator--(int) {
                rbtree_iterator tmp(*this);

                --(*this);
                return tmp;
            }

        private :

            node_ptr    _min(node_ptr node) {
                while (node->left != this->NIL)
                    node = node->left;
                return node;
            }

            node_ptr    _max(node_ptr node) {
                while (node->right != this->NIL)
                    node = node->right;
                return node;
            }

            node_ptr    _prev() {
                node_ptr    node = node;
                node_ptr    prev = this->NIL;

                if (node->left != this->NIL)
                    return this->_max(node->left);
                prev = node->parent;
                while (prev != this->NIL && node == prev->left) {
                    node = prev;
                    prev = prev->parent;
                }
                return prev;
            }

            node_ptr    _next() {
                node_ptr    n = node;
                node_ptr    next = this->NIL;

                if (n->right != this->NIL)
                    return this->_min(n->right);
                next = n->parent;
                while (next != this->NIL && n == next->right) {
                    n = next;
                    next = next->parent;
                }
                return next;
            }

    }; // class rbtree_iterator 

} // namespace ft

#endif