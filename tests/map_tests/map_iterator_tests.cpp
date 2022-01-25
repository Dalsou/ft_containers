/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:20:23 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/24 12:17:23 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tests.hpp"

void iterator_tests(void)
{
    /*------------ std::map ---------*/
    std::map<int, char> m;
    std::map<int, char>::iterator it, it1;

    ft::map<int, char> my_m;
    ft::map<int, char>::iterator my_it, my_it1, tmp;

    for (int i = 0; i < 10; ++i)
    {
        my_m.insert(ft::make_pair(i, static_cast<char>(i + 97)));
        m.insert(std::make_pair(i, static_cast<char>(i + 97)));
    }

    it = m.begin();
    it1 = ++(m.begin());
    my_it = my_m.begin();
    my_it1 = ++(my_m.begin());
    /*----------------------------------*/
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
              << "] --------------------]\t\t\033[0m";
    {
        ft::map<int, char>::iterator ob(my_it);
        EQUAL(&(*my_it) == &(*ob));
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " iterator to const_iterator "
              << "] --------------------]\t\t\033[0m";
    {
        ft::map<int, char>::const_iterator c_it, c_ob(my_it);
        c_it = my_it;
        EQUAL(&(*my_it) == &(*c_it) && (&(*my_it) == &(*c_ob)));
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it == it1) == (my_it == my_it1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it != it1) == (my_it != my_it1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((((*my_it).second = '6') == '6') && ((*my_it).first == ((*my_m.begin()).first)));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*--------------- std::map-------------------- */
        std::map<int, std::string> m;
        ft::map<int, std::string> my_m;

        for (int i = 0; i < 5; ++i)
        {
            m.insert(std::make_pair(i, "HELLO"));
            my_m.insert(ft::make_pair(i, "HELLO"));
        }

        ft::map<int, std::string>::iterator my_it = my_m.begin();
        std::map<int, std::string>::iterator it = m.begin();
        /*---------------------------------------------- */
        EQUAL(it->second.length() == my_it->second.length());
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        // {
        //     time_t start, end, diff;

        //     std::map<int, std::string> m;
        //     ft::map<int, std::string> ft_m;
        //     for (size_t i = 0; i < 10000; ++i)
        //     {
        //         m.insert(std::make_pair(i, "value"));
        //         ft_m.insert(ft::make_pair(i, "value"));
        //     }
        //     start = get_time();
        //     for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
        //         ;
        //     end = get_time();
        //     diff = end - start;
        //     diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

        //     ualarm(diff * 1e3, 0);
        //     for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
        //         ;
        //     ualarm(0, 0);
        // }
        bool cond(false);
        {
            int res(0);
            int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
                res += it->first;
            cond = res == 210;
        }
        {
            int res(0), tmp;
            int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            ft::map<int, int>::iterator it = m.begin(), eit = --m.end();
            tmp = eit->first;
            m.erase(eit);
            for (; it != m.end(); ++it)
                res += it->first;
            cond = cond && (res == (210 - tmp));
        }
        ++my_it; // I incremented here to make sure that the object changes
        EQUAL(*my_it == *my_it1);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 10000; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            std::map<int, std::string>::iterator it = --m.end();
            for (; it != m.begin(); --it)
                ;
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft::map<int, std::string>::iterator ft_it = --ft_m.end();
            for (; ft_it != ft_m.begin(); --ft_it)
                ;
            ualarm(0, 0);
        }
        int res(0);
        {
            int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            ft::map<int, int>::iterator it = --m.end();
            for (;; --it)
            {
                if (it == m.begin())
                {
                    res += it->first;
                    break;
                }
                res += it->first;
            }
        }
        --my_it; // I decremented here to make sure that the object changes
        EQUAL(*my_it != *my_it1);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it++;
    EQUAL(*my_it != *tmp && *my_it == *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it--;
    EQUAL(*my_it != *tmp && *my_it == *(my_m.begin()));
}

void const_iterator_tests(void)
{
    /*------------ std::map ---------*/
    std::map<int, char> m;
    std::map<int, char>::const_iterator it, it1;

    ft::map<int, char> my_m;
    ft::map<int, char>::const_iterator my_it, my_it1, tmp;

    for (int i = 0; i < 5; ++i)
    {
        my_m.insert(ft::make_pair(i, static_cast<char>(i + 97)));
        m.insert(std::make_pair(i, static_cast<char>(i + 97)));
    }

    it = m.begin();
    it1 = ++(m.begin());
    my_it = my_m.begin();
    my_it1 = ++(my_m.begin());
    /*----------------------------------*/

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
              << "] --------------------]\t\t\033[0m";
    {
        ft::map<int, char>::const_iterator ob(my_it);
        EQUAL(*my_it == *ob);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it == it1) == (my_it == my_it1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((it != it1) == (my_it != my_it1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*--------------- std::map-------------------- */
        std::map<int, std::string> m;
        ft::map<int, std::string> my_m;

        for (int i = 0; i < 5; ++i)
        {
            m.insert(std::make_pair(13, "HELLO"));
            my_m.insert(ft::make_pair(13, "HELLO"));
        }

        ft::map<int, std::string>::iterator my_it = my_m.begin();
        std::map<int, std::string>::iterator it = m.begin();
        /*---------------------------------------------- */
        EQUAL(it->second.length() == my_it->second.length());
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator "
              << "] --------------------]\t\t\033[0m";
    ++my_it; // I incremented here to make sure that the object changes
    EQUAL(*my_it == *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator "
              << "] --------------------]\t\t\033[0m";
    --my_it; // I decremented here to make sure that the object changes
    EQUAL(*my_it != *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it++;
    EQUAL(*my_it != *tmp && *my_it == *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it--;
    EQUAL(*my_it != *tmp && *my_it == *(my_m.begin()));
}

void reverse_iterator_tests(void)
{
    /*------------ std::reverse_iterator ---------*/
    std::map<int, char> m;
    for (int i = 0; i < 1e2; i++)
        m.insert(std::make_pair(i, 'A'));

    std::reverse_iterator<std::map<int, char>::iterator> rit(m.end()), rit_1(--m.end());

    ft::reverse_iterator<std::map<int, char>::iterator> my_rit(m.end()), my_rit1(--m.end());
    /*----------------------------------*/
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
              << "] --------------------]\t\t\033[0m";
    {
        ft::reverse_iterator<std::map<int, char>::iterator> ob(my_rit);
        EQUAL(*my_rit == *ob);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " riterator to const_riterator "
              << "] --------------------]\t\t\033[0m";
    {
        ft::map<int, char> my_m;
        for (int i = 0; i < 1e2; i++)
            my_m.insert(ft::make_pair(i, 'A'));

        ft::map<int, char>::reverse_iterator my_rit2(my_m.end());
        ft::map<int, char>::const_reverse_iterator c_it, c_ob(my_m.end());
        c_it = my_rit2;
        EQUAL(my_rit2->first == c_it->first && my_rit2->first == c_ob->first);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " base function "
              << "] --------------------]\t\t\033[0m";
    EQUAL((rit->first == (rit_1.base()->first)) && (my_rit->first == my_rit1.base()->first));
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator "
    //           << "] --------------------]\t\t\033[0m";
    // EQUAL((rit == rit_1) == (my_rit == my_rit1));
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator "
    //           << "] --------------------]\t\t\033[0m";
    // EQUAL((rit != rit_1) == (my_rit != my_rit1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL(((my_rit->first == (--m.end())->first) && ((my_rit->first) == ((--m.end())->first))) && ((rit->first == (--m.end())->first) && ((rit->first) == ((--m.end())->first))));

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator "
              << "] --------------------]\t\t\033[0m";
    EQUAL((((*my_rit).first == (*(--m.end())).first) && (((*my_rit).first) == ((*(--m.end())).first))) && (((*rit).first == (*(--m.end())).first) && ((*(rit)).first) == ((*(--m.end())).first)));

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++rit operator "
              << "] --------------------]\t\t\033[0m";
    ++my_rit; // I incremented here to make sure that the object changes
    ++rit;
    EQUAL(&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --rit operator "
              << "] --------------------]\t\t\033[0m";
    --my_rit; // I incremented here to make sure that the object changes
    --rit;
    EQUAL((my_rit->first == (--my_rit1)->first) && (rit->first == (--rit_1)->first));
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit++ operator "
              << "] --------------------]\t\t\033[0m";
    {
        std::reverse_iterator<std::map<int, char>::iterator> tmp(rit++);
        ft::reverse_iterator<std::map<int, char>::iterator> my_tmp(my_rit++);
        EQUAL(tmp->first == (--rit)->first && my_tmp->first == (--my_rit)->first);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit-- operator "
              << "] --------------------]\t\t\033[0m";
    {
        rit++;
        my_rit++;
        std::reverse_iterator<std::map<int, char>::iterator> tmp(rit--);
        ft::reverse_iterator<std::map<int, char>::iterator> my_tmp(my_rit--);
        EQUAL(tmp->first == (++rit)->first && my_tmp->first == (++my_rit)->first);
    }
}