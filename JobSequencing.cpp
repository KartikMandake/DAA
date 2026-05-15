#include<bits/stdc++.h>
using namespace std;

class Job{
	public:
		char id;
		int deadline;
		int profit;
};
bool compare(Job a,Job b){
	return a.profit>b.profit;
}

class JobSequencing{
	public:
		void sequenceJob(Job jobs[],int n){
			sort(jobs,jobs+n,compare);
			int maxD = 0;
			for(int i=0;i<n;i++){
				maxD = max(maxD,jobs[i].deadline);
			}
			vector<bool> slot(maxD+1,false);
			vector<char> result(maxD+1);
			
			int totalProfit = 0;
			int count = 0;
			for(int i=0;i<n;i++){
				for(int j=min(maxD,jobs[i].deadline);j>=1;j--){
					if(!slot[j]){
					slot[j] = true;
					result[j] = jobs[i].id;
					totalProfit += jobs[i].profit;
					count++;
					break;	
					}
				}
			}
			cout << "\nJobs Selected: ";
        for(int i = 1; i <= maxD; i++)
        {
            if(slot[i])
            {
                cout << result[i] << " ";
            }
        }
        cout << endl;
        cout << "Total Profit: "
             << totalProfit << endl;
        cout << "Number of Jobs: "
             << count << endl;
    }
};

int main(){
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    Job jobs[n];
    // Input jobs
    for(int i = 0; i < n; i++){
        cout << "Enter Job ID Deadline Profit: ";
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;
    }
    JobSequencing js;
    js.sequenceJob(jobs, n);
	
	return 0;
}
