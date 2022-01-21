/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:13:27 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/20 11:20:09 by afoulqui         ###   ########.fr       */
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
			container_type 				c;

		public :
			// Copy Constructor
			stack(const stack& src) : c(src.c) {};

			//Assignment Operator
			stack& operator=(const stack& op) {
				if (&op == this)
					return (*this);
				this->c = op.c;
				return (*this);
			};

		public :

			// Constructors & Destructor
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {};
			~stack() {};

			// Member Function Overloads
			bool 				empty() const { return (c.empty()); };
			size_type 			size() const { return (c.size()); };
			value_type& 		top() { return (c.back()); };
			const value_type& 	top() const { return (c.back()); };
			void 				push (const value_type& val) { c.push_back(val); };
			void 				pop() { c.pop_back(); };

			// Non-Member Function Overloads
			friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c == rhs.c);
			}

			friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return (lhs.c < rhs.c);
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