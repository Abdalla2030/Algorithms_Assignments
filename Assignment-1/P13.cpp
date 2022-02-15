//Ahmed Essam eldin Abd-elfattah Ibrahim    CS-S2   20190050

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cfloat>
#include <cstring>

using namespace std;
int dp[50][50] , indx[50][50];
class Node{
public:  int row , col;
};
void printSeq(int n , int start , int end)
{

    if(start==end)
    {
        cout<<"A"<<start+1;
        return;
    }

        cout<<"(";
        printSeq(n ,  start , indx[start][end]);
        cout<<"x";
        printSeq(n , indx[start][end]+1 , end);
        cout<<")";
}
void calcMin(vector<Node> vec, int n )
{
    memset(dp,0,sizeof(dp));
    memset(indx,0,sizeof(indx));
    //indx=new int*[n];
    //dp=new int*[n];
    int min=INT_MAX , multCount;
    for(int i=1 ; i<n ; i++)
    {
        for(int j=0 ; j<n-i ; j++)
        {
            int k=i+j;
            dp[j][k]=min;
            for(int l=j ; l<k ; l++)
            {
                multCount=dp[j][l]+dp[l+1][k]+(vec[j].row * vec[l].col * vec[k].col);
                if(multCount<dp[j][k])
                {
                    dp[j][k] = multCount;
                    indx[j][k]= l;
                }
            }

        }
    }
    printSeq(n ,  0 , n-1);


}
int main() {

    cout<<"Enter number  of matrices: ";
    int n; cin>>n;
    cout<<endl;
    vector<Node> matSize;
    for(int i=1 ; i<=n ; i++) {
        Node node ;
        cin>>node.row;  cin>>node.col;
        matSize.push_back(node);

    }
    calcMin(matSize , n );

    return 0;
}
