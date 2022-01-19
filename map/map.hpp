/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:49:33 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/19 17:43:34 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../shared/utils.hpp"
#include "../shared/reverse_iterator.hpp"
#include "pair.hpp"
#include "map_node.hpp"
#include "map_iterator.hpp"


namespace ft {

template < class Key,
		   class T,
		   class Compare = std::less<Key>,
		   class Alloc = std::allocator<pair<const Key, T> >
		   >
	class map {

		// ******************** Aliases ******************** //
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
			typedef pair<const key_type, mapped_type>				value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;

			typedef ft::mapNode<value_type>							node_type;
			typedef node_type*										node_ptr;

			typedef ft::map_iterator<value_type, node_type>			iterator;
			typedef ft::map_iterator<const value_type, node_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			class	value_compare {
				public:
					Compare _comp;

					value_compare(Compare comp) :
					_comp(comp) {};

					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					
					bool	operator()(const value_type& x, const value_type& y) const {
						return _comp(x.first, y.first);
					}	
			};

		// ******************** Attributes ******************** //
		private:
			node_ptr		_data;
			key_compare		_key_cmp;
			allocator_type	_alloc;
			size_type		_size;

		public :

		// ******************** Constructors & Destructor ******************** //
			
			// Constructor
			explicit map(const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()) :
			_data(), _key_cmp(comp), _alloc(alloc), _size(0) {
				this->_data = new node_type;
			};

			// Destructor
			virtual ~map(void) {
				this->clear();
				delete this->_data;
			};
			
			// Range constructor
			template <class Ite>
			map(Ite first, Ite last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
				typename enable_if<!is_integral<Ite>::value,Ite >::type = Ite()) :
			_data(), _key_cmp(comp), _alloc(alloc), _size(0) {
				this->_data = new node_type;
				this->insert(first, last);
			};
			
			// Copy constrcutor
			map(const map &src) :
			_data(), _key_cmp(key_compare()), _alloc(allocator_type()), _size(0) {
				this->_data = new node_type;
				*this = src;
			};

			// Assignment operator
			map& operator=(map const &op) {
				if (&op == this)
					return *this;
				this->clear();
				this->insert(op.begin(), op.end());
				return *this;
			};

		// ******************** Iterators ******************** //

			// begin
			iterator				begin(void) {
				return iterator(farLeft(this->_data));
			};
			const_iterator			begin(void) const {
				return const_iterator(farLeft(this->_data));
			};

			//end
			iterator				end(void) {
				return iterator(farRight(this->_data));
			};
			const_iterator			end(void) const {
				return const_iterator(farRight(this->_data));
			};

			//rbegin
			reverse_iterator		rbegin(void) {
				return reverse_iterator(this->end());
			};
			const_reverse_iterator	rbegin(void) const {
				return const_reverse_iterator(this->end());
			};

			//rend
			reverse_iterator		rend(void) {
				return reverse_iterator(this->begin());
			};
			const_reverse_iterator	rend(void) const {
				return const_reverse_iterator(this->begin());
			};

		// ******************** Capacity ******************** //

			// capacity
			bool		empty(void) const {
				if (this->_size == 0)
					return true;
				return false;
			};

			// size
			size_type	size(void) const {
				return this->_size;
			};

			//max_size
			size_type	max_size(void) const {
				return std::numeric_limits<difference_type>::max() / (sizeof(node_type) / 2 ?: 1);
			};

		// ******************** Element Access ******************** //

			//operator[]
			mapped_type	&operator[](const key_type& k) {
				return (this->insert(value_type(k, mapped_type()))).first->second;
			};

		// ******************** Modifiers ******************** //

			//insert
			iterator	insert(iterator position, const value_type& val) {
				static_cast<void>(position);
				return this->insert(val).first;
			};

			template <class Ite>
			void	insert(Ite first, Ite last) {
				while (first != last) {
					this->insert(*first++);
				}
			};

			ft::pair<iterator, bool>	insert(const value_type &val) {
				ft::pair<iterator, bool> res;

				res.second = !this->count(val.first);
				if (res.second == true)
					this->BTreeAdd(new node_type(val));
				res.first = this->find(val.first);
				return res;
			};

			// erase
			void		erase(iterator position) {
				this->erase(position++, position);
			};

			void		erase(iterator first, iterator last) {
				while (first != last)
					this->BTreeRM((first++)._node);
			};

			size_type	erase(const key_type& k) {
				iterator element = this->find(k);
				if (element == this->end())
					return 0;
				this->BTreeRM(element._node);
				return 1;
			};

			// swap
			void	swap(map& x) {
				map	tmp;

				tmp._copyContent(x);
				x._copyContent(*this);
				this->_copyContent(tmp);
			};

			//clear
			void	clear() {
				node_ptr	tmp = this->end()._node;
				if (this->_size == 0)
					return ;
				tmp->parent->right = NULL;
				this->BTreeClear(this->_data);
				this->_data = tmp;
				this->_size = 0;
			};

		// ******************** Observers ******************** //

