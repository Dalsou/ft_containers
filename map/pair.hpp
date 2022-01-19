/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:28:23 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/19 11:55:48 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

	template <class T1, class T2>
	struct	pair
	{
		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;

		// Constructors 
		pair(void) : first(), second() {};

		template<class U, class V>
		pair(const pair<U, V> &src) :
		first(src.first), second(src.second) {};

		pair(const first_type &a, const second_type &b) :
		first(a), second(b) {};

		pair&	operator=(const pair &src) {
			if (this == &src)
				return (*this);
			this->first = src.first;
			this->second = src.second;
			return *this;
		}
	}; // struct pair

	// Comparaison Operators
	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}

	template <class T1, class T2>
  	pair<T1, T2> make_pair(T1 x, T2 y) {
    	return (pair<T1, T2>(x, y));
  	}

} // namespace ft

#endif