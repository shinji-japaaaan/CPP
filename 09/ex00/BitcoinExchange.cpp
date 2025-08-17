#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool BitcoinExchange::loadPriceDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str()); // c_str()を使う
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // ヘッダー読み飛ばし

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string priceStr;

        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, priceStr))
            continue;

        double price = 0.0;
        std::stringstream ssPrice(priceStr);
        ssPrice >> price;
        if (ssPrice.fail())
            continue;

        priceMap[date] = price;
    }
    return true;
}

double BitcoinExchange::getPriceForDate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = priceMap.lower_bound(date);
    if (it != priceMap.end() && it->first == date) {
        return it->second;
    }
    if (it == priceMap.begin()) {
        return -1.0;
    }
    --it;
    return it->second;
}
