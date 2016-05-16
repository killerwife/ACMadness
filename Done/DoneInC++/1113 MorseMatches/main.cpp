#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    int numOfCases;
    string input;
    int numOfWords;
    string dictionary[10000];
    string dictionaryMorse[10000];
    string morseCode[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    int counters[4000];
    int result;
    int first=0;
    scanf("%d", &numOfCases);
    getc(stdin);
    while (numOfCases > 0)
    {
        int i,k,l;
        string blank;
        int temp;
        if(first==0)
        {
            first=1;
        }
        else
        {
            printf("\n");
        }
        getline(cin, blank);
        getline(cin,input);
        scanf("%d", &numOfWords);
        getc(stdin);
        for (i = 0; i < input.length(); i++)
        {
            counters[i] = 0;
        }
        for (i = 0; i < numOfWords; i++)
        {
            getline(cin, dictionary[i]);
        }
        for (i = 0; i < numOfWords; i++)
        {
            for (k = 0; k < dictionary[i].length(); k++)
            {
                dictionaryMorse[i] += morseCode[(dictionary[i][k]-'A')];
            }
        }
        for (i = 0; i < numOfWords; i++)
        {
            int broken=0;
            for (k = 0; k < dictionaryMorse[i].length(); k++)
            {
                if (dictionaryMorse[i][k] != input[k])
                {
                    broken = 1;
                    break;
                }
            }
            if (broken == 0)
            {
                counters[k-1]++;
            }
        }
        for (i = 0; i < input.length(); i++)
        {
            if (counters[i] != 0)
            {
                for (k = 0; k < numOfWords; k++)
                {
                    int broken = 0;
                    for (l = 0; l < dictionaryMorse[k].length()&&l+i<input.length(); l++)
                    {
                        if (dictionaryMorse[k][l] != input[l+i+1])
                        {
                            broken = 1;
                            break;
                        }
                    }
                    if (broken == 0)
                    {
                        counters[l + i]+=counters[i];
                    }
                }
            }
        }
        printf("%d\n", counters[input.length()-1]);
        for (i = 0; i < numOfWords; i++)
        {
            dictionary[i].clear();
            dictionaryMorse[i].clear();
        }
        input.clear();
        numOfCases--;
    }
}
