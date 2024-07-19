/*
  This is a program made to reverse the nodes within a particular array where the size of the node
  and of the array are all user defined.

  Problem 25, Reverse Nodes in k-Group, Leetcode.
  Difficulty: Hard.

  All constraints regarding k and node size were ignored, but arguably this makes the program more
  versatile in a controlled enviroment.

  It takes the original array into array [], isolates all the nodes into array_nodes [][], and uses a 
  modified bubble sort algorithm to flip each node to it's respective result, before recombining it
  into array [] for the final printout.

  The bubble sort looks for values that match the array median to flip ad get the final result.

  Copyright 2024, Shicheng Z.

  Published July 19th, 2024.
  */
#include <stdio.h> 
void main_algorithm () {
    int size_of_node = 0, size_of_array = 0;
    printf ("What is the size of the node:");   
    scanf ("%d", &size_of_node);
    printf ("What is the size of the array:");
    scanf ("%d", &size_of_array);
    int array [size_of_array];
    for (int x = 0; x < size_of_array; x++) {
        array [x] = 0;
        printf ("Enter the value of array [%d]:", x);
        scanf ("%d", &array [x]);
    }
    int num_of_nodes = 0, remaining = 0;
    num_of_nodes = size_of_array / size_of_node;
    remaining = size_of_array % size_of_node;
    int array_nodes [num_of_nodes][size_of_node];
    for (int y = 0; y < num_of_nodes; y++) {
        for (int z = 0; z < size_of_node; z++) {
            array_nodes [y][z] = 0;
        }
    }
    int ascend = 0; 
    for (int a = 0; a < num_of_nodes; a++) {
        for (int b = 0; b < size_of_node; b++) {
            array_nodes [a][b] = array [ascend];
            ascend++;
        }
    } for (int c = 0; c < num_of_nodes; c++) {
        float reference = (size_of_node - 1) / 2.0;
        for (int d = 0; d < size_of_node / 2; d++) {
            int e = size_of_node - 1 - d;
            int temp = 0;
            temp = array_nodes [c][d];
            array_nodes [c][d] = array_nodes [c][e];
            array_nodes [c][e] = temp;
        }
    }
    int ascend2 = 0; 
    for (int h = 0; h < num_of_nodes; h++) {
        for (int i = 0; i < size_of_node; i++) {
            array [ascend2] = array_nodes [h][i];
            printf ("%d ", array_nodes [h][i]);
            ascend2++;
        }
        printf ("\n");
    } for (int j = 0; j < size_of_array; j++) {
        printf ("%d ", array [j]);
    }
    printf ("\n");
} int main () {
    main_algorithm ();
    return 0;
}
