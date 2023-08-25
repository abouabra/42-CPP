#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		void	Print_Contact_Table();
		void	add();
		void	search();
};
#endif