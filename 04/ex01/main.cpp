/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:41:51 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/20 20:50:33 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Animal a;
    // a.makeSound();
    const int arraySize = 10;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- DELETING ANIMALS ---\n" << std::endl;

    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

    std::cout << "\n--- DEEP COPY TEST ---\n" << std::endl;

    Dog basic;
    {
        Dog tmp(basic);
        std::cout << "Inside block" << std::endl;
    }
    std::cout << "After block" << std::endl;
    return 0;
}
