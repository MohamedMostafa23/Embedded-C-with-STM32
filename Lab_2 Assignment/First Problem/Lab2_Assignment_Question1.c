#include <stdio.h>
#include <stdbool.h>

#define CHAR_SIZE sizeof(char)        // Size of int in bytes
#define CHAR_BITS CHAR_SIZE * 8 - 1   // Size of int in bits - 1

#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) {__HadError=true;goto ExitJmp;}

char leftRotate(unsigned char num, int rotation);

char rightRotate(unsigned char num, int rotation);

int main()
{
    unsigned char x,o;
    int n,num;
    
    printf("enter number in range 0 - 255 : ");
    
    try{
        
    scanf("%d", &num);
    if(num>255){
        throw();
        
    }
    
    else {
        x = num;
    }
    
    }catch(){
        printf("you have to enter number in range 0 - 255");
    return 0;
    }
    
    printf("enter rotate type R for right rotation and L for left rotation : ");
    
    getchar();
    
    scanf("%c", &o);
    
    printf("enter number of rotating cycles : ");
    getchar();

    scanf("%d", &n);
    

    if (o=='R'){
        x = rightRotate(x,n);
    }
    
    else if(o=='L'){
        x = leftRotate(x,n);
    }
    printf("%d",x);

    return 0;
}

char leftRotate(unsigned char num, int rotation)
{
    int DROPPED_MSB;

    // The effective rotation
    rotation %= CHAR_BITS;


    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get MSB of num before it gets dropped
        DROPPED_MSB = (num >> CHAR_BITS) & 1; 

        // Left rotate num by 1 and 
        // Set its dropped MSB as new LSB
        num = (num << 1) | DROPPED_MSB;
    }

    return num;
}

char rightRotate(unsigned char num, int rotation)
{
    int DROPPED_LSB;
    // The effective rotation
    rotation %= CHAR_BITS;

    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get LSB of num before it gets dropped
        DROPPED_LSB = num & 1;

        // Right shift num by 1 and 
        // Clear its MSB
        num = (num >> 1) & (~(1 << CHAR_BITS));

        // Set its dropped LSB as new MSB
        num = num | (DROPPED_LSB << CHAR_BITS);
    }

    return num;
}

