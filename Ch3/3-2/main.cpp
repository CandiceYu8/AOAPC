#include <stdio.h>
#include <string.h>
#include <ctype.h>

double weight[]= {0,0,12.01,0,0,0,0,1.008,0,0,0,0,0,14.01,16.00,0,0,0,0,0,0,0,0,0,0,0};
int main()
{
    char str[100];
    int T, cnt=0;
    scanf("%d\n", &T);
    while(T--)
    {
        double sum=0;
        scanf("%s",str);
        for(int i=0; i<(int)strlen(str); i++)
        {
            if((i+1)==(int)strlen(str) || isalpha(str[i+1]))
            {
                sum+=weight[str[i]-'A'];
            }
            else
            {
                cnt=0;
                double c=weight[str[i]-'A'];
                while((i+1)<(int)strlen(str) && isdigit(str[i+1]))
                {
                    cnt=cnt*10+str[i+1]-'0';
                    i++;
                }
                sum+=c*cnt;
            }
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}
