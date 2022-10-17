#include <iostream>
#include <string>

using namespace std;

string middleSquareMethod(int seed){

	string str = to_string(seed);				//Converts seed from int to string
	int seedLength = str.length();				//Stores in a variable the number of digits
	
	if ((seedLength%2)!=0) {					//Correction in case the seed has an odd number of digits
        str.insert(0, "0"); 					//Adding a 0 at the beginning of the string 
        seedLength += 1;						//Increse of lenght variable
    }

    string sqrStr = to_string(seed*seed);		//Conversion of the square of the root from int to string

    while(sqrStr.length() < seedLength*2)		//Checks that the number of digits of the square of the seed is at least 2*seedLenght
    		sqrStr.insert(0, "0");				//(algorithm requirement) otherwise a padding of zeros is added									

	string result = "";							//Result Generation

	for (int i = (sqrStr.length()/2)/2; i < sqrStr.length()/2; i++) 
		result += sqrStr.at(i);
	
	for (int i = sqrStr.length()/2; i < (sqrStr.length()/2)+(sqrStr.length()/2)/2; i++) 
		result += sqrStr.at(i);

	return result;
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