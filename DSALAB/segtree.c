#include<stdio.h>
#define int  long int
int seg[200005];
int arr[50005];
int sum;
void insert(int ,int ,int ,int ,int);
void print(int);
int query(int ,int , int , int ,int );
void modify(int ,int ,int , int ,int , int );

int main(void)
{
/*	int n;
	scanf("%ld",&n);
	for(int j=1;j<=n;j++)
	{scanf("%ld",&arr[j]);
		insert(arr[j],j,1,n,1);
	}
	int m;
int orig=0;
	scanf("%ld",&m);
	for(int y=0;y<m;y++)
	{
		int  ch;
		int a, b;
		scanf("%ld%ld%ld",&ch,&a,&b);
		if(ch==0)
		{
			orig=arr[a+1];
			modify(b,a+1,1, n,1,  orig);
		}
		if (ch==1)
		{
			query(a+1,b+1, 0, 6,1);
			printf("%ld\n",sum);
			sum=0;

		}
	}*/
arr[1]=2;
arr[1]=5;
arr[1]=3;
arr[1]=1;
arr[1]=6;
arr[1]=7;
arr[1]=9;
for(int h=1;h<=7;h++)
insert(arr[h],h,1,7,1);
	return 0;
print(7);
}

int query(int l,int r, int low, int high,int q)
{
	if(low>r||high<l)
		return 0;
	if(low>=l &&high<=r)
	{

		sum+= seg[q];
		return sum;
	}
	query(l,r,low,(low+high)/2,2*q);
	query(l,r,(low+high)/2+1,high,2*q+1);


}
void insert(int x,int i,int l,int r,int q)
{
	if(l>r)
		return;
	if(l==r)
	{
		seg[q]=x;
		return;
	}
	else
	{
		if(i>=l&&i<=(l+r)/2)
		{
			seg[q]+=x;
			insert(x,i,l,(l+r)/2,q*2);

		}
		else
		{
			seg[q]+=x;
			insert(x,i,(l+r)/2+1,r,q*2+1);
		}
	}
}

void modify(int x,int i,int l, int r,int q, int orig)
{
	if(l>r)
		return;
	if(l==r)
	{
		seg[q]=seg[q]-orig+x;
		return;
	}
	else
	{
		if(i>=l&&i<=(l+r)/2)
		{
			seg[q]=seg[q]-orig+x;
			modify(x,i,l,(l+r)/2,q*2,orig);

		}
		else
		{
			seg[q]=seg[q]-orig+x;
			modify(x,i,(l+r)/2+1,r,q*2+1,orig);
		}
	}

}
void print(int n)
{
printf("here\n");
	for(int t=1;t<=28;t++)
		printf("%ld	",seg[t]);
	printf("\n");
}
