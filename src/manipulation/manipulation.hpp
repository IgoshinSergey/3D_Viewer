#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MANIPULATION_HPP_
#define CPP4_3DVIEWER_V2_0_1_SRC_MANIPULATION_HPP_

/************************************************************
 * @file manipulation.hpp
 * @brief Логика модели
 ************************************************************/

#include "../parser/parser.hpp"
#include "../transformation/transformation.hpp"

namespace s21 {

/************************************************************
 * @brief Класс для реализации паттерна "Фасад"
 * @details Реализованы методы для управления моделью
 ************************************************************/
class ManipulationFacade {
 private:
  /************************************************************
   * @brief Парсер obj файлов
   ************************************************************/
  ObjectParser parser;

  /************************************************************
   * @brief Объект осуществляющий преобразования модели
   ************************************************************/
  ObjectTransformer transformer;

 public:
  /************************************************************
   * @brief Конструктор по умолчанию
   * @details Вызывает конструкторы по умолчанию
   ***********************************************************/
  ManipulationFacade();

  /************************************************************
   * @brief Метод для парсинга файла
   * @param object Ссылка на объект, в котором будет сохраняться информация
   * @param filename Путь до файла
   ************************************************************/
  void parseFile(Object& object, std::string filename);

  /************************************************************
   * @brief Метод преобразования модели
   *
   * В методе устанавливается стратегия, которая нам нужна, и вызывается метод
   *преобразования объекта transformer
   * @param vertexes Вектор, над которым будет происходить преобразование
   * @param move Название преобразования
   * @param value Значение, указывающий или шаг, или угол, или коэффициент
   *масштабирования
   ************************************************************/
  void TransformModel(std::vector<Point>& vertexes, Movement move, double val);

  /************************************************************
   * @brief Метод для нормализации модели
   *
   * Метод нормализует модель, то есть централизует и уменьшает масштаб,чтобы
   *модель была в экране
   * @param vertexes Вектор, который нормализуем
   ************************************************************/
  void Normalization(std::vector<Point>& vertexes);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MANIPULATION_HPP_