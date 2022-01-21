/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operator_tests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:59:49 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/21 11:31:42 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void	vector_operator_tests() {
	/*------------------------------------------ = operator tests --------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 1 : test with equale size vecotrs ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size = rhs.size) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string1");
            std::vector<std::string>    v2(1e6, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string1");
            ft::vector<std::string>    ft_v2(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string1");
        std::vector<std::string>    v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string1");
        ft::vector<std::string>    ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 2 : test with diff size vecotrs ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size < rhs.size) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e4, "string1");
            std::vector<std::string>    v2(1e6, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e4, "string1");
            ft::vector<std::string>    ft_v2(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string1");
        std::vector<std::string>    v2(20, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string1");
        ft::vector<std::string>    ft_v2(20, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 3 : test with diff size vecotrs ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size > rhs.size) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string1");
            std::vector<std::string>    v2(1e4, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string1");
            ft::vector<std::string>    ft_v2(1e4, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(20, "string1");
        std::vector<std::string>    v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(20, "string1");
        ft::vector<std::string>    ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 4 : test with one empty vector ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size = 0) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1;
            std::vector<std::string>    v2(1e6, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1;
            ft::vector<std::string>    ft_v2(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1;
        std::vector<std::string>    v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1;
        ft::vector<std::string>    ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 5 : test with one empty vector ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (rhs.size = 0) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            std::vector<std::string>    v2;
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ft::vector<std::string>    ft_v2;
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<std::string>    v2;
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<std::string>    ft_v2;
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

            EQUAL(res == ft_res);
	}
}