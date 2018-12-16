// ConsoleApplication14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <locale.h>

int main()
{
	int count ;
	int sr; 
	int i; //индекс массива
	int s, k; //номера элементов массива ввоимые пользователем
	int komanda = 0; //обработка массива
	int menu = 4; //выбор действия(главное меню)
	bool sizeEntered = false; //был ли задан размер массива
	bool wasFilled = false; //был ли массив заполнен
	char checking; //обработка вводимых данных
	int sizeofarray;
	int* mass = NULL;
	setlocale(LC_ALL, "Rus");

	do
	{
		//главное меню
		while (menu == 4)
		{
			printf("Главное меню:\n");
			printf("1) Заполнение массива\n");
			printf("2) Обработка массива\n");
			printf("3) Вывод массива\n");
			printf("0) Выход\n");
			printf("Выберете действие: ");

			while (scanf_s("%d%c", &menu, &checking, 1) != 2 || checking != '\n' || (menu != 1 && menu != 2 && menu != 3 && menu != 0))
			{
				printf("\nОшибка! Введите номер нужного действия: 1, 2, 3 или 0\n");
				printf("Действие ");
				while (getchar() != '\n');
			}
			system("cls");
		}
		//заполнение массива
		while (menu == 1)
		{
			komanda = -1;
			printf("Выберете способ заполнения массива:\n");
			printf("1. задать размер массива\n");
			printf("2. заполнить автоматически (случайными числами)\n");
			printf("3. заполнить вручную (с клавиатуры)\n");
			printf("0. Вернуться в Главное меню\n");

			while (scanf_s("%d%c", &komanda, &checking, 1) != 2 || checking != '\n' || (komanda != 1 && komanda != 2 && komanda != 3 && komanda != 0))
			{
				printf("Введите номер действия: 1, 2, 3 или 0!\n");
				while (getchar() != '\n');
			}
			system("cls");
			switch (komanda)
			{
			case 1:
				printf("Задайте размер массива: ");
				while (scanf_s("%d%c", &sizeofarray, &checking, 1) != 2 || checking != '\n' || sizeofarray <= 0)
				{
					printf("Размер массива должен быть выражен целым положительным чилом!\n");
					while (getchar() != '\n');
				}
				delete[] mass;
				mass = new int[sizeofarray]();
				sizeEntered = true;
				wasFilled = false;
				break;
			case 2:
				if (sizeEntered == false)
					printf("Сначала нужно задать размер массива\n\n");
				else
				{
					for (i = 0; i < sizeofarray; i++)
						mass[i] = rand();
					wasFilled = true;
					printf("Массив успешно заполнен\n");
					printf("Для вывода массива на экран нажмите 3\n");
					printf("Для выхода в Главное меню нажмите 4\n");
					while (scanf_s("%d%c", &menu, &checking, 1) != 2 || checking != '\n' || (menu != 3 && menu != 4))
					{
						printf("Введите цифру 3 или 4!\n");
						while (getchar() != '\n');
					}
					if (menu == 4)
						system("cls");
				}
				break;
			case 3:
				if (sizeEntered == false)
					printf("Сначала нужно задать размер массива\n\n");
				else
				{
					system("cls");
					for (i = 0; i < sizeofarray; i++)
					{
						printf("Элемент %d: ", i + 1);
						while (scanf_s("%d%c", &mass[i], &checking, 1) != 2 || checking != '\n')
						{
							printf("Массив должен состоять из целых чисел!\n");
							while (getchar() != '\n');
						}
					}
					wasFilled = true;
					printf("Массив успешно заполнен\n");
					printf("Для вывода массива на экран нажмите 3\n");
					printf("Для выхода в Главное меню нажмите 4\n");
					while (scanf_s("%d%c", &menu, &checking, 1) != 2 || checking != '\n' || (menu != 3 && menu != 4))
					{
						printf("Введите цифру 3 или 4!\n");
						while (getchar() != '\n');
					}
				}
				break;
			case 0:
				menu = 4;
				break;
			}
		}
		//работа с массивом
		while (menu == 2)
		{
			if (wasFilled == false)
			{
				printf("Сначала нужно заполнить массив!\n\n");
				menu = 1;
			}
			else
			{
				komanda = -1;
				while (komanda != 0)
				{
					printf("\nВыберете нужное действие\n");
					printf("1. Вывести колличество пятерок и четверок\n");
					printf("2. Найти средний балл\n");
					printf("0. Вернуться в главное меню\n");
					while (scanf_s("%d%c", &komanda, &checking, 1) != 2 && checking != '\n' || (komanda != 1 && komanda != 2 && komanda != 3 && komanda !=

						0))
					{
						printf("Введите номер действия: 1, 2, 3 или 0!\n");
						while (getchar() != '\n');
					}
					switch (komanda)
					{
					case 1:
						system("cls");
						printf("Вывести на экран колличество пятерок и четверок\n");
						count = 0;
						for (i=0; i < sizeofarray; i++)
						{
							if (mass[i] == 4 )
								count++;
							printf("%d", &count);
						}

							
						break;
					case 2:
						system("cls");
						sr = 0;
						printf("Найти средней балл\n");

						for (int i = 0; i<sizeofarray; i++)
						{
							sr += mass[i];
						}
						sr = sr / sizeofarray;
						printf("%d", &sr);
						break;
					case 0:
						system("cls");
						menu = 4;
						break;
					}
				}
			}
		}
		//вывод массива
		if (menu == 3)
		{
			if (wasFilled == false)
			{
				printf("Сначала нужно заполнить массив!\n\n");
				menu = 1;
			}
			else
			{
				system("cls");
				printf("Массив из %d чисел: ", sizeofarray);
				for (int i = 0; i < sizeofarray; i++)
					printf("%d ", mass[i]);
				printf("\n");
				menu = 4;
			}
		}
		//выход
		if (menu == 0)
		{
			printf("Вы уверены, что хотие выйти?\n");
			printf("1. Да 2.Нет\n");
			while (scanf_s("%d%c", &komanda, &checking, 1) != 2 && checking != '\n' || (komanda != 1 && komanda != 2))
			{
				printf("Введите номер действия: 1 или 2!\n");
				while (getchar() != '\n');
			}
			if (komanda == 2)
			{
				system("cls");
				menu = 4;
			}
		}
	} while (menu != 0);
	delete[] mass;
	return 0;
}