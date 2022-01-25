/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:15:37 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/24 18:41:51 by afoulqui         ###   ########.fr       */
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
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " get_allocator method "
              << "] --------------------]\t\t\033[0m";
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

    std::cout << RED << "________________________________________________________________________________________________________" << std::endl;
    std::cout << RED << "**** The test is taking so much time to test the all cases and the time complexity of each method ****" << std::endl;
    std::cout << RED << "--------------------------------------------------------------------------------------------------------" << RESET << std::endl;
    signal(SIGALRM, alarm_handler);

    std::cout << YELLOW << "Testing Iterators;" << RESET << std::endl;
    TEST_CASE(iterator_tests);
    TEST_CASE(const_iterator_tests);
    TEST_CASE(reverse_iterator_tests);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Constructors;" << RESET << std::endl;
    TEST_CASE(testConstructors);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Iterator Methods;" << RESET << std::endl;
    TEST_CASE(testIterators);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Capacity Methods;" << RESET << std::endl;
    TEST_CASE(testCapacityMethods)
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Access Element Methods; " << RESET << std::endl;
    TEST_CASE(testElementAccess);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Modifiers Methods;" << RESET << std::endl;
    TEST_CASE(testModifiers)
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Observers Methods;" << RESET << std::endl;
    TEST_CASE(testObservers)
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Operations Methods;" << RESET << std::endl;
    TEST_CASE(testOperations)
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Allocator Methods;" << RESET << std::endl;
    TEST_CASE(testAllocatorMethodes)
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Retional Operators; " << RESET << std::endl;
    TEST_CASE(testRetionalOperators);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing Non-Member Swap  ; " << RESET << std::endl;
    TEST_CASE(testNonMemberSwap);
    std::cout << std::endl;

    
    return 0;
}
