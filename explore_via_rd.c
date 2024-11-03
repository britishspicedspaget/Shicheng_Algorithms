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
    } printf("The route that can be taken is: ");
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
                } printf ("%d ", total);
            }
        }
    }
    printf ("\n");
} int main () {
    main_algorithm ();
    return 0;
}
