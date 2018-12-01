#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main (int numOfArguments, string filename[])
{
    if (numOfArguments == 2)
    {
        //second index of command line equals char variable
        char* file = filename[1];
        char filenames[8];

        //opens file that we created as a reading file
        FILE* card = fopen(file, "r");

        if (!card)
        {
            printf ("No file or nothing in the file.\n");
            return 1;
        }

        //define buffer
        BYTE buffer[512];
        //file pointer
        FILE* newjpg_ptr = NULL;

        // keep count of every file name for new jpgs
        int filename_count = 0;
        //check through 512 bytes at a time - always 4 arguments for fread
        while (fread(buffer, 512, 1, card) == 1)
        {
            //shorthand math to check header file in jpg. Check if file is jpg
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                //if we don't find a first image
                if (newjpg_ptr != NULL)
                fclose(newjpg_ptr);
            {
                sprintf(filenames, "%03i.jpg", filename_count++);
                newjpg_ptr = fopen(filenames, "w");
            }

        }

        if (newjpg_ptr != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, newjpg_ptr);
        }
    }

        fclose(card);
        fclose(newjpg_ptr);
        return 0;
    }

        else
        {

        //If user does not enter 2 arguments quit immediately
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
        }
}