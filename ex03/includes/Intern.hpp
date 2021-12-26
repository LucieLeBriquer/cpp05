/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:00:23 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/26 11:00:23 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern(const Intern &intern);
		
	public:
		Intern(void);
		virtual ~Intern();

		Intern	&operator=(const Intern &intern);

		Form	*makeForm(const std::string formName, const std::string target) const;
};

#endif
