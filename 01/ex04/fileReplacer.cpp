/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:41:02 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/04 06:41:06 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileReplacer.hpp"
#include <iostream>
#include <fstream>

void replaceInFile(const std::string& filename,
                   const std::string& s1,
                   const std::string& s2) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file "
                  << filename << ".replace" << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}
