#include <stdio.h>
#include <string.h>

int main()
{
    int N, n, j;
    int ans[11];
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &n);
        memset(ans, 0, sizeof(ans));
        for(int i=1; i<=n; i++)
        {
            j = i;
            while(j>=10)
            {
                ans[j%10]++;
                j/=10;
            }
            ans[j]++;
        }
        for(int i=0; i<9; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[9]);
    }
    return 0;
}
