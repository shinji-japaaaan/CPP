/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:24:28 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/03 06:30:52 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File: main.cpp
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

// 関数宣言
Zombie* zombieHorde(int N, std::string name);

int main() {
    // ゾンビの群れを作成
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    // 各ゾンビに自己紹介させる（while文で書き換え）
    int i = 0;
    while (i < N) {
        horde[i].announce();
        ++i;
    }

    // メモリ解放
    delete[] horde;

    return 0;
}


