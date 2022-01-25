/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_non_member_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:01:46 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 12:00:30 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tests.hpp"

void testNonMemberSwap()
{
    TITLE("non-member swap method");
    {
        int res(0), ft_res(0), key_res(0), ft_key_res(0);
        ft::map<char, int> foo, bar;

        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        swap(foo, bar);

        for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
        {
            res += it->second;
            key_res += it->first;
        }

        for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
        {
            ft_res += it->second;
            ft_key_res += it->first;
        }
        EQUAL((res == 66) && (ft_res = 300) && (key_res == ('a' + 'b' + 'c')) && (ft_key_res == ('x' + 'y')));
    }
}

void testRetionalOperators()
{

    /* ---------------  pretty simple tests --------------- */
    std::map<char, int> foo, bar;
    ft::map<char, int> ft_foo, ft_bar;
    bool res;
    bool ft_res;
    foo['a'] = 100;
    foo['b'] = 200;
    bar['a'] = 10;
    bar['z'] = 1000;

    ft_foo['a'] = 100;
    ft_foo['b'] = 200;
    ft_bar['a'] = 10;
    ft_bar['z'] = 1000;

    std::map<int, std::string> m, m1;
    ft::map<int, std::string> ft_m, ft_m1;
    for (size_t i = 0; i < 10000; ++i)
    {
        m.insert(std::make_pair(i, "value"));
        ft_m.insert(ft::make_pair(i, "value"));
    }
    for (size_t i = 0; i < 10000; ++i)
    {
        m1.insert(std::make_pair(i + 1, "value1"));
        ft_m1.insert(ft::make_pair(i + 1, "value1"));
    }

    TITLE("operator ==");
    /*---------------------------------- time limit test --------------------------------------------*/
    {
        time_t start, end, diff;
        start = get_time();
        res = m == m1;
        end = get_time();
        diff = end - start;
        diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        ualarm(diff * 1e3, 0);
        ft_res = ft_m == ft_m1;
        ualarm(0, 0);
    }

    EQUAL(((foo == bar) == (ft_foo == ft_bar)) && res == ft_res);

    TITLE("operator !=");
    /*---------------------------------- time limit test --------------------------------------------*/
    {
        time_t start, end, diff;

        start = get_time();
        res = m != m1;
        end = get_time();
        diff = end - start;
        diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        ualarm(diff * 1e3, 0);
        ft_res = ft_m != ft_m1;
        ualarm(0, 0);
    }
    EQUAL((foo != bar) == (ft_foo != ft_bar) && res == ft_res);

    TITLE("operator >");
    /*---------------------------------- time limit test --------------------------------------------*/
    {
        time_t start, end, diff;
        start = get_time();
        res = m > m1;
        end = get_time();
        diff = end - start;
        diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        ualarm(diff * 1e3, 0);
        ft_res = ft_m > ft_m1;
        ualarm(0, 0);
    }
    EQUAL(((foo > bar) == (ft_foo > ft_bar)) && (res == ft_res));

    TITLE("operator >=");
    /*---------------------------------- time limit test --------------------------------------------*/
    {
        time_t start, end, diff;

        start = get_time();
        res = m >= m1;
        end = get_time();
        diff = end - start;
        diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        ualarm(diff * 1e3, 0);
        ft_res = ft_m >= ft_m1;
        ualarm(0, 0);
    }
    EQUAL(((foo >= bar) == (ft_foo >= ft_bar)) && (res == ft_res));

    TITLE("operator <");
    /*---------------------------------- time limit test --------------------------------------------*/
    {
        time_t start, end, diff;

        start = get_time();
        res = m < m1;
        end = get_time();
        diff = end - start;
        diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        ualarm(diff * 1e3, 0);
        ft_res = ft_m < ft_m1;
        ualarm(0, 0);
    }
    EQUAL(((foo < bar) == (ft_foo < ft_bar)) && (res == ft_res));

    TITLE("operator <=");
    /*---------------------------------- time limit test --------------------------------------------*/
    {
        time_t start, end, diff;

        start = get_time();
        res = m <= m1;
        end = get_time();
        diff = end - start;
        diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        ualarm(diff * 1e3, 0);
        ft_res = ft_m <= ft_m1;
        ualarm(0, 0);
    }
    EQUAL(((foo <= bar) == (ft_foo <= ft_bar)) && (res == ft_res));
}