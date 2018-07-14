#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

bool first=true;
int r, c, seq=0;
int number[11][11];
char net[11][11];
int main()
{
    int i, j, cnt=0;
    cin >> r;
    char ch;
    while(r!=0)
    {
        cnt=0;
        memset(number, 0, sizeof(number));
        memset(net, ' ', sizeof(net));
        cin >> c;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                cin >> ch;
                net[i][j] = ch;
                if(i==0 || j==0 || (i>0 && net[i-1][j]=='*') || (j>0 && net[i][j-1]=='*'))
                {
                    if(ch!='*')
                        number[i][j]=(++cnt);
                }
            }
        }

        if(first)
            first=false;
        else
            cout << endl;
        printf("puzzle #%d:\n", ++seq);
        cout << "Across" << endl;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(number[i][j])
                {
                    if(j==0 || (j>0 && net[i][j-1]=='*'))
                    {
                        printf("%3d.", number[i][j]);
                        int y=j;
                        while(y<c && net[i][y]!='*')
                        {
                            cout << net[i][y];
                            y++;
                        }
                        cout << endl;
                    }
                }
            }
        }
        cout << "Down" << endl;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(number[i][j])
                {
                    if(i==0 || (i>0 && net[i-1][j]=='*'))
                    {
                        printf("%3d.", number[i][j]);
                        int x=i;
                        while(x<r && net[x][j]!='*')
                        {
                            cout << net[x][j];
                            x++;
                        }
                        cout << endl;
                    }
                }
            }
        }
        cin >> r;
    }
    return 0;
}
