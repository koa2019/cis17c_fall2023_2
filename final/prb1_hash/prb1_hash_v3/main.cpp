/* File:    main.cpp
 * Author:  Danielle F
 * Created: 12-07-2023 @ 6 PM
 * Purpose: CIS-17C Final problem 1 v3
 * 
 * v3:
 * 
 * To do:
 * Push vector of hashes into a linked list.
 * Count number of collisions.
 * Make h2() hash with the map('A',2) instead of h1()'s switch case.
*/

//System Libraries
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include  <algorithm>
#include <iterator>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "SimpleVector.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
int h1(string); // Switch converts string to corresponding phone numbers
string h2(string);
//int h3(string);
void setHashes(const vector<string>, vector<int> &);
void setInitials(string &);
void setLetters(vector<string>&);//Generate container of random 3 letter strings
int mrkRand(int seed=0);
void fillVec(vector<int> &);//
void prntHashes(const vector<string>, const vector<int>);
void prntVecStr(vector<string>);
void prntVecInt(vector<int> &, int perLine=10);//Prints indices used in simple vector


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
        
    srand(static_cast<unsigned int>(time(0))); //Set random number seed once here
    //rand()%90+10;//2 digit numbers    
    
    //Declare & initialize variables    
    const int SIZE=512;  // size of linked list array   
    string str=" ";      // User's initials      
    vector<string> vecStr; // Container of random 3 letter strings
    vector<int> vecHash;   // Container of hashed 3 letter strings
    int collsn0,collsn1,collsn2,collsn3;
    collsn0=collsn1=collsn2=collsn3=0;
    
    // Map inputs to outputs
    setLetters(vecStr);   // Generate container of random 3 letter strings 
    setInitials(str); //  Prompt for user's initials
    vecStr.push_back(str); // Push user's initials into container
    setHashes(vecStr,vecHash); // Hash the container of 3 letter strings    
    // Outputs
    cout<<"You entered: "<<str<<endl;
    cout<<"["<<SIZE-1<<"]="<<vecStr[SIZE-1]<<"="<<vecHash[SIZE-1]<<" %512 = "<<vecHash[SIZE-1]%512<<endl<<endl;
    //cout<<"\tVector of hashed initials:\n";
    //prntVecStr(vecStr); // Print vector of random 3 letter initials
    //prntVecInt(vecHash);  // Print vector of  hashed initials
    //prntHashes(vecStr,vecHash);

    
    int n=SIZE+1,// +1 compensates for the [0]=0 created in constructor
        num=0, 
        indx=0, 
        totlCollsion=0;  
    vector<int> indxUsed1x;
    vector<int> iCollsions;
    
    // Allocating  memory for a static array of Linked Lists
    SimpleVector<int> *sv;
    sv = new SimpleVector<int>[SIZE];//SimpleVector<int> sv(size);
    
    //cout<<"\nSetting Hashes in Array\n";
    vector<int>::iterator it;
    for(int i=0;i<SIZE;i++){
        num=vecHash[i];//rand()%26+65;
        indx=num%SIZE;
        //cout<<i<<". Pushing: "<<num<<".  ";
        sv[indx].pushBack(num);// Save hash to linked list
        
        // Save single copy of the indx hashes that were used to a vector
        it = std::find(indxUsed1x.begin(), indxUsed1x.end(), indx);
        if(it==indxUsed1x.end()){indxUsed1x.push_back(indx); // keep track of indices used
        } else{
            iCollsions.push_back(indx);// keep track of indices that collided
            totlCollsion++;}
            
        //cout<<i<<". ["<<indx<<"] = ";
        //sv[indx].prntSV();  
    }
    
    cout<<endl; 
    sort(indxUsed1x.begin(), indxUsed1x.end());
    cout<<endl<<"Index's used in SimpleVector = {\n";    
    prntVecInt(indxUsed1x,10);
    
    sort(iCollsions.begin(), iCollsions.end());
    //cout<<endl<<endl<<"Index's that Collided = {\n";    
    //prntVecInt(iCollsions,10);
    
    // Find unique indices used in hash
    vector<int> indxNOCol;
    vector<int> copy;
    vector<int> unqColIndx(iCollsions.size());
    copy=iCollsions;
    cout<<endl<<endl<<"Copy of Index's that Collided = {\n";
    prntVecInt(copy,10);
    it = std::unique_copy(copy.begin(), copy.end(), unqColIndx.begin());
    unqColIndx.resize(std::distance(unqColIndx.begin(), it));// Resizing vector copy
    cout<<endl<<endl<<"Unique Index's that Collided = {\n";
    prntVecInt(unqColIndx,10);
    
    // if indxUsed1x[i] is not in iCollisons container, 
    // then it has NO collisions
    int numUniq=0, nCollsn=0;
    for(int j=0;j<indxUsed1x.size();j++){
        it = std::find(indxUsed1x.begin(), indxUsed1x.end(), unqColIndx[j]);
        if(it==indxUsed1x.end()){
            cout<<"NO Col "<<setw(3)<<numUniq<<". ["<<setw(3)<<j<<"] "<<indxUsed1x[j]<<"!="<<unqColIndx[j]<<endl;
            numUniq++;
            indxNOCol.push_back(indxUsed1x[j]);
        } else {
         cout<<"crash "<<setw(3)<<nCollsn<<". ["<<setw(3)<<j<<"] "<<*it<<"=="<<unqColIndx[j]<<endl;              
         nCollsn++;
        }       
    }
    
    cout<<endl<<endl<<"Indices With No Collisions = {\n";
    prntVecInt(indxNOCol,10);
    
    // Calculate collision frequencies
    int max,min=1,freq,ones,twos,threes,plus3,maxIndx,minIndx;
    max=num=freq=ones=twos=threes=plus3=maxIndx=minIndx=0;
    
    for(int j=0;j<iCollsions.size();j++){
        
        num=iCollsions[j];
        freq=count(iCollsions.begin(),iCollsions.end(),num);
        if(freq==1){ones++;}
        else if(freq==2){twos++;}
        else if(freq==3){threes++;}
        else {plus3++;}
        
        min = freq<=min ? freq : min;
        if(freq>max){
            max = freq;
            maxIndx=num;
        }
        //cout<<j<<". "<<num<<" freq = "<< freq <<endl;        
    }
    
    
    
    // Linked List Report
    int sumHash=totlCollsion+indxUsed1x.size();
    cout<<left<<endl<<endl<<"Linked List Collision Report:\n";
    cout<<setw(28)<<"Size of array:        "<<SIZE<<endl;
    cout<<setw(28)<<"Number of hashes:     "<<vecHash.size()<<endl;
    cout<<setw(26)<<"Total indiv indices filled"<<": "<<indxUsed1x.size()<<endl;
    cout<<setw(28)<<"Number of empty indices: "<<SIZE-indxUsed1x.size()<<endl;
    cout<<setw(28)<<"Total collisions:     "<<totlCollsion<<endl;
    cout<<setw(28)<<"Sum of hashes:        "<<sumHash<<endl;
    cout<<setw(28)<<"Max freq:             "<<max<<endl;
    cout<<setw(28)<<"Index Hashed Most:    "<<maxIndx<<endl;
    cout<<setw(28)<<"Min freq:             "<<min<<endl;
    cout<<setw(28)<<"No collisions:        "<<numUniq<<endl;
    cout<<setw(28)<<"1  collisions:       "<<ones<<endl;    
    cout<<setw(28)<<"2  collisions:       "<<twos<<endl;
    cout<<setw(28)<<"3  collisions:       "<<threes<<endl;
    cout<<setw(28)<<"4+ collisions:       "<<plus3<<endl;
    
    return 0;
}

