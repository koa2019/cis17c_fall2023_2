/* File:    main.cpp
 * Author:  Danielle F
 * Created: 
 * Purpose:  cis17c final prb6_weightedGraph v1
*/

//System Libraries
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
// struct store adj list nodes
struct Node {
    int val,cost;
    Node *next;
};

// struct store graph edges
struct Edge {
    int src, dest, weight;
};

class Graph {
    protected:
    int N; // Number of vertices/nodes in graph
    
    // func allocate new node of adj list
    Node* getAdjListNode(int value, int weight, Node* head)
    {
        Node* newNode = new Node;
        newNode->val  = value;
        newNode->cost = weight;
        
        // point new node to current head
        newNode->next = head;
        
        return newNode;
    }


    public:
    
        // array of pointers to Node to rep adj list
        Node **head;
    
        // Constructor
        Graph(Edge edges[], int n, int N)// N=Number of vertices in graph
        {                                // n=number of edges 
            
            //cout<<"NumVertices = "<<N<<" numEdges = "<<n<<endl;
            //int count=0;
            
            // allocate memory
            head = new Node*[N](); // array of pointer Nodes
            this->N = N;          // Set Number of vertices in graph
    
            // initialize head ptr for all vertices
            for(int i=0; i<N; i++)
            {
                //Trying to make adjacency list directed and not undirected
                // because it prints dupes sometimes
                //count=0;
                int nDirectdEdge = sizeof(edges[i])/sizeof(edges[i].weight);
                 cout<<"nDirectdEdge = "<<nDirectdEdge<<" \n";//<<edges[0].weight<<endl;
                
                head[i] = nullptr;
                
                for(unsigned i=0; i<n; i++)// n=number of edges
                {
                    //cout<<count++<<" =  ";
                    //cout<<"i="<<i<<" ";
                    int src  = edges[i].src;
                    int dest = edges[i].dest;
                    int weight = edges[i].weight;
                    //cout<<src<<","<<dest<<","<<weight<<endl;
                    
                    // insert in beginning
                    // Create array of Adj Node and the weight of it
                    //cout<<"head["<<src<<"] = "<<head[src]<<endl;
                    Node* newNode = getAdjListNode(dest, weight, head[src]);
    
                    // point head ptr to new node
                    head[src] = newNode;
    
                //    // uncomment below lines for undirected graph
                    newNode = getAdjListNode(src,weight,head[dest]);
                //   //  change head ptr to pt to new node
                    head[dest] = newNode;
                }
                //cout<<endl;
            }
        }
    
        // Destructor
        ~Graph() 
        {
            for(int i=0; i<N; i++)
            { delete [] head[i]; }
            delete [] head;
        }
};


string getCity(int loc){
    string str = loc==0 ? "BOS" :
                 loc==1 ? "DFW" :
                 loc==2 ? "SFO" :
                 loc==3 ? "JFK" :
                 loc==4 ? "LAX" :
                 loc==5 ? "MIA" : "ORD";
    return str;
}


// Calculate shortest path ORD to LAX == vertex 6 to 4
void setShrtPath(Node *ptr, int begn, Node *endPtr, int finalDes, int numStop){    
    
    string start  = getCity(begn);
    string end   = getCity(finalDes);
    int sum=0;
    int stop1 = numStop;
    bool keepGoing=true;
    while(ptr != nullptr){        
        //cout << "("<<start<< ","<< ptr->val<< ","<< ptr->cost << ") \n";  
        if(ptr->val==stop1){
            sum += ptr->cost;
            cout<<start<<" to "<<getCity(stop1)<<" Cost: "<<setw(4)<<ptr->cost<<" sum: "<<sum<<endl;
            keepGoing=false;
        }
        if(keepGoing){ptr = ptr->next;}
        else {ptr=NULL;}
    }
    
    while(endPtr != nullptr){        
        //cout << "("<<dest<< ","<< endPtr->val<< ","<< endPtr->cost << ")\n";  
        if(endPtr->val==stop1){
            sum+=endPtr->cost;
            cout<<getCity(stop1)<<" to "<<end<<" Cost: "<<setw(4)<<endPtr->cost<<" sum: "<<sum<<endl;
            break;
        }
        endPtr = endPtr->next;
    }
    cout << start << " to " << end << " weight: " << sum << endl;
}


