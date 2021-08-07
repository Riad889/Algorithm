#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the object number : "<<endl;
    int n;
    cin>>n;
    int i;
    int w[n+1],p[n+1];
    double r[n+1];
    cout<<"Enter the weights and profits : "<<endl;
    for(i=0;i<n;i++)
    {
        int weight,profit;
        cin>>weight>>profit;
        double ratio=profit/(weight*1.0);
        w[i]=weight,p[i]=profit,r[i]=ratio;


    }
    int j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(r[i]<r[j])
            {
                swap(r[i],r[j]);
                swap(w[i],w[j]);
                swap(p[i],p[j]);
            }
        }
    }
    cout<<"Enter the knapsack size : "<<endl;
    int kp;
    cin>>kp;
    double total_profit=0.0;
    for(i=0;i<n;i++)
    {
        if(w[i]<=kp)
        {
            kp-=w[i];
            total_profit+=(p[i]);
        }
        else
        {
            total_profit+=(p[i]*(kp/(w[i]*1.0)));
            break;
        }

    }
    cout<<"Total profit = "<<total_profit<<endl;

}
