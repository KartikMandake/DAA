#include<bits/stdc++.h>
using namespace std;

class Activity{
	public:
		int id;
		int startTime;
		int finishTime;
		
		Activity(int id,int startTime,int finishTime){
			this->id = id;
			this->startTime = startTime;
			this->finishTime = finishTime;
		}
};

bool compare(Activity a,Activity b){
	return a.finishTime<b.finishTime;
}

void activitySelection(vector<Activity> &activities){
	int n = activities.size();
	sort(activities.begin(),activities.end(),compare);
	
	cout<<"\n\nSelected Aactivities : ";
	int count = 1;
	
	cout<<"\nActivity "<<activities[0].id<<"["<<activities[0].startTime<<"-"<<activities[0].finishTime<<"]"<<endl;;
	int lastTime = activities[0].finishTime;
	
	for(int i=1;i<n;i++){
		if(activities[i].startTime>=lastTime){
			cout<<"Activity "<<activities[i].id<<"["<<activities[i].startTime<<"-"<<activities[i].finishTime<<"]"<<endl;
			count++;
			lastTime = activities[i].finishTime;
		}
	}
	cout<<"Total No of Activities Selected is : "<<count<<endl;
}

int main(){
	int n;
	cout<<"Enter the no of Activities : ";
	cin>>n;
	vector<Activity> activities;
	cout<<"Enter Activities start-time and finish-time :"<<endl;
	for(int i=0;i<n;i++){
		int start,finish;
		
		cout<<"\nActivity "<<i+1<<endl;
		
		cout<<"start time : ";
		cin>>start;
		
		cout<<"finish time : ";
		cin>>finish;
		
		activities.push_back(Activity(i+1,start,finish));
	} 
	activitySelection(activities);
	
	return 0;
}