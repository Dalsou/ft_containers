/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:15:37 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 12:12:14 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tests.hpp"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

void testAllocatorMethodes()
{
    TITLE("get_allocator method");
    {
        int psize;
        ft::map<char, int> mymap;
        ft::pair<const char, int> *p;

        // allocate an array of 5 elements using mymap's allocator:
        p = mymap.get_allocator().allocate(5);

        psize = sizeof(std::map<char, int>::value_type) * 5;
        EQUAL(psize == 40);
        mymap.get_allocator().deallocate(p, 5);
    }
}

void alarm_handler(int seg)
{
    (void)seg;
    std::cout << "\033[1;33mTLE\033[0m\n";
    kill(getpid(), SIGINT);
}

int main()
{
    signal(SIGALRM, alarm_handler);

	std::cout << "\n\t\t\t\033[093;1m*.................................*";
	std::cout << "\n\t\t\t*                                 *";
	std::cout << "\n\t\t\t*\t     MAP  TEST            *";
	std::cout << "\n\t\t\t*                                 *";
	std::cout << "\n\t\t\t\033[093;1m*.................................*\033[0m\n\n";

	std::cout << CYAN << "\tTesting Iterator" << RESET << std::endl;
    TEST_CASE(iterator_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Const Iterator" << RESET << std::endl;
    TEST_CASE(const_iterator_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Reverse Iterator" << RESET << std::endl;
    TEST_CASE(reverse_iterator_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Constructors" << RESET << std::endl;
    TEST_CASE(testConstructors);
	sleep(1);
	std::cout << CYAN << "\tTesting Iterator Functions" << RESET << std::endl;
    TEST_CASE(testIterators);
	sleep(1);
	std::cout << CYAN << "\tTesting Capacity Functions" << RESET << std::endl;
    TEST_CASE(testCapacityMethods)
	sleep(1);
	std::cout << CYAN << "\tTesting Element Access Function" << RESET << std::endl;
    TEST_CASE(testElementAccess);
	sleep(1);
	std::cout << CYAN << "\tTesting Modifier Functions" << RESET << std::endl;
    TEST_CASE(testModifiers)
	sleep(1);
	std::cout << CYAN << "\tTesting Observer Functions" << RESET << std::endl;
    TEST_CASE(testObservers)
	sleep(1);
	std::cout << CYAN << "\tTesting Operation Functions" << RESET << std::endl;
    TEST_CASE(testOperations)
	sleep(1);
	std::cout << CYAN << "\tTesting Get Allocator Function" << RESET << std::endl;
    TEST_CASE(testAllocatorMethodes)
	sleep(1);
	std::cout << CYAN << "\tTesting Relational Operators" << RESET << std::endl;
    TEST_CASE(testRetionalOperators);
	sleep(1);
	std::cout << CYAN << "\tTesting Non Member Swap Function" << RESET << std::endl;
    TEST_CASE(testNonMemberSwap);

    return 0;
}
