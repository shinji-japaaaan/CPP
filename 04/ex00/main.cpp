/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:31:48 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/07 05:23:21 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    std::cout << "---- Wrong Animal Test ----" << std::endl;

    const WrongAnimal* wMeta = new WrongAnimal();
    const WrongAnimal* wCat = new WrongCat();

    std::cout << wCat->getType() << " " << std::endl;
    wCat->makeSound();
    wMeta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wMeta;
    delete wCat;

    return 0;
}
