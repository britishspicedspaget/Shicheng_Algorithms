/*
 This is International Dates, Question 3 of the Kattis Problems, U of A
 2023 B set questions. It states that you are given a full date, but you
 have no idea if it is in DD/MM/YYYY, which is EU time format, or MM/DD/YYYY,
 which is US time format. Given that some values are unsolveable when both
 MM and DD are below 13 and could be any time format, the task is to determine
 which time format the current date is in: EU, US, or possible to be both.

 The algorithm checks the year first, between a value of 0 to 2100, and then checks
 the date AND month possible values first. If both are over 12, then the values are 
 sent back to the input to be re-entered. If the first two values are above 12 while
 second two values are not. It is EU time as it is DD/MM. If the contrary is true, 
 then it is US time as it is MM/DD.

 The usage of -1 as the error code is for cases where user input is wrong and both
 possible date and month values are both over 12.

 This is the base algorithm. A update which can deduct date values according to month,
 which is unasked for in the original program requirements, will be developed as soon
 as Problem 4 is finished.

 Please give appropiate credit to this program should it be used in other programs.

 Copyright 2024, Shicheng Zhang, 22/9/24.
*/
#include <stdio.h>
void main_algorithm () {
    int array_date [8] = {0};
    reinput:
    for (int x = 0; x < 8; x++) {
        printf ("Enter the digits of the date from left to right (if any value is one digit, put 0'digit'):");
        scanf ("%d", &array_date [x]);
    } 
    int format = -1;
    if ((array_date [4] * 1000 + array_date [5] * 100 + array_date [6] * 10 + array_date [7] > 0) && (array_date [4] * 1000 + array_date [5] * 100 + array_date [6] * 10 + array_date [7] < 2100)) {
        if ((array_date [2] * 10 + array_date [3] > 12) && (array_date [0] * 10 + array_date [1] > 12)) {
            format = -1;
        } else {
            if (array_date [0] * 10 + array_date [1] > 12) {
                format = 1;
            } else if (array_date [2] * 10 + array_date [3] > 12) {
                format = 0;
            } else {
                format = 2;
            }
        }
    } else {
        goto reinput;
    } if (format == -1) {
        printf ("Error in input, please check value.\n");
    } else {
        if (format == 0) {
            printf ("US/America time format.\n");
        } else if (format == 1) {
            printf ("EU/Europe time format.\n");
        } else {
            printf ("Possible to be both time formats.\n");
        }
    }
} int main () {
    main_algorithm ();
    return 0;
}
