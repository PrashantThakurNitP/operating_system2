/********PRASHANT THAKUR*******/
/***********ROUND ROBIN*******************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sjf_preemptive(vector<data>&v1,int n,float *avg_tat,float *avg_wt,int t_time)
{
  cout<<"**************Shortest remaining time/sjf preemptive*******************   "<<endl;
  int tq=1;
  //cout<<"Enter time quantum "<<endl;
  //cin>>tq;//time quantum
  vector<data>v2(n);
v2=v1;//copying to maintain check of remaining burst time and to maintain ready queue ie when will this proces executed
int jump=0;//time upto which to check
int prev=0;
int count=0;
int time=0;
*avg_tat=0;
 *avg_wt=0;
while(time<t_time)//RUN AS MANY TIME AS THAT OF BURST TIME/TIME QUANTUM
{
  struct data temp_min=v1[0];
  int bt_min=20000;
  int u1=0;
  int flag=0;
  for( int u=0;u<n;u+=1)//CHOSING MINIMUM ARIVAL TIME AMONG AVAILABLE PROCESS TILL TIME JUMP
  {
    
    if(v2[u].bt<bt_min && v2[u].at<=jump)
      {
        bt_min=v2[u].bt;
        temp_min=v2[u];
        u1=u;
        flag=1;
        
      }
      //set time upto which to sort
     
  }//finding min at each time
    // v2[u1].bt=20000;
    jump=min(jump+tq,v2[u1].at+v2[u1].bt);//UPDATING JUMP UPTO WHERE TO SEARCH
    if(flag)//IF TILL TIME JUMP ANY PROCESS FOUND
    {
      v2[u1].bt-=min(v2[u1].bt,tq);//REMAINING BURST TIME
    //IF PROCESS IS STILL REMAINING
        //v2[u1].at=tq*n+count;//push at end of queue this process start when all other process completes at least once
      // SOMETIME NO PROCESS FOUND AS JUMP CANNOT INCREASE MORE THAN TIME QUANTOM
      if(v2[u1].bt<=0)
      {
         v2[u1].at=20000;//random large value 
         v1[u1].ct=time+1;//PROCESS HAS FINISHED
         cout<<"Process P"<<u1+1<<"  complete at "<<time+1<<endl;
      }
       cout<<"Process P"<<u1+1<<" burst time "<<v1[u1].bt<<" jump = "<<jump<<endl;
       v1[u1].ct=v1[u1].ct+min(tq,v2[u1].bt);
       time+=tq;//time currently from starting
       count+=1;//how mant time context switch occured
    }
}
  for(int i=0;i<n;i++)//CALCULATION
  {

      v1[i].tat=v1[i].ct-v1[i].at;
      v1[i].wt=v1[i].tat-v1[i].bt;
      v1[i].wt=v1[i].tat-v1[i].bt;
      cout<<"process P"<<i+1<<" arrival time "<<v1[i].at<<" burst time "<<v1[i].bt;
      cout<<" turn around time "<<v1[i].tat<<"  waiting time "<<v1[i].wt<<endl;
      *avg_tat+=v1[i].tat;
      *avg_wt+=v1[i].wt;
  }
    *avg_tat/=n;
    *avg_wt/=n;

}//main ends
