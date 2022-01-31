/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:28:23 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/28 16:41:07 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

	template <class T, class U>
	struct	pair
	{
		public :
			typedef T		first_type;
			typedef U		second_type;

			first_type		first;
			second_type		second;

			// Constructors 
			pair() : first(first_type()), second(second_type()) {};

			pair(const first_type& a, const second_type& b) :
			first(a), second(b) {};

			template<class T1, class T2>
			pair(const pair<T1, T2>& src) :
			first(src.first), second(src.second) {};

			template<class T1, class T2>
			pair&	operator=(const pair<T1, T2>&op) {
				if (this == &op)
					return (*this);
				this->first = op.first;
				this->second = op.second;
				return *this;
			}
	}; // class pair

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

	template <typename T1, typename T2>
  	pair<T1, T2> make_pair(const T1& x, const T2& y) {
    	return (ft::pair<T1, T2>(x, y));
  	}

} // namespace ft

#endif