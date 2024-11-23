/*
 * This is an algorithm to determine the area under the curve for any kind of graph with the form 
 * y = ax^n + bx^n-1 + cx^n-2 ..... nx^1 + (constant of choice). It currently uses the rectangle formula,
 * and can take in any formula or graphgiven as long as it belongs to one variable only. It uses rectangles
 * and therefore is not very accurate with a minimal amount of rectangles. However, a trapezoid formula and
 * a implementation of the Simpson's formula will shortly be programmed for versatility and better efficiency.
 * 
 * Please give appropiate credit should you choose to use this code in other programs.
 * 
 * Copyright 2024, Shicheng Z, 23/11/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main_algorithm () {
    int list_x_power_max = 0, list_x_power_min = 0;
    re_input_max:
    printf ("Enter the maximum x power: ");
    scanf ("%d", &list_x_power_max);
    re_input_min:
    printf ("Enter the minimum x power: ");
    scanf ("%d", &list_x_power_min);
    char confirmation;
    int no_rad = 0;
    if (list_x_power_min == -1) {
        re_input_confirmation:
        system ("clear");
        printf ("Confirm no radical equation input (y/n): ");
        scanf (" %c", &confirmation);
        if (confirmation == 'y') {
            printf ("Confirmed. No radical values will be used.\n");
            no_rad = 1;
        } else if (confirmation == 'n') {
            printf ("Not confirmed, please re-enter choice.\n");
            goto re_input_confirmation;
        } else {
            printf ("Unconfirmed. Please re-enter choice.\n");
            goto re_input_confirmation;
        }
    } else {
        if (list_x_power_min < 2) {
            system ("clear");
            printf ("The minimum power of x must be larger than 2 (x ^ n = x, where n = -1, abs(n) must be larger than 1).\n");
            goto re_input_min;
        } else if (list_x_power_max < 1) {
            system ("clear");
            printf ("The maximum power of x must be larger than 1 (x ^ 0 = 1).\n");
            goto re_input_max;
        }
    } int total_size_all_power = 0;
    if (no_rad == 0) {
        total_size_all_power = list_x_power_max + list_x_power_min;
    } else {
        total_size_all_power = list_x_power_max + 1;
    } int array_x [total_size_all_power][2];
    int power_counter = list_x_power_max;
    for (int x = 0; x < total_size_all_power; x++) {
        if (power_counter == -1) {
            if (no_rad == 1) {
                break;
            } else {
                power_counter = power_counter - 1;
            }
        } array_x [x][0] = power_counter;
        printf ("Enter the coefficient of x ^ %d: ", array_x [x][0]);
        scanf ("%d", &array_x [x][1]);
        power_counter = power_counter - 1;
    } int formula_determinant = 0;
    formula_choice:
    printf ("Which formula would you like to run (0 for rectangle, 1 for trapezoid): ");
    scanf ("%d", &formula_determinant);
    if (formula_determinant == 0) {
        // Rectangle Formulae
        int rectangle_amt = 0, lower_bound = 0, higher_bound = 0; 
        rectangle_input:
        printf ("What will be the amount of rectangles you wish to the calculation (More is more accurate estimate): ");
        scanf ("%d", &rectangle_amt);
        if (rectangle_amt < 1) {
            printf ("You must have at least 1 rectangle to perform the computation.\n");
            goto rectangle_input;
        } lower_bound_input_1:
        printf ("What will be the lower bound of the graph: ");
        scanf ("%d", &lower_bound);
        if (lower_bound < 0) {
            printf ("The lower bound must be higher than 0.\n");
            goto lower_bound_input_1;
        } higher_bound_input_1:
        printf ("What will be the higher bound of the graph: ");
        scanf ("%d", &higher_bound);
        if (higher_bound <= lower_bound) {
            printf ("The higher bound must be larger than the lower bound.\n");
            goto higher_bound_input_1;
        } float avg_x = (higher_bound - lower_bound) / (float) rectangle_amt;
        float concurrent_x_low = lower_bound - avg_x;
        float concurrent_x_high = lower_bound;
        float total_area = 0;
        for (int y = 0; y < rectangle_amt; y++) {
            float concurrent_y_low = 0, concurrent_y_high = 0; 
            concurrent_x_high = concurrent_x_high + avg_x;
            concurrent_x_low = concurrent_x_low + avg_x;
            for (int z = 0; z < total_size_all_power; z++) {
                concurrent_y_high = concurrent_y_high + pow (concurrent_x_high, array_x [z][0]) * array_x [z][1];
                concurrent_y_low = concurrent_y_low + pow (concurrent_x_low, array_x [z][0]) * array_x [z][1];
            } if ((concurrent_y_high == concurrent_y_low) || (concurrent_y_high > concurrent_y_low)) {
                total_area = total_area + concurrent_y_low * avg_x;
            } else {
                total_area = total_area + concurrent_y_high * avg_x;
            }
        } printf ("Your total area of the graph ");
        for (int a = 0; a < total_size_all_power; a++) {
            if (a == total_size_all_power - 1) {
                printf ("%d * (x ^ %d)", array_x [a][1], array_x [a][0]);
            } else {
                printf ("%d * (x ^ %d) + ", array_x [a][1], array_x [a][0]);
            }
        } printf(" = %f units ^ 2.\n", total_area);
    } else if (formula_determinant == 1) {
        // Trapezoid Formula 
    } else {
        system ("clear");
        printf ("Invalid Choice, only options are 0 and 1.\n");
        goto formula_choice;
    }
} int main () {
    main_algorithm ();
    return 0;
}
