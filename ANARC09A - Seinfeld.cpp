
#include<iostream>
using namespace std;
int main()
{
 int count=0;
   while(1)
   {
    char str[2050];
    scanf("%s",str);
      if(str[0]=='-')
        break;
    count++;
    int i=0,left=0,right=0,ans=0;
          
          while(str[i])
          {
            if(str[i]=='{')
              left++;
            else
             {
               if(str[i]=='}' && left==0)         //converted '}' -> '{'
                { left++;                         // so left++ and ans++
                  ans+=1;
                }
                  
                else
                  left--;
              }
            i++;
          }
       ans+=left/2;                   //left-> no. of '{' so 
       printf("%d. %d\n",count,ans);  //to balance them we need to change 
    }                                 //half of them to '}'
 return 0;
}