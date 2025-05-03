/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:23:03 by sishizaw          #+#    #+#             */
/*   Updated: 2025/04/29 05:43:18 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie();  // デフォルトコンストラクタを追加
    Zombie(std::string name);  // 名前を受け取るコンストラクタ
    ~Zombie();
    void announce(void) const;
};

#endif





