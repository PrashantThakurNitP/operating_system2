#include<bits/stdc++.h>
//           PRASHANT THAKUR
//            1706001
//           MEMORY MANAGEMENT
using namespace std;
int main()
{      
cout<<"MEMORY MANAGEMENT ROLL 1706001"<<endl;
	cout<<"Enter no of memory block  ";
	int n;
	cin>>n;;
	cout<<"Enter no of process  ";
	int m;
	cin>>m;
	vector<int>memory(n,0);
	vector<int>process(m,0);
	cout<<"Enter memeory block size"<<endl;
	for(int i=0;i<n;i++)
		cin>>memory[i];
	cout<<"Enter process size"<<endl;
	for(int i=0;i<m;i++)
		cin>>process[i];
	//	cout<<"Enter 1 to print first  best next and worst"
//	cout<<"Enter 1 for first 2 for best 3 for next 4 for worst"<<endl;
//	int a;
	//cin>>a;
	bool flag=0;int min1,max1,pos;
	switch(1)
	{
       case 1://first
        flag=0;
       for(int i=0;i<m;i++)
       {
       	for(int j=0;j<n;j++)
       	{
          if(memory[j]>process[i])
          {
          	cout<<memory[j]<<" is the first fit for the process "<<process[i]<<endl;
          	flag=1;
          	break;
          }
       	}
       }
       if(!flag)
       	cout<<"No first fit "<<endl;

     //  break;
cout<<endl;
       case 2://best fit
       for(int i=0;i<m;i++)
       {
       	 min1=9999;
       	 flag=0;
       	for(int j=0;j<n;j++)
       	{
          if(memory[j]>process[i] && memory[j]<min1)
          {
          	min1=memory[j];
          	flag=1;
          	//
          	//break;
          }
       	}
       	if(flag)
       	cout<<min1<<" is the best fit for the process "<<process[i]<<endl;
       else cout<<"no best fit"<<endl;
       }

       //break;
       cout<<endl;
       case 3://next fit
       for(int i=0;i<m;i++)
       {
       	 min1=9999;
       	pos=0;
       	for(int j=0;j<n;j++)
       	{
          if(memory[j]>process[i] )
          {
          	min1=memory[j];
          	pos=j;
          	break;
          	//
          	//break;
          }
       	}
      // 	cout<<min1<<" is the first fit for the process "<<process[i]<<endl;
       	 min1=9999;
       	 flag=0;
       	if(pos<n-1)
       	for(int j=pos+1;j<n;j++)
       	{
          if(memory[j]>process[i] )
          {
          	min1=memory[j];
          	//pos=j;
          	flag=1;
          	//
          	break;
          }
       	}
       	if(flag)
       		cout<<min1<<" is the next fit for process size "<<process[i]<<endl;
       	else
       		cout<<"No next fit"<<endl;
       }


      // break;
      cout<<endl;
       case 4:
        for(int i=0;i<m;i++)
       {
       	 max1=0;
       	 flag=0;
       	for(int j=0;j<n;j++)
       	{
          if(memory[j]>process[i] && memory[j]>max1)
          {
          	max1=memory[j];
          	flag=1;
          	//
          	//break;
          }
       	}
       	if(flag)
       	cout<<max1<<" is the worst fit for the process "<<process[i]<<endl;
       else cout<<"no best fit"<<endl;
       }

       break;
	}
}
