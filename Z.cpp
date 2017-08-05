#include<iostream>
#include<vector>
using namespace std;

void z(char s[100],int n)
{
  vector<int> z;
  int l=0,r=0;
  z.push_back(0);
  for(int i=1;i<n;i++)
  {
    if(i>r)
    {
    	while(s[i]==s[r-l]&&r<n) r++;
    	z.push_back(r-l);
    }
    else
    {

    }
  }

}    


int main()
{

	return 0;
}