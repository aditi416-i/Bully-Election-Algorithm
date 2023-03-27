#include<stdio.h>
#include<stdlib.h>

int bully (int place, int process[], int flag[], int num)
{
for(int i=0; i<num; i++)
{
if (process[i]>process[place])
{
printf("The election message sent from %d to %d \n", process[place], process[i]);
}
else
{
flag[i]=1; //process is not active
}
}
printf("\n");

for(int i=0; i<num; i++)
{
if(flag[i]!= 1 && process[i]>process[place])
{
printf("The takeover message sent from %d to %d \n", process[i], process[place]);
flag[place]=1;
}
}
printf("---------------\n");

for(int i=0; i<num; i++)
{
if(flag[i]==0)
{
place = bully(i, process, flag, num);
}
}
return place;
}



int compare(const void *a, const void *b)
{
return(*(int*)a-*(int*)b);
}

//Driver code
int main() 
{
srand(time(0));
int num, max = -1, place=0, crash = -1, elect = -1;
printf("Enter the number of processes:");
scanf("%d", &num);
printf(" Enter the number of priorities of %d processes:", num);


int process [num];
int flag[num];
for (int i=0; i<num; i++)
{
process[i] = 0;
flag[i]=0;
}
for (int i=0; i<num; i++)
{
scanf("%d", &process[i]);
}


qsort(process, num, sizeof(int), compare);

place = num-1; 
printf("Priorities:\n");

for(int i=0; i<num; i++)
{
printf("%d ", process[i]);
}
printf("The current co-ordinator process is %d:", process[num-1]);
printf(" Enter the process that crashed:\n");
scanf("%d", &crash);

for (int i=0; i<num; i++)
{
if(crash== process[i])

 {
 flag[i]=1; //process is passive
 }
}
printf(" Enter the number of processes that start election:\n");
scanf("%d", &elect);

for(int i=0; i<num; i++)
{
if(elect == process[i])
{
place=i;
}
}

int leader= bully(place, process, flag, num); //Calling bully function for higher priority process whose flag!=1
printf("The current co-ordinator process is %d\n", process[leader]);

for(int i=0; i<num; i++)
{
if(i!= leader && process[i]<process[leader])
{
printf("The victory message from %d to %d \n", process[leader], process[i]);
}
}
return 0; 

}





