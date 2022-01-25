/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:14:36 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 11:57:27 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTS_HPP
#define MAP_TESTS_HPP

#include "../../stack/stack.hpp"       // your stack path.
#include "../../vector/vector.hpp" // your Vector path.
#include "../../map/map.hpp"  // path to ft::pair.

#include <map>
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define RESET "\e[0m"
#define MAGENTA "\e[1;95m"
#define CYAN "\e[1;96m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mOK\033[0m\n") : (std::cout << "\033[1;31mKO\033[0m\n"))
#define TIME_FAC 20

typedef std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> iter_def;
typedef ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_iter_def;
typedef std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator> const_iter_def;
typedef ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator> ft_const_iter_def;

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