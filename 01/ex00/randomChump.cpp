/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rondam.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 05:06:57 by sishizaw          #+#    #+#             */
/*   Updated: 2025/04/29 05:06:59 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// randomChump.cpp
#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}
