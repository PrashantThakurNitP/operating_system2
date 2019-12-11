#include "struct.cpp"
#include "sjf.cpp"
#include"fcfs.cpp"
#include"round robin.cpp"
#include"priority.cpp"
#include"shortest remaining time.cpp"
#include"priority preemptive.cpp"
using namespace std;
int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("C:/Users/PRASHANT/Desktop/compiler/input output/input.txt","r",stdin);
	freopen("C:/Users/PRASHANT/Desktop/compiler/input output/output.txt","w",stdout);
	#endif*/
cout<<"******************PRASHANT THAKUR****************************"<<endl;
cout<<"********************1706001**********************************"<<endl;
 cout<<" SCHEDULING ALGORITHM"<<endl;
cout<<"Enter no of process : ";
int n;
cin>>n;
vector<data>v1(n);
vector<data>v2(n);
int t_time=0;
struct data d1;
for(int i=0;i<n;i++)
{
cout<<" Enter arival time ,burst time and priority no : ";
cin>>d1.at;
cin>>d1.bt;
cin>>d1.pt;
t_time+=d1.bt;
d1.ct=0;
d1.tat=0;
d1.wt=0;
v1[i]=d1;
}
float avg_tat=0;
float avg_wt=0;

for(int i1=0;i1<4;i1++)
{
	int opt;
	cout<<" 1: fcfs\n 2:sjf\n 3:priority\n 4:round robin\n 5: shortest remaining time\n";
	cout<<" 6: priority preemptive\n";
	cout<<"\t";
	cin>>opt;
	switch(opt)
	{
		case 1:
	 	  	fcfs(v1,n,&avg_tat,&avg_wt);
	 		break;
		case 2:
	   		sjf(v1,n,&avg_tat,&avg_wt);
	  		break;
		case 3:
	  		 priority(v1,n,&avg_tat,&avg_wt);
	  		 break;
		case 4:
	  		 round_robin(v1,n,&avg_tat,&avg_wt,t_time);
	  	 	break; 
	  	 case 5:
	  		 sjf_preemptive(v1,n,&avg_tat,&avg_wt,t_time);
	  		 break;
	  	 case 6:

	  		 priority_preemptive(v1,n,&avg_tat,&avg_wt,t_time);
	  	 	break; 
	}


cout<<"avg_tat  =  "<<avg_tat<<endl;
cout<<"avg_wt   =  "<<avg_wt<<endl;
}
}//main ends
