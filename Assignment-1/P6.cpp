//Ahmed Essam eldin Abd-elfattah Ibrahim    CS-S2   20190050

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
class empNode{
public: string ID , name , dept;
        };
class tranNode{
public: string sellerID , product , buyer;
};
int hashFunc (string word) {
    int result = 0;
    for(size_t i = 0; i < word.length(); ++i) {
        result += word[i] * pow(31, i);
    }
    return result;
}
int main() {
    vector<empNode> employees;
    vector<tranNode> transactions;
    map<string , int> idIndx;
    int n , m;

    cout<<"number of employees: ";
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        empNode node;
        cin>>node.ID>>node.name>>node.dept;
        employees.push_back(node);
        //idIndx[node.ID]=hashFunc(node.ID);
        idIndx[node.ID]=i;
    }
    cout<<"number of transactions: ";
    cin>>m;

    for(int i=0 ; i<m ; i++)
    {
        tranNode node;
        cin>>node.product>>node.sellerID>>node.buyer;
        transactions.push_back(node);
    }
    int arr[m];
    for(int i=0 ; i<m ; i++)
    {
        arr[i]=idIndx[transactions[i].sellerID] ;
        cout<<arr[i]<<endl;
    }



    return 0;
}
