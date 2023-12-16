/* Danielle, Dr. Lehr, and
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created: December 6, 2023, 3:14 PM
 * Purpose:  Everything Trees assignment
 * 
 * Original program:
 * Uses a class and a structure.
 * Traverses tree 3 different ways (in-order,pre, post).
 * Inserts node into the tree.
 * Deletes a node from the tree.
 * Balances tree using AVL technique.
 * 
 * Completed:
 *          * level order traversal function
 *          * randomize filling tree values
 *          * randomize deleting a node from tree  
 * 
 * To do: Create:

 */

//System Libraries
#include<iostream>
#include<iomanip>
#include<algorithm>
#include <vector>
using namespace std;
 
//User Libraries
#include "AVLTree.h"

//Global Constants

//Function Prototypes
void menu();

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers    
    
    AVLTree avl;
    int choice, item;
    int num1=0, num2=0;  
    const int SIZE = 15;
    int arr[]={8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
    vector<int> node;
    
    // Fill tree with random numbers    
    for(int i=0;i<SIZE;i++){        
        for(int j=0;j<7;j++){//shuffle so i hopefully dont get duplicates
            num1 = rand()%10;// [0,10)  
            num2 = num1 + (rand()%50+1);// [1,50]  
        }
        node.push_back(num2);// Push rand number into vector
        //cout<<"num2 = "<<num2<<"  node="<<node[i]<<" ";     
        avl.root = avl.insert(avl.root, num2);//(avl.root, arr[i]);
    } cout<<endl;
    
    // Print results
                                                
 
    cout << endl << "Pre-order traversal of binary tree: " << endl;
    avl.preorder(avl.root);     
    
    cout<<endl<<"Postorder traversal of binary tree: "<<endl;
    avl.postorder(avl.root);
    
    cout << endl << "Level Order traversal of binary tree: " << endl;
    avl.prntLev(avl.root); cout<<endl; 
    
    cout<<"In-order Traversal before Deletion:"<<endl;
    avl.inorder(avl.root);
    
    // Delete nodes from tree
    vector<int>::iterator it;
    vector<int> deleted;
    for(int i=0;i<4;i++){ 
        num1 = rand()%node.size();// [0,15)
        it = node.begin()+num1;
        deleted.push_back(node[num1]);
        avl.deleteBNT(avl.root,node[num1]);
        node.erase(it);
    }

    cout<<endl<<"In-order Traversal after Deletion:"<<endl;
    avl.inorder(avl.root); cout<<endl;
    
    cout<<endl<<deleted.size()<<" Nodes Randomly Deleted:\n";
    for(int i=0;i<deleted.size();i++){cout<<deleted[i]<<" ";}cout<<endl;
    
    //Exit stage right!
    return 0;
}