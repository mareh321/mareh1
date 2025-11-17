#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
double getUravn(const double x);
double getValue();
void getProverka(const double x);
void checkStep(const double step);
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
