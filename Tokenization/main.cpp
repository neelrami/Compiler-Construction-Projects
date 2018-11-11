#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
    char expression[100];
    char tokens[100][100];
    int no_of_tokens=0;
    int no_of_char_tokens=0;
    int length=0;
    int i=0;
    int isprevcharalnum=1;

    cout<<"Enter any expression"<<endl;

    gets(expression);

    length=strlen(expression);

    for(i=0;i<length;i++)
    {
        if(isalnum(expression[i]))
        {
            if(isprevcharalnum==0)
            {
                tokens[no_of_tokens][no_of_char_tokens]='\n';
                no_of_tokens++;
                no_of_char_tokens=0;
            }
            tokens[no_of_tokens][no_of_char_tokens]=expression[i];
            no_of_char_tokens++;
            isprevcharalnum=1;
        }
        else
        {
            if(expression[i]==' ')
            {

            }
            else
            {
                if(isprevcharalnum==1)
                  {
                    tokens[no_of_tokens][no_of_char_tokens]='\n';
                    no_of_tokens++;
                    no_of_char_tokens=0;
                }
                tokens[no_of_tokens][no_of_char_tokens]=expression[i];
                no_of_char_tokens++;
                isprevcharalnum=0;
            }
        }
    }
    for(i=0;i<no_of_tokens+1;i++)
    {
        cout<<"Token No. "<<i;
        cout<<" "<<tokens[i];
    }
    return 0;
}
