/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:31:38 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/10 15:29:30 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &presidential);
		
	public:
		PresidentialPardonForm(const std::string &target);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &presidential);

		void					execute(const Bureaucrat &Bureaucrat) const;
};

#endif
