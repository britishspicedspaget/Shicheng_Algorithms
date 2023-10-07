#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ABS(int number)
{
        if(number < 0)
        {
                return number * -1;
        }
        else
        {
                return number;
        }
}
int main()
{
        int size;
        printf("Enter how much of y height you with to graph/plot:");
        scanf("%d",&size);
        double a, b, c, attry[size];
        int decision;
        double testx1, testx2;
        printf("Solve for y when x = 0 first or just graph this equation?");
        scanf("%d",&decision);
        if(decision == 1)
        {
                printf("We will solve for x when y = 0 first then.\n");
        }
        printf("Enter your a value:");
        scanf("%lf",&a);
        printf("Enter your b value:");
        scanf("%lf",&b);
        printf("Enter your c value:");
        scanf("%lf",&c);
        printf("Note: This calculator's equation follows ax2 + bx + c = 0 or x = -b +- sqrt(b2 - 4ac) / 2a format.\n");
        if(decision == 1)
        {
                testx1 = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
                testx2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
                printf("Test results: y = 0.0, x1 = %lf, x2 = %lf\n",testx1,testx2);
        }
        int x1, x2;
        printf("Select the y range for your graphing:");
        scanf("%d %d",&x1,&x2);
        head:
        if((ABS(x2 - x1) + 1) != size)
        {
                printf("\nPlease re-enter your size of the y range(entered %d, defined maximum %d):",ABS(x2 - x1) + 1, size);
                scanf("%d %d",&x1, &x2);
                goto head;
        }
        double x;
        if(x1 == x2)
        {
                goto head;
        }
        else if(x1 < x2)
        {
                x = x1;
        }
        else
        {
                x = x2;
        }
        for(int i = 0;i < size;i++)
        {
                attry[i] = (a * x * x) + (b * x) + c;
                printf("X %lf    Y %lf\n",x, attry[i]);
                x++;
        }
}
