/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:44:54 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/02 18:13:35 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;

public:
    PhoneBook();
    void addContact();
    void searchContact() const;
    void displayContacts() const;
};

#endif
