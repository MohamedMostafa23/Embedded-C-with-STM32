#include <stdio.h>

int main()
{
    float u, a, t, v, s;
    printf("enter the initial velocity: ");
    
    scanf("%f", &u);    
    
    printf("enter the acceleration: ");
    
    scanf("%f", &a);
        
    printf("enter the the time that has elapsed: ");
    
    scanf("%f", &t);
    
    v = u+a*t;
    s = u*t+(a/2)*t*t;
    printf("the final velocity is: %f \n", v);
    
    printf("the distance traversed is: %f", s);
    
    return 0;
}
