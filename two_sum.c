#include <stdio.h>
int main()
{
        int number, target;
        printf("Enter the size of the attribute:");
        scanf("%d",&number);
        int attr[number];
        int attr2[number];
        int attr3[number][2];
        printf("Enter your target number:");
        scanf("%d",&target);
        for(int s = 0;s < number;s++)
        {
                printf("Enter the attribute:");
                scanf("%d",&attr[s]);
                attr2[s] = 1;
                attr3[s][0] = 0;
                attr3[s][1] = 0;
        }
        int v = 0;
        for(int d = 0;d < number;d++)
        {
                for(int p = 0;p < number;p++)
                {
                        if((attr2[d] != 0) && (attr2[p] != 0) && (d != p))
                        {
                                if(attr[d] + attr[p] == target)
                                {
                                        attr3[v][0] = attr[d];
                                        attr3[v][1] = attr[p];
                                        attr2[d] = 0;
                                        attr2[p] = 0;
                                        v++;
                                }
                        }
                }
        }
        for(int a = 0;a < v;a++)
        {
                printf("{%d, %d}\n",attr3[a][0], attr3[a][1]);
        }
}
