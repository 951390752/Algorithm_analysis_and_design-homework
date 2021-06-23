#include <bits/stdc++.h>
using namespace std;
int n; //集装箱数
int cw; // 当前载重量, current weight
int bestw; //最优载重重量
int r;  //剩余集装箱重量
int c1; //第一艘轮船的载重量
int c2; //第二艘轮船的载重量
int x[100]; //当前解
int bestx[100]; //当前最优解
int w[100]; //集装箱重量数组
void OutPut()
{
    int restweight = 0;
    for(int i = 1; i <= n; ++i)
        if(bestx[i] == 0)
           restweight += w[i];
    if(restweight > c2)
        cout<<"不能装入"<<endl;
    else
    {
        cout<<"船1装入的货物为:";
        for(int i = 1; i <= n; ++i)
            if(bestx[i] == 1)
               cout<<" "<<i;
        cout<<endl<<"船2装入的货物为:";
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
    if(cw + w[i] <= c1) //约束条件
    {
        cw += w[i];
        x[i] = 1;
        BackTrack(i + 1);
        x[i] = 0;
        cw -= w[i];
    }
    if(cw + r > bestw) //限界函数
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
    cout<<"请输入箱子个数：";
    cin>>n;

    cout<<"请输入两艘船的最大载重量：";
    cin>>c1>>c2;

    cout<<"请输入箱子的重量：";
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

