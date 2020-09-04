#include<stdio.h>
#include<stdlib.h>
int final=0;

typedef struct try
{
	struct try* pl;
	struct try* pr;
	int sum;
	int data;
}TRY;
void add(TRY*,int);
int  search(TRY*,int);void printpre(TRY*);
void sum(TRY*);
void printin(TRY*);
void printpresum(TRY*);
void printpost(TRY*);
int main(void)
{
	TRY* head;
	head=NULL;
	int ch;
	head=malloc(sizeof(TRY));
	head->data=-1;
	head->sum=0;
	head->pl=NULL;
	head->pr=NULL;
	int value=0;
	while(value!=-1)
	{
		printf("Until you enter -1, value is added\n");
		printf("Enter value to be added:\n");
		scanf("%d",&value);
		if(value==-1)
			break;
		search(head,value);
		if(final==1)
			printf("ALREADY PRESENT\n");
		else
		{		add(head,value);

			//		sum(head);
		}
		final=0;
	}
	printpre(head);
	printf("\n");
	//        printpost(head);//to find the sums


	printpresum(head);
	//	printf("\n");
	int q;

}
int  search(TRY* temp,int value)
{
	if(temp->data==value)
	{
		final=1;
		return temp->sum;
	}
	else
	{if(temp->data>value)
		{if(temp->pl!=NULL)
			search(temp->pl,value);
		}
		if(temp->data<value)
		{if(temp->pr!=NULL)
			search(temp->pr,value);
		}
	}
}
void printpost(TRY* temp)
{
	printf("%d      ",temp->data);
	if(temp->pl==NULL&&temp->pr==NULL)
	{              temp->sum=temp->data;}
	else{
		if(temp->pl!=NULL)
		{	printpost(temp->pl);
			temp->sum=temp->data+(temp->pl)->sum;}

		if(temp->pr!=NULL)
		{     printpost(temp->pr);		temp->sum=temp->data+(temp->pl)->sum;


	}
printf("data:%d		sum:%d\n",temp->data,temp->sum);
}
}
                       //temp->sum+=value;


 
void printpresum(TRY* temp)
{
	printf("%d	",temp->sum);
	if(temp->pl!=NULL)
		printpre(temp->pl);
	if(temp->pr!=NULL)
		printpre(temp->pr);
	if(temp->pl==NULL&&temp->pr==NULL)
		return;
}




void add(TRY* temp ,int value)
{
	//printf("value:%d\n",value);
	//+	temp->sum+=value;
	//printf("###\n");
	if(temp->data>value)
	{
		if(temp->pl==NULL)
		{
			//			printf("here*\n");
			//			printf("%d",temp->data);
			TRY* strn;
			strn=(TRY*)malloc(sizeof(TRY));
			strn->pl=NULL;
			strn->pr=NULL;
			strn->data=value;
			temp->pl=strn;
			strn->sum=0;
		}
		else
		{
			//temp->sum+=value;


			add(temp->pl,value);
		}
	}
	if(temp->data<value)
	{
		if(temp->pr==NULL)
		{//crete
			//printf("***/n");
			TRY* strn;
			strn=(TRY*)malloc(sizeof(TRY));
			strn->pl=NULL;
			strn->pr=NULL;
			strn->sum=0;
			strn->data=value;
			temp->pr=strn;

		}
		else
		{
			//	temp->sum+=value;

			add(temp->pr,value);


		}





	}
}




