#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "string.h"

// UTILITY FUNCTIONS
/* length_of_string - Calculates the length of a string  */
int length_of_string(char* str){
	int i, length = 0;

	if (str == NULL)
		return length;

	for (i = 0; ; i++){
		if(str[i] == '\0')
			break;
	}

	length = i;

	printf("Length of string=%d\n", length);
	return length;
}

// A function to check if a string str is palindrome
void isPalindrome(char str[]){
    // Start from leftmost and rightmost corners of str
    int start = 0;
    int end = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (end > start) {
    	if (str[start++] != str[end--]) {
            printf("%s is Not Palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}


/**
 * isUnique
 */
int isUniqueChars(char* str) {
	int length = strlen(str);

    // check if string is longer than char_set
    if (length > 128)
        return 0;

    // initialize all elements to 0
    char char_set[128] = {0};
//    for (int j = 0; j<128; j++)
//    	char_set[j] = 0;

    for (int i = 0; i < length; i++) {
        int val = str[i];
        if (char_set[val])
            return 0;

        char_set[val] = 1;
    }

    return 1;
}

int has_unique(char * str){
    int checker = 0;
    int length = strlen(str);

	for (int i = 0; i < length; ++i) {
		int val = (str[i]); //- 'a');
		if ((checker & (1 << val)) > 0){
			printf("val %d 1<<val : %d %d\n",val, 1<<val, 'a');
			return 0;
		}

		checker |= (1 << val);
	}
	return 1;
}

// isUnique (Brute Force Method)
// Time Complexity = O(n^2)
int is_unique(char * string){
	if(string == NULL)
		return 0;

	int i,j;
	int length;
	for (i=0; ; i++)
		if(string[i] == '\0')
			break;

	length = i - 1;

	// @2 loops
	for(i=0;i<length;i++){
		for(j=0;j<length;j++){
			if(string[i] == string[j] && i != j)
				return 0;
		}
	}
	return 1;
}

/* URLify
 * [CTCI 6th 1.3]
 * Write a Method to replace all the spaces in a String with '%20'.
 *
 * replace_spaces - function to replace spaces with '%20'
 */
void replace_spaces(char *str){
	/* Two Scan Method */
	int length, spaceCount=0;
	length = strlen(str);

	printf("String = %s\n", str);
	// 1st scan
	for(int i = 0; i<length; i++){
		if(str[i] == ' '){
			spaceCount++;
		}
	}

	int newlength = length + spaceCount * 3 - spaceCount; // or length + spacecount*2 as space already has 1
	printf("Old Length = %d SpaceCount = %d newLength = %d\n",length, spaceCount, newlength);
	str[newlength] = '\0';

	// 2nd scan
	for (int i = length-1; i>=0; i--){
		if(str[i] == ' '){
			str[newlength-1] = '0';
			str[newlength-2] = '2';
			str[newlength-3] = '%';
			newlength = newlength -3;
		}
		else{
			str[newlength-1] = str[i];
			newlength = newlength-1;
		}
	}

	printf("New String = %s\n", str);
}

/* One Away:
 * [CTCI 6th 1.5]
 *
 * There are three types of edits that can be performed on strings:
 * insert a character,
 * remove a character, or
 * replace a character.
 * Given two strings, write a function to check if they are one edit (or zero edits) away.
 * EXAMPLE
 * pale, ple -> true
 * pales, pale -> true
 * pale, bale -> true
 * pale, bae -> false
 */
/* Solutions:
 */
int one_edit_replace(char *, char *);
int one_edit_insert(char *, char *);
int one_edit_remove(char *, char *);

int one_away(char *str1, char *str2){
	int len1, len2;
	len1 = strlen(str1);
	len2 = strlen(str2);

	// Replacement
	if(len1 == len2){
		return one_edit_replace(str1, str2);
	}
	// Insertion
	else if((len1 +1) == len2){
		return one_edit_insert(str1, str2);
	}
	// Removal
	else if((len1 -1) == len2){
		return one_edit_remove(str1, str2);
	}

	// All other cases
	return 0;
}

int one_edit_replace(char* str1, char* str2){
	// Str1 and Str2 are one edit replacement away if they have 1 and only 1
	// character difference.
	int diff = 0;
	int len1 = strlen(str1);

	for(int i = 0; i<len1; i++){
		// Check if the chars are different, set diff to 1 if true
		if(str1[i] != str2[i]){
			diff = 1;
		}

		// check for difference first to avoid checking for all the characters
		if(diff){
			return 0;
		}

	}
	return 0;
}

int one_edit_insert(char* str1, char* str2){
	// Str1 and Str2 are one edit insertion away if they have 1 and only 1
	// character less.
	// str1 --- index1
	// str2 --- index2
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int index1 = 0;
	int index2 = 0;

	while (index1<len1 && index2<len2){
		if(str1[index1] != str2[index2]){
			if(index1 != index2){
				return 0;
			}
			index2++;
		}
		else {
			index1++;
			index2++;
		}
	}
	return 1;
}

int one_edit_remove(char* str1, char* str2){
	// Str1 and Str2 are one edit removal away if they have 1 and only 1
	// character more .
	// str1 --- index1
	// str2 --- index2
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int index1 = 0;
	int index2 = 0;

	while (index1<len1 && index2<len2){
		if(str1[index1] != str2[index2]){
			if(index1 != index2){
				return 0;
			}
			index1++;
		}
		else {
			index1++;
			index2++;
		}
	}
	return 1;
}

/**
 * Check Permutation aka AnaGrams
 * [CTCI 6th 1.2]
 *
 * Anagrams: Check if 2 strings are anagrams of each other or not.
 * Anagrams are words who have the same characters but in different orders.
 */

#define NO_OF_CHARS 256
int are_anagram(char *str1, char* str2){
	/* Method 1 -- Count the number of distinct characters in both the strings.
	 * 1. Create count arrays of size 256 (number of chars) for both strings.
	 * 		Initialize all the values in the count array to 0. <as not populated>
	 * 2. Iterate through every character of both strings and
	 * 		increment the count of character in the corresponding count arrays.
	 * 2. Compare the count arrays. If the values matches then yes they are anagrams.
	 * e.g: acre and care
	 */
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int hash1[NO_OF_CHARS] = {0};
	int hash2[NO_OF_CHARS] = {0};

	printf("Comparing for Permutations 1=%s with 2=%s\n", str1, str2);

	// Check if the lengths of both the strings are different.
	// If the lengths are different then we can fail it right away.
	if (len1 != len2){
		printf("The strings are not anagrams as len1=%d and len2=%d\n", len1, len2);
		return 0;
	}

	for (int i = 0; i < len1 ; i++){
		printf("-- %d %c\n", str1[i], str1[i]);
		hash1[str1[i]]++;
		hash2[str2[i]]++;
	}

	// Compare the hash arrays now
	for(int i = 0; i<256; i++){
		if(hash1[i] != hash2[i]){
			printf("The strings are not anagrams %d != %d\n", hash1[i], hash2[i]);
			return 0;
		}
	}

	// Else it is an anagram.
	printf("the strings are anagrams\n");
	return 1;
}

#define NO_OF_CHARS 256
int are_anagram_2(char *str1, char* str2){
	/* Method 2 -- Optimized from Method 1 |
	 * Count the number of distinct characters in both the strings.
	 * 1. Create only 1 count array of size 256 (number of chars) for both strings.
	 * 		Initialize all the values in the count array to 0. <as not populated>
	 * 2. We can increment the value in count array for characters in str1 and
	 * 		decrement for characters in str2.
	 * 2. If all count values are 0, then the two strings are anagram of each other.
	 * e.g: acre and care
	 */
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int count[NO_OF_CHARS] = {0};

	printf("Comparing for Permutations 1=%s with 2=%s\n", str1, str2);

	// Check if the lengths of both the strings are different.
	// If the lengths are different then we can fail it right away.
	if (len1 != len2){
		printf("The strings are not anagrams as len1=%d and len2=%d\n", len1, len2);
		return 0;
	}

	// Optimization:
	// For each character in input strings,
	// increment count in the corresponding count array and decrement also
	for (int i = 0; i < len1 ; i++){
		printf(" str1-- %d %c\n str2-- %d %c\n", str1[i], str1[i], str2[i], str2[i]);
		count[str1[i]]++;
		count[str2[i]]--;
	}

	// Compare the count array now
	for(int i = 0; i<256; i++){
		if(count[i]){
			printf("The strings are not anagrams \n");
			return 0;
		}
	}

	// Else it is an anagram.
	printf("the strings are anagrams\n");
	return 1;
}


int main() {
	char * null_address = NULL;
	char unique_str[100] = "abcdefgh13";
	char non_unique_str[100] = "ab123";

	int length = length_of_string(unique_str);
	printf("Length of string=%d\n", length);

	length = length_of_string(null_address);
	printf("Length of string=%d\n", length);

	length = length_of_string(non_unique_str);
	printf("Length of string=%d\n", length);

	printf("True %d\n", isUniqueChars(unique_str));
	printf("True %d\n", has_unique(unique_str));

/* ----------- URLify ----------------------------*/

	char str[] = "Mr John  Smith";
	replace_spaces(str);

/* ----------- Compress String -------------------*/
	char cstr[] = "aaabbbccc";
	char cstr1[] = "abc";
	char *cstr2 = "ABZEEE";

	compress_string(cstr1);
	compress_string(cstr);

	char *cstr3 = encode(cstr2);
	printf("%s \n", cstr3);

/* ----------- one away String -------------------*/

	char ste1[] = "cakeaA";
	char ste2[] = "acakeA";
	char ste3[] = "bcakeA";

	printf("One away : %d\n", one_away(str, str));

/* ----------- Anagram String -------------------*/
	int res = are_anagram(ste1, ste3);
	printf("are_anagram = %d", res);

	res = are_anagram_2(ste1, ste2);
	printf("are_anagram = %d", res);

/* ----------- Permutation Palindrome String -------------------*/

	permutation_palindrome(ste2);
	isPalindrome(ste2);

/* ----------- Longest Sub String -------------------
	char ls1[] = "abscdabc";
	char ls2[] = "bbbbb";
	char ls3[] = "geeksforgeeks";
	int resls;

	//resls = longest_unique_substring(ls1);
	printf("Longest SUB String in %s size = %d\n",ls1, resls);

	//resls = lengthOfLongestSubstring(ls3);
	printf("Longest SUB String in %s size = %d\n",ls3, resls);
	//resls = lengthOfLongestSubstring(ls2);
	printf("Longest SUB String in %s size = %d\n",ls2, resls);
*/
	return 0;
}
