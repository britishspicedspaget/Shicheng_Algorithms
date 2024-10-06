/*
 This is a solution to Question "Mean Words" of the Kattis Questions, U of A 2023 questions list.

 The aim is to combine many defined strings and print out, in succession, the average value of their
 combined letter constituents.

 For exmaple, if there are 2 strings, "mean" and "word", the output would be the average of the ASCII
 values of m and w, e and o, and so forth until n and d.

 Please include references to this program if you choose to employ its contents.

 Copyright 2024, Shicheng Z, 06/10/2024
*/
#include <stdio.h>
#include <math.h>
void main_algorithm () {
    int amount_of_words = 0;
    printf ("Enter the amount of words that will be included:");
    scanf ("%d", &amount_of_words);
    int size_of_word = 0;
    printf ("Enter the maximum size of each word:");
    scanf ("%d", &size_of_word);
    char input [amount_of_words][size_of_word];
    for (int x = 0; x < amount_of_words; x++) {
        for (int y = 0; y < size_of_word; y++) {
            input [x][y] = '~';
        }
    } int average, column_avg [size_of_word], div_counter [size_of_word];
    char final_output [size_of_word];
    for (int z = 0; z < size_of_word; z++) {
        column_avg [z] = 0;
        div_counter [z] = 0;
        final_output [z] = '}';
    } for (int a = 0; a < amount_of_words; a++) {
        printf ("Enter the word in attribute [%d]:", a);
        scanf ("%s", input [a]);
    } for (int b = 0; b < size_of_word; b++) {
        for (int c = 0; c < amount_of_words; c++) {
            if (((input [c][b] >= 65) && (input [c][b] <= 90)) || ((input [c][b] >= 97) && (input [c][b] <= 122))) {
                column_avg [b] = column_avg [b] + (int) (input [c][b]);
            } else {
                column_avg [b] = column_avg [b] + 32;
            }
            div_counter [b]++;
        }
        printf ("\n");
    } for (int d = 0; d < size_of_word; d++) {
        final_output [d] = (char) ((int) (column_avg [d] / div_counter [d]));
    } printf ("\n");
} int main () {
    main_algorithm ();
    return 0;
}
