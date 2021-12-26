/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:24:14 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/26 11:26:31 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

Intern	&Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

/*
**		MEMBER FUNCTIONS
*/

static const std::string	lowerStr(const std::string str)
{
	std::string	res;

	for (unsigned int i = 0; i < str.size(); i++)
		res += tolower(str[i]);
	return (res);
}

Form	*Intern::makeForm(const std::string formName, const std::string target) const
{
	Form	*forms[3] = { new ShrubberyCreationForm(target),
						new RobotomyRequestForm(target), 
						new PresidentialPardonForm(target) };
	Form	*formPtr = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (lowerStr(formName) == lowerStr(forms[i]->getName()))
		{
			formPtr = forms[i];
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (formPtr != forms[i])
			delete forms[i];
	}
	std::cout << YELLOW << "Intern" << END;
	if (formPtr)	
		std::cout << " creates " << GREEN << formPtr->getName() << END << " formular" << std::endl;
	else
		std::cout << " cannot create " << GREEN << formName << END << " because " << BLUE << "it's unknown" << END << std::endl;
	return (formPtr);
	
}