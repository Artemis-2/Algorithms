#include<stdio.h>
#include<stdlib.h>
typedef struct try
{
	struct try* ptr;
	int data;
}TRY;
TRY* insert_at_head(TRY*, int);
TRY* insert_at_end(TRY*,int);
void print(TRY*);
void delete_from_tail(TRY*);
TRY* delete_from_head(TRY*);
int main(void)
{
	TRY* head;
	head=NULL;
	int ch;
	int data;
	while(ch!=0)
	{scanf("%d %d",&ch,&data);
		if(ch==1)
			head=insert_at_head(head,data);
		if(ch==2)
			head=	insert_at_end(head,data);
                if(ch==3)
                 delete_from_tail(head);
                 if(ch==4)
                head= delete_from_head(head);
                if(ch==5)
                 print(head);
  //printf("%d ",head->data);
	}
	if(ch==0)
		print(head);
	return 0;
}

TRY* insert_at_head(TRY* head,int data1)
{
	TRY* str0;
	TRY* head2;
	str0=malloc(sizeof(TRY));
	head2=str0;
	str0->ptr=head;
	str0->data=data1;
	return head2;

}

TRY*  insert_at_end(TRY* head,int data1)
{
	TRY* temp=head;
if(head!=NULL)
{
	while(temp->ptr!=NULL)
	{
		temp=temp->ptr;


	}
	TRY* strn;
	strn=malloc(sizeof(TRY));
	
	{
		temp->ptr=strn;
		strn->ptr=NULL;
		strn->data=data1;
	}
}
else
  
        {
  TRY* strn;
        strn=malloc(sizeof(TRY));

             head=strn;
                strn->data=data1;
        }
return head;

}
void print(TRY* temp)
{
//return ;
       
	while(temp->ptr!=NULL)
	{

		printf("%d",temp->data);
		temp=temp->ptr;

	}
    
	printf("%d",temp->data);
}
void delete_from_tail(TRY* temp)
{
TRY* temp2;

while(temp->ptr!=NULL)
{
temp2=temp;
temp=temp->ptr;
}
temp2->ptr=NULL;
free(temp);
}

TRY* delete_from_head(TRY* head)
{
TRY* temp=head;
head=head->ptr;
free(temp);
return head;

}






