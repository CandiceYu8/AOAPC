#include <stdio.h>
#include <string.h>

int m, n, N, dif;
char arr[64][1024];
int cnt[27];
int main()
{
    int i, j;
    scanf("%d\n", &N);
    while(N--)
    {
        scanf("%d %d", &m, &n);
        for(i=0; i<m; i++)
            scanf("%s", arr[i]);
        dif=0;
        for(j=0; j<n; j++)
        {
            memset(cnt, 0, sizeof(cnt));
            for(i=0; i<m; i++)
                cnt[arr[i][j]-'A']++;
            int max=cnt[0];
            char ans='A';
            if(max<cnt[2])
            {
                max=cnt[2];
                ans='C';
            }
            if(max<cnt[6])
            {
                max=cnt[6];
                ans='G';
            }
            if(max<cnt[19])
            {
                max=cnt[19];
                ans='T';
            }
            dif+=(m-max);
            printf("%c", ans);
        }
        printf("\n%d\n", dif);
    }
    return 0;
}

