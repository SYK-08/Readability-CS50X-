//Program to find reading level according to Coleman-Liau index.

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{

    //taking input string
    string words = get_string("Type here: ");

    //setting required vars
    int no_of_words = 1;
    int sentence = 0;
    int letters = 0;
    
    //Processing result
    for(int i = 0;i < strlen(words); i++){
        if((words[i] >= 'a' && words[i] <= 'z') || (words[i] >= 'A' && words[i] <= 'Z'))
        {
            letters++;
        }

        else if(words[i] == ' ')
        {
            no_of_words++;
        }

        else if(words[i] == '.' || words[i] == '!' || words[i] == '?')
        {
            sentence++;
        }
    }
    
    //Formula to find Reading level
    int grade = 0.0588 * (100 * (float) letters / (float) no_of_words) - 0.296 * (100 * (float) sentence / (float) no_of_words) - 15.8;
    
    //Declaring output
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
