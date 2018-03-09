#include <bits/stdc++.h>

 using namespace std;

  string Arr[]  = {"Zero" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine"};



   int main(){
        int N;
        cout << "Enter an integer N : ";
        cin >> N;
        cout << N%10 << " : "  << Arr[N%10] ;
   }
