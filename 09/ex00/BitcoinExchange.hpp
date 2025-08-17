#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> priceMap;

public:
    bool loadPriceDatabase(const std::string &filename);
    double getPriceForDate(const std::string &date) const;
};

#endif
