#include <stdio.h>
#include <string.h>

int main() {

    /*int i;
    float f;
    printf("Enter an integer value: ");
    scanf("%d", &i);
    printf("Enter a float value: ");
    scanf("%f", &f);
    printf("\nInteger value: %d\n", i);
    printf("Float value: %f", f);
    return 0;*/

    char str[80];
    int i;

    printf("Enter a string: ");
    fgets(str, 255, stdin);

    /* remove newline, if present */
    i = strlen(str)-1;
    if( str[ i ] == '\n') 
        str[i] = '\0';

    printf("This is your string: %s", str);

}