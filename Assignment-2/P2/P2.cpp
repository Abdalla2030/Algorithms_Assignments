#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cfloat>
#include <cstring>

using namespace std;
int ack(int m , int n)
{
    if (m==0) return n+1;
    else if (n==0 && m>0) return ack(m-1 , 1);
    else if (n>0 && m>0) return ack(m-1 , ack(m , n-1));

}
int fast_ack(int m , int n)
{
    int next[m+1] , goal[m+1] , value , curr;
    for(int i=0 ; i<m ; i++)
    {
        next[i]=0;
        goal[i]=1;
    }
    goal[m]=-1;
    next[m]=0;
    while (next[m] != n+1){
        value=next[0]+1 ,  curr=0;
        bool finished= false;
        while (!finished){
            if(next[curr] == goal[curr])
                goal[curr]=value;
            else finished=true;
            next[curr]++;
            curr++;
        }

    }
    return value;

}

int main() {
    cout<<ack(3,3)<<" "<<fast_ack(4,1);

    return 0;
}
