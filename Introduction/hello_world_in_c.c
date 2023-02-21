/******************************
 * Author: Zachary R. Perales *
 ******************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char s[100];
    
    /************************************************************************************************** 
     * Parameter 1:                                                                                   *
     * Format specifiers that instruct the compiler to read in and store all of the characters except *
     * the newline character, then read in and discard the newline character.                         *
     *                                                                                                *
     * Parameter 2:                                                                                   *
     * The memory address of the variable s. s stores the memory address of the first element of the  *
     * char array.                                                                                    *
     **************************************************************************************************/

    scanf("%[^\n]%*c", &s);
    
    printf("Hello, World!\n%s", s);
    
    return 0;
}
