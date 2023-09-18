//File name :problem_2.c
//Author : Shubham Pokale
//Email address : shubham.pokale2001@gmail.com
//Assignment no. 4 : Problem 2
//Description : Write a program that converts a string like "124" to an integer 124
//Last changed : 18-09-2023s

#include<stdio.h>
#include<conio.h>
int main()
{
	char str[100];
	int i, num, fin = 0;
	printf("Enter a string of numbers : ");
	gets(str);
	for (i = 0; str[i] != '\0'; i++)
	{
		num = str[i] - 48;
		fin = fin * 10 + num;
	}
	printf("\nNumber : %d", fin);
	_getch();
	return 0;
}