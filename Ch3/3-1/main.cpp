#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int n, sum=0, ans=0;
    scanf("%d\n", &n);
    while(n--)
    {
        sum=0;
        ans=0;
        scanf("%s", str);
        for(int i=0; i<(int)strlen(str); i++)
        {
            if(str[i]=='X')
                ans=0;
            else
                sum+=(++ans);
        }
        printf("%d\n",sum);
    }
    return 0;
}
