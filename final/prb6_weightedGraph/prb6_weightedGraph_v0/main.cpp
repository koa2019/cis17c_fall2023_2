#include <iostream>
#include <string>
using namespace std;

const int MAX_VERTICES = 10; // Adjust the maximum number of vertices

class Node {
public:
    string value;
    int weight;
    Node* next;

    Node(const string& val, int w) : value(val), weight(w), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(const string& val, int weight) {
        Node* newNode = new Node(val, weight);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << "(" << current->weight << ") ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

class Graph {
private:
    string vertices[MAX_VERTICES];
    int numVertices;
    LinkedList* adjList;

public:
    Graph(int verticesCount) {
        numVertices = verticesCount;
        adjList = new LinkedList[numVertices];
    }

    void addVertex(const string& v) {
        for (int i = 0; i < numVertices; ++i) {
            if (vertices[i].empty()) {
                vertices[i] = v;
                break;
            }
        }
    }

    void addEdge(int src, int dest, int weight) {
        adjList[src].insert(vertices[dest], weight);
        adjList[dest].insert(vertices[src], weight); 
    }

    void displayGraph() {
        for (int i = 0; i < numVertices; ++i) {
            if (!vertices[i].empty()) {
                cout << "Adjacency list of vertex " << vertices[i] << ": ";
                adjList[i].display();
            }
        }
    }

    ~Graph() {
        delete[] adjList;
    }
};

int main() {
    string names[] = {"A", "B", "C", "D"};
    int numVertices = 4;

    Graph graph(numVertices);

    // Add vertices to the graph
    for (int i = 0; i < numVertices; ++i) {
        graph.addVertex(names[i]);
    }

    // Adding edges with weights
    graph.addEdge(0, 1, 2); // Edge from 0 to 1 with weight 2
    graph.addEdge(0, 2, 3); // Edge from 0 to 2 with weight 3
    graph.addEdge(1, 2, 1); // Edge from 1 to 2 with weight 1
    graph.addEdge(2, 3, 4); // Edge from 2 to 3 with weight 4

    cout << "Graph's adjacency list with weights:" << endl;
    graph.displayGraph();

    return 0;
}