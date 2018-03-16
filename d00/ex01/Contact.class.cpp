#include "Contact.class.hpp"

Contact::Contact(void) {
	this->index = Contact::nb;
	Contact::nb += 1;
}

Contact::~Contact(void) {
	Contact::nb -= 1;
}

int Contact::nb = 0;
