/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:00:38 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/14 06:13:14 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File: main.cpp
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp" // 追加

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

        std::cout << "=== Intern test ===" << std::endl;

        Intern someIntern;

        AForm* form1 = someIntern.makeForm("shrubbery creation", "internHome");
        alice.signForm(*form1);
        alice.executeForm(*form1);
        delete form1;

        AForm* form2 = someIntern.makeForm("robotomy request", "internTarget");
        alice.signForm(*form2);
        alice.executeForm(*form2);
        delete form2;

        AForm* form3 = someIntern.makeForm("presidential pardon", "internTargetB");
        alice.signForm(*form3);
        alice.executeForm(*form3);
        delete form3;

        // 存在しないフォーム名のテスト（例外キャッチ）
        try {
            AForm* form4 = someIntern.makeForm("unknown form", "nothing");
            delete form4;
        } catch (std::exception& e) {
            std::cout << "Intern failed to create form: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}





