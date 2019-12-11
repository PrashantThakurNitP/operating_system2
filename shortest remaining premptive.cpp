
//#include "priority.h"
//#include "round robin.h"
//#include "fcfs.h"

//using namespace std;
#include<iostream>

#include<vector>
#include<algorithm>


//#include "priority.h"
//#include "round robin.h"
//#include "fcfs.h"

using namespace std;

void sjf(vector<data> &v1,int n,float *avg_tat,float *avg_wt)
{
  cout<<"SHORTEST JOB FIRST PRE-EMPTIVE"<<endl;
  vector<data>v2(n);
  
  v2=v1;//copying
  int jump=0;//time upto which to check
  int count=0;
  int prev=0;

 //*avg_tat=0;
 //*avg_wt=0;
//nt prev=0;
  *avg_tat=0;
 *avg_wt=0;
while(count<n)
{
  struct data temp_min=v1[0];
  int bt_min=20000;
  int u1=0;
  for( int u=0;u<n;u+=1)
  {
    
    if(v2[u].bt<bt_min && v2[u].at<=jump)
      {
        bt_min=v2[u].bt;
        temp_min=v2[u];
        u1=u;
        
      }
      //set time upto which to sort
              
  }//finding min at each time
      v2[u1].bt=20000;
      v2[u1].at=10000; 
      cout<<" min bt "<<v1[u1].bt<<" jump = "<<jump<<"u1 = "<<u1<<endl;
      v1[u1].ct=max(prev,v1[u1].at)+v1[u1].bt;
      prev=v1[u1].ct;//updated for next
      jump=max(v1[u1].ct,jump);
      v1[u1].tat=v1[u1].ct-v1[u1].at;
      v1[u1].wt=v1[u1].tat-v1[u1].bt;
      
      *avg_tat+=v1[u1].tat;
      *avg_wt+=v1[u1].wt;
      cout<<"process P"<<u1+1<<" arrival time "<<v1[u1].at<<" burst time "<<v1[u1].bt<<"completition time "<<v1[u1].ct<<" turn around time "<<v1[u1].tat<<"  waiting time "<<v1[u1].wt<<endl;
      count+=1;
}
*avg_tat/=n;
*avg_wt/=n;


}//main ends
