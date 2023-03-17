/*11/3 2023
#
# This is a C program designed to be an accurate timer to the amount of seconds that you enter.
# it does not have a minute or hour calibration, and the inputs and output are purely in seco-
# nds. Please note that any non-numerical input will give an instant output of 0.00001, and a-
# ny mixed number-letter input will result in the timer counting the seconds of the first sec-
# tion of the numerical input ONLY and may return values that are faulty to the programmer's 
# purposes.
#  
# Please no not copy paste this program into your own program and claim credit, that is plagi-
# arism and if discovered may lead to serious penalties. Copy and paste of this program is on-
# ly permmited with a direct reference to the program writer(see below).
#
# NOTE: SECOND CALIBRATION MAY BE DIFFERENT ON DIFFERENT DEVICES, CHANGE THE FLOAT VALUE AT
# LINE 36 ACCORDINGLY TO CALIBRATE WITH ONE SECOND OF RUNTIME ON YOUR SYSTEM.
#
# Copyright 2023, Shicheng.Z
#*/
#include <stdio.h>
int main()
{
        int number;
        printf("Enter the seconds you want to set a timer to:");
        scanf("%d",&number);
        float numbernumber = 1;
        while (1)
        {
                if((numbernumber / 100000) >= number)
                {
                        printf("%f\n",numbernumber / 100000);
                        break;
                }
                else
                {
                        printf("%f\n",numbernumber / 100000);
                        numbernumber = numbernumber + 2.6;
                        // CHANGE THE VALUE IF NESSESARY^
                }       
        }
}
