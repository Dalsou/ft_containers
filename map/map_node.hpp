/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:31:50 by afoulqui          #+#    #+#             */
/*   Updated: 2022/02/04 12:01:14 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_NODE_HPP
#define MAP_NODE_HPP

#include <iomanip>

#include "pair.hpp"
#include "map_iterator.hpp"
#include "../shared/reverse_iterator.hpp"

namespace ft {

    template <typename T>
    struct map_node {

        T           value;
        map_node*   left;
        map_node*   right;
        map_node*   parent;
        bool        last;

        map_node(T v, map_node *l, map_node* r, map_node *p, bool lst = false) :
        value(v), left(l), right(r), parent(p), last(lst) {}

		map_node(const T& src = T()) :
		value(src), left(NULL), right(NULL), parent(NULL), last(false) {}

    }; // struct map_node

	template <typename T>
	map_node<T>*	toTheLeft(map_node<T>* node) {
		while (node && node->left)
			node = node->left;
		return node;
	}

}

#endif