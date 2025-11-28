#include <stdio.h>
#include <math.h>
#include <locale.h>
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
* @brief Рассчитывает площадь треугольника по заданой формуле
* param x - значение первой стороны
* param x - значение второй стороны
* return рассчитанная площадь
*/
double getThe_area_of_the_triangle(const double st1, const double st2);
/**
* @brief Рассчитывает площадь прямоугольника по заданой формуле
* param x - значение первой стороны
* param x - значение второй стороны
* return рассчитанная площадь
*/
double getRectangle_area(const double st1, const double st2);
/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main() {
    setlocale(LC_ALL, "Russian");
    printf("Первая сторона - ");
    double st1 = getValue();
    printf("Вторая сторона - ");
    double st2 = getValue();
    getThe_area_of_the_triangle(st1, st2);
    getRectangle_area(st1, st2);
    return 0;
}

double getThe_area_of_the_triangle(const double st1, const double st2) {
    printf("Площадь треугольника - ");
    printf("%.2lf", st1 * st2 * 0.5);

}

double getRectangle_area(const double st1, const double st2) {
    printf("\nПлощадь прямоугольника - ");
    printf("%.2lf", st1 * st2);

}

double getValue() {
    double value = 0;
    if (!scanf_s("%lf", &value)) {
        printf("----");
        abort();
    }
    else {
        return value;
    }
}
