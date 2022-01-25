#include "../../stack/stack.hpp"

#include <vector>
#include <stack>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define RESET "\e[0m"
#define MAGENTA "\e[1;95m"
#define CYAN "\e[1;96m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mOK\033[0m\n") : (std::cout << "\033[1;31mKO\033[0m\n"))
#define TIME_FAC 20

#define TITLE(str) \
	std::cout << "\t\t\033[1;37m" << std::setw(30) << std::left << str << "   ===== >\t\t\033[0m";
using namespace std;

#define TEST_CASE(fn)                                                                                        \
    cout << MAGENTA << "\t==========================================================================" << RESET << endl;			 \
    cout << endl;                                                                                            \
    fn();                                                                                                    \
    cout << endl;                                                                                            \
    cout << MAGENTA << "\t==========================================================================\n" << RESET << endl;
using namespace std;

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

void	testConstructors(void)
{
    TITLE("default constructor");
	{
		std::vector<int> myvector (2,200);
		ft::stack<int,std::vector<int> > s(myvector);
		EQUAL(s.size() == 2);
	}
}

void	testMemberMethods(void)
{
    TITLE("empty method");
	{
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		EQUAL(sum == 55);
	}
    TITLE("size method");
	{
		bool cond(false);
		ft::stack<int> myints;
		cond = myints.size() == 0;

		for (int i=0; i<5; i++) myints.push(i);
		cond = cond && (myints.size() == 5);

		myints.pop();
		cond = cond && (myints.size() == 4);
		EQUAL(cond);
	}
    TITLE("top method");
	{
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;
		std::vector<int> vec(10, 50);
		vec.push_back(300);
		ft::stack<int, std::vector<int> > const c_mystack(vec);

		EQUAL(mystack.top() == 15 && c_mystack.top() == 300);
	}
    TITLE("push & pop methods");
	{
		int sum(0);
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		EQUAL(sum == 10);
	}
}

void	testRelationalOperators(void)
{
    TITLE("operator==");
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack ==  mystack1) == (stack == stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack ==  mystack1) == (stack == stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack ==  mystack1) == (stack == stack1);
		}
		EQUAL(cond);
	}
	TITLE("operator!=");
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack !=  mystack1) == (stack != stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack !=  mystack1) == (stack != stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack !=  mystack1) == (stack != stack1);
		}
		EQUAL(cond);
	}
	TITLE("operator<");
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack < mystack1) == (stack < stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack < mystack1) == (stack < stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack < mystack1) == (stack < stack1);
		}
		EQUAL(cond);
	}
    TITLE("operator<=");
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack <= mystack1) == (stack <= stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack <= mystack1) == (stack <= stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack <= mystack1) == (stack <= stack1);
		}
		EQUAL(cond);
	}
	TITLE("operator>");
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack > mystack1) == (stack > stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack > mystack1) == (stack > stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack > mystack1) == (stack > stack1);
		}
		EQUAL(cond);
	}
	TITLE("operator>=");
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack >= mystack1) == (stack >= stack1);
		}
		{
			vec.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack >= mystack1) == (stack >= stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::stack<int, std::vector<int> > mystack1(vec);
			ft::stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack >= mystack1) == (stack >= stack1);
		}
		EQUAL(cond);
	}
}


void alarm_handler(int seg)
{
    (void)seg;
    std::cout << "\033[1;33mTLE\033[0m\n";
    kill(getpid(), SIGINT);
}

int main()
{
    signal(SIGALRM, alarm_handler);

	std::cout << "\n\t\t\t\033[093;1m*.................................*";
	std::cout << "\n\t\t\t*                                 *";
	std::cout << "\n\t\t\t*\t    STACK  TEST           *";
	std::cout << "\n\t\t\t*                                 *";
	std::cout << "\n\t\t\t\033[093;1m*.................................*\033[0m\n\n";

    std::cout << CYAN << "\tTesting Constructors" << RESET << std::endl;
    TEST_CASE(testConstructors);

    std::cout << CYAN << "\tTesting Member Methods" << RESET << std::endl;
    TEST_CASE(testMemberMethods);

    std::cout << CYAN << "\tTesting Relational Operators" << RESET << std::endl;
    TEST_CASE(testRelationalOperators);

	return 0;
}