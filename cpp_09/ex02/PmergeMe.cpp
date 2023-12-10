#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <sys/_types/_size_t.h>
#include <utility>
#include <vector>

int n_compares;

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
	int size_of_v = 2 * vec_size;
	if (size_of_v == 0)
		size_of_v = 1;
	
	make_pairs(v, size_of_v, big_v);
	print_vec(big_v, rest, vec_size);
	reorder_v(vec_size, big_v, v);

	if(big_v.size() > 3)
		merge_part(v, size_of_v, big_v);
	insertion_part(big_v, rest, vec_size, v);
}

void PmergeMe::make_pairs(std::vector<int> v, int size_of_v, std::vector<std::vector<int> > &big_v)
{
	if (size_of_v == 0)
		size_of_v = 1;
	big_v.clear();
	rest.clear();
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

void PmergeMe::make_new_v(std::vector<std::vector<int> > &big_v, std::vector<int> &v)
{
	v.clear();
	for(size_t i = 0; i < big_v.size(); i++)
		for (size_t j = 0; j < big_v[i].size(); j++)
			v.push_back(big_v[i][j]);
	for(size_t i = 0; i < rest.size(); i++)
		v.push_back(rest[i]);
}

void PmergeMe::reorder_v(int vec_size, std::vector<std::vector<int> > &big_v, std::vector<int> &v)
{
	if(vec_size == 0)
		vec_size = 1;
	for(size_t i = 0; i + 1 < big_v.size(); i += 2)
	{
		n_compares++;
		if (big_v[i].back() > big_v[i + 1].back())
			std::swap(big_v[i], big_v[i + 1]);
	}
	make_new_v(big_v, v);
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
	size_t size = numbers.size();
	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	std::vector<std::vector<int> > big_v;
	merge_part(numbers, 0, big_v);
	std::cout << std::endl << "n_compares: " << n_compares << std::endl;
	std::cout << "numbers: " << std::endl;
	for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	
	
	
	
	
	std::is_sorted(numbers.begin(), numbers.end()) ? std::cout << "sorted" << std::endl : std::cout << "not sorted" << std::endl;
	if(size != numbers.size())
		std::cout << "size is wrong" << std::endl;
	else
		std::cout << "size is correct" << std::endl;
}

void PmergeMe::print_main_and_pend_chain(std::vector<std::vector<int> > main_chain, std::vector<std::pair<std::vector<int> , std::vector<std::vector<int> >::iterator> > pend_chain, std::vector<int> rest, int vec_size)
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
	for(std::vector<std::pair<std::vector<int> , std::vector<std::vector<int> >::iterator> >::iterator it = pend_chain.begin(); it != pend_chain.end(); it++)
	{
		std::cout << "[";
		for(std::vector<int>::iterator it2 = it->first.begin(); it2 != it->first.end(); it2++)
		{
			std::cout << *it2;
			if(it2 + 1 != it->first.end())
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

void PmergeMe::insertion_part(std::vector<std::vector<int> > &big_v, std::vector<int> rest, int vec_size, std::vector<int> &v)
{
	(void)vec_size;
	(void)rest;
	(void)big_v;

	print_vec(big_v, rest, vec_size);
	std::vector<std::vector<int> > main_chain;
	std::vector<std::pair<std::vector<int> , std::vector<std::vector<int> >::iterator> > pend_chain;
	pend_chain.reserve(big_v.size());
	main_chain.reserve(big_v.size());
	size_t i = 0;

	for(; i < 2 && i < big_v.size(); i++)
	{
		main_chain.push_back(big_v[i]);
	}
	// for(size_t i = 2; i < big_v.size();)
	// {
	// 	pair_temp.first = big_v[i];
	// 	pair_temp.second = main_chain.end();
	// 	++i;
	// 	if (i < big_v.size())
	// 	{
	// 		pair_temp.second = main_chain.insert(main_chain.end(), big_v[i]);
	// 		// std::cout << "value : " << pair_temp.second->back() << std::endl;
	// 		// pend_chain.push_back(pair_temp);
	// 	}
	// 	// if (pair_temp.second != main_chain.end())
	// 	// 	std::cout << "second element : " << pair_temp.second->back() << std::endl;
	// 	// std::cout << "here" << std::endl;
	// 	pend_chain.push_back(pair_temp);
	// 	++i;
	// 	// std::cout << "creation loop:" << std::endl;
	// 	// for(std::vector<int>::iterator it = pend_chain.back().second->begin(); it != pend_chain.back().second->end(); it++)
	// 	// 	std::cout << *it << " ";
	// // 	// std::cout << std::endl;
	// 	}
	std::pair<std::vector<int>, std::vector<std::vector<int> >::iterator > pair_temp;
	std::vector<std::vector<int> >::iterator tmp;
	// for(std::vector<std::vector<int> >::iterator it = big_v.begin() + 2; it != big_v.end(); )
	// {
	// 	// if (it + 1 == big_v.end())
	// 	// {
	// 	// 	pend_chain.push_back(std::make_pair(*it,main_chain.end()));
	// 	// 	// std::cout << "here 1" << std::endl;
	// 	// 	break ;
	// 	// }
	// 	// tmp = main_chain.insert(main_chain.end(), *(it + 1));
	// 	// pend_chain.push_back(std::make_pair(*it,tmp));
	// 	// it += 2;

	// 	// std::cout << "size: " << pend_chain.back().second->size() << std::endl;
	// 	// for(std::vector<int>::iterator it2 = pend_chain.back().second->begin(); it2 != pend_chain.back().second->end(); it2++)
	// 	// 	std::cout << *it2 << " ";
	// 	// std::cout << std::endl;
	// }

	for(std::vector<std::vector<int> >::iterator it = big_v.begin() + 2; it != big_v.end(); )
	{
		pair_temp.first = *it;
		pair_temp.second = main_chain.end();
		++it;
		if (it != big_v.end())
		{
			pair_temp.second = main_chain.insert(main_chain.end(), *it);
			++it;
		}
		pend_chain.push_back(pair_temp);
	}
	for(std::vector<std::pair<std::vector<int> , std::vector<std::vector<int> >::iterator> >::iterator it = pend_chain.begin(); it != pend_chain.end(); it++)
	{
			// std::cout << "first : " << it->first.back() << std::endl;
			// if(it->second != main_chain.end())
			// 	std::cout << "second : " << it->second->back() << std::endl;

		// if(it->second != main_chain.end())
			// std::cout << "here 3" << std::endl;

		// if (it->second == main_chain.end())
		// {
			// std::cout << "here 3" << std::endl;
		// 	break;
		// }
		// std::cout << "here 2" << std::endl;
	// // if(it->second->size() != 1)
	// // {

		// std::cout << it->second->size() << std::endl;
		// for(std::vector<int>::iterator it2 = it->second->begin(); it2 != it->second->end(); it2++)
		// {

		// 	// std::cout << "****************" << std::endl;
		// 	std::cout << *it2 << " ";
		// }
		// std::cout << std::endl;
	// }
	}
	// std::cout << "pend size :" << pend_chain.size() << std::endl;
	// std::cout << "****************" << std::endl;
	// if (pend_chain.size())
	// 	std::cout << "had lvector : " << pend_chain.begin()->first.front() << " value : " << pend_chain.begin()->second->front() << std::endl; 
	
	print_main_and_pend_chain(main_chain, pend_chain, rest, vec_size);








	// for(size_t i = 0; i < pend_chain.size(); i++)
	// {
	// 	if(pend_chain[i].second == main_chain.end())
	// 	{
	// 		std::cout<<"here 3"<<std::endl;
	// 		break;
	// 	}
	// 	for(std::vector<int>::iterator it = pend_chain[i].second->begin() ; it != pend_chain[i].second->end(); it++)
	// 	{
			
	// 			std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl;
	// }



	
	// int count = 0;
	// for(size_t i = 0; i < pend_chain.size(); i++)
	// {
	// 	if(!count)
	// 	{
	// 		count++;
	// 		// std::cout << "hello" << std::endl;
	// 		//print vector on pend_chain[i].second
	// 		// for(std::vector<std::vector<int> >::iterator it = pend_chain[i].second; it != big_v.end(); it++)
	// 		// {
	// 			// std::cout << "hello" << std::endl;
	// 			// for(std::vector<int>::iterator it2 =  pend_chain[i].second->begin(); it2 !=  pend_chain[i].second->end(); it2++)
	// 			// 	std::cout << *it2 << " ";
	// 			// std::cout << std::endl;
	// 		// }

	// 		// std::cout << "hello" << std::endl;
	// 		// std::cout<<"here 1"<<std::endl;
	// 		// std::cout<<"index: " << i << "| first element: " << *pend_chain[i].second->begin() << std::endl;
	// 		std::cout<<"here 1"<<std::endl;
	// 		for(std::vector<int>::iterator it = pend_chain[i].second->begin(); it != pend_chain[i].second->end(); it++)
	// 		{
	// 			std::cout << *it << " ";
	// 		}
	// 		std::cout << std::endl;
	// 		std::cout<<"here 2"<<std::endl;
			// std::vector<std::vector<int> >::iterator it = std::lower_bound(main_chain.begin(), pend_chain[i].second, pend_chain[i].first, comp_func);
			// main_chain.insert(it, pend_chain[i].first);
	// 	}
	// 	else
	// 	{
			// std::vector<std::vector<int> >::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[i].first, comp_func);
			// main_chain.insert(it, pend_chain[i].first);
	// 	}
	// }
	
	for(std::vector<std::pair<std::vector<int> , std::vector<std::vector<int> >::iterator> >::iterator it = pend_chain.begin(); it != pend_chain.end(); it++)
	{
		// if (it->second == main_chain.end())
		// 	break;
		// if (it->second < main_chain.end())
		// 	std::cout << "second  " << it->second->back() << std::endl;
		// if(it->second != main_chain.end())
		// {
		// 	for(std::vector<int>::iterator it2 = it->second->begin(); it2 != it->second->end(); it2++)
		// 	{
		// 		std::cout << *it2 << " ";
		// 	}
		// }
		// std::cout << std::endl;
		if(it == pend_chain.begin())
		{
			// std::cout << "here 0" << std::endl;
	// 		//print vector on it->second
	// 		// std::cout << "print first" << *it->second->begin() << std::endl;
	// 		// for(std::vector<int>::iterator it2 = it->second->begin(); it2 != it->second->end(); it2++)
	// 		// {
	// 		// 	std::cout << *it2 << " ";
	// 		// }
	// 		// std::cout << std::endl;
	// 		std::cout << "here 1" << std::endl;
			// if (pend_chain.size() && it->second != main_chain.end())
			// 	std::cout << "second  " << it->second->back() << std::endl;
			std::vector<std::vector<int> >::iterator it2 = std::lower_bound(main_chain.begin(), it->second, it->first, comp_func);
	// 		std::cout << "here 2" << std::endl;
			main_chain.insert(it2, it->first);
		}
		else
		{
		std::vector<std::vector<int> >::iterator it2 = std::lower_bound(main_chain.begin(), main_chain.end(), it->first, comp_func);
		main_chain.insert(it2, it->first);
		}
	// // 	// std::cout << std::endl;
	}

	make_v_from_main_and_pend_chain(main_chain, rest, v);
	
	make_pairs(v, vec_size, big_v);
}


bool comp_func(std::vector<int> v1, std::vector<int> v2)
{
	n_compares++;
	return v1.back() < v2.back();
}
void PmergeMe::split_big_v(std::vector<std::vector<int> > &big_v, std::vector<int> v, int vec_size)
{
	(void)vec_size;
	(void)v;
	(void)big_v;
	if(vec_size == 0)
		vec_size = 1;
	big_v.clear();
	std::vector<int> small_v;
	for(size_t i = 0; i < v.size(); i += vec_size)
	{
		small_v.clear();
		small_v.push_back(v[i]);
		if(i + 1 < v.size())
			small_v.push_back(v[i + 1]);
		big_v.push_back(small_v);
	}
}


void PmergeMe::make_v_from_main_and_pend_chain(std::vector<std::vector<int> > main_chain, std::vector<int> rest, std::vector<int> &v)
{
	v.clear();
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = 0; j < main_chain[i].size(); j++)
			v.push_back(main_chain[i][j]);
	}
	for (size_t i = 0; i < rest.size(); i++)
		v.push_back(rest[i]);
}


