#include <iostream>
#include <string>

using namespace std;

string middleSquareMethod(int seed) {

	string str = to_string(seed);			//Converts seed from int to string
	int seedLength = str.length();			//Stores in a variable the number of digits
	
	if ((seedLength%2)!=0) {			//Correction in case the seed has an odd number of digits
        	seedLength += 1;			//The length of the variable will be increased by one as
    	}						//if a 0 is inserted at the beginning of the seed (ex 540 -> 0540)

	string sqrStr = to_string(seed*seed);		//Conversion of the square of the root from int to string
	
    	while(sqrStr.length() < seedLength*2)		//Checks that the number of digits of the square of the seed is at least 2*seedLenght
    		sqrStr.insert(0, "0");			//(algorithm requirement) otherwise a padding of zeros is added									

	str = "";					//Result Generation

	for (int i = sqrStr.length()/4; i < (sqrStr.length()/2)+(sqrStr.length()/4); i++) 
		str += sqrStr.at(i);
	
	return str;
}

void iterativeMiddleSquareMethod(int seed, int num){

	string str;

	do {
		str = middleSquareMethod(seed);
		cout << "Number generated: " << str << endl;
		seed = stoi(str);
		num--;
	} while(num > 0);
}

int main() {

	int seed;
	int num;
	int algorithmID;
	cout << "Insert seed:" << endl;
	cin >> seed;
	cout << "Insert how many numbers to generate:" << endl;
	cin >> num;
	
	iterativeMiddleSquareMethod(seed, num);

	return 0;
}
