#include <iostream>
#include <string>

#include "Solution.h"

using namespace std;
using namespace cc;

int main()
{
	Solution s(10.0);
	Solution o(10.0);

	cout << "Expected: 1\n";
	cout << "Result: " << (s / o).getVal() << endl;

	cout << "Expected: 0\n";
	cout << "Result " << (s / Solution(ExistenceType::Infinity)).getVal() << endl;

	cout << "Expected: " << (int)ExistenceType::NegInfinity << '\n';
	cout << "Result " << (int)(Solution(ExistenceType::Infinity) / (-s)).getType() << endl;

	cout << "Expected: " << (int)ExistenceType::Undefined << '\n';
	cout << "Result: " << (int)(s / Solution(0.0)).getType() << endl;
	
	string input;
	getline(cin, input);

	return 0;
}