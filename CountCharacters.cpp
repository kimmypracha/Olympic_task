#include <bits/stdc++.h>

 using namespace std;

   char str[1<<15]; // 1<<15 == 2^15
   int main(){
        int up , low , num , sp , sc ; // upper case , lower case , number , space , special character
        up = low = num = sp = sc = 0;
        gets(str);
        int len = strlen(str);
        for(int i = 0 ; i < len; ++i){
            if(islower(str[i])){
                low++;
            }else if(isupper(str[i])){
                up++;
            }else if(str[i]>='0' and str[i] <= '9'){
                num++;
            }else if(str[i] == ' '){
                sp++;
            }else{
                sc++;
            }
        }
        printf("\n No. of Uppercase Letters : %d" , up);
        printf("\n No. of Lowercase Letters : %d" , low);
        printf("\n No. of Number : %d" , num);
        printf("\n No. of Space : %d" , sp);
        printf("\n No. of Special Characters : %d" , sc);
   }
