/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:07:17 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/24 16:54:57 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// newZombie.cpp
#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *newZ = new Zombie(name);
	return newZ;
}
