#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 500
#define CLEAR_INPUT while (getchar() != NULL) /*void*/

int del_enter (char *string){
    if (*(string + (strlen(string)-1)) == '\n'){
        *(string + (strlen(string)-1)) = '\0';
        return 1;
    }
return 0;
}

void sort_up (char *string){
    char ch;
    unsigned int i;
    
    ch = *string;
    for (i = 0; i < strlen(string); i++){
        if (*(string + 1 + i) <= ch){
            ch = *(string + i);
            *(string + 1 + i) = *(string + i);
            *(string + i) = ch;
        }
    }
}

int main (int argc, char *argv[]){
    char *string_input;

    if ((string_input = malloc(MAXSTR*sizeof (char))) == NULL){
        printf("Memory error!\n");
        exit(0);
    }

    printf ("Insert string:\n");
    fgets (string_input, MAXSTR, stdin);
    del_enter (string_input);
    sort_up (string_input);
    printf ("String ordenada: %s\n", string_input);
    free (string_input);
return 0;   
}
