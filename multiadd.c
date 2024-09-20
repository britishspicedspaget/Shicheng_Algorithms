/*
 This program is the Question 1 from the Kattis program, U of A programming contest 2023,
 which is "Adding Trouble".

 The problem is that we have three integers A, B, C. Make sure that A + B = C, and we have made the correct addition.
 Ensure that ((A, B, C) <= 10 ^ 9) && ((A, B, C) >= -(10 ^ 9)).

 This program has been slightly modified to be able to perform all additions instead of just A + B = C.
 In other words, it also checks for B + C = A and A + C = B, and returns results accordingly. For example,
 if one were to enter: (3, 7, 4) in the described program, the answer would be false as it would only
 check for 3 + 7 = 4, which is false. This program checks 3 + 7 = 4, 7 + 4 = 3, and 3 + 4 = 7, which is all
 the options available. 

 This design ensures optimization for variants of the program. For example, if one were to change the amount of 
 values to 4, 5, 10, or to be user inputted, this design ensures that one does not have to write all addition statements
 to run all values and instead use a calculated for loop constructed from the factorial calculation of all values to 
 optimise code length, efficiency, and run time.

 The script_algorithm [][] array is for defining which values of the original array, array [], would have to undergo calculation 
 and have outputted at which particular  time. This optimises program speed and efficiency for both writer and program
 due to reliance on a repeating loop and incremented change instead of having to calculate many more instances of repeating addition.

 The error_code variable is to check if the values fit within the specified boundaries of the program design:
 ((A, B, C) <= 10 ^ 9) && ((A, B, C) >= -(10 ^ 9))
 0 is for no error occuring, 1 is for a error occuring and requiring a new input from the user.

 Please do not copy the program in any way, shape, or form without giving associated credit.

 Copyright 2024. Shicheng Zhang. September 19th, 2024.
*/

#include <stdio.h>
#include <math.h>
int script_algorithm [3][2] = {
    {0, 1}, 
    {1, 2},
    {0, 2}
}; void main_algorithm () {
    long long array [3] = {0};
    int error_code = 0;
    reinput:
    for (int x = 0; x < 3; x++) {
        printf ("Input array [%d]:", x);
        scanf ("%lld", &array [x]);
    } for (int y = 0; y < 3; y++) {
        if ((array [y] < -1 * (powl (10, 9))) && (array [y] > powl (10, 9))) {
            error_code = 1;
        } else {
            ;
        }
    } if (error_code == 1) {
        goto reinput;
    } else {
        for (int z = 0; z < 3; z++) {
            if (array [script_algorithm [z][0]] + array [script_algorithm [z][1]] == array [3 - (script_algorithm [z][0] + script_algorithm [z][1])]) {
                printf ("Correct! {%lld + %lld = %lld}\n", array [script_algorithm [z][0]], array [script_algorithm [z][1]], array [3 - (script_algorithm [z][0] + script_algorithm [z][1])]);
            } else {
                printf ("Incorrect! {%lld + %lld != %lld}\n", array [script_algorithm [z][0]], array [script_algorithm [z][1]], array [3 - (script_algorithm [z][0] + script_algorithm [z][1])]);
            }
        }
    }
} int main () {
    main_algorithm ();
    return 0;
}
