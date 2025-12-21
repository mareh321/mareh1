#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>
#include <math.h>
/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value();
/**
 * @brief Проверяет корректность массива: что указатель не NULL и размер больше 0
 * @param arr массив
 * @param size размер массива
 */
void checkArray(const int* arr, const size_t size);
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
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);
/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */

enum { RANDOM = 1, MANUAL };
/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param size Размер массива
 * @return Полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет в массиве отрицательный элемент с максимальным модулем на 0
 * @param copyArr массив, в котором выполняется замена
 * @param size размер массива
 * @return 0, если программа выполнена корректно, иначе 1. 
 */
int replaceAbs(int* arr, const size_t size);

/**
 * @brief Вставляет число K между соседними элементами массива, если их знаки разные (0 считается неотрицательным)
 * @param copyArr исходный массив
 * @param size размер исходного массива
 * @param K число, которое необходимо вставлять
 * @param outSize указатель на переменную, в которую будет записан новый размер массива после вставок
 * @return новый массив с вставками (память выделяется внутри функции; освобождается вызывающей стороной через free)
 */
int* pasteK(int* copyArr, const size_t size, const int K, size_t* outSize);

/**
 * @brief Преобразует массив по параметру k: для первых k элементов заменяет значение на отрицательный квадрат, остальные уменьшает на 1
 * @param arr массив, который преобразуется
 * @param size размер массива
 * @param k количество первых элементов, к которым применяется преобразование (0 <= k <= size)
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int newmass(int* arr, const size_t size, const int k);
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
        exit(1);
    }
    printf("Введите число K - ");
    int K = Value();
    printf("\nИсходный массив - ");
    printArray(arr, size);
    printf("\nМассив после 1го действия - ");
    size_t newsize = 0;
    replaceAbs(arr, size);
    printArray(arr, size);
    printf("\nМассив после второго действия - ");
    int* tmp = pasteK(arr, size, K, &newsize);
    void checkArray(tmp, newsize);
    free(arr);
    arr = tmp;     
    printArray(arr, newsize);
    int* copyArr = copyArray(arr, newsize);
    printf("\nВведите число k - ");
    int k = Value();
    newmass(copyArr, newsize, k);
    printf("\nНовый массив с преобразованиемиями - ");
    printArray(copyArr, newsize);
    free(copyArr);
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
        printf("Введите %zu элемент списка = ", i);
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
int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    checkArray(copyArr, size);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}
int replaceAbs(int* arr, const size_t size)
{
    size_t index = 0;
    int max = 0;
    for (size_t i = 0; i < size; i++)
    {
        
        if ((arr[i] < 0 ) && (abs(arr[i]) > max))
        {
            max = abs(arr[i]);
            index = i;
        }
    }
    if (max != 0)
    {
        arr[index] = 0;
    }

    return 0;
}



int* pasteK(int* copyArr, const size_t size, const int K, size_t* outSize)
{
    if (!copyArr || !outSize)
    
        

    if (size < 2)
    {
        int* newarr = malloc(size * sizeof(int));
        if (!newarr) return NULL;

        if (size == 1) newarr[0] = copyArr[0];

        *outSize = size;
        return newarr;
    }

    
    size_t a = 0;
    int* b = calloc(size, sizeof(int));
    if (!b) 
    {
        return NULL;
    }
    for (size_t i = 0; i < size - 1; i++)
    {
        if (((copyArr[i] < 0) && (copyArr[i + 1] >= 0)) ||
            ((copyArr[i] >= 0) && (copyArr[i + 1] < 0)))
        {
            a += 1;
            b[i] = 1;
        }
    }
    size_t newsize = size + a;
    int* newarr = calloc(newsize, sizeof(int));
    if (!newarr)
    {
        free(b);
        return NULL;
    }
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        newarr[j++] = copyArr[i];

        if (i < size - 1 && b[i] == 1)
        {
            newarr[j++] = K;
        }
    }
    free(b);
    *outSize = j;
    return newarr;
}


int newmass(int* arr, const size_t size, const int k)
{
    if (k < 1 || k > size)
    {
        printf("Error\n");
        abort();

    }
    for (size_t i= 0; i < size; i++) 
    {
        if (i < k)
        {
            arr[i] = -(pow(arr[i],2));
        }
        else
        {
            arr[i] = arr[i] - 1;
        }
    }
    return 0;
}
void checkArray(const int* arr, const size_t size)
{
    if (arr == NULL)
    {
        printf("Error: массив не выделен (NULL)\n");
        abort();
    }
    if (size == 0)
    {
        printf("Error: размер массива равен 0\n");
        abort();
    }
}
