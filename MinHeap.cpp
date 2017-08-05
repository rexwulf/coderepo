#include<iostream>
#include<math.h>
using namespace std;

void swap(int *a,int *b)
{
   int temp=*a;
   *a=*b;
   *b=temp;
}

class minheap
{
  public:
  
  int *A;
  int capacity;
  int heap_size;
  int left(int i){ return 2*i+1;}
  int right(int i){ return 2*i+2;}
  int parent(int i){ return floor(i/2);}
  
  minheap(int cap)
  {
    capacity=cap;
    heap_size=0;
    A=new int[cap];
  }

  void heapify(int i)
  {
    int l=left(i);
    int r=right(i);
    int smallest=i;

    if(l<heap_size && A[l]<A[smallest])
    	smallest=l;
    if(r<heap_size && A[r]<A[smallest])
    	smallest=r;
    if(smallest!=i)
    {
    	swap( &A[smallest] , &A[i] );
    	heapify(smallest);
    }
  }

  void insertkey(int a)
  {
    if(heap_size==capacity)
    {
    	cout<<"Memory out of flow";
        return;
    }
    heap_size++;
    int i=heap_size-1;
    A[i]=a;

    while(i!=0 && A[parent(i)] > A[i])
    {
       swap(&A[parent(i)] , &A[i]);
       i=parent(i);
    }
  }

  void decreasekey(int i,int value)
  {
  	A[i]=value;
  	while(i!=0 && A[parent(i)]>A[i] )
  	{
  		swap( &A[parent(i)] , &A[i]);
  		i=parent(i);
  	}
  }
  
  int extractmin()
  {
  	if(heap_size<=0)
  		return INT_MAX;
  	if(heap_size==1)
  	{
  		heap_size--;
  		return A[0];
  	}
  	int temp=A[0];
  	A[0]=A[heap_size-1];
  	heap_size--;
  	heapify(0);
  	return temp;
  }
  int deletekey(int i)
  {
  	decreasekey(i,INT_MIN);
  	return extractmin();
  }

};
int main()
{
	minheap h(11);
	h.insertkey(3);
    h.insertkey(2);
    h.deletekey(1);
    h.insertkey(15);
    h.insertkey(5);
    h.insertkey(4);
    h.insertkey(45);
    cout << h.extractmin() << " ";
    cout << h.A[0] << " ";
    h.decreasekey(2, 1);
    cout << h.A[0];
    return 0;
}

//  O/P : 2 4 1