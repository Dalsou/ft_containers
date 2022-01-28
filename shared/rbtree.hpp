/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:31:50 by afoulqui          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/28 15:22:46 by afoulqui         ###   ########.fr       */
=======
/*   Updated: 2022/01/20 17:09:46 by afoulqui         ###   ########.fr       */
>>>>>>> 99fce3a08d0e02c3faef2a6da007aef3a8d49703
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "pair.hpp"
#include "rbtree_iterator.hpp"
#include "reverse_iterator.hpp"

#define BLACK false
#define RED true

namespace ft {

    template <class T>
    struct rb_node {

<<<<<<< HEAD
=======
        typedef T  value_type;
>>>>>>> 99fce3a08d0e02c3faef2a6da007aef3a8d49703
        rb_node*   parent;
        rb_node*   left;
        rb_node*   right;
        bool       color;

        T           data;

        rb_node(const T& data)
        : data(data) {}

    }; // struct rb_node

<<<<<<< HEAD
    template <  class Key,
				class T,
                class Compare = std::less<Key>,
                class  Allocator = std::allocator<ft::pair<const Key, T> > >
=======
    template <  class T,
                class Compare,
                class  Allocator = std::allocator<rb_node<T> > >
>>>>>>> 99fce3a08d0e02c3faef2a6da007aef3a8d49703
    class rb_tree {

        public :

        // ******************** ALIASES ******************** //

<<<<<<< HEAD
			typedef ft::pair<const Key, T> 				value_type;
        	typedef Key 								key_type;
			typedef T 									mapped_type;
            typedef Compare                             compare;
            typedef Allocator                           allocator;
            typedef ft::pair<const Key, T>				value_type;
            typedef size_t                              size_type;
            typedef rb_node<value_type>                 node;
            typedef node*                               node_ptr;
            typedef std::ptrdiff_t                     	difference_type;
=======
            typedef Compare                             compare;
            typedef Allocator                           allocator;
            typedef T                                   value_type;
            typedef size_t                              size_type;
            typedef rb_node<value_type>                 node;
            typedef node*                               node_ptr;
            typedef  std::ptrdiff_t                     difference_type;
>>>>>>> 99fce3a08d0e02c3faef2a6da007aef3a8d49703

            typedef ft::rbtree_iterator<node>           iterator;
            typedef ft::rbtree_iterator<node>           const_iterator;
            typedef ft::rbtree_iterator<iterator>       reverse_iterator;
            typedef ft::rbtree_iterator<const_iterator> const_reverse_iterator;

        private :

        // ******************** ATTRIBUTES ******************** //

            node_ptr    _root;
            node_ptr    _NIL;
            compare     _compare;
            allocator   _alloc;
            size_type   _size;

        public :

        // ******************** CONSTRUCTORS ******************** //

            // constructor
            rb_tree(allocator alloc = allocator()) :
            _compare(compare()), _alloc(alloc), _size(0) {
                this->_NIL = this->_alloc.allocate(1);
                this->_alloc.construct(this->_NIL, value_type());
                this->_NIL->parent = this->_NIL;
                this->_NIL->left = this->_NIL;
                this->_NIL->right = this->_NIL;
                this->_NIL->color = BLACK;
                this->_root = this->_NIL;
            }

            // destructor
            ~rb_tree() {
                clear();
                this->_alloc.destroy(this->_NIL);
                this->_alloc.deallocate(this->_NIL, 1);
            }

            // cpy constructor
            rb_tree(const rb_tree& src) {
                this->_alloc = src._alloc;
                this->_compare = src._compare;
                this->_size = src._size;
                this->_NIL = this->_alloc.allocate(1);
                this->_NIL->parent = this->_NIL;
               this->_NIL->left = this->_NIL;
                this->_NIL->right = this->_NIL;
                this->_NIL->color = BLACK;

                this->_root = this->_NIL;
                src.print();
                this->_recursiveCopy(*this, src._root, src._NIL);
            }


            rb_tree& operator=(const rb_tree& op) {
                clear();
                this->_recursiveCopy(*this, op._root, op->_NIL);
                return *this;
            }  

        // ******************** ITERATORS ******************** //

