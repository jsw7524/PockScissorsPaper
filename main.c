#include <stdio.h>
#include <stdlib.h>

char Record[2^16]="srp";

int StringMatch(char *Context, char *Pattern)
{
    int I,J,K,L;
    int Counter=0;
    K=strlen(Context);
    L=strlen(Pattern);
    for (I=0; I<K; I++)
    {
        for (J=0; J<L;)
        {
            if (Context[I+J]==Pattern[J])
            {
                J++;
            }
            else
            {
                break;
            }
        }
        if (J==L)
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    //P(A|B)=P(A^B)/P(B)

    char Pattern[4];
    int Previous;
    int Length=3;
    double Rock,Scissor,Paper;

    while (EOF!=scanf("%c",&Record[Length]))
    {
        getchar();
        Length++;
        Record[Length]='\0';
        strncpy(Pattern,Record+Length-2,2);
        Previous=StringMatch(Record,Pattern);
        Pattern[3]='\0';
        Pattern[2]='r';
        Rock=StringMatch(Record,Pattern)/((double)(Previous-1));
        Pattern[2]='s';
        Scissor=StringMatch(Record,Pattern)/((double)(Previous-1));
        Pattern[2]='p';
        Paper=StringMatch(Record,Pattern)/((double)(Previous-1));
        Pattern[2]='\0';

        printf("%s\n",Record);
        printf("S:%f R:%f P:%f\n",Scissor,Rock,Paper);
    }


    //double Result=((double)A/(B-1));
    //printf("%f\n",Result);
    return 0;
}
