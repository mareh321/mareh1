#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value();

/**
 * @brief Считывает введённое с клавиатуры вещественное значение и проверяет на правильность ввода
 * @return введённое значение
 */
double getValue();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return сумма
 */
double SumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности, с учетом e
 * @param e - заданное число
 * @return сумма
 */
double SumE(const double e);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double Recurent(const int i);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double i);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите n:");
    int n = Value();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %lf\n", n, SumN(n));
    printf("*Вместо '.' используйте ','\nВведите e:");
    double e = getValue();
    checkPositive(e);
    printf("Сумма последовательности с учетом числа e равна %lf\n",  SumE(e));

    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double SumN(const int n)
{
    if (n == 0)
        return 0.0;

    double current = -1.0;
    double result = current;
    for (int i = 1; i <= n; ++i)
    {
        current *= Recurent(i);
        result += current;
    }

    return result;
}
double SumE(const double e)
{
    double current = -1.0;
    double result = 0;
    for (int i = 1; fabs(current) > e; i++)
    {
        result += current;
        current *= Recurent(i);
    }
    return result;
}

double Recurent(const int i)
{

    return -1.0 / i;
}

void checkPositive(const double i)
{
    if (i <= 0)
    {
        printf("Ошибка, число должно быть положительным!\n");
        exit(1);
    }
}

