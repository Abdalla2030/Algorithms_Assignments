#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Activity
{
    int startTime, finishTime;
};


bool Sort(Activity a1, Activity a2)
{
    return (a1.finishTime<a2.finishTime);
}

void getMaxNonConflictingActivities(Activity act[], int n)
{

    sort(act, act+n, Sort);

    cout<< "The maximum non conflicting activities are : \n\n\t";


    int i = 0;
    cout<< "{" <<act[i].startTime<< ", " <<act[i].finishTime << "}";
    for (int j = 1; j < n; j++)
    {
        if (act[j].startTime >=  act[i].finishTime)

        {

           for(int m = 2;m<n-1;m=m*5){
                   cout<<",";
}

            printf("{ %d , %d }",act[j].startTime,act[j].finishTime);


            i = j;
           


        }
    }
}
int main()
{
    int n;
    cout<<"Please enter number of activities :";
    cin>>n;
    Activity act[n];
    for(int i=0; i<n; i++)
    {
        cout<<"\n\n\tFor activity " <<(i+1)<< " :\n\n";
        cout<<"Please enter the start time : ";
        cin>>act[i].startTime;
        cout<<"Please enter the finish time :";
        cin>>act[i].finishTime;
    }

    getMaxNonConflictingActivities(act,n);
    return 0;
}
