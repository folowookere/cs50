//Libraries that need to be included

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//the main function will take 2 arguments
int main(int argc, string argv[])
{
    //If argc isn't 2, the program won't continue
    if (argc != 2)
    {

        printf("Program cannot continue. \n");
        return 1;
    }

    //convert key to from a string to integer
    int keyint = atoi(argv[1]);
    //right now I'm just checking the key is correct
    printf("%i \n", keyint);

    //Declare variable string for text
    string plaintext;

    //Get plaintext from the user
    plaintext = get_string("plaintext: ");

    //print out ciphertext
    printf("ciphertext: ");
    //right now just iterating over every character in the string
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        //printing each character
        //if the current character is lowercase
        if islower(plaintext[i])
        {
            //print character minus the ascii value mod 26 then add ascii value back
            printf("%c", (plaintext[i] - 'a' + keyint) % 26 + 'a');
        }

        //if the current character is uppercase
        else if isupper(plaintext[i])
        {
            printf("%c", (plaintext[i] - 'A' + keyint) % 26 + 'A');
        }

        else
        {
            printf("%c", plaintext[i]);
        }

        //create a new line after printing the complete string
        printf("\n");

    }