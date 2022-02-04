#include <vector>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <list>
#include <stack>
#include <map>

#include "stack/stack.hpp"
#include "vector/vector.hpp"
#include "map/map.hpp"

#ifndef NS
# define NS ft
#endif

// **************** STACK TEST **************** //

void	stack_tests() {

	std::cout << "\n\t\t*.................................*";
	std::cout << "\n\t\t*                                 *";
	std::cout << "\n\t\t*           STACK  TEST           *";
	std::cout << "\n\t\t*                                 *";
	std::cout << "\n\t\t*.................................*\n\n";

	std::cout << "STACK : Default Constructor & Empty & Size Methods \n";
	std::cout << "=====================================================\n";

	NS::stack<int> stack;
	NS::stack<int> copy_stack;

	std::cout << "* Before Push *\n";
	std::cout << "SIZE\t: " << stack.size() << std::endl;
	std::cout << "EMPTY\t: " << stack.empty() << std::endl;

	for (int i = 42; i < 50; i++)
		stack.push(i);
	for (int i = 23; i < 37; i++)
		stack.push(i);

	std::cout << "\n* After Push *\n";
	std::cout << "SIZE\t: " << stack.size() << std::endl;
	std::cout << "EMPTY\t: " <<stack.empty() << std::endl;

	std::cout << "\nSTACK : Copy Constrcutor\n";
	std::cout << "=====================================================\n";

	copy_stack = stack;
	std::cout << "SIZE\t| Src: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Src: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t\t| Src: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	std::cout << "\nSTACK : Pop Method\n";
	std::cout << "=====================================================\n";

	stack.pop();

	std::cout << "SIZE\t| Src: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Src: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t\t| Src: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	std::cout << "\nSTACK : Compare Functions\n";
	std::cout << "=====================================================\n";

	std::cout << "Stack1 == Stack2:\t" << (stack == copy_stack) << std::endl;
	std::cout << "Stack1 != Stack2:\t" << (stack != copy_stack) << std::endl;
	std::cout << "Stack1 < Stack2:\t" << (stack < copy_stack) << std::endl;
	std::cout << "Stack1 <= Stack2:\t" << (stack <= copy_stack) << std::endl;
	std::cout << "Stack1 > Stack2:\t" << (stack > copy_stack) << std::endl;
	std::cout << "Stack1 >= Stack2:\t" << (stack >= copy_stack) << std::endl;

	std::cout << "\nSTACK : Swap Method\n";
	std::cout << "=====================================================\n";
	std::cout << "* Before Swap *\n";
	std::cout << "SIZE\t| Src: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Src: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t\t| Src: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
	std::cout << "SIZE\t| Src: " << copy_stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Src: " << copy_stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t\t| Src: " << copy_stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	swap(stack, copy_stack);

	std::cout << "\n* After Swap *\n";
	std::cout << "SIZE\t| Src: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Src: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t\t| Src: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
	std::cout << "SIZE\t| Src: " << copy_stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Src: " << copy_stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t\t| Src: " << copy_stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
}

// **************** END STACK TEST **************** //


// **************** VECTOR TEST ******************* //

void	print_content(NS::vector<int> &v) {
	NS::vector<int>::iterator	it = v.begin();
	NS::vector<int>::iterator	ite = v.end();

	NS::vector<int>::const_iterator	cit = v.begin();
	NS::vector<int>::const_iterator	cite = v.end();
	
	NS::vector<int>::reverse_iterator	rev = v.rbegin();
	NS::vector<int>::reverse_iterator	reve = v.rend();

	std::cout << "Vector Iterator Content :\n";
	for (; it != ite; ++it)
		std::cout << "\t\t" << *it << '\n';
	std::cout << "\n";

	std::cout << "Vector Const Iterator Content :\n";
	for (; cit != cite; ++cit)
		std::cout << "\t\t" << *cit << '\n';
	std::cout << "\n";

	std::cout << "Vector Reverse Iterator Content :\n";
	for (; rev != reve; ++rev)
		std::cout << "\t\t" << *rev << '\n';
	std::cout << "\n";
}

