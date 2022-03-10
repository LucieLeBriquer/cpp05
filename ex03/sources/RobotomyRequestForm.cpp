/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:01:58 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/10 15:29:43 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("Robotomy request", 72, 45), _target("unknown")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("Robotomy request", 72, 45), _target(target)
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

/*
**		MEMBER FUNCTIONS
*/

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int	robotomized;

	this->AForm::executeCheck(bureaucrat);
	std::cout << "*rizZzzz BzzZz rZz* ";
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << PURPLE << _target << END << " was robotomized" << std::endl;
	else
		std::cout << PURPLE << _target << END << " was not robotomized" << std::endl;
	
}