//******************************************************************************
//                  Function Implementations  
//******************************************************************************


//******************************************************************************
//         Converts a 3 letter string into a 3 digit string based on 
//          the buttons on a phone. Returns a number. "MEL" -> 635 
//******************************************************************************
int h1(string str){
    int seed;
    int hash=0;
    for(int i=0;i<str.size();i++){    
        switch(str[i]){
            case 'A': case 'B': case 'C':{ seed=2; break;}
            case 'D': case 'E': case 'F':{ seed=3; break;}
            case 'G': case 'H': case 'I':{ seed=4; break;}   
            case 'J': case 'K': case 'L':{ seed=5; break;}
            case 'M': case 'N': case 'O':{ seed=6; break;}
            case 'P': case 'Q': case 'R': case 'S':{ seed=7; break;}
            case 'T': case 'U': case 'V': { seed=8; break;}
            case 'W': case 'X': case 'Y': case 'Z':{ seed=9; break;}
        }         
        hash = (hash * 10) + seed;
    }    
    return hash;
}

//******************************************************************************
//         Hash a 3 letter string into a 3 digit string based on 
//          the buttons on a phone. Returns a number. "MEL" -> 635 
//******************************************************************************

string h2(string str){
    string temp="h2";    
    unordered_map<char, int> phone = {
        {'A', 2}, {'B', 2}, {'C', 2},
        {'D', 3}, {'E', 3}, {'F', 3},
        {'G', 4}, {'H', 4}, {'I', 4},
        {'J', 5}, {'K', 5}, {'L', 5},
        {'M', 6}, {'N', 6}, {'O', 6},
        {'P', 7}, {'Q', 7}, {'R', 7}, {'S', 7},
        {'T', 8}, {'U', 8}, {'V', 8},
        {'W', 9}, {'X', 9}, {'Y', 9}, {'Z', 9}
    };
    
    //for(int i=0;i<str.size();i++){ 
        
    //}
   return temp;  
}


