#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrcmp(char* prvistringerino, char* drugistringerino)
{
    for(int i = 0; i < strlen(prvistringerino) && i < strlen(drugistringerino); i++)

    {
        if (prvistringerino[i] == drugistringerino[i]) { 
            continue;
        }
        else if (prvistringerino[i] < drugistringerino[i])

        {
            return -1;
        }

        else if (prvistringerino[i] > drugistringerino[i])

        {
            return 1;
        }

    }
    return 0;

}

int main()
{
    char prvistringerino[] = "recenicatri";
    char drugistringerino[] = "recenicatri";
    printf("%d\n", mystrcmp(prvistringerino, drugistringerino));
    printf("%d\n", strcmp(prvistringerino, drugistringerino));
}