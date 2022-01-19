/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:20:01 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/19 17:11:28 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

# ifndef __APPLE__
#  define __APPLE__ 0
# endif

# include <iostream>
# include <string>
# include <memory>
# include <limits>
# include <cstddef> // ptrdiff_t
# include <sstream> // ostring

namespace ft {

	// struct enable_if<bool, true>
	template <bool, class IsTrue = void>
	struct enable_if;

	template <class IsTrue>
	struct enable_if<true, IsTrue> {
		typedef IsTrue type;
	};

	// Relational Operators Comparison Functions
	template <class Ite1, class Ite2>
	bool	equal(Ite1 first1, Ite1 last1, Ite2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class Ite1, class Ite2>
	bool	lexicographical_compare(Ite1 first1, Ite1 last1, Ite2 first2, Ite2 last2)
	{
		while (first1 != last1 && first2 != last2 && *first1 == *first2)
		{
			++first1;
			++first2;
		}
		if (first1 == last1)
			return (first2 != last2);
		else if (first2 == last2)
			return (false);
		return (*first1 < *first2);
	}

	template <class I> struct is_integral { static const bool value = false;};
	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<short int> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long int> { static const bool value = true; };
	template <> struct is_integral<long long int> { static const bool value = true; };
	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<unsigned short int> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long int> { static const bool value = true; };
	template <> struct is_integral<unsigned long long int> { static const bool value = true; };

} // namespace ft

#endif