            iterator begin() {
                return iterator (this->_min(this->_root), this->_root, this->_NIL);
            }

            const_iterator begin() const{
                return const_iterator (this->_min(this->_root), this->_root, this->_NIL);
            }

            iterator end() {
                return iterator(this->_NIL, this->_root, this->_NIL);
            }

            const_iterator end() const {
                return const_iterator(this->_NIL, this->_root, this->_NIL);
            }

            reverse_iterator rbegin() {
                return reverse_iterator(this->end());
            }

            const_reverse_iterator rbegin() const {
                return const_reverse_iterator(this->end());
            }

            reverse_iterator rend() {
                return reverse_iterator(this->begin());
            }

            const_reverse_iterator rend() const {
                return const_reverse_iterator(this->begin());
            }

        // ******************** FUNCTIONS ******************** //
    
            iterator find(const value_type& val) {
                node_ptr    found = _findNode(val);

                if (!found)
                    return this->end();
                else
                    return iterator(found, this->_root, this->_NIL);
            }

            const_iterator find(const value_type& val) const {
                node_ptr    found = _findNode(val);

                if (!found)
                    return this->end();
                else
                    return iterator(found, this->_root, this->_NIL);
            }

            ft::pair<iterator, bool> insert(const value_type& val) {
                node_ptr                    n = _newNode(val);
                ft::pair<node_ptr, bool>    r = _insertRecursive(this->_root, n);

                if (r.second) {
                    this->_size++;
                    if (n->parent == this->_NIL)
                        n->color = BLACK;
                    else
                        this->_insertFixup(n);
                    this->_root = n;
                    while (this->_root->parent != this->_NIL)
                        this->_root = this->_root->parent;
                    return ft::make_pair(iterator(n, this->_root, this->_NIL), true);
                }
                else {
                    this->_alloc.destroy(n);
                    this->_alloc.deallocate(n, 1);
                    return ft::make_pair(iterator(r.first, this->_root, this->_NIL), false);
                }
            }

            iterator    insert(iterator hint, const value_type& val) {
                node_ptr    next = this->_next(hint.node);

                if (this->_compare(*hint, val) && this->_compare(val, next->data)) {
                    node_ptr    n = this->_newNode(val);
                    ft::pair<node_ptr, bool>    r = this->_insertRecursive(hint.node, n);
                    this->_size++;
                    return iterator(r.first, this->_root, this->_NIL);
                }
                else
                    return this->insert(val).first;
            }

            size_type   erase(const value_type& val) {
                node_ptr    n = _findNode(val);

                if (n) {
                    this->_deleteNode(n);
                    return (1);
                }
                else
                    return (0);
            }

            void    erase(iterator pos) {
                if (pos.node != this->_NIL)
                    this->_deleteNode(pos.node);
            }

            void    clear() {
                this->_recursiveClear(this->_root);
                this->_root = this->_NIL;
                this->_size = 0;
            }

            size_type   size() const {
                return this->_size;
            }

            size_type   max_size() const {
                return this->_alloc.max_size();
            }

            void    swap(rb_tree& x) {
                std::swap(this->_alloc, x._alloc);
                std::swap(this->_compare, x._compare);
                std::swap(this->_size, x._size);
                std::swap(this->_NIL, x._NIL);
                std::swap(this->_root, x._root);
            }

            iterator    lower_bound(const value_type& val) {
                for (iterator it = this->begin(); it != this->end(); ++it)
                    if (this->_compare(val, it.node->data) || this->_compare(it.node->data, val) == 0)
                        return it;
                return this->end();
            }

            const_iterator    lower_bound(const value_type& val) const {
                for (iterator it = this->begin(); it != this->end(); ++it)
                    if (this->_compare(val, it.node->data) || this->_compare(it.node->data, val) == 0)
                        return it;
                return this->end();
            }

            iterator    upper_bound(const value_type&  val) {
                for (iterator it = this->begin(); it != this->end(); ++it)
                    if (this->_compare(val, it.node->data))
                        return it;
                return this->end();
            }

            const_iterator    upper_bound(const value_type&  val) const {
                for (iterator it = this->begin(); it != this->end(); ++it)
                    if (this->_compare(val, it.node->data))
                        return it;
                return this->end();
            }

