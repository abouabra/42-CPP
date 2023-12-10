#include "PmergeMe.hpp"

int n_compares;

PmergeMe::PmergeMe(char **av)
{
	debug_mode = false;
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

		// for(vec_iteriterator it = numbers.begin(); it != numbers.end(); it++)
		// 	for(vec_iter it2 = it + 1; it2 != numbers.end(); it2++)
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

void PmergeMe::set_debug_mode(bool debug_mode)
{
	this->debug_mode = debug_mode;
}

void PmergeMe::merge_part(vec_int &v, int vec_size, vec_vec_int &big_v)
{
	int size_of_v = 2 * vec_size;
	if (size_of_v == 0)
		size_of_v = 1;

	make_pairs(v, size_of_v, big_v);
	if(debug_mode)
		print_vec(big_v, rest, vec_size);
	reorder_v(vec_size, big_v, v);

	if(big_v.size() > 3)
		merge_part(v, size_of_v, big_v);
	insertion_part(big_v, rest, vec_size, v);
}

void PmergeMe::make_pairs(vec_int v, int size_of_v, vec_vec_int &big_v)
{
	if (size_of_v == 0)
		size_of_v = 1;
	big_v.clear();
	rest.clear();
	vec_int small_v;
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

void PmergeMe::make_new_v(vec_vec_int &big_v, vec_int &v)
{
	v.clear();
	for(size_t i = 0; i < big_v.size(); i++)
		for (size_t j = 0; j < big_v[i].size(); j++)
			v.push_back(big_v[i][j]);
	for(size_t i = 0; i < rest.size(); i++)
		v.push_back(rest[i]);
}

void PmergeMe::reorder_v(int vec_size, vec_vec_int &big_v, vec_int &v)
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

void PmergeMe::print_vec(vec_vec_int big_v, vec_int rest, int vec_size)
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
	for(vec_vec_iter it = big_v.begin(); it != big_v.end(); it++)
	{
		std::cout << "[";
		for(vec_iter it2 = it->begin(); it2 != it->end(); it2++)
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
		for(vec_iter it = rest.begin(); it != rest.end(); it++)
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
	for(vec_iter it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	vec_vec_int big_v;
	merge_part(numbers, 0, big_v);
	std::cout << std::endl << "n_compares: " << n_compares << std::endl;
	std::cout << "numbers: " << std::endl;
	for(vec_iter it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	
	
	
	
	
	std::is_sorted(numbers.begin(), numbers.end()) ? std::cout << "sorted" << std::endl : std::cout << "not sorted" << std::endl;
	size != numbers.size() ? std::cout << "size is wrong: " << size << std::endl : std::cout << "size is correct: " << size << std::endl;
}

void PmergeMe::print_main_and_pend_chain(vec_vec_int main_chain, vec_pair pend_chain, vec_int rest, int vec_size)
{
	for (int i = 0; i < vec_size; i++)
		std::cout << "\t";
	std::cout << "main_chain: ";
	for(vec_vec_iter it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << "[";
		for(vec_iter it2 = it->begin(); it2 != it->end(); it2++)
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
	for(vec_pair_iter it = pend_chain.begin(); it != pend_chain.end(); it++)
	{
		std::cout << "[";
		for(vec_iter it2 = it->first.begin(); it2 != it->first.end(); it2++)
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
	for(vec_iter it = rest.begin(); it != rest.end(); it++)
	{
		std::cout << *it;
		if(it + 1 != rest.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::insertion_part(vec_vec_int &big_v, vec_int rest, int vec_size, vec_int &v)
{
	if(debug_mode)
		print_vec(big_v, rest, vec_size);
	vec_vec_int main_chain;
	vec_pair pend_chain;

	pend_chain.reserve(big_v.size());
	main_chain.reserve(big_v.size());


	make_main_chain_and_pend_chain(main_chain, pend_chain, big_v);

	if(debug_mode)
		print_main_and_pend_chain(main_chain, pend_chain, rest, vec_size);

	for(vec_pair_iter it = pend_chain.begin(); it != pend_chain.end(); it++)
	{
		vec_vec_iter it2 = std::lower_bound(main_chain.begin(), it->second, it->first, comp_func);
		main_chain.insert(it2, it->first);
		update_pend_chain(pend_chain, it->second);
	}

	make_v_from_main_and_pend_chain(main_chain, rest, v);
	
	make_pairs(v, vec_size, big_v);
}

void PmergeMe::make_main_chain_and_pend_chain(vec_vec_int &main_chain, vec_pair &pend_chain, vec_vec_int big_v)
{
	size_t i = 0;

	for(; i < 2 && i < big_v.size(); i++)
	{
		main_chain.push_back(big_v[i]);
	}

	std::pair<vec_int, vec_vec_iter > pair_temp;
	for(vec_vec_iter it = big_v.begin() + 2; i == 2 && it != big_v.end(); )
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
}

void PmergeMe::update_pend_chain(vec_pair &pend_chain, vec_vec_iter it)
{
	for(vec_pair_iter it2 = pend_chain.begin(); it2 != pend_chain.end(); it2++)
	{
		if(it2->second != it)
			it2->second++;
	}
}

bool comp_func(vec_int v1, vec_int v2)
{
	n_compares++;
	return v1.back() < v2.back();
}
void PmergeMe::split_big_v(vec_vec_int &big_v, vec_int v, int vec_size)
{
	if(vec_size == 0)
		vec_size = 1;
	big_v.clear();
	vec_int small_v;
	for(size_t i = 0; i < v.size(); i += vec_size)
	{
		small_v.clear();
		small_v.push_back(v[i]);
		if(i + 1 < v.size())
			small_v.push_back(v[i + 1]);
		big_v.push_back(small_v);
	}
}


void PmergeMe::make_v_from_main_and_pend_chain(vec_vec_int main_chain, vec_int rest, vec_int &v)
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