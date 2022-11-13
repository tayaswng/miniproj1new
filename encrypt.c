#include <stdio.h>
#include <string.h>


void encrypt(char *original){
    int i;
    int len = strlen(original);
    int arr[len];

    FILE *fp;
    fp = fopen("C:/Users/Taya/Desktop/CCode/git/miniproj1new/encrypted.txt", "w+");

    //creat an array of the ascii numbers for each input character
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
        //create an array of the resulting outChars and print to a file
        arr[i] = outChar;
        fprintf(fp, "%2x", arr[i]);
    }
    fclose(fp);
}

void main(){
    char original[] = "Hello There how are you?";
    encrypt(original);
}


