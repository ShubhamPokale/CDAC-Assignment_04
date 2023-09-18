//File name :problem_3_using_malloc.c
//Author : https://garbagevalue.com/bs/let-us-c-solutions/chapter-10-strings/f-4/write-a-program-that-uses-an-array-of-pointers-to-strings-str-receive-two-strings-str-1-and-str-2
//Email address : shubham.pokale2001@gmail.com
//Assignment no. 4 : Problem 1
//Description : Write a program that extracts part of the given string from the specified position. For example, if the sting is "Working with strings is fun", then if from position 4, 4 characters are to be extracted then the program should return string as "king". If the number of characters to be extracted is 0 then the program should extract entire string from the specified position.
//Last changed : 18-09-2023

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#define LINE 6/*If the number of lines are increased
 so no need to change anything in the program just change
 LINE macro here.*/
#pragma warning (disable : C4267)

void ser_rep(char **str, char *old, char *news)
{
	int i, j, k, m, c;
	j = k = m = i = c = 0;
	char ans[10][100], *p;
        
        
	for (i = 0; i <= LINE - 1; i++)
	{
		m = 0;
		c = 0;
        /*This loop for traversing the current line character by character.*/
		for (j = 0; str[i][j] != '\0';)
		{

			if (str[i][c] == old[k])/*If the character matches*/
			{
				k++;
				c++;
				if (old[k] == '\0')/*If the whole word is found.*/
				{
                /*This loop is replacing the word character by character.*/
					for (k = 0; news[k] != '\0'; k++, m++)
						ans[i][m] = news[k];
					j = c;
					k = 0;
				}
			}
			else/*If the character/word is not matched, so as it is string is copied.*/
			{
				ans[i][m] = str[i][j];
				m++;
				j++;
				c = j;
				k = 0;
			}
		}
		ans[i][m] = '\0';/*Terminate every line by NULL character*/
		j = k = m = 0;/*Reinitialization for next line.*/
	}
	for (i = 0; i <= LINE - 1; i++)
	{
		p = (char*)malloc(strlen(ans[i]) + 1);
        /*Memory needed is 1 more for null character.
          str[i] = ans[i]; This doesn't works becuase left side is pointer and right side is simple
          char variable therefore a news pointer p is taken and copied the content of ans[i] and
          assign to the str[i].*/
		strcpy(p, ans[i]);
		str[i] = p;
	}
}
int main()
{
	char *str[] = {
		"We will teach you how to...",
		"Move a mountain",
		"Level a building",
		"Erase the past",
		"Make a million",
		"...all through C!"
	};
	char str1[10], str2[10];
	puts("Enter the word you want to replace.");
	scanf("%s", str1);
	puts("Enter the word you want to put.");
	scanf("%s", str2);
	ser_rep(str, str1, str2);
	for (int i = 0; i <= LINE - 1; i++)
		puts(str[i]);
	_getch();
	return 0;
}