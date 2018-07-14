#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//    int a, b, c, i, cnt=0;
//    while(scanf("%d %d %d", &a, &b, &c)==3 && (a || b || c))
//    {
//        printf("Case %d: %d.", ++cnt, a/b);
//        a = a%b;
//        for(i=1; i<c; i++)
//        {
//            printf("%d", a*10/b);
//            a = a*10%b;
//        }
//        if(a*10%b*10/b < 5)
//            printf("%d\n", a*10/b);
//        else
//            printf("%d\n", a*10/b+1);
//    }

    int a,b,c,i=0;
    while (scanf("%d%d%d",&a,&b,&c)==3 && a && b && b<=pow(10.0,6.0) && c && c<=100) {
        printf("Case %d: %.*lf\n",++i,c,(double)a/b);
    }
    return 0;
}
