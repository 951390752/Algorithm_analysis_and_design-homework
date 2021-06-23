#include <bits/stdc++.h>
using namespace std;
int n; //��װ����
int cw; // ��ǰ������, current weight
int bestw; //������������
int r;  //ʣ�༯װ������
int c1; //��һ���ִ���������
int c2; //�ڶ����ִ���������
int x[100]; //��ǰ��
int bestx[100]; //��ǰ���Ž�
int w[100]; //��װ����������
void OutPut()
{
    int restweight = 0;
    for(int i = 1; i <= n; ++i)
        if(bestx[i] == 0)
           restweight += w[i];
    if(restweight > c2)
        cout<<"����װ��"<<endl;
    else
    {
        cout<<"��1װ��Ļ���Ϊ:";
        for(int i = 1; i <= n; ++i)
            if(bestx[i] == 1)
               cout<<" "<<i;
        cout<<endl<<"��2װ��Ļ���Ϊ:";
        for(int i = 1; i <= n; ++i)
            if(bestx[i] != 1)
               cout<<" "<<i;

    }
}
void BackTrack(int i)
{
    if(i > n)
    {
        if(cw > bestw)
        {
            for(int i = 1; i <= n; ++i)
                bestx[i] = x[i];
            bestw = cw;
        }
        return;
    }
    r -= w[i];
    if(cw + w[i] <= c1) //Լ������
    {
        cw += w[i];
        x[i] = 1;
        BackTrack(i + 1);
        x[i] = 0;
        cw -= w[i];
    }
    if(cw + r > bestw) //�޽纯��
    {
        x[i] = 0;
        BackTrack(i + 1);
    }
    r += w[i];

}
void Initialize()
{
    bestw = 0;
    r = 0;
    cw = 0;
    for(int i = 1; i <= n; ++i)
        r += w[i];
}
void InPut()
{
    cout<<"���������Ӹ�����";
    cin>>n;

    cout<<"���������Ҵ��������������";
    cin>>c1>>c2;

    cout<<"���������ӵ�������";
    for(int i = 1; i <= n; ++i)
       cin>>w[i];

}
int main()
{
    InPut();
    Initialize();
    BackTrack(1);
    OutPut();
}
