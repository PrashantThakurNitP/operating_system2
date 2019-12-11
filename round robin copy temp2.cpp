/********PRASHANT THAKUR*******/
/***********ROUND ROBIN*******************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void round_robin(vector<data>&v1,int n,float *avg_tat,float *avg_wt,int t_time)
{
  cout<<"    ROUND ROBIN   "<<endl;
  int tq;
  cout<<"Enter time quantum "<<endl;
  cin>>tq;//time quantum
  vector<data>v2(n);
  v2=v1;//copying to maintain check of remaining burst time and to maintain ready queue ie when will this proces executed
int jump=0;//time upto which to check
int prev=0;
int count=0;
int time=0;
*avg_tat=0;
 *avg_wt=0;
 int count2=0;
 //int prev=-1;
while(time<t_time+tq)//RUN AS MANY TIME AS THAT OF BURST TIME/TIME QUANTUM
{
  struct data temp_min=v1[0];
  int at_min=20000;
  int u1=0;
  int flag=0;
  
  for( int u=0;u<n;u+=1)//CHOSING MINIMUM ARIVAL TIME AMONG AVAILABLE PROCESS TILL TIME JUMP
  {
    
    if(v2[u].at<at_min && v2[u].at<=jump)
      {
        at_min=v2[u].at;
        temp_min=v2[u];
        u1=u;
        flag=1;//means process found
        
      }
      //set time upto which to sort
     
  }//finding min at each time
    // v2[u1].bt=20000;
  if(v2[u1+1].at >= time + v2[u1].bt){
    
         v2[u1].at=20000;//random large value 
         v1[u1].ct=time+v2[u1].bt;//PROCESS HAS FINISHED
         cout<<"Process P"<<u1+1<<"  complete at "<<time+v2[u1].bt<<endl;
         jump=v2[u1+1].at;
         time=jump;
         continue;
  }
    jump=min(jump+tq,jump+v2[u1].bt);//UPDATING JUMP UPTO WHERE TO SEARCH
    time=jump;
    if(flag)//IF TILL TIME JUMP ANY PROCESS FOUND
    {
     // time+=min(v2[u1].bt,tq)
      v2[u1].bt-=min(v2[u1].bt,tq);//REMAINING BURST TIME
      if(v2[u1].bt>0 )//IF PROCESS IS STILL REMAINING
         v2[u1].at=jump+1;//push at end of queue this process start when all other process completes at least once
     /* else if(v2[u1].bt>0 && prev==u1)//IF PROCESS IS STILL REMAINING
         {
            v2[u1].at=jump;//
            time=time-1;
            jump=jump-1;

         }*/
      else// SOMETIME NO PROCESS FOUND AS JUMP CANNOT INCREASE MORE THAN TIME QUANTOM
      {
         v2[u1].at=20000;//random large value 
         v1[u1].ct=time;//PROCESS HAS FINISHED
         cout<<"Process P"<<u1+1<<"  complete at "<<time<<endl;
      }
       cout<<"Process P"<<u1+1<<" burst time "<<v1[u1].bt<<" jump = "<<jump<<endl;
      // v1[u1].ct=v1[u1].ct+min(tq,v2[u1].bt);
      /******** time+=min(tq,v2[u1].at+v2[u1].bt-jump);********///time currently from starting
      
       count+=1;//how mant time context switch occured
    }
    else
    time++;
}
  for(int i=0;i<n;i++)//CALCULATION
  {

      v1[i].tat=v1[i].ct-v1[i].at;
      v1[i].wt=v1[i].tat-v1[i].bt;
      //v1[i].wt=v1[i].tat-v1[i].bt;
      cout<<"process P"<<i+1<<" arrival time "<<v1[i].at<<" burst time "<<v1[i].bt;
      cout<<" turn around time "<<v1[i].tat<<"  waiting time "<<v1[i].wt<<endl;
      *avg_tat+=v1[i].tat;
      *avg_wt+=v1[i].wt;
  }
    *avg_tat/=n;
    *avg_wt/=n;

}//main ends