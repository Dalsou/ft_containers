/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity_functions_tests.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:05:19 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/21 13:43:58 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void	capacity_functions_tests() {
	std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " size method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.size();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");          // fill constructor
        std::vector<std::string>    v2;                         // empty constructor
        std::vector<std::string>    v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string>    v4(v3);                     // copy constructor
        std::vector<std::string>    v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<std::string>    ft_v2;
        ft::vector<std::string>    ft_v3(ft_v1.begin(), ft_v1.end());
        ft::vector<std::string>    ft_v4(ft_v1);
        ft::vector<std::string>    ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        EQUAL(v1.size() == ft_v1.size() && v2.size() == ft_v2.size() 
        && v3.size() == ft_v3.size() && v4.size() == ft_v4.size() && v5.size() == ft_v5.size());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " capacity method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.capacity();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.capacity();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");          // fill constructor
        std::vector<std::string>    v2;                         // empty constructor
        std::vector<std::string>    v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string>    v4(v3);                     // copy constructor
        std::vector<std::string>    v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<std::string>    ft_v2;
        ft::vector<std::string>    ft_v3(ft_v1.begin(), ft_v1.end());
        ft::vector<std::string>    ft_v4(ft_v1);
        ft::vector<std::string>    ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        EQUAL(v1.capacity() == ft_v1.capacity() && v2.capacity() == ft_v2.capacity() 
        && v3.capacity() == ft_v3.capacity() && v4.capacity() == ft_v4.capacity() && v5.capacity() == ft_v5.capacity());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " max_size method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.max_size();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.max_size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/

        std::vector<std::string>    v1(10, "string");
        std::vector<int>            v2;
        std::vector<double>         v4;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string>     ft_v1(10, "string2");
        ft::vector<int>             ft_v2;
        ft::vector<double>          ft_v4;
        /*----------------------------------------------------*/
        EQUAL(v1.max_size() == ft_v1.max_size() && v2.max_size() == ft_v2.max_size() 
        && v4.max_size() == ft_v4.max_size());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " resize method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
			/*
			 * test with n greater than vector capacity
			 */
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(10, "string2");
            start = get_time();
            v1.resize(1e6);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(10, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.resize(1e6);
            ualarm(0, 0);
            /*----------------------------------------------------*/
			/*
			 *	test with n lesser than capacity and greater than size
			 */
            /*------------------ std::vectors ---------------------*/
			v1.resize(20);
            start = get_time();
            v1.resize(1e5);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
			ft_v1.resize(20);
            ualarm(diff * 1e3, 0);
            ft_v1.resize(1e5);
            ualarm(0, 0);
            /*----------------------------------------------------*/
			/*
			 * test with n lesser than capacity and lesser an size
			 */
            /*------------------ std::vectors ---------------------*/
			v1.resize(100);
            start = get_time();
            v1.resize(50);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
			ft_v1.resize(100);
            ualarm(diff * 1e3, 0);
            ft_v1.resize(50);
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, s3, s4, ft_s1, ft_s2, ft_s3, ft_s4;
        std::string sit1, sit2, sit3, ft_sit1, ft_sit2, ft_sit3; // strings to store the result by iterators
		/*
		 * Var to store the size and the capacity
		 */
		size_t z1, z2, z3, z4, ft_z1, ft_z2, ft_z3, ft_z4;
		size_t c1, c2, c3, c4, ft_c1, ft_c2, ft_c3, ft_c4;
        /*
         * iterators to check the iterator validity
         *  it : iterator, eit : iterator to the end
         */
        std::vector<std::string>::iterator valid_it, valid_eit;
        ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
		/*
		 * test with n greater than vector capacity
		 */
		/*------------------ std::vectors ---------------------*/
		std::vector<std::string>    v1(10, "string2");
		v1.resize(1e6, "hello");
		/*------------------ ft::vectors ---------------------*/
		ft::vector<std::string>    ft_v1(10, "string2");
		ft_v1.resize(1e6, "hello");

		z1 = v1.size();
		ft_z1 = ft_v1.size();
        c1 = v1.capacity();
        ft_c1 = ft_v1.capacity();
		for (size_t i = 0; i < v1.size(); ++i)
			s1 += v1[i];
		
		for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_s1 += *it;
		/*----------------------------------------------------*/
		/*
		 *	test with n lesser than capacity and greater than size
		 */
		/*------------------ std::vectors ---------------------*/
		v1.resize(20);
        valid_it = v1.begin();
        valid_eit = v1.end();
		v1.resize(1e5);
		/*------------------ ft::vectors ---------------------*/
		ft_v1.resize(20);
        ft_valid_it = ft_v1.begin();
        ft_valid_eit = ft_v1.end();
		ft_v1.resize(1e5);

		z2 = v1.size();
		ft_z2 = ft_v1.size();
        c2 = v1.capacity();
        ft_c2 = ft_v1.capacity();
		for (size_t i = 0; i < v1.size(); ++i)
			s2 += v1[i];
        
        for (; valid_it != valid_eit; ++valid_it)
            sit1 += *valid_it;
		
		for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_s2 += *it;

        for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
            ft_sit1 += *ft_valid_it;
		/*----------------------------------------------------*/
		/*
		 * test with n lesser than capacity and lesser an size
		 */
		/*------------------ std::vectors ---------------------*/
        valid_it = v1.begin();
		v1.resize(50);
		/*------------------ ft::vectors ---------------------*/
        ft_valid_it = ft_v1.begin();
		ft_v1.resize(50);

		z3 = v1.size();
		ft_z3 = ft_v1.size();
        c3 = v1.capacity();
        ft_c3 = ft_v1.capacity();
		for (size_t i = 0; i < v1.size(); ++i)
			s3 += v1[i];

        for (; valid_it != v1.end(); ++valid_it)
            sit2 += *valid_it;
		
		for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_s3 += *it;

        for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
            ft_sit2 += *ft_valid_it;
		/*----------------------------------------------------*/
		/*
		 * test with n = 0
		 */
		/*------------------ std::vectors ---------------------*/
        valid_it = v1.begin();
		v1.resize(0, "string4");
		/*------------------ ft::vectors ---------------------*/
        ft_valid_it = ft_v1.begin();
		ft_v1.resize(0, "string4");

		z4 = v1.size();
		ft_z4 = ft_v1.size();
        c4 = v1.capacity();
        ft_c4 = ft_v1.capacity();
		for (size_t i = 0; i < v1.size(); ++i)
			s4 += v1[i];

        for (; valid_it != v1.end(); ++valid_it)
            sit3 += *valid_it;
		
		for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_s4 += *it;

        for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
            ft_sit3 += *ft_valid_it;
		/*----------------------------------------------------*/
		EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1 && sit1 == ft_sit1) && (s2 == ft_s2 &&  z2 == ft_z2 && c2 == ft_c2)
        && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3 && sit2 == ft_sit2) && (s4 == ft_s4 && z4 == ft_z4 && c4 == ft_c4 && sit3 == ft_sit3));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " empty method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.empty();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.empty();
            ualarm(0, 0);
        }
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<int>            v2;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<int>            ft_v2;
        
        EQUAL(v1.empty() == ft_v1.empty() && v2.empty() == ft_v2.empty());

    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " reserve method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(10, "string2");
            start = get_time();
            v1.reserve(1e6);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string>    ft_v1(10, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.reserve(1e6);
            ualarm(0, 0);
        }
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, s3, ft_s1, ft_s2, ft_s3;
        std::string sit1, ft_sit1; // strings to store the result by iterators
		/*
		 * Var to store the size and the capacity
		 */
		size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
		size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        /*
         * iterators to check the iterator validity
         *  it : iterator, eit : iterator to the end
         */
        std::vector<std::string>::iterator valid_it, valid_eit;
        ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
        // bool to check if the function throw or not
        bool exec_throwed = false;
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<char>            v2;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string>    ft_v1(10, "string2");
        ft::vector<char>            ft_v2;
        try
        {
            ft_v1.reserve(ft_v1.max_size() + 1);
        }
        catch(std::length_error const& e)
        {
            (void)e;
            exec_throwed = true;
        }
        v1.reserve(100);
        ft_v1.reserve(100);

		z1 = v1.size();
		ft_z1 = ft_v1.size();
        c1 = v1.capacity();
        ft_c1 = ft_v1.capacity();

        for (size_t i = 0; i < v1.size(); ++i)
            s1 += v1[i];
            
        ft_valid_it = ft_v1.begin();
        for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
            ft_s1 += *ft_valid_it;

        valid_it = v1.begin();
        valid_eit = v1.end();
        ft_valid_it = ft_v1.begin();
        ft_valid_eit = ft_v1.end();
        v1.reserve(50);
        ft_v1.reserve(50);

		z2 = v1.size();
		ft_z2 = ft_v1.size();
        c2 = v1.capacity();
        ft_c2 = ft_v1.capacity();

        for (size_t i = 0; i < v1.size(); ++i)
            s2 += v1[i];

        for (; valid_it != valid_eit; ++valid_it)
            sit1 += *valid_it;
            
        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
            ft_s2 += *it;

        for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
            ft_sit1 += *ft_valid_it;

        v2.reserve(200);
        ft_v2.reserve(200);
		z3 = v2.size();
		ft_z3 = ft_v2.size();
        c3 = v2.capacity();
        ft_c3 = ft_v2.capacity();

        for (size_t i = 0; i < v2.size(); ++i)
            s3 += v2[i];
            
        for (ft::vector<char>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it)
            ft_s3 += *it;
        
		EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1 && sit1 == ft_sit1) && (s2 == ft_s2 &&  z2 == ft_z2 && c2 == ft_c2)
        && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3) && exec_throwed);
    }
}