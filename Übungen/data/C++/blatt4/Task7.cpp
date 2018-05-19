#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

vector<double> pot(double n){
	return {n*n, pow(n,3), pow(n,4)}; // Create vector with all values and return it
}

void npot(double n, vector<double> *r){
	*r = {n*n, pow(n,3), pow(n,4)}; // Set vector at the pointer position to result vector
}

int main(int argc, char *argv[]){
	double a; // Argument from console
	if(argc < 2){ // Check if enough arguments passed
		cout << "Not enough arguments passed" << endl;
		return -1;
	} else {
		// Convert from char to double
		stringstream convert(argv[1]);
		if (!(convert >> a)){
			cout << "First argument have to be a number" << endl;
			return -1;
		}
	}
	// Do task and print
	cout<<"Potenzen von "<< a << ":" << endl;
	for(double n : pot(a)) {
        cout << n << endl;
    }
    
    cout << endl;
    
    // Do second task and print
    cout<<"Potenzen von "<< a << ":" << endl;
    vector<double> vec; // Create return vector
	npot(a, &vec); // Pass pointer to function
	for(double n : vec) {
        cout << n << endl;
    }
}




