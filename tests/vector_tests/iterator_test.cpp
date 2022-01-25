/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:47:38 by afoulqui          #+#    #+#             */
/*   Updated: 2022/01/25 11:11:53 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"vector_tests.hpp"

void    iterator_tests(void)
{
    /*------------ std::vector ---------*/
    std::vector<int> v(3,4);
    std::vector<int>::iterator it,it1;
    it = v.begin();
    it1 = v.begin() + 1;
    /*----------------------------------*/
    /*------------ ft::vector ---------*/
    ft::vector<int>    my_v(3,4);
    ft::vector<int>::iterator my_it,my_it1, tmp;
    my_it = my_v.begin();
    my_it1 = my_v.begin() + 1;
    /*----------------------------------*/
    TITLE("copy constructor");
    {
        ft::vector<int>::iterator ob(my_it);
        EQUAL(&(*my_it) == &(*ob));
    }
   TITLE("it. to const_iterator");
    {
        ft::vector<int>::const_iterator c_it, c_ob(my_it);
        c_it = my_it;
        EQUAL(&(*my_it) == &(*c_it) && (&(*my_it) == &(*c_ob)));
    }
    TITLE("== operator");
    EQUAL((it == it1) == (my_it == my_it1));
    TITLE("!= operator");
    EQUAL((it != it1) == (my_it != my_it1));
    TITLE("> operator");
    EQUAL((it > it1) == (my_it > my_it1));
    TITLE(">= operator");
    EQUAL((it >= it1) == (my_it >= my_it1));
    TITLE("< operator");
    EQUAL((it < it1) == (my_it < my_it1));
    TITLE("<= operator");
    EQUAL((it <= it1) == (my_it <= my_it1));
    TITLE("* operator");
    EQUAL(((*my_it = 6) == 6) && (*my_it == *(my_v.begin())));
    TITLE("-> operator");
    {
        /*--------------- std::vector-------------------- */
        std::vector<std::string>    v(3, "hello");
        std::vector<std::string>::iterator it = v.begin();
        /*---------------------------------------------- */
        /*--------------- ft::vector-------------------- */
        ft::vector<std::string>    my_v(3, "hello");
        ft::vector<std::string>::iterator my_it = my_v.begin();
        /*---------------------------------------------- */
        EQUAL(it->length() == my_it->length());
    }
    TITLE("- operator");
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    TITLE("+= operator");
	my_it += 1;
	EQUAL(&(*my_it) == &(*my_it1));
    TITLE("-= operator");
	my_it -= 1;
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    TITLE("[] operator");
	EQUAL(((my_it[0] = 5) == 5) && (*my_it == 5));
    TITLE("++it operator");
    ++my_it; // I incremented here to make sure that the object changes
	EQUAL(&(*my_it) == &(*my_it1));
    TITLE("--it operator");
    --my_it; // I decremented here to make sure that the object changes
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    TITLE("+ operator (n + it)");
	EQUAL(&(*(1 + my_it)) == &(*(my_it1)) && (&(*my_it) == &(*(my_v.begin()))));
    TITLE("- operator (it1 - it)");
	EQUAL(((my_it1 - my_it == 1)) && ((my_it - my_it1) == -1));
    TITLE("it++ operator");
    tmp = my_it++;
    EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*my_it1)));
    TITLE("it-- operator");
    tmp = my_it--;
	EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*(my_v.begin()))));
}

void    const_iterator_tests(void)
{
    /*------------ std::vector ---------*/
    std::vector<int> v(3,4);
    std::vector<int>::const_iterator it,it1;
    it = v.begin();
    it1 = v.begin() + 1;
    /*----------------------------------*/
    /*------------ ft::vector ---------*/
    ft::vector<int>    my_v(3,4);
    ft::vector<int>::const_iterator my_it,my_it1, tmp;
    my_it = my_v.begin();
    my_it1 = my_v.begin() + 1;
    /*----------------------------------*/
    TITLE("copy constructor");
    {
        ft::vector<int>::const_iterator ob(my_it);
        EQUAL(&(*my_it) == &(*ob));
    }
    TITLE("== operator");
    EQUAL((it == it1) == (my_it == my_it1));
    TITLE("!= operator");
    EQUAL((it != it1) == (my_it != my_it1));
    TITLE("> operator");
    EQUAL((it > it1) == (my_it > my_it1));
    TITLE(">= operator");
    EQUAL((it >= it1) == (my_it >= my_it1));
    TITLE("< operator");
    EQUAL((it < it1) == (my_it < my_it1));
    TITLE("<= operator");
    EQUAL((it <= it1) == (my_it <= my_it1));
    TITLE("* operator");
    EQUAL(*my_it == *(my_v.begin()) && (&(*my_it) == &(*(my_v.begin()))));
    TITLE("-> operator");
    {
        /*--------------- std::vector-------------------- */
        std::vector<std::string>    v(3, "hello");
        std::vector<std::string>::const_iterator it = v.begin();
        /*---------------------------------------------- */
        /*--------------- ft::vector-------------------- */
        ft::vector<std::string>    my_v(3, "hello");
        ft::vector<std::string>::const_iterator my_it = my_v.begin();
        /*---------------------------------------------- */
        EQUAL(it->length() == my_it->length());
    }
    TITLE("- operator");
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    TITLE("+= operator");
	my_it += 1;
	EQUAL(&(*my_it) == &(*my_it1));
    TITLE("-= operator");
	my_it -= 1;
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    TITLE("[] operator");
	EQUAL((my_it[0] == *(my_v.begin())) && (&(my_it[0]) == &(*(my_v.begin()))));
    TITLE("++it operator");
    ++my_it; 
	EQUAL(&(*my_it) == &(*my_it1));
    TITLE("--it operator");
    --my_it; 
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    TITLE("+ operator (n + it)");
	EQUAL(&(*(1 + my_it)) == &(*(my_it1)) && (&(*my_it) == &(*(my_v.begin()))));
    TITLE("- operator (it1 - it)");
	EQUAL(((my_it1 - my_it == 1)) && ((my_it - my_it1) == -1));
    TITLE("it++ operator");
    tmp = my_it++;
    EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*my_it1)));
    TITLE("it-- operator");
    tmp = my_it--;
	EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*(my_v.begin()))));
}

