#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // creating the variables for all the types of data we'll manipulate
    int lama_population, start_size, end_size, years = 0;

    // will ask the user for the start and repeat until a valid answer is typed
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);
    
    // same thing for the end_size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // lama_population will hold the initial_size and then be altered with each year
    lama_population = start_size;
    
    // calculate until wer reach a population equal to the end_size
    while (lama_population < end_size)
    {
        // every year these two change as population grows
        int lamas_born = lama_population / 3;
        int lamas_pass_away = lama_population / 4;
    
        lama_population = lama_population + lamas_born - lamas_pass_away;
        years++;
        
    }
    
    // printing the years it took to reach the end size
    printf("Years: %d\n", years);
    
}