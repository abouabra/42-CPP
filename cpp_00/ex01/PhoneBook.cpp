#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}
std::string set_string(std::string text)
{
	if(text.length() > 10)
		text = text.substr(0,9).append(".");
	return text;
}
Contact get_contact_info(void)
{
	std::string line;
	Contact new_contact;

	std::string data[5];
	int i = 0;
	while(i < 5)
	{
		if(i == 0)
			std::cout << "Enter First Name: ";
		else if(i == 1)
			std::cout << "Enter Last Name: ";
		else if(i == 2)
			std::cout << "Enter Nick Name: ";
		else if(i == 3)
			std::cout << "Enter Phone Number: ";
		else if(i == 4)
			std::cout << "Enter Darkest Secrest: ";

		std::getline(std::cin,line);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
		if(line.length() > 0)
		{
			data[i] = line;
			i++;
		}
	}
 	new_contact = Contact(data[0], data[1],data[2],data[3],data[4]);
	return new_contact;
}

void  PhoneBook::add()
{
	int i;
	static int index;

	i = index % 8;
	contacts[i] = get_contact_info();
	index++;
	std::cout << "\tContact added successfully " << std::endl;
}

void Print_Specific_Contact(Contact &contact, int index)
{

	std::cout << std::endl;
	std::cout << "\tINDEX:          " << index << std::endl;
	std::cout << "\tFirst Name:     " << contact.GetFirstName() << std::endl;
	std::cout << "\tLast Name:      " << contact.GetLastName() << std::endl;
	std::cout << "\tNick Name:      " << contact.GetNickName() << std::endl;
	std::cout << "\tPhone Number:   " << contact.GetPhoneNumber() << std::endl;
	std::cout << "\tDarkest Secret: " << contact.GetDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void PhoneBook::Print_Contact_Table()
{
	int i = -1;

	std::cout << "=============================================" << std::endl;
	std::cout << "|  INDEX   |First Name| Last Name| Nick Name|"  << std::endl;
	while(++i < 8)
	{
		if(contacts[i].GetFirstName().length() <= 0)
			break;
		std::cout << "|==========|==========|==========|==========|" << std::endl;
		std::cout << "|";
		std::cout << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::setw(10) << set_string(contacts[i].GetFirstName());
		std::cout << "|";
		std::cout << std::setw(10)  << set_string(contacts[i].GetLastName());
		std::cout << "|";
		std::cout << std::setw(10) << set_string(contacts[i].GetNickName());
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "=============================================" << std::endl;
}

int Get_Contact_Index(int i)
{
	std::string tmp;
	int index;

	while(1)
    {
		if(!i)
			break;
        std::cout << "Enter index: ";
		std::getline(std::cin,tmp);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
		if(tmp.length() == 1 && std::isdigit(tmp[0]))
		{
			index = tmp[0] - '0';
			if (index >= 0 && index < i)
				break;
		}
    }
	return index;
}
void PhoneBook::search()
{
	int index;

	Print_Contact_Table();

	int i = -1;
	while(++i < 8)
		if(contacts[i].GetFirstName().length() <= 0)
			break;
	
	index = Get_Contact_Index(i);
	if(i > 0)
		Print_Specific_Contact(contacts[index], index);
}
