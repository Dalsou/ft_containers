/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:53:07 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/17 15:13:20 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "utils.hpp"
# include "random_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft {

	template< typename T, typename Alloc = std::allocator<T> >
	class vector {

		// ******************** Aliases ******************** //
		
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

		// ******************** Attributes ******************** //

		private:
			value_type*				_data;
			allocator_type			_alloc;
			size_type				_size;
			size_type				_capacity;

		public :

		// ******************** Iterator class ******************** //

		class iterator : public random_iterator<value_type> {
		
			protected:
				typedef random_iterator<value_type> iter;
				iterator(value_type *src) : random_iterator<value_type>(src) {};
		
			private:
				iterator(const random_iterator<value_type> &src) : random_iterator<value_type>(src) {};

			public:
				iterator() : random_iterator<value_type>() {};
				iterator(const iterator &src) : random_iterator<value_type>(src) {};

				typedef value_type&			reference;
				typedef value_type*			pointer;

				reference	operator*() const {
					return *this->_value;
				};

				pointer	operator->() const {
					return this->_value;
				};

				iterator&	operator+=(difference_type n) {
					this->_value += n;
					return *this;
				};
				iterator&	operator-=(difference_type n) {
					this->_value -= n;
					return *this;
				};
				reference	operator[](difference_type n) const {
					return this->_value[n];
				};

				// Increment
				iterator&	operator++() {
					iter::operator++();
					return *this;
				};

				iterator	operator++(int) {
					return iter::operator++(0);
				};

				// Decrement
				iterator&	operator--() {
					iter::operator--();
					return *this; 
				};
				iterator	operator--(int) {
					return iter::operator--(0);
				};

				// Increment by n
				iterator	operator+(difference_type n) const {
					return iter::operator+(n);
				};

				// Decrement by n
				iterator	operator-(difference_type n) const {
					return iter::operator-(n);
				};

				difference_type	operator-(const random_iterator<value_type> &n) const { 
					return iter::operator-(n);
				};

				friend iterator	operator+(difference_type n, const iterator &it) { 
					return it.operator+(n);
				};

				friend class vector;
			
		}; // class iterator

		// ******************** Const Iterator class ******************** //

		class const_iterator : public random_iterator<value_type> {
		
			protected:
				typedef random_iterator<value_type> iter;
				const_iterator(value_type *src) : random_iterator<value_type>(src) {};
		
			public:
				const_iterator() : random_iterator<value_type>() {};
				const_iterator(const random_iterator<value_type> &src) : random_iterator<value_type>(src) {};

				typedef const value_type&		reference;
				typedef const value_type*		pointer;

				reference	operator*() const {
					return *this->_value;
				};

				pointer	operator->() const {
					return this->_value;
				};

				const_iterator&	operator+=(difference_type n) {
					this->_value += n;
					return *this;
				};

				const_iterator&	operator-=(difference_type n) {
					this->_value -= n;
					return *this;
				};

				reference	operator[](difference_type n) const {
					return this->_value[n];
				};

				// Increment				
				const_iterator&	operator++() {
					iter::operator++();
					return *this;
				};

				const_iterator	operator++(int) {
					return iter::operator++(0);
				};

				// Decrement
				const_iterator&	operator--() {
					iter::operator--();
					return *this;
				};

				const_iterator	operator--(int) {
					return iter::operator--(0);
				};

				// Increment by n
				const_iterator	operator+(difference_type n) const {
					return iter::operator+(n);
				};

				// Decrement by n
				const_iterator	operator-(difference_type n) const {
					return iter::operator-(n);
				};
				
				difference_type	operator-(const random_iterator<value_type> &n) const {
					return iter::operator-(n);
				};

				friend const_iterator	operator+(difference_type n, const const_iterator &it) {
					return it.operator+(n);
				};

				friend class vector;

		}; // class const_iterator

		// ******************** Reverse & const reverse iterators ******************** //
	
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// ******************** Constructors & Destructor ******************** //

			// Default Constructors
			explicit vector(const allocator_type& alloc = allocator_type()) :
			_data(NULL), _alloc(alloc), _size(0), _capacity(0) {};

			// Destructor
			virtual ~vector() {
				this->destroyData();
			};

			// Constructor
			explicit vector(size_type size, const value_type& value = value_type(),
							const allocator_type& alloc = allocator_type()) :
			_data(NULL), _alloc(alloc), _size(0), _capacity(0) {
				this->createData(size, value);
			};

			// Constructor Iterator Range
			template <class Ite>
			vector(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first,
					Ite last, const allocator_type& alloc = allocator_type()) :
			_data(NULL), _alloc(alloc), _size(0), _capacity(0) {
				this->createData(this->getItLen(first, last), first, last);
			};
	
			// Copy constructor
			vector(const vector &src) :
			_data(NULL), _alloc(allocator_type()), _size(0), _capacity(0) {
				*this = src;
			};

			// Assignment Operator
			vector	&operator=(vector const &op) {
				if (&op == this)
					return *this;
				const_iterator first = op.begin();
				const_iterator last = op.end();
				size_type len = this->getItLen(first, last);
				this->createData((len > this->_capacity) ? len : this->_capacity, first, last);
				return *this;
			};

			// ******************** Iterators ******************** //

			// begin
			iterator		begin() {
				return iterator(this->_data);
			};
			const_iterator	begin() const {
				return const_iterator(this->_data);
			};

			// end
			iterator		end() {
				return iterator(&this->_data[this->_size]);
			};
			const_iterator	end() const {
				return const_iterator(&this->_data[this->_size]);
			};

			// rbegin
			reverse_iterator		rbegin() {
				return reverse_iterator(&this->_data[this->_size]);
			};
			const_reverse_iterator	rbegin() const {
				return const_reverse_iterator(&this->_data[this->_size]);
			};

			// rend
			reverse_iterator		rend() {
				return reverse_iterator(this->_data);
			};
			const_reverse_iterator	rend() const {
				return const_reverse_iterator(this->_data);
			};

			// ******************** Capacity ******************** //

			// size
			size_type	size() const {
				return this->_size;
			};

			// max_size
			size_type	max_size() const {
				return this->_alloc.max_size();
			};

			// resize
			void	resize(size_type size, value_type val = value_type()) {
				if (this->_size > size) {
					while (this->_size > size) {
						this->_alloc.destroy(&this->_data[--this->_size]);
					}	
				}
				else {
					size_type const &lambda = (__APPLE__ ? this->_capacity : this->_size);

					if (this->_capacity >= size)
						;
					else if (lambda * 2 >= size)
						this->reserve(lambda * 2);
					else
						this->reserve(size);
					while (this->_size < size) {
						this->_alloc.construct(&this->_data[this->_size++], val);
					}
				}
			};

			// capacity
			size_type	capacity() const {
				return this->_capacity;
			};

			// empty
			bool		empty() const {
				if (this->_size == 0)
					return true;
				return false;
			};

			// reserve
			void	reserve(size_type n) {
				if (this->max_size() < n)
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				if (this->capacity() >= n)
					return ;
				this->createData(n, this->begin(), this->end());
			};

			// ******************** Element Access ******************** //

			// operator[]
			reference			operator[](size_type n) {
				return this->_data[n];
			};
			const_reference		operator[](size_type n) const {
				return this->_data[n];
			};

			// at
			reference			at(size_type n) {
				if (this->_size > n)
					return (*this)[n];
				std::ostringstream ostr;
				ostr << "vector";
				if (!__APPLE__)
					ostr << "::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->_size << ")";
				throw std::out_of_range(ostr.str());
			};
			const_reference		at(size_type n) const {
				if (this->_size > n)
					return (*this)[n];
				std::ostringstream ostr;
				ostr << "vector";
				if (!__APPLE__)
					ostr << "::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->_size << ")";
				throw std::out_of_range(ostr.str());
			};

			// front
			reference			front() {
				return (*this)[0];
			};
			const_reference		front() const {
				return (*this)[0];
			};

			// back
			reference			back() {
				return (*this)[this->_size - 1];
			};
			const_reference		back() const {
				return (*this)[this->_size - 1];
			};

			// ******************** Modifiers ******************** //

			// assign
			void	assign(size_type n, const value_type &val) {
				if (this->_capacity < n)
					this->createData(n, val);
				else {
					this->clear();
					while (this->_size < n) {
						this->_alloc.construct(&this->_data[this->_size], val);
						this->_size++;
					}
				}
			};

			template <class Ite>
			void	assign(typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type first, Ite last) {
				size_type size = this->getItLen(first, last);
				if (this->_capacity < size)
					this->createData(size, first, last);
				else {
					this->clear();
					while (first != last) {
						this->_alloc.construct(&this->_data[this->_size], *first);
						this->_size++;
						first++;
					}
				}
			};

			// push_back
			void	push_back(const value_type &val) {
				if (this->_size == this->_capacity)
					this->resize(this->_size + 1, val);
				else {
					this->_alloc.construct(&this->_data[this->_size], val);
					this->_size++;
				}
			};

			// pop_back
			void	pop_back() {
				this->_alloc.destroy(&this->_data[this->_size]);
				this->_size--;
			};

			// insert
			iterator	insert(iterator position, const value_type &val) {
				difference_type i = position - this->begin();
				this->insert(position, 1, val);
				return (iterator(this->begin() + i));
			};

			void	insert(iterator position, size_type n, const value_type &val) {
				difference_type const	i = position - this->begin();
				difference_type const	old_end_i = this->end() - this->begin();
				iterator				old_end;
				iterator				end;

				this->resize(this->_size + n);
				end = this->end();
				position = this->begin() + i;
				old_end = this->begin() + old_end_i;
				while (old_end != position) {
					*--end = *--old_end;
				}
				while (n-- > 0) {
					*position++ = val;
				}
			};
			
			template <class Ite>
			void	insert(iterator position, Ite first, typename ft::enable_if<!std::numeric_limits<Ite>::is_integer, Ite>::type last) {
				difference_type const	i = position - this->begin();
				difference_type const	old_end_i = this->end() - this->begin();
				iterator				old_end;
				iterator				end;

				this->resize(this->_size + (this->getItLen(first, last)));
				end = this->end();
				position = this->begin() + i;
				old_end = this->begin() + old_end_i;
				while (old_end != position) {
					*--end = *--old_end;
				}
				while (first != last) {
					*position++ = *first++;
				}
			};
			
			// erase
			iterator	erase(iterator ite) {
				return this->erase(ite, ite + 1);
			};

			iterator	erase(iterator first, iterator last) {
				iterator	tmp = first;
				iterator	end = this->end();
				size_type	deleted = this->getItLen(first, last);

				while (last != end) {
					*first = *last;
					++first;
					++last;
				}
				while (deleted > 0) {
					this->_alloc.destroy(&this->_data[this->_size]);
					deleted--;
					--this->_size;
				}
				return tmp;
			};

			// swap
			void	swap(vector &x) {
				vector<T, Alloc> tmp;

				tmp.copyContent(x);
				x.copyContent(*this);
				this->copyContent(tmp);
			};

			// clear
			void	clear() {
				while (this->_size > 0) {
					this->_alloc.destroy(&this->_data[this->_size]);
					--this->_size;
				}
			};

		private :

			//get it len
			template <class Ite>
			size_type	getItLen(Ite first, Ite last) {
				size_type	i = 0;
				while (first != last){
					++first;
					++i;
				}
				return (i);
			};

			// create data
			template <class Ite>
			void	createData(difference_type capacity, Ite first, Ite last) {
				vector<T, Alloc> res;
				difference_type len = this->getItLen(first, last);

				if (capacity < len || capacity < 0)
					__APPLE__ ? throw std::length_error("vector") : throw std::bad_alloc();
				res._alloc = this->_alloc;
				res._size = len; res._capacity = capacity;
				res._data = res._alloc.allocate(capacity);
				for (size_type i = 0; first != last; ++first)
					res._alloc.construct(&res._data[i++], *first);
				this->destroyData();
				this->copyContent(res);
			};

			void	createData(size_type size, const value_type &val = value_type()) {
				this->destroyData();
				this->_data = this->_alloc.allocate(size);
				for (size_type i = 0; i < size; ++i)
					this->_alloc.construct(&this->_data[i], val);
				this->_size = size; this->_capacity = size;
			};

			// destroy data	
			void	destroyData() {
				if (!this->_data)
					return ;
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = NULL; this->_size = 0; this->_capacity = 0;
			};

			// copy data
			template <class Ite, class Iterator>
			static void	copyData(Ite start, Iterator first, Iterator last) {
				while (first != last) {
					*start = *first;
					++start;
					++first;
				}
			};

			// copy content	
			void	copyContent(vector &vec) {
				this->_data = vec._data;
				this->_alloc = vec._alloc;
				this->_size = vec._size;
				this->_capacity = vec._capacity;
				vec._data = NULL;
				vec._size = 0;
				vec._capacity = 0;
			};

	}; // class vector

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }
	
} // ft namespace

#endif