#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define hello cout<<"Hello\n";
using namespace std::chrono;
int main()
{
    //cout<<"Enter the amount of number :\n";
    /*for creating text file
    int cc,nn;
    ofstream in;
    in.open("input_10000.txt");


    for (cc = 1; cc <= 10000; cc++)
    {
        nn = rand() % 10000 + 1;
        in<<nn<<endl;
    }
    in.close();
    */

   /*for read the file
    ll n=0,number;
    ifstream myfile;
    myfile.open("input_1000.txt");
    ll a[100000],c[100000];
    int i;
    while(myfile>>number)
    {
        a[n++]=(number);
    }
    */
    cout<<"Enter the amount of number : "<<endl;
    int n;
    cin>>n;
    int a[n+1];
    int i;
    cout<<"Enter the elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll maximum=*max_element(a,a+n);
    ll b[maximum+5];
    ll c[100000];
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));

    for(i=0; i<n; i++)
    {

        b[a[i]]++;

    }

    for(i=1; i<=maximum; i++)
    {

        b[i]=b[i-1]+b[i];
    }
    int cnt1=1;

    for(i=n-1; i>=0; i--)
    {
        //cout<<"position = "<<b[a[i]]<<endl;
        c[b[a[i]] - 1] = a[i];
        b[a[i]]--;
        //cnt1+=4;



    }
    //cnt1+=1;
    cout<<"Sorted List in ascending : "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<"\n";

    //cout<<"Statement count : "<<cnt1<<endl;

}
