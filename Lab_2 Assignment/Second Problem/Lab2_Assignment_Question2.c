#include <stdio.h>

int main()
{
    int stars = 1, shift = 1, shape = 0, stop = 1;

    while(stars>=1){
        for (int i =8-shift;i>=1;i--){
            printf(" ");
        }
        for (int i =1;i<=stars;i++){
            printf("*");
        }
        printf("\n");
        if (stop>=9){
            stars-=2;
            shift--;
            shape = 1;
            if (stars>=9){
                break;
            }
            continue;
        }
        stop+=2;
        stars+=2;
        shift++;
    }

    return 0;
}


