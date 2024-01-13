/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    char s[1000];
    char temp;
    int n;
    scanf("%s%n",s,&n);
    printf("Original String: %s",s);
    
    int l = n-1;
    
    for(int i = 0;i<n/2; i++)
    {
        temp = s[i];
        s[i] = s[l];
        s[l--] = temp;
    }
    
    printf("\nReversed String: %s", s);
}
