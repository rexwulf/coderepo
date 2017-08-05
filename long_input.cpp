#include <iostream>

using namespace std;

int main()

{

string str;

int a,b,c;

cin>>str;

c=str.size();

int arr[c];

b=0;

while(b!=c)

{

arr[b]=str[b]-'0' ;

b++;

}

cout<<"\n";
for(int i=0;i<c;i++)
	cout<<arr[i];
return 0;

}