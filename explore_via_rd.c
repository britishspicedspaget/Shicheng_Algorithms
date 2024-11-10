/*
 * This is a solution to the UAPC23D1 Question K: Sneaky Exploration, under the U of A 
 * Kattis questions. The aim is to find the number of paths that can be undertaken by a person 
 * travelling from a defined number of buildings without travelling along specified roads 
 * which connect individual buildings. 
 * 
 * For example, if you have 4 buildings, labelled 1 to 4 respectively, and there are routes marked
 * between buildings [1, 2], [2, 3], [3, 4]. There are 3 possible routes that can be taken.
 * 
 * This program uses a permutation finder to find, in turn, at which of the buildings can a route 
 * not be taken. Using these results, it deducts the possible ways in which a route can be taken, while 
 * ensuring that it does not equal the values set at the beginning of all inputs (roads between buildings).
 * In the end, the number printed out is the number of ways that travel without using roads can be under-
 * taken with these combinations of roads set and their buildings (Assuming that only following the road 
 * counts as an impossible route.)
 * 
 * Please give appropriate credit to this program should you choose to implement it in your own programs.
 * 
 * 10/11/24, Shicheng Z, Copyright 2024.
 * 
*/
#include <stdio.h>
int add_factorial (int number) {
    int temp = 0;
    for (int l = number; l > 0; l--) {
        temp = temp + l;
    }
    return temp;
} void main_algorithm () {
    int num_of_buildings = 0;
    printf ("How many buildings are there: ");
    scanf ("%d", &num_of_buildings);
    num_of_buildings = num_of_buildings - 1; 
    int road_count [num_of_buildings][2];
    for (int x = 0; x < num_of_buildings; x++) {
        road_count [x][0] = 0;
        road_count [x][1] = 0;
    } for (int y = 0; y < num_of_buildings; y++) {
        printf ("Enter the starting building of this road: ");
        scanf ("%d", &road_count [y][0]);
        printf ("Enter the ending building of this road: ");
        scanf ("%d", &road_count [y][1]);
    } printf("The number of routes that can be taken is: ");
    for (int a = 0; a < num_of_buildings; a++) {
        int in_built_ban_list [num_of_buildings - 1];
        for (int e = 0; e < num_of_buildings - 1; e++) {
            in_built_ban_list [e] = 0;
        } int building_in_question = a + 1;
        for (int d = 0; d < num_of_buildings; d++) {
            for (int f = 0; f < 2; f++) {
                if (road_count [d][f] == building_in_question) {
                    int miniature_check = -1;
                    if (f == 0) { 
                        for (int g = 0; g < num_of_buildings - 1; g++) {
                            if (road_count [d][1] == in_built_ban_list [g]) {
                                miniature_check = 0;
                                break;
                            }
                        }
                    } else { 
                        for (int h = 0; h < num_of_buildings - 1; h++) {
                            if (road_count [h][0] == in_built_ban_list [h]) {
                                miniature_check = 0;
                                break;
                            }
                        }
                    } if (miniature_check == -1) {
                        for (int i = 0; i < num_of_buildings - 1; i++) {
                            if (in_built_ban_list [i] == 0) {
                                in_built_ban_list [i] = building_in_question;
                                break;
                            }
                        }
                    }
                }
            }
        } for (int j = 0; j < num_of_buildings; j++) {
            if (in_built_ban_list [j] == 0) {
                int total = add_factorial (num_of_buildings - building_in_question);
                for (int k = 0; k < num_of_buildings - 1; k++) {
                    if (k == building_in_question) {
                        continue;
                    } else {
                        total = total - k;
                    }
                } printf ("%d", total);
            }
        }
    }
    printf ("\n");
} int main () {
    main_algorithm ();
    return 0;
}
