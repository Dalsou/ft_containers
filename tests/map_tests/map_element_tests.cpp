/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:31:04 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/24 12:11:08 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tests.hpp"

void testElementAccess()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator [] "
              << "] --------------------]\t\t\033[0m";
    {
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;

            for (size_t i = 0; i < 10000; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }
            start = get_time();
            m1[9999] = "string";
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[9999] = "string";
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            start = get_time();
            m1[9999 - 100] = "string";
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[9999 - 100] = "string";
            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            start = get_time();
            m1[999 - 100] = m1[999];
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1[9999 - 100] = ft_m1[999];
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        std::map<char, std::string> m;
        ft::map<char, std::string> ft_m;

        m['a'] = "an element";
        m['b'] = "another element";
        m['c'] = m['b'];
        m['a'] = "test";

        ft_m['a'] = "an element";
        ft_m['b'] = "another element";
        ft_m['c'] = ft_m['b'];
        ft_m['a'] = "test";

        EQUAL(m['a'] == ft_m['a'] && m['b'] == ft_m['b'] && m['c'] == ft_m['c'] && m.size() == ft_m.size());
    }
}