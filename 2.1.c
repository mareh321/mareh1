#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
/**
* @brief Рассчитывает среднее арифметическое кубов этих чисел
* param number1 - значение первого числа
* param number2 - значение второго числа
* return рассчитанное значение
*/
double getSrArifm(const double number1, const double number2);
/**
* @brief Рассчитывает геометрическое модулей этих чисел
* param number1 - значение первого числа
* param number2 - значение второго числа
* return рассчитанное значение
*/
double getSrGeom(const double number1, const double number2);
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main() {
    setlocale(LC_ALL, "Russian");
    printf("Введите первое число: ");
    double number1 = getValue();


    printf("Введите второе число: ");
    double number2 = getValue();

    printf("%lf\n", getSrArifm(number1, number2));
    printf("%lf\n", getSrGeom(number1, number2));
    return 0;
}

double getSrArifm(const double number1, const double number2) {
    printf("Среднее арифметическое кубов этих чисел: ");
    return ((pow(number1, 3) + pow(number2, 3)) / 2.0);
}
double getSrGeom(const double number1, const double number2) {
    printf("Среднее геометрическое модулей этих чисел: ");
    return sqrt(fabs(number1) * fabs(number2));
}
double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