void	print_size(NS::vector<int> &v) {
	std::cout << "EMPTY\t\t:\t" << v.empty() << std::endl;
	std::cout << "SIZE\t\t:\t" << v.size() << std::endl;
	std::cout << "MAX_SIZE\t:\t" << v.max_size() << std::endl;
}

void	print_capacity(NS::vector<int> &v) {
	std::cout << "CAPACITY\t:\t" << v.capacity() << std::endl;
}

void	vector_tests() {
	std::cout << "\n\t\t*.................................*";
	std::cout << "\n\t\t*                                 *";
	std::cout << "\n\t\t*           VECTOR TEST           *";
	std::cout << "\n\t\t*                                 *";
	std::cout << "\n\t\t*.................................*\n\n";

	NS::vector<int>	v;
	NS::vector<int>	v1;
	NS::vector<int>	v_fill(23, 42);
	NS::vector<int>	v_range(v_fill.begin() + 6, v_fill.end() - 14);
	NS::vector<int>	v_copy(v_range);
	NS::vector<int>	const v_const(19, 2);

	std::cout << "\nVECTOR : Empty Vector\n";
	std::cout << "=====================================================\n";
	print_content(v); print_size(v); print_capacity(v);

	std::cout << "\nVECTOR : Fill Vector\n";
	std::cout << "=====================================================\n";
	print_content(v_fill); print_size(v_fill); print_capacity(v_fill);
	std::cout << "FRONT\t\t:\t" << v_fill.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v_fill.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v_fill.at(2) << std::endl;

	std::cout << "\nVECTOR : Range Vector\n";
	std::cout << "=====================================================\n";
	print_content(v_range); print_size(v_range); print_capacity(v_range);
	std::cout << "FRONT\t\t:\t" << v_range.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v_range.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v_range.at(2) << std::endl;

	std::cout << "\nVECTOR : Copy Vector\n";
	std::cout << "=====================================================\n";
	print_content(v_copy); print_size(v_copy); print_capacity(v_copy);
	std::cout << "FRONT\t\t:\t" << v_copy.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v_copy.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v_copy.at(2) << std::endl;

	std::cout << "\nVECTOR : Const Vector\n";
	std::cout << "=====================================================\n";
	std::cout << "FRONT\t\t:\t" << v_const.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v_const.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v_const.at(2) << std::endl;

	std::cout << "\nVECTOR : Assign (one element) Method\n";
	std::cout << "=====================================================\n";
	v.assign(5, 54);
	v.push_back(6);
	print_content(v); print_size(v); print_capacity(v);
	std::cout << "FRONT\t\t:\t" << v.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v.at(2) << std::endl;

	std::cout << "\nVECTOR : Assign (range) Method\n";
	std::cout << "=====================================================\n";
	v1.assign(v_fill.begin() + 1, v_fill.begin() + 3);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t:\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v1.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v1.at(1) << std::endl;

	std::cout << "\nVECTOR : Clear Method\n";
	std::cout << "=====================================================\n";
	v1.clear();
	print_content(v1); print_size(v1); print_capacity(v1);

	std::cout << "\nVECTOR : Insert Method\n";
	std::cout << "=====================================================\n";
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin(), 4);
	v1.insert(v1.begin(), 7);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t:\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v1.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v1.at(1) << std::endl;

	std::cout << "\nVECTOR : Erase Method\n";
	std::cout << "=====================================================\n";
	v1.erase(v1.begin(), v1.begin() + 1);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t:\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v1.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v1.at(1) << std::endl;

	std::cout << "\nVECTOR : Operators\n";
	std::cout << "=====================================================\n";
	std::cout << "* v1 becomes a copy of v_fill\n";

	v1 = v_fill;

	std::cout << "v1 = v2:\t" << (v1 == v_fill) << std::endl;
	std::cout << "v1 != v2:\t" << (v1 != v_fill) << std::endl;

	std::cout << "\n* Pop last elem of v1\n";
	v1.pop_back();

	std::cout << "v1 < v2:\t" << (v1 < v_fill) << std::endl;
	std::cout << "v1 > v2:\t" << (v1 > v_fill) << std::endl;

	std::cout << "\n* Check operator[] | v1[2] = 10\n";
	std::cout << "v1[2] = " << v1[2] << std::endl;

	std::cout << "\nVECTOR : Reserve Method\n";
	std::cout << "=====================================================\n";
	v1.reserve(18);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t:\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v1.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v1.at(1) << std::endl;

	std::cout << "\nVECTOR : Resize Method\n";
	std::cout << "=====================================================\n";
	v1.resize(2);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t:\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t:\t" << v1.back() << std::endl;
	std::cout << "AT\t\t\t:\t" << v1.at(1) << std::endl;

	v_range.push_back(18);
	v_range.push_back(7);
	v_range.push_back(2);
	v_range.push_back(1);
	v_range.push_back(98);

	std::cout << "\nVECTOR : Swap Method\n";
	std::cout << "=====================================================\n";
	std::cout << "* Before swap:\n";
	std::cout << "v1 is :\n";
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "\nv_range is :\n";
	print_content(v_range); print_size(v_range); print_capacity(v_range);

	v1.swap(v_range);

	std::cout << "\n* After swap:\n";
	std::cout << "v1 is :\n";
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "\nv_range is :\n";
	print_content(v_range); print_size(v_range); print_capacity(v_range);
}

