#include <stdio.h>
#include <string.h>


void encrypt(char *original){
    int i;
    int len = strlen(original);
    int arr[len];

    //open new file to write the ecrypted text to
    FILE *fp;
    fp = fopen("encrypted.crp", "w+");  //NOTE:this needs to be changed so that the file name has the same base name as the inputted file name

    //create an array of the ascii numbers for each input character
    for (i=0; i<len; i++)
    {
        int asciinum = original[i];
        arr[i] = asciinum;
        //printf("original ascii: %d\n", arr[i]);
    }

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



void cryptoMagic (char input[], char fname[]){

    char fileinput[255];    //what is read from the file
    FILE *fp;   //pointer to the file

    if (input == "-D"){

        fp = fopen(fname,"r");
        fgets(fileinput, 255, (FILE*)fp);
    
        encrypt(fileinput);
    }
    else{

        fp = fopen(fname,"r");
        fgets(fileinput, 255, (FILE*)fp);
    
        encrypt(fileinput);
    }

}



int main(){
    
    cryptoMagic("-E", "testdoc.txt"); //im not sure if this is how they want us to give the arguments?
    return 0;
}