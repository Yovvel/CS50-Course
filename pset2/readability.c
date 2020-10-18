// Coleman-Liau index is een index formule om te bepalen welk leesniveau een bepaalde tekst heeft
// de formule is als volgt: index = 0.0588 * L - 0.296 * S - 15.8
// waarbij L het gemiddelde aantal letters per 100 woorden in de tekst is en S het gemiddelde aantal zinnen per 100 woorden is.
// deze methode geldt voor amerikaanse teksten.
// Voor nederland kun je beter flesch kincaid methode gebruiken


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int lettercount();
int wordcount();
int sentencecount();
int colemanindexcalc();

int main (void)
{
  string  text = get_string("text: ");
  int letters = lettercount(text);
  int words = wordcount(text);
  int sentence = sentencecount(text);
  int colemanindex = colemanindexcalc(letters, words, sentence);

  if (colemanindex >= 16)
    {
        printf("Grade 16+");
    }
    else if (colemanindex <= 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i\n",colemanindex);
    }
}


int lettercount (string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int wordcount (string text)
{
    int words = 1;              //starts with 1, because the first word begins without a space.
    for (int i = 0; i < strlen(text); i++)
    {
        if(isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int sentencecount (string text)
{
    int sentence = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '!')
        {
            sentence++;
        }
    }
    return sentence;
}

int colemanindexcalc(int letters, int words, int sentence)
{
    // gemiddeld aantal letters per 100 woorden: letter/woorden*100
    float avgLetters = letters * 100 / words;
    // gemiddelde aantal zinnen per 100 woorden is
    float avgSentence = sentence * 100 / words;
    // index = 0.0588 * L - 0.296 * S - 15.8
    float index = round(0.0588 * avgLetters - 0.296 * avgSentence - 15.8);

    return index;
}
