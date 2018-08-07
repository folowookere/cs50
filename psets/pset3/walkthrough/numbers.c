#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //accepts an input in the form xx-0000
    //letters will be initials
    //numbers will be passcodes
    //two arguments 1.) xx-0000 [the code]
    //2.) Hash integer 1-9999

    if (argc != 3)
    {
        printf("Usage: ./numbers xx-0000 1-9999\n");
        return 1;
    }
    string passcode = argv[1];
    double hash = atol(argv[2]);
    //validate parameters
    if (strlen(passcode) != 7)
    {
        printf("Parameter 1 must be 7 characters\n");
        return 1;
    }

    //set up an array for the numeric code
    char numbers[5];
    char letters[3];
    int x = 0;
    int y = 0;
    int z = 0;
    while(x < 8)
    {
        if(isdigit(passcode[x]))
        {
            numbers[y++] = passcode[x];
            //y++;
        }
        else if (isalpha(passcode[x]))
        {
            letters[z++] = passcode[x];
            //z++;
        }
        x++;
    }
    printf("%s\n", letters);
    printf("%s\n", numbers);
    int code = atoi(numbers);

    //if the string letters is not the same it'll do the pow
    if (strcmp(letters[0], "A") != 0) {
    printf("Your four digit code is %i\n", code);
    double securecode = code / 2;
    printf("Your super secure code is %lf\n", pow(securecode, hash));
    {
        else
        {
            //if letters equal to A
            printf("Your super secure frequency is %i\n", letters[1]);
            //2^n / 12 * 440
        }
    return 0;
}