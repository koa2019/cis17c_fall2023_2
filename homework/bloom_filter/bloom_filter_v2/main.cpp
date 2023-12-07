/*
 * v2:
 * creates new string names[8] and fills it randomly with 4
 * strings that are already inserted in the bitarray.
 * Random search for a string in names array and prints if it
 * is probably or not present.
 https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/?ref=header_search
 */
#include <bits/stdc++.h> 
#define ll long long 
using namespace std; 

// hash 1 
int h1(string s, int bitSize) 
{ 
	ll int hash = 0; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = (hash + ((int)s[i])); 
                //cout<<s[i]<<" hash="<<hash<<" ";
		hash = hash % bitSize; 
                //cout<<" hash%bitSize="<<hash<<" \n";
	} 
        //cout<<" hash%bitSize="<<hash<<" \n";
	return hash; 
} 

// hash 2 
int h2(string s, int bitSize) 
{ 
	ll int hash = 1; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = hash + pow(19, i) * s[i]; 
		hash = hash % bitSize; 
	} 
	return hash % bitSize; 
} 

// hash 3 
int h3(string s, int bitSize) 
{ 
	ll int hash = 7; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = (hash * 31 + s[i]) % bitSize; 
	} 
	return hash % bitSize; 
} 

// hash 4 
int h4(string s, int bitSize) 
{ 
	ll int hash = 3; 
	int p = 7; 
	for (int i = 0; i < s.size(); i++) { 
		hash += hash * 7 + s[0] * pow(p, i); 
		hash = hash % bitSize; 
	} 
	return hash; 
} 


// lookup operation 
bool lookup(bool* bitarray, int bitSize, string s) 
{ 
	int a = h1(s, bitSize); 
	int b = h2(s, bitSize); 
	int c = h3(s, bitSize); 
	int d = h4(s, bitSize); 

        // Checks if string may already be in bit array
	if (bitarray[a] && bitarray[b] && bitarray[c] 
		&& bitarray[d]) {
           // cout<<"\t["<<a<<"]="<<bitarray[a]
                    //<<" ["<<b<<"]="<<bitarray[b]
                    //<<" ["<<c<<"]="<<bitarray[c]
                    //<<" ["<<d<<"]="<<bitarray[d]<<"  ";
		return true; 
	} else
		return false; 
} 

// insert operation 
void insert(bool* bitarray, int bitSize, string s) 
{ 
	// check if the element in already present or not 
	if (lookup(bitarray, bitSize, s)) {
		//cout << s << " is Probably already present" << endl; 
            cout<<"";
        } else { // 4 different hashes
		int a = h1(s, bitSize); 
		int b = h2(s, bitSize); 
		int c = h3(s, bitSize); 
		int d = h4(s, bitSize); 

		bitarray[a] = true; 
		bitarray[b] = true; 
		bitarray[c] = true; 
		bitarray[d] = true; 
                
                //cout <<"["<<a<<"]="<<bitarray[a]
                    //<<" ["<<b<<"]="<<bitarray[b]
                    //<<" ["<<c<<"]="<<bitarray[c]
                    //<<" ["<<d<<"]="<<bitarray[d]<<"  ";
		//cout << s << " inserted" << endl; 
	} 
} 





// Driver Code 
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
	int bitSize = 100; 
	bool bitarray[bitSize] = { false }; 
	string sarray[33] 
		= { "abound", "abounds", "abundance", 
		    "abundant", "accessible", "bloom", 
                    "blossom", "bolster", "bonny", 
                    "bonus", "bonuses",	 "coherent", 
                    "cohesive", "colorful", "comely", 
                    "comfort", "gems",	 "generosity", 
		    "generous", "generously", "genial", 
                    "bluff", "cheater",	 "hate", 
                    "war", "humanity",	 "racism", 
                    "hurt", "nuke", "gloomy", 
		    "facebook", "geeksforgeeks", "twitter" }; 
	for (int i = 0; i < 33; i++) { 
		insert(bitarray, bitSize, sarray[i]); 
	} 
        
        
        // Fill half of array with strings that are inserted in the 
        // bitarray.
        int rIndx=0;
        string names[8]={};
        for (int i = 0; i < 4; i++) { 
            for (int j = 0; j<4; j++) {
                rIndx = rand()%33;
            }
            names[i] = sarray[rIndx]; 
            //cout<<names[i]<<" ";            
	} 
        names[4]="December";
        names[5]="may";
        names[6]="winter";
        names[7]="spring";
        
        // Print mixed string array
        cout<<"50-50 mix of strings inside bitarray\n";
        cout<<setw(12)<<"string\t"<<"In bitarray\n";
        for (int i = 0; i < 8; i++) { 
            cout<<setw(12)<<names[i]<<"    ";            
            if(i<4){cout<<"yes\n";}
            else {cout<<"no\n";}
	}
        
        // Search for a random string to test bloom filter
        rIndx=rand()%8;
        string s = names[rIndx];    
        cout<<endl<<"Searching for a random string = "<<s<<endl;
        if (lookup(bitarray, bitSize, s)) {
            cout << s << " is Probably already present" << endl;
        } else {
            cout << s << " is not present" << endl;
        }
        
	return 0; 
}
