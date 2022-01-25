/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_functions_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:09:42 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 11:20:30 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void	element_functions_tests() {
	TITLE("operator[] method");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1[1e6 - 1];
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1[1e6 - 1];
            ualarm(0, 0);
        }
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<char>    const   v2(10, '9');
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<char>    const   ft_v2(10, '9');
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, ft_s1, ft_s2;

        for (size_t i = 0; i < v1.size(); ++i)
        {
            if (i == v1.size() - 1)
                v1[i] = "other";
            s1 += v1[i];
        }

        for (size_t i = 0; i < ft_v1.size(); ++i)
        {
            if (i == ft_v1.size() - 1)
                ft_v1[i] = "other";
            ft_s1 += ft_v1[i];
        }

        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2[i];

        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2[i];
        
        EQUAL(s1 == ft_s1 && s2 == ft_s2);
    }
    TITLE("at method");
   	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.at(1e6 - 1);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.at(1e6 - 1);
            ualarm(0, 0);
        }
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<char>    const   v2(10, '9');
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<char>    const   ft_v2(10, '9');
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, ft_s1, ft_s2;
        // bool to check if an exception is throwed
        bool exce_throwed = false;

        try
        {
            ft_v1.at(20);
        }
        catch (std::out_of_range const& e)
        {
            (void)e;
            exce_throwed = true;
        }
        for (size_t i = 0; i < v1.size(); ++i)
        {
            if (i == v1.size() - 1)
                v1.at(i) = "other";
            s1 += v1.at(i);
        }
        for (size_t i = 0; i < ft_v1.size(); ++i)
        {
            if (i == ft_v1.size() - 1)
                ft_v1.at(i) = "other";
            ft_s1 += ft_v1.at(i);
        }

        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2.at(i);
        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2.at(i);

        EQUAL(s1 == ft_s1 && s2 == ft_s2 && exce_throwed);
    }
    TITLE("front method");
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<int>    const   v2(10, 9);
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<int>    const   ft_v2(10, 9);

        v1.front() = "LEET";
        ft_v1.front() = "LEET";
        EQUAL(v1.front() == ft_v1.front() && v2.front() == ft_v2.front());
    }
    TITLE("back method");
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<int>    const   v2(10, 9);
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<int>    const   ft_v2(10, 9);

        v1.back() = "LEET";
        ft_v1.back() = "LEET";
        EQUAL(v1.back() == ft_v1.back() && v2.back() == ft_v2.back());
    }
}