#include <stdio.h>
#include<string.h>
#include<math.h>
#define int long long int
char  arr[10000];
int find_pre(int);
int find_suff(int);
int find_pow(int);
int main(void)
{

	int p=37;
	int l,r;

	scanf("%s",arr);
	scanf("%lld%lld",&l,&r);
	int prer=find_pre(r);
	int prel1=0;
     prel1=find_pre(l-1);
   printf("%lld %lld:",prer,prel1);

	int suffnl=find_suff(strlen(arr)-l);
	int suffnr=find_suff(strlen(arr)-r-1);
        printf("%lld %lld:",suffnl,suffnr);
	int mult1=find_pow(l*1995);
	int mult2=find_pow((strlen(arr)-r-1)*1995);
	int ans1=((prer-prel1)*mult1)%1997;
	int ans2=((suffnr-suffnl)*mult2)%1997;
	if(ans1==ans2)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	return 0;
}
int  find_pre(int j)
{

	int p=37;
	int ans1=0;
	int temp1=1;
	for(int i=0;i<=j;i++)
	{printf("HERE\n");
		ans1+=((temp1)*(arr[i]))%1997;
	temp1*=p;
//		temp1%=1997;
		ans1%=1997;

	}
//	ans1*=temp1;
	ans1=ans1%1997;
	return ans1;
}
int  find_suff(int j)
{int temp1=1;
	int p=37;
	int ans1=0;
printf("here\n");
	for(int i=strlen(arr)-1;i>j-1;i--)
	{
		ans1+=((temp1)*(arr[i]))%1997;
	temp1*=p;
//		temp1%=1997;
		ans1%=1997;

	}
//	ans1*=temp1;
	ans1=ans1%1997;
	return ans1;
}

int find_pow(int a)
{
	int p=37;
	int 	temp=1;int ans=1;
	while(a>0)
	{printf("herer\n");
		if(a%2!=0)
			temp*=p;
		if(a%2==0)
			ans*=ans;
		ans%=1997;
		temp%=1997;
	}
	ans*=temp;
	ans%=1997;
	return ans;
}
