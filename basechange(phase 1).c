/*
* This is a C program which is a preliminary design stage tester
* for a program that can change the base of the inputted number.
* As of now, this program can only change bases below 10 with 
* perfect accuracy. For bases above 10, the program cannot convert
* to any numbers with lettering representations within the number
* itself. If the inputted number does not have a letter with in the 
* representation, then it can still convert to base 10.
*
* Updates for Stage 2 will be comming with in 2 weeks time, until 
* then, please do not copy and use the program in any way.
*
* Copyright 2023. Shicheng.Z, September 4th, 2023.
*/
#include <stdio.h>
int power(int number, int number2);
int power(int number, int number2)
{
	int result = number;
	int result2 = 1;
	if(number == 0)
	{
		return result2;
	}
	else if(number == 1)
	{
		return number;
	}
	else
	{
		for(int h = 0;h < number2 - 1;h++)
		{
			result = result * number;
		}
		return result;
	}
}
int main()
{ 
	int number, base, base2;
       	printf("Enter the number:");
        scanf("%d",&number);
        printf("Enter it's original base:");
        scanf("%d",&base);
        printf("Enter the base which it is to be transfered to:");
        scanf("%d",&base2);
        int div_base = 0;
        int div_count = 1;
        //stage 0: Figuring out the digits
        while (1)
        {
                if(number / div_count == 0)
                {
			                  div_count = 1;
			                  div_base = div_base - 1;
                        break;
                }
                else
                {
                        div_count = div_count * 10;
			                  div_base++;
                }
        }
	    printf("0. %d\n\n",div_base);
	    int attr[div_base];
	    int div_base2 = div_base;
	    int number2 = number;
      // Stage 1: converting to base 10.
	    printf("1. %d\n\n",number);
	    attr[0] = number2 % power(10, div_base);
	    printf("2. %d\n\n",attr[0]);
	    for(int h = div_base;h > 0;h--)
	    {
		          attr[h] = number2 / power(10, h);
		          number2 = number;
		          if(attr[h] >= 10)
		          {
			                  attr[h] = 0;
		          }
		          printf("%d",attr[h]);		
	    }
	    printf("\n");
	    int base10number = 0;
	    for(int j = div_base;j >= 0;j = j - 1)
	    {
		          if(j == 0)
		          {
			                  base10number = base10number + attr[j];
			                  printf("%d\t%d\t%d\t%d\n",j,(attr[j] * power(base, j)),div_base,attr[j]);
		          }
		          else
		          {
			                  base10number = base10number + (attr[j] * power(base, j));
			                  printf("%d\t%d\t%d\t%d\n",j,(attr[j] * power(base, j)),div_base,attr[j]);
		          }
	  }	
	  printf("\n%d\n",base10number);
	  int attrsize2 = 0;
    // Stage 2: Convert to base2.
	  while (1)
	  {
		          if(base10number % base2 != base10number)
		          {
			                  attrsize2++;
		          }	
		          else
		          {
			                  break;
		          }
	  }
	  printf("\n%d\n",attrsize2);
}
