#include <stdio.h>

int main()
{

    int timeElapsed, timeInMinutes;
    int hours, minutes, seconds;

    printf("enter the total time elapsed (in seconds) : ");
    
    scanf("%i", &timeElapsed);
    
    timeInMinutes = timeElapsed/60;
    
    hours = (timeInMinutes)/60;

    minutes = (timeInMinutes)%60;

    seconds = timeElapsed%60;
    
    
    printf("Time in Hours:Minutes:Seconds : %i:%i:%i \n", hours, minutes, seconds);

    return 0;
}

