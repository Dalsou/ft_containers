/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor_tests.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:51:17 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/21 16:53:22 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tests.hpp"


template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

bool testmapConstructors()
{
    bool cond;
    std::map<char, int> first;
    ft::map<char, int> m_first;

    for (size_t i = 97; i < 110; i++)
    {
        first[i - 97] = i;
        m_first[i - 97] = i;
    }

    std::map<char, int> copy(first);
    ft::map<char, int> m_copy(m_first);

    cond = first.size() == m_first.size() && comparemaps(first.begin(), first.end(), m_first.begin(), m_first.end());

    std::map<char, int> second(first.begin(), first.end());
    ft::map<char, int> m_second(m_first.begin(), m_first.end());

    cond = cond && second.size() == m_second.size() && comparemaps(second.begin(), second.end(), m_second.begin(), m_second.end());
    std::map<char, int> third(second);
    ft::map<char, int> m_third(m_second);

    cond = cond && third.size() == m_third.size() && comparemaps(third.begin(), third.end(), m_third.begin(), m_third.end());

    std::map<char, int, classcomp> fourth;  // class as Compare
    ft::map<char, int, classcomp> m_fourth; // class as Compare

    cond = fourth.size() == m_fourth.size() && cond && comparemaps(fourth.begin(), fourth.end(), m_fourth.begin(), m_fourth.end());

    bool (*fn_pt)(char, char) = fncomp;
    std::map<char, int, bool (*)(char, char)> fifth(fn_pt);  // function pointer as Compare
    ft::map<char, int, bool (*)(char, char)> m_fifth(fn_pt); // function pointer as Compare

    cond = fifth.size() == m_fifth.size() && cond && comparemaps(fifth.begin(), fifth.end(), m_fifth.begin(), m_fifth.end());

    first = std::map<char, int>();
    m_first = ft::map<char, int>();

    cond = copy.size() == m_copy.size() && cond && comparemaps(copy.begin(), copy.end(), m_copy.begin(), m_copy.end());

    return cond;
}

