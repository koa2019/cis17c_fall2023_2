/* Danielle, Dr. Lehr, and
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created: December 6, 2023, 3:14 PM
 * Purpose:  Everything Trees assignment
 * 
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
 * 
 * To do: Create:
 *          * randomize filling tree values
 *          * randomize deleting a node from tree   
 */

//System Libraries
#include<iostream>
#include<iomanip>
#include<algorithm>
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
        
    // Fill tree with random numbers
    cout<<SIZE<<" random numbers:\n";
    for(int i=0;i<SIZE;i++){
        avl.root = avl.insert(avl.root, arr[i]);
    } cout<<endl;
    
    cout << endl << "Pre-order traversal of binary tree: " << endl;
    avl.preorder(avl.root);     
    
    cout<<endl<<"Postorder traversal of binary tree: "<<endl;
    avl.postorder(avl.root);
    
    cout << endl << "Level Order traversal of binary tree: " << endl;
    avl.prntLev(avl.root); cout<<endl;
    
    cout<<"In-order Traversal before Deletion:"<<endl;
    avl.inorder(avl.root); 
    
    // Delete nodes from tree
    avl.deleteBNT(avl.root,1);
    avl.deleteBNT(avl.root,4);
    avl.deleteBNT(avl.root,12);
    avl.deleteBNT(avl.root,8);
    cout<<endl<<"In-order Traversal after Deletion:"<<endl;
    avl.inorder(avl.root);
    
    //Exit stage right!
    return 0;
}