/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:33:23 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/03 20:33:30 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPtr = &brain;
    std::string& stringRef = brain;

    std::cout << "Memory address of brain: " << &brain << std::endl;
    std::cout << "Memory address held by stringPtr: " << stringPtr << std::endl;
    std::cout << "Memory address held by stringRef: " << &stringRef << std::endl;

    std::cout << "Value of brain: " << brain << std::endl;
    std::cout << "Value pointed to by stringPtr: " << *stringPtr << std::endl;
    std::cout << "Value referenced by stringRef: " << stringRef << std::endl;

    return 0;
}
