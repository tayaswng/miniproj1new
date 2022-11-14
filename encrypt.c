#include <stdio.h>
#include <string.h>


void encrypt(char *original){
    int i;
    int len = strlen(original);
    int arr[len];

    //open new file to write the ecrypted text to
    FILE *fp;
    fp = fopen("C:/Users/Taya/Desktop/CCode/git/miniproj1new/encrypted.crp", "w+");

    //create an array of the ascii numbers for each input character
    for (i=0; i<len; i++)
    {
        int asciinum = original[i];
        arr[i] = asciinum;
        printf("original ascii: %d\n", arr[i]);
    }

    printf("\n");

    //subtracts 16 from the ascii value
    for (i=0; i<len; i++){
        int outChar = arr[i]-16;

        //if the resulting outChar is less than 32 
        if (outChar<32){
            outChar = (outChar-32)+144;
        }
        //print resulting outChars to a file
        fprintf(fp, "%2X", outChar);
    }

    fclose(fp); 
}



int main(FILE *fp){

    char fileinput[255];
    fp = fopen("C:/Users/Taya/Desktop/CCode/git/miniproj1new/testdoc.txt", "r");
    fgets(fileinput, 255, (FILE*)fp);

    encrypt(fileinput);

    return 0;
}


