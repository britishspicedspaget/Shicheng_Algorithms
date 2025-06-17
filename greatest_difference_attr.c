/*
 * Leetcode 2016锛?Max Diff Between Increasing elements
 *
 * This is a program degisned to solve Leetcode Question
 * No.2016, finding the maximum difference between two
 * elements in increasing order. It uses a all unique
 * pair searcher to find the available permutations that
 * describe values increasing in size from the first
 * attribute to the second attribute and coallates its
 * sum to find the maximum difference between the two values.
 *
 * Please reference this code should you use it in your own programs.
 *
 * Copyright 2025, Shicheng Z, 17/06/25
*/
#include <stdio.h>
void main_algorithm () {
	int size_arr = 0;
	printf ("Enter the size of the array:");
	scanf ("%d", &size_arr);
	int array [size_arr];
	for (int x = 0; x < size_arr; x++) {
		printf ("Enter the attirbute:");
		scanf ("%d", &array [x]);
	} int gap = -1;
	for (int y = 0; y < size_arr - 1; y++) {
		for (int z = y + 1; z < size_arr; z++) {
			if (array [y] > array [z]) continue;
			else {
				if ((array [z] - array [y]) > gap) gap = array [z] - array [y];
				else ;
			}
		}
	} printf ("Largest Gap: %d\n", gap);
} int main () {
	main_algorithm ();
	return 0;
}
