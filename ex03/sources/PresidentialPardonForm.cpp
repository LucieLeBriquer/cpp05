/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:41:16 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/25 16:41:16 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Presidential pardon", 25, 5), _target("unknown")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	Form("Presidential pardon", 25, 5), _target(target)
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

std::ostream	&operator<<(std::ostream &o, const PresidentialPardonForm &form)
{
	o << "[" << form.getName() << "]" << std::endl;
	o << "\t" << "signed : " << form.getSigned() << std::endl;
	o << "\t" << "target : " << form.getTarget() << std::endl;
	o << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	o << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
	return (o);
};

/*
**		MEMBER FUNCTIONS
*/

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	this->Form::executeCheck(bureaucrat);
	std::cout << PURPLE << _target << END << " was forgiven by Zafor Beeblebrox" << std::endl;
}

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}
