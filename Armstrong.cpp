#include <bits/stdc++.h>

 using namespace std;

  int main(){
        int N;
        printf("Enter an integer less than 1000 to test whether it is an armstrong number : ");
        scanf("%d",&N);
        int ten = 10 , digit = 1;
        while(N/ten){
            ten *= 10;
            digit++;
        }
        int Sum = 0;
        int Tmp = N;
        while(N){
            Sum += pow(N%10 , digit);
            N /= 10;
        }
        if(Sum == Tmp) printf("%d is Armstrong number" ,Tmp);
        else printf("%d is not Armstrong number",Tmp);

  }
