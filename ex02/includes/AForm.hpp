/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:42:27 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 08:28:39 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		
	public:
		AForm(void);
		AForm(const std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &form);
		virtual ~AForm();

		AForm	&operator=(const AForm &form);

		// member functions
		const std::string	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSigned(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat &bureaucrat) const = 0;
		virtual void		executeCheck(const Bureaucrat &bureaucrat) const;

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too high"); }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too low"); }
		};
		
		class ExecuteNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("form is not signed"); }
		};
		
		class FileOpeningFail : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("file cannot be opened"); }
		};
};

std::ostream	&operator<<(std::ostream &o, const AForm &form);

#endif
