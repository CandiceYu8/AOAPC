#include <stdio.h>
#include <map>
#include <string>
using namespace std;

map<int, int> Pos;
void solve(int n, const int div, string &ans, int &len);
int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b)==2)
    {
        string ans=".(0)";
        int r=1;
        if(a%b)
            solve(a%b, b, ans, r);
        printf("%d/%d = %d%s\n", a, b, a/b, ans.c_str());
        printf("   %d = number of digits in repeating cycle\n\n", r);
    }
    return 0;
}

void solve(int n, const int div, string &ans, int &len)
{
    ans = ".";
    Pos.clear();
    while(true)
    {
        n *= 10;
        int p = Pos[n];
        if(p == 0)
            Pos[n] = ans.size();
        else // ��������ʼ�ظ�
        {
            len = ans.size()-p;
            if(len>50)
            {
                ans.erase(p+50);
                ans += "...";
            }
            ans.insert(p,"(");
            ans += ")";
            break;
        }
        if(n<div)
        {
            ans += "0";
            continue;
        }
        int divide = n/div, mod = n%div;
        ans += (char)(divide+'0');  //������ת�����ַ���
        n = mod;
        if(n==0)
        {
            ans += "(0)";
            len = 1;
            break;
        }
    }
}
