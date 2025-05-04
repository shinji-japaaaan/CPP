/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:35:07 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/04 20:18:47 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
	private:
		typedef void (Harl::*FuncPtr)();
		void debug();
		void info();
		void warning();
		void error();
	public:
		void complain(std::string level);
	};

#endif
