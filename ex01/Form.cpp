/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:47:01 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 07:47:01 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
**		CONSTRUCTORS AND DESTRUCTOR
*/

Form::Form(void) : _name("useless"), _gradeSign(150), _gradeExec(150), _signed(false)
{
	return ;
}

Form::Form(const std::string name, int gradeSign, int graedExec) :
	_name(name), _gradeSign(gradeSign), _gradeExec(graedExec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &form) : _gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
	*this = form;
}

Form::~Form()
{
	return ;
}

/*
**		OVERLOAD OPERATORS
*/

Form	&Form::operator=(const Form &form)
{
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "[" << form.getName() << "]" << std::endl;
	o << "\t" << "signed : " << form.getSigned() << std::endl;
	o << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	o << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
	return (o);
};

/*
**		MEMBER FUNCTIONS
*/

const std::string	Form::getName(void) const
{
	return (_name);
}

int		Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int		Form::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	bureaucrat.signForm(*this);
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}
