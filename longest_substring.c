#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* longest_substring.c
 * CTCI 17 | LeetCode M
 * Length of the longest substring without repeating characters
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * For example,
 * for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.
 * For “BBBB” the longest substring is “B”, with length 1.
 * For “GEEKSFORGEEKS”, there are two longest substrings with length 7. EKSFORG or KSFORGE
 */

/* Algorithm:
 * Linear Time and Extra Space - O(n+k)
 * Keep track of the visited characters in a HashMap.
 * Assuming ASCII 128 Commonly used tables are:
 * int[26] for Letters 'a' - 'z' or 'A' - 'Z'
 * int[128] for ASCII
 * int[256] for Extended ASCII
 */
/*
 * The idea is to scan the string from left to right, and
 * keep track of the maximum length Non-Repeating Character Substring (NRCS) seen so far.
 * Let the maximum length be max_len.
 *
 * When we traverse the string, we also keep track of length of the current NRCS
 *  using cur_len variable.
 * For every new character, we look for it in already processed part of the string
 * (A temp array called visited[] is used for this purpose).
 *
 * If it is not present, then we increase the cur_len by 1.
 * If present, then there are two cases:
 * a) The previous instance of character is not part of current NRCS (The NRCS which is under process).
 *    In this case, we need to simply increase cur_len by 1.
 * b) If the previous instance is part of the current NRCS, then our current NRCS changes.
 *    It becomes the substring staring from the next character of previous instance
 *    to currently scanned character.
 *
 *  We also need to compare cur_len and max_len, before changing current NRCS (or changing cur_len).
 *
 *
 */



#define MAX_CHARS 128
int longest_unique_substring(char* str){
	int len = strlen(str);
	int curLen = 1;
	int maxLen = 1;

	int prevIndex;
	// Populate the hashMap visited with -1 to indicate it has no characters yet.
	int visited[MAX_CHARS] = {-1};

	visited[str[0]] = 0;

	for(int i = 1; i<len; i++){
		prevIndex = visited[str[i]];

		/* if the current character is not present in the already processed substring
		 * or it is not part of the current NRCS then do curLen++ */
		if((prevIndex == -1) || (i - curLen >prevIndex)){
			curLen++;
		}
		/* If the current character is present in the current NRCS, then update
		 * NRCS to start from the next character of previous instance */
		else{
			if(curLen > maxLen)
				maxLen = curLen;

			curLen = i - prevIndex;
		}

		// update the index of the current character
		visited[str[i]] = i;
	}

	if(curLen > maxLen)
		maxLen = curLen;

	return maxLen;
}

int lengthOfLongestSubstring(char* s) {
	int len = strlen(s);
	int ans = 0;

	int index[128]; // current index of character

	// try to extend the range [i, j]
	int j;
	int i;
	for (j = 0, i = 0; j < len; j++) {
		i = fmax(index[s[j]], i);
		ans = fmax(ans, j - i + 1);
		index[s[j]] = j + 1;
	}

	return ans;
}


