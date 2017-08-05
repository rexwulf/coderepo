#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

vector<unsigned int> zero(vector<unsigned int> a)
{
    bool f=false;
    int size=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=0)
        {
            f=true;
            size=i;
            break;
        }
    }
    if(f)
    {
        vector<unsigned int> b(size+1);
        for(int i=0;i<size+1;i++)
            b[i]=a[size-i];
        return b;
    }
    else
        return a;
}
/// a+b
vector<unsigned int> sum(vector<unsigned int> a,vector<unsigned int> b)
{
    if(a.size()>b.size())
    {
        vector<unsigned int> rez(3000);
        int a_end=a.size()-1;
        int remainder=0,k=0,ans;
        for(int i=b.size()-1;i>=0;i--)
        {
            ans=a[a_end]+b[i]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            a_end--;
        }
        int kk=k;
        for(int i=a.size();i>kk;i--)
        {
            ans=a[a_end]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            a_end--;
        }
        if(remainder!=0)
            rez[k]=remainder;
        return zero(rez);
    }
    else
    {
        vector<unsigned int> rez(3000);
        int b_end=b.size()-1;
        int remainder=0,k=0,ans;
        for(int i=a.size()-1;i>=0;i--)
        {
            ans=b[b_end]+a[i]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            b_end--;
        }
        int kk=k;
        for(int i=b.size();i>kk;i--)
        {
            ans=b[b_end]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            b_end--;
        }
        if(remainder!=0)
            rez[k]=remainder;

        return zero(rez);
    }
}
/// a & b comparison
int compare(vector<unsigned int> a,vector<unsigned int> b)
{
    if(a.size()>b.size())
        return 1;
    if(b.size()>a.size())
        return 2;
    int r=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>b[i])
        {
            r=1;
            break;
        }
        if(b[i]>a[i])
        {
            r=2;
            break;
        }
    }
    return r;
}
/// a-b
vector<unsigned int> subtraction(vector<unsigned int> a,vector<unsigned int> b)
{
    vector<unsigned int> rez(1000);
    int a_end=a.size()-1;
    int k=0,ans;
    for(int i=b.size()-1;i>=0;i--)
    {
        ans=a[a_end]-b[i];
        if(ans<0)
        {
            rez[k]=10+ans;
            a[a_end-1]--;
        }
        else
            rez[k]=ans;
        k++;
        a_end--;
    }
    int kk=k;
    for(int i=a.size();i>kk;i--)
    {
        ans=a[a_end];
        if(ans<0)
        {
            rez[k]=10+ans;
            a[a_end-1]--;
        }
        else
            rez[k]=ans;
        k++;
        a_end--;
    }
    return zero(rez);
}
/// a div b
vector<unsigned int> div(vector<unsigned int> a,vector<unsigned int> b)
{
    vector<unsigned int> rez(a.size());
    rez=a;
    int comp=-1;
    vector<unsigned int> count(1000);
    vector<unsigned int> one(1);
    one[0]=1;
    while(comp!=0 || comp!=2)
    {
        comp=compare(rez,b);
        if(comp==0)
            break;
        rez=subtraction(rez,b);
        count=sum(count,one);
    }
    count=sum(count,one);
    return count;
}
vector<unsigned int> product(vector<unsigned int> a, vector<unsigned int> b)
 {
vector<unsigned int> result(a.size() + b.size(), 0);
	for( int i = a.size() - 1; i >= 0; i-- )
	{
		for( int j = b.size() - 1; j >= 0; j-- )
		   result[ i + j + 1 ] +=  b[ j ]  * a[ i ] ; //single array to store intermediate values
		
	
		for( int i = a.size() + b.size(); i >= 0; i-- )
		   if( result[ i ] >= 10 )
		    result[ i - 1 ] +=result[ i ] / 10;result[ i ] %= 10;
		
		
	}
 return result;
}
vector<unsigned int> modi(vector<unsigned int> a,vector<unsigned int> b)
{  vector<unsigned int> q=div(a,b);
   vector<unsigned int> p=subtraction(a,product(b,q));
   return p;
}
vector<unsigned int> gcd_recursive(vector<unsigned int> a, vector<unsigned int> b)
{
    if (b[0])
        return gcd_recursive(b, modi(a,b));
    else
        return a;
}
int main()
{
	int t;
	string a,b;
	int lena,lenb;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",&a,&b);
		lena=a.length();
		lenb=b.length();
		vector<unsigned int> A(lena),B(lenb),c;
		for(int i=0;i<lena;i++)
           A[i]=a[i]-'0';
        for(int i=0;i<lenb;i++)
           B[i]=b[i]-'0';
        c=gcd_recursive(A,B);
        int lenc=c.size();
        for(int i=0;i<lenc;i++)
           cout<<c[i];
	}
	/* code */
	return 0;
}