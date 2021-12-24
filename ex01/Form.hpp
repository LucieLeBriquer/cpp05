/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:42:27 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 08:28:39 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		
	public:
		Form(void);
		Form(const std::string name, int gradeSign, int graedExec);
		Form(const Form &form);
		virtual ~Form();

		Form	&operator=(const Form &form);

		// member functions
		const std::string	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat &bureaucrat);

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Form::exception : Grade is too high"); }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Form::exception : Grade is too low"); }
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &form);

#endif
