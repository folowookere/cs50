#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main (int numOfArguments, string argValues[])
{
    if (numOfArguments == 2)
    {
        //second index of command line equals char variable
        char* file = argValues[1];
        //opens file that we created as a reading file
        FILE* card = fopen(file, "r");
        if (!card)
        {
            printf ("No file or nothing in the file.\n");
            return 1;
        }
        //define buffer -
        unsigned char buffer[512];
        //keep count
        int imgcount = 0;
        //check through 1 byte at a time - always 4 arguments for fread
        while (fread(buffer, 512, 1, card) == 1)
        {
            //shorthand math to check header file in jpg. Check if file is jpg
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                //increate imgcount by 1
                imgcount++;
            }
        }
        //print out how many jpgs are in the file
        printf("Total number of jpg images in file: %i\n", imgcount);
        fclose(card);
        return 0;
    }
    else
    {
        //If user does not enter 2 arguments quit immediately
        printf ("Usage: ./getJpg filename\n");
        return 1;
    }
}