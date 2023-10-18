#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
}
Base::~Base()
{
}

Base &Base::operator=(const Base &obj)
{
	(void) obj;
	return (*this);
}
Base::Base(const Base &obj)
{
	(void) obj;
}

Base * generate(void)
{
	srand(clock()); 
	int choice = rand() % 3;
	if (choice == 0)
		return (new A);
	else if (choice == 1)
		return (new B);
	else
		return (new C);
}
void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Type is Unknown" << std::endl;
}
void identify(Base& p)
{
	try {
		Base &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type is A" << std::endl;
	} catch (std::exception &e) {
		try
		{
			Base &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Type is B" << std::endl;
		}
		catch (std::exception &e) {
			try
			{
				Base &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Type is C" << std::endl;
			}
			catch (std::exception &e) { std::cout << "Type is Unkown" << std::endl; }
		}
	}
}