#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,b,c,d,e,f,g;
    g = 0;
    printf("Simpleminded mindboggling undoable quiz.\n");
    printf("Question 1:\n");
 focus1:   printf("Who was the ringbearer in Lord of the rings.\n");
    printf("1.Frodo 2.Frolo 3.Me 4.Gandalf\n");
    scanf("%d",&a);if(a==1){g++;}if(a<1||a>4){goto focus1;}
  focus2:  printf("Question 2:\n");
    printf("What are the coin names in Harry potter heptalogy:\n");
    printf("1.Knuts Sickles Galeons 2.Knuts Silvers Golds 3. Bronzes Silvers Gold coins \n4.Cents Euros Paperbanknotes\n");
     scanf("%d",&b);if(b==1){g++;}if(b<1||b>4){goto focus2;}
     focus3:  printf("Question 3:\n");
    printf("Where does the Warcraft saga take place\n");
    printf("1.Middleearth 2.Slovakia 3.Azeroth 4.Plain multiverse\n");
     scanf("%d",&c);if(c==3){g++;}if(c<1||c>4){goto focus3;}
     focus4:  printf("Question 4:\n");
    printf("What number is the best:\n");
    printf("1.73 2.42 3.2 4.Pi\n");
    scanf("%d",&d);if(d==2){g++;}if(d<1||d>4){goto focus4;}
    focus5:  printf("Question 5:\n");
    printf("Where is the current best supercomputer:\n");
    printf("1.Japan 2.China 3.America 4.Europe\n");
    scanf("%d",&e);if(e==1){g++;}if(e<1||e>4){goto focus5;}
    printf("Do you like this quiz\n");
    printf("1.Yes 2.Yes 3.Yes 4.Yes\n");
    scanf("%d",&f);
    if(a==1&&b==1&&c==3&&d==2&&e==1){printf("Indeed you know a lot. Congrats. Your score is 5.\n");}

    else{printf("You need to learn more. Your score is only %d\n Answers: \n 1:Frodo 2:Knuts Sickles Galeons 3:Azeroth 4:42 5:Japan.",g);}



    return 0;
}
