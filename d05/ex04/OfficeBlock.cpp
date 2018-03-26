#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor)
{
	this->_intern = intern;
	this->_signer = signer;
	this->_executor = executor;
	this->_form = NULL;
	return;
}

OfficeBlock::OfficeBlock(Intern & intern, Bureaucrat & signer, Bureaucrat & executor)
{
	this->_intern = &intern;
	this->_signer = &signer;
	this->_executor = &executor;
	this->_form = NULL;
	return;
}

OfficeBlock::OfficeBlock(void)
{
	this->_intern = NULL;
	this->_signer = NULL;
	this->_executor = NULL;
	this->_form = NULL;
	return;
}

OfficeBlock::~OfficeBlock(void) { return; }

void	OfficeBlock::setIntern(Intern intern)
{
	this->_intern = new Intern(intern);
}

void	OfficeBlock::setSigner(Bureaucrat signer)
{
	this->_signer = new Bureaucrat(signer);
}

void	OfficeBlock::setExecutor(Bureaucrat executor)
{
	this->_executor = new Bureaucrat(executor);
}

void	OfficeBlock::doBureaucracy(std::string form, std::string target)
{
	if (!this->_intern)
		throw OfficeBlock::noInternException();
	if (!this->_signer)
		throw OfficeBlock::noSignerException();
	if (!this->_executor)
		throw OfficeBlock::noExecutorException();
	this->_form = this->_intern->makeForm(form, target);
	if (!this->_form)
		throw OfficeBlock::unknownFormException();
	this->_signer->signForm(*(this->_form));
	this->_executor->executeForm(*(this->_form));
}

OfficeBlock::noInternException::noInternException(void) { return; }

char const * OfficeBlock::noInternException::what(void) const throw()
{
	return ("Intern are missing");
}

OfficeBlock::noSignerException::noSignerException(void) { return; }

char const * OfficeBlock::noSignerException::what(void) const throw()
{
	return ("Signer are missing");
}

OfficeBlock::noExecutorException::noExecutorException(void) { return; }

char const * OfficeBlock::noExecutorException::what(void) const throw()
{
	return ("Executor are missing");
}

OfficeBlock::unknownFormException::unknownFormException(void) { return; }

char const * OfficeBlock::unknownFormException::what(void) const throw()
{
	return ("Form are missing");
}