// **************** END VECTOR TEST **************** //

// **************** MAP TEST *********************** //

void	print_content(NS::map<int, int> &m)
{
	NS::map<int, int>::iterator	it = m.begin();
	NS::map<int, int>::iterator	ite = m.end();

	NS::map<int, int>::const_iterator	cit = m.begin();
	NS::map<int, int>::const_iterator	cite = m.end();

	NS::map<int, int>::reverse_iterator	rev = m.rbegin();
	NS::map<int, int>::reverse_iterator	reve = m.rend();


	std::cout << "Map Iterator Content :\n";
	for (; it != ite; ++it)
		std::cout << "\tKey: " << it->first << "\t\t\tVal: " << it->second << '\n';
	std::cout << "\n";

	std::cout << "Map Const Iterator Content :\n";
	for (; cit != cite; ++cit)
		std::cout << "\tKey: " << cit->first << "\t\t\tVal: " << cit->second << '\n';
	std::cout << "\n";

	std::cout << "Map Reverse Iterator Content :\n";
	for (; rev != reve; ++rev)
		std::cout << "\tKey: " << rev->first << "\t\t\tVal: " << rev->second << '\n';
	std::cout << "\n";
}

void	print_size(NS::map<int, int> &v)
{
	std::cout << "EMPTY\t\t:\t" << v.empty() << std::endl;
	std::cout << "SIZE\t\t:\t" << v.size() << std::endl;
	std::cout << "MAX_SIZE\t:\t" << v.max_size() << std::endl;
}

