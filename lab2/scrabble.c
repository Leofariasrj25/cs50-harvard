#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// each user will input their words
// for each word calculate how many points they have
// to calculate the points each letter has a number of points assigned to it
// get every letter's points then sum then all together, this is the player's score
// check the player's scores against each other
// the winner is the one who has the bigger score
// if the scores are equal then print Tie!

// array that holds all of the letter scores. ordered alphabetically
// a is equal to 1, b is equal to 3 and so on.


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// prototype, informs the compiler we will declare/use a function later in the code
int compute_score(string word);

// party happens here
int main(void)
{
    // Get input wordss from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // variable to avoid repetition
    string winner = "Player x";
    
    if (score1 > score2)
    {
        winner = "Player 1";
    }
    else if (score2 > score1)
    {
        winner = "Player 2";
    }
    else
    {
        printf("Tie!\n");
        return 0;
    }
    
    printf("%s wins!\n", winner);
    return 0;
}

int compute_score(string word)
{
    int score = 0;
    
    // computing the size of the word.
    int word_size = strlen(word);
    
    
    // for each letter of the word do
    for (int i = 0; i < word_size; i++)
    {
        
        /* copying to a variable so we do manipulation/calculations without messing
         with original string */
        // at every iteration of the loop this will be reset
        char letter = word[i];

        // checking if it's upper and converting
        if (isupper(letter) != 0)
        {
            // making it lower case for better comparison
            letter = (char) word[i] + 32;
        }
        
        // only do the calculations on letters from a to z
        if (letter >= 97 && letter <= 122)
        {
            /* letters are represented by numbers, ie: ascii */
            // using this fact, we subtract so we get their respective indexes on array POINT
            // because POINTS is ordered using the alphabet's natural ordering
            int letter_score_index = (int) letter - 97; // 97 equals to 'a'
            int letter_score = POINTS[letter_score_index];
        
            score += letter_score;    
        }
        
        
    }

    return score;
}