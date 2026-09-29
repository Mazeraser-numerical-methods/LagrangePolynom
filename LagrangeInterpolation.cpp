#include "LagrangeInterpolation.h"

/* 
* @brief Вычисляет коэффициент Лагранжа для i-й точки в точке x 
* 
* @param i Индекс точки, для которой строится коэффициент Лагранжа 
* @param x Аргумент, в котором вычисляется значение коэффициента Лагранжа 
* @return double Значение коэффициента Лагранжа l_i(x) 
* @throws std::runtime_error Если обнаруживаются совпадающие узлы 
*/ 
double LagrangeInterpolation::basisPolynomial(size_t i, double x) const { 
    double result = 1.0; 
    double xi = points[i].x; 
    for (size_t j = 0; j < points.size(); ++j) { 
        if (j == i) continue; 
        double xj = points[j].x; 
        // Проверка на совпадающие узлы (необходимо для корректности метода) 
        if (xi == xj) { 
            throw std::runtime_error("Обнаружены совпадающие узлы! Интерполяция невозможна."); 
        } 
        result *= (x - xj) / (xi - xj); 
    } 
    return result; 
} 

/** 
* @brief Конструктор класса интерполяции Лагранжа 
* 
* @param pts Вектор точек, через которые должен проходить полином 
* @throws std::invalid_argument Если вектор точек пуст 
*/ 
LagrangeInterpolation::LagrangeInterpolation(const std::vector<Point>& pts) : points(pts) { 
    if (points.empty()) { 
        throw std::invalid_argument("Вектор точек не может быть пустым"); 
    } 
    // Дополнительная проверка на совпадающие узлы при инициализации 
    for (size_t i = 0; i < points.size(); ++i) { 
        for (size_t j = i + 1; j < points.size(); ++j) { 
            if (points[i].x == points[j].x) { 
                throw std::invalid_argument("Обнаружены совпадающие узлы!"); 
            } 
        } 
    } 
} 

/** 
* @brief Вычисляет значение интерполяционного полинома Лагранжа в точке x 
* 
* @param x Аргумент, для которого вычисляется значение полинома 
* @return double Значение полинома L(x) 
*/ 
double LagrangeInterpolation::interpolate(double x) const { 
    double result = 0.0; 
    // Суммирование по всем узлам: L(x) = sum(y_i * l_i(x)) 
    for (size_t i = 0; i < points.size(); ++i) { 
        result += points[i].y * basisPolynomial(i, x); 
    } 
    return result; 
} 

/* 
* @brief Вычисляет значение полинома Лагранжа в точке x (перегруженная версия) 
* 
* Эта функция является синонимом interpolate() для удобства использования 
* 
* @param x Аргумент, для которого вычисляется значение полинома 
* @return double Значение полинома L(x) 
*/ 
double LagrangeInterpolation::operator()(double x) const { 
    return interpolate(x); 
} 

/* 
* @brief Получить количество точек интерполяции 
* @return size_t Количество точек 
*/ 
size_t LagrangeInterpolation::size() const { 
    return points.size(); 
}