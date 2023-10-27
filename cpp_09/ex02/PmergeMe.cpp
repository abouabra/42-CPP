#include "PmergeMe.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
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
	{
		numbers = other.numbers;
	}
	return *this;
}

PmergeMe::PmergeMe()
{
}

void PmergeMe::run()
{
	std::cout << "numbers: " << std::endl;
	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;



	if(numbers.size() % 2 != 0)
	{
		Struggler.push_back(numbers.back());
		numbers.pop_back();
	}

	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it += 2)
	{
		if(*it > *(it + 1))
		{
			std::pair<int, int> pair(*(it + 1), *it);
			vecPair.push_back(pair);
		}
		else
		{
			std::pair<int, int> pair(*it, *(it + 1));
			vecPair.push_back(pair);
		}
	}

	std::cout << "Struggler: " << std::endl;
	for(std::vector<int>::iterator it = Struggler.begin(); it != Struggler.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "Step 2: " << std::endl;
	for(std::vector<std::pair<int, int> >::iterator it = vecPair.begin(); it != vecPair.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;
	



	for(std::vector<std::pair<int, int> >::iterator it = vecPair.begin(); it != vecPair.end(); it++)
	{
		for(std::vector<std::pair<int, int> >::iterator it2 = vecPair.begin(); it2 != vecPair.end(); it2++)
		{
			if(it->second < it2->second)
			{
				std::pair<int, int> tmp = *it;
				*it = *it2;
				*it2 = tmp;
			}
		}
	}
	std::cout << "Step 3: " << std::endl;
	for(std::vector<std::pair<int, int> >::iterator it = vecPair.begin(); it != vecPair.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	
	for(std::vector<std::pair<int, int> >::iterator it = vecPair.begin(); it != vecPair.end(); it++)
	{
		mainChain.push_back(it->second);
		PendChain.push_back(it->first);
	}

	// since b1 < a1
	mainChain.insert(mainChain.begin(), *PendChain.begin());
	PendChain.erase(PendChain.begin());
	
	std::cout << std::endl << "Step 4: " << std::endl;
	std::cout << "mainChain: " << std::endl;
	for(std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "PendChain: " << std::endl;
	for(std::vector<int>::iterator it = PendChain.begin(); it != PendChain.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

}
