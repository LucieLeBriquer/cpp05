/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:23:49 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/24 11:11:53 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

static void     printTitle(std::string title)
{
        std::string     toPrint;
        int     size = 68;
        int     n;

        toPrint = " " + title + " ";
        n = toPrint.size();
        if (n > size)
        {
                toPrint = toPrint.substr(0, size - 2);
                toPrint[size - 4] = '.';
                toPrint[size - 3] = ' ';
                n = toPrint.size();
        }
        std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
        std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
        std::cout << toPrint.substr(n / 2, n - n / 2);
        std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
        std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}


int	main(void)
{
	srand(time(NULL));

	printTitle("Shrubbery Creation");
	ShrubberyCreationForm	shrub("home");
	Bureaucrat				bob("Bob", 1);
	Bureaucrat				me("Lucie", 140);

	bob.executeForm(shrub);
	bob.signForm(shrub);
	std::cout << shrub << std::endl;
	std::cout << bob << std::endl;
	bob.executeForm(shrub);
	me.executeForm(shrub);

	printTitle("Robotomy Request");
	RobotomyRequestForm		robotomy("correcteur");
	Bureaucrat				me2("Lucie", 1);
	me2.executeForm(robotomy);
	me2.signForm(robotomy);
	me2.executeForm(robotomy);
	me2.executeForm(robotomy);
	me2.executeForm(robotomy);
	me2.executeForm(robotomy);
	
	printTitle("Presidential Pardon");
	PresidentialPardonForm		presidential("correcteur");
	Bureaucrat					me3("Lucie", 6);
	me3.executeForm(presidential);
	me3.signForm(presidential);
	me3.executeForm(presidential);
	me3.upGrade();
	me3.executeForm(presidential);

	return (0);
}
