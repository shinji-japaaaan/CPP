/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 06:01:23 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/14 06:01:31 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    typedef AForm* (Intern::*CreateFormFunc)(const std::string& target) const;

    AForm* createShrubberyCreationForm(const std::string& target) const;
    AForm* createRobotomyRequestForm(const std::string& target) const;
    AForm* createPresidentialPardonForm(const std::string& target) const;
};

#endif
