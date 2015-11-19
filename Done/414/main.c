#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    int i=0;
    int counter=0;
    char *line;
	line=(char*)malloc(26*sizeof(char));
    scanf("%d",&a);
    fgetc(stdin);
    int temprows=a;
    while(a!=0)
    {
            int minimum=30;
            int all = 0;
        while(a>0)
        {
			line=fgets(line,26,stdin);
			        fgetc(stdin);
            while(i<25)
            {
                if(line[i]==' ')
                {
                    counter++;
                }
                i++;
            }
            if(minimum>counter)
            {
                minimum=counter;
            }
            all=all+counter;
            i=0;
            counter=0;
            a--;
        }
        all=all-minimum*temprows;
        printf("%d\n",all);
        scanf("%d",&a);
        fgetc(stdin);
        temprows=a;
    }
    free(line);
    return 0;
}
