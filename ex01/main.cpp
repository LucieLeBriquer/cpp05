/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:23:49 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 08:23:35 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form 		f("formular", 10, 4);
	Bureaucrat	bob("Bob", 11);

	std::cout << f << std::endl;
	std::cout << bob << std::endl;
	
	bob.signForm(f);
	bob.upGrade();
	bob.signForm(f);

	std::cout << std::endl << f << std::endl;

	return (0);
}
