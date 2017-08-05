#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string str;
  
    int flag,t,go=1;
    int length;
    int req_same;
    cin>>t;
    while(t--)
        {cin>>str; 
        flag=1;
         int same[26]={0};
         length=str.length();
         if(!length) go=0;
        if(length==1) go=0;
        if(length==2&&str[0]!=str[1]) go=0;
         req_same=2;

    if(go)    
    for(int i=0;i<length&&flag;i++)
        {
        switch(str[i])
            {
            case 'a': same[0]++; if(same[0]>=req_same) flag=0; break;
            case 'b': same[1]++; if(same[1]>=req_same) flag=0; break;
            case 'c': same[2]++; if(same[2]>=req_same) flag=0;break;
            case 'd': same[3]++; if(same[3]>=req_same) flag=0;break;
            case 'e': same[4]++; if(same[4]>=req_same) flag=0;break;
            case 'f': same[5]++; if(same[5]>=req_same) flag=0;break;
            case 'g': same[6]++; if(same[6]>=req_same) flag=0;break;
            case 'h': same[7]++; if(same[7]>=req_same) flag=0;break;
            case 'i': same[8]++; if(same[8]>=req_same) flag=0;break;
            case 'j': same[9]++; if(same[9]>=req_same) flag=0;break;
            case 'k': same[10]++; if(same[10]>=req_same) flag=0;break;
            case 'l': same[11]++; if(same[11]>=req_same) flag=0;break;
            case 'm': same[12]++; if(same[12]>=req_same) flag=0; break;
            case 'n': same[13]++; if(same[13]>=req_same) flag=0; break;
            case 'o': same[14]++; if(same[14]>=req_same) flag=0; break;
            case 'p': same[15]++; if(same[15]>=req_same) flag=0; break;
            case 'q': same[16]++; if(same[16]>=req_same) flag=0; break;
            case 'r': same[17]++; if(same[17]>=req_same) flag=0; break;
            case 's': same[18]++; if(same[18]>=req_same) flag=0; break;
            case 't': same[19]++; if(same[19]>=req_same) flag=0; break;
            case 'u': same[20]++; if(same[20]>=req_same) flag=0; break;
            case 'v': same[21]++; if(same[21]>=req_same) flag=0; break;
            case 'w': same[22]++; if(same[22]>=req_same) flag=0; break;
            case 'x': same[23]++; if(same[23]>=req_same) flag=0; break;
            case 'y': same[24]++; if(same[24]>=req_same) flag=0; break;
            case 'z': same[25]++; if(same[25]>=req_same) flag=0; break;
        }
    }
    if(flag) cout<<"\nno";
    else cout<<"\nyes";
}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

