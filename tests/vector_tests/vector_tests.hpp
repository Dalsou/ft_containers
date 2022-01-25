/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:48:38 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 11:32:34 by afoulqui         ###   ########.fr       */
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


#define RESET "\e[0m"
#define MAGENTA "\e[1;95m"
#define CYAN "\e[1;96m"

# define EQUAL(x) ((x) ? (std::cout << "\033[1;32mOK\033[0m\n") : (std::cout << "\033[1;31mKO\033[0m\n"))
# define TIME_FAC 20

#define TITLE(str) \
	std::cout << "\t\t\033[1;37m" << std::setw(30) << std::left << str << "   ===== >\t\t\033[0m";
using namespace std;

#define TEST_CASE(fn)                                                                                        \
    cout << MAGENTA << "\t==========================================================================" << RESET << endl;			 \
    cout << endl;                                                                                            \
    fn();                                                                                                    \
    cout << endl;                                                                                            \
    cout << MAGENTA << "\t==========================================================================\n" << RESET << endl;
using namespace std;

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