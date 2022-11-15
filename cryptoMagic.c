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
        printf("original ascii: %d\n", arr[i]);
    }

    //subtracts 16 from the ascii value
    for (i=0; i<len; i++){
        int outChar = arr[i]-16;

        //if the resulting outChar is less than 32 
        if (outChar<32){
            outChar = (outChar-32)+144;
        }
        arr[i] = outChar;
        if(arr[i] == 106){
            printf("newline\n");
            fputs("\n", fp);
        }
        else{
            printf("outchar: %2X\n", arr[i]);
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
    char basename [(fnamelen-1)];

    for(int i=0; i<fnamelen && fname[i] != '.'; ++i){
        printf("%c\n", fname[i]);
        basename[i] = fname[i];
        printf("%c\n", basename[i]);
    }
    printf("%s", basename);

    if(input == "-D"){

        printf("decrypt");

//change this


        /*fp = fopen(fname,"r");
        fgets(line, 255, (FILE*)fp);
    
        encrypt(line, encrypted); */
    }

    else{

        fp = fopen(fname,"r"); //read the user's file

        char fext[] = ".crp";   //the file extension we are going to use is ".crp"
        
        strcat(basename, fext); //makes the encrypted filename ex. "filebase.crp" and stores it in basename
        printf("filename: %s\n", basename);

        encrypted = fopen(basename,"w+"); //opens a new file to write the encrypted message to 

        //Reads one line at a time from a file and encrypts it
        while(fgets(line, 120, (FILE*)fp)){
            printf("%s", line);
            encrypt(line, basename);
        }
    } 
}


int main(){
    cryptoMagic("-E", "testdoc.txt"); //im not sure if this is how they want us to give the arguments?
    return 0;
}