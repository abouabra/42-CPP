#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct s_Data
{
	int n1;
	int n2;
	std::string name;
} Data;
typedef unsigned long           uintptr_t;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &obj);
	Serializer &operator=(const Serializer &obj);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif