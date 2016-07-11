#include <string>
#include <iostream>
#include <vector>

using namespace std;

class course
{
public:
	course(string nam);
	~course();

	string name;
	vector<course*> prereqs;
	bool completed;

	/* data */
};