/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_functions_tests.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:02:46 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/21 11:03:40 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void	iterator_functions_tests() {
	std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " begin and end methods " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.begin();
            v1.end();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.begin();
            ft_v1.end();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<std::string>    const v2(10, "string2");
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<std::string>    const ft_v2(10, "string2");
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;
        for(std::vector<std::string>::const_iterator rit = v2.begin(); rit != v2.end(); ++rit) // fill c_res from const v1
            c_res += *rit;

        for(ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;
        for(ft::vector<std::string>::const_iterator rit = ft_v2.begin(); rit != ft_v2.end(); ++rit) // fill c_ft_res from const ft_v1
            c_ft_res += *rit;

        EQUAL(res == ft_res && c_res == c_ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.rbegin();
            v1.rend();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.rbegin();
            ft_v1.rend();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<std::string>    const v2(10, "string2");
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<std::string>    const ft_v2(10, "string2");
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit) // fill res from v1
            res += *rit;
        for(std::vector<std::string>::const_reverse_iterator rit = v2.rbegin(); rit != v2.rend(); ++rit) // fill c_res from const v1
            c_res += *rit;

        for(ft::vector<std::string>::reverse_iterator rit = ft_v1.rbegin(); rit != ft_v1.rend(); ++rit) // fill ft_res from ft_v1
            ft_res += *rit;
        for(ft::vector<std::string>::const_reverse_iterator rit = ft_v2.rbegin(); rit != ft_v2.rend(); ++rit) // fill c_ft_res from const ft_v1
            c_ft_res += *rit;

        EQUAL(res == ft_res && c_ft_res == c_res);
	}
}