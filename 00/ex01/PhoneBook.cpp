/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:44:44 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/02 18:13:25 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

static std::string truncateField(const std::string &field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setFirstName(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setLastName(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setNickname(input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
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

    // 入力失敗（数字以外）を検出
    if (std::cin.fail()) {
        std::cin.clear(); // エラー状態リセット
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // バッファを捨てる
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


