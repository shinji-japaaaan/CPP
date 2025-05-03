/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 06:41:02 by sishizaw          #+#    #+#             */
/*   Updated: 2025/05/04 07:22:20 by sishizaw         ###   ########.fr       */
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
        std::string result;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            result += line.substr(0, pos) + s2;  // 置き換え部分を追加
            line = line.substr(pos + s1.length());  // 残りの部分を切り取る
            pos = 0;  // 次の位置を最初に戻す
        }
        result += line;  // 残りの部分を追加
        outputFile << result << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

