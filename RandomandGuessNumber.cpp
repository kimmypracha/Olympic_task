#include <bits/stdc++.h>

 using namespace std;

  int main(){
        double x , y;
        printf("Pls enter an integer x : ");
        scanf("%lf",&x);
        printf("Pls enter an integer y : ");
        scanf("%lf",&y);
        printf("Random number from 15 to 22 was created\n");
        int ans = ceil(sqrt(y-x));
        while(true){
            int A ;
            printf("Guess your no. : ");
            scanf("%d" , &A);
            if(ans < A) printf("Your no. is too big\n");
            else if(ans > A) printf("Your no. is too small\n");
            else {
                printf("Yes !! Your no. is right <^,^>V\n");
                break;
            }
        }
  }
