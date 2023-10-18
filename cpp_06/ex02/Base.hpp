#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
protected:
	Base();
	Base(const Base &obj);
	Base &operator=(const Base &obj);
public:
	virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif