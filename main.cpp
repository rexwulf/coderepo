        #include <iostream>
        #include<vector>
        using namespace std;

        vector<int> P,from,to,black,white;

        int findinblack(int z)
        {   int y=0;
            while(y<black.size())
            {
                if(black[y]==z) return 1;
            }
            return 0;
        }


        int main() {
            int a,t,N,u,v,temp,c;
            cin>>t;
            while(t--)
            {
                cin>>N;
                temp=N;
                while(temp--) {
                    cin >> a;
                    P.push_back(a);
                }
                cout<<"phase1 done !";
              temp=N-1;
                while(temp--)
                {  u=0,v=0;
                    cout<<"loop"<<temp+1;
                    scanf("%d %d",&u,&v);
                    cout<<u<<v;
                    cout<<"yo";
                    from.push_back(u); 
                    to.push_back(v);   
                    cout<<"temp = "<<temp<<" ";
                }
                cout<<"phase2 done !";

                for(int i=1;i<=N;i++)
                {
                    vector<int>::iterator it;
                    c=0;
                    for(it=from.begin();it<from.end();it++,c++)
                    { if(*it==i) black.push_back(to[c]);

                    }
                    c=0;
                    for(it=to.begin();it<to.end();it++,c++)
                    { if(*it==i) black.push_back(from[c]);

                    }
                    for(int k=1;k<=N;k++) {
                        if(!findinblack(k))
                            white.push_back(k);
                    }
                    int max=white[0];
                    for(int l=1;l<white.size();l++)
                    {
                        if(white[l]>max) max=white[l];
                    }
                    cout<<max<<endl;

                }

            }
            return 0;
        }