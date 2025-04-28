/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:07:17 by sishizaw          #+#    #+#             */
/*   Updated: 2025/04/29 05:07:19 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// newZombie.cpp
#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
