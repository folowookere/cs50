// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"


typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

node* first;

int word_counter = 0;
int get_index(char c);
node* create_init_node();
bool freeMemory(node* node_ptr);


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node* node_ptr = first;
    for(int i = 0, length = strlen(word); i <= length; i++)
    {
        if (word[i] == '\0')
        {
            if (node_ptr -> is_word == true)
                return true;
            else
                return false;
        }
        int index = get_index(word[i]);
        if (node_ptr -> children[index] == NULL)
            return false;

        node_ptr = node_ptr -> children[index];
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE* file_ptr = fopen(dictionary, "r");
    if (file_ptr == NULL)
    {
        fclose(file_ptr);
        fprintf(stderr, "Error: Could not open file.\n");
        return false;
    }

    // Global first variable gets new node
    first = create_init_node();

    node* node_ptr = first;

    int index;

    // Check until it reaches the end of the file

    for (char c = fgetc(file_ptr); c != EOF; c = fgetc(file_ptr))
    {
        if (c != '\n')
        {
            // If it's not at the end of the word
            index = get_index(c);
            if (node_ptr ->children[index] == NULL)
                node_ptr->children[index] = create_init_node();
            node_ptr = node_ptr ->children[index];
        }
        else
        {
            // Reached end of the word
            node_ptr -> is_word = true;

            // Increment real word count by 1
            word_counter++;

            // Restart
            node_ptr = first;
        }


    }
         fclose(file_ptr);
     return true;

}

int get_index(char c)
{
    if (c == '\'')
        return 26;
    else if (c >= 'a' && c <= 'z')
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A';

        // If there's an error with the index return -1
        return -1;
}

// Returns a pointer for a node with false

node* create_init_node()
{
    node* node_ptr = malloc(sizeof(node));
    node_ptr -> is_word = false;
    for (int i = 0; i < 27; i++)
    {
        node_ptr -> children[i] = NULL;
    }

    return node_ptr;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    if (freeMemory(first))
        return true;
    return false;
}

bool freeMemory(node* node_ptr)
{
     for (int i = 0; i < 27; i++)
     {
        if (node_ptr -> children[i] != NULL)
        {
            freeMemory(node_ptr -> children[i]);
        }
     }

     free(node_ptr);

     return true;
}