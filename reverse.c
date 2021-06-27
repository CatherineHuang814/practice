#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv){
    FILE *file;
    if(argc==3){
        file = fopen(argv[2], "r");
    }
    char *line = malloc(sizeof(char)*1024);
    char **word=malloc(sizeof(char*)*1024);
    for(int i=0; i<1024; i++){
        *(word+i) = malloc(sizeof(char)*1024);
    }
    int cnt=0;
    int len=0;
    while(fgets(line, 1024, file)!=NULL){
        line[strcspn(line,"\n")]='\0';
        strcpy(word[cnt],line);
        cnt++;
    }
    fclose(file);
    file = fopen(argv[2],"w+");
    for(int i=cnt-1; i>=0; i--){
        len = strlen(word[i]);
        for(int j=len-1; j>=0; j--){
            fprintf(file, "%c", word[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
    free(line);
    free(word);
}
