#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the number of items : "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the weight and profit of each items : \n";
    int i;
    int weight[n],profit[n];
    for(i=0; i<n; i++)
    {
        int w,p;
        cin>>w>>p;
        weight[i]=w;
        profit[i]=p;
    }
    int kw;
    cout<<"Enter the knapsack total weight : "<<endl;
    cin>>kw;
    int dp[n+1][kw+1];
    int j;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=kw; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(weight[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],(dp[i-1][j-weight[i-1]])+profit[i-1]);

                continue;
            }
            dp[i][j]=dp[i-1][j];



        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=kw;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum profit = "<<dp[n][kw]<<endl;;
    for(int i=n, j= kw; i>0; i--)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            cout << "Item: "<<i <<" Selected \n";
            j = j- weight[i-1];
        }
    }
}



