#include "parser.hpp"

/************************************************************
 * @file parser.сpp
 * @brief Рализация парсинга через паттерн "Стратегия"
 ************************************************************/

s21::ParsingVertex::ParsingVertex(Object &object) : object{object} {}

void s21::ParsingVertex::parse(const std::string &line) const {
  std::istringstream iss(line);
  std::string symbol{};
  double x, y, z;
  if (iss >> symbol >> x >> y >> z) {
    object.vertexes.emplace_back(x, y, z);
  }
}

s21::ParsingLine::ParsingLine(Object &object) : object{object} {}

void s21::ParsingLine::parse(const std::string &line) const {
  std::stringstream iss(line);
  std::string symbol{};
  std::string word{};
  iss >> symbol;
  iss.ignore();
  Line res{};
  char delim{' '};
  while (std::getline(iss, word, delim)) {
    std::stringstream iss2(word);
    double point{};
    iss2 >> point;
    res.indexes.push_back(point);
  }
  object.lines.push_back(res);
}

s21::ObjectParser::ObjectParser() {}
s21::ObjectParser::~ObjectParser() {}

void s21::ObjectParser::set_strategy(
    std::unique_ptr<s21::ParsingStrategy> &&strategy) {
  currentStrategy = std::move(strategy);
}

void s21::ObjectParser::parseFile(Object &object, const std::string &filename) {
  std::ifstream file;
  file.open(filename);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      if (!line.empty()) {
        if (line.substr(0, 2) == "v ") {
          set_strategy(std::make_unique<ParsingVertex>(object));
          currentStrategy->parse(line);
        } else if (line.substr(0, 2) == "f ") {
          set_strategy(std::make_unique<ParsingLine>(object));
          currentStrategy->parse(line);
        }
      }
    }
    file.close();
  }
}
