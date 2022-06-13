//Kacper Kulpa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

char Stos[100];
int top=-1;

bool niepuste()
{
    return (top!=-1);
}

void Push (char y)
{
    if (top <100)
        {
        top=top+1;
        Stos[top]=y;
        }
}

char Top() {
    if (niepuste())
        return Stos[top];
}

void Pop(){
    if(niepuste())
        top=top-1;
}

bool czyliczba (char x)
{
    int y=x;
    return (y>47 && y<58);
}

int priorytet(char z){
    int w=0;
    if( z=='+' || z=='-' )
        w=1;
    if( z=='*' || z=='/')
        w=2;
    if( z=='^' )
        w=3;
    return w;
}

struct ONP
{
    char typ;
    float val;
    struct ONP *next;
};

typedef struct ONP * lista;

lista
    First = NULL,
    p = NULL,
    q;

float oblicz (float a, float b, char z)
{
    float w=0;
    if(z=='+')
        w=a+b;
    if(z=='-')
        w=a-b;
    if(z=='*')
        w=a*b;
    if(z=='/')
        w=a/b;
    if(z=='^')
        {
            int i=0;
            w=1;
            while(i<b)
            {
                w=w*a;
                i++;
            };
        }
    return w;
}

int main()
{
    char x[100];
    FILE * plik;
    plik = fopen("Obliczenia.txt","w");
    printf("------------ K A L K U L A T O R ------------\n");
    printf("\nDozwolone dzialania: + | - | * | / | ^ | () \n");
    printf("\nWpisz rownanie: ");
    scanf("%s", &x);
    int i=0, d=0;
    while (x[i]!=0)
    {
        i++;
        d++;
    };
    printf("\n");

    q=(lista) malloc(sizeof(struct ONP));
    q->next=NULL;
    First=p=q;

    i=0;
    while(x[i]!='#')
    {
        fprintf(plik,"%s:\n",x);
        while (i<d)
        {
            if (x[i]=='(')
            {
                Push(x[i]);
            }
            else
            {
                if(czyliczba(x[i]))
                {
                    float liczba=0;
                    while(i<d && czyliczba(x[i]))
                    {
                        liczba=liczba*10+(x[i]-'0');
                        i++;
                    };
                    i--;

                    q=(lista) malloc(sizeof(struct ONP));
                    q->next=NULL;
                    q->typ='l';
                    q->val=liczba;
                    p->next=q;
                    p=q;
                }
                else
                {
                    if (x[i]==')')
                    {
                        while (niepuste() && Top()!='(')
                        {
                            q=(lista) malloc(sizeof(struct ONP));
                            q->next=NULL;
                            q->typ=Top();
                            p->next=q;
                            p=q;
                            Pop();
                        }
                        if(niepuste())
                            Pop();
                    }
                    else
                    {
                        if (x[i]=='-' && !czyliczba(x[i-1]))
                        {
                            float liczba=0;
                            i++;
                            while(i<d && czyliczba(x[i]))
                            {
                                liczba=liczba*10+(x[i]-'0');
                                i++;
                            };
                            liczba=-liczba;
                            --i;

                            q=(lista) malloc(sizeof(struct ONP));
                            q->next=NULL;
                            q->typ='l';
                            q->val=liczba;
                            p->next=q;
                            p=q;
                        }
                        else
                        {
                            while (niepuste() && priorytet(Stos[top])>=priorytet(x[i]))
                            {
                                q=(lista) malloc(sizeof(struct ONP));
                                q->next=NULL;
                                q->typ=Top();
                                p->next=q;
                                p=q;
                                Pop();
                            }
                            Push(x[i]);
                        };
                    };

                }
            }
            i++;
        };

        while (niepuste())
            {
                q=(lista) malloc(sizeof(struct ONP));
                q->next=NULL;
                q->typ=Top();
                p->next=q;
                p=q;
                Pop();
            }

        p=First->next;
        printf("Rownanie w ONP:\t\n");
        while (p!=NULL)
        {
            if(p->typ=='l')
                printf("%g ", p->val);
            else
                printf("%c ", p->typ);
            p = p->next;
        };

        float liczby[100];
        int j=-1;
        p=First->next;
        printf("\n\nObliczenia:\n");
        while (p!=NULL)
        {
            if(p->typ=='l')
            {
                j++;
                liczby[j]=p->val;
            }
            else
            {
                printf("%g%c%g=", liczby[j-1], p->typ, liczby[j]);
                fprintf(plik,"%g%c%g=", liczby[j-1], p->typ, liczby[j]);
                liczby[j-1]=oblicz(liczby[j-1], liczby[j], p->typ);
                printf("%g\n", liczby[j-1]);
                fprintf(plik,"%g\n", liczby[j-1]);
                j=j-1;
            }
            p = p->next;
        };

        printf("\n\nWynik:\n");
        printf("%s=%g", x,liczby[j]);
        fprintf(plik,"\n\t%s=%g", x,liczby[j]);
        fprintf(plik,"\n\n\n");

        printf("\n\n\n");

        printf("------------ K A L K U L A T O R ------------\n");
        printf("\n\t     (Aby wyjsc wpisz #)\n");
        printf("\nWpisz rownanie: ");
        scanf("%s", &x);
        i=0;
        d=0;
        while (x[i]!=0)
        {
            i++;
            d++;
        };
        printf("\n");
        i=0;

        q=(lista) malloc(sizeof(struct ONP));
        q->next=NULL;
        First=p=q;
    };
    fclose(plik);
    return 0;
}