void	map_tests()
{
	std::cout << "\n\t\t*.................................*";
	std::cout << "\n\t\t*                                 *";
	std::cout << "\n\t\t*            MAP  TEST            *";
	std::cout << "\n\t\t*                                 *";
	std::cout << "\n\t\t*.................................*\n\n";

	NS::map<int, int>			m;
	NS::map<int, int>			m1;
	NS::map<int, int> const 	m2;

	NS::pair <int,int>			p00;
  	NS::pair <int,int>			p01;
	NS::pair <int,int>			p02;
  	NS::pair <int,int>			p03;
	NS::pair <int,int>			p04;
  	NS::pair <int,int>			p05;
	NS::pair <int,int>			p06;
  	NS::pair <int,int>			p07;
	NS::pair <int,int>			p08;
  	NS::pair <int,int>			p09;
	NS::pair <int,int>			p10;
  	NS::pair <int,int>			p11;
  	NS::pair <int,int>			p12;

	p00 = NS::make_pair(12554, 54);
  	p01 = NS::make_pair(30, 78);
	p02 = NS::make_pair(2, 198);
  	p03 = NS::make_pair(8, 78);
	p04 = NS::make_pair(12, 18);
  	p05 = NS::make_pair(95, 5);
  	p06 = NS::make_pair(38, 2);
  	p07 = NS::make_pair(0, 453);
  	p08 = NS::make_pair(1, 2);
  	p09 = NS::make_pair(99, 7845);
  	p10 = NS::make_pair(89732, 1);
  	p11 = NS::make_pair(-1982, 2);
	p12 = NS::make_pair(42,23);

	m1.insert(p00);
	m1.insert(p01);
	m1.insert(p02);
	m1.insert(p03);
	m1.insert(p04);
	m1.insert(p05);
	m1.insert(p06);
	m1.insert(p07);
	m1.insert(p08);
	m1.insert(p09);
	m1.insert(p10);
	m1.insert(p11);
	m1.insert(p12);

	std::cout << "\nMAP : Empty Map\n";
	std::cout << "=====================================================\n";
	print_content(m); 
	print_size(m);

	std::cout << "\nMAP : Insert (one element) Method\n";
	std::cout << "=====================================================\n";
	print_content(m1); print_size(m1);

	std::cout << "\nMAP : Range Map\n";
	std::cout << "=====================================================\n";
	NS::map<int, int>	m_range(++m1.begin(), --m1.end());
	print_content(m_range); print_size(m_range);

	std::cout << "\nMAP : Copy Map\n";
	std::cout << "=====================================================\n";
	NS::map<int, int>	m_copy(m_range);
	print_content(m_copy); print_size(m_copy);

  	NS::pair <int,int>			elem;
	elem = NS::make_pair(-23, 1234567);

	std::cout << "\nMAP : Insert Method (pos, val)\n";
	std::cout << "=====================================================\n";
	m_copy.insert(++(++(m_copy.begin())), elem);
	print_content(m_copy); print_size(m_copy);

	std::cout << "\nMAP : Insert Method (range)\n";
	std::cout << "=====================================================\n";
	m.insert(m_copy.begin(), --(--(m_copy.end())));
	print_content(m); print_size(m);

	std::cout << "\nMAP : Erase Method (pos)\n";
	std::cout << "=====================================================\n";
	std::cout << "* Before Erase *\n";
	print_content(m_copy); print_size(m_copy);

	m_copy.erase(++m_copy.begin());

	std::cout << "\n* After Erase: *\n";
	print_content(m_copy); print_size(m_copy);

	std::cout << "\nMAP : Erase Method (key)\n";
	std::cout << "=====================================================\n";
	std::cout << "* Before Erase *\n";
	print_content(m_copy); print_size(m_copy);

	m_copy.erase(12);
	
	std::cout << "\n* After Erase *\n";
	print_content(m_copy); print_size(m_copy);

	std::cout << "\nMAP : Erase Method(begin, end)\n";
	std::cout << "=====================================================\n";
	std::cout << "* Before Erase *\n";
	print_content(m_copy); print_size(m_copy);

	m_copy.erase(m_copy.begin(), --m_copy.end());
	
	std::cout << "\n* After Erase *\n";
	print_content(m_copy); print_size(m_copy);

	std::cout << "\nMAP : Swap Method\n";
	std::cout << "=====================================================\n";
	std::cout << "* Before swap *\n";
	print_content(m_copy); print_size(m_copy);
	print_content(m); print_size(m);

	m_copy.swap(m);

	std::cout << "\n* After swap *\n";
	print_content(m_copy); print_size(m_copy);
	print_content(m); print_size(m);

	std::cout << "\nMAP : Find Method\n";
	std::cout << "=====================================================\n";
	std::cout << "Res: " << m_copy.find(38)->first << std::endl;

	std::cout << "\nMAP : Count Method\n";
	std::cout << "=====================================================\n";
	std::cout << "Res: " << m_copy.count(38) << std::endl;

	std::cout << "\nMAP : Clear Method\n";
	std::cout << "=====================================================\n";
	m_copy.clear();
	print_content(m_copy); print_size(m_copy);
}

// **************** END MAP TEST ****************** //

int main(void)
{
	stack_tests();
	vector_tests();
	map_tests();

    return 0;
}