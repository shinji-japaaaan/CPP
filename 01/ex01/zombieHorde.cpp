/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:24:04 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/03 06:53:13 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];

    int i = 0;
    while (i < N) {
        std::ostringstream oss;
        oss << name << i;
        horde[i] = Zombie(oss.str());
        i++;
    }
    return horde;
}





