#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value();   

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);
/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);
/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(int* arr, const size_t size);
/**
 * @brief считает количество цифр в массиве, которые не больше числа А и положительны
 * @param A число вводимое пользователем
 * @param arr массив
 * @param size размер массива
 * @return Возвращает количество найденных чисел
 */
int Quantity(int* arr, const size_t size, double A);
/**
 * @brief Считает сумму всех отрицательных чисел в массиве
 * @param arr массив
 * @param size размер массива
 * @return полученная сумма
 */
int sumOtric(int* arr, const size_t size);
/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);
/**
 * @brief Находит индекс последней пары с разными знаками
 */
void Number(int* arr, const size_t size);
/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum { RANDOM = 1, MANUAL };
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main() 
{
    setlocale(LC_ALL, "Russian");
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
        "%d случайными числами \n%d вручную\nВыбор -   ", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        printf("error");
        free(arr);
        break;
        exit(1);
    }
    printf("\nИсходный массив - ");
    printArray(arr, size);
    printf("\nВведите число A - ");
    int A = Value();
    printf("\nКолличество чисел <= A и > 0 - %d", Quantity(arr, size, A));
    printf("\nСумма отриц - %d", sumOtric(arr, size));
    Number(arr, size);

    printf("\n");
 
    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите %d элемент списка = ", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Quantity(int* arr, const size_t size, double A)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] <= A) {
            result += 1;
        }
        
    }
    return result;
}


int sumOtric(int* arr, const size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            result += arr[i];
        }
    }
    return result;
}

void fillRandom(int* arr, const size_t size)
{
    printf("Левая граница ");
    int start = Value();
    printf("Правая граница ");
    int end = Value();
    if (start > end) {
        printf("Левая граница больше правой !\nError");
        abort();
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

void Number(const int* arr, const size_t size)
{
    int res = -5;
    for (size_t i = 0; i < size-1; i++)
    {
        if ((arr[i] < 0 && arr[i+1] >= 0) || (arr[i+1] < 0 && arr[i] >= 0)) {
            res = i;
        }
        
    }
    if (res == -5){
        printf("\nПар с разными знаками нет");
        
    }
    else {
        printf("\nНомер последних элементов с разными знаками - %d", res);
    }
    
}
