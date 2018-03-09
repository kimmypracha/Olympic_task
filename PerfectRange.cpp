#include <bits/stdc++.h>

 using namespace std;
  int Sieve[1000001] ={};
  int main(){
    for(int i = 1; i<= 1000000; ++i)
    {
        for(int j=  2*i ; j<= 1000000 ; j+=i){
            Sieve[j] += i;
        }
    }
    int X , Y;
    scanf("%d%d",&X,&Y );
//    printf("%d",Sieve[16]);
    for(int i = X ; i <= Y ; ++i){
        if(Sieve[i] == i)printf("%d\n", i);
    }
  }
