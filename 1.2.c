#include <stdio.h>
#include <math.h>
#include <locale.h>
/**
* @brief Рассчитывает площадь треугольника по заданой формуле
* param st1 - значение первой стороны 
* param st2 - значение второй стороны
* return рассчитанная площадь
*/
double getA(double st1, double st2);
/**
* @brief Рассчитывает площадь прямоугольника по заданой формуле
* param x - значение первой стороны
* param x - значение второй стороны
* return рассчитанная площадь
*/
double getB(double st1, double st2);
/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main() {
    setlocale(LC_ALL, "Russian");
    double st1, st2;

    printf("Первая сторона - ");
    scanf_s("%lf", &st1);

    printf("Вторая сторона - ");
    scanf_s("%lf", &st2);
    getA(st1, st2);
    getB(st1, st2);
    
}

double getA(double st1, double st2) {
    printf("Площадь треугольника - ");
    printf("%.2lf", st1 * st2 * 0.5);
    return 0;
}

double getB(double st1, double st2) {
    printf("Площадь прямоугольника - ");
    printf("%.2lf", st1 * st2);
    return 0;
}
