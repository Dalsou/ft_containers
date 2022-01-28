/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:56:44 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/28 14:53:52 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATOR_HPP
#define RANDOM_ITERATOR_HPP

#include "utils.hpp"

namespace ft {

	template <typename Ite>
	class random_iterator {

		protected:
			Ite*						_value;

		public:

			typedef Ite				value_type;
			typedef std::ptrdiff_t	difference_type;

			// Constructors & Destructor
			random_iterator() : _value(NULL) {};
			virtual ~random_iterator() {};
			random_iterator(Ite* value) : _value(value) {};
			random_iterator(const random_iterator& src) { *this = src; };
			random_iterator& operator=(random_iterator const& op) {
				if (&op == this)
					return *this;
				this->_value = op._value;
				return *this;
			};

			// Increment
			random_iterator<Ite>& operator++() {
				++this->_value;
				return *this;
			};

			random_iterator<Ite>	operator++(int) {
				random_iterator<Ite>	tmp(*this);
				++this->_value;
				return (tmp);
			};
			
			// Decrement
			random_iterator<Ite>& operator--() {
				--this->_value;
				return *this;
			};

			random_iterator<Ite>	operator--(int) {
				random_iterator<Ite>	tmp(*this);
				--this->_value;
				return (tmp);
			};

			// Increment by n
			random_iterator<Ite>	operator+(difference_type n) const {
				return random_iterator(this->_value + n);
			};

			// Decrement by n
			random_iterator<Ite>	operator-(difference_type n) const {
				return random_iterator(this->_value - n);
			};

			// Range's lenght between this random_iterator and another one.
			difference_type	operator-(const random_iterator &it) const {
				return this->_value - it._value;
			};
			
			friend random_iterator<Ite>	operator+(difference_type n, const random_iterator& it) { 
				return it.operator+(n);
			};

			// Comparaison operators
			bool operator==(const random_iterator &rhs) const {
				return this->_value == rhs._value;
			};
			bool operator!=(const random_iterator &rhs) const {
				return this->_value != rhs._value;
			};
			bool operator<(const random_iterator &rhs) const {
				return this->_value < rhs._value;
			};
			bool operator<=(const random_iterator &rhs) const {
				return this->_value <= rhs._value;
			};
			bool operator>(const random_iterator &rhs) const {
				return this->_value > rhs._value;
			};
			bool operator>=(const random_iterator &rhs) const {
				return this->_value >= rhs._value;
			};

	}; // class random_iterator

} // ft namespace

#endif