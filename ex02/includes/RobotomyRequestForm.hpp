/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:57:11 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/10 15:29:29 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &robotomy);
		
	public:
		RobotomyRequestForm(const std::string target);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &robotomy);

		void					execute(const Bureaucrat &bureaucrat) const;
};

#endif
