#include<stdio.h>
#include<stdlib.h>

char *GetString();
void ReverseString(char *StringPTR);
void FreeString(char * StringPTR);

int main(){
    char* String = GetString();
    ReverseString(String); 
    FreeString(String);
    return 0;
}

char *GetString()
{
    char *FullString = calloc(0,sizeof(char));
    int LastChar;
    for (int i = 0, CurrentChar; (CurrentChar = getchar()) != EOF;i++)
    {
        FullString = realloc(FullString,sizeof(char)* i + 1);
        FullString[i] = CurrentChar;
        LastChar = i + 1;
    }
    FullString = realloc(FullString,sizeof(char)* LastChar + 1);
    FullString[LastChar]= '\0';
    return FullString;
}

void FreeString(char * StringPTR)
{
    free(StringPTR);
}

void ReverseString(char *StringPTR)
{
    
    int LineTracker = 0, CharCounter = 0;
    while (StringPTR[LineTracker] != '\0')
    {
        CharCounter++;
        if (StringPTR[LineTracker] == '\n')
        {
            for (int i = LineTracker; i > LineTracker - CharCounter; i--)
                printf("%c",StringPTR[i]);
            CharCounter = 0;
        }
        LineTracker++;
    }
}
