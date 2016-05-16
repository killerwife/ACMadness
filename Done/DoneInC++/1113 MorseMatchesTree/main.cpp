#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node
{
    int value;
    Node* dot;
    Node* dash;
    Node(){ value = 0; dot = nullptr; dash = nullptr; };
    Node(int i){ value = i; dot = nullptr; dash = nullptr; };
    ~Node(){};
};

class Trie
{
public:
    Node* root;
    long long count;
    Trie()
    {
        root = new Node();
        count = 1;
    }
    ~Trie()
    {
        int i = 0;
        int k = 1;
        Node** timeToTidyUp = new Node*[count];
        timeToTidyUp[0] = root;
        int *beenThere = new int[count];
        for (i = 0; k < count; i++)
        {
            if (timeToTidyUp[i]->dash != nullptr)
            {
                timeToTidyUp[k] = timeToTidyUp[i]->dash;
                k++;
            }
            if (timeToTidyUp[i]->dot != nullptr)
            {
                timeToTidyUp[k] = timeToTidyUp[i]->dot;
                k++;
            }
        }
        for (i = count-1; i >0; i--)
        {
            delete timeToTidyUp[i];
        }
        delete[] beenThere;
        delete[] timeToTidyUp;
    };
    void addWord(string input)
    {
        int i;
        Node* temp = root;
        for (i = 0; i < input.length(); i++)
        {
            if (input[i] == '-')
            {
                if ((*temp).dash == nullptr)
                {
                    if (i == input.length() - 1)
                    {
                        (*temp).dash = new Node(1);
                        count++;
                        break;
                    }
                    else
                    {
                        (*temp).dash = new Node();
                        temp = temp->dash;
                        count++;
                    }
                }
                else
                {
                    if (i == input.length() - 1)
                    {
                        (*((*temp).dash)).value++;
                        break;
                    }
                    else
                    {
                        temp = (*temp).dash;
                    }
                }
            }
            else
            {
                if ((*temp).dot == nullptr)
                {
                    if (i == input.length() - 1)
                    {
                        (*temp).dot = new Node(1);
                        count++;
                        break;
                    }
                    else
                    {
                        (*temp).dot = new Node();
                        temp = temp->dot;
                        count++;
                    }
                }
                else
                {
                    if (i == input.length() - 1)
                    {
                        (*((*temp).dot)).value++;
                        break;
                    }
                    else
                    {
                        temp = (*temp).dot;
                    }
                }
            }
        }
    };
};

int main()
{
    int numOfCases;
    string input;
    int numOfWords;
    string dictionary[10000];
    string dictionaryMorse[10000];
    string morseCode[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    int counters[4000];
    char *binaryTree = new char[2097153];
    int result;
    int first = 0;
    scanf("%d", &numOfCases);
    getc(stdin);
    while (numOfCases > 0)
    {
        int i, k, l;
        string blank;
        Trie trees = Trie();
        if (first == 0)
        {
            first = 1;
        }
        else
        {
            printf("\n");
        }
        memset(binaryTree, 0, 2097153 * sizeof(*binaryTree));
        getline(cin, blank);
        getline(cin, input);
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
                dictionaryMorse[i] += morseCode[(dictionary[i][k] - 'A')];
            }
        }
        /*for (i = 0; i < numOfWords; i++)
        {
            int valueInTree = (int)dictionaryMorse[i][0] - '-' + 1;
            for (k = 1; k < dictionaryMorse[i].length(); k++)
            {
                valueInTree = valueInTree * 2 + (int)dictionaryMorse[i][k] - '-';
            }
            binaryTree[valueInTree]++;
        }
        int valueInInput = (int)input[0] - '-' + 1;
        counters[0] += binaryTree[valueInInput];
        for (i = 1; i < 20&&i<input.length(); i++)
        {
            valueInInput = valueInInput * 2 + (int)input[i] - '-';
            counters[i] += binaryTree[valueInInput];
        }
        for (i = 0; i < input.length()-1; i++)
        {
            if (counters[i] != 0)
            {
                valueInInput = (int)input[i+1] - '-' + 1;
                counters[i + 1] += binaryTree[valueInInput]*counters[i];
                for (k = 1; k < 20 && k+i+1<input.length(); k++)
                {
                    valueInInput = valueInInput * 2 + (int)input[k+i+1] - '-';
                    counters[k + i + 1] += binaryTree[valueInInput]*counters[i];
                }
            }
        }*/
        for (i = 0; i < numOfWords; i++)
        {
            trees.addWord(dictionaryMorse[i]);
        }
        Node* temp = trees.root;
        for (i = 0; i < input.length(); i++)
        {
            if (input[i] == '-')
            {
                if ((*temp).dash == nullptr)
                {
                    break;
                }
                else
                {
                    temp = (*temp).dash;
                    counters[i] += (*temp).value;
                }
            }
            else
            {
                if ((*temp).dot == nullptr)
                {
                    break;
                }
                else
                {
                    temp = (*temp).dot;
                    counters[i] += (*temp).value;
                }
            }
        }
        for (i = 0; i < input.length(); i++)
        {
            if (counters[i] > 0)
            {
                Node* temp = trees.root;
                for (k = i + 1; k < input.length(); k++)
                {
                    if (input[k] == '-')
                    {
                        if ((*temp).dash == nullptr)
                        {
                            break;
                        }
                        else
                        {
                            temp = (*temp).dash;
                            counters[k] += (*temp).value*counters[i];
                        }
                    }
                    else
                    {
                        if ((*temp).dot == nullptr)
                        {
                            break;
                        }
                        else
                        {
                            temp = (*temp).dot;
                            counters[k] += (*temp).value*counters[i];
                        }
                    }
                }
            }
        }
        printf("%d\n", counters[input.length() - 1]);
        for (i = 0; i < numOfWords; i++)
        {
            dictionary[i].clear();
            dictionaryMorse[i].clear();
        }
        input.clear();
        numOfCases--;
    }
    delete[]binaryTree;
}
