#include <stdio.h>
void count(int num,int *addAll,int *mulAll){
    int i = num/100;   //��λ��
    int j = num/10%10; //ʮλ��
    int k = num%10;    //��λ��
    (*addAll) += i+j+k;
    (*mulAll) *= i*j*k;
    return;
}
int main()
{
    //����3λ������λ��������1�����ֲ����ظ�������Ϊ123
    //ͬ�� ���Ϊ987���ݱ����� i���Ϊ987/3
    int i;
    for(i = 123; i <=987/3; i++)
    {
        int addAll=0;
        int mulAll=1;
        count(  i, &addAll, &mulAll);
        count(i*2, &addAll, &mulAll);
        count(i*3, &addAll, &mulAll);
        //1-9�ĺ�ֻ���� 9*10/2
        //1-9�Ļ�ֻ���� 2*3*4*5*6*7*8*9
        if(addAll == 9*10/2 && mulAll == 2*3*4*5*6*7*8*9)
            printf("%d %d %d\n", i, i*2, i*3);
    }
    return 0;
}