			// key_comp
			key_compare	key_comp(void) const {
				return key_compare();
			};

			// value_comp
			value_compare	value_comp(void) const {
				return value_compare(key_compare());
			};

		// ******************** Operations ******************** //
		
			// find
			iterator		find(const key_type &k) {
				iterator it = this->begin();
				iterator ite = this->end();

				while (it != ite) {
					if (this->KeyEq(it->first, k))
						break ;
					++it;
				}
				return it;
			};
			
			const_iterator	find(const key_type& k) const {
				const_iterator	it = this->begin();
				const_iterator	ite = this->end();

				while (it != ite) {
					if (this->KeyEq(it->first, k))
						break;
					++it;
				}
				return it;
			};

			//count
			size_type		count(const key_type& k) const {
				const_iterator	it = this->begin();
				const_iterator	ite = this->end();
				size_type		res = 0;

				while (it != ite) {
					if (this->KeyEq((it++)->first, k)) {
						++res;
						break ;
					}
				}
				return res;
			};

			// lower bound
			iterator		lower_bound(const key_type& k) {
				iterator	it = this->begin();
				iterator	ite = this->end();

				while (it != ite) {
					if (!this->_key_cmp(it->first, k))
						break ;
					++it;
				}
				return it;
			};

			const_iterator	lower_bound(const key_type& k) const {
				const_iterator	it = this->begin();
				const_iterator	ite = this->end();

				while (it != ite) {
					if (!this->_key_cmp(it->first, k))
						break ;
					++it;
				}
				return it;
			};

			// upper_bound
			iterator		upper_bound(const key_type& k) {
				iterator	it = this->begin();
				iterator	ite = this->end();

				while (it != ite) {
					if (this->_key_cmp(k, it->first))
						break ;
					++it;
				}
				return (it);
			};

			const_iterator	upper_bound(const key_type& k) const {
				const_iterator	it = this->begin();
				const_iterator	ite = this->end();

				while (it != ite) {
					if (this->_key_cmp(k, it->first))
						break ;
					++it;
				}
				return (it);
			};

			//equal_range
			pair<iterator,iterator>	equal_range(const key_type& k) {
				pair<iterator, iterator> res;

				res.first = this->lower_bound(k);
				res.second = this->upper_bound(k);
				return res;
			};

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const {
				pair<const_iterator, const_iterator> res;

				res.first = this->lower_bound(k);
				res.second = this->upper_bound(k);
				return res;
			};

			allocator_type	get_allocator() const {
				return this->_alloc;
			}

		private :
			
			void	_copyContent(map& src) {
				this->clear();
				node_ptr tmp = this->_data;

				this->_data = src._data;
				this->_key_cmp = src._key_cmp;
				this->_alloc = src._alloc;
				this->_size = src._size;
				src._data = tmp; src._size = 0;
				tmp = NULL;
			};

			void	BTreeClear(node_ptr node) {
				if (node == NULL)
					return ;
				this->BTreeClear(node->left);
				this->BTreeClear(node->right);
				delete node;
			};

			void	BTreeAdd(node_ptr newNode) {
				node_ptr	*parent = &this->_data;
				node_ptr	*node = &this->_data;
				node_ptr	ghost = farRight(this->_data);
				bool		side_left = -1;

				++this->_size;
				while (*node && *node != ghost) {
					parent = node;
					side_left = this->_key_cmp(newNode->data.first, (*node)->data.first);
					node = (side_left ? &(*node)->left : &(*node)->right);
				}
				if (*node == NULL) {
					newNode->parent = (*parent);
					*node = newNode;
				}
				else {
					*node = newNode;
					newNode->parent = ghost->parent;
					ghost->parent = farRight(newNode);
					farRight(newNode)->right = ghost;
				}
			};

			void	BTreeRM(node_ptr rmNode) {
				node_ptr	replaceNode = NULL;
				node_ptr	*rmPlace = &this->_data;

				--this->_size;
				if (rmNode->parent)
				rmPlace = (rmNode->parent->left == rmNode ? &rmNode->parent->left : &rmNode->parent->right);
				if (rmNode->left == NULL && rmNode->right == NULL)
					;
				else if (rmNode->left == NULL)
					replaceNode = rmNode->right;
				else {
					replaceNode = farRight(rmNode->left);
					if (replaceNode != rmNode->left)
						if ((replaceNode->parent->right = replaceNode->left))
							replaceNode->left->parent = replaceNode->parent;
				}
				if (replaceNode) {
					replaceNode->parent = rmNode->parent;
					if (rmNode->left && rmNode->left != replaceNode) {
						replaceNode->left = rmNode->left;
						replaceNode->left->parent = replaceNode;
					}
					if (rmNode->right && rmNode->right != replaceNode) {
						replaceNode->right = rmNode->right;
						replaceNode->right->parent = replaceNode;
					}
				}
				*rmPlace = replaceNode;
				delete rmNode;
			};

			bool	KeyEq(const key_type& k1, const key_type& k2) const {
					return (!this->_key_cmp(k1, k2) && !this->_key_cmp(k2, k1));
			};
		
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