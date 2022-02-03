/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:49:33 by afoulqui          #+#    #+#             */
/*   Updated: 2022/02/03 20:24:11 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>

#include "../shared/utils.hpp"
#include "rb_node.hpp"
#include "rbtree_iterator.hpp"
#include "../shared/reverse_iterator.hpp"
#include "pair.hpp"

namespace ft {

	template < class Key,
			   class T,
			   class Compare = std::less<Key>, 
			   class Allocator = std::allocator<ft::pair<const Key, T> >
		   >
	class map {

		// ******************** Aliases ******************** //
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef rb_node<value_type>							node_type;
			typedef Allocator									allocator_type;

			class	binary_function {
				
				public:
					typedef bool 		res_type;
					typedef value_type	first_arg_type;
					typedef value_type	second_arg_type;
			};

			class	value_compare : public binary_function {
				
				public:

					Compare	comp;

					value_compare(Compare c) :
					comp(c) {}
					
					bool	operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

			typedef typename allocator_type::template rebind<node_type>::other	node_allocator;
        	typedef typename allocator_type::reference 							reference;
        	typedef typename allocator_type::const_reference 					const_reference;
        	typedef typename allocator_type::pointer 							pointer;
        	typedef typename allocator_type::const_pointer 						const_pointer;
        	typedef typename allocator_type::size_type 							size_type;
        	typedef typename allocator_type::difference_type 					difference_type;
        	typedef rbtree_iterator<value_type, node_type *> 					iterator;
        	typedef rbtree_iterator<const value_type, node_type *> 				const_iterator;
        	typedef ft::reverse_iterator<iterator> 								reverse_iterator;
        	typedef ft::reverse_iterator<const_iterator> 						const_reverse_iterator;

	
		// ******************** Attributes ******************** //
		private:
			node_allocator	_allocator;
			key_compare		_key_compare;
			size_type		_size;
			node_type*		_root;

		public :

		// ******************** Constructors & Destructor ******************** //
			
			map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : 
			_allocator(alloc), _key_compare(comp), _size(0), _root(NULL) {
			}

        	template <class InputIterator>
        	map(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
			_allocator(alloc), _key_compare(comp), _size(0), _root(NULL) { 
				insert(first, last); 
			}
        
			map(const map& src) : 
			_allocator(src._allocator), _key_compare(src._key_compare), _size(0), _root(NULL) { 
				*this = src; 
			}
        
			virtual ~map() { 
				this->_clearTree(this->_root);
			}

        	map& operator=(const map& op) {
            	this->_clearTree(this->_root);
            	insert(op.begin(), op.end());
            	return *this;
        	}

		// ******************** Iterators ******************** //

			iterator begin() {
        	    //if (!this->_root)
        	        //this->_initialize();
				if (this->_size == 0)
        	        return this->_root; 
				return iterator(farLeft(this->_root));
        	}

        	const_iterator begin() const {
				if (this->_size == 0)
					return this->_root;
				return const_iterator(farLeft(this->_root));
        	}

			iterator end() {
        	    //if (!this->_root)
        	        //this->_initialize();
        	    if (this->_size == 0)
        	        return this->_root; 

        	    node_type *tmp = this->_root;
        	    
				while (tmp && !tmp->color)
        	        tmp = tmp->right;
        	    return iterator(tmp);
        	}

        	const_iterator end() const {
        	    if (this->_size == 0)
        	        return const_iterator(_root); 

        	    node_type *tmp = this->_root;
        	   
			    while (tmp && !tmp->color)
        	        tmp = tmp->right;
        	    return const_iterator(tmp);
        	}

        	reverse_iterator rbegin() {
        	    return reverse_iterator(end()--);
        	}

        	const_reverse_iterator rbegin() const {
        	    return const_reverse_iterator(end()--);
        	}

        	reverse_iterator rend() {
        	    return reverse_iterator(begin());
        	}

        	const_reverse_iterator rend() const {
        	    return const_reverse_iterator(begin());
        	}

	// 	// ******************** Capacity ******************** //

        	bool empty() const {
        	    return (this->_size == 0);
        	}

        	size_type size() const {
        	    return this->_size;
        	}

			size_type max_size() const {
				return this->_allocator.max_size();
			}

		// ******************** Element Access ******************** //

		    mapped_type& operator[](const key_type& k) {
        	    node_type*	tmp = this->_recursiveFindKey(k, this->_root);

        	    if (tmp)
        	        return tmp->value.second;
        	    insert(value_type(k, mapped_type()));
        	    return _recursiveFindKey(k, this->_root)->value.second;
        	}

	// 	// ******************** Modifiers ******************** //

        	//Insert one element
        	ft::pair<iterator, bool>	insert(const value_type& val) {
        	    size_type 	backup = this->_getSize();

        	    this->_insertNodeFromRoot(val, this->_root);
        	    return ft::pair<iterator, bool>(this->_recursiveFindKey(val.first, this->_root), backup != this->_size);
        	}

        	//insert with hint
        	iterator	insert(iterator position, const value_type& val) {
        	    (void)position;
        	    this->_insertNodeFromRoot(val, this->_root);
        	    return iterator(this->_recursiveFindKey(val.first, this->_root));
        	}

        	//insert range
        	template <class InputIterator>
        	void insert(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
        	    while (first != last) {
        	        insert(*first);
        	        ++first;
        	    }
        	}

        	void	erase(iterator position){
        	    erase(position->first);
        	}

        	size_type erase(const key_type& k) {
        	    size_type	backup = this->_size;

        	    this->_root = this->_deleteNode(this->_root, k);
        	    return (backup - this->_size);
        	}

        	void	erase(iterator first, iterator last)
        	{
        	    map<key_type, mapped_type>	tmp(first, last);
        	    iterator 					it = tmp.begin();
        	    iterator 					ite = tmp.end();

        	    for (; it != ite; it++)
        	        this->_root = this->_deleteNode(this->_root, it->first);
        	}

			void swap(map& x) {
            	node_allocator	tmp_alloc_type = this->_allocator;
            	key_compare		tmp_key_compare = this->_key_compare;
            	size_type 		tmp_size = this->_size;
            	node_type*		tmp_root = this->_root;

            	this->_allocator = x._allocator;
            	this->_key_compare = x._key_compare;
            	this->_size = x._size;
            	this->_root = x._root;

            	x._allocator = tmp_alloc_type;
            	x._key_compare = tmp_key_compare;
            	x._size = tmp_size;
            	x._root = tmp_root;
            	return;
        	}

			void clear() {
            	node_type*	ghost = this->end().get_node();

				if (this->_size == 0)
					return;
				ghost->parent->right = NULL;
				this->_clearTree(this->_root);
				this->_root = ghost;
				this->_size = 0;
        	}

		// ******************** Observers ******************** //

		    key_compare key_comp() const {
    	        return this->_key_compare;
        	}

	        value_compare value_comp() const {
            	return value_compare(key_compare());
        	}

		// ******************** Operations ******************** //
		
       		iterator find(const key_type& k) {
        	    node_type *tmp = this->_recursiveFindKey(k, this->_root);

        	    if (tmp)
        	        return (iterator(tmp));
        	    return this->end();
        	}

        	const_iterator find(const key_type& k) const
        	{
        	    node_type *tmp = this->_recursiveFindKey(k, this->_root);

        	    if (tmp)
        	        return const_iterator(tmp);
        	    return const_iterator(this->end());
        	}

        	size_type count(const key_type& k) {
            	iterator tmp = this->find(k);
            	if (tmp != this->end())
                	return 1;
            	return 0;
        	}

        	size_type	count(const key_type& k) const {
            	const_iterator tmp = this->find(k);
            	if (tmp != this->end())
                	return 1;
            	return 0;
        	}

			iterator	lower_bound(const key_type& k) {
        	    iterator ite = this->end();
        	    iterator it = this->begin();

        	    while (it != ite) {
        	        if (!this->_key_compare(it->first, k))
        	            return (it);
        	        it++;
        	    }
        	    return (ite);
        	}

			const_iterator lower_bound(const key_type& k) const {
        	    const_iterator ite = this->end();
        	    const_iterator it = this->begin();

        	    while (it != ite) {
        	        if (!this->_key_compare(it->first, k))
        	            return (it);
        	        it++;
        	    }
        	    return (ite);
        	}

        	iterator upper_bound(const key_type &k) {
        	    iterator it = this->begin();
        	    iterator ite = this->end();

        	    while (it != ite) {
        	        if (this->_key_compare(k, it->first))
        	            return (it);
        	        it++;
        	    }
        	    return (ite);
        	}

        	const_iterator upper_bound(const key_type &k) const {
        	    const_iterator it = this->begin();
        	    const_iterator ite = this->end();

        	    while (it != ite) {
        	        if (this->_key_compare(k, it->first))
        	            return (it);
        	        it++;
        	    }
        	    return (ite);
        	}

			pair<iterator, iterator> equal_range(const key_type& k) {
            	return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
        	}

        	pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
            	return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
        	}

			allocator_type get_allocator() const {
            	return this->_allocator;
        	}

		private:

        	size_type _getSize() {
            	return this->_size;
        	}

        	void _setSize(size_type n) {
            	this->_size = n;
        	}

        	void _clearTree(node_type* current) {
            	if (current) {
                	_clearTree(current->left);
                	_clearTree(current->right);

                	this->_allocator.destroy(current);
                	this->_allocator.deallocate(current, 1);
                	if (this->_getSize() > 0)
                    	this->_setSize(this->_getSize() - 1);
                	if (current == this->_root)
                    	this->_root = NULL;
            	}
        	}

        	node_type* _addNode(const value_type& val, node_type* parent) {
        	    node_type* tmp = _allocator.allocate(1);
	
				this->_allocator.construct(tmp, node_type(val, NULL, NULL, parent, false));
        	    this->_size++;
        	    return tmp;
        	}

        	void _initialize() {
        	    insert(value_type(key_type(), mapped_type()));
        	    this->_root->color = true;
        	    this->_size--;
        	}

        	node_type* _insertNode(const value_type& val, node_type* current, node_type* parent) {
        	    if (!current)
        	        return this->_addNode(val, parent);
        	    if (current->color) {
        	        node_type *to_insert = this->_addNode(val, parent);
        	        current->parent = to_insert;
        	        to_insert->right = current;
        	        current = to_insert;
        	        return current;
        	    }
        	    if (_key_compare(val.first, current->value.first))
        	        current->left = this->_insertNode(val, current->left, current);
        	    else if (_key_compare(current->value.first, val.first))
        	        current->right = this->_insertNode(val, current->right, current);
        	    return current;
        	}

        	node_type* _minValueNode(node_type* node) {
        	    node_type* current = node;

        	    while (current->left != NULL)
        	        current = current->left;
        	    return current;
        	}

        	node_type* _maxValueNode(node_type* node) {
        	    node_type* current = node; 

        	    while (current->right != NULL)
        	        current = current->right;
        	    return current;
        	}

        	node_type* _deleteNode(node_type* current, const key_type& key) {
        	    if (!current || current->color)
        	        return current;
        	    if (this->_key_compare(key, current->value.first)) 
        	        current->left = this->_deleteNode(current->left, key);
        	    else if (this->_key_compare(current->value.first, key))
        	        current->right = this->_deleteNode(current->right, key);
        	    else {
        	        if (!current->left || !current->right) {
        	            node_type *tmp = current->left ? current->left : current->right;

        	            if (!current->left && !current->right) {
        	                tmp = current;
        	                this->_allocator.destroy(tmp);
        	                this->_allocator.deallocate(tmp, 1);
        	                current = NULL;
        	                this->_size--;
        	            }
        	            else {
        	                tmp->parent = current->parent;
        	                node_type *tmp2 = current;
        	                current = tmp;
        	                this->_allocator.destroy(tmp2);
        	                this->_allocator.deallocate(tmp2, 1);
        	                this->_size--;
        	            }
        	        }
        	        else {
        	            node_type *tmp = _minValueNode(current->right);

        	            if (tmp != current->right) {
        	                tmp->right = current->right;
        	                current->right->parent = tmp;
        	            }
        	            tmp->left = current->left;
        	            current->left->parent = tmp;
        	            tmp->parent->left = NULL;
        	            tmp->parent = current->parent;
        	            if (this->_root == current)
        	                this->_root = tmp;
        	            this->_allocator.destroy(current);
        	            this->_allocator.deallocate(current, 1);
        	            this->_size--;
        	            current = tmp;
        	        }
        	    }
        	    return current;
        	}

        	node_type* _insertNodeFromRoot(const value_type &val, node_type *current, node_type *parent = NULL) {
        	    if (!this->_root) {
        	        this->_root = this->_addNode(val, NULL);
        	        node_type *last = this->_addNode(value_type(key_type(), mapped_type()), this->_root);

        	        this->_size--;
        	        this->_root->right = last;
        	        last->color = true;
        	        return (this->_root);
        	    }
        	    if (this->_root->color) {
        	        node_type *new_root = this->_addNode(val, NULL);

        	        this->_root->parent = new_root;
        	        new_root->right = this->_root;
        	        this->_root = new_root;
        	        return (this->_root);
        	    }
        	    return this->_insertNode(val, current, parent);
        	}

        	node_type* _recursiveFindKey(const key_type &key, node_type *current) const {
        	    if (!current || current->color)
        	        return NULL;
        	    if (this->_key_compare(key, current->value.first))
        	        return this->_recursiveFindKey(key, current->left);
        	    else if (this->_key_compare(current->value.first, key))
        	        return this->_recursiveFindKey(key, current->right);
        	    else
        	        return current;
        	}
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        if (lhs.size() != rhs.size())
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return !(lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return (lhs < rhs || lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return rhs < lhs;
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
        return (lhs > rhs || lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
        x.swap(y);
    }
	
} // namespace ft

#endif