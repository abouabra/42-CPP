#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number,std::string darkest_secret)
{
    First_name = first_name;
    Last_name = last_name;
    Nick_name = nick_name;
    Phone_number = phone_number;
    Darkest_secret = darkest_secret;
}

Contact ::Contact()
{
    return ;
}

Contact ::~Contact()
{
    return ;
}

std::string Contact::GetFirstName()
{
    return Contact::First_name;
}

std::string Contact::GetLastName()
{
    return Contact::Last_name;
}

std::string Contact::GetNickName()
{
    return Contact::Nick_name;
}

std::string Contact::GetPhoneNumber()
{
    return Contact::Phone_number;
}

std::string Contact::GetDarkestSecret()
{
    return Contact::Darkest_secret;
}