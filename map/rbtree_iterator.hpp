#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include <iostream>
#include "../shared/utils.hpp"

namespace ft {

    template <typename T, typename node_pointer>
    class rbtree_iterator {

        public:

        /* ------------------------ ALIASES ----------------------- */
            typedef T                               value_type;
            typedef value_type*                     pointer;
            typedef value_type&                     reference;
            typedef typename std::ptrdiff_t         difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;

        protected:
        /* ------------------------ ATTRIBUTES ----------------------- */
            node_pointer                            _ptr;

        public :

        /* ------------------------ CONSTRUCTORS ----------------------- */

            rbtree_iterator() : 
            _ptr(NULL) {}

            rbtree_iterator(node_pointer ptr) :
            _ptr(ptr) {}

            virtual ~rbtree_iterator() {}

            rbtree_iterator(const rbtree_iterator& src) :
            _ptr(src._ptr) {}


            rbtree_iterator& operator=(const rbtree_iterator& op) {
                if (this != &op)
                    this->_ptr = op._ptr;
                return *this;
            }

        /* ------------------------ OPERATORS ----------------------- */

            reference operator*() const {
                return this->_ptr->value;
            }

            pointer operator->() const {
                return &(operator*());
            }

            node_pointer    get_node() {
                return this->_ptr;
            }

            node_pointer    get_node()  const {
                return this->_ptr;
            }

            operator rbtree_iterator<const T, node_pointer>() const {
                return rbtree_iterator<const T, node_pointer>(this->_ptr);
            }

            template <typename It>
            bool operator==(const rbtree_iterator<It, node_pointer>& op) const {
                return (this->_ptr == op.get_node());
            }

            template <typename It>
            bool operator!=(const rbtree_iterator<It, node_pointer>& op) const {
                return (this->_ptr != op.get_node());
            }

        /* ------------------------ INCREMENT ----------------------- */

            rbtree_iterator& operator++() {
                this->_increase();
                return *this;
            }

            rbtree_iterator operator++(int) {
                rbtree_iterator tmp(*this);

                ++(*this);
                return tmp;
            }

        /* ------------------------ DECREMENT ----------------------- */

            rbtree_iterator& operator--() {
                this->_decrease();
                return *this;
            }

            rbtree_iterator operator--(int) {
                rbtree_iterator tmp(*this);

                --(*this);
                return tmp;
            }

        private :

            void    _increase() {
                if (this->_ptr->right) {
                    this->_ptr = this->_ptr->right;
                    while (this->_ptr->left)
                        this->_ptr = this->_ptr->left;
                }
                else {
                    node_pointer tmp = this->_ptr;
                    this->_ptr = this->_ptr->parent;
                    while (this->_ptr->left != tmp) {
                        tmp = this->_ptr;
                        this->_ptr = this->_ptr->parent;
                    }
                }
            }

            void    _decrease() {
                if (this->_ptr->left) {
                    this->_ptr = this->_ptr->left;
                    while (this->_ptr->right)
                        this->_ptr = this->_ptr->right;
                }
                else {
                    node_pointer tmp = this->_ptr;
                    this->_ptr = this->_ptr->parent;
                    while (this->_ptr->right != tmp) {
                        tmp = this->_ptr;
                        this->_ptr = this->_ptr->parent;
                    }
                }
            }

    }; // class rbtree_iterator

    template <typename One, typename Two>
    std::ostream& operator<<(std::ostream& os, const rbtree_iterator<One, Two>& op) {
        os << *op.get_node();
        return os;
    }
} // namespace ft

#endif