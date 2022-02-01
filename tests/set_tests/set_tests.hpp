/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:03:14 by afoulqui          #+#    #+#             */
/*   Updated: 2022/02/01 18:07:07 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TESTS_HPP
#define SET_TESTS_HPP

#include "../../set/set.hpp"

#include <set>
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

#define RESET "\e[0m"
#define MAGENTA "\e[1;95m"
#define CYAN "\e[1;96m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mOK\033[0m\n") : (std::cout << "\033[1;31mKO\033[0m\n"))
#define TIME_FAC 20

typedef std::pair<std::set<int>::iterator, std::set<int>::iterator> iter_def;
typedef ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ft_iter_def;

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

time_t	get_time(void);

void	iterator_tests(void);
void	const_iterator_tests(void);
void	reverse_iterator_tests(void);
void 	testIterators();
void 	testCapacityMethods();
void 	testElementAccess();
void 	testModifiers();
void	testObservers();
void	testOperations();
void	testNonMemberSwap();
void	testRetionalOperators();
void 	testConstructors();

#endif