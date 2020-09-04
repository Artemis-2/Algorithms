#include<stdio.h>
int arr[100];
int i;
int size;
void insert(int key)
{

	arr[size]=key;
	int temp;
        i=size;
        size++;
        
	while(i>0&&arr[(i-1)/2]>arr[i])
	{
		if(arr[(i-1)/2]>arr[i])
		{
			temp=arr[(i-1)/2];
			arr[(i-1)/2]=arr[i];
			arr[i]=temp;
			i=(i-1)/2;
		}
	}
	i++;
}

void minheapify(int j)
{
//printf("HRE%d\n ",j);

		
        int left,right;
        left=arr[2*j+1];
        right=arr[2*j+2];
        int temp;
//printf("###%d	%d\n",left,right);

//	printf("i:%d\n",i);      
        if(arr[j]>left&&2*j+1<size)
        {
//                 printf("***\n");
                temp=arr[j];
                arr[j]=arr[2*j+1];
                arr[2*j+1]=temp;
               minheapify(2*j+1);
        }
        else if(arr[j]>arr[2*j+2]&&2*j+2<size)
        {
                temp=arr[j];
                arr[j]=arr[2*j+2];
                arr[2*j+2]=temp;
                minheapify(2*j+2);
        }
       else
        return;
}
void extractmin()
{
	arr[0]=arr[i+1];
	i--;	minheapify(0);

}
void delete(int ind)
{
arr[ind]=arr[size-1];
size--;
minheapify(ind);

}


int main(void)
{
	int value=0;
	int size=0;

	insert(1);
	insert(5);
	insert(3);
	insert(2);
	//extractmin();
delete(2);

	for(int q=0;q<5;q++)
		printf("%d	",arr[q]);

	return 0;
}

