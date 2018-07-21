//header
#include <stdio.h>
#include <cs50.h>

int main (void)
{

//int is return type - void means no parameters inside parentheses
//declare global variable for height
    int height;
    do
    {
//get positive height from user
    height = get_int("Enter a height: ");
    }
//height should be less than or equal to 23 and greater than 0
    while (height < 0 || height > 24 );

//print out rows
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i; j++) {
         printf(" ");
        }
    for (int j = 0; j < i + 1; j++) {
        printf("#");
      }
        printf("\n");
  }
}
