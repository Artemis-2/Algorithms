#include<stdio.h>
#include<stdlib.h>
int final=0;
/*void add(TRY*,int);
  void search(TRY*,int);
  void printpre(TRY*);*/
typedef struct try
{
	struct try* pl;
	struct try* pr;
	int data;
	int count;
}TRY;
void add(TRY*,int);
//int searchc(TRY*,int);
void printpre(TRY*);

//TRY* insert_at_end(TRY*,int);
//void print(TRY*,int);
TRY* delete_leaf(TRY*,int);
//void printin(TRY*);
//void printpost(TRY*);
//void search(TRY*, int);
int main(void)
{
	TRY* head;
	head=NULL;
	int ch;
	int data;
	//	printf("enter data=-1 to stop tree\n");
	head=malloc(sizeof(TRY));
	add(head,7);
	add(head,5);
	add(head,8);
	add(head,9);
	add(head,6);
	add(head,3);
	add(head,2);
	add(head,4);
	printpre(head);
	//	delete_leaf(head,8);
	printf("\n");
//	printin(head);
//	searchc(head, 3);
//	printf("\n%d:\n",final);
	return 0;
}
/*void printpost(TRY* temp)
{
	if(temp->pl!=NULL)
		printpost(temp->pl);
	if(temp->pr!=NULL)
		printpost(temp->pr);
	printf("%d	",temp->data);


}*/


void printpre(TRY* temp)
{
	printf("%d",temp->data);
	if(temp->pl!=NULL)
		printpre(temp->pl);
	if(temp->pr!=NULL)
		printpre(temp->pr);
	if(temp->pl==NULL&&temp->pr==NULL)
		return;




}
/*void printin(TRY* temp)
{

	if(temp->pl!=NULL)
		printin(temp->pl);
	printf("%d	",temp->data);
	if(temp->pr!=NULL)
		printin(temp->pr);

}*/

/*void  search(TRY* temp,int value)
{
	if(temp->data==value-1)
		final=1;
	else
	{
		if(temp->data>value)
		{
			if(temp->pl==NULL)
				return;
			else
				search(temp->pl,value);

		}
		if(temp->data<value)
		{
			if(temp->pr==NULL)
				return;
			else
				search(temp->pr,value);

		}
	}
}*/
/*int  searchc(TRY* temp,int value)
{
	if(temp->count+1==value)
	{printf("%d",temp->data);
		return 0;
	}
	else
	{
		if(temp->count>value)
		{
			if(temp->pl==NULL)
				return 0;
			else
				searchc(temp->pl,value);

		}
		if(temp->count<value)
		{
			if(temp->pr==NULL)
				return 0;
			else
				searchc(temp->pr,value);

		}
	}

}*/

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
TRY*  delete(TRY* temp,int value)
{
	TRY* new;

	TRY* store;
	if(temp->data==value)
	{
		if(temp->pl==NULL&&temp->pr==NULL)//both children are absent
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
