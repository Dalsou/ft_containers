/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:12:23 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/19 17:13:55 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_NODE_HPP
#define MAP_NODE_HPP

namespace ft {

	template <typename T>
	struct	lstNode
	{
		T			data;
		lstNode*	next;
		lstNode*	prev;

		lstNode(const T &src = T()) : 
		data(src), next(this), prev(this) {};
	};

	template <typename T>
	struct	mapNode
	{
		private:
			bool _unused;
			#if __APPLE__ == 0
				int _unused_for_linux;
			#endif

		public:
			T			data;
			mapNode*	parent;
			mapNode*	left;
			mapNode*	right;

			mapNode(const T &src = T()) :
			data(src), parent(NULL), left(NULL), right(NULL) {};
	};

	template <typename T>
	mapNode<T>	*farRight(mapNode<T> *node) {
		while (node->right != NULL)
			node = node->right;
		return (node);
	}

	template <typename T>
	mapNode<T>	*farLeft(mapNode<T> *node) {
		while (node->left != NULL)
			node = node->left;
		return (node);
	}

} // namespace f

#endif