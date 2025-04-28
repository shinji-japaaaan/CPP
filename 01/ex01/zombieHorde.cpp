/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:24:04 by sishizaw          #+#    #+#             */
/*   Updated: 2025/04/29 05:43:41 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {
    // N体のゾンビを生成する（デフォルトコンストラクタが必要）
    Zombie* horde = new Zombie[N];

    // 各ゾンビに名前を設定する
    for (int i = 0; i < N; ++i) {
        horde[i] = Zombie(name);  // 名前を渡してゾンビを生成
    }

    return horde;
}




