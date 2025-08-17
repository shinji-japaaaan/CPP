#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <sstream>
#include <cctype>

static bool isCharLiteral(const std::string& s) {
  return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isSpecialFloat(const std::string& s) {
  return s == "-inff" || s == "+inff" || s == "nanf";
}

static bool isSpecialDouble(const std::string& s) {
  return s == "-inf" || s == "+inf" || s == "nan";
}

void ScalarConverter::convert(const std::string& literal) {
  double value;

  if (isCharLiteral(literal)) {
    char c = literal[0];
    value = static_cast<double>(c);
  } else if (isSpecialFloat(literal)) {
    value = std::strtof(literal.c_str(), NULL);
  } else if (isSpecialDouble(literal)) {
    value = std::strtod(literal.c_str(), NULL);
  } else {
    // ここを std::stod から strtod に書き換え
    char* endptr = NULL;
    value = std::strtod(literal.c_str(), &endptr);
    if (*endptr != '\0') {
      std::cerr << "Invalid literal" << std::endl;
      return;
    }
  }
  // char
  std::cout << "char: ";
  if (std::isnan(value) || value < 0 || value > 127)
    std::cout << "impossible" << std::endl;
  else if (std::isprint(static_cast<char>(value)))
    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;

  // int
  std::cout << "int: ";
  if (std::isnan(value) || value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max())
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(value) << std::endl;

  // float
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(value) << "f" << std::endl;

  // double
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(value) << std::endl;
}
