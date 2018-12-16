// ConsoleApplication14.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	int i; //������ �������
	int s, k; //������ ��������� ������� ������� �������������
	int komanda = 0; //��������� �������
	int menu = 4; //����� ��������(������� ����)
	bool sizeEntered = false; //��� �� ����� ������ �������
	bool wasFilled = false; //��� �� ������ ��������
	char checking; //��������� �������� ������
	int sizeofarray;
	int* mass = NULL;
	setlocale(LC_ALL, "Rus");

	do
	{
		//������� ����
		while (menu == 4)
		{
			printf("������� ����:\n");
			printf("1) ���������� �������\n");
			printf("2) ��������� �������\n");
			printf("3) ����� �������\n");
			printf("0) �����\n");
			printf("�������� ��������: ");

			while (scanf_s("%d%c", &menu, &checking, 1) != 2 || checking != '\n' || (menu != 1 && menu != 2 && menu != 3 && menu != 0))
			{
				printf("\n������! ������� ����� ������� ��������: 1, 2, 3 ��� 0\n");
				printf("�������� ");
				while (getchar() != '\n');
			}
			system("cls");
		}
		//���������� �������
		while (menu == 1)
		{
			komanda = -1;
			printf("�������� ������ ���������� �������:\n");
			printf("1. ������ ������ �������\n");
			printf("2. ��������� ������������� (���������� �������)\n");
			printf("3. ��������� ������� (� ����������)\n");
			printf("0. ��������� � ������� ����\n");

			while (scanf_s("%d%c", &komanda, &checking, 1) != 2 || checking != '\n' || (komanda != 1 && komanda != 2 && komanda != 3 && komanda != 0))
			{
				printf("������� ����� ��������: 1, 2, 3 ��� 0!\n");
				while (getchar() != '\n');
			}
			system("cls");
			switch (komanda)
			{
			case 1:
				printf("������� ������ �������: ");
				while (scanf_s("%d%c", &sizeofarray, &checking, 1) != 2 || checking != '\n' || sizeofarray <= 0)
				{
					printf("������ ������� ������ ���� ������� ����� ������������� �����!\n");
					while (getchar() != '\n');
				}
				delete[] mass;
				mass = new int[sizeofarray]();
				sizeEntered = true;
				wasFilled = false;
				break;
			case 2:
				if (sizeEntered == false)
					printf("������� ����� ������ ������ �������\n\n");
				else
				{
					for (i = 0; i < sizeofarray; i++)
						mass[i] = rand();
					wasFilled = true;
					printf("������ ������� ��������\n");
					printf("��� ������ ������� �� ����� ������� 3\n");
					printf("��� ������ � ������� ���� ������� 4\n");
					while (scanf_s("%d%c", &menu, &checking, 1) != 2 || checking != '\n' || (menu != 3 && menu != 4))
					{
						printf("������� ����� 3 ��� 4!\n");
						while (getchar() != '\n');
					}
					if (menu == 4)
						system("cls");
				}
				break;
			case 3:
				if (sizeEntered == false)
					printf("������� ����� ������ ������ �������\n\n");
				else
				{
					system("cls");
					for (i = 0; i < sizeofarray; i++)
					{
						printf("������� %d: ", i + 1);
						while (scanf_s("%d%c", &mass[i], &checking, 1) != 2 || checking != '\n')
						{
							printf("������ ������ �������� �� ����� �����!\n");
							while (getchar() != '\n');
						}
					}
					wasFilled = true;
					printf("������ ������� ��������\n");
					printf("��� ������ ������� �� ����� ������� 3\n");
					printf("��� ������ � ������� ���� ������� 4\n");
					while (scanf_s("%d%c", &menu, &checking, 1) != 2 || checking != '\n' || (menu != 3 && menu != 4))
					{
						printf("������� ����� 3 ��� 4!\n");
						while (getchar() != '\n');
					}
				}
				break;
			case 0:
				menu = 4;
				break;
			}
		}
		//������ � ��������
		while (menu == 2)
		{
			if (wasFilled == false)
			{
				printf("������� ����� ��������� ������!\n\n");
				menu = 1;
			}
			else
			{
				komanda = -1;
				while (komanda != 0)
				{
					printf("\n�������� ������ ��������\n");
					printf("1. ������� ����������� ������� � ��������\n");
					printf("2. ����� ������� ����\n");
					printf("0. ��������� � ������� ����\n");
					while (scanf_s("%d%c", &komanda, &checking, 1) != 2 && checking != '\n' || (komanda != 1 && komanda != 2 && komanda != 3 && komanda !=

						0))
					{
						printf("������� ����� ��������: 1, 2, 3 ��� 0!\n");
						while (getchar() != '\n');
					}
					switch (komanda)
					{
					case 1:
						system("cls");
						printf("������� �� ����� ����������� ������� � ��������\n");
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
						printf("����� ������� ����\n");

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
		//����� �������
		if (menu == 3)
		{
			if (wasFilled == false)
			{
				printf("������� ����� ��������� ������!\n\n");
				menu = 1;
			}
			else
			{
				system("cls");
				printf("������ �� %d �����: ", sizeofarray);
				for (int i = 0; i < sizeofarray; i++)
					printf("%d ", mass[i]);
				printf("\n");
				menu = 4;
			}
		}
		//�����
		if (menu == 0)
		{
			printf("�� �������, ��� ����� �����?\n");
			printf("1. �� 2.���\n");
			while (scanf_s("%d%c", &komanda, &checking, 1) != 2 && checking != '\n' || (komanda != 1 && komanda != 2))
			{
				printf("������� ����� ��������: 1 ��� 2!\n");
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