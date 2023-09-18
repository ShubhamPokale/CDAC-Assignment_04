//File name :problem_3.c
//Author : Shubham Pokale
//Email address : shubham.pokale2001@gmail.com
//Assignment no. 4 : Problem 3
//Description : Write a program that uses an array of pointers to strings str[ ]. Receive two strings str1 and str2 and check if str1 is embedded in any of the strings in str[ ]. If str1 is found, then replace it with str2. char *str[ ] = { "We will teach you how to...", "Move a mountain", "Level a building", "Erase the past", "Make a million", "...all through C!" } ; For example if str1 contains "mountain" and str2 contains "car", then the second string in str should get changed to "Move a car".
//Last changed : 18-09-2023s




#include <stdio.h>
#include <string.h>

int main() {
    char *str[] = {
        "We will teach you how to...",
        "Move a mountain",
        "Level a building",
        "Erase the past",
        "Make a million",
        "...all through C!"
    };

    char str1[100], str2[100];

    printf("Enter the string to find (str1): ");
    scanf("%s", str1);

    printf("Enter the replacement string (str2): ");
    scanf("%s", str2);

    int found = 0;

    for (int i = 0; i < 6; i++) {
        if (strstr(str[i], str1) != NULL) {
            char *pos = strstr(str[i], str1);
            int index = pos - str[i];  // Calculate the index of the occurrence
            memmove(pos + strlen(str2), pos + strlen(str1), strlen(str[i]) - index - strlen(str1) + 1);
            strncpy(pos, str2, strlen(str2));
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Modified strings:\n");
        for (int i = 0; i < 6; i++) {
            printf("%s\n", str[i]);
        }
    } else {
        printf("String not found in the array.\n");
    }

    return 0;
}


// This code snippet aims to search for the first occurrence of str1 within each string in the str array and replace it with str2 if //found. Let's break it down step by step:

// for (int i = 0; i < 6; i++):

// This loop iterates through the str array, which contains 6 strings.
// if (strstr(str[i], str1) != NULL):

// Within each iteration of the loop, the strstr() function is used to search for the substring str1 within the current string str[i]. If str1 is found, strstr() returns a pointer to the first occurrence within str[i, and this condition evaluates to true. If str1 is not found, the condition evaluates to false, and the loop continues to the next string.
// char *pos = strstr(str[i], str1);:

// If str1 is found within the current string str[i], a pointer pos is assigned to the address where the first occurrence of str1 starts within str[i].
// int index = pos - str[i];:

// This line calculates the index (or offset) of where str1 is found within str[i]. It does so by subtracting the memory address pointed to by str[i] from the memory address pointed to by pos. This index helps identify the exact position of str1 within str[i].
// memmove(pos + strlen(str2), pos + strlen(str1), strlen(str[i]) - index - strlen(str1) + 1);:

// This line is responsible for replacing str1 with str2 within the string str[i]. Here's how it works:
// pos + strlen(str2) is the destination where the modified content will be moved.
// pos + strlen(str1) is the source from which the content will be copied.
// strlen(str[i]) - index - strlen(str1) + 1 is the number of characters to be copied. It ensures that the entire string beyond str1 (including the null terminator \0) is copied to the new location.
// strncpy(pos, str2, strlen(str2));:

// After the memmove(), this line replaces the first occurrence of str1 with str2 by copying the characters from str2 to the location pointed to by pos. strlen(str2) specifies how many characters from str2 should be copied.
// found = 1;:

// This flag is set to indicate that at least one occurrence of str1 was found and replaced in the entire array.
// break;:

// This break statement exits the loop once the replacement is done, as there is no need to continue searching through the remaining strings.
// The result is that the program will search for str1 in each string within the str array and replace the first occurrence of str1 with str2 in the first string where it's found.