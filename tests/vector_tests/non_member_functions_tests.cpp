/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_functions_tests.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:19:18 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/21 11:20:39 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void	non_member_functions_tests() {
	std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator== " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*----------------------------------- test 1: lhs.size == rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e6, "string");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v == v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e6, "string");
                ft::vector<std::string>     ft_v1(1e6, "string");
                ualarm(diff * 1e3, 0);
                (void)(ft_v == ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
            /*----------------------------------- test 2: lhs.size != rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e5, "hello");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v == v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e5, "hello");
                ft::vector<std::string>     ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                (void)(ft_v == ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
        }
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = ((v == v1) == (ft_v == ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int>    v(50, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(50, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = (cond && (v == v1) == (ft_v == ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(50, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(50, 5);

            cond = (cond && (v == v1) == (ft_v == ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator!= " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*----------------------------------- test 1: lhs.size == rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e6, "string");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v != v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e6, "string");
                ft::vector<std::string>     ft_v1(1e6, "string");
                ualarm(diff * 1e3, 0);
                (void)(ft_v != ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
            /*----------------------------------- test 2: lhs.size != rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e5, "hello");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v != v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e5, "hello");
                ft::vector<std::string>     ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                (void)(ft_v != ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
        }
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = ((v != v1) == (ft_v != ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int>    v(50, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(50, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = (cond && (v != v1) == (ft_v != ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(50, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(50, 5);

            cond = (cond && (v != v1) == (ft_v != ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator< " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*----------------------------------- test 1: lhs.size == rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e6, "string");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v < v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e6, "string");
                ft::vector<std::string>     ft_v1(1e6, "string");
                ualarm(diff * 1e3, 0);
                (void)(ft_v < ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
            /*----------------------------------- test 2: lhs.size != rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e5, "hello");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v < v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e5, "hello");
                ft::vector<std::string>     ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                (void)(ft_v < ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
        }
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = ((v < v1) == (ft_v < ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int>    v(50, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(50, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = (cond && (v < v1) == (ft_v < ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(50, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(50, 5);

            cond = (cond && (v < v1) == (ft_v < ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator<= " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*----------------------------------- test 1: lhs.size == rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e6, "string");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v <= v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e6, "string");
                ft::vector<std::string>     ft_v1(1e6, "string");
                ualarm(diff * 1e3, 0);
                (void)(ft_v <= ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
            /*----------------------------------- test 2: lhs.size != rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e5, "hello");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v <= v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e5, "hello");
                ft::vector<std::string>     ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                (void)(ft_v <= ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
        }
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = ((v <= v1) == (ft_v <= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int>    v(50, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(50, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = (cond && (v <= v1) == (ft_v <= ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(50, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(50, 5);

            cond = (cond && (v <= v1) == (ft_v <= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator> " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*----------------------------------- test 1: lhs.size == rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e6, "string");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v > v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e6, "string");
                ft::vector<std::string>     ft_v1(1e6, "string");
                ualarm(diff * 1e3, 0);
                (void)(ft_v > ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
            /*----------------------------------- test 2: lhs.size != rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e5, "hello");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v > v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e5, "hello");
                ft::vector<std::string>     ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                (void)(ft_v > ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
        }
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = ((v > v1) == (ft_v > ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int>    v(50, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(50, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = (cond && (v > v1) == (ft_v > ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(50, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(50, 5);

            cond = (cond && (v > v1) == (ft_v > ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator>= " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*----------------------------------- test 1: lhs.size == rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e6, "string");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v >= v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e6, "string");
                ft::vector<std::string>     ft_v1(1e6, "string");
                ualarm(diff * 1e3, 0);
                (void)(ft_v >= ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
            /*----------------------------------- test 2: lhs.size != rhs.size ---------------------*/
            {
                /*------------------ std::vectors ---------------------*/
                std::vector<std::string>    v(1e5, "hello");
                std::vector<std::string>    v1(1e6, "string");
                start = get_time();
                (void)(v >= v1);
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(1e5, "hello");
                ft::vector<std::string>     ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                (void)(ft_v >= ft_v1);
                ualarm(0, 0);
            }
            /*---------------------------------------------------------------------------------------*/
        }
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = ((v >= v1) == (ft_v >= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int>    v(50, 5);
            std::vector<int>    v1(100, 5);
            ft::vector<int>     ft_v(50, 5);
            ft::vector<int>     ft_v1(100, 5);

            cond = (cond && (v >= v1) == (ft_v >= ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int>    v(100, 5);
            std::vector<int>    v1(50, 5);
            ft::vector<int>     ft_v(100, 5);
            ft::vector<int>     ft_v1(50, 5);

            cond = (cond && (v >= v1) == (ft_v >= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " swap " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v(1e6, "string");
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            swap(v, v1);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>     ft_v(1e6, "string");
            ft::vector<std::string>     ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            swap(ft_v, ft_v1);
            ualarm(0, 0);
        }
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type  s, ft_s;
        ft::vector<std::string>::size_type  c, ft_c;
        ft::vector<std::string>::iterator b1, b2;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*---------------------------------- test 1: equal size vectors ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            std::vector<std::string> v1(200, "string");
            ft::vector<std::string> ft_v(200, "hello");
            ft::vector<std::string> ft_v1(200, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            swap(v, v1);
            swap(ft_v, ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs > rhs ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            std::vector<std::string> v1(50, "string");
            ft::vector<std::string> ft_v(200, "hello");
            ft::vector<std::string> ft_v1(50, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            swap(v, v1);
            swap(ft_v, ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs < rhs ----------------------*/
        {
            std::vector<std::string> v(50, "hello");
            std::vector<std::string> v1(200, "string");
            ft::vector<std::string> ft_v(50, "hello");
            ft::vector<std::string> ft_v1(200, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            swap(v, v1);
            swap(ft_v, ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
}