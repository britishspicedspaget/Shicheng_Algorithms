/* This is a simple c program designed to be a calculater for binomial distribution 
* and probability calculations using a pascals triangle as the coefficient finder
* and also solving the probability by employing the sum of all the possibilities 
* as calculated. Please note that this is a premature version, a newer version 
* that can solve different singular probability questions and graph the results 
* will be uploaded soon.
*
* Please do not copy and paste :(
*
* Shicheng.Z  July 15th, 2023.
*/
#include <stdio.h>
int main()
{
        int og_total, choice, prob;
        printf("Enter the total amount of choices:");
        scanf("%d",&og_total);
        printf("Enter the choice:");
        scanf("%d",&choice);
        printf("ENter the probability:");
        scanf("%d",&prob);
        int total = og_total + 1;
        int attr[total][total];
        for(int s = 0;s < total;s++)
        {
                for(int u = 0;u < total;u++)
                {
                        attr[s][u] = 0;
                }
        }
        attr[0][0] = 1;
        attr[1][0] = 1;
        attr[1][1] = 1;
        for(int x = 2;x < total;x++)
        {
                for(int a = 0;a < total;a++)
                {
                        if(a == 0)
                        {
                                attr[x][a] = 1;
                        }
                        else
                        {
                                attr[x][a] = attr[x - 1][a] + attr[x - 1][a - 1];
                        }
                }
        }
        int result = attr[total - 1][0];
        for(int l = 1;l < total;l++)
        {
                result = attr[total - 1][l] + result;
        }
        printf("Getting a %d chosen results out of %d og tosses in 2 mutually exclusive outcomes is %d / %d or %f percent\n",choice,og_total,attr[total - 1][choice],result,((float)attr[total - 1][choice] / (float)result) * 100);
}
