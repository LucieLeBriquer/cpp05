/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 06:42:04 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 07:13:05 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		_grade = bureaucrat._grade;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (o);
}

/*
**		MEMBER FUNCTIONS
*/

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upGrade(void)
{
	if (_grade == 1)
		return ;
	_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade == 150)
		return ;
	_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	std::cout << _name;
	if (form.getSigned())
		std::cout << " cannot sign " << form.getName() << " beacause it's already signed." << std::endl;
	else if (_grade > form.getGradeSign())
		std::cout << " cannot sign " << form.getName() << " beacause his grade is too low." << std::endl;
	else
		std::cout << " signs " << form.getName() << std::endl;
}
