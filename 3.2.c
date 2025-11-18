#include <stdio.h>
#include <locale.h>
#include <math.h>
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief рассчитывает сумму рекурсивной функции  по заданной формуле и переменной
 * @param k переменная
 * @return сумма
 */
double getRekurs(const double k);
/**
 * @brief рассчитывает фактариал числа
 * @param r число
 * @return фактариал числа
 */
double getFact(const double r);
/**
* @brief точка входа в программу
* @return возврат 0 в случае если программа работает правиьлно
 */
int main() {
	setlocale(LC_ALL, "Russian");
	printf("Введите переменную n - ");
	double n = getValue();
	printf("%lf", getRekurs(n));
	return 0;

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
double getFact(const double r) {
	if (r == 1.0) {
		return 1;
	}
	return r * getFact(r - 1);
}

double getRekurs(const double k) {
	if (k == 0) {
		return 0;
	}
	return ((pow(-1, k) * k) / getFact(k)) + getRekurs(k - 1);
}
