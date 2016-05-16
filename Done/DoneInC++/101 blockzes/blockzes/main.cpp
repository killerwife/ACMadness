#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
int main(int argc, char* argv[])
{
    int blocks;
    int locations[25][2];
    int pileCounters[25];
    int piles[25][25];
    int i;
    std::string input="";
    scanf("%d",&blocks);
    getc(stdin);
    for (i = 0; i < blocks; i++)
    {
        locations[i][0] = i;
        locations[i][1] = 0;
        piles[i][0] = i;
        pileCounters[i] = 1;
    }
    while (input != "exit")
    {
        std::string command;
        std::getline(std::cin,input);
        command=input.substr(0,4);
        if (command == "move")
        {            
            int firstBlock, secondBlock;
            std::string subcommand;
            if (input[6] != ' ')
            {
                secondBlock = atoi(input.substr(5, 2).data());
                subcommand = input.substr(8, 4);
                if (input.length() > 13)
                {
                    firstBlock = atoi(input.substr(13, 2).data());
                }
                else
                {
                    firstBlock = atoi(input.substr(13, 1).data());
                }
            }
            else
            {
                secondBlock = atoi(input.substr(5, 1).data());
                subcommand = input.substr(7, 4);
                if (input.length() > 12)
                {
                    firstBlock = atoi(input.substr(12, 2).data());
                }
                else
                {
                    firstBlock = atoi(input.substr(12, 1).data());
                }
            }
            if (firstBlock == secondBlock || locations[firstBlock][0] == locations[secondBlock][0])
            {
                continue;
            }            
            if (subcommand == "onto")
            {
                while (pileCounters[locations[firstBlock][0]]>locations[firstBlock][1] + 1)
                {
                    piles[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]][pileCounters[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]]] = piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1];
                    locations[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]][0] = piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1];
                    locations[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]][1] = pileCounters[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]];
                    pileCounters[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]]++;
                    pileCounters[locations[firstBlock][0]]--;
                }                
                while (pileCounters[locations[secondBlock][0]]>locations[secondBlock][1] + 1)
                {
                    piles[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]][pileCounters[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]]] = piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1];
                    locations[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]][0] = piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1];
                    locations[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]][1] = pileCounters[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]];
                    pileCounters[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]]++;
                    pileCounters[locations[secondBlock][0]]--;
                }
                pileCounters[locations[secondBlock][0]]--;
                piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]]] = secondBlock;
                locations[secondBlock][0] = locations[firstBlock][0];
                locations[secondBlock][1] = pileCounters[locations[firstBlock][0]]++;
            }
            else
            {
                while (pileCounters[locations[secondBlock][0]]>locations[secondBlock][1] + 1)
                {
                    piles[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]][pileCounters[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]]] = piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1];
                    locations[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]][0] = piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1];
                    locations[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]][1] = pileCounters[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]];
                    pileCounters[piles[locations[secondBlock][0]][pileCounters[locations[secondBlock][0]] - 1]]++;
                    pileCounters[locations[secondBlock][0]]--;
                }
                pileCounters[locations[secondBlock][0]]--;
                piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]]] = secondBlock;
                locations[secondBlock][0] = locations[firstBlock][0];
                locations[secondBlock][1] = pileCounters[locations[firstBlock][0]]++;
            }
        }
        else if (command == "pile")
        {
            int firstBlock, secondBlock;
            std::string subcommand;
            if (input[6] != ' ')
            {
                secondBlock = atoi(input.substr(5, 2).data());
                subcommand = input.substr(8, 4);
                if (input.length() > 13)
                {
                    firstBlock = atoi(input.substr(13, 2).data());
                }
                else
                {
                    firstBlock = atoi(input.substr(13, 1).data());
                }
            }
            else
            {
                secondBlock = atoi(input.substr(5, 1).data());
                subcommand = input.substr(7, 4);
                if (input.length() > 12)
                {
                    firstBlock = atoi(input.substr(12, 2).data());
                }
                else
                {
                    firstBlock = atoi(input.substr(12, 1).data());
                }
            }           
            
            if (firstBlock == secondBlock||locations[firstBlock][0]==locations[secondBlock][0])
            {
                continue;
            }
            if (subcommand == "onto")
            {                
                int k = 0;
                int secondPos;
                int secondCount;
                while (pileCounters[locations[firstBlock][0]]>locations[firstBlock][1] + 1)
                {
                    piles[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]][pileCounters[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]]] = piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1];
                    locations[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]][0] = piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1];
                    locations[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]][1] = pileCounters[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]];
                    pileCounters[piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]] - 1]]++;
                    pileCounters[locations[firstBlock][0]]--;
                }       
                secondCount = locations[secondBlock][1];
                secondPos = locations[secondBlock][0];
                while (secondCount + k < pileCounters[secondPos])
                {
                    piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]]] = piles[secondPos][secondCount + k];
                    locations[piles[secondPos][secondCount + k]][0] = locations[firstBlock][0];
                    locations[piles[secondPos][secondCount + k]][1] = pileCounters[locations[firstBlock][0]];
                    pileCounters[locations[firstBlock][0]]++;
                    k++;
                }
                pileCounters[secondPos] -= k;
            }
            else
            {
                int k = 0;
                int secondPos;
                int secondCount = locations[secondBlock][1];
                secondPos = locations[secondBlock][0];
                while (secondCount + k < pileCounters[secondPos])
                {
                    piles[locations[firstBlock][0]][pileCounters[locations[firstBlock][0]]] = piles[secondPos][secondCount + k];
                    locations[piles[secondPos][secondCount + k]][0] = locations[firstBlock][0];
                    locations[piles[secondPos][secondCount + k]][1] = pileCounters[locations[firstBlock][0]];
                    pileCounters[locations[firstBlock][0]]++;
                    k++;
                }
                pileCounters[secondPos] -= k;
            }
        }
        else if (command == "quit")
        {
            for (i = 0; i < blocks; i++)
            {
                printf("%d:", i);
                for (int k = 0; k < pileCounters[i]; k++)
                {
                    printf(" %d", piles[i][k]);
                }
                printf("\n");
            }
            return 0;
        }
    }
    return 0;
}