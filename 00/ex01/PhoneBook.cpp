/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:44:44 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/04 15:26:15 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

static std::string truncateField(const std::string &field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

bool readInput(const std::string &prompt, std::string &output) {
    std::cout << prompt;
    if (!std::getline(std::cin, output)) {
        std::cout << "\nEOF detected during input. Cancelling add.\n";
        return false;
    }
    if (output.empty()) {
        std::cout << "Field cannot be empty. Cancelling add.\n";
        return false;
    }
    return true;
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    if (!readInput("First Name: ", input)) return;
    newContact.setFirstName(input);

    if (!readInput("Last Name: ", input)) return;
    newContact.setLastName(input);

    if (!readInput("Nickname: ", input)) return;
    newContact.setNickname(input);

    if (!readInput("Phone Number: ", input)) return;
    newContact.setPhoneNumber(input);

    if (!readInput("Darkest Secret: ", input)) return;
    newContact.setDarkestSecret(input);

    if (contactCount < 8)
        contacts[contactCount++] = newContact;
    else {
        int i = 1;
        while (i < 8) {
            contacts[i - 1] = contacts[i];
            i++;
        }
        contacts[7] = newContact;
    }
}

void PhoneBook::displayContacts() const {
    std::cout << "|"
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;

    int i = 0;
    while (i < contactCount) {
        std::cout << "|"
                  << std::setw(10) << i << "|"
                  << std::setw(10) << truncateField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getNickname()) << "|"
                  << std::endl;
        i++;
    }
}

void PhoneBook::searchContact() const {
    int index;

    if (contactCount == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    displayContacts();
    std::cout << "Enter index: ";
    std::cin >> index;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number." << std::endl;
        return;
    }

    std::cin.ignore();

    if (index < 0 || index >= contactCount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}


