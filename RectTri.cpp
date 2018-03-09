#include <bits/stdc++.h>

 using namespace std;

 
 int main(){
	int Op;
	int A,  B;
	printf("Select 1: Rectangle or 2 : Triangle :");
	scanf("%d",&Op);
	switch(Op){
		
		case 1 :
			printf("Enter width ,length = "); 
			scanf("%d,%d", &A , &B);
			printf("Rectangle Area = %d" , A*B);
			break;
		case 2 :
			printf("Enter base , hight = ");
			scanf("%d,%d",&A,&B);
			printf("Triangle Area = %d" , (A*B)/2);
			break; 
	}
	return 0;
 }
