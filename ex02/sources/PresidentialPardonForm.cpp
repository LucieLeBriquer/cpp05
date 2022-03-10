/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:41:16 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/10 15:29:46 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential pardon", 25, 5), _target("unknown")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("Presidential pardon", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidential)
{
	*this = presidential;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &presidential)
{
	(void)presidential;
	return (*this);
}

/*
**		MEMBER FUNCTIONS
*/

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	this->AForm::executeCheck(bureaucrat);
	std::cout << PURPLE << _target << END << " was forgiven by Zafor Beeblebrox" << std::endl;
}
