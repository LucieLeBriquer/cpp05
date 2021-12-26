/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:01:58 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 11:01:58 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Robotomy request", 72, 45), _target("unknown")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	Form("Robotomy request", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy)
{
	*this = robotomy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy)
{
	(void)robotomy;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm &form)
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

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int	robotomized;

	this->Form::executeCheck(bureaucrat);
	std::cout << "*rizZzzz BzzZz rZz* ";
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << PURPLE << _target << END << " was robotomized" << std::endl;
	else
		std::cout << PURPLE << _target << END << " was not robotomized" << std::endl;
	
}

const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}
