/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:31:50 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/19 14:34:09 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {

	template <class Iterator> 
	class iterator_traits {

		public:
			typedef typename Iterator::difference_type			difference_type;
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer					pointer;
			typedef typename Iterator::reference				reference;
			typedef typename std::random_access_iterator_tag	iterator_category;
	};

	template <class It> 
	class iterator_traits<It*> {

		public:
			typedef It											value_type;
			typedef	value_type&									reference;
			typedef	value_type const&							const_reference;
			typedef	value_type*									pointer;
			typedef ptrdiff_t									difference_type;
			typedef typename std::random_access_iterator_tag	iterator_category;
	};

	template <class It> 
	class iterator_traits<const It*> {
		
		public:
			typedef It											value_type;
			typedef	value_type&									reference;
			typedef	value_type const&							const_reference;
			typedef	value_type*									pointer;
			typedef ptrdiff_t									difference_type;
			typedef typename std::random_access_iterator_tag	iterator_category;
	};

} // namespace ft

#endif