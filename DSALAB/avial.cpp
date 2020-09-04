#include <bits/stdc++.h>
using namespace std;
struct node{
int val;
node* left;
node* right;
int h;
};
node* makenew(int value)
{
node*  star=new node();
star->val=value;
star->left=star->right=NULL;
star->h=0;
return star;

}
int geth(node* head)
{
returrn node==NULL?0:node->h;
}
void updateh(node* head)
{
head->h=max(geth(head->left),geth(head->right))+1;
}
node* lrotation(node* a)
{
node* c=a->right;
a->right=c->left;
c->left=a;
updateh(a);
updateh(c);
return c;
}
node* rrotation(node* a)
{
node* c=a->left;
a->left=c->right;
c->right=a;
updateh(a);
updateh(c);
return c;
}
void insert(int value,node* head)
{
if(head->val>value)
{
if(head->left!=NULL)
{
insert(head->left,value);

}
else
head->left=makenew(value);


}
if(head->val<value)
{
if(head->right!=NULL)
{
insert(head->right,value);

}
else
head->right=makenew(value);
}
head=balance->head
head->h=updateh(head);


}
node* balance(node* a)
{
int balance=geth(a->left)-geth(a->right);
if(balance>1)
{
if(geth(a->left->left)>geth(a->left->right))
a=rrotation(a);
else
{
a->left=lrotation(a->left);
a=rrotation(a);
}
}
else if(balance<-1)
{


}
return a;
}
int main(void)
{
int a;
cin>>a;
insert(a);
}

