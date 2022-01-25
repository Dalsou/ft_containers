/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_functions_tests.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:13:38 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 11:21:32 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void	modifier_functions_tests() {
	TITLE("assign(fill) method");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.assign(1e6 + 1, "assign");
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.assign(1e6 + 1, "assign");
            ualarm(0, 0);
        }
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<char>            v2;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>     ft_v1(10, "string2");
        ft::vector<char>             ft_v2;
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, s3, ft_s1, ft_s2, ft_s3;
		/*
		 * Var to store the size and the capacity
		 */
		size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
		size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        // test for n greater than the vector capactiy
        v1.assign(20, "assign");
        ft_v1.assign(20, "assign");
        		
        z1 = v1.size();
        ft_z1 = ft_v1.size();
        c1 = v1.capacity();
        ft_c1 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s1 += v1.at(i);

        for (size_t i = 0; i < ft_v1.size(); ++i)
            ft_s1 += ft_v1.at(i);
        // test for n lesser than the vector capactiy
        v1.assign(10, "less");
        ft_v1.assign(10, "less");

        z2 = v1.size();
        ft_z2 = ft_v1.size();
        c2 = v1.capacity();
        ft_c2 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s3 += v1.at(i);

        for (size_t i = 0; i < ft_v1.size(); ++i)
            ft_s3 += ft_v1.at(i);
        // test for empty vectors
        v2.assign(20, 'h');
        ft_v2.assign(20, 'h');

        z3 = v2.size();
        ft_z3 = ft_v2.size();
        c3 = v2.capacity();
        ft_c3 = ft_v2.capacity();
        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2.at(i);
        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2.at(i);
        
        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2)
        && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
    }
    TITLE("assign(range) method");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            std::vector<std::string>    v2(1e4, "string2");
            start = get_time();
            v2.assign(v1.begin(), v1.end());
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ft::vector<std::string>    ft_v2(1e4, "string2");
            ualarm(diff * 1e3, 0);
            ft_v2.assign(ft_v1.begin(), ft_v1.end());
            ualarm(0, 0);
        }
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(20, "less");
        std::vector<std::string>    v2;
        std::vector<std::string>    v3(10, "string2");
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>     ft_v1(20, "less");
        ft::vector<std::string>     ft_v2;
        ft::vector<std::string>     ft_v3(10, "string2");
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, s3, ft_s1, ft_s2, ft_s3;
		/*
		 * Var to store the size and the capacity
		 */
		size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
		size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        // test for n greater than the vector capactiy
        v3.assign(v1.begin(), v1.end());
        ft_v3.assign(v1.begin(), v1.end());
        
        z1 = v3.size();
        c1 = v3.capacity();
        ft_z1 = ft_v3.size();
        ft_c1 = ft_v3.capacity();
        for (size_t i = 0; i < v3.size(); ++i)
            s1 += v3.at(i);

        for (size_t i = 0; i < ft_v3.size(); ++i)
            ft_s1 += ft_v3.at(i);
        // test for n lesser than the vector capactiy
        v1.assign(v3.begin(), v3.end());
        ft_v1.assign(ft_v3.begin(), ft_v3.end());

        z2 = v1.size();
        c2 = v1.capacity();
        ft_z2 = ft_v1.size();
        ft_c2 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s3 += v1.at(i);

        for (size_t i = 0; i < ft_v1.size(); ++i)
            ft_s3 += ft_v1.at(i);
        // test for empty vectors
        v2.assign(v1.begin(), v1.end());
        ft_v2.assign(ft_v1.begin(), ft_v1.end());

        z3 = v2.size();
        c3 = v2.capacity();
        ft_z3 = ft_v2.size();
        ft_c3 = ft_v2.capacity();
        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2.at(i);

        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2.at(i);
        
        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2)
        && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
    }
    TITLE("push_back method");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            // test 1: test with capacity greater than or equal the size + the new element (reallocation must'nt happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string>    v1(1e6, "string2");
                v1.reserve(1e6 + 1);
                start = get_time();
                v1.push_back("string1");
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>    ft_v1(1e6, "string2");
                ft_v1.reserve(1e6 + 1);
                ualarm(diff * 1e3, 0);
                ft_v1.push_back("string1");
                ualarm(0, 0);
            }
            /*--------------------------------------------------------------------------------------*/
            // test 2: test with capacity lesser than the size + the new element (reallocation must happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string>    v1(1e6, "string2");
                start = get_time();
                v1.push_back("string1");
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>    ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                ft_v1.push_back("string1");
                ualarm(0, 0);
            }
            /*--------------------------------------------------------------------------------------*/
        }
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>     ft_v;
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, s3, ft_s1, ft_s2, ft_s3;
		/*
		 * Var to store the size and the capacity
		 */
		size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
		size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        ft::vector<std::string>::iterator ft_it;
        // test for an empty vector
        v.push_back("hello");
        ft_v.push_back("hello");
        ft_it = ft_v.begin();
        // ft_it->length();
        
        z1 = v.size();
        c1 = v.capacity();
        ft_z1 = ft_v.size();
        ft_c1 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s1 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s1 += ft_v.at(i);
        /*---------------------------------------------*/
        // test for a vector with capacity >= size + the new element
        v.reserve(30);
        ft_v.reserve(30);
        v.push_back("string");
        ft_v.push_back("string");
        v.push_back("string");
        ft_v.push_back("string");

        z2 = v.size();
        c2 = v.capacity();
        ft_z2 = ft_v.size();
        ft_c2 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s2 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s2 += ft_v.at(i);
        /*---------------------------------------------------------*/
        // test for a vector with capactiy < size + the new element
        for (size_t i = 0; i < 100; ++i)
            v.push_back("string");
        for (size_t i = 0; i < 100; ++i)
            ft_v.push_back("string");

        z3 = v.size();
        c3 = v.capacity();
        ft_z3 = ft_v.size();
        ft_c3 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s3 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s3 += ft_v.at(i);
        
        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2)
        && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
    }
    TITLE("pop_back method");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.pop_back();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.pop_back();
            ualarm(0, 0);
        }
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v(20, "string");
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>     ft_v(20, "string");
		/*
		 * Strings to store the results
		 */
		std::string	s1, ft_s1;
		/*
		 * Var to store the size and the capacity
		 */
		size_t z1, ft_z1;
		size_t c1, ft_c1;
        v.pop_back();
        ft_v.pop_back();
        z1 = v.size();
        ft_z1 = ft_v.size();
        c1 = v.capacity();
        ft_c1 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s1 += v[i];
        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s1 += ft_v[i];
        EQUAL(z1 == ft_z1 && c1 == ft_c1 && s1 == ft_s1);
    }
    TITLE("insert method (single element)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            // test 1: test with capacity greater than or equal the size + the new element (reallocation must'nt happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string>    v1(1e6, "string2");
                v1.reserve(1e6 + 1);
                start = get_time();
                v1.insert(v1.begin() + 1e5, "string1");
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>    ft_v1(1e6, "string2");
                ft_v1.reserve(1e6 + 1);
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, "string1");
                ualarm(0, 0);
            }
            /*--------------------------------------------------------------------------------------*/
            // test 2: test with capacity lesser than the size + the new element (reallocation must happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string>    v1(1e6, "string2");
                start = get_time();
                v1.insert(v1.begin() + 1e5, "string1");
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>    ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, "string1");
                ualarm(0, 0);
            }
        }
        /*--------------------------------------------------------------------------------------*/
        /*
            * strings to store the resutls
            */
        std::string str, ft_str;
        /*
            * var to store the size and the capacity
            */
        ft::vector<std::string>::size_type  s, ft_s;
        ft::vector<std::string>::size_type  c, ft_c;
        ft::vector<std::string>::iterator   ft_it;
        std::vector<std::string>::iterator  it;
        /*
            * bool to store the comparison
            */
        bool cond;
    
        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string>    v;
            ft::vector<std::string>     ft_v;
            it = v.insert(v.begin(), "hello");
            ft_it = ft_v.insert(ft_v.begin(), "hello");
            // (*ft_it).length();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
           cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));
        }
        // insert at the end
        {
            std::vector<std::string>    v;
            ft::vector<std::string>     ft_v;

            it = v.insert(v.end(), "hello");
            ft_it = ft_v.insert(ft_v.end(), "hello");
            ft_it->length();
            
            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 2: the vector capacity >= size + the new element ----------------------------------------*/
        { 
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(30);
            ft_v.reserve(30);
            valid_it = ft_v.begin();
            it = v.insert(v.begin() + 10, "hello");
            ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
            ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 3: the vector capacity < size + the new element ----------------------------------------*/
        { 
            std::vector<std::string>    v(20, "string");
            ft::vector<std::string>     ft_v(20, "string");

            it = v.insert(v.begin() + 10, "hello");
            ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
            ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
        }
        /*---------------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    TITLE("insert method (fill)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
        //     // test 1: test with capacity greater than or equal the size + n (reallocation must'nt happen)
        //     /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string>    v1(1e6, "string2");
                v1.reserve(1e6 + 200);
                start = get_time();
                v1.insert(v1.begin() + 1e5, 100, "string1");
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>    ft_v1(1e6, "string2");
                ft_v1.reserve(1e6 + 200);
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, 100, "string1");
                ualarm(0, 0);
            }
        //     /*--------------------------------------------------------------------------------------*/
        //     // test 2: test with capacity lesser than the size + n (reallocation must happen)
        //     /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string>    v1(1e6, "string2");
                start = get_time();
                v1.insert(v1.begin() + 1e5, 200, "string1");
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>    ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, 200, "string1");
                ualarm(0, 0);
            }
        //     /*--------------------------------------------------------------------------------------*/
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
        /*
            * bool to store the comparison
            */
        bool cond;
    
        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string>    v;
            ft::vector<std::string>     ft_v;
            v.insert(v.begin(), 100, "hello");
            ft_v.insert(ft_v.begin(), 100, "hello");
            ft_v.begin()->length();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // insert at the end
        {
            std::vector<std::string>    v;
            ft::vector<std::string>     ft_v;

            v.insert(v.end(), "hello");
            ft_v.insert(ft_v.end(), "hello");
            ft_v.begin()->length();
            
            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 2: the vector capacity >= size + n ----------------------------------------*/
        { 
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(100);
            ft_v.reserve(100);
            valid_it = ft_v.begin();
            v.insert(v.begin() + 15, 70, "hello");
            ft_v.insert(ft_v.begin() + 15, 70, "hello");

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 3: the vector capacity < size + n && n > size ----------------------------------------*/
        { 
            std::vector<std::string>    v(20, "string");
            ft::vector<std::string>     ft_v(20, "string");

            v.insert(v.begin() + 10, 100, "hello");
            ft_v.insert(ft_v.begin() + 10, 100, "hello");

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 4: the vector capacity < size + n && n <= size ----------------------------------------*/
        { 
            std::vector<std::string>    v(20, "string");
            ft::vector<std::string>     ft_v(20, "string");

            v.insert(v.begin() + 10, 15, "hello");
            ft_v.insert(ft_v.begin() + 10, 15, "hello");

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    TITLE("insert method (range)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            // test 1: test with capacity greater than or equal the size + n (reallocation must'nt happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string>    v(100, "hello");
                std::vector<std::string>    v1(1e6, "string2");
                v1.reserve(1e6 + 200);
                start = get_time();
                v1.insert(v1.begin() + 1e5, v.begin(), v.end());
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>     ft_v(100, "hello");
                ft::vector<std::string>     ft_v1(1e6, "string2");
                ft_v1.reserve(1e6 + 200);
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, ft_v.begin(), ft_v.end());
                ualarm(0, 0);
            }
            /*--------------------------------------------------------------------------------------*/
            // test 2: test with capacity lesser than the size + n (reallocation must happen)
            /*------------------ std::vectors ---------------------*/
            {
                ft::vector<std::string>    v(1e5, "hello");
                ft::vector<std::string>    v1(1e6, "string2");
                start = get_time();
                v1.insert(v1.begin() + 1e5, v.begin(), v.end());
                end = get_time();
                diff = end - start;
                diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string>    ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, v.begin(), v.end());
                ualarm(0, 0);
            }
            /*--------------------------------------------------------------------------------------*/
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
        /*
            * bool to store the comparison
            */
        bool cond;
    
        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string>     v1(300, "string");
            std::vector<std::string>    v;
            ft::vector<std::string>     ft_v;
            v.insert(v.begin(), v1.begin(), v1.end());
            ft_v.insert(ft_v.begin(), v1.begin(), v1.end());
            ft_v.begin()->length();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // insert at the end
        {
            std::vector<std::string>    v;
            std::vector<std::string>    v1(300, "string");
            ft::vector<std::string>     ft_v;
            //ft::vector<std::string>     ft_v1(300, "string");

            v.insert(v.end(), v1.begin(), v1.end());
            ft_v.insert(ft_v.end(), v1.begin(), v1.end());
            ft_v.begin()->length();
            
            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 2: the vector capacity >= size + n ----------------------------------------*/
        { 
            std::vector<std::string>  v1(70, "hello");
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(100);
            ft_v.reserve(100);
            valid_it = ft_v.begin();
            v.insert(v.begin() + 15, v1.begin(), v1.end());
            ft_v.insert(ft_v.begin() + 15, v1.begin(), v1.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 3: the vector capacity < size + n && n > size ----------------------------------------*/
        { 
            std::vector<std::string>    v1(100, "hello");
            std::vector<std::string>    v(20, "string");
            ft::vector<std::string>     ft_v(20, "string");

            v.insert(v.begin() + 10, v1.begin(), v1.end());
            ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 4: the vector capacity < size + n && n <= size ----------------------------------------*/
        { 
            std::vector<std::string>     v1(15, "hello");
            std::vector<std::string>    v(20, "string");
            ft::vector<std::string>     ft_v(20, "string");

            v.insert(v.begin() + 10, v1.begin(), v1.end());
            ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*---------------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    TITLE("erase method (single element)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.erase(v1.begin() + 1e5);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>     ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.erase(ft_v1.begin() + 1e5);
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
        /*
         * bool to store the comparison
         */
        bool cond;

        std::vector<std::string> v(200, "hello");
        ft::vector<std::string> ft_v(200, "hello");
        ft::vector<std::string>::iterator valid_it;
        std::vector<std::string>::iterator it;
        ft::vector<std::string>::iterator ft_it;
        valid_it = ft_v.begin() + 99;
        it = v.erase(v.begin() + 100);
        ft_it = ft_v.erase(ft_v.begin() + 100);
        // ft_it->length();

        s = v.size();
        ft_s = ft_v.size();
        c = v.capacity();
        ft_c = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            str += v[i];
        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_str += ft_v[i];
        cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*(ft_v.begin() + 99))));
        //cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        EQUAL(cond);
    }
    TITLE("erase method (range)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.erase(v1.begin(), v1.end());
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>     ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.erase(ft_v1.begin(), ft_v1.end());
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
        std::vector<std::string>::iterator it;
        ft::vector<std::string>::iterator ft_it;
        /*
         * bool to store the comparison
         */
        bool cond;
        /*------------------ test 1: erase from the begin to end -------------------*/
        {
            std::vector<std::string>    v(100, "hello");
            ft::vector<std::string>     ft_v(100, "hello");
        
            it = v.erase(v.begin(), v.end());
            ft_it = ft_v.erase(ft_v.begin(), ft_v.end());

            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
            //cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }
        /*--------------------------------------------------------------------------*/
        /*------------------ test 2: erase from the begin to begin + 70 -------------------*/
        {
            std::vector<std::string>    v(100, "hello");
            ft::vector<std::string>     ft_v(100, "hello");
        
            it = v.erase(v.begin(), v.begin() + 70);
            ft_it = ft_v.erase(ft_v.begin(), ft_v.begin() + 70);
            // ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            //cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }
        /*--------------------------------------------------------------------------*/
        /*------------------ test 3: erase from the begin + 60 to end -------------------*/
        {
            std::vector<std::string>    v(100, "hello");
            ft::vector<std::string>     ft_v(100, "hello");
        
            it = v.erase(v.begin() + 60, v.end());
            ft_it = ft_v.erase(ft_v.begin() + 60, ft_v.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
           //cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }
        /*--------------------------------------------------------------------------*/
        /*------------------ test 4: erase from the begin + 20 to end - 30 -------------------*/
        {
            std::vector<std::string>    v(100, "hello");
            ft::vector<std::string>     ft_v(100, "hello");
        
            it = v.erase(v.begin() + 20, v.end() - 30);
            ft_it = ft_v.erase(ft_v.begin() + 20, ft_v.end() - 30);
            // ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            //cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }
        /*--------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    TITLE("swap method");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v(1e6, "string");
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v.swap(v1);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>     ft_v(1e6, "string");
            ft::vector<std::string>     ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v.swap(ft_v1);
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

            v.swap(v1);
            ft_v.swap(ft_v1);

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

            v.swap(v1);
            ft_v.swap(ft_v1);

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

            v.swap(v1);
            ft_v.swap(ft_v1);

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
    TITLE("clear method");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v(1e6, "string");
            start = get_time();
            v.clear();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>     ft_v(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v.clear();
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
        /*
         * bool to store the comparison
         */
        bool cond;

        /*---------------------------------- test 1: equal size vectors ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            ft::vector<std::string> ft_v(200, "hello");

            v.clear();
            ft_v.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*--------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
}