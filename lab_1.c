//Luqmaan Irshad 217222365 luq21 
//EECS 3216 Lab 1
#include <stdio.h>
#include <string.h>

//Use Ctrl + Z to simulate EOF (End of File) on Windows

int main() {

    char filename[261], sentence[255], select;
    int text, send = 0;
    FILE*file;

    printf("Welcome to the second word finder!  This program finds and prints the second word of each line of text!");
    printf("\nWould you like to enter text via the terminal or file input?\n\n\t1 - Terminal\n\t2 - File Input\n\n: ");
    scanf("%c", &select);
    printf("----------------------------\n");

    if (select == '2'){
        
        printf("Enter the file name (e.g. labtext.txt): ");
        scanf("%s", filename);
        printf("----------------------------\n");

        file = fopen(filename, "r");

        while ((text = fgetc(file)) != EOF){
        
            if (text == ' ')        //Keeps track of how many spaces we encounter.  We need to print everything in between the first and second space of that line
                send++;

            else if (text == '\n'){ //If we encounter a newline, we reset the space counter to 0
                send = 0;
                printf("\n");
            }
            
            else if (send == 1)    //If we have only encountered 1 space in the line at this point in the iteration, we print the character
                putchar(text); 
        }
    
        fclose(file);
    }

    else {

        int j;
        printf("Enter your text here (max 255 characters, e.g. Mario loves pasta\\nLuigi enjoys pizza): ");
        scanf("%c", sentence);
        fgets(sentence, 255, stdin); 
        
        printf("----------------------------\n");

        for (int i = 0; i < strlen(sentence); i++){
            
            if (sentence[i] == ' ')          //Keeps track of how many spaces we encounter.  We need to print everything in between the first and second space of that line
                send++;

            else if (sentence[i] == '\\'){  //If we encounter a newline, we reset the space counter to 0
                if (i+1 <= strlen(sentence)){
                    if (sentence[i+1] == 'n'){
                        send = 0;
                        printf("\n");
                    }
                }
            }
            
            else if (send == 1)             //If we have only encountered 1 space in the line at this point in the iteration, we print the character
                putchar(sentence[i]);

            else if (sentence[i] == EOF)
                break;
        }
    }
    return 0;
}