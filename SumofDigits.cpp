#include <bits/stdc++.h>

 using namespace std;

   int main(){
        int N , Sum = 0;
        printf("Enter an integer\n");
        scanf("%d",&N);
        while(N){
            Sum += N%10;
            N/=10;
        }
        printf("Sum of digits of entered number = %d", Sum);
   }
