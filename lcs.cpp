#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n1=a.size();
    int n2=b.size();
    int c[n1][n2];
    int i,j;
    for(i=0;i<=n2;i++)
    {
        for(j=0;j<=n1;j++)
        {
            if(i==0 || j==0)
            {
                c[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
        }
    }
    cout<<c[n1][n2]<<endl;

}
