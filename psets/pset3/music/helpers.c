// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    int duration = (numerator * 8 / denominator);

    return duration;

    // TODO
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    float frequency = 0;
    int semitonesAway = 0;
    int A4 = 440;

    if (note[0] == 'A' && note[1] == '4')
    {
        frequency = A4;
    }

    if (note[0] == 'A')
    {
        semitonesAway = 10;
    }

    if (note[0] == 'B')
    {
        semitonesAway = 12;
    }

    if (note[0] == 'C')
    {
        semitonesAway = 1;
    }

    if (note[0] == 'D')
    {
        semitonesAway = 3;
    }

    if (note[0] == 'E')
    {
        semitonesAway = 5;
    }

    if (note[0] == 'F')
    {
        semitonesAway = 6;
    }

    if (note[0] == 'G')
    {
        semitonesAway = 8;
    }

// Add in calculation for notes that have sharp and flat
    if (note[1] == '#')
    {
        semitonesAway++;
    }

    else if (note[1] == 'b')
    {
        semitonesAway--;
    }

// Calculate the different octaves
    int octave = note[strlen(note) - 1] - '0';


// Calculate frequency of given note
    frequency = pow(2, (semitonesAway - 10) / (float)12) * A4;

// Round frequency
    int final = round(frequency * (pow(2, octave - 4)));

    return final;
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{

    return !strlen(s);
    // TODO
}
