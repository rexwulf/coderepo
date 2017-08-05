#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int N[100001];
    long int D, sum=0,j;
    cin>>D;
    for(long int i=0;i<D;i++ )
        cin>>N[i];
    
    for(long int i=0;i<D;i++ )
        {
            if(i==D-1)
            { sum+=N[i]/2;
             break;
            }
            if(N[i]%2==0)
             {
                sum+=N[i]/2;
            }  
            else{
                if(N[i]==1)
                    {
                    
                    j=i+1;
                    while(!N[j]&&j<D)
                    	j++;
                  if(N[j])
                   { sum+=1;
                    N[j]--;
                    }

                }
                else{
                    
                    j=i+1;
                    while(!N[j]&&j<D)
                    	j++;
                   if(N[j])
                   { 	
                   sum+=(N[i]+1)/2;
                    N[j]--;
                    }
                    else sum+=(N[i])/2;
                }
        }
    }
    cout<<sum;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

