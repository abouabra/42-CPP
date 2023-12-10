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

typedef std::vector<int> vec_int;
typedef vec_int::iterator vec_iter;

typedef std::vector<std::vector<int> > vec_vec_int;
typedef vec_vec_int::iterator vec_vec_iter;


typedef std::vector<std::pair<vec_int, vec_vec_iter> > vec_pair;
typedef vec_pair::iterator vec_pair_iter;
class PmergeMe
{
	private:
		vec_int numbers;
		vec_int rest;
		bool debug_mode;
		PmergeMe();
	public:
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void merge_insertion_sort();
		void merge_part(vec_int &v, int vec_size, vec_vec_int &big_v);
		void print_vec(vec_vec_int big_v,vec_int rest, int vec_size);
		void reorder_v(int vec_size, vec_vec_int &big_v,vec_int &v);
		void make_new_v(vec_vec_int &big_v,vec_int &new_v);
		void make_pairs(vec_int v, int size_of_v, vec_vec_int &big_v);
		void insertion_part(vec_vec_int &big_v,vec_int rest, int vec_size,vec_int &new_v);
		void print_main_and_pend_chain(vec_vec_int main_chain, vec_pair pend_chain,vec_int rest, int vec_size);
		void split_big_v(vec_vec_int &big_v,vec_int v, int vec_size);
		void make_v_from_main_and_pend_chain(vec_vec_int main_chain,vec_int rest,vec_int &v);
		void update_pend_chain(vec_pair &pend_chain, vec_vec_iter it);
		void make_main_chain_and_pend_chain(vec_vec_int &main_chain, vec_pair &pend_chain, vec_vec_int big_v);
		void set_debug_mode(bool debug_mode);
};		

bool comp_func(vec_int v1, vec_int v2);

#endif