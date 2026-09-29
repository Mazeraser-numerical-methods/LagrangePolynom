#ifndef LAGRANGE_INTERPOLATION_H
#define LAGRANGE_INTERPOLATION_H

#include <vector>
#include <stdexcept>
#include "Point.h"

/* 
* @brief Класс для интерполяции полиномом Лагранжа 
* 
* Реализует построение интерполяционного полинома Лагранжа по набору точек. 
* 
* Полином имеет вид: L(x) = sum(y_i * l_i(x)), где l_i(x) - базисные полиномы. 
*/ 
class LagrangeInterpolation { 
private: 

    std::vector<Point> points; // Исходные точки для интерполяции 

    /* 
    * @brief Вычисляет коэффициент Лагранжа для i-й точки в точке x 
    * 
    * @param i Индекс точки, для которой строится коэффициент Лагранжа 
    * @param x Аргумент, в котором вычисляется значение коэффициента Лагранжа 
    * @return double Значение коэффициента Лагранжа l_i(x) 
    * @throws std::runtime_error Если обнаруживаются совпадающие узлы 
    */ 
    double basisPolynomial(size_t i, double x) const; 

public: 

    /** 
    * @brief Конструктор класса интерполяции Лагранжа 
    * 
    * @param pts Вектор точек, через которые должен проходить полином 
    * @throws std::invalid_argument Если вектор точек пуст 
    */ 
    LagrangeInterpolation(const std::vector<Point>& pts); 

    /** 
    * @brief Вычисляет значение интерполяционного полинома Лагранжа в точке x 
    * 
    * @param x Аргумент, для которого вычисляется значение полинома 
    * @return double Значение полинома L(x) 
    */ 
    double interpolate(double x) const; 

    /* 
    * @brief Вычисляет значение полинома Лагранжа в точке x (перегруженная версия) 
    * 
    * Эта функция является синонимом interpolate() для удобства использования 
    * 
    * @param x Аргумент, для которого вычисляется значение полинома 
    * @return double Значение полинома L(x) 
    */ 
    double operator()(double x) const; 

    /* 
    * @brief Получить количество точек интерполяции 
    * @return size_t Количество точек 
    */ 
    size_t size() const; 
};

#endif // LAGRANGE_INTERPOLATION_H