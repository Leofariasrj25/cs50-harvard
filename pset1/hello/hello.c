// lib to get basic input and send output from/to the user
#include <stdio.h>
// lib to get have access to get_string
#include <cs50.h>

int main(void) 
{
    // create a variable to hold the user input returned by get_string
    string name = get_string("What's your name?\n");

    // we print the value contained inside the variable next to hello world
    // %s specifies it'll include an string inside the target string
    printf("hello world, %s\n", name);
}
