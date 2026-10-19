#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "LagrangeInterpolation.h"

int main() {
    try {
        const int W = 70;
        std::cout << std::string(W, '=') << "\n"
                  << std::setw((W + 40) / 2) << "Лабораторная работа №2. Полином Лагранжа\n"
                  << std::string(W, '=') << "\n\n";

        std::vector<Point> points;
        int n;
        std::cout << "Введите количество точек: ";
        std::cin >> n;

        std::cout << "\n" << std::string(W, '-') << "\n"
                  << std::left  << std::setw(6)  << "№"
                  << std::right << std::setw(15) << "x"
                  << std::right << std::setw(15) << "y" << "\n"
                  << std::string(W, '-') << "\n";

        std::cout << std::fixed << std::setprecision(2);
        for (int i = 0; i < n; ++i) {
            double x = std::rand() % 100;
            double y = std::rand() % 100;
            points.push_back({x, y});
            std::cout << std::left  << std::setw(6)  << i + 1
                      << std::right << std::setw(15) << x
                      << std::right << std::setw(15) << y << "\n";
        }
        std::cout << std::string(W, '-') << "\n\n";

        LagrangeInterpolation lagrange(points);

        std::cout << "Степень полинома: " << lagrange.size() - 1 << "\n\n";

        std::vector<double> testPoints = {0.0, 2.0, 4.0};
        std::cout << std::string(W, '-') << "\n"
                  << std::left  << std::setw(20) << "Тестовая точка x"
                  << std::right << std::setw(20) << "L(x)" << "\n"
                  << std::string(W, '-') << "\n";

        std::cout << std::fixed << std::setprecision(6);
        for (double x : testPoints) {
            double y = lagrange.interpolate(x);
            std::cout << std::left  << std::setw(20) << x
                      << std::right << std::setw(20) << y << "\n";
        }
        std::cout << std::string(W, '-') << "\n\n";

        // Проверка прохождения через узлы
        std::cout << std::string(W, '-') << "\n"
                  << std::left  << std::setw(6)  << "№"
                  << std::right << std::setw(15) << "x (узел)"
                  << std::right << std::setw(15) << "y (узел)"
                  << std::right << std::setw(15) << "L(x)" << "\n"
                  << std::string(W, '-') << "\n";

        int idx = 1;
        for (const auto& p : points) {
            double y = lagrange.interpolate(p.x);
            std::cout << std::left  << std::setw(6)  << idx++
                      << std::right << std::setw(15) << p.x
                      << std::right << std::setw(15) << p.y
                      << std::right << std::setw(15) << y << "\n";
        }
        std::cout << std::string(W, '-') << "\n";

        std::cout << "\n" << std::string(W, '=') << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}