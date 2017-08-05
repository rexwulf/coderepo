       #include<iostream>
       #include<vector>
       using namespace std; 
    double myans(vector<int> nums1,vector<int> nums2,int l1,int r1,int l2,int r2)
    {  int m1,m2,m11,m12=0,m21,m22=0;
       if(!n1) l1=r1=0;
       else l1=0,r1=n1-1;
       if(!n2) l2=r2=0;
       else l2=0,r2=n2-1;
       
       if(!n1&&!n2) return 0;
       if(n1%2==0)
          { m11=double(n1)/2.0;
            m12=double(n1)/2.0+1.0;
            m1=(m11+m12)/2.0;
          }
       else 
       {
          m11=double(n1)/2.0;
          m1=m11;
       }  
       if(n2%2==0)
          { m21=double(n2)/2.0;
            m22=double(n2)/2.0+1.0;
            m2=(m21+m22)/2.0;
          }
       else 
       {
          m21=double(n2)/2.0;
          m2=m21;
       }    
       if(!n1) 
       {
        if(n2%2==0) return m2;
        return m21;
       }
       if(!n2) 
       {
        if(n1%2==0) return m1;
        return m11;
       }
       if(m1>m2)
        myans(nums1,num2,)
        
    }
  //for(int i=0;i<n;i++)
    //cout<<" "<<a[i];
    
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       

}

int main()
{ 
  vector<int> A; A.push_back(0);
  vector<int> B; B.push_back(1);
  cout<<findMedianSortedArrays(A,B);
  return 0;
}