#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение
 * @return
 */
double getUravn(const double x);
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return заканчивает работу программы, если значение не подходит под условие
 */
void getProverka(const double x);
/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);
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

	checkStep(step);
	for (double i = start; i <= end + step; i += step) {
		if (log(i) <= 0) {
			printf("\nНет решения при значении x =");
			printf("%lf", i);
		}
		else {
			printf("\nПри х = %lf, значение функции = ", i);
			printf("%lf", getUravn(i));

		}
	}
}
double getUravn(const double x)
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
void getProverka(const double x) {
	if (log(x) <= 0) {
		printf("\nНет решения при значении x =");
		printf("%lf", x);
	}
}
void checkStep(const double step)
{
	if (step <= 0)
	{
		printf("\nОшибка, шаг должен быть положительным");
		abort();
	}
}
