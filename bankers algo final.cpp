
#include<bits/stdc++.h>
#include<vector>
#include <algorithm>
using namespace std;
int n=3;//no of resources
class data
{
	public:
	vector<int> max1;
	
	vector<int> alloc;
	vector<int> need;
	
   	void get_max1()
   	{
   		
   		cout<<"maximum  ";
      		for(int i=0;i<n;i++)
      		{
      		int a1;
      		cin>>a1;

      		max1.push_back(a1);
      		}
		

   	}
   	void get_alloc()
   	{
   		cout<<"allocation  ";
   		
	  		for(int i=0;i<n;i++)
	  		{
      			 	int a1;
      				 cin>>a1;
					alloc.push_back(a1);
					
	  		}
		
   	}
   	void cal_need()
   	{
   		cout<<"need  ";
   		for(int i=0;i<n;i++)
	 {
	 	//need[i]=max1[i]-alloc[i];
	 	need.push_back(max1[i]-alloc[i]);
	 	cout<<need[i]<<"  ";
	 }
   	}
 	
};

int main()
{

	vector<int> total(n);
	vector<int> total_allocated(n,0);//total no of process allocated
	
	cout<<"Enter total resorces"<<endl;
	for(int i=0;i<n;i++)
		cin>>total[i];
	cout<<"Enter total no of process"<<endl;
	int m;
	cin>>m;//no of process
	vector<data>process(m);
	
	cout<<"Enter max process allocated need and available "<<endl;
	for(int j=0;j<m;j++)
		process[j].get_max1();//calling function
    for(int j=0;j<m;j++)
		process[j].get_alloc();//calling function
	
   
	 for(int j=0;j<m;j++)
	{
	 process[j].cal_need();
	 cout<<endl;
		
	}
   for(int j=0;j<m;j++)
   {
   	 for(int i=0;i<n;i++)
   	 	total_allocated[i]+=process[j].alloc[i];

   }
   cout<<"Total allocated are ";
   for(int i=0;i<n;i++)
	  cout<<total_allocated[i]<<" ";
   cout<<endl;

   vector<int>available;
   for(int i=0;i<n;i++)
        available.push_back(total[i]-total_allocated[i]);//available calculated
    cout<<"Total available  are ";
   for(int i=0;i<n;i++)
	  cout<<available[i]<<" ";
   cout<<endl;

	vector<data>process2;
	process2=process;//duplicate
	int count=0;
	
	int count2=0;
	vector<int> safe;
	for(int j=0;j<=m;j++)
	{  

		if(std::count(safe.begin(),safe.end(),j+1)>0 && j>=m-1)
			j=0;
		else if(std::count(safe.begin(),safe.end(),j+1)>0 && j<=m-1)
			continue;

		count2+=1;//denote no unsuccesful pass
		if(count2>m)
		{
			cout<<"not safe squence"<<endl;
			break;
		}
		//flag2=0;
	    int flag=1;

		for(int i=0;i<n;i++)
		{
           if(available[i]<process2[j].need[i])
           {
           	flag=0;//itereate on all items
           	break;
           }
		}
		
		   if(flag)
		   {
		     count2=0;//reinitialize count2, coint2 denote no of unsuccesful pass
		     
		     
		     	cout<<"\n  process P "<<j+1<<" allocated"<<endl;
		     	safe.push_back(j+1);
		     	//total_allocated[i]-=process[j].alloc[i];
		     	
		     	count+=1;//count denote no of process complete 
		     }

			if(flag)
			{
				cout<<"Available resources are"<<endl;
				for(int i=0;i<n;i++)
		  		{
		     		//available[i]=total[i]-total_allocated[i];
					available[i]=available[i]+process[j].alloc[i];
					cout<<available[i]<<"  ";

		   		}
			}
		     if(count==m)
		     	{
		     		cout<<"\n  total process completed"<<endl;
		     		break;
		     	}

		     
		if(count<m && count2<m && j==m-1)
			j=-1;//go to begining ie p0
		
	}
	cout<<"Safe sequence is  ";
	for(int i=0;i<m;i++)
		cout<<"P"<<safe[i]<<" ";


	


	
}
