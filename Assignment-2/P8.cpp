// Abdalla Fadl Shehata
// 20190305
// Problem #8  - Job Sequencing with Deadlines
#include <iostream>
using namespace std;
/////////////////////////////////////////
struct job {
   char JobID;
   int Deadline;
   int Profit;
};
//////////////////////////////////////////
// sort jobs based on profit
void sortBasedOnProfit (job *jobs, int numberOfJobs){
    for (int i = 0 ; i < numberOfJobs-1;i++){
        for (int j = i+1 ; j <numberOfJobs;j++){
            if (jobs[i].Profit < jobs[j].Profit){
                    job temp = jobs[i];
                    jobs[i] = jobs[j] ;
                    jobs[j] = temp ;
            }
        }
    }
}
//////////////////////////////////////////
int getMaxDeadline(job *jobs, int numberOfJobs){
    int maxDeadline=jobs[0].Deadline;
    for(int i=0;i<numberOfJobs;i++){
        if (jobs[i].Deadline > maxDeadline){
            maxDeadline=jobs[i].Deadline;
        }
    }
    return maxDeadline;
}
/////////////////////////////////////////////
void findJobScheduling(job *jobs,int numberOfJobs){
    sortBasedOnProfit(jobs,numberOfJobs);
    int maxDeadline = getMaxDeadline(jobs,numberOfJobs);
    char result[maxDeadline];

    for(int i=0;i<maxDeadline;i++){
            result[i] = ' ';
    }
    /////////////////////////////////////////////////////////////
     for(int i=0;i<numberOfJobs;i++){
           if (result[jobs[i].Deadline-1] == ' '){
                        result[jobs[i].Deadline-1]=jobs[i].JobID;
                }
                else {
                    for(int j=(jobs[i].Deadline)-1;j>=0;j--){
                           if(result[j]==' '){
                                 result[j]=jobs[i].JobID;
                                 break;
                          }
                    }
                }
     }
     ///////////////////////////////////////////////////////
     // print the result
     //////////////////////////////////////////////////////
     for(int i=0;i<maxDeadline;i++){
        if(result[i] != ' '){
            if (i==maxDeadline-1){
                cout<<result[i];
            } else{
                cout<<result[i]<<", ";
            }
        }
    }
     //////////////////////////////////////////////////////////

}
//////////////////////////////////////////
int main(){
   job jobs[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},{'d', 1, 25}, {'e', 3, 15}};
    int numberOfJobs = sizeof(jobs)/sizeof(jobs[0]) ;
    cout << "Following is maximum profit sequence of jobs:" << endl;
    findJobScheduling(jobs, numberOfJobs);
    return 0;
}
