#include <stdio.h>

void main(){
    FILE *fp;
    fp = fopen("C:/Users/Taya/Desktop/CCode/git/miniproject-1/testdoc.txt", "w+");

    fprintf(fp, "testing the purpose of fprintf\n");    //to write things in a file
    fputs("Testing the purpose of fputs\n", fp);
    fclose(fp);

    char buff[255];
    fp = fopen("C:/Users/Taya/Desktop/CCode/git/miniproject-1/testdoc.txt", "r");
    fgets(buff, 255, (FILE*)fp);
    printf("1: %s\n", buff);

    fgets(buff, 255, (FILE*)fp);
    printf("2: %s\n", buff);
    fclose(fp);
    
}
