#include <stdio.h>
int min(int a, int b);
int max(int a, int b);

int main()
{
    int int1, int2, int3, sum, product, smallest, largest;
    
    float average;
    
    printf("Enter three different integers sepereted with space : ");
    
    scanf("%i %i %i", &int1,&int2,&int3);    
    
    sum = int1+int2+int3;
    
    average = (int1+int2+int3)/3;
    
    printf("Sum is: %i \n", sum);
    
    printf("Average is: %f \n", average);
    
    product = int1*int2*int3;

    printf("Product is: %i \n", product);
    
    smallest = min(int1,min(int2,int3));
    
    printf("Smallest is: %i \n", smallest);
    
    largest = max(int1,max(int2,int3));
    
    printf("Largest is: %i \n", largest);
    
    return 0;
}

int min(int a, int b){
    return (a>b) ? b : a;
}

int max(int a, int b){
    return (a>b) ? a : b;
}
