/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:31:50 by afoulqui          #+#    #+#             */
/*   Updated: 2022/02/04 12:01:14 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "pair.hpp"
#include "rbtree_iterator.hpp"
#include "../shared/reverse_iterator.hpp"

#define BLACK false
#define RED true

namespace ft {

    template <typename T>
    struct rb_node {

        T           value;
        rb_node*    left;
        rb_node*    right;
        rb_node*    parent;
        bool        color;

        rb_node(T v, rb_node *l, rb_node* r, rb_node *p, bool c = BLACK) :
        value(v), left(l), right(r), parent(p), color(c) {}

		rb_node(const T& src = T()) :
		value(src), left(NULL), right(NULL), parent(NULL), color(BLACK) {}
        
        //~rb_node() {}

    }; // struct rb_node

	template <typename T>
	rb_node<T>	*farRight(rb_node<T>* node) {
		while (node->right != NULL)
			node = node->right;
		return (node);
	}

	template <typename T>
	rb_node<T>	*farLeft(rb_node<T> *node) {
		while (node->left != NULL)
			node = node->left;
		return (node);
	}

}