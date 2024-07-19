/*
  This is a program to find the median of two fused arrays. Both arrays
  will have a user-defined size.

  Problem 4, Median of Two Sorted Arrays, Leetcode.
  Difficulty: Hard.

  It combines the two arrays into one, and then finds the combined median out of all those values.

  array3 [] was the combined array.

  Copyright 2024, Shicheng Z.

  Published July 19th, 2024.
  */
#include <stdio.h>
void main_algorithm () {
    int size = 0, size2 = 0;
    printf ("Enter the size of array 1:");
    scanf ("%d", &size);
    printf ("Enter the size of array 2:");
    scanf ("%d", &size2);
    float array [size], array2 [size2];
    for (int x = 0; x < size; x++) {
        array [x] = 0;
        printf ("Enter the value of array [%d]:", x);
        scanf ("%f", &array [x]);
    } for (int y = 0; y < size2; y++) {
        array2 [y] = 0;
        printf ("Enter the value of array2 [%d]:", y);
        scanf ("%f", &array2 [y]);
    }
    float array3 [size + size2];
    for (int z = 0; z < (size + size2); z++) {
        array3 [z] = 0;
    } 
    int a;
    for (a = 0; a < size; a++) {
        array3 [a] = array [a];
    } for (int b = 0; b < size2; b++) {
        array3 [a] = array2 [b];
        a++;
    } for (int c = 0; c < (size + size2); c++) {
        for (int d = 0; d < (size + size2); d++) {
            float temp = 0.0;
            if (array3 [c] < array3 [d]) {
                temp = array3 [c];
                array3 [c] = array3 [d];
                array3 [d] = temp;
            } else {
                ;
            }
        }
    } int size3 = size + size2 - 1;
    float average = 0.0, prev = 0.0;
    if ((size3 % 2) != 0) {
        prev = array3 [size3 / 2] + array3 [size3 / 2 + 1];
        average = prev / 2.0;
    } else {
        average = array3 [size3 / 2];
    }
    printf ("The median of these two arrays is %f.\n", average);
} int main () {
    main_algorithm ();
    return 0;
}
