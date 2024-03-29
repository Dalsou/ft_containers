/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:42:27 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/28 15:00:43 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "utils.hpp"
#include "iterator_traits.hpp"
#include "random_iterator.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {

		protected :
			typedef Iterator						iter;
			Iterator 								_base;

		public : 
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::value_type			value_type;

			// Constructors & Destructor
			reverse_iterator() : _base() {};
			reverse_iterator(Iterator base) : _base(base) {};
			Iterator base() const { return this->_base; };
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &src) : _base(src.base()) {};
			template <class Iter>
			reverse_iterator<Iterator>& operator=(const reverse_iterator<Iter>& op) {
				if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&op))
					return *this;
				this->_base = op.base();
				return *this;
			};
		
			// Access operator
			reference	operator*(void) const { 
				return (--iter(this->_base)).operator*();
			};
			pointer	operator->(void) const {
				return &this->operator*();
			};

			// Increment
			reverse_iterator&	operator++(void) {
				this->_base.operator--();
				return *this; 
			};
			reverse_iterator	operator++(int) { 
				return reverse_iterator(this->_base.operator--(0)); 
			};

			// Decrement
			reverse_iterator&	operator--(void) { 
				this->_base.operator++();
				return *this;
			};
			reverse_iterator	operator--(int) {
				return reverse_iterator(this->_base.operator++(0));
			};

			// Range's lenght between this random_iterator and another one.
			template <class Iter>
			difference_type	operator-(const reverse_iterator<Iter> &u) { 
				return u.base().operator-(this->_base);
			};

			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator(this->_base.operator-(n));
			};

			reverse_iterator&	operator+=(difference_type n) {
				this->_base.operator-=(n);
				return *this;
			};

			reverse_iterator	operator-(difference_type n) const {
				return reverse_iterator(this->_base.operator+(n));
			};

			reverse_iterator&	operator-=(difference_type n) {
				this->_base.operator+=(n); 
				return *this;
			};

			reference	operator[](difference_type n) const {
				return *this->operator+(n);
			};

			friend reverse_iterator	operator+(difference_type n, const reverse_iterator &it) {
				return it.operator+(n);
			};

			// Comparaison operators
			template <class Iter>
			bool operator==(const reverse_iterator<Iter> &rhs) const {
				return this->_base.operator==(rhs.base());
			};

			template <class Iter>
			bool operator!=(const reverse_iterator<Iter> &rhs) const {
				return this->_base.operator!=(rhs.base());
			};

			template <class Iter>
			bool operator<(const reverse_iterator<Iter> &rhs)
				const { return this->_base.operator> (rhs.base());
			};

			template <class Iter>
			bool operator<=(const reverse_iterator<Iter> &rhs) const {
				return this->_base.operator>=(rhs.base());
			};

			template <class Iter>
			bool	operator>(const reverse_iterator<Iter> &rhs) const {
				return this->_base.operator< (rhs.base());
			};
			
			template <class Iter>
			bool	operator>=(const reverse_iterator<Iter> &rhs) const {
				return this->_base.operator<=(rhs.base());
			};
	
	}; // class reverse_iterator

} //namespace ft

#endif