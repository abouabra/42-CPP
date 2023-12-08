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
		
		// std::vector<std::vector<int> > big_v;
		std::vector<int> rest;
		// std::vector<int> new_v;
		PmergeMe();
	public:
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void merge_insertion_sort();
		void merge_part(std::vector<int> &v, int vec_size, std::vector<std::vector<int> > &big_v);
		void print_vec(std::vector<std::vector<int> > big_v, std::vector<int> rest, int vec_size);
		void reorder_v(int vec_size, std::vector<std::vector<int> > &big_v, std::vector<int> &v);
		void make_new_v(std::vector<std::vector<int> > &big_v, std::vector<int> &new_v);
		void make_pairs(std::vector<int> v, int size_of_v, std::vector<std::vector<int> > &big_v);
		void insertion_part(std::vector<std::vector<int> > &big_v, std::vector<int> rest, int vec_size, std::vector<int> &new_v);
		void print_main_and_pend_chain(std::vector<std::vector<int> > main_chain, std::vector<std::pair<std::vector<int> , std::vector<std::vector<int> >::iterator> > pend_chain, std::vector<int> rest, int vec_size);
		void split_big_v(std::vector<std::vector<int> > &big_v, std::vector<int> v, int vec_size);
		void make_v_from_main_and_pend_chain(std::vector<std::vector<int> > main_chain, std::vector<int> rest, std::vector<int> &v);
};		
		bool comp_func(std::vector<int> v1, std::vector<int> v2);

#endif