/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:13:27 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/19 11:51:53 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include "../vector/vector.hpp"

namespace ft {

	template<class T, class Container = ft::vector<T> >
	class stack {

		public :
			/* ------------------------ ALIASES ----------------------- */
			typedef T					value_type;
			typedef Container			container_type;
			typedef size_t				size_type;

		protected :
			/* ------------------------ ATTRIBUTE ----------------------- */
			container_type 				_ctnr;

		public :
			// Copy Constructor
			stack(const stack& src) : _ctnr(src._ctnr) {};

			//Assignment Operator
			stack& operator=(const stack& op) {
				if (&op == this)
					return (*this);
				this->_ctnr = op._ctnr;
				return (*this);
			};

		public :

			// Constructors & Destructor
			explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {};
			~stack() {};

			// Member Function Overloads
			bool 				empty() const { return (_ctnr.empty()); };
			size_type 			size() const { return (_ctnr.size()); };
			value_type& 		top() { return (_ctnr.back()); };
			const value_type& 	top() const { return (_ctnr.back()); };
			void 				push (const value_type& val) { _ctnr.push_back(val); };
			void 				pop() { _ctnr.pop_back(); };

			// Non-Member Function Overloads
			friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs._ctnr == rhs._ctnr);
			}

			friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs._ctnr < rhs._ctnr);
			}

	};

	// Non-Member Function Overloads
	
	template <class T, class Container>	
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Container>	
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Container>	
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Container>	
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return !(lhs < rhs);
	}
}

#endif