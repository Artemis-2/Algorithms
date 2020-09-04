#include<stdio.h>
int min[100000];
int max[100000];
int smin,smax;
int main(void)
{
int ans;
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
int ele;
scanf("%d",ele);
if(i%2==0)
{
//this implies both have the same
ans=(min[0]+max[0])/2;

}
else
{
if(smax>smin)
ans=max[0];
else
ans=min[0];

}
if(ele>ans)
insertmin(ele);
else
insertmax(ele);
while(smax-smin>1)
extractmax(0);
while(smin-smax>1)
extractmin(0);

}
}
void maxheapify(int j)
{
//printf("HRE%d\n ",j);


        int left,right;
        left=arr[2*j+1];
        right=arr[2*j+2];
        int temp;
//printf("###%d %d\n",left,right);

//      printf("i:%d\n",i);      
        if(max[j]<left&&2*j+1<smax)
        {
                 
                temp=max[j];
                max[j]=max[2*j+1];
                max[2*j+1]=temp;
               maxheapify(2*j+1);
        }
        else if(arr[j]<arr[2*j+2]&&2*j+2<smax)
        {
                temp=max[j];
                max[j]=max[2*j+2];
                max[2*j+2]=temp;
                maxheapify(2*j+2);
        }
       else
        return;
}
void extractmax()
{
        max[0]=max[smax-1];
        smax--; maxheapify(0);

}

void insertmax(int key)
{
int i;
        max[smax]=key;
        int temp;
        i=smax;
        smax++;

        while(i>0&&max[(i-1)/2]<max[i])
        {
                if(max[(i-1)/2]<max[i])
                {
                        temp=max[(i-1)/2];
                        max[(i-1)/2]=max[i];
                        max[i]=temp;
                        i=(i-1)/2;
                }
        }
        i++;
}

void extractmin()
{
        smin[0]=smin[i+1];
        smin--;    minheapify(0);

}

void insertmin(int key)
{
int i;
       min[smin]=key;
        int temp;
        i=smin;
        smin++;

        while(i>0&&min[(i-1)/2]>min[i])
        {
                if(min[(i-1)/2]>min[i])
                {
                        temp=min[(i-1)/2];
                        min[(i-1)/2]=min[i];
                        min[i]=temp;
                        i=(i-1)/2;
                }
        }
        
}
void minheapify(int j)
{
                
        int left,right;
        left=min[2*j+1];
        right=min[2*j+2];
        int temp;
    
        if(min[j]>left&&2*j+1<size)
        {
                temp=min[j];
                min[j]=min[2*j+1];
                min[2*j+1]=temp;
               minheapify(2*j+1);
        }
        else if(arr[j]>arr[2*j+2]&&2*j+2<size)
        {
                temp=min[j];
                min[j]=min[2*j+2];
                min[2*j+2]=temp;
                minheapify(2*j+2);
        }
       else
        return;
}


