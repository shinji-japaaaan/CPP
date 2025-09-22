#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> priceMap;

public:
    // Orthodox Canonical Form
    BitcoinExchange();                              // デフォルトコンストラクタ
    BitcoinExchange(const BitcoinExchange &other); // コピーコンストラクタ
    BitcoinExchange &operator=(const BitcoinExchange &other); // コピー代入
    ~BitcoinExchange();                             // デストラクタ
    
    bool loadPriceDatabase(const std::string &filename);
    double getPriceForDate(const std::string &date) const;
};

#endif
