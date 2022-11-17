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


void decrypt(char original[255], char *writefile){
    int i;
    size_t len = strlen(original);
    int arr[len];

    FILE* fp;
    fp = fopen(writefile, "a");

    //create array of ascii numbers
    for (i=0; i<len; i++)
    {
        //writes string of character values of different non-alphabetical characters to file
        if((original[i]==56)&& (original[i+1]==48)){
        fputs(" ", fp);
        i=i+1;
        }
        else if ((original[i]==56)&& (original[i+1]==55)){
        fputs("'", fp);
        }
        else if((original[i]==50)&&(original[i+1]==70)){
        fputs("?", fp);
        }
        else if((original[i]==56)&&(original[i+1]==49)){
        fputs("!", fp);
        }
                else{
        if((i%2==0 || i==0) && i!=1)
        {writefile[i]=original[i]-48;
        writefile[i]=writefile[i]*16;
        }

        //write the ASCII correspondants of each letter to file
        else{
            if (original[i]=='A')
                writefile[i]=writefile[i-1]+10;

            else if (original[i]=='B')
                writefile[i]=writefile[i-1]+11;

            else if (writefile[i]=='C')
                writefile[i]=writefile[i-1]+12;

            else if (original[i]=='D')
                writefile[i]=writefile[i-1]+13;

            else if (original[i]=='E')
                writefile[i]=writefile[i-1]+14;

            else if (original[i]=='F')
                writefile[i]=writefile[i-1]+15;

            else        //for letters not A-F set to 0
                {
                writefile[i]=original[i]-48;
                writefile[i]=writefile[i-1]+writefile[i];
                }
                original[i]= writefile[i]+16;

                if(original[i]>127)
                {
                    original[i]=(original[i]-144)+32;
                    printf("%c",original[i]);
                }
                else
                    fprintf(fp,"%c",original[i]);
            }

         }
        }

    fclose(fp);
}


void cryptoMagic (char input[], char fname[]){

    char line[255];    //what is read from the file
    FILE *fp;   //pointer to the file
    FILE *encrypted; //pointer to encrypted file
    FILE *decrypt_file;
    size_t fnamelen = strlen(fname); //length of user's file name
    char basename [(fnamelen)];

    for(int i=0; i<fnamelen && fname[i] != '.'; ++i){
        basename[i] = fname[i];
    }

    if(input == "-D"){
        char fext[] = ".txt";   //the file extension we are going to use is ".crp"
        char decrypted[255];
        strcat(basename, fext);

        fp = fopen(fname,"r");

        decrypt_file = fopen(basename, "w+"); 

        //Reads one line at a time from a file and encrypts it
        while(fgets(line, 120, (FILE*)fp)){
            decrypt(line, basename);
        }

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
    cryptoMagic("-D", "testdoc.crp");
    return 0;
}