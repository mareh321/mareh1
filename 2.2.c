#include <stdio.h>
#include <math.h>
#include <locale.h>
/**
* @brief Рассчитывает функцию по заданному числу и константе 
* param numb1 - значение заданного числа
* return рассчитанное значение
*/
double getRezultat(double numb1);
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
int main() {
	setlocale(LC_ALL, "Russian");
	printf("Введите ваше число -\n");
	double numb1 = getValue();
	if ((numb1 < 4.0 * 2.1 * numb1 + pow(numb1, 3)) && (numb1 >= 4)) {
		printf("%lf", getRezultat(numb1));
	}
	else {
		printf("Не подходит по условию");
	}
	return 0;
}
double getRezultat(double numb1){
	printf("Ответ -\n");
	return ((2.1/numb1) + pow(numb1,2));
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

