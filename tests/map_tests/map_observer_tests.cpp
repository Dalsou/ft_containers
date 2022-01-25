/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_observer_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:22:33 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/24 11:24:51 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tests.hpp"

void testObservers()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " key_comp method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond(true);
        std::map<int, int> m;
        ft::map<int, int> ft_m;
        std::map<int, int>::key_compare comp = m.key_comp();
        ft::map<int, int>::key_compare mycomp = ft_m.key_comp();

        for (size_t i = 0; i < 100; i++)
        {
            m.insert(std::make_pair(i, -1));
            ft_m.insert(ft::make_pair(i, -1));
        }

        int highest = m.rbegin()->first;       // key value of last element
        int ft_highest = ft_m.rbegin()->first; // key value of last element

        std::map<int, int>::iterator it = m.begin();
        ft::map<int, int>::iterator ft_it = ft_m.begin();
        do
        {
            if (!(it->first == ft_it->first && it->second == ft_it->second))
            {
                cond = false;
                break;
            }

        } while (comp((*it++).first, highest) && mycomp((*ft_it++).first, ft_highest));
        EQUAL(cond);
    }

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " value_comp method "
              << "] --------------------]\t\t\033[0m";
    {
        int sum(0);
        int s_key(0);
        ft::map<char, int> mymap;

        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;

        ft::pair<char, int> highest = *mymap.rbegin(); // last element

        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            sum += it->second;
            s_key += it->first;
        } while (mymap.value_comp()(*it++, highest));

        EQUAL(sum == 6006 && s_key == 363);
    }
}