void testConstructors()
{
    TITLE("empty constructor");
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
             time_t start, end, diff;

             start = get_time();
             std::map<int, std::string> m;
             for (int i = 0; i < 100; ++i)
                 m.insert(std::make_pair(i, "fill constructor test"));
             end = get_time();
             diff = end - start;
             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

             ualarm(diff * 1e3, 0);

             ft::map<int, std::string> my_m;
             for (int i = 0; i < 100; ++i)
                 my_m.insert(ft::make_pair(i, "fill constructor test"));
             ualarm(0, 0);
        }
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- fill tow vectors with a 10 strings ------*/
        ft::map<int, std::string> my_m;
        std::map<int, std::string> m;
        for (int i = 0; i < 10; i++)
        {
            m.insert(std::make_pair(i, "Hello"));
            my_m.insert(ft::make_pair(i, "Hello"));
        }
        /*---------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res;
        /*---------------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it) // fill res from std::map
            res += it->second;
        for (ft::map<int, std::string>::iterator it = my_m.begin(); it != my_m.end(); ++it) // fill res from std::map
            my_res += it->second;
        EQUAL(res == my_res);
    }
    TITLE("range constructor");
    {
        /*---------------------------------- time limit test --------------------------------------------*/
         {
             time_t start, end, diff;
             std::map<int, std::string> m;
             ft::map<int, std::string> my_m;

             for (size_t i = 0; i < 100; i++)
             {
                 m.insert(std::make_pair(i, "range constructor test"));
                 my_m.insert(ft::make_pair(i, "range constructor test"));
             }

             start = get_time();
             std::map<int, std::string> m1(m.begin(), m.end());
             end = get_time();
             diff = end - start;
             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

             ualarm(diff * 1e3, 0);
             ft::map<int, std::string> my_m1(my_m.begin(), my_m.end());
             ualarm(0, 0);
         }
        /*-----------------------------------------------------------------------------------------------*/
        /*--------------- fill std::map with 10 strings and ft::map with range of iterators ------*/
        std::map<int, std::string> m;
        ft::map<int, std::string> my_m;
        for (size_t i = 0; i < 10; i++)
        {
            m.insert(std::make_pair(i, "range constructor test"));
            my_m.insert(ft::make_pair(i, "range constructor test"));
        }

        ft::map<int, std::string> my_m1(my_m.begin(), my_m.end()); // this one is to check if the range works with ft::map
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res, my_res1;
        int sum(0), my_sum(0), my_sum1(0);
        /*--------------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
        { // fill res from std::map
            res += it->second;
            sum += it->first;
        }

        for (ft::map<int, std::string>::iterator it = my_m.begin(); it != my_m.end(); ++it)
        { // fill my_res from ft::map
            my_res += it->second;
            my_sum += it->first;
        }

        for (ft::map<int, std::string>::iterator it = my_m1.begin(); it != my_m1.end(); ++it)
        { // fill my_res1 from ft::map
            my_res1 += it->second;
            my_sum1 += it->first;
        }
        EQUAL(res == my_res && my_res == my_res1);
    }
    TITLE("copy constructor");
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            std::map<int, char> m;
            ft::map<int, char> my_m;

            for (size_t i = 0; i < 100; i++)
            {
                m.insert(std::make_pair(i, 'X'));
                my_m.insert(ft::make_pair(i, 'X'));
            }

            start = get_time();
            std::map<int, char> copy_m(m);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * 20) : 20;

            alarm(diff);
            ft::map<int, char> my_copy_m(my_m);
            alarm(0);
        }
        /*---------------------------------------------------------------------------------------------*/
        /*---------------------------- declare a vector and fill with 'a', and create a copy of it ------------------*/
        ft::map<int, char> m1;
        for (int i = 0; i < 10; i++)
            m1.insert(ft::make_pair(i, 'a'));
        ft::map<int, char> copy_m(m1);
        /*-----------------------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, res1;
        /*--------------------------------------------------------*/
        for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, char>::iterator it = copy_m.begin(); it != copy_m.end(); ++it) // fill res from copy_m
            res1 += it->second;
        EQUAL(res == res1);
    }
    TITLE("constructors with costum comp");
    EQUAL(testmapConstructors());
    TITLE("operator= (lhs.s = rhs.s)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
         {
             time_t start, end, diff;
             std::map<int, std::string> m1;
             std::map<int, std::string> m2;
             ft::map<int, std::string> ft_m1;
             ft::map<int, std::string> ft_m2;
             for (int i = 0; i < 100; ++i)
             {
                 m1.insert(std::make_pair(i, "string1"));
                 m2.insert(std::make_pair(i, "string2"));
                 ft_m1.insert(ft::make_pair(i, "string1"));
                 ft_m2.insert(ft::make_pair(i, "string2"));
            }

             start = get_time();
             m1 = m2;
             end = get_time();
             diff = end - start;
             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
             /*-----------------------------------------------------*/
             /*------------------ ft::map ---------------------*/
             ualarm(diff * 1e3, 0);
             ft_m1 = ft_m2;
             ualarm(0, 0);
             /*----------------------------------------------------*/
         }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;
        for (int i = 0; i < 10; ++i)
        {
            m1.insert(std::make_pair(i, "string1"));
            m2.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string1"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }

        m1 = m2;
        ft_m1 = ft_m2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->first;

        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->first;

        EQUAL(res == ft_res);
    }

    TITLE("operator= deep copy");
    {
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m2;
        ft::map<int, std::string> ft_m1;
        for (int i = 0; i < 1e4; ++i)
        {
            m2.insert(std::make_pair(i, "string2"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }

        m1 = m2;
        ft_m1 = ft_m2;
        m2.begin()->second = "hello";
        ft_m2.begin()->second = "hello";

        EQUAL((m1.begin()->second != m2.begin()->second) && (ft_m1.begin()->second != ft_m2.begin()->second));
    }

    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 2 : test with diff size vecotrs ----------------------------------------------------------------------*/
    TITLE("= operator (lhs.s < rhs.s)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
         {
             time_t start, end, diff;
             /*------------------ std::map ---------------------*/
             std::map<int, std::string> m1;
             std::map<int, std::string> m2;
             ft::map<int, std::string> ft_m1;
             ft::map<int, std::string> ft_m2;

             for (int i = 0; i < 100; ++i)
             {
                 m1.insert(std::make_pair(i, "string1"));
                 ft_m1.insert(ft::make_pair(i, "string1"));
             }

             for (int i = 0; i < 100; ++i)
             {
                 m2.insert(std::make_pair(i, "string2"));
                 ft_m2.insert(ft::make_pair(i, "string2"));
             }

             start = get_time();
            m1 = m2;
             end = get_time();
             diff = end - start;
             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
             /*-----------------------------------------------------*/
             /*------------------ ft::map ---------------------*/
             ualarm(diff * 1e3, 0);
             ft_m1 = ft_m2;
             ualarm(0, 0);
             /*----------------------------------------------------*/
         }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;
        for(size_t i = 0; i < 100; ++i)
        {
            m2.insert(std::make_pair(i, "value"));
            ft_m2.insert(ft::make_pair(i, "value"));
        }
        m1 = m2;
        /*-----------------------------------------------------*/
        /*------------------ ft::map ---------------------*/
        ft_m1 = ft_m2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;

        EQUAL(res == ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 3 : test with diff size vecotrs ----------------------------------------------------------------------*/
    TITLE("= operator (lhs.s > rhs.s)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
         {
             time_t start, end, diff;
             /*------------------ std::map ---------------------*/
             std::map<int, std::string> m1;
             std::map<int, std::string> m2;
             ft::map<int, std::string> ft_m1;
             ft::map<int, std::string> ft_m2;

             for (int i = 0; i < 100; ++i)
             {
                 m1.insert(std::make_pair(i, "string1"));
                 ft_m1.insert(ft::make_pair(i, "string1"));
             }

             for (int i = 0; i < 100; ++i)
             {
                 m2.insert(std::make_pair(i, "string2"));
                 ft_m2.insert(ft::make_pair(i, "string2"));
             }
             start = get_time();
             m1 = m2;
             end = get_time();
             diff = end - start;
             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
             /*-----------------------------------------------------*/
             /*------------------ ft::map ---------------------*/
             ualarm(diff * 1e3, 0);
             ft_m1 = ft_m2;
             ualarm(0, 0);
             /*----------------------------------------------------*/
         }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;

        for (int i = 0; i < 20; ++i)
        {
            m1.insert(std::make_pair(i, "string1"));
            ft_m1.insert(ft::make_pair(i, "string1"));
        }

        for (int i = 0; i < 10; ++i)
        {
            m2.insert(std::make_pair(i, "string2"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }
        m1 = m2;
        /*-----------------------------------------------------*/
        /*------------------ ft::map ---------------------*/
        ft_m1 = ft_m2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;

        EQUAL(res == ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 4 : test with one empty vector ----------------------------------------------------------------------*/
    TITLE("= operator (lhs.size = 0)");
    {
        /*-------------------------------------- time limit test -----------------------------------*/
         {
             time_t start, end, diff;
             std::map<int, std::string> m1;
             std::map<int, std::string> m2;
             ft::map<int, std::string> ft_m1;
             ft::map<int, std::string> ft_m2;

             for (int i = 0; i < 100; ++i)
             {
                 m2.insert(std::make_pair(i, "string2"));
                 ft_m2.insert(ft::make_pair(i, "string2"));
             }

             start = get_time();
             m1 = m2;
             end = get_time();
             diff = end - start;
             diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
             /*-----------------------------------------------------*/
             /*------------------ ft::map ---------------------*/
             ualarm(diff * 1e3, 0);
             ft_m1 = ft_m2;
             ualarm(0, 0);
            /*----------------------------------------------------*/
         }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;

        for (int i = 0; i < 10; ++i)
        {
            m2.insert(std::make_pair(i, "string2"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }
        m1 = m2;
        /*-----------------------------------------------------*/
        /*------------------ ft::map ---------------------*/

        ft_m1 = ft_m2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;

        EQUAL(res == ft_res);
    }    
}