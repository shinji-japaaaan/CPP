/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:00:38 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/12 21:00:45 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade(); // grade 1になる
        std::cout << a << std::endl;
        a.incrementGrade(); // 例外（高すぎ）
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;
        b.decrementGrade(); // grade 150になる
        std::cout << b << std::endl;
        b.decrementGrade(); // 例外（低すぎ）
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 151); // コンストラクタで例外
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
