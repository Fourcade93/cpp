#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal;
	std::string email;
	std::string phone;
	std::string birthdate;
	std::string fv_meal;
	std::string undwear_col;
	std::string secret;
	int index;
	static int nb;
	Contact(void);
	~Contact(void);
	
};

#endif