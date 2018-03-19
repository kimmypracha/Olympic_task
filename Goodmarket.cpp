#include <bits/stdc++.h>

 using namespace std;
 typedef struct node{
	int dat;
	node *l , *r;
	int hei;
	int lz;
	node(int x): dat(x) , l(NULL) , r(NULL) , hei(0) , lz(0) {};
 };
 const int lim = 1e5+10;
 int arr[lim];
  int n ,m , k;
 int getbal(node *t){
  	int L = (t->l == NULL)? 0 : t->l->hei;
	int R = (t->r == NULL)? 0 : t->r->hei;
	t->hei = 1 + max(L,R);
	return (L-R);
 }
 node* lr(node* t){
	node* tmp = t->r;
	t->r = t->r->l;
	getbal(t);
	tmp->l = t;
	getbal(tmp);
	return tmp;
 }
 node* rr(node* t){
 	node* tmp = t->l;
	t->l = t->l->r;
	getbal(t);
	tmp->r = t;
	getbal(tmp);
	return tmp;
 }
 node* ins(node* root , int A){
 	if(root == NULL){
		return new node(A);
	}
	if(root->lz != 0){
		root->dat += root->lz;
		if(root->l != NULL) root->l->lz = root->lz;
		if(root->r != NULL) root->r->lz = root->lz;
		root->lz = 0;
	}
	if(root->dat >= A){
		root->l  = ins(root->l , A);
	}else{
		root->r  = ins(root->r , A);
	}
	int bal = getbal(root);
    if(bal > 1 and root->l->dat < A) root->l = lr(root->l);
    if(bal < -1 and root->r->dat >= A) root->r = rr(root->r);
	if(bal > 1) return rr(root);
	if(bal < -1 ) return lr(root);
  	return root;
 }
 void inc(node* t){
	if(t == NULL)return;
		t->lz += k;
		t->dat += t->lz;
		if(t->l != NULL) t->l->lz = t->lz;
		if(t->r != NULL) t->r->lz = t->lz;
		t->lz = 0;
		return;
 }
 node* del(node* root){
 	if(root == NULL) return NULL;
	if(root->l == NULL and root->r == NULL)return NULL;
	if(root->l != NULL){
		root->l = del(root->l);
	}else{
		root->r = del(root->r);
	}
	int bal = getbal(root);
	if(bal < -1 and getbal(root->r) > 0 ) root->r = rr(root->r);
	if(bal > 1 and getbal(root->l)  < 0 ) root->l = lr(root->l);
	if(bal < -1) return lr(root);
	if(bal > 1) return rr(root);
	return root;
 }
 long long  cnt = 0 , sum = 0;
 void dfs(node* t){
 	if(t == NULL) return ;
	cnt++;
	if(t->lz != 0){
		t->dat += t->lz;
		if(t->l != NULL) t->l->lz = t->lz;
		if(t->r != NULL) t->r->lz = t->lz;
		t->lz = 0;
	}
	sum +=(long long) t->dat;
	//printf("%d ",t->dat);
	dfs(t->l);
	dfs(t->r);
 }
 int main(){
	int t;
	scanf("%d",&t);
	while(t--){
	node* root = NULL;
	scanf("%d%d%d",&n,&m,&k);
	for(int i =0 ; i < n;  ++i){
		scanf("%d",&arr[i]);
		root = ins(root , arr[i]);
	}
	int P;
	for(int i =0 ; i < m; ++i){
		int A;
		scanf("%d",&A);
		switch(A){
			case 1 :
				scanf("%d",&P);
				root = ins(root , P);
				break;
			case 2 :inc(root);
				break;
			case 3 : root = del(root);
				break;
		}
	}
	dfs(root);
	printf("%lld %lld\n",cnt, sum);
	cnt = sum = 0;
	}
 }
