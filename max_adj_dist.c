/*
 * Leetcode 3423: Maximum Distance between Adjacent Elements.
 *
 * This is a program to find the maximum difference between all
 * adjacent elements in an array. It uses a absolute value function
 * to ensure no negative differences can cause processing errors in
 * the program, and then circulates between all adjacent values in
 * array until the pair with the most difference is found.
 *
 * Please reference this program should you wish to use it in your own code.
 * 
 * Copyright 2025, Shicheng. Z, 17/06/25
 *
*/
#include <stdio.h>
int abs (int num);
int abs (int num) {
	if (num < 0) num * -1;
	else ;
	return num;
} void main_algorithm () {
	int size_arr = 0;
	printf ("Enter the size of the array:");
	scanf ("%d", &size_arr);
	int array [size_arr];
	int gap = 0;
	for (int x = 0; x < size_arr; x++) {
		printf ("Enter the attribute:");
		scanf ("%d", &array [x]);
		if (x == 0);
		else if (x == size_arr - 1) {
			if (abs (array [size_arr - 1] - array [0]) > gap) gap = abs (array [size_arr - 1] - array [0]);
			else ;
		} else {
			if (abs (array [x] - array [x - 1]) > gap) gap = abs (array [x] - array [x - 1]);
			else ;
		}
	} printf ("Largest Gap: %d\n", gap);
} int main () {
	main_algorithm ();
	return 0;
}
