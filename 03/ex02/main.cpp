/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:04:48 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/05 21:04:50 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap unit1("Thor");

    unit1.attack("Loki");
    unit1.takeDamage(20);
    unit1.beRepaired(15);
    unit1.highFivesGuys();

    FragTrap unit2(unit1);
    FragTrap unit3("Odin");
    unit3 = unit1;

    return 0;
}
