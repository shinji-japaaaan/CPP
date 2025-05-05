/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:58:33 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/05 20:58:36 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap ct1("Taro");

	ct1.attack("Enemy A");
	ct1.takeDamage(4);
	ct1.beRepaired(3);
	ct1.takeDamage(10);
	ct1.attack("Enemy B");
	ct1.beRepaired(2);

	return 0;
}
