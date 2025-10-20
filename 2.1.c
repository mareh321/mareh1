#include <stdio.h>
#include <math.h>
/**
* @brief Рассчитывает среднее арифметическое кубов этих чисел
* param number1 - значение первого числа
* param number2 - значение второго числа
* return рассчитанное значение
*/
double getSrArifm(const double number1,const double number2);
/**
* @brief Рассчитывает геометрическое модулей этих чисел
* param number1 - значение первого числа
* param number2 - значение второго числа
* return рассчитанное значение
*/
double getSrGeom(const double number1,const double number2);
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
    double const number1, number2;

    printf("Введите первое число: ");
    double number1 = getValue();


    printf("Введите второе число: ");
    double number2 = getValue();

    printf("%lf\n", getA(number1, number2));
    printf("%lf\n", getB(number1, number2));
    return 0;
}

double getSrArifm(double number1, double number2) {
    printf("Среднее арифметическое кубов этих чисел: ");
    return (pow(number1, 3) + pow(number2, 3)) / 2.0;
}
double getSrGeom(double number1, double number2) {
    printf("Среднее геометрическое модулей этих чисел: ");
    return pow(fabs(number1 * number2), 0.5);
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
