//Libraries that need to be included

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//the main function will take 2 arguments
int main(int argc, char* argv[])
{
if (argc != 2)
    {

        printf("Program cannot continue. \n");
        return 1;
    }

        string key = argv[1];
        int keylength = strlen(key);
        for(int i = 0; i < keylength; i++)
        {
          if (!isalpha(key[i]))
          {
            printf("Invalid key.\n");
            return 1;
        }
}
         //Declare variable string for text
    string plaintext;

    //Get plaintext from the user
    plaintext = get_string("plaintext: ");
    //Print ciphered text
    printf("ciphertext: ");
for (int i = 0, keychar = 0, length = strlen(plaintext); i < length; i++)
    {
        //printing each character
        //if the current character is lowercase
        if (isalpha(plaintext[i]))
        {
            if islower(plaintext[i])
            {
                //print character minus the ascii value mod 26 then add ascii value back
                printf("%c", (plaintext[i] - 'a' + toupper(key[keychar]) -'A') % 26 + 'a');

            }
     //if the current character is uppercase
            else if isupper(plaintext[i])
            {
                printf("%c", (plaintext[i] - 'A' + tolower(key[keychar]) - 'a') % 26 + 'A');
            }
                keychar = (keychar + 1) % keylength;
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }
        //create a new line after printing the complete string
        printf("\n");
}
