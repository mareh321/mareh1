#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/**
 * @brief Считывает введённое с клавиатуры значение и проверяет на правильность ввода
 * @return введённое значение
 */
double getValue();

/**
 * @brief Проверяет, что левая граница меньше правой
 * @param min левая граница
 * @param max правая граница
 */
void check(const double min, const double max);

/**
 * @brief Проверяет, что число положительное
 * @param value проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Вычисляет коэффициент рекуррентного выражения
 * @param n текущий индекс
 * @param x значение параментра x
 * @return рассчитанное значение
 */
double Recurent(const int n, const double x);

/**
 * @brief Считает сумму членов последовательности с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);


/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите левую границу -  ");
    double min = getValue();
    printf("Введите правую границу -  ");
    double max = getValue();
    check(min, max);
    printf("Введите шаг -  ");
    double step = getValue();
    checkPositive(step);
    printf("Введите e -  ");
    double e = getValue();
    checkPositive(e);
    for (double x = min; x <= max ; x += step)
    {
        printf("x = %lf,(x) = %lf, S = %lf\n", x,x, getSumE(e, x));
    }
    return 0;
}

double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Ошибка, введено неверное значение!\n");
        exit(1);
    }
    return value;
}

void check(const double min, const double max)
{
    if (min >= max)
    {
        printf("Ошибка, левая граница должна быть меньше правой!\n");
        exit(1);
    }
}


void checkPositive(const double value)
{
    if (value <= 0)
    {
        printf("Ошибка, число должно быть положительным!\n");
        exit(1);
    }
}

double Recurent(const int n, const double x)
{
    return -pow(x, 2) / ((2.0 * n + 2.0) * (2.0 * n + 3.0));
}

double getSumE(const double e, const double x)
{
    double current = x;
    double res = current;
    for (int n = 0; fabs(current) > e; n++)
    {
        current *= Recurent(n, x);
        res += current;
    }
    return res;
}
