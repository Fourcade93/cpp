#include "Contact.class.hpp"

void	add_contact(Contact *contact)
{
	std::cout << "Enter the first name: ";
	getline(std::cin, contact->first_name);
	std::cout << "Enter the last name: ";
	getline(std::cin, contact->last_name);
	std::cout << "Enter the nickname: ";
	getline(std::cin, contact->nickname);
	std::cout << "Enter the login: ";
	getline(std::cin, contact->login);
	std::cout << "Enter the postal address: ";
	getline(std::cin, contact->postal);
	std::cout << "Enter the email address: ";
	getline(std::cin, contact->email);
	std::cout << "Enter the phone number: ";
	getline(std::cin, contact->phone);
	std::cout << "Enter the birthday date: ";
	getline(std::cin, contact->birthdate);
	std::cout << "Enter the favorite meal: ";
	getline(std::cin, contact->fv_meal);
	std::cout << "Enter the underwear color: ";
	getline(std::cin, contact->undwear_col);
	std::cout << "Enter the darkest secret: ";
	getline(std::cin, contact->secret);
}

void	print_col(std::string s)
{
	int j = -1;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 9 && s.size() > 10)
			std::cout << ".";
		else if (i + s.size() < 10)
			std::cout << " ";
		else
			std::cout << s[++j];
	}
	std::cout << "|";
}

void	get_contact(Contact contacts[8], int i)
{
	int index;

	std::cout << "Please enter the index: ";
	std::cin >> index;
	std::cin.ignore(256, '\n');
	if (index < 0 || index > i)
	{
		std::cout << "Error. Please enter valid index" << std::endl;
		return ;
	}
	print_col(std::to_string(contacts[index].index));
	print_col(contacts[index].first_name);
	print_col(contacts[index].last_name);
	print_col(contacts[index].nickname);
	std::cout << std::endl;
}

int main(void)
{
	std::string in;
	Contact contacts[8];
	int i = -1;

	while (1)
	{
		std::cout << "Please enter the command: ";
		getline(std::cin, in);
		if (in.compare("EXIT") == 0)
			exit(1);
		else if (in.compare("ADD") == 0 && i < 8)
			add_contact(&(contacts[++i]));
		else if (in.compare("ADD") == 0 && i >= 8)
			std::cout << "Sorry, but phonebook is full :-(" << std::endl;
		else if (in.compare("SEARCH") == 0)
			get_contact(contacts, i);
		else
			std::cout << "Error. Invalid command!" << std::endl;
	}
	return 0;
}