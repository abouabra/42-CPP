#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sys/_types/_size_t.h>
#include <utility>
#include <vector>

PmergeMe::PmergeMe(char **av)
{
	int tmp;
	try {
		for (int i = 0; av[i]; i++)
		{
			std::string str(av[i]);
			if(str.empty())
				throw std::exception();
			if(str.find_first_not_of("0123456789") != std::string::npos)
				throw std::exception();
			tmp = atoi(av[i]);
			if(tmp < 0)
				throw std::exception();
			numbers.push_back(tmp);
		}

		// for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		// 	for(std::vector<int>::iterator it2 = it + 1; it2 != numbers.end(); it2++)
		// 		if(*it == *it2)
		// 			throw std::exception();
	}
	catch (std::exception &e) { std::cout << "Error: Invalid input" << std::endl; exit(1);}
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if(this != &other)
		numbers = other.numbers;
	return *this;
}

PmergeMe::PmergeMe()
{
}


void PmergeMe::merge_part(std::vector<int> &v, int vec_size, std::vector<std::vector<int> > &big_v)
{
	std::vector<std::vector<int> > new_big_v;
	// std::vector<int> new_v;
	new_big_v = big_v;
	// new_v = v;
	// big_v.clear();
	rest.clear();
	// new_v.clear();

	int size_of_v = 2 * vec_size;
	if (size_of_v == 0)
		size_of_v = 1;
	
	make_pairs(v, size_of_v, big_v);
	print_vec(big_v, rest, vec_size);
	reorder_v(vec_size, big_v);
	make_new_v(big_v, v);

	if(big_v.size() > 3)
		merge_part(v, size_of_v, new_big_v);
	insertion_part(big_v, rest, vec_size, v);
	big_v = new_big_v;
	// v = new_v;
}

void PmergeMe::make_pairs(std::vector<int> v, int size_of_v, std::vector<std::vector<int> > &big_v)
{
	std::vector<int> small_v;
	for(size_t i = 0; i < v.size(); i += size_of_v)
	{
		if(i + size_of_v > v.size())
		{
			for(size_t j = i; j < v.size(); j++)
				rest.push_back(v[j]);
			break;
		}
		small_v.clear();
		for(size_t j = i; j < i + size_of_v && j < v.size(); j++)
			small_v.push_back(v[j]);
		big_v.push_back(small_v);
	}
}

void PmergeMe::make_new_v(std::vector<std::vector<int> > &big_v, std::vector<int> &new_v)
{
	new_v.clear();
	for(size_t i = 0; i < big_v.size(); i++)
		for (size_t j = 0; j < big_v[i].size(); j++)
			new_v.push_back(big_v[i][j]);
	for(size_t i = 0; i < rest.size(); i++)
		new_v.push_back(rest[i]);
}

void PmergeMe::reorder_v(int vec_size, std::vector<std::vector<int> > &big_v)
{
	if(vec_size == 0)
		vec_size = 1;
	for(size_t i = 0; i + 1 < big_v.size(); i += 2)
	{
		n_compares++;
		if (big_v[i].back() > big_v[i + 1].back())
			std::swap(big_v[i], big_v[i + 1]);
	}
}

void PmergeMe::print_vec(std::vector<std::vector<int> > big_v, std::vector<int> rest, int vec_size)
{
	vec_size *= 2;
	if(vec_size == 0)
		vec_size = 1;
	for (int i = 0; i < vec_size; i++)
		std::cout << "\t";
	std::cout << "vec_size: " << vec_size << std::endl;
	for (int i = 0; i < vec_size; i++)
		std::cout << "\t";
	std::cout << "numbers: ";
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i];
		if(i + 1 != numbers.size())
			std::cout << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < vec_size; i++)
		std::cout << "\t";
	std::cout << "big_v: ";
	for(std::vector<std::vector<int> >::iterator it = big_v.begin(); it != big_v.end(); it++)
	{
		std::cout << "[";
		for(std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			std::cout << *it2;
			if(it2 + 1 != it->end())
				std::cout << " ";
		}
		std::cout << "]";
		if(it + 1 != big_v.end())
			std::cout << " ";
	}

	if(!rest.empty())
	{
		std::cout << " + [";
		for(std::vector<int>::iterator it = rest.begin(); it != rest.end(); it++)
		{
			std::cout << *it;
			if(it + 1 != rest.end())
				std::cout << " ";
		}
		std::cout << "]";
	}
	std::cout << std::endl;
}

void PmergeMe::merge_insertion_sort()
{
	std::cout << "numbers: " << std::endl;
	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::vector<std::vector<int> > big_v;
	merge_part(numbers, 0, big_v);
	std::cout << std::endl << "n_compares: " << n_compares << std::endl;
}

void PmergeMe::print_main_and_pend_chain(std::vector<std::vector<int> > main_chain, std::vector<std::vector<int> > pend_chain, std::vector<int> rest, int vec_size)
{
	for (int i = 0; i < vec_size; i++)
		std::cout << "\t";
	std::cout << "main_chain: ";
	for(std::vector<std::vector<int> >::iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << "[";
		for(std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			std::cout << *it2;
			if(it2 + 1 != it->end())
				std::cout << " ";
		}
		std::cout << "]";
		if(it + 1 != main_chain.end())
			std::cout << " ";
	}

	std::cout << std::endl;
	for (int i = 0; i < vec_size; i++)
		std::cout << "\t";
	std::cout << "pend_chain: ";
	for(std::vector<std::vector<int> >::iterator it = pend_chain.begin(); it != pend_chain.end(); it++)
	{
		std::cout << "[";
		for(std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			std::cout << *it2;
			if(it2 + 1 != it->end())
				std::cout << " ";
		}
		std::cout << "]";
		if(it + 1 != pend_chain.end())
			std::cout << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < vec_size; i++)
		std::cout << "\t";
	std::cout << "rest: ";
	for(std::vector<int>::iterator it = rest.begin(); it != rest.end(); it++)
	{
		std::cout << *it;
		if(it + 1 != rest.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}
void PmergeMe::insertion_part(std::vector<std::vector<int> > big_v, std::vector<int> rest, int vec_size, std::vector<int> &new_v)
{
	(void)vec_size;
	(void)rest;
	(void)big_v;

	print_vec(big_v, rest, vec_size);

	std::vector<std::vector<int> > main_chain;
	std::vector<std::vector<int> > pend_chain;

	for(size_t i = 0; i < 2; i++)
		main_chain.push_back(big_v[i]);

	for(size_t i = 2; i < big_v.size(); i++)
	{
		if(i % 2 == 0)
			pend_chain.push_back(big_v[i]);
		else
			main_chain.push_back(big_v[i]);
	}

	print_main_and_pend_chain(main_chain, pend_chain, rest, vec_size);

	new_v.clear();
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = 0; j < main_chain[i].size(); j++)
			new_v.push_back(main_chain[i][j]);
	}
	for (size_t i = 0; i < pend_chain.size(); i++)
	{
		for (size_t j = 0; j < pend_chain[i].size(); j++)
			new_v.push_back(pend_chain[i][j]);
	}
	for (size_t i = 0; i < rest.size(); i++)
		new_v.push_back(rest[i]);
}