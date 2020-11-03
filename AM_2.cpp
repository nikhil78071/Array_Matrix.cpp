#include<iostream>

using namespace std;
class Diagonal
{
  int *d;
  int n,k;
public:
   Diagonal(int size=10)
   {
    n=size;
    if(size!=0)
     {
      d=new int[n*(n+1)/2];
     }
    else
      d=0;
    }
    ~Diagonal()
    {
     delete []d;
    }
 void store(int x,int i,int j);
 int retrieve(int i,int j);
 void show();	 
};

void Diagonal::store(int x,int i,int j)
{ 
 if(i<1||i>n||j<1||j>n)
 {
  std::cout<<"\nOut of bound";
  exit(0);
 }
 else if(i<j&&x!=0) 
  std::cout<<"\nMust be zero";
 else if(i>=j)
 {
  k= i*(i-1)/2+j-1;
  d[k+1]=x;
 }
}

int Diagonal::retrieve(int i,int j)
{
  if(i<1||i>n||j<1||j>n)
  {
   std::cout<<"\nOut of bound";
  }
  else if (i>=j)
  {
    k= i*(i-1)/2+j-1;
    return d[k+1];
  }	
  else 
    return 0;
}
	 
void Diagonal::show()
{
  std::cout<<"\nSparse matrix:";
  for(int i=1;i<=n*(n+1)/2;++i)
  {
   cout<<d[i]<<" ";
  }  
  std::cout<<"\nComplete matrix :\n"; 
  int z=1;
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=n;j++)
   {
    if(i>=j)
    std::cout<<d[z++]<<" ";
    else
    std::cout<<"0"<<" ";
   }
   std::cout<<"\n";
  }
}
 
int main()
{
 int m1=0,m2=0,y=0,i=0,j=0;
 std::cout<<"\nEnter the size of diagonal matrix:\n";
 std::cin>>m1>>m2;
 if(m1!=m2)
 {
  std::cout<<"\nInvalid size";
  exit(0);
 }  
 diagonal ob(m1)	
 std::cout<<"\nEnter the elements of array:\n";
 for(i=1;i<=m1;++i)
 {
  for(j=1;j<=m2;++j)
  {
    if(i>=j)
    { 	
     cin>>y; 
     ob.store(y,i,j);
    }
  }
 }
 std::cout<<"\nMatrix is:\n";
 ob.show(); 
 std::cout<<"\nEnter the location of retrieval:\n";
 std::cin>>i>>j;
 cout<<"Retrieved value is:"<<ob.retrieve(i,j)<<"\n";
 return 0;
}