            void   print(node* ptr = NULL, int indent = 0) const {
                if (ptr == NULL)
                    ptr = this->_root;
                if (ptr != this->_NIL) {
                    if (ptr->right != this->_NIL)
                        print(ptr->right, indent + 4);
                    if (indent)
                        std::cout << std::setw(indent) << ' ';
                    if (ptr->right != this->_NIL)
                        std::cout << " /\n" << std::setw(indent) << ' ';
                    if (ptr->color == RED)
                        std::cout << "\033[0;31m";
                    std::cout << ptr->data << "\n ";
                    std::cout << "\033[0m";
                    if (ptr->left != this->_NIL) {
                        std::cout << std::setw(indent) << ' ' << " \\\n";
                        print(ptr->left, indent + 4);
                    } 
                }
            }

        private :

        // ******************** PRIVATE FUNCTIONS ******************** //

            void    _recursiveCopy(rb_tree &dst, node_ptr x, node_ptr x_nil) {
                if (x != x_nil) {
                    this->_recursiveCopy(dst, x->left, x_nil);
                    dst.insert(x->data);
                    this->_recursiveCopy(dst, x->right, x_nil);
                }
            }

            node_ptr    _min(node_ptr x) const {
                while (x->left != this->_NIL)
                    x = x->left;
                return x;
            }

            node_ptr    _max(node_ptr x) const {
                while (x->right != this->_NIL)
                    x = x->right;
                return x;
            }

            node_ptr    _findNode(const value_type& val) const {
                node_ptr    current = this->_root;

                while (current != this->_NIL) {
                    if (this->_compare(val, current->data))
                        current = current->left;
                    else if (this->_compare(current->data, val))
                        current = current->right;
                    else
                        return current;
                }
                return NULL;
            }

            node*    _newNode(const value_type& val) {
                node*   node = this->_alloc.allocate(1);
                this->_alloc.construct(node, val);
                node->parent = this->_NIL;
                node->left = this->_NIL;
                node->right = this->_NIL;
                node->color = RED;
                return node;
            }

            void    _rotateLeft(node_ptr x) {
                node_ptr    y = x->right;

                x->right = y->left;
                if (y->left != this->_NIL)
                    y->left->parent = x;
                y->parent = x->parent;
                if (x->parent == this->_NIL)
                    this->_root = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->left = x;
                x->parent = y;
            }

            void    _rotateRight(node_ptr x) {
                node_ptr    y = x->left;

                x->left = y->right;
                if (y->right != this->_NIL)
                    y->right->parent = x;
                y->parent = x->parent;
                if (x->parent == this->_NIL)
                    this->_root = y;
                else if (x == x->parent->right)
                    x->parent->right = y;
                else
                    x->parent->left = y;
                y->right = x;
                x->parent = y;
            }

            ft::pair<node_ptr, bool>    _insertRecursive(node_ptr root, node_ptr node) {
                if (root != this->_NIL && this->_compare(node->data, root->data)) {
                    if (root->left != this->_NIL)
                        return this->_insertRecursive(root->left, node);
                    else
                        root->left = node;
                }
                else if (root != this->_NIL && this->_compare(root->data, node->data)) {
                    if (root->right != this->_NIL)
                        return this->_insertRecursive(root->right, node);
                    else
                        root->right = node;
                }
                else if (root != this->_NIL)
                    return ft::make_pair(root, false);
                node->parent = root;
                node->left = this->_NIL;
                node->right = this->_NIL;
                node->color = RED;
                return ft::make_pair(node, true);
            }

            void    _insertFixup(node_ptr k) {
                node_ptr    u;

                while (k->parent->color == RED) {
                    if (k->parent == k->parent->parent->right) {
                        u = k->parent->parent->left;
                        if (u->color ==  RED) {
                            u->color = BLACK;
                            k->parent->color = BLACK;
                            k->parent->parent->color = RED;
                            k = k->parent->parent;
                        }
                        else {
                            if (k == k->parent->left) {
                                k = k->parent;
                                this->_rotateRight(k);
                            }
                        k->parent->color =  BLACK;
                        k->parent->parent->color = RED;
                        this->_rotateLeft(k->parent->parent);
                        }
                    }
                    else {
                        u = k->parent->parent->right;
                        if (u->color == RED) {
                            u->color = BLACK;
                            k->parent->color = BLACK;
                            k->parent->parent->color = RED;
                            k = k->parent->parent;
                        }
                        else {
                            if (k == k->parent->right) {
                                k = k->parent;
                                this->_rotateLeft(k);
                            }
                            k->parent->color = BLACK;
                            k->parent->parent->color = RED;
                            this->_rotateRight(k->parent->parent);
                        }
                    }
                    if (k == this->_root)
                        break ;
                }
                this->_root->color = BLACK;
            }

