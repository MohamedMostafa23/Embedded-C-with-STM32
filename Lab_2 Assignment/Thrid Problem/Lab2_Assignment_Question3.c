#include <stdio.h>
#include <math.h>
int main()
{
    int termsNum, sum = 0, num1 = 0, num2 = 1;
    printf("Enter the number of series terms: ");
    
    scanf("%d", &termsNum);  
        
    for (int i = 0 ;i<termsNum/2;i++){

        
        printf("%d ",num1);
        printf("%d ",num2);

        num1 += num2;

        num2 += num1;
    }
    
    if (termsNum%2 !=0){
        printf("%d",num1);
    }

    return 0;
}


