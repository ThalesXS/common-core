// Created by tde-sous on 4/1/24.
#include "BitcoinExchange.hpp"

template <typename T> std::string BitcoinExchange::NumberToString(T Number) {
  std::ostringstream ss;
  ss << Number;
  return ss.str();
}

float BitcoinExchange::findValue(std::string date) {
  std::string bestMatch;


	std::map<std::string, float>::iterator it = this->list_.begin();

	while(it != this->list_.end())
	{
		if (date <= it->first) {
      		if (date < it->first) {
        			if (it != list_.begin())
          				it--;
      			}
    		return it->second;
    	}
		it++;
	}
	it--;
	return it->second;
}

void BitcoinExchange::parseDatabase() {
  std::ifstream databaseFile("data.csv", std::ifstream ::in);
  std::string str;

  if (!databaseFile.is_open())
    throw noDatabaseFile();

  int i = 0;
  while (std::getline(databaseFile, str)) {
    if (str == "date,exchange_rate" && i++ == 0)
      continue;

    std::string datePart = str.substr(0, str.find(','));
    std::string amountPartStr = str.substr(str.find(',') + 1);

    this->list_.insert(std::make_pair<std::string, float>(
        datePart, std::atof(amountPartStr.c_str())));
    i++;
  }
  if (i == 0)
    throw nothingToRead();
}

void BitcoinExchange::parseInputFile(const char *file) {
  std::ifstream fileStream(file, std::ifstream::in);
  std::string str;
  int i = 0;

  while (std::getline(fileStream, str)) {
    try {
      if (i == 0) {
        if (str != "date | value") {
          std::cout << "Line " << i + 1 << ": " << str << std::endl;
          throw wrongHeader();
        }
        i++;
        continue;
      }

      if (str.find(" | ") == std::string::npos) {
        std::cout << "Line " << i + 1 << ": " << str << std::endl;
        throw invalidFormat();
      }

      std::string datePart = str.substr(0, str.find(" | "));
      std::string amountPartStr = str.substr(str.find(" | ") + 3);

      struct tm tm = {};
      if (!strptime(datePart.c_str(), "%Y-%m-%d", &tm) || !isValidData(tm)) {
        std::cout << "Line " << i + 1 << ": " << str << std::endl;
        throw invalidDate();
      }

      if (!amountPartStr.empty()) {
        char *pEnd;
        float a = std::strtof(&amountPartStr[0], &pEnd);
        if (a < 0 || a > 1000) {
          std::cout << "Line " << i + 1 << ": " << str << std::endl;
          throw amountOutOfRange();
        }
      }

      std::string datePartTmp = datePart;

      float amount = std::atof(amountPartStr.c_str());

      float value = findValue(datePart);
      std::cout << datePartTmp << "=> " << amountPartStr << " = "
                << value * amount << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    i++;
  }
  if (i == 0)
    throw nothingToRead();
}

bool BitcoinExchange::isValidData(const tm &date) {
  switch (date.tm_mon) {
  case 1:
    if ((date.tm_year % 4 == 0 && date.tm_year % 100 != 0) ||
        (date.tm_year % 400 == 0)) {
      return date.tm_mday <= 29;
    } else {
      return date.tm_mday <= 28;
    }
  case 3:
  case 5:
  case 8:
  case 10:
    return date.tm_mday <= 30;
  default:
    return date.tm_mday <= 31;
  }
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *file) {
  parseDatabase();
  parseInputFile(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void)other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  (void)other;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char *BitcoinExchange::noDatabaseFile::what() const throw() {
  return "The data.csv file doesn't exists.";
}

const char *BitcoinExchange::amountOutOfRange::what() const throw() {
  return "Amount is out of range. Use between 0 and 1000.";
}

const char *BitcoinExchange::invalidDate::what() const throw() {
  return "Date format is invalid.";
}

const char *BitcoinExchange::invalidFormat::what() const throw() {
  return "Invalid format missing \" | \".";
}

const char *BitcoinExchange::wrongHeader::what() const throw() {
  return "Wrong header on the file.";
}

const char *BitcoinExchange::nothingToRead::what() const throw() {
  return "Nothing to read on the file.";
}
