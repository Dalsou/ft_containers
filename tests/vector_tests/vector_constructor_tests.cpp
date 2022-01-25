/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor_tests.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:56:15 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 11:22:44 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void	vector_constructor_tests() {
	TITLE("fill constructor");
	{
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;

            start = get_time();
            std::vector<std::string>    v(10000, "fill constructor test");
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft::vector<std::string>    my_v(10000, "fill constructor test");
            ualarm(0, 0);
        }
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- fill tow vectors with a 10 strings ------*/
        ft::vector<std::string>		my_v(10, "fill constructor test");
        std::vector<std::string>	v(10, "fill constructor test");
        /*---------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res;
        /*---------------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
            res += *it;
        
        for(ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
            my_res += *it;
        EQUAL(res == my_res);
	}
    TITLE("range constructor");
	{
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            std::vector<std::string>    v(10000, "range constructor test");
            start = get_time();
            std::vector<std::string>	v1(v.begin(), v.end());
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft::vector<std::string>		my_v(v.begin(), v.end());
            ualarm(0, 0);
        }
        /*-----------------------------------------------------------------------------------------------*/
        /*--------------- fill std::vector with 10 strings and ft::vector with range of iterators ------*/
        std::vector<std::string>    v(10, "range constructor test");
        ft::vector<std::string>     my_v(10, "range constructor test");
        ft::vector<std::string>		my_v1(my_v.begin(), my_v.end()); // this one is to check if the range works with ft::vector
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res, my_res1;
        /*--------------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
            res += *it;
        
        for(ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
            my_res += *it;

        for(ft::vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it) // fill my_res1 from ft::vector
            my_res1 += *it;
        EQUAL(res == my_res && my_res == my_res1);
	}
    TITLE("copy constructor");
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            std::vector<char>    v(10000, 'a');
            start = get_time();
            std::vector<char>	copy_v(v);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  20)  :  20;

            ft::vector<char>    my_v(10000, 'a');
            alarm(diff);
            ft::vector<char>	my_copy_v(my_v);
            alarm(0);
        }
        /*---------------------------------------------------------------------------------------------*/
        /*---------------------------- declare a vector and fill with 'a', and create a copy of it ------------------*/
        ft::vector<char>    v1(10, 'a');
        ft::vector<char>    copy_v(v1);
        /*-----------------------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, res1;
        /*--------------------------------------------------------*/
        for(ft::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::vector<char>::iterator it = copy_v.begin(); it != copy_v.end(); ++it) // fill res from copy_v
            res1 += *it;
        EQUAL(res == res1);
    }
}