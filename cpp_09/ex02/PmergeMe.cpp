#include "PmergeMe.hpp"
#include <algorithm>
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

		for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
			for(std::vector<int>::iterator it2 = it + 1; it2 != numbers.end(); it2++)
				if(*it == *it2)
					throw std::exception();
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

void PmergeMe::set_straggler()
{
	if(numbers.size() % 2 != 0)
	{
		straggler.push_back(numbers.back());
		numbers.pop_back();
	}
}
void PmergeMe::make_each_pair()
{
	std::pair<int, int> pair;

	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it += 2)
	{
		if(*it > *(it + 1))
			pair = std::make_pair(*(it + 1), *it);
		else
			pair = std::make_pair(*it, *(it + 1));
		vecPair.push_back(pair);
	}
}

// void insert(std::pair<int, int> element, std::vector<std::pair<int, int> >& pair, int n) {
// 	if (n < 0)
// 		pair[0] = element;

// 	else if (element.second >= pair[n].second) {
// 		if (n == static_cast<int>(pair.size() - 1))
// 			pair.push_back(element);
// 		else
// 			pair[n + 1] = element;
//   	} 
// 	else {
// 		if (n == static_cast<int>(pair.size() - 1))
// 			pair.push_back(pair[n]);
// 		else {
// 			pair[n + 1] = pair[n];
// 			insert(element, pair, n - 1);
// 		}
// 	}
// }

void insert(std::pair<int, int> element, std::vector<std::pair<int, int> >& pair, int n) {
	// std::cout << "n: " << n   << "    element: " << element.first << " | " << element.second << std::endl;
	// for(std::vector<std::pair<int, int> >::iterator it = pair.begin(); it != pair.end(); it++)
	// 	std::cout << it->first << " | " << it->second << std::endl;

    if (n < 0)
        pair[0] = element;
    else if (element.second >= pair[n].second) {
        pair[n + 1] = element;
        if (n == static_cast<int>(pair.size() - 1))
            pair.push_back(pair[n]);
    } else {
        pair[n + 1] = pair[n];
        insert(element, pair, n - 1);
    }
}

void PmergeMe::insertion_sort_kinda(std::vector<std::pair<int, int> > &pairs, int len)
{
	if(len < 1)
		return;
	insertion_sort_kinda(pairs, len - 1);
	insert(pairs[len], pairs, len -1);
}

int jacobsthal(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> jacobstall_sequence(std::vector<int> &PendChain)
{
	int size = PendChain.size();
	std::vector<int> jacob_seq;

	// jacob_seq.push_back(1);
	int jacob_index = 3;
	for(int i = 0; i < size; i++)
	{
		jacob_seq.push_back(jacobsthal(jacob_index));
		jacob_index++;
	}
	
	return jacob_seq;
}

void PmergeMe::merge_insertion_sort()
{
	std::cout << "numbers: " << std::endl;
	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	set_straggler();
	make_each_pair();

	std::cout << "straggler: " << std::endl;
	for(std::vector<int>::iterator it = straggler.begin(); it != straggler.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "pairs: " << std::endl;
	for(std::vector<std::pair<int, int> >::iterator it = vecPair.begin(); it != vecPair.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;	

	insertion_sort_kinda(vecPair, vecPair.size() -1);

	std::cout << "sorted pairs by their second member:" << std::endl;
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


	std::vector<int> jacob_seq = jacobstall_sequence(PendChain);
	std::cout << "jacobstall_sequence: " << std::endl;
	for(std::vector<int>::iterator it = jacob_seq.begin(); it != jacob_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	int inc = 0;
	int max = PendChain.size();
	for(int i = 0; i < (int)jacob_seq.size();i++)
	{
		int location = jacob_seq[i];
		if(location > (int)PendChain.size())
			location = max;
		// std::cout << "location: " << location << std::endl;
		std::vector<int>::iterator it2 = std::upper_bound(mainChain.begin(), mainChain.begin() + location + inc, *PendChain.begin());
		// std::cout << "all: " << location + inc << "   increment: " << inc << "   location: " << location << "   jacob_seq: " << jacob_seq[i] << "   main_Size: " << mainChain.size() << "    num_of_comp li rba7na: " <<  mainChain.size() - (location + inc)<< std::endl;
		mainChain.insert(it2, *PendChain.begin());
		PendChain.erase(PendChain.begin());
		if(PendChain.empty())
			break;
		inc++;
	}

	std::cout << std::endl << "merge: " << std::endl;
	for(std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	if(!straggler.empty())
	{
		std::vector<int>::iterator it2 = std::upper_bound(mainChain.begin(), mainChain.end(), *straggler.begin());
		mainChain.insert(it2, *straggler.begin());
		straggler.erase(straggler.begin());
	}

	std::cout << std::endl << "adding straggler: " << std::endl;
	for(std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}
// make re &&./PmergeMe 1 2 99 4 22 6 7 33 56 28 45