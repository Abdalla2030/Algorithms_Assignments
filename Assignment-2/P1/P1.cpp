// Abdalla Fadl Shehata
// 20190305
// Problem #1
// PrimMST Algorithm
#include <iostream>
using namespace std;
const int numOfVertices = 7 ;
/////////////////////////////////////////////////////////////////////////////
// return Node that have minimum key and not belong to mst group
int minNode(int keys[], bool mst[]){
    int minimum = 1000;    // maximun value
    int  index = -1 ;
    // O(V)
    for (int i = 0; i < numOfVertices; i++){
        if (keys[i] < minimum && mst[i] == false ){
            minimum = keys[i];
            index = i;
        }
    }
    return index;
}
////////////////////////////////////////////////////////////////////////////
void findPrimMST(int graph[numOfVertices][numOfVertices]) {
    // array to store vertices that will add to Minimum spanning trees
    int mstResult[numOfVertices];
    // array to store the key of each vertix
    int keys[numOfVertices];
    // boolean array to store if vertix belong to mst or not
    bool mst[numOfVertices];

    // Initially all vertices have key = infinity
    for (int i = 0; i < numOfVertices; i++){
        keys[i] = 1000;    // infinity number
        mst[i] = false;
    }

    // we start from vertix ( v1)
    // so the key to this vertix  equal 0
    // v1 will added to mstResult
    keys[0] = 0;
    mstResult[0] = -1;

    for (int i = 0; i < numOfVertices - 1;i++){
        // index of vertix that has minimum key and not in mst
        int minVertix_index = minNode(keys,mst);
        //add vertix to mst
        mst[minVertix_index] = true;

        for (int v = 0; v < numOfVertices; v++){
            if (graph[minVertix_index][v] != 0  && mst[v] == false && graph[minVertix_index][v] < keys[v]){
                mstResult[v] = minVertix_index;
                keys[v] = graph[minVertix_index][v]; // update key
            }
        }
    }
    //////////////////////////////////////////////////////////////////////////////
    // print the output
    cout<<"Edges"<< "         "<<"Weight"<<endl;
    cout<<"==================="<<endl;
    for (int i = 1 ; i < numOfVertices; i++){
        cout<<"v"<<mstResult[i]+1<<" - "<<"v"<<i+1<<"         "<<graph[i][mstResult[i]]<<endl;
        cout<<endl;
    }
    //////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////////
int main(){
    // numOfVertices = 7
    // 2D array to represent the graph
    int graph[numOfVertices][numOfVertices] = { { 0, 2,4,1,0,0,0},
                                                                                                {2, 0,0,3,10,0,0},
                                                                                                 { 4,0,0,2,0,5,0},
                                                                                                { 1,3,2,0,7,8,4 },
                                                                                                { 0,10,0,7,0,0,6},
                                                                                                { 0,0,5,8,0,0,1 },
                                                                                               { 0,0,0,4,6,1,0 } };

    findPrimMST(graph);

    return 0;
}