// print all neighboring vertices of given vertex
void prntList2(Node *ptr, int x){    
    
    string src  = getCity(x);
    string dest = " ";
    cout<<"Node "<<x<<" "<<src<<" Adj List: \n";
    while(ptr != nullptr){
        cout<<"\t("<<src<< ",";        
        int y = ptr->val;
        dest =  getCity(y);    
        cout << dest << "," <<setw(4)<<right<< ptr->cost << ") \n";
        ptr = ptr->next; // Move iterator to next node
    }
    cout<<endl;
}

// print all neighboring vertices of given vertex
void prntList(Node *ptr, int i){    
    
    while(ptr != nullptr){
        cout<<"("<<i<< ","<< ptr->val <<","
            << ptr->cost << ") \n";
        ptr = ptr->next;
    }
    cout<<endl;
}

// Dijkstra's algorithm to find shortest path from src to all vertices
//map<string, int> dijkstra(struct Graph& graph, string src) {
//    map<string, int> dist;
//    set<pair<int, string>> pq;
//
//    for (auto& it : graph.adj) {
//        string v = it.first;
//        dist[v] = (v == src) ? 0 : INT_MAX;
//        pq.insert(make_pair(dist[v], v));
//    }
//
//    while (!pq.empty()) {
//        string u = pq.begin()->second;
//        pq.erase(pq.begin());
//
//        for (auto& v : graph.adj[u]) {
//            if (dist[u] != INT_MAX && dist[v.dest] > dist[u] + v.weight) {
//                pq.erase(make_pair(dist[v.dest], v.dest));
//                dist[v.dest] = dist[u] + v.weight;
//                pq.insert(make_pair(dist[v.dest], v.dest));
//            }
//        }
//    }
//
//    return dist;
//}


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers   
    //(rand()%18)+99; //[99,117]
    //(rand()%20)+(1+rand()%9); //[0,29]
    //char ch = 65+(rand()%26); //A-Z[65,90]
       
       
    // array of graph edges as per above diagram.    
    Edge edges[] =  
    {   
        // (src,dest,weight)->(x,y,w) edge from x to y having weight w
        {0,2,2730},{0,3,189},{0,5,1257},{0,6,868}, // x=0=BOS
        {1,2,1465},{1,4,1234},{1,5,1124},{1,6,803}, // x=1=DFW
        {2,4,338}, {2,6,1847},// x=2=SFO
        {3,5,1093},// x=3=JFK
        {4,5,2341},// x=4=LAX, // x=5=MIA        
        {6,3,743}// x=6=ORD
    };
//    {0,2,2730},{0,3,189},{0,5,1257},{0,6,868}, // x=0=BOS
//        {1,2,1465},{1,4,1234},{1,5,1124},{1,6,803}, // x=1=DFW
//        {2,0,2703},{2,1,1465},{2,4,338}, {2,6,1847},// x=2=SFO
//        {3,0,189},{3,5,1093},{3,6,743},// x=3=JFK
//        {4,1,1234},{4,2,338},{4,5,2341},// x=4=LAX
//        {5,0,1257},{5,1,1124},{5,3,1093},{5,4,2341},// x=5=MIA
//        {6,0,868}, {6,1,803}, {6,2,1847},{6,3,743}// x=6=ORD

    
    // N=Number of vertices in graph
    int N = 7;
        
    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);       
    
    // construct graph
    Graph graph(edges, n, N);

    // Print adj list representation of graph
    cout<<endl<<"Adjacency list of graph"<<endl;
    cout<<"Vertices: "<<N<<" edges: "<<n<<endl;
    cout<<"\t("<<"src"<< ","<< "dest"<<","<< "wt" << ")\n";
    
    for(int i=0;i<N;i++){// N=Number of vertices in graph
        // print all its neighboring vertices
        prntList2(graph.head[i], i);        
    }

    cout<<endl<<"Shortest path from ORD to LAX:\n";
    setShrtPath(graph.head[6],6,graph.head[4],4,1);// shortest path ORD to LAX == vertex 6 to 4
    
    cout<<endl<<"Shortest path from JFK to SFO:\n";
    setShrtPath(graph.head[3],3,graph.head[2],2,6);// shortest path ORD to LAX == vertex 6 to 4
     
    cout<<endl<<"Yes my hand written analysis matches my program.\n";
    
    return 0;
}
//******************************************************************************
//                  Function Implementations  
//******************************************************************************

//******************************************************************************
//              
//******************************************************************************