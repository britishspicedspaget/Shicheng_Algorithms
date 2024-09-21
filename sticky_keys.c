/*
 This is a solution to Question 2 of the Kattis Questions, U of A 2023, Sticky Keys.
 The problem is that a keyboard is sticky and as a result may result in keys repeating.
 The task is to remove duplicate letters affixed together. Please note that spelling 
 is not a aspect of this program and as a result words that do have two letters affixed
 together will also have their letter removed while being grammatically correct, as we 
 cannot link it to a spellcheck data base.

 Provided with a string with size from 1 to 1000 letters, inclusive, the task of the program
 is defined as above.

 It uses a incremental system, recordig previous letters and comparing it to the next one
 in number format, which determines if any letters are repeating or not and/or have to be
 remove or not.

 Please give appropiate credit to this program if you choose to implement it in any other code.

 Copyright 2024, Shicheng Zhang, 21/9/24
*/
#include <stdio.h>
void main_algorithm () {
    int string_length = 0;
    repeat_input:
    printf ("Enter how many letters the string conatins, spaces count:");
    scanf ("%d", &string_length);
    if ((string_length < 1) && (string_length > 1000)) {
        goto repeat_input;
    }
    char string_input [string_length];
    int array [string_length];
    printf ("Enter the string: ");
    scanf ("%s", string_input);
    int cut_off = 0;
    for (int x = 0; x < string_length; x++) {
        array [x] = 0;
        array [x] = (int) string_input [x];
        printf ("%d ", array [x]);
    } printf ("\n");
    int last_variable = array [0]; 
    for (int y = 1; y < string_length; y++) {
        printf ("1. %d %d\n", array [y], y);
        if (((array [y] != -1) && (last_variable != -1)) && (array [y] == last_variable)) {
            int last_variable2 = array [y];
            printf ("2. %d %d\n", array [y], y);
            if (y == string_length - 1) {
                for (int c = y - 1; c > 0; c--) {
                    if (array [c] == array [y]) {
                        array [c] = -1;
                    } else {
                        ;
                    }
                }
            } else {
                for (int z = y + 1; z < string_length; z++) {
                    if (((array [y] != -1) && (last_variable2 != -1)) && (array [z] != last_variable2)) {
                        printf ("3. %d %d\n", array [z], z);
                        for (int a = y; a < z; a++) {
                            printf ("4. %d %d\n", array [a], a);
                            array [a] = -1;
                        }
                        cut_off = z;
                        last_variable = -1;
                    } 
                }
            }
        } else {
            last_variable = array [y];
        }
    } for (int b = 0; b < string_length; b++) {
        if (array [b] == -1) {
            ;
        } else {
            printf ("(%c %d)", (char) (array [b]), b);
        }
    } printf ("\n");
} int main () {
    main_algorithm ();
    return 0;
}
