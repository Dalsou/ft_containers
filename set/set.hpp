/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:19:05 by afoulqui          #+#    #+#             */
/*   Updated: 2022/02/01 17:56:14 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <memory>
#include "../shared/rbtree.hpp"
#include "../shared/utils.hpp"
#include "../shared/pair.hpp"

namespace ft
{
	template <
		class Key,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<Key> >
	class set
	{
		public:

			// ******************** Aliases ******************** //
			typedef Key 							key_type;
			typedef Key 							value_type;
			typedef std::size_t 					size_type;
			typedef std::ptrdiff_t 					difference_type;
			typedef Compare 						value_compare;
			typedef Compare 						key_compare;
			typedef Allocator 						allocator_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;

			typedef typename rb_tree<value_type, value_compare>::iterator 				iterator;
			typedef typename rb_tree<value_type, value_compare>::const_iterator 		const_iterator;
			typedef typename rb_tree<value_type, value_compare>::reverse_iterator 		reverse_iterator;
			typedef typename rb_tree<value_type, value_compare>::const_reverse_iterator const_reverse_iterator;

		private:
		// ******************** Attributes ******************** //

			rb_tree<value_type, value_compare> 	_tree;
			allocator_type 						_alloc;
			key_compare 						_comp;

		public:

		// ******************** Constructors & Destructor ******************** //

			// Constructor
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : 
			_tree() {
				_comp = comp;
				_alloc = alloc;
			}

			// Range constructor
			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_tree() {
				_alloc = alloc;
				_comp = comp;
				insert(first, last);
			}

			// Destructor
			~set() {};

			// Copy constrcutor
			set(const set& src) {
				_alloc = src._alloc;
				_comp = src._comp;
				_tree = src._tree;
			}

			// Assignment operator
			set& operator=(const set& op)
			{
				if (this != &op) {
					_alloc = op._alloc;
					_comp = op._comp;
					_tree = op._tree;
				}
				return *this;
			}

			// get_allocator
			allocator_type get_allocator() const {
				return _alloc;
			}

		// ******************** Iterators ******************** //

			// begin
			iterator begin() {
				return _tree.begin();
			}
			const_iterator begin() const {
				return _tree.begin();
			}

			//end
			iterator end() {
				return _tree.end();
			}
			const_iterator end() const {
				return _tree.end();
			}

			//rbegin
			reverse_iterator rbegin() {
				return _tree.rbegin();
			}
			const_reverse_iterator rbegin() const {
				return _tree.rbegin();
			}

			//rend
			reverse_iterator rend() {
				return _tree.rend();
			}
			const_reverse_iterator rend() const {
				return _tree.rend();
			}

		// ******************** Capacity ******************** //

			size_type size() const {
				return _tree.size();
			}

			size_type max_size() const {
				return _tree.max_size();
			}

			bool empty() const {
				return (_tree.size() == 0);
			}

		// ******************** Modifiers ******************** //


			void clear() {
				_tree.clear();
			}

			ft::pair<iterator, bool> insert(const value_type& val) {
				return _tree.insert(val);
			}

			iterator insert(iterator hint, const value_type& val){
				return _tree.insert(hint, val);
			}

			template <class InputIt>
			void insert(InputIt first, InputIt last){
				for (; first != last; ++first)
					_tree.insert(*first);
			}

			void erase(iterator pos) {
				_tree.erase(pos);
			}

			void erase(iterator first, iterator last){
				while (first != last)
					_tree.erase(first++);
			}

			size_type erase(const key_type& key){
				return _tree.erase(key);
			}

			void swap(set& x){
				std::swap(_alloc, x._alloc);
				std::swap(_comp, x._comp);
				_tree.swap(x._tree);
			}

		// ******************** Observers ******************** //

			key_compare key_comp() const {
				return _comp;
			}

			value_compare value_comp() const {
				return _comp;
			}
			
		// ******************** Operations ******************** //

			size_type count(const key_type& key) const{
				iterator res = _tree.find(key);

				return (res == _tree.end()) ? 0 : 1;
			}

			iterator find(const Key& key){
				return _tree.find(key);
			}

			const_iterator find(const Key& key) const {
				return _tree.find(key);
			}

			iterator lower_bound(const Key& key) {
				return _tree.lower_bound(key);
			}

			const_iterator lower_bound(const Key& key) const {
				return _tree.lower_bound(key);
			}

			iterator upper_bound(const Key& key) {
				return _tree.upper_bound(key);
			}

			const_iterator upper_bound(const Key& key) const {
				return _tree.upper_bound(key);
			}

			ft::pair<iterator, iterator> equal_range(const Key& key) {
				iterator lower = _tree.lower_bound(key);
				iterator upper = _tree.upper_bound(key);

				return ft::make_pair(lower, upper);
			}

			ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const {
				const_iterator lower = _tree.lower_bound(key);
				const_iterator upper = _tree.upper_bound(key);

				return ft::make_pair(lower, upper);
			}

	}; // class set

	template <class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return (lhs == rhs || lhs < rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return (rhs == lhs || rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	void swap(ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}

}//namespace ft

#endif
