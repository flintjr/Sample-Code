/*
Implement a void function F that takes pointers to two arrays of
integers (A and B) and a size N as parameters. It then populates B
where B[i] is the product of all A[j] where j != i.

For example: If A = {2, 1, 5, 9}, then B would be {45, 90, 18, 10}.
*/
#include <iostream>
using std::cout;using std::endl;

void f(int *a, int *b, const int n){
  int i,j;
  for (i=0;i!=n;++i) *(b+i)=1; //have to init to 1 for product to be correct.
  for (j=0;j!=n;++j){
    for (i=0;i!=n;++i){
      if (j!=i)
	*(b+j) *= *(a+i);
    }
  }
}
void print(std::ostream &os, const int *x, const int n){
  for (auto i=0; i!=n; ++i){
    os<<*(x+i);
    if (i!=(n-1))os<<',';
  }
}

main(){
  int a[]={2, 1, 5, 9};
  const int n=(sizeof(a)/sizeof(*a));
  cout<<"n="<<n<<endl;
  int b[n];
  f(a,b,n);
  print(cout,a,n);cout<<endl;
  print(cout,b,n);cout<<endl;
}
