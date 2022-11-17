#include <stdio.h>
#include <string.h>


void encrypt(char original[120], char *writefile){

    int i;
    size_t len = strlen(original);
    int arr[len];

    //open new file to write the ecrypted text to
    FILE *fp;
    fp = fopen(writefile, "a");

    //create an array of the ascii numbers for each input character
    for (i=0; i<len; i++)
    {
        int asciinum = original[i];
        arr[i] = asciinum;
    }

    //subtracts 16 from the ascii value
    for (i=0; i<len; i++){
        int outChar = arr[i]-16;

        //if the resulting outChar is less than 32 
        if (outChar<32){
            outChar = (outChar-32)+144;
        }

        arr[i] = outChar;

        //detects if there is a carriage return, and creates a new line in the file instead of writing it 
        if(arr[i] == 106){
            fputs("\n", fp);
        }

        else{
            fprintf(fp, "%2X", outChar);
        }
    }

    fclose(fp); 
}



void cryptoMagic (char input[], char fname[]){

    char line[120];    //what is read from the file
    FILE *fp;   //pointer to the file
    FILE *encrypted; //pointer to encrypted file
    size_t fnamelen = strlen(fname); //length of user's file name
    char basename [(fnamelen)];

    for(int i=0; i<fnamelen && fname[i] != '.'; ++i){   //code for this doesnt work with no file extension, it adds random characters to the end?
        basename[i] = fname[i];
    }

    if(input == "-D"){

        //add decrypt function 
        printf("decrypt");


    }

    else{

        fp = fopen(fname,"r"); //read the user's file

        char fext[] = ".crp";   //the file extension we are going to use is ".crp"
        
        strcat(basename, fext); //makes the encrypted filename ex. "filebase.crp" and stores it in basename

        encrypted = fopen(basename,"w+"); //opens a new file to write the encrypted message to 

        //Reads one line at a time from a file and encrypts it
        while(fgets(line, 120, (FILE*)fp)){
            encrypt(line, basename);
        }
    } 
}


int main(){
    cryptoMagic("-E", "testdoc.txt"); //im not sure if this is how they want us to give the arguments?
    return 0;
}