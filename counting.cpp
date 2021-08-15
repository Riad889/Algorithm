#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define hello cout<<"Hello\n";
using namespace std::chrono;
int main()
{

    int cc,nn;
    ofstream in;
    in.open("input.txt");
    for (cc = 1; cc <= 10000; cc++)
    {
        nn = rand() % 10000 + 1;
        in<<nn<<endl;
    }
    in.close();
    int n=0,number;
    ifstream myfile;
    myfile.open("input.txt");
    int a[100000],c[100000];
    int i;
    while(myfile>>number)
    {
        a[n++]=(number);
    }
    auto t1 = chrono::steady_clock::now();
    ll maximum=*max_element(a,a+n);
    ll b[maximum+5];
    ll c1[100000];
    memset(b,0,sizeof(b));
    memset(c1,0,sizeof(c));

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

        c1[b[a[i]] - 1] = a[i];
        b[a[i]]--;




    }
    auto t2 = chrono::steady_clock::now();
    double diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t2-t1).count());
    cout<<"Execution time for Counting Sort is: "<<diff1/1000000<<" milliseconds"<<endl;

    //cout<<"Statement count : "<<cnt1<<endl;

}
