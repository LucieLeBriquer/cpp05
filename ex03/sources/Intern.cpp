/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:24:14 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/10 15:51:48 by lle-briq         ###   ########.fr       */
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

static AForm	*newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static int		getFormNumber(const std::string formName)
{
	std::string		formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int				choosen = -1;

	for (int i = 0; i < 3; i++)
	{
		if (lowerStr(formName) == formNames[i])
		{
			choosen = i;
			break;
		}
	}
	return (choosen);
}

AForm	*Intern::makeForm(const std::string formName, const std::string target) const
{
	constructorPtr	funCreations[3] = {&newShrubbery, &newRobotomy, &newPresidential};
	int				choosen;
	AForm			*formPtr = NULL;

	choosen = getFormNumber(formName);
	std::cout << YELLOW << "Intern" << END;
	if (choosen >= 0)
	{
		formPtr = funCreations[choosen](target);
		std::cout << " creates " << GREEN << formPtr->getName() << END << " formular" << std::endl;
	}
	else
		std::cout << " cannot create " << GREEN << formName << END << " because " << BLUE << "it's unknown" << END << std::endl;
	return (formPtr);

}