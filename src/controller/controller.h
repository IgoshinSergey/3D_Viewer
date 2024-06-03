#ifndef CPP4_3DVIEWER_V2_0_1_SRC_3D_CONTROLLER_HPP_
#define CPP4_3DVIEWER_V2_0_1_SRC_3D_CONTROLLER_HPP_
#include "../manipulation/manipulation.hpp"
#include <vector>

/************************************************************
 * @file controller.hpp
 * @brief Реализация контроллера
 ************************************************************/

namespace s21{

/**
 * @brief Реализация паттерна "Синглтон" в контроллере
*/
class Controller{
public:
    Controller(const Controller& other) = delete;
    Controller(Controller&& other) = delete;
    void operator=(const Controller& other) = delete;
    
    /************************************************************
    * @brief Метод возвращающей объект контроллера
    *
    * Метод всегда возвращает один и тот же объект
    ************************************************************/
    static Controller& getInstance(){
        static Controller controller;
        return controller;
    }

    /************************************************************
    * @brief Метод для преобразования модели
    *
    * @param move Название преобразования
    * @param val Значение, указывающий или шаг, или угол, или коэффициент масштабирования
    ************************************************************/
    void TransformModel(Movement move, double val) {
        model.TransformModel(object.vertexes, move, val);
    }

    /************************************************************
    * @brief Метод нормализующий модель
    ************************************************************/
    void Normalization() {
        model.Normalization(object.vertexes);
    }

    /**
     * @brief Метод, для получения доступа к информации о 3д моделе
     * @return Ссылка на модель
    */
    Object& getObject() {
        return object;
    }

    /**
     * @brief Метод для очистки векторов вершин и полигонов (фасетов) 
     * @return void
    */
    void clearObject() {
        object.vertexes.clear();
        object.lines.clear();
    }

    /**
     * @brief Метод для считывания информации о 3д моделе из файла
     * @param filename путь до файла 
     * @return void
    */
    void parseFile(std::string filename) {
        model.parseFile(object, filename);
    }

private:
    Controller() = default;
    ~Controller() = default;
    
    Object object;
    ManipulationFacade model;
};
}

#endif // CPP4_3DVIEWER_V2_0_1_SRC_3D_CONTROLLER_HPP_
