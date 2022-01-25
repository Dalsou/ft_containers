/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operation_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:53:46 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/24 11:58:16 by afoulqui         ###   ########.fr       */
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

void testOperations()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " find method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond(true);
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1000; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }

            start = get_time();

            for (size_t i = 10; i < 1000; i++)
                m1.find(i);

            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            for (size_t i = 1e1; i < 100; i += 10)
                ft_m1.find(i);
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        std::vector<int> vec;
        std::vector<int> ft_vec;
        std::random_device randDev;
        std::mt19937 generator(randDev());
        std::uniform_int_distribution<int> distr(0, 1e8);

        std::map<int, std::string> m1;
        ft::map<int, std::string> ft_m1;
        std::map<int, std::string>::iterator it;
        ft::map<int, std::string>::iterator ft_it;

        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string2"));
        }

        for (size_t i = 0; i < 1000; i++)
        {
            int n = distr(generator);
            it = m1.find(n);
            ft_it = ft_m1.find(n);
            if (it == m1.end() && ft_it == ft_m1.end())
                continue;
            if (it == m1.end() && ft_it != ft_m1.end())
            {
                cond = false;
                break;
            }
            else
            {
                vec.push_back(it->first);
                ft_vec.push_back(ft_it->first);
            }
        }

        std::map<char, int> m;
        ft::map<char, int> ft_m;
        std::map<char, int>::iterator it2;
        ft::map<char, int>::iterator ft_it2;

        m['a'] = 50;
        m['b'] = 100;
        m['c'] = 150;
        m['d'] = 200;

        ft_m['a'] = 50;
        ft_m['b'] = 100;
        ft_m['c'] = 150;
        ft_m['d'] = 200;

        it2 = m.find('a');
        ft_it2 = ft_m.find('a');

        cond = cond && it2->first == ft_it2->first && it2->second == ft_it2->second;

        if (it2 != m.end())
            m.erase(it2);
        if (ft_it2 != ft_m.end())
            ft_m.erase(ft_it2);

        cond = cond && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        EQUAL(cond && vec == ft_vec);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " count method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond = false;
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            bool res, ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1000; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            res = m.count(1000 - 10);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft_res = ft_m.count(1000 - 10);
            ualarm(0, 0);
            cond = ft_res == res;
        }
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
        cond = (cond && (m.count(65) == ft_m.count(65) && m.count(300) == ft_m.count(300)));
        EQUAL(cond);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " lower_bound method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            int res, ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1000; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            res = m.lower_bound(100)->first;
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft_res = ft_m.lower_bound(100)->first;
            ualarm(0, 0);
            cond = ft_res == res;
        }
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
        std::map<int, std::string> const c_m(m.begin(), m.end());
        ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
        cond = (cond && (m.lower_bound(15)->first == ft_m.lower_bound(15)->first));
        cond = (cond && (m.lower_bound(65)->first == ft_m.lower_bound(65)->first));
        cond = (cond && (m.lower_bound(63)->first == ft_m.lower_bound(63)->first));
        cond = (cond && (m.lower_bound(120)->first == ft_m.lower_bound(120)->first));
        cond = (cond && (m.lower_bound(70)->first == ft_m.lower_bound(70)->first));

        cond = (cond && (c_m.lower_bound(15)->first == c_ft_m.lower_bound(15)->first));
        cond = (cond && (c_m.lower_bound(65)->first == c_ft_m.lower_bound(65)->first));
        cond = (cond && (c_m.lower_bound(63)->first == c_ft_m.lower_bound(63)->first));
        cond = (cond && (c_m.lower_bound(120)->first == c_ft_m.lower_bound(120)->first));
        cond = (cond && (c_m.lower_bound(70)->first == c_ft_m.lower_bound(70)->first));
        EQUAL(cond);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " upper_bound method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            int res, ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1000; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            res = m.upper_bound(100)->first;
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft_res = ft_m.upper_bound(100)->first;
            ualarm(0, 0);
            cond = ft_res == res;
        }
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
        std::map<int, std::string> const c_m(m.begin(), m.end());
        ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
        cond = (cond && (m.upper_bound(15)->first == ft_m.upper_bound(15)->first));
        cond = (cond && (m.upper_bound(65)->first == ft_m.upper_bound(65)->first));
        cond = (cond && (m.upper_bound(63)->first == ft_m.upper_bound(63)->first));
        cond = (cond && (m.upper_bound(120)->first == ft_m.upper_bound(120)->first));
        cond = (cond && (m.upper_bound(70)->first == ft_m.upper_bound(70)->first));
        cond = (cond && (m.upper_bound(150)->first == ft_m.upper_bound(150)->first));

        cond = (cond && (c_m.upper_bound(15)->first == c_ft_m.upper_bound(15)->first));
        cond = (cond && (c_m.upper_bound(65)->first == c_ft_m.upper_bound(65)->first));
        cond = (cond && (c_m.upper_bound(63)->first == c_ft_m.upper_bound(63)->first));
        cond = (cond && (c_m.upper_bound(120)->first == c_ft_m.upper_bound(120)->first));
        cond = (cond && (c_m.upper_bound(70)->first == c_ft_m.upper_bound(70)->first));
        cond = (cond && (c_m.upper_bound(150)->first == c_ft_m.upper_bound(150)->first));
        EQUAL(cond);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " equal_range method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            iter_def res;
            ft_iter_def ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1000; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            res = m.equal_range(100);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 10, 0);
            ft_res = ft_m.equal_range(100);
            ualarm(0, 0);
            cond = (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first);
        }
        iter_def res;
        ft_iter_def ft_res;
        const_iter_def c_res;
        ft_const_iter_def ft_c_res;
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
        std::map<int, std::string> const c_m(m.begin(), m.end());
        ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());

        res = m.equal_range(15);
        ft_res = ft_m.equal_range(15);
        cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
        res = m.equal_range(65);
        ft_res = ft_m.equal_range(65);
        cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
        res = m.equal_range(63);
        ft_res = ft_m.equal_range(63);
        cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
        res = m.equal_range(120);
        ft_res = ft_m.equal_range(120);
        cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
        res = m.equal_range(70);
        ft_res = ft_m.equal_range(70);
        cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
        res = m.equal_range(150);
        ft_res = ft_m.equal_range(150);
        cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));

        c_res = c_m.equal_range(15);
        ft_c_res = c_ft_m.equal_range(15);
        cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
        c_res = c_m.equal_range(65);
        ft_c_res = c_ft_m.equal_range(65);
        cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
        c_res = c_m.equal_range(63);
        ft_c_res = c_ft_m.equal_range(63);
        cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
        c_res = c_m.equal_range(120);
        ft_c_res = c_ft_m.equal_range(120);
        cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
        c_res = c_m.equal_range(70);
        ft_c_res = c_ft_m.equal_range(70);
        cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
        c_res = c_m.equal_range(150);
        ft_c_res = c_ft_m.equal_range(150);
        cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
        EQUAL(cond);
    }
}