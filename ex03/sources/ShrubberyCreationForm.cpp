/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 08:51:31 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/10 15:29:40 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery creation", 145, 137), _target("unknown")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("Shrubbery creation", 145, 137), _target(target)
{
	return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm)
{
	*this = shrubberyForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyForm)
{
	(void)shrubberyForm;
	return (*this);
}

/*
**		MEMBER FUNCTIONS
*/

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::ofstream	file;

	this->AForm::executeCheck(bureaucrat);
	file.open((_target + "_shrubbery").c_str());
	if (file.good() == false)
		throw FileOpeningFail();
	file << "              v .   ._, |_  .," << std::endl;
    file << "       \'-._\\/  .  \\ /    |/_" << std::endl;
    file << "           \\\\  _\\, y | \\//" << std::endl;
    file << "     _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
    file << "       \'7-,--.\'._||  / / ," << std::endl;
    file << "       /\'     \'-.\'./ / |/_.\'" << std::endl;
    file << "                 |    |//" << std::endl;
    file << "                 |_    /   " << _target << std::endl;
    file << "                 |-   |" << std::endl;
    file << "                 |   =|" << std::endl;
    file << "                 |    |" << std::endl;
	file << "----------------/ ,  . \\--------._" << std::endl;
	file.close();
}
