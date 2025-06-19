/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:00:38 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/12 21:15:05 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("targetA");
        PresidentialPardonForm pardon("targetB");

        alice.signForm(shrub);
        alice.executeForm(shrub);

        alice.signForm(robot);
        alice.executeForm(robot);

        alice.signForm(pardon);
        alice.executeForm(pardon);

        // bob は shrubbery を実行できない
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