void    reverse_iterator_tests(void)
{
    /*------------ std::reverse_iterator ---------*/
    std::vector<int> v(3,4);
    std::vector<int>::reverse_iterator rit(v.end()), rit_1(v.end() - 1);
    /*----------------------------------*/
    /*------------ ft::reverse_iterator ---------*/
    ft::vector<int> my_v(3,4);
    ft::vector<int>::reverse_iterator my_rit(my_v.end()), my_rit1(my_v.end() - 1);
    /*----------------------------------*/
    TITLE("copy constructor");
    {
        ft::vector<int>::reverse_iterator ob(my_rit);
        EQUAL(&(*my_rit) == &(*ob));
    }
    TITLE("base function");
    EQUAL((&(*rit) == &(*rit_1.base())) && (&(*my_rit) == &(*my_rit1.base())));
    TITLE("== operator");
    EQUAL((rit == rit_1) == (my_rit == my_rit1));
    TITLE("!= operator");
    EQUAL((rit != rit_1) == (my_rit != my_rit1));
    TITLE("> operator");
    EQUAL((rit > rit_1) == (my_rit > my_rit1));
    TITLE(">= operator");
    EQUAL((rit >= rit_1) == (my_rit >= my_rit1));
    TITLE("< operator");
    EQUAL((rit < rit_1) == (my_rit < my_rit1));
    TITLE("<= operator");
    EQUAL((rit <= rit_1) == (my_rit <= my_rit1));
    TITLE("* operator");
    EQUAL(((*my_rit == *(my_v.end() - 1)) && (&(*my_rit) == &(*(my_v.end() - 1))))
    && ((*rit == *(v.end() - 1)) && (&(*rit) == &(*(v.end() - 1)))));
    TITLE("-> operator");
    {
        std::vector<std::string> v(3, "hello");
        ft::vector<std::string> my_v(3, "hello");
        std::vector<std::string>::reverse_iterator rit(v.end());
        ft::vector<std::string>::reverse_iterator   my_rit(my_v.end());
        EQUAL(rit->length() == my_rit->length());
    }
    TITLE("- operator");
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    TITLE("+ operator");
	EQUAL((&(*(my_rit + 1)) == &(*my_rit1)) && (&(*(rit + 1)) == &(*rit_1)));
    TITLE("+= operator");
	my_rit += 1;
	rit += 1;
	EQUAL((&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1)));
    TITLE("-= operator");
	my_rit -= 1;
	rit -= 1;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    TITLE("[] operator");
	EQUAL((my_rit[0] = 5) == 5);
    TITLE("++rit operator");
    ++my_rit;
    ++rit;
	EQUAL(&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1));
    TITLE("--rit operator");
    --my_rit;
    --rit;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    TITLE("+ operator (n + rit)");
	EQUAL((&(*(2 + my_rit)) == &(*(1 + my_rit1))) && (&(*(2 + rit)) == &(*(1 + rit_1))));
    TITLE("- operator (rit1 - rit)");
    EQUAL(((my_rit - my_rit1) == (rit - rit_1)) && ((my_rit1 - my_rit) == (rit_1 - rit)));
    TITLE("rit++ operator");
    {
        std::vector<int>::reverse_iterator   tmp(rit++);
        ft::vector<int>::reverse_iterator    my_tmp(my_rit++);
        EQUAL((&(*tmp) == &(*(--rit))) && (&(*my_tmp) == &(*(--my_rit))));
    }
    TITLE("rit-- operator");
    {
        std::vector<int>::reverse_iterator   tmp(rit--);
        ft::vector<int>::reverse_iterator    my_tmp(my_rit--);
        EQUAL((&(*tmp) == &(*(++rit))) && (&(*my_tmp) == &(*(++my_rit))));
    }
    TITLE("*rit++ test");
    {
        std::vector<char> v(10);
        ft::vector<char> my_v(10);
        std::string res, my_res;
        std::vector<char>::reverse_iterator start(v.end()), end(v.begin());
        ft::vector<char>::reverse_iterator 	my_start(my_v.end()), my_end(my_v.begin());
        for(size_t i = 0; i < 10; ++i)
            v[i] = '0' + i;
		size_t i = 0;
		for(ft::vector<char>::iterator it = my_v.begin(); it != my_v.end(); ++it)
			*it = '0' + i++;
        while (start != end)
            res.push_back(*start++);
        while (my_start != my_end)
            my_res.push_back(*my_start++);
        EQUAL(res == my_res);
    }
}