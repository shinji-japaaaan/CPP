/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:00:38 by sishizaw          #+#    #+#             */
/*   Updated: 2025/08/11 10:51:44 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Form form1("FormA", 2, 10);

        std::cout << alice << std::endl;
        std::cout << form1 << std::endl;

        alice.signForm(form1);  // 成功するはず
        std::cout << form1 << std::endl;

        Bureaucrat bob("Bob", 150);
        Form form2("FormB", 100, 10);

        bob.signForm(form2);  // 失敗するはず

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

