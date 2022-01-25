/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:51:33 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:21 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return(msecs_time);
}	

void	get_allocator_test() {
    TITLE("get_allocator method");
    {
        std::vector<std::string> v(200, "hello");
        ft::vector<std::string> ft_v(200, "hello");
        
        EQUAL(v.get_allocator().max_size() == ft_v.get_allocator().max_size());
    }
}

void vector_tests(void)
{
	std::cout << CYAN << "\tTesting Constructors" << RESET << std::endl;
	TEST_CASE(vector_constructor_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Operators" << RESET << std::endl;
	TEST_CASE(vector_operator_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Iterator Functions" << RESET << std::endl;
	TEST_CASE(iterator_functions_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Capacity Functions" << RESET << std::endl;
	TEST_CASE(capacity_functions_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Element Access Functions" << RESET << std::endl;
	TEST_CASE(element_functions_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Modifier Functions" << RESET << std::endl;
	TEST_CASE(modifier_functions_tests);
	sleep(1);
	std::cout << CYAN << "\tTesting Get Allocator Function" << RESET << std::endl;
	TEST_CASE(get_allocator_test);
	sleep(1);
	std::cout << CYAN << "\tTesting Non Member Functions" << RESET << std::endl;
	TEST_CASE(non_member_functions_tests);
}

void alarm_handler(int seg)
{
    (void)seg;
    std::cout << "\033[1;33mTLE\033[0m\n";
    kill(getpid(), SIGINT);
}

int main(void)
{
    signal(SIGALRM, alarm_handler);

	std::cout << "\n\t\t\t\033[093;1m*.................................*";
	std::cout << "\n\t\t\t*                                 *";
	std::cout << "\n\t\t\t*\t    VECTOR TEST           *";
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
    vector_tests();

    return 0;
}