#include<iostream>
#include<string>
using namespace std;
struct process{
string processID;
int burstTime;
int arrivalTime;
int finishTime;
int waitingTime;
int turnAroundTime;
int startTime;
};
process p[20];
int numberOfProcess;
void getProcessData();
void firstComeFirstServeAlgorithm();
void shortJobFirstAlgorithm();
void srt();
void getProcessData()



{
int ch;
cout<<"Enter the number of Process for Scheduling \n";
cin>> numberOfProcess ;

cout<< "please enter which algoritm you want to apply" << endl;
cout << " 1- First Come First Served" << endl;
cout << " 2- Shortest Job First" <<endl;
cout << " 3- str" << endl;
cin>> ch;
for (int i = 0; i < numberOfProcess; i++)
{
cin>>p[i].processID;
cout<<"Enter the burst time for Process - " << i <<" :\n";
cin>>p[i].burstTime ;
cout<<"Enter the arrival time for Process - " <<i<<" \n";

cin>>p[i].arrivalTime ;


}
switch(ch){
case 1:
firstComeFirstServeAlgorithm();
break;
case 2:
shortJobFirstAlgorithm();
break;
case 3:
srt();
break;
default :
cout<<"Wrong choice please enter the correct number " << endl;
}

}
void srt(){
int current_time=0,min=100000,index_min=-1,completed=0;
float sumWT=0, sumTAT=0, averageWaitingTime, averageTurnAroundTime;
bool check[20]={false};
int burstrem [numberOfProcess];

for (int  i = 0; i < numberOfProcess; i++)
{
    burstrem [i] = p[i].burstTime;
}

while(completed!=numberOfProcess){
min=10000;

for(int i = 0; i < numberOfProcess; i++) {

if(p[i].arrivalTime <= current_time && p[i].burstTime < min && !check[i])
{

min = p[i].burstTime;
index_min = i;

}
}

if(index_min != -1) {
if (burstrem [index_min] == p[index_min].burstTime)
{
    p[index_min].startTime = current_time;
}
burstrem [index_min] =- 1;
current_time++;
if (burstrem [index_min] == 0)
{
   p[index_min].finishTime = current_time;
   p[index_min].turnAroundTime = p[index_min].finishTime - p[index_min].startTime;
   p[index_min].waitingTime = p[index_min].turnAroundTime - p[index_min].burstTime;

sumTAT += p[index_min].turnAroundTime;
sumWT += p[index_min].waitingTime;

completed++;
//current_time = p[index_min].finishTime;
check[index_min]=true; 
}



}
else {
current_time++;
}

}

averageWaitingTime=sumWT/numberOfProcess;
averageTurnAroundTime=sumTAT/numberOfProcess;
cout<<"SJF Scheduling Algorithm : ";
cout<<"ProcessId \t BurstTime \t ArrivalTime \t Priority \t WaitingTime \t TurnAroundTime \n";

for (int i = 0; i < numberOfProcess; i++)

{
cout<< p[i].processID<<"\t"<< p[i].burstTime << "\t " << p[i].waitingTime<< "\t" << p[i].turnAroundTime <<endl;
}
cout<< "\t \t \t \t \t Average" <<averageWaitingTime <<"\t" <<averageTurnAroundTime;
}

void shortJobFirstAlgorithm()
{
int current_time=0,min=100000,index_min=-1,completed=0;
float sumWT=0, sumTAT=0, averageWaitingTime, averageTurnAroundTime;
bool check[20]={false};
cout<<numberOfProcess<<endl;
while(completed!=numberOfProcess){
min=10000;

for(int i = 0; i < numberOfProcess; i++) {

if(p[i].arrivalTime <= current_time && p[i].burstTime<min && !check[i])
{

min = p[i].burstTime;
index_min = i;

}
}

cout<<p[index_min].processID<<endl;



if(index_min != -1) {

p[index_min].finishTime = current_time + p[index_min].burstTime;
p[index_min].turnAroundTime = p[index_min].finishTime - p[index_min].arrivalTime;
p[index_min].waitingTime = p[index_min].turnAroundTime - p[index_min].burstTime;

sumTAT += p[index_min].turnAroundTime;
sumWT += p[index_min].waitingTime;

completed++;
current_time = p[index_min].finishTime;
check[index_min]=true;

}
else {
current_time++;
}

}

averageWaitingTime=sumWT/numberOfProcess;
averageTurnAroundTime=sumTAT/numberOfProcess;
cout<<"SJF Scheduling Algorithm : ";
cout<<"ProcessId \t BurstTime \t ArrivalTime \t WaitingTime \t TurnAroundTime \n";

for (int i = 0; i < numberOfProcess; i++)
{
cout<< p[i].processID<<"\t"<< p[i].burstTime << "\t " <<


p[i].arrivalTime <<"\t"
<<p[i].waitingTime<< "\t" << p[i].turnAroundTime <<endl;
}
cout<< "\t \t \t \t \t Average" <<averageWaitingTime <<"\t" <<averageTurnAroundTime;
}

void firstComeFirstServeAlgorithm()
{

float sumWT=0, sumTAT=0, averageWaitingTime, averageTurnAroundTime;

//calculating waiting & turn-around time for each process
p[0].finishTime = p[0].arrivalTime + p[0].burstTime;
p[0].turnAroundTime =p[0].finishTime - p[0].arrivalTime;
p[0].waitingTime = p[0].turnAroundTime - p[0].burstTime;
for (int i = 1; i < numberOfProcess; i++)
{
// p[i].finishTime = p[i].burstTime+p[i-1].finishTime ;
// p[i].turnAroundTime =p[i].finishTime - p[i].arrivalTime;
// p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
p[i].waitingTime=p[i-1].waitingTime+p[i-1].burstTime-p[i].arrivalTime;
p[i].turnAroundTime=p[i].waitingTime+p[i].burstTime;
sumWT+=p[i].waitingTime;
sumTAT+=p[i].turnAroundTime;

}


averageWaitingTime = sumWT / numberOfProcess;

averageTurnAroundTime = sumTAT / numberOfProcess;

//print on console the order of processes scheduled using FirstComeFirstServer Algorithm
cout<<"FCFS Scheduling Algorithm : ";
cout<<"ProcessId \t BurstTime \t ArrivalTime \t WaitingTime \t TurnAroundTime \n";
for (int i = 0; i < numberOfProcess; i++)
{
cout<< p[i].processID<<"\t"<< p[i].burstTime << "\t " <<
p[i].arrivalTime <<"\t"
<<p[i].waitingTime<< "\t" << p[i].turnAroundTime <<endl;
}
cout<< "\t \t \t \t \t Average" <<averageWaitingTime <<"\t" <<averageTurnAroundTime;
}

int main()
{
getProcessData();
}
