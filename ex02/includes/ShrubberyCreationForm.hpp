/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 08:41:23 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 08:41:23 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm);
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(const std::string target);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &shrubberyForm);
		
		void					execute(const Bureaucrat &bureaucrat) const;
		const std::string		getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm &shrubberyForm);

#endif
