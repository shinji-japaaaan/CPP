/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:24:28 by sishizaw          #+#    #+#             */
/*   Updated: 2025/04/29 05:41:56 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.h"

// 関数宣言
Zombie* zombieHorde(int N, std::string name);

int main() {
    // ゾンビの群れを作成
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    // 各ゾンビに自己紹介させる
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    // メモリ解放
    delete[] horde;

    return 0;
}


