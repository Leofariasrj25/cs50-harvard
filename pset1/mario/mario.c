#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n_whitespaces, height, n_blocks = 0;
    char block_sprite = '#';
    char void_space = ' ';

    do
    {
        height = get_int("Height: "); // gets the user input
    }
    while (height > 8 || height <= 0); // will keep asking until a number between 1 and 8 is supplied
    
    // we assume the width is equal to the height
    int line_width = height + 2; // making space for the gap 
    n_whitespaces = height - 1;
    n_blocks = 2; // we start with one block for each side
    
    // for each line do:
    for (int i = 0; i < height; i++) 
    {
        // printing the white spaces
        for (int j = 0; j < n_whitespaces; j++) 
        {
            printf(" ");
        }    
        
        // printing the blocks
        for (int z = 0; z <= n_blocks; z++) 
        {
            
            // if we reach the middle point, then print the gap and continue
            if (z == n_blocks / 2)
            {
                printf("%c%c", void_space, void_space);
                continue;
            }
            else 
            {
                printf("%c", block_sprite);
            }
        }
        
        n_blocks += 2; // one more block for each side
        n_whitespaces--; // one less white space for each side
        printf("\n"); // jump to next line
    }
}