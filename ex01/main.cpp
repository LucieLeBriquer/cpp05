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
#include <iomanip>

static void     printTitle(std::string title)
{
        std::string     toPrint;
        int     size = 54;
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

void	test(int exception)
{
	Form 		f("formular", 10, 4);
	Bureaucrat	bob("Bob", 11);

	std::cout << f << std::endl;
	std::cout << bob << std::endl;
	
	if (exception == 0)
		f.beSigned(bob);
	bob.upGrade();
	f.beSigned(bob);
	std::cout << f << std::endl;
	f.beSigned(bob);
}

int	main(void)
{
	printTitle("TRY 0");
	try 
	{
		test(0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	printTitle("TRY 1");
	try
	{
		test(1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}
