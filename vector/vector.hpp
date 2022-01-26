/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:53:07 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/21 14:40:29 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "../shared/utils.hpp"
# include "../shared/random_iterator.hpp"
# include "../shared/reverse_iterator.hpp"

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

		// ******************** Attributes ******************** //

		private:
			value_type*				_data;
			allocator_type			_alloc;
			size_type				_size;
			size_type				_capacity;

		public :

		// ******************** Constructors & Destructor ******************** //

			// Default Constructors
			explicit vector(const allocator_type& alloc = allocator_type()) :
			_data(NULL), _alloc(alloc), _size(0), _capacity(0) {};

			// Destructor
			virtual ~vector() {
				this->_alloc.deallocate(this->_data, this->_capacity);
			};

			// Constructor
			explicit vector(size_type size, const value_type& value = value_type(),
							const allocator_type& alloc = allocator_type()) :
			_data(NULL), _alloc(alloc), _size(0), _capacity(0) {
				this->_createData(size, value);
			};

			// Constructor Iterator Range
			template <class Ite>
			vector(Ite first, Ite last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<Ite>::value,Ite >::type = Ite()) :
			_data(NULL), _alloc(alloc), _size(0), _capacity(0) {
				this->_createData(this->_getItLen(first, last), first, last);
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
				size_type len = this->_getItLen(first, last);
				this->_createData((len > this->_capacity) ? len : this->_capacity, first, last);
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
			void	resize(size_type n, value_type val = value_type()) {
                if (n > this->_size) {
                    if (n > this->_capacity) {
                        reserve(n);
                        for (; this->_size < n ; this->_size++)
							this->_alloc.construct(&this->_data[this->_size], val);
                    }
                    else
                        for (; this->_size < n ; this->_size++)
							this->_alloc.construct(&this->_data[this->_size], val);
                }   
                else
                    for (size_t i = this->_size; i > n; i--)
                        this->_data[this->_size--].~value_type();
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
				if (n > max_size())
                    throw std::length_error("vector");
                if (n <= this->_capacity)
				    return ;
                pointer tmp = this->_alloc.allocate(n);
                for (size_type i = 0; i < this->_size; ++i)
                    _alloc.construct(&tmp[i], this->_data[i]);
                this->~vector();
                this->_capacity = n;
                this->_data = tmp;
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
                if (n > this->_size)
                    throw std::out_of_range("Out of Range error");
                return (this->_data[n]);
            }
			const_reference		at(size_type n) const {
               if (n > this->_size)
                    throw std::out_of_range("Out of Range error");
                return (this->_data[n]);
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
					reserve(n);
                for (size_type i = 0; i < n; i++)
                    this->_alloc.construct(&this->_data[i], val);
                this->_size = n;
			};

			template <class Ite>
			void	assign(Ite first, Ite last,  typename enable_if<!is_integral<Ite>::value,Ite >::type = Ite()) {
				size_type i = this->_getItLen(first, last);
                reserve(i);
				this->_size = 0;
				while (first != last)
					this->_alloc.construct(&this->_data[this->_size++], *first++);
			};

			// push_back
			void	push_back(const value_type& val) {
				if (this->_size == 0)
					reserve(1);
				else if (this->_capacity == this->_size)
					reserve(this->_capacity * 2);
				this->_alloc.construct(&this->_data[this->_size], val);
				this->_size++;
			};

			// pop_back
			void	pop_back() {
				if (this->_size > 0) {
					this->_alloc.destroy(&this->_data[this->_size - 1]);
					this->_size--;
				}
			};

			// insert
			iterator	insert(iterator position, const value_type &val) {
				difference_type i = position - this->begin();
				this->insert(position, 1, val);
				return iterator(&this->_data[i]);
			};

			void	insert(iterator position, size_type n, const value_type &val) {
				difference_type	d = position - this->begin();
                long long j = d;

                if ((this->_size + n) > this->_capacity)
                {
                    if (n > this->_size)
                        reserve(this->_size + n);
                    else
                        reserve(this->_capacity * 2);
                }
                else if (this->_size == 0)
                    reserve(n);
                for (long long i = this->_size - 1; i >= j; i--)
                    this->_alloc.construct(&this->_data[i + n], this->_data[i]);
                for (size_type i = 0; i < n; i++)
                    this->_alloc.construct(&this->_data[j++], val);
                this->_size += n;
			};
			
			template <class Ite>
			void	insert(iterator position, Ite first, Ite last, typename enable_if<!is_integral<Ite>::value,Ite >::type = Ite()) {
				difference_type	d = position - this->begin();
                size_type range = this->_getItLen(first, last);
                long long j = d;
                size_t n = range;
                if ((this->_size + n) > this->_capacity)
                {
                    if (n > this->_size)
                        reserve(this->_size + n);
                    else
                        reserve(this->_capacity * 2);
                }
                else if (this->_size == 0)
                    reserve(n);
                for (long long i = this->_size - 1; i >= j; i--)
                    this->_alloc.construct(&this->_data[i + n], this->_data[i]);
                for (size_type i = 0; i < n; i++)
                {
                    this->_alloc.construct(&this->_data[j++], *first);
                    first++;
                }
                this->_size += n;
			};
			
			// erase
			iterator	erase(iterator ite) {
				return this->erase(ite, ite + 1);
			};

			iterator	erase(iterator first, iterator last) {
				iterator	tmp = first;
				iterator	end = this->end();
				size_type	deleted = this->_getItLen(first, last);

				while (last != end) {
					*first = *last;
					first++;
					last++;
				}
				while (deleted > 0) {
					this->_alloc.destroy(&this->_data[--this->_size]);
					deleted--;
				}
				return tmp;
			};

			// swap
			void	swap(vector &x) {
				vector<T, Alloc> tmp;

				tmp._copyContent(x);
				x._copyContent(*this);
				this->_copyContent(tmp);
			};

			// clear
			void	clear() {
				while (this->_size > 0)
					this->_alloc.destroy(&this->_data[--this->_size]);
			};

			allocator_type	get_allocator() const {
				return this->_alloc;
			}

		private :

			//get it len
			template <class Ite>
			size_type	_getItLen(Ite first, Ite last) {
				size_type	i = 0;
				while (first != last){
					first++;
					i++;
				}
				return (i);
			};

			// create data
			template <class Ite>
			void	_createData(difference_type capacity, Ite first, Ite last) {
				vector<T, Alloc> res;
				difference_type len = this->_getItLen(first, last);

				if (capacity < len || capacity < 0)
					__APPLE__ ? throw std::length_error("vector") : throw std::bad_alloc();
				res._alloc = this->_alloc;
				res._size = len; res._capacity = capacity;
				res._data = res._alloc.allocate(capacity);
				for (size_type i = 0; first != last; ++first)
					res._alloc.construct(&res._data[i++], *first);
				this->_destroyData();
				this->_copyContent(res);
			};

			void	_createData(size_type size, const value_type &val = value_type()) {
				this->_destroyData();
				this->_data = this->_alloc.allocate(size);
				for (size_type i = 0; i < size; ++i)
					this->_alloc.construct(&this->_data[i], val);
				this->_size = size;
				this->_capacity = size;
			};

			// destroy data	
			void	_destroyData() {
				if (!this->_data)
					return ;
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = NULL; this->_size = 0; this->_capacity = 0;
			};

			// copy content	
			void	_copyContent(vector &vec) {
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
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }
	
} // ft namespace

#endif