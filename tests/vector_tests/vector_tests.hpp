/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:48:38 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/21 11:20:35 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

# include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
#include "../../stack/stack.hpp"       // your stack path.
#include "../../vector/vector.hpp" // your Vector path.
#include "../../map/map.hpp"  // path to ft::pair.


# define BLUE "\e[0;34m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RESET "\e[0m"

# define EQUAL(x) ((x) ? (std::cout << "\033[1;32mOK\033[0m\n") : (std::cout << "\033[1;31mKO\033[0m\n"))
# define TIME_FAC 20 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

time_t 	get_time(void);

// ITERATOR TESTS
void    iterator_tests(void);
void    const_iterator_tests(void);
void    reverse_iterator_tests(void);
void    reverse_iterator_with_ft_vector(void);

void	vector_constructor_tests();
void	vector_operator_tests();
void	iterator_functions_tests();
void	capacity_functions_tests();
void	element_functions_tests();
void	modifier_functions_tests();
void	non_member_functions_tests();

#endif