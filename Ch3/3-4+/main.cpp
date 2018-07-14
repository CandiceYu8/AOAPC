#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    char str[100];
    bool first=true;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%s",str);
        int sz = (int)strlen(str);
        if(first)
            first=false;
        else
            printf("\n");
        for(int i=1; i<=sz; i++)
        {
            if(sz%i) continue;
            bool ans = true;
            for(int j=0; j<i; j++)
            {
                for(int k=i+j; k<sz; k+=i)
                {
                    if(str[j] != str[k])
                    {
                        ans = false;
                        break;
                    }
                }
                if(!ans)
                    break;
            }
            if(ans)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
