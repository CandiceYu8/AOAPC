#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

char puzzle[6][6];
char moves[100];
void find_space(int &x, int &y);
bool move_line(int &x, int &y, int sz);
int main()
{
    memset(puzzle, ' ', sizeof(puzzle));
    memset(moves, ' ', sizeof(moves));
    int cnt=0;
    bool con=true;
    bool first=true;
    while(con)
    {
        for(int i=0; i<5; i++)
        {
            cin.getline(puzzle[i], 6);
            if(!strcmp(puzzle[0], "Z"))
            {
                con=false;
                break;
            }
        }
        if(con)
        {
            scanf("%s\n", moves);
            int sz=strlen(moves);
            bool ans=true;
            int x, y;
            find_space(x, y);
            while(moves[sz-1]!='0')
            {
                ans=move_line(x, y, sz);
                if(ans)
                {
                    scanf("%s\n", moves);
                    sz=strlen(moves);
                }
                else
                {
                    break;
                }
            }
            printf("Puzzle #%d:\n", ++cnt);
            if(first)
                first=false;
            else
                printf("\n");

            if(ans)
            {
                ans=move_line(x, y, sz-1);
                if(ans)
                {
                    for(int i=0; i<5; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            printf("%c ", puzzle[i][j]);
                        }
                        printf("%c\n", puzzle[i][4]);
                    }
                }
                else
                    printf("This puzzle has no final configuration.");
            }
            else
                printf("This puzzle has no final configuration.");
        }
        else
            break;
    }
    return 0;
}

void find_space(int &x, int &y)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(puzzle[i][j]==' ')
            {
                x=i;
                y=j;
                return;
            }
        }
    }
}

bool move_line(int &x, int &y, int sz)
{
    bool ans=true;
    for(int i=0; i<sz; i++)
    {
        switch (moves[i])
        {
        case 'A':
            if(x>0)
            {
                puzzle[x][y]=puzzle[x-1][y];
                puzzle[x-1][y]=' ';
                x--;
            }
            else
                ans=false;
            break;
        case 'B':
            if(x<4)
            {
                puzzle[x][y]=puzzle[x+1][y];
                puzzle[x+1][y]=' ';
                x++;
            }
            else
                ans=false;
            break;
        case 'L':
            if(y>0)
            {
                puzzle[x][y]=puzzle[x][y-1];
                puzzle[x][y-1]=' ';
                y--;
            }
            else
                ans=false;
            break;
        case 'R':
            if(y<4)
            {
                puzzle[x][y]=puzzle[x][y+1];
                puzzle[x][y+1]=' ';
                y++;
            }
            else
                ans=false;
            break;
        }
    }
    return ans;
}
