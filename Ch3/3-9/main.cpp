#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    string s, t;
    unsigned int lens, lent;
    while(cin>>s>>t)
    {
        lens=s.size();
        lent=t.size();
        bool ans = true;
        for(unsigned i=0, j=0; i<lens; i++, j++)
        {
            while(j<lent && s[i]!=t[j])
                j++;
            if(j>=lent)
                ans=false;
        }
        printf("%s\n", ans?"Yes":"No");
    }
    return 0;
}
