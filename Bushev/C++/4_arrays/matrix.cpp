#include <iostream>

#define MSIZE 2

using namespace std;

int main(){
    int mA[MSIZE][MSIZE], mB[MSIZE][MSIZE], mC[MSIZE][MSIZE] = {0};
    
    cout << "Fill in the 1st Matrix\n";
    
    for(int i = 0; i <MSIZE; i++){
        for(int j = 0; j < MSIZE; j++){
            cin >> mA[i][j];
        }
    }
    
    cout << "\nFill in the 2nd Matrix\n";
    
    for(int i = 0; i <MSIZE; i++){
        for(int j = 0; j < MSIZE; j++){
            cin >> mB[i][j];
        }
    }
    
    cout << endl << "A+B: " << endl;
    
    for(int i = 0; i < MSIZE; i++){
        for(int j = 0; j < MSIZE; j++){
            cout << mA[i][j] + mB[i][j] << " ";
        }
        
        cout << endl;
    }
    
    cout << endl << "A-B: " << endl;
    
    for(int i = 0; i < MSIZE; i++){
        for(int j = 0; j < MSIZE; j++){
            cout << mA[i][j] - mB[i][j] << " ";
        }
        
        cout << endl;
    }
    
    cout << endl << "A * B: " << endl;
    
    int val = 0;
    
    for(int i = 0; i < MSIZE; i++){
    	for(int j = 0; j < MSIZE; j++){
    		val = 0;
    		
    		for(int c = 0; c < MSIZE; c++){
    		    mC[i][j] += mA[i][c] * mB[c][j];
    		}
    		
    		cout << mC[i][j] << " ";
    	}
    	
    	cout << endl;
    }
    
    cout << endl;
    
    if(MSIZE == 2){
        cout << "det A * B: ";
        cout << mC[0][0] * mC[1][1] - mC[0][1] * mC[1][0] << endl;
    }
    
    return 0;
}