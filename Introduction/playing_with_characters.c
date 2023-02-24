/***************************
 * Author: Zachary Perales *
 ***************************/
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 99
int main() 
{
    char ch;
    char* s = malloc(sizeof(char) * MAX_LEN);
    char* sen = malloc(sizeof(char) * MAX_LEN); 
    scanf("%c", &ch);
    printf("%c\n", ch);   
    scanf("\n");
    scanf("%[^\n]%*c", s);
    printf("%s\n", s);
    scanf("%[^\n]%*c", sen);
    printf("%s", sen);
    
    return 0;
}

