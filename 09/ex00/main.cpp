#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

bool isValidDate(const std::string &date) {
    // シンプルに YYYY-MM-DD の形式か確認するだけ（詳細チェックは省略）
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i]))
            return false;
    }
    return true;
}

bool isValidValue(const std::string &valueStr, double &value) {
    std::stringstream ss(valueStr);
    ss >> value;
    if (ss.fail() || !ss.eof()) // 変換失敗、余分な文字がある場合はfalse
        return false;
    if (value < 0 || value > 1000)
        return false;
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadPriceDatabase("data.csv")) {  // 仮にデータベースファイル名は data.csv
        std::cerr << "Error: could not open price database." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    // 1行目はヘッダーの可能性があるので読み飛ばし
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // 前後の空白除去
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        if (!isValidValue(valueStr, value)) {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double price = btc.getPriceForDate(date);
        if (price < 0) {
            std::cerr << "Error: no price available for date " << date << std::endl;
            continue;
        }

        double result = value * price;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    return 0;
}
