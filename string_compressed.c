/*
 * string_compressed.c
 *
 *  Created on: Mar 6, 2018
 *      Author: hsahu
 */

#include "string.h"

/* String Compression aka Run-Length Encoding
 * [CTCI 6th 1.6]
 *
 * Algorithm
 * 1. Iterate through the string and copy the character to the new string, also
 * counting the repeats.
 * 2. At each iteration Check if the current character is same as the next character.
 * 3. If not add the count to the new string
 */
void compress_string(char * src){
	char buffer[50];
	int len = strlen(src);
	printf("Length of the src string = %s is %d\n",src, len);

	// For keeping the count of the consecutive characters
	int countConsecutive;
	int j = 0;		// Index for Destination String

	char* dest = (char*)malloc(sizeof(len*2+1));

	// Loop to go through the src characters one by one.
	for(int i =0; i<len; i++){
		dest[j++] = src[i];
		countConsecutive = 1;	// If this character is there than its there atleast once
		while((src[i] == src[i+1]) && (i+1)<len){
			countConsecutive++;
			i++;
		}
		// Push the number of occurrences of the character to a string buffer or
		// use (integer to Char function)
		sprintf(buffer, "%d", countConsecutive);

		// Now iterate through the buffer to copy the integer and put it in the
		//destination string
		for(int k = 0; *(buffer+k); k++){
			dest[j++] = buffer[k];
		}
	}

	dest[j] = '\0';
	printf("dest = %s\n", dest);

	int dst_len = strlen(dest);
	printf("Length of the destination string is %d\n", dst_len);

	if (dst_len > len)
		printf("Final dest = %s\n", src);
	else
		printf("Final dest = %s\n", dest);
}


// [COPIED CODE]
/*
Algorithm:
a) Pick the first character from source string.
b) Append the picked character to the destination string.
c) Count the number of subsequent occurrences of the picked character and append the count to destination string.
d) Pick the next character and repeat steps b) c) and d) if end of string is NOT reached.
*/

#define MAX_RLEN 50
/* Returns the Run Length Encoded string for the source string src */
char *encode(char *src) {
	int rLen;
	char count[MAX_RLEN];
	int len = strlen(src);

	/* If all characters in the source string are different,
    then size of destination string would be twice of input string.
    For example if the src is "abcd", then dest would be "a1b1c1d1"
    For other inputs, size would be less than twice.  */
	char *dest = (char *)malloc(sizeof(char)*(len*2 + 1));

	int i, j = 0, k;

	/* traverse the input string one by one */
	for(i = 0; i < len; i++) {
		dest[j] = src[i];	// Copy the first occurrence of the new character in to the dest
		j++;				// Increment j

		/* Count the number of occurrences of the new character */
		rLen = 1;		// At least one item is there

		while(i + 1 < len && src[i] == src[i+1]) {
			rLen++;
			i++;
		}

		/* Store rLen in a character array count[] */
		sprintf(count, "%d", rLen);

		/* Copy the count[] to destination */
		for(k = 0; *(count+k); k++, j++) {
			dest[j] = count[k];
		}
	}
	/*terminate the destination string */
	dest[j] = '\0';

	int dst_len = strlen(dest);
	printf("Length of the destination string is %d\n", dst_len);

	if (dst_len > len)
		return src;
	else
		return dest;

}