//******************************************************************************
//              Hash the container of 3 letter strings
//******************************************************************************

void setHashes(const vector<string> vecStr, vector<int> &vecHash){
    int hash=0;
    vector<int>::iterator it;
    for(int i=0;i<vecStr.size();i++){   
        hash=h1(vecStr[i]);// Calls hash1 function
        //cout<<left<<setw(2)<<i<<". Hash: "<<hash<<" %512 = "<<hash%512<<endl;
        vecHash.push_back(hash); 
    }
}

//******************************************************************************
//              Generate container of random 3 letter strings
//******************************************************************************

void setLetters(vector<string> &vecStr){
    const int SIZE=511;
    char ch1,ch2,ch3;
    string letters="";
    vector<int>::iterator it;
    for(int i=0;i<SIZE;i++){   
        for(int j=0;j<3;j++){
            ch1 = 65+(rand()%26); //A-Z[65,90]  
            letters+=ch1;
            //cout<<ch1<<" ";
        }//cout<<letters<<" "<<endl;
        vecStr.push_back(letters); 
        letters="";
    }
}

//******************************************************************************
//              Get user's 3 initials
//******************************************************************************

void setInitials(string &str){
    str="MEL";
    //cout<<"Input 3 letters that represent your initials.\n";
    //cin>>str;
}

//******************************************************************************
//              Print container of strings and hashes
//******************************************************************************

void prntHashes(const vector<string> vecStr, const vector<int> vecHash){
    int index=0, hash=0;
    do{
        cout<<endl<<"Enter a number between 0 and "<<vecHash.size()-1
            <<". To exit enter: -66\n";
        cin>>index;
        if(index>=0 && index<=vecHash.size()-1){
            hash=vecHash[index];
            cout<<"["<<index<<"] = "<<vecStr[index]<<" = "<<hash<<" % 512 = "<<hash%512<<endl;
        }
    } while(index!=-66 || (index>=0 && index<=vecHash.size()-1));
}
    
//******************************************************************************
//              Print container of random 3 lettered strings
//******************************************************************************

void prntVecStr(vector<string> vecStr){        
    cout<<"\n\n\tVector of random 3 initials:\n";
    for(int i=0;i<vecStr.size();i++){ 
        cout<<vecStr[i]<<" ";
        if(i%10==9){cout<<endl;}
    } cout<<endl<<endl<<endl;
}

//******************************************************************************
//              Print container of hashed integers
//******************************************************************************

void prntVecInt(vector<int> &vecStr, int perLine){  
    cout<<"vector size: "<<vecStr.size()<<endl;
    for(int i=0;i<vecStr.size();i++){
        cout<<setw(3)<<vecStr[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    } cout<<"}"<<endl;
}


void fillVec(vector<int> &vec){
    for(int i=0;i<5;i++){vec[i]=mrkRand(5)%26+65;}
}

int mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}