/*
 * string_permute_palindrome.c
 *
 *  Created on: Mar 6, 2018
 *      Author: hsahu
 */


#include <stdlib.h>
#include <stdio.h>

#include "string.h"

/**
 * Permutation_palindrome
 * Given a String write a function to check if the string is a permutation of its palindrome.
 */
/* Algorithm:
 * 1. Start a Count Array of size 256 - NO_OF_CHARS possible
 * 2. Iterate over the array and count the number of occurrences of a particular
 *    character in the string.
 * 3. If the count array has the all even entries than it could be a palindrome,
 * 	  If the count array has 1 odd entry also then also it could be a palin.
 * 	  else its not gonna be a palindrome.
 */
/*
 * Time Complexity = O(n)
 * Space = O(k) where K is 256 if K distinct values
 */

#define NO_OF_CHARS 256
void permutation_palindrome(char *str){
	int len = length_of_string(str);
	printf("Length of the given '%s' String = %d\n", str, len);

	int count[NO_OF_CHARS] = {0};

	for (int i = 0; i<len; i++){
		printf("str[i] = %c %d\n", str[i], str[i]);
		count[str[i]]++;		// Index = str[i]'s ASCII value e.g: 'a' = 66
	}

	int odd = 0;
	for (int j = 0; j<NO_OF_CHARS; j++){
		if(count[j] % 2 != 0) {
			odd++;
			printf("odd = %d count[%d] = %d \n", odd, j, count[j]);
		}

		if (odd > 1){
			printf("Palindrome not possible.\n");
			return;
		}
	}

	printf("String Permutation can be a Palindrome.\n");
	return;
}
