/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:23:42 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/03 06:30:48 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") { 
    // デフォルトコンストラクタ（空の名前で初期化）
}

Zombie::Zombie(std::string name) : name(name) { 
    // 名前を受け取るコンストラクタ
}

Zombie::~Zombie() {
    // デストラクタでゾンビが破棄されたことを表示
    std::cout << name << " has been destroyed!" << std::endl;
}

void Zombie::announce(void) const {
    // ゾンビが自己紹介する
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}




