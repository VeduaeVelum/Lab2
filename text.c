# Lab2
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#define SYSTEM_NO_WARNINGS

void clean_stdin(void);
int input_data_of_children(int element);
int check_year(int element);
int check_string(char *massive);
void func_input(int element);
int check_flag(void);
int check_number_of_hospital(int element);
int func_repeat(int element);
void sort_surnames(int element);
void func_output(int element);
void func_statistic(int element);

struct union_children
{
	char *surname_child;
	char *disease;
	char *surname_doctor1;
	char *surname_doctor2;
	char *name_of_street;
	int birthday;
	int number_of_house;
	int number_hosp;
}*str;
struct data_children
{
	char *disease;
	char *surname_child;
	int birthday;
}*cls;

int main()
{
	int number_of_children = 0, repeat = 0;
	do
	{
		number_of_children = input_data_of_children(number_of_children);
		func_input(number_of_children);
		sort_surnames(number_of_children);
		func_output(number_of_children);
		repeat = func_repeat(repeat);
	} while (repeat == 1);
	return 0;
}

void func_input(int element)
{
	int i = 0, flag = 0;
	str = (struct union_children*)calloc(element, sizeof(struct union_children));
	if (!str)
	{
		printf("\nMemory hasn't desinged\n");
	}
	cls = (struct data_children*)calloc(element, sizeof(struct data_children));
	if (!cls)
	{
		printf("\nMemory hasn't desinged\n");
		free(str);
	}
	for (i = 0; i < element; i++)
	{
		str[i].disease = (char*)calloc(50, sizeof(char));
		str[i].surname_doctor1 = (char*)calloc(50, sizeof(char));
		str[i].surname_doctor2 = (char*)calloc(50, sizeof(char));
		str[i].name_of_street = (char*)calloc(50, sizeof(char));
		str[i].surname_child = (char*)calloc(50, sizeof(char));
		cls[i].disease = (char*)calloc(50, sizeof(char));
		cls[i].surname_child = (char*)calloc(50, sizeof(char));
	}
	printf("Input information of children:\n");
	for (i = 0; i < element; i++)
	{
		printf("\tInput year of birthday(for example 1990): ");
		str[i].birthday = check_year(str[i].birthday);
		printf("\tInput surname of the %d children: ", i + 1);
		do
		{
			scanf("%s", str[i].surname_child);
			clean_stdin();
			flag = check_string(str[i].surname_child);
		} while (flag == 1);
		printf("\tInput desease of the %d children: ", i + 1);
		do
		{
			scanf("%s", str[i].disease);
			clean_stdin();
			flag = check_string(str[i].disease);
		} while (flag == 1);
		printf("\tInput surname of district doctor of this kid: ");
		do
		{
			scanf("%s", str[i].surname_doctor1);
			clean_stdin();
			flag = check_string(str[i].surname_doctor1);
		} while (flag == 1);
		printf("\tDid this kid was in the hospital? - press 1 if you want or 2 if don't: ");
		flag = check_flag();
		switch (flag)
		{
		case 1:
			printf("\tInput number of hospital: ");
			str[i].number_hosp = check_number_of_hospital(str[i].number_hosp);
			printf("\tInput addres of the hospital\n");
			printf("\t\tName of street: ");
			do
			{
				scanf("%s", str[i].name_of_street);
				clean_stdin();
				flag = check_string(str[i].name_of_street);
			} while (flag == 1);
			printf("\t\tNumber of house: ");
			str[i].number_of_house = check_number_of_hospital(str[i].number_of_house);
			printf("\t\tSurname of doctor in charge: ");
			do
			{
				scanf("%s", str[i].surname_doctor2);
				clean_stdin();
				flag = check_string(str[i].surname_doctor2);
			} while (flag == 1);
			printf("Thanks for information\n");
			break;
		case 2:
			printf("Thanks for information\n");
			break;
		default:
			printf("Programm will continue\n");
			break;
		}
		printf("\n");
	}
}
int input_data_of_children(int element)
{
	int element1;
	printf("Puts number of sick children: ");
	do
	{
		element1 = scanf("%d", &element);
		clean_stdin();
		if (element1 != 1 || element < 1 || element > 20)
		{
			printf("Incorrect input! Use number from 1 to 20: ");
		}
	} while (element1 != 1 || element < 1 || element > 20);
	return element;
}
int check_year(int element)
{
	int element1 = 0;
	signed int old = 0;
	do
	{
		element1 = scanf("%d", &element);
		clean_stdin();
		old = 2015 - element;
		if (element1 != 1 || old >= 18 || old <= 0)
		{
			printf("\tIncorrect input! This person are not a child or not borning: ");
		}
	} while (element1 != 1 || (old >= 18 || old <= 0));
	return element;
}
int check_string(char *massive)
{
	char c = 0;
	int i = 0, n = 0, flag = 0;
	n = strlen(massive);
	for (i = 0; i < n; i++)
	{
		c = massive[i];
		if (c > '0' && c < '9')
		{
			printf("\t\tThere are numbers in string, input in again: ");
			flag = 1;
			return flag;
		}
	}
	return flag;
}
int check_flag(void)
{
	int element = 0, element1 = 0;
	do
	{
		element1 = scanf("%d", &element);
		clean_stdin();
		if (element1 != 1)
		{
			printf("\n\t\tInvalid input, try again: ");
		}
		else if (element < 1 || element > 2)
		{
			printf("\n\t\tInvalid input, try again: ");
		}
		else break;
	} while (1);
	return element;
}
int check_number_of_hospital(int element)
{
	int element1 = 0;
	do
	{
		element1 = scanf("%d", &element);
		clean_stdin();
		if (element1 != 1 || element < 1 || element > 99999999)
		{
			printf("\tIncorrect input! Try again: ");
		}
	} while (element1 != 1 || element < 1 || element > 99999999);
	return element;
}
void sort_surnames(int element)
{
	char *massive2 = { NULL };
	int i = 0, j = 0, bubble = 0;
	massive2 = (char*)calloc(15, sizeof(char));
	if (!massive2)
	{
		printf("\nMemory hasn't desinged\n");
		for (i = 0; i < element; i++)
		{
			if (str[i].surname_doctor2 != NULL)
			{
				free(str[i].surname_doctor2);
			}
			if (str[i].name_of_street != NULL)
			{
				free(str[i].name_of_street);
			}
			free(str[i].disease);
			free(str[i].surname_doctor1);
			free(cls[i].disease);
			free(cls[i].surname_child);
		}
		free(str); free(cls);
	}
	for (i = 0; i < element; i++)
	{
		strcpy(cls[i].surname_child, str[i].surname_child);
		strcpy(cls[i].disease, str[i].disease);
		cls[i].birthday = str[i].birthday;
	}
	for (i = 0; i < (element - 1); i++)
	{
		for (j = 1; j < element; j++)
		{
			if ((strcmp(cls[i].surname_child, cls[j].surname_child) > 0))
			{
				strcpy(massive2, cls[i].surname_child);
				strcpy(cls[i].surname_child, cls[j].surname_child);
				strcpy(cls[j].surname_child, massive2);
				strcpy(massive2, cls[i].disease);
				strcpy(cls[i].disease, cls[j].disease);
				strcpy(cls[j].disease, massive2);
				bubble = cls[i].birthday;
				cls[i].birthday = cls[j].birthday;
				cls[j].birthday = bubble;
			}
		}
	}
	free(massive2);
}
void clean_stdin(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
void func_output(int element)
{
	int i = 0, n, flag = 0, temp = 0;
	char *massive = { NULL };
	do
	{
		massive = (char*)calloc(15, sizeof(char));
		n = 0;
		if (!massive)
		{
			printf("\nMemory hasn't desinged\n");
			for (i = 0; i < element; i++)
			{
				if (str[i].surname_doctor2 != NULL)
				{
					free(str[i].surname_doctor2);
				}
				if (str[i].name_of_street != NULL)
				{
					free(str[i].name_of_street);
				}
				free(str[i].surname_child);
				free(str[i].disease);
				free(str[i].surname_doctor1);
				free(cls[i].disease);
				free(cls[i].surname_child);
			}
			free(str); free(cls);
		}
		printf("\nPlease choose desiase: ");
		do
		{
			scanf("%s", massive);
			for (i = 0; i < element; i++)
			{
				temp = strcmp(massive, str[i].disease);
				if (temp == 0)
				{
					n = 1;
					break;
				}
			}
			if (n == 0)
			{
				printf("This disease aren't in the list. Input again: ");
			}
		} while (n == 0);
		if (n != 0)
		{
			clean_stdin();
		}
		printf("Children with %s sickness are: \n", massive);
		for (i = 0; i < element; i++)
		{
			if (strcmp(cls[i].disease, massive) == 0)
			{
				printf("\t%s\t%d\n", cls[i].surname_child, cls[i].birthday);
			}
		}
		printf("\nDo you want to output children with another sickness? - press 1 if you want or 2 if don't: ");
		free(massive);
		flag = check_flag();
	} while (flag == 1);
	printf("Do you want to output statistic of sickness? - press 1 if you want or 2 if don't: ");
	flag = check_flag();
	if (flag == 1)	func_statistic(element);
	do
	{
		printf("Do you want to output statistic of sickness of another year? - press 1 if you want or 2 if don't: ");
		flag = check_flag();
		if (flag == 1)	func_statistic(element);
	} while (flag == 0);
	for (i = 0; i < element; i++)
	{
		if (str[i].surname_doctor2 != NULL)
		{
			free(str[i].surname_doctor2);
		}
		if (str[i].name_of_street != NULL)
		{
			free(str[i].name_of_street);
		}
		free(str[i].surname_child);
		free(str[i].disease);
		free(str[i].surname_doctor1);
		free(cls[i].disease);
		free(cls[i].surname_child);
	}	
	free(cls); free(str);
}
void func_statistic(int element)
{
	int i = 0, year = 0, temp = 0;
	float persent = 0;
	printf("\nChoose the year of statistic: ");
	year = check_year(year);
	for (i = 0; i < element; i++)
	{
		if (year == cls[i].birthday)
		{
			temp++;
		}
	}
	if (temp == 0) printf("\nThere fre not children of this year of birthday");
	persent = (float)temp;
	persent /= element;
	persent *= 100;
	printf("\nPersent of sick children of the %2d year are %2.3f%%\n", year, persent);
}
int func_repeat(int element)
{
	int flag = 0;
	printf("\nDo you want to input data of other children? - press 1 if you want or 2 if don't: ");
	flag = check_flag();
	if (flag == 1)
	{
		element = 1;
		return element;
	}
	else if (flag == 2)
	{
		printf("Thanks for work with us\n");
		element = 0;
		return element;
	}
	else
	{
		printf("Invalid input. Program will stop\n");
		return element;
	}
}
