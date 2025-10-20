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
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main() {
	setlocale(LC_ALL, "Russian");	
	double st1, st2, st3;
	
	printf("Первая сторона\n");
	double st1 = getValue();
	printf("Вторая сторона\n");
	double st2 = getValue();
	printf("Третья сторона\n");
	double st3 = getValue();
	if ((st1 > st2) && (st1 > st3)) {
		if (st1 == pow(((pow(st2, 2)) + (pow(st3, 2))), 0.5)) {
			printf("Треугольник прямоугольный и гипотенузой является первая сторона");
		}

	}
	else if ((st2 > st1) && (st2 > st3)) {
		if (st2 == pow(((pow(st1, 2)) + (pow(st3, 2))), 0.5)) {
			printf("Треугольник прямоугольный и гипотенузой является вторая сторона");
		}

	}
	else if ((st3 > st1) && (st3 > st2)) {
		if (st3 == pow(((pow(st1, 2)) + (pow(st2, 2))), 0.5)) {
			printf("Треугольник прямоугольный и гипотенузой является третья сторона");
		}
	}
	else {
		printf("Треугольник не прямоугольный");
	}
	
	return 0;
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
