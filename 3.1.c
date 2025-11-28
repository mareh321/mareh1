#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение
 * @return
 */
double getEquation(const double x);
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return выводит, что точка не подходит, если значение не подходит под условие
 */
int getCheck(const double x);
/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStepandGap(const double step, const double start, const double end);
/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
 */
int main() {
	setlocale(LC_ALL, "Russian");
	printf("ВВедите левую границу");
	double start = getValue();
	printf("Введите правую границу");
	double end = getValue();

	printf("Введите шаг, используя запятую, а не точку:");
	double step = getValue();

	checkStepandGap(step,start,end);
	for (double i = start; i <= end + step; i += step) {
		if (getCheck(i)) {
		}
		else {
			printf("\nПри х = %lf, значение функции = ", i);
			printf("%lf", getEquation(i));

		}
	}
}
double getEquation(const double x)
{
	return	(0.1 * pow(x, 2) - x * log(log(x)));
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
int getCheck(const double x) {
	if ((log(x) <= 0) || (x <= 0)) {
		printf("\nНет решения при значении x =");
		printf("%lf", x);
		return 1;
	}
	return 0;
}
void checkStepandGap(const double step, const double start, const double end)
{
	if ((step <= 0) || (start >= end))
	{
		printf("\nError");
		abort();
	}
}
