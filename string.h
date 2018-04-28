/*
 * string.h
 *
 *  Created on: Mar 6, 2018
 *      Author: hsahu
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef STRING_H_
#define STRING_H_

// Utility Functions
int length_of_string(char* str);

void compress_string(char * src);
int lengthOfLongestSubstring(char* s);
int longest_unique_substring(char* str);


#endif /* STRING_H_ */
