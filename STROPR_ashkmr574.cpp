/**
   Problem: Chef and Strange Operations.
   Tags: Combinatorics,Modular Multiplicative Inverse

**/
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long int LL;
#define M 1000000007
LL power(LL a,LL b)
{
    LL tmp;
    if(b==0)
        return 1;
    tmp=power(a,LL(b/2));
    if(b%2==0)
        return (((tmp%M)*tmp)%M);
    else
        return ((((a*tmp)%M)*tmp)%M);
}
int main()
{
    int t;
    LL n,x,m,p,ans,k,l,ans1,ans2,ans4;
    LL a[100000];
    LL i;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        ans1=1;
        ans2=1;
        l=1;
        p=1;
        scanf("%lld%lld%lld",&n,&x,&m);
            k=m;
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        if(x==1)
        {
                printf("%lld\n",a[0]%M);
        }
        else
        {
            for(i=x-2;i>=0;i--)
            {
                ans1=(ans1*(k%M))%M;
                ans1=(ans1*power(l,M-2))%M;
                ans=ans+(ans1*(a[i]%M))%M;
                ans=ans%M;
                k++;
                l++;
                //printf("%lld %lld %lld\n",ans1,ans2,ans);
            }
            printf("%lld\n",(ans+a[x-1])%M);
        }
    }
    return 0;
}
