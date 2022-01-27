/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:49:33 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/20 15:11:48 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>

#include "../shared/utils.hpp"
#include "../shared/rbtree.hpp"
#include "../shared/pair.hpp"

namespace ft {

	template < class Key,
		   class T,
		   class Compare = std::less<Key>,
		   class Allocator = std::allocator<ft::pair<Key, T> >
		   >
	class map {

		// ******************** Aliases ******************** //
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::ptrdiff_t						difference_type;
			typedef std::size_t							size_type;
			typedef ft::pair<key_type, mapped_type>		value_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;

			class	value_compare {
				
				public:
					
					bool	operator()(const value_type& x, const value_type& y) const {
						return (key_compare()(x.first, y.first));
					}

					value_compare& operator=(const value_compare &) {
						return *this;
					}
			};

			typedef typename rb_tree<value_type, value_compare>::iterator				iterator;
			typedef typename rb_tree<value_type, value_compare>::const_iterator			const_iterator;
			typedef typename rb_tree<value_type, value_compare>::reverse_iterator		reverse_iterator;
			typedef typename rb_tree<value_type, value_compare>::const_reverse_iterator	const_reverse_iterator;

		// ******************** Attributes ******************** //
		private:
			rb_tree<value_type, value_compare>	_tree;
			key_compare							_key_cmp;
			allocator_type						_alloc;
			value_compare						_value_cmp;

		public :

		// ******************** Constructors & Destructor ******************** //
			
			// Constructor
			explicit map(const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()) :
			_tree() {
				this->_alloc = alloc;
				this->_key_cmp = comp;
				this->_value_cmp = value_compare();
			}

			// Destructor
			~map() {}
			
			// Range constructor
			template <class Ite>
			map(Ite first, Ite last, const Compare& comp = Compare(), const Allocator& alloc = Allocator(),
				typename enable_if<!is_integral<Ite>::value,Ite >::type = Ite()) :
			_tree() {
				this->_alloc = alloc;
				this->_key_cmp = comp;
				this->_value_cmp = value_compare();
				this->insert(first, last);
			}
			
			// Copy constrcutor
			map(const map &src) {
				this->_alloc = src._alloc;
				this->_key_cmp = src._key_cmp;
				this->_value_cmp = src._value_cmp;
				this->_tree = src._tree;
			}

			// Assignment operator
			map& operator=(map const &op) {
				if (&op == this)
					return *this;
				this->_alloc = op._alloc;
				this->_key_cmp = op._key_cmp;
				this->_value_cmp = op._value_cmp;
				this->_tree = op._tree;
				return *this;
			}

		// ******************** Iterators ******************** //

			// begin
			iterator				begin(void) {
				return this->_tree.begin();
			}
			const_iterator			begin(void) const {
				return this->_tree.begin();
			}

			//end
			iterator				end(void) {
				return this->_tree.end();
			}
			const_iterator			end(void) const {
				return this->_tree.end();
			}

			//rbegin
			reverse_iterator		rbegin(void) {
				return this->_tree.rbegin();
			}
			const_reverse_iterator	rbegin(void) const {
				return this->_tree.rbegin();
			}

			//rend
			reverse_iterator		rend(void) {
				return this->_tree.rend();
			}
			const_reverse_iterator	rend(void) const {
				return this->_tree.rend();
			}

		// ******************** Capacity ******************** //

			// capacity
			bool		empty(void) const {
				return (this->_tree.size() == 0);
			}

			// size
			size_type	size(void) const {
				return this->_tree.size();
			}

			//max_size
			size_type	max_size(void) const {
				return this->_tree.max_size();			
			}

		// ******************** Element Access ******************** //

			//operator[]
			mapped_type	&operator[](const key_type& k) {
				iterator	res =  this->_tree.find(ft::make_pair(k, mapped_type()));

				if (res != this->_tree.end())
					return (res.node->data.second);
				else {
					ft::pair<iterator, bool>	res2 = this->_tree.insert(ft::make_pair(k, mapped_type()));
					return res2.first.node->data.second;
				}
			}

		// ******************** Modifiers ******************** //

			//insert
			iterator	insert(iterator pos, const value_type& val) {
				return (this->_tree.insert(pos, val));
			}

			template <class Ite>
			void	insert(Ite first, Ite last) {
				for (;  first != last; ++first)
					this->_tree.insert(*first);
			}

			ft::pair<iterator, bool>	insert(const value_type &val) {
				return this->_tree.insert(val);
			}

			// erase
			void		erase(iterator pos) {
				this->_tree.erase(pos);
			}

			void		erase(iterator first, iterator last) {
				while (first != last)
					this->_tree.erase(first++);
			}

			size_type	erase(const key_type& k) {
				return this->_tree.erase(ft::make_pair(k, mapped_type()));
			}

			// swap
			void	swap(map& x) {
				std::swap(this->_alloc, x._alloc);
				std::swap(this->_key_cmp, x._key_cmp);
				std::swap(this->_value_cmp, x._value_cmp);
				this->_tree.swap(x._tree);
			}

			//clear
			void	clear() {
				this->_tree.clear();
			}

		// ******************** Observers ******************** //

			// key_comp
			key_compare	key_comp(void) const {
				return this->_key_cmp;
			}

			// value_comp
			value_compare	value_comp(void) const {
				return this->_value_cmp;
			}

		// ******************** Operations ******************** //
		
			// find
			iterator		find(const key_type &k) {
				return this->_tree.find(ft::make_pair(k, mapped_type()));
			}
			
			const_iterator	find(const key_type& k) const {
				return this->_tree.find(ft::make_pair(k, mapped_type()));
			}

			//count
			size_type		count(const key_type& k) const {
				iterator	res = this->_tree.find(ft::make_pair(k, mapped_type()));
				
				return (res == this->_tree.end()) ? 0 : 1;
			}

			// lower bound
			iterator		lower_bound(const key_type& k) {
				return this->_tree.lower_bound(ft::make_pair(k, mapped_type()));
			}

			const_iterator	lower_bound(const key_type& k) const {
				return this->_tree.lower_bound(ft::make_pair(k, mapped_type()));
			}

			// upper_bound
			iterator		upper_bound(const key_type& k) {
				return this->_tree.upper_bound(ft::make_pair(k, mapped_type()));
			}

			const_iterator	upper_bound(const key_type& k) const {
				return this->_tree.upper_bound(ft::make_pair(k, mapped_type()));
			}

			//equal_range
			ft::pair<iterator,iterator>	equal_range(const key_type& k) {
				iterator	lower = lower_bound(k);
				iterator	upper = upper_bound(k);

				return ft::make_pair(lower, upper);
			}

			ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const {
				const_iterator	lower = lower_bound(k);
				const_iterator	upper = upper_bound(k);

				return ft::make_pair(lower, upper);
			}

			allocator_type	get_allocator() const {
				return this->_alloc;
			}
		
	}; // class map

	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator< (const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator> (const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc>& lhs,
						const map<Key, T, Compare, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
		x.swap(y);
	}

} // namespace ft

#endif