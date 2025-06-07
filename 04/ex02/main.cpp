/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:01:45 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/07 20:38:12 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // ✅ Animal クラスが抽象であることの確認（コメントアウトを試す）
    // Animal a; // コンパイルエラーになるべき → OK
    // Animal* a = new Animal(); // ❌ コンパイルエラー（抽象クラス）
    // a.makeSound();

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
        animals[i]->makeSound();  // ✅ 正しくオーバーライドされているか確認
    }

    for (int i = 0; i < arraySize; ++i)
        delete animals[i];

    // ✅ Deep Copy の確認（DogのコピーがBrainもコピーしているか）
    std::cout << "\n--- DEEP COPY TEST ---\n" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "Inside block" << std::endl;
    }
    std::cout << "After block" << std::endl;

    return 0;
}

