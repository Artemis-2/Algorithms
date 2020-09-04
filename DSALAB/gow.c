#include<stdio.h>
#include<stdlib.h>
#define int long long int

int final=0;
int arr[100010];
/*void add(TRY*,int);
  void search(TRY*,int);
  void printpre(TRY*);*/
int n,k;
typedef struct try
{
	struct try* pl;
	struct try* pr;
	int data;
	int count;
}TRY;
void add(TRY*,int);
int searchc(TRY*,int);
void printpre(TRY*);

TRY* insert_at_end(TRY*,int);
void print(TRY*,int);
TRY* delete_leaf(TRY*,int);
int printin(TRY*,int,int);
void printpost(TRY*);
void search(TRY*, int);
int main(void)
{
	TRY* head;
	head=NULL;
	int ch;
	int data;
	int n;
	scanf("%lld",&n);
	int t;
	scanf("%lld%lld",&t,&k);
	//	printf("enter data=-1 to stop tree\n");

	for(int q=1;q<=n;q++)
		scanf("%lld",&arr[q]);

	head=malloc(sizeof(TRY));
	int max=0;
	int sum=0;   
        head->pl=NULL;
        head->pr=NULL;
        head->data=arr[1];
  
	for(int w=2;w<=n;w++)
	{

		if(w>t)
		{delete_leaf(head,arr[t-w]);
			add(head,arr[w]);
			sum=printin(head,0,sum);
		}
		if(w<t)
		{
			add(head,arr[w]);
		}
		if(w==t)
		{
			add(head,arr[w]);
			max=printin(head,0,sum);
		}
		if(sum>max)
			max=sum;


printout(head);

}
	
 printf("%lld\n",max);
return 0;
}


	int printin(TRY* temp,int ctr,int sum)
	{

		if(temp->pr!=NULL)
			printin(temp->pr ,ctr,sum);
		if(ctr<k)
		{
			sum+=temp->data;
			ctr++;

		}
		if(temp->pl!=NULL)
			printin(temp->pl,ctr,sum);

	}
void  printout(TRY* temp)
        {

                if(temp->pl!=NULL)
                        printout(temp->pl);
               printf("%d	",temp->data);

                if(temp->pr!=NULL)
                        printout(temp->pl);

        }



	void add(TRY* temp ,int value)
	{
		if(temp->data>value)
		{
			if(temp->pl==NULL)
			{
				TRY* strn;
				strn=(TRY*)malloc(sizeof(TRY));
				strn->pl=NULL;
				strn->pr=NULL;
				strn->data=value;
				temp->pl=strn;
				strn->count=1;
			}
			else
			{	temp->count+=1;
				add(temp->pl,value);
			}
		}
		if(temp->data<value)
		{
			if(temp->pr==NULL)
			{//crete
				TRY* strn;
				strn=(TRY*)malloc(sizeof(TRY));
				strn->pl=NULL;
				strn->pr=NULL;
				strn->data=value;
				strn->count=1;
				temp->pr=strn;		}
			else
				add(temp->pr,value);


		}





	}
	TRY*  delete_leaf(TRY* temp,int value)
	{
		TRY* new;

		TRY* store;
		if(temp->data==value)
		{
			if(temp->pl==NULL&&temp->pr==NULL)
			{
				printf("here\n");
				//TRY* ptr=temp;
				free (temp);
				return NULL;

			}
			else if(temp->pl==NULL && temp->pr!=NULL)
			{
				new=temp->pr ;
				//temp=temp->pr;

				free(temp);
				return new;
			}
			else if(temp->pl==NULL && temp->pr!=NULL)
			{
				new=temp->pl ;
				//	temp=temp->pl;

				free(new);
				return new;

			}
			else
			{
				new= temp->pr;
				while(new->pl!=NULL)
				{ if(new->pl==NULL)
					break;
					else
						new=new->pl;
				}
				TRY* del;
				del=temp;
				temp=new;
				free(del);
				return NULL;
			}

		}

		else
		{
			if(temp->data>value)
			{
				if(temp->pl==NULL)
					return NULL;
				else
					store=  delete_leaf(temp->pl,value);

			}
			if(temp->pl==store)
				temp->pl=NULL;
			if(temp->data<value)
			{
				if(temp->pr==NULL)
					return NULL;
				else
					store=   delete_leaf(temp->pr,value);


			}
			if(temp->pr==store)
				temp->pr=NULL;
		}

	}
