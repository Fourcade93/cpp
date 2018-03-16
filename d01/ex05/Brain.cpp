#include "Brain.hpp"

Brain::Brain(void) { return; }
Brain::~Brain(void) { return; }

std::string Brain::identify(void) const
{
	std::stringstream ss;
	ss << std::hex << this;
	return (ss.str());
}
