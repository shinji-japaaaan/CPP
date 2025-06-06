/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:41:02 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/02 20:21:58 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
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

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
    std::cerr << "Error: Could not create output file "
              << outputFilename << std::endl;
    inputFile.close();
    return;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        std::string result;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            result += line.substr(0, pos) + s2;
            line = line.substr(pos + s1.length());
            pos = 0;
        }
        result += line;
        outputFile << result << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

