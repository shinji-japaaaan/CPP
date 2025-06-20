/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:01:45 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/20 21:30:10 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Animal a;
    // Animal* a = new Animal(); // ❌

    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < arraySize; ++i) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < arraySize; ++i)
        delete animals[i];

    std::cout << "\n--- DEEP COPY TEST ---\n" << std::endl;

    Dog basic;
    {
        Dog tmp(basic);
        std::cout << "Inside block" << std::endl;
    }
    std::cout << "After block" << std::endl;

    return 0;
}

