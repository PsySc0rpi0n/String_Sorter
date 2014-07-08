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
    unsigned int i, j;
    char ch_tmp;
    
    for (i = 0; i < strlen(string); i++){
        for (j = 0; j < (strlen(string) - 1) - i; j++){
            if (*(string + j) > *(string + 1 + j)){
                ch_tmp = *(string + j);
                *(string + j) = *(string + 1 + j);
                *(string + 1 + j) = ch_tmp;
            }
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
