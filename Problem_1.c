//File name :problem_1.c
//Author : Shubham Pokale
//Email address : shubham.pokale2001@gmail.com
//Assignment no. 4 : Problem 1
//Description : Write a program that extracts part of the given string from the specified position. For example, if the sting is "Working with strings is fun", then if from position 4, 4 characters are to be extracted then the program should return string as "king". If the number of characters to be extracted is 0 then the program should extract entire string from the specified position.
//Last changed : 15-09-2023

#include<stdio.h>
#include<string.h>

int main(){
    int i; 
char str1[100];
char str2[100];
int start_index;
int end_index;

int modified_start_index;
printf("Enter the string:");
gets(str1);

printf("\nEnter the starting Index: ");
scanf("%d", &start_index);
modified_start_index =  start_index -1 ;
printf("\nEnter the Ending Index: ");
scanf("%d", &end_index);

if(start_index < 0 || start_index >= strlen(str1)){
    printf("Invalid Starting Index ");
    return 1; 
}

for( i=0; i < end_index && str1[i + start_index] != '\0'; i++){

str2[i] = str1[modified_start_index + i ];

}
str2[i]= '\0';
printf("\nThe extracted String is: %s", str2);


return 0;
}