#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTR 500
#define CLEAR_INPUT while (getchar() != '\n') /*void*/

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

void sort_down (char *string){
    unsigned int i, j;
    char ch_tmp;
    
    for (i = 0; i < strlen(string); i++){
        for (j = 0; j < (strlen(string) - 1) - i; j++){
            if (*(string + j) < *(string + 1 + j)){
                ch_tmp = *(string + j);
                *(string + j) = *(string + 1 + j);
                *(string + 1 + j) = ch_tmp;
            }
        }  
    }
}

int main (int argc, char *argv[]){
    char *string_input;
    char opt;

    if ((string_input = malloc(MAXSTR*sizeof (char))) == NULL){
        printf("Memory error!\n");
        exit(0);
    }

    printf ("Insert string:\n");
    fgets (string_input, MAXSTR, stdin);
    del_enter (string_input);
    printf ("Como deseja ordenar a string? (C)rescente ou (D)ecrescente?\n");
    do{
        switch (tolower(opt = fgetc(stdin))) {
            case 'c': sort_up (string_input);
                      break;
            case 'd': sort_down (string_input);
                      break;
            default:  printf("Escolha \"c\" para ordem crescente ou \"d\" para ordem decrescente!\n");
                      break;
        }
        CLEAR_INPUT;
    }while (opt != 'c' && opt != 'd');
    printf ("String ordenada: %s\n", string_input);
    free (string_input);
return 0;   
}