            node_ptr    _next(node_ptr node) const {
                node_ptr    next = this->_NIL;

                if (node->right != this->_NIL)
                    return this->_min(node->right);
                next = node->parent;
                while (next != this->_NIL && node == next->right) {
                    node = next;
                    next = next->parent;
                }
                return next;
            }

            void    _transplant(node_ptr u, node_ptr v) {
                if (u->parent == this->_NIL)
                    this->_root = v;
                else if (u == u->parent->left)
                    u->parent->left = v;
                else
                    u->parent->right = v;
                v->parent = u->parent;
            }

            void    _deleteFixup(node_ptr x) {
                node_ptr    s;

                while (x != this->_root && x->color == BLACK) {
                    if (x == x->parent->left) {
                        s = x->parent->right;
                        if (s->color == RED) {
                            s->color = BLACK;
                            x->parent->color = RED;
                            this->_rotateLeft(x->parent);
                            s = x->parent->right;
                        }
                        if (s->left->color == BLACK && s->right->color == BLACK) {
                            s->color = RED;
                            x = x->parent;
                        }
                        else {
                            if (s->right->color == BLACK) {
                                s->left->color = BLACK;
                                s->color = RED;
                                this->_rotateRight(s);
                                s = x->parent->right;
                            }
                            s->color = x->parent->color;
                            x->parent->color = BLACK;
                            s->right->color = BLACK;
                            this->_rotateLeft(x->parent);
                            x = this->_root;
                        }
                    }
                    else {
                        s = x->parent->left;
                        if (s->color == RED) {
                            s->color = BLACK;
                            x->parent->color = RED;
                            this->_rotateRight(x->parent);
                            s = x->parent->left;
                        }
                        if (s->right->color == BLACK && s->left->color == BLACK) {
                            s->color = RED;
                            x = x->parent;
                        }
                        else {
                            if (s->left->color == BLACK) {
                                s->right->color = BLACK;
                                s->color = RED;
                                this->_rotateLeft(s);
                                s = x->parent->left;
                            }
                            s->color = x->parent->color;
                            x->parent->color = BLACK;
                            s->left->color = BLACK;
                            this->_rotateRight(x->parent);
                            x = this->_root;
                        }
                    }
                }
                x->color = BLACK;
            }

            void    _deleteNode(node_ptr z) {
                node_ptr    y = z;
                node_ptr    x;
                bool        y_original_color = y->color;

                if (z->left == this->_NIL) {
                    x = z->right;
                    this->_transplant(z, z->right);
                }
                else if (z->right == this->_NIL) {
                    x = z->left;
                    this->_transplant(z, z->left);
                }
                else {
                    y = this->_min(z->right);
                    y_original_color = y->color;
                    x = y->right;
                    if (y->parent == z)
                        x->parent = y;
                    else {
                        this->_transplant(y, y->right);
                        y->right = z->right;
                        y->right->parent = y;
                    }
                    this->_transplant(z, y);
                    y->left = z->left;
                    y->left->parent = y;
                    y->color = z->color;
                }
                this->_alloc.destroy(z);
                this->_alloc.deallocate(z, 1);
                this->_size--;
                if (y_original_color == BLACK)
                    this->_deleteFixup(x);
            }

            void    _recursiveClear(node_ptr x = NULL) {
                if (x == NULL)
                    x = this->_root;
                if (x != this->_NIL) {
                    this->_recursiveClear(x->left);
                    this->_recursiveClear(x->right);
                    this->_alloc.destroy(x);
                    this->_alloc.deallocate(x, 1);
                }
            }

    }; //class rb_tree

}// namespace ft