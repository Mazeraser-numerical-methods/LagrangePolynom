#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "LagrangeInterpolation.h"

/*
* @brief Пример использования интерполяции Лагранжа
*
* Демонстрирует построение полинома по точкам из учебного пособия
* и вычисление значения в заданной точке
*/
int main() {
    try {
        // --- Пример 3 из учебного пособия (Таблица 3) ---
        // Точки: (-2, -4), (-1, 0), (1.2, 3.8), (3.5, -2), (5, 7)
        std::vector<Point> points1 = {
            {-2.0, -4.0},
            {-1.0, 0.0},
            {1.2, 3.8},
            {3.5, -2.0},
            {5.0, 7.0}
        };
        std::cout << "=== Пример 3: Интерполяция по 5 точкам ===" << std::endl;
        std::cout << "Точки:" << std::endl;
        for (const auto& p : points1) {
            std::cout << " (" << p.x << ", " << p.y << ")" << std::endl;
        }
        LagrangeInterpolation lagrange1(points1);
        std::cout << "Степень полинома: " << lagrange1.size() - 1 << std::endl << std::endl;
        // Вычисление значения полинома в нескольких точках
        std::vector<double> testPoints = {0.0, 2.0, 4.0};
        std::cout << "Значения полинома в точках:" << std::endl;
        for (double x : testPoints) {
            double y = lagrange1.interpolate(x);
            std::cout << " L(" << x << ") = " << y << std::endl;
        }
        // Проверка прохождения через узлы
        std::cout << "\nПроверка прохождения через узлы:" << std::endl;
        for (const auto& p : points1) {
            double y = lagrange1.interpolate(p.x);
            std::cout << " L(" << p.x << " ) = " << y << std::endl;
        }
        std::cout << "\n" << std::string(50, '=') << std::endl;
        // --- Пример с большим количеством точек (синусоида) ---
        std::cout << "=== Дополнительный пример: интерполяция синусоиды ===" << std::endl;
        std::vector<Point> points2;
        for (int i = 0; i <= 6; ++i) {
            double x = i * 0.5; // Шаг 0.5
            points2.push_back({x, std::sin(x)});
        }
        std::cout << "Построение полинома по 7 точкам на интервале [0, 3]" << std::endl;
        std::cout << "Степень полинома: " << points2.size() - 1 << std::endl << std::endl;
        LagrangeInterpolation lagrange2(points2);
        // Вычисление значений в промежуточных точках
        std::cout << "Сравнение значений:" << std::endl;
        std::cout << " x\t\tL(x)\t\ttsin(x)\t\tПогрешность" << std::endl;
        for (double x = 0.0; x <= 3.0; x += 0.1) {
            double interpolated = lagrange2.interpolate(x);
            double exact = std::sin(x);
            double error = std::abs(interpolated - exact);
            std::cout << " " << x << "\t\t" << interpolated << "\t\t" << exact << "\t\t" << error << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}