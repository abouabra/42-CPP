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
		std::vector<int> Struggler;

		std::vector<int> mainChain;
		std::vector<int> PendChain;
		PmergeMe();
	public:
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void run();
};

#endif