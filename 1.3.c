#include <stdio.h>
#include <math.h>
#include <locale.h>
/**
* @brief Рассчитывает время по заданной формуле
* param R - значение сопротивления
* param I - значение силы тока
* param Q - значение
* return рассчитанная площадь
*/
double getZakonOma(const double R,const double I,const double Q);
/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main() {
	setlocale(LC_ALL, "Russian");
	double R = 0, I = 0, Q = 0;
	printf("Сопротивление -");
	scanf_s("\n%lf", &R);
	printf("Сила тока -");
	scanf_s("\n%lf", &I);
	printf("Количество теплоты -");
	scanf_s("%lf", &Q);
	printf("%.2lf",getZakonOma(R, I, Q));
	return 0;
}
double getZakonOma(const double R,const double I,const double Q){
	return ((Q*I*I)/R);
}
