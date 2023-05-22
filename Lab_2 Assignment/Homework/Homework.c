#include <stdio.h>
#include <math.h>
int findFactorial(int num);

int main()
{   
    
    int exponent, iterations;
    float sum=0.0f;
    
    printf("enter the exponent number: ");
    
    scanf("%d", &exponent);    

    printf("enter the iterations number: ");
    
    scanf("%d", &iterations);    
    
    for (int i = iterations-1; i > 0; i--){
        sum = 1 + exponent * sum / i;
    }
    
    printf("the exponential result : %f ",sum);

    return 0;
}

