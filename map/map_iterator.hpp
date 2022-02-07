#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iostream>
#include "../shared/utils.hpp"

namespace ft {

    template <typename T, typename node_pointer>
    class map_iterator {

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

            map_iterator() : 
            _ptr(NULL) {}

            map_iterator(node_pointer ptr) :
            _ptr(ptr) {}

            virtual ~map_iterator() {}

            map_iterator(const map_iterator& src) :
            _ptr(src._ptr) {}


            map_iterator& operator=(const map_iterator& op) {
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

            operator map_iterator<const T, node_pointer>() const {
                return map_iterator<const T, node_pointer>(this->_ptr);
            }

            template <typename It>
            bool operator==(const map_iterator<It, node_pointer>& op) const {
                return (this->_ptr == op.get_node());
            }

            template <typename It>
            bool operator!=(const map_iterator<It, node_pointer>& op) const {
                return (this->_ptr != op.get_node());
            }

        /* ------------------------ INCREMENT ----------------------- */

            map_iterator& operator++() {
                this->_increase();
                return *this;
            }

            map_iterator operator++(int) {
                map_iterator tmp(*this);

                ++(*this);
                return tmp;
            }

        /* ------------------------ DECREMENT ----------------------- */

            map_iterator& operator--() {
				if (this->_ptr)
                	this->_decrease();
                return *this;
            }

            map_iterator operator--(int) {
                map_iterator tmp(*this);

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

		public:

		node_pointer    get_node() {
            return this->_ptr;
        }

    	node_pointer    get_node()  const {
            return this->_ptr;
        }

		template <class, class, class, class>
		friend class map;

    }; // class map_iterator

    template <typename One, typename Two>
    std::ostream& operator<<(std::ostream& os, const map_iterator<One, Two>& op) {
        os << *op.get_node();
        return os;
    }
} // namespace ft

#endif