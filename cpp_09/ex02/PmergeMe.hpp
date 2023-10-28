#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

class PmergeMe
{
	private:
		std::vector<int> numbers;
		
		std::vector<std::pair<int, int> > vecPair;
		std::vector<int> straggler;

		std::vector<int> mainChain;
		std::vector<int> PendChain;
		PmergeMe();
	public:
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void merge_insertion_sort();
		void set_straggler();
		void make_each_pair();
		void insertion_sort_kinda(std::vector<std::pair<int, int> > &pairs, int len);
};

#endif