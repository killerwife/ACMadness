#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int main(int argc, char* argv[])
{
    char input[500000];
    int escapedLine = 0;
    int sumToFind = 0;
    int i = 0;
    int depth = 0;
    int isEmpty = 0;
    int doubleEscape = 0;
    int foundNum = 0;
    int negative = 0;
    int lastAdded = 0;
    int stack[100000];
    stack[0] = 0;
    while (escapedLine != 0 || fgets(input, 500000, stdin) != NULL)
    {
        if (escapedLine == 0)
        {
            if (input[0] == '-')
            {
                for (i = 1; input[i] != ' '; i++)
                {
                    sumToFind = sumToFind * 10 + (input[i] - '0');
                }
                sumToFind = -sumToFind;
            }
            else
            {
                for (i = 0; input[i] != ' '; i++)
                {
                    sumToFind = sumToFind * 10 + (input[i] - '0');
                }
            }
            escapedLine = 1;
        }
        else if (escapedLine == 1)
        {
            while (input[i] != '\n')
            {
                int temp = input[i];
                if (temp == ' ')
                {
                    i++;
                    continue;
                }
                else if (temp == '(')
                {
                    doubleEscape = 0;
                    isEmpty++;
                    depth++;
                    stack[depth] = stack[depth - 1];
                    i++;
                }
                else if (temp == ')')
                {
                    doubleEscape++;
                    depth--;
                    if (doubleEscape > 1)
                    {
                        isEmpty = 0;
                    }
                    else if (isEmpty == 2)
                    {
                        if (sumToFind == stack[depth])
                        {
                            foundNum = 1;
                            escapedLine = 2;
                            i++;
                            while (depth != 0)
                            {
                                int docas = input[i];
                                switch (docas)
                                {
                                case '\n':
                                    fgets(input, 500000, stdin);
                                    i = 0;
                                    break;
                                case '(':
                                    depth++;
                                    i++;
                                    break;
                                case ')':
                                    depth--;
                                    i++;
                                    break;
                                default:
                                    i++;
                                    break;
                                }
                                                                  
                            }
                            i--;
                            break;
                        }
                    }
                    if (depth == 0)
                    {
                        escapedLine = 2;
                        break;
                    }
                    i++;
                }
                else if (temp == '-')
                {
                    negative = 1;
                    i++;
                }
                else
                {
                    isEmpty = 0;
                    int number = 0;
                    while (input[i] >= '0')
                    {
                        number = number * 10 + (input[i] - '0');
                        i++;
                    }
                    number = negative == 1 ? -number : number;
                    stack[depth] += number;
                    negative = 0;
                }
            }
            if (input[i] == '\n')
            {
                fgets(input, 500000, stdin);
                i = 0;
            }
        }
        else
        {
            if (foundNum == 1)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
            stack[0] = 0;
            escapedLine = 0;
            sumToFind = 0;
            i = 0;
            depth = 0;
            isEmpty = 0;
            doubleEscape = 0;
            foundNum = 0;
            lastAdded = 0;
        }
    }
    return 0;
}