#include <bits/stdc++.h>

 using namespace std;

   int main(){
        int N , Sum = 0;
        printf("Enter a number: ");
        scanf("%d" , &N);
        for(int i = 1 ; i < N ;++i){
            if(N%i == 0){
                Sum += i;
            }
        }
        if(Sum == N)printf("%d is a perfect number",N);
        else printf("%d is not a perfect number" , N);
   }
