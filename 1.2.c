#include <stdio.h>
#include <math.h>
#include <locale.h>
/**
* @brief Рассчитывает площадь треугольника по заданой формуле
* param x - значение первой стороны 
* param x - значение второй стороны
* return рассчитанная площадь
*/
double getPloshad_treug(const double st1,const double st2);
/**
* @brief Рассчитывает площадь прямоугольника по заданой формуле
* param x - значение первой стороны
* param x - значение второй стороны
* return рассчитанная площадь
*/
double getPloshad_pryamoug(const double st1,const double st2);
/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main() {
    setlocale(LC_ALL, "Russian");
    double st1 = 0, st2 = 0;

    printf("Первая сторона - ");
    scanf_s("%lf", &st1);

    printf("Вторая сторона - ");
    scanf_s("%lf", &st2);
    getA(st1, st2);
    getB(st1, st2);
    
}

double getPloshad_treug(const double st1,const double st2) {
    printf("Площадь треугольника - ");
    printf("%.2lf", st1 * st2 * 0.5);
    
}

double getPloshad_pryamoug(const double st1,const double st2) {
    printf("Площадь прямоугольника - ");
    printf("%.2lf", st1 * st2);
    
}
