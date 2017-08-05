#include<iostream>
#include<string>
#include<vector>
using namespace std;
 int calc(char ch)
 {
 	switch(ch)
 	{
 		case '+': return 1;
 		case '-': return 2;
 		case '*': return 3;
 		case '/': return 4;
 		case '^': return 5;
 		case '(': return 6;
 		case ')': return 6;
 		default : return 0;
 	}
 }
 void display(vector<char> ans)
 {
 	int ans_size=ans.size();
        	for(int i=0;i<ans_size;i++)
        		cout<<ans[i];
        	cout<<"\n";
 }
int main()
{       string str;
        int t, str_size, ans_size,i ,j;  
        char ch;      
        cin>>t;
        while(t--)
        {   vector<char> ans, stack ;
        	stack.push_back('(');
        	cin>>str;
        	str_size=str.size(), i=0,j=0;
        	while(i<str_size)
        	{
        		if(isalpha(str[i]))
        		{
        			ans.push_back(str[i]);
        		}
        		else
        		{
        			if(str[i]==')')
        			{
                        while(stack[stack.size()-1]!='('&&j>0)
                        {  ch=stack[stack.size()-1];
                        	stack.pop_back();
                           if(ch!=')'&&ch!='(') 
                           {
                           	ans.push_back(ch);
                           }
                           j--;
                        }                                      
                     if(j)
                     {   stack.pop_back();
                        j--;
                    }
        			}
        			else
        			{
        			      while(calc(str[i])<=calc(stack[j]) && j>0 && stack[j]!='(')
        			      {
        			    	ch=stack[stack.size()-1];
                        	stack.pop_back();
        			    	if(ch!=')'&&ch!='(') 
        			    		{
        			    			ans.push_back(ch);
        			    		}	
        			    	j--;
        			      }

                        stack.push_back(str[i]);
                        j++;
        			}
        		}
        		
        		i++;
        	}
        	stack.push_back(')');
        	while(stack[stack.size()-1]!='('&&stack.size())
                        {  ch=stack[stack.size()-1];
                        	stack.pop_back();
                           if(ch!=')'&&ch!='(') 
                           {
                           	ans.push_back(ch);
                           }
                           j--;
                        }  
        	display(ans);
        }
        return 0;
}
