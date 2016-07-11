#include "course.h"
#include <stack>
#include <map>
#include <iostream>
using namespace std;


vector<course*>* get_courses(){
	course* cs125 = new course("CS 125 - Intro to Computer Science");

	course* cs173 = new course("CS 173 - Discrete Structures");
	cs173->prereqs.push_back(cs125);

	course* cs225 = new course("CS 225 - Data Structures");
	cs225->prereqs.push_back(cs125);
	cs225->prereqs.push_back(cs173);

	course* cs233 = new course("CS 233 - Computer Architecture");
	cs233->prereqs.push_back(cs225);

	course* cs241 = new course("CS 241 - System Programmimg");
	cs241->prereqs.push_back(cs233);

	course* cs374 = new course("CS 374 - Introduction to Algorithms and Models of Computation");
	cs374->prereqs.push_back(cs173);
	cs374->prereqs.push_back(cs225);

	course* cs421 = new course("CS 421 - Programmimg languages and compilers");
	cs421->prereqs.push_back(cs233);
	cs421->prereqs.push_back(cs374);

	course* cs422 = new course("CS 422 - Programmimg languages design");
	cs422->prereqs.push_back(cs421);

	course* cs426 = new course("CS 426 - Compiler Construction");
	cs426->prereqs.push_back(cs421);

	course* cs475 = new course("CS 475 - Formal Models of Computation");
	cs475->prereqs.push_back(cs374);

	course* cs476 = new course("CS 476 - Program Verification");
	cs476->prereqs.push_back(cs225);
	cs476->prereqs.push_back(cs374);

	course* cs477 = new course("CS 477 - Formal Software Development Methods");
	cs477->prereqs.push_back(cs225);
	cs477->prereqs.push_back(cs374);

	vector<course*>* courses = new vector<course*>;
	courses->push_back(cs173);
	courses->push_back(cs225);
	courses->push_back(cs125);
	courses->push_back(cs233);
	courses->push_back(cs374);
	courses->push_back(cs475);
	courses->push_back(cs476);
	courses->push_back(cs477);
	courses->push_back(cs421);
	courses->push_back(cs422);
	courses->push_back(cs426);
	courses->push_back(cs241);

	return courses;
}

int main(){
	std::vector<course*>* courses = get_courses();

	// for(int i = 0; i<(int)courses->size(); i++){
	// 	cout << "Course name: " << (*courses)[i]->name << endl;
	// 	cout << "Its prereqs are: \n";
	// 	if((*courses)[i]->prereqs.size() == 0){
	// 		cout << "This course has no prereqs";
	// 	}
	// 	for (int j = 0; j < (int)(*courses)[i]->prereqs.size(); j++)
	// 	{
	// 		cout << (*courses)[i]->prereqs[j]->name << " , ";
	// 	}
	// 	cout << endl << endl	;
	// }

	// map<course*, int> completed;
	// for(size_t i = 0; i < courses->size(); i++){
	// 	completed[(*courses)[i]] = 0;
	// }

	stack<course*> mystack;
	do{
		if(mystack.empty()){
			mystack.push(courses->back());
			courses->pop_back();	
			continue;
		}

		course* curr = mystack.top();

		if(curr->completed){
			mystack.pop();
			continue;
		}

		if(curr->prereqs.size()==0){

			cout<< curr->name  << endl;

			curr->completed = true;
			mystack.pop();
			continue;
		}

		for(size_t i = 0; i < curr->prereqs.size(); i++){
			if(!curr->prereqs[i]->completed){
				mystack.push(curr->prereqs[i]);
			}
		}

		if(mystack.top() == curr){
			//all the prereqs have been completes, so none were pushed

			// cout<< "all the prereqs have been completes, so none were pushed\n";

			cout<< curr->name  << endl;

			curr->completed = true;
			mystack.pop();
			continue;	
		}


	}while(!mystack.empty() || !courses->empty());


	for(size_t i = 0; i < courses->size(); i++){
		delete (*courses)[i];
	}
	delete courses;

	return 0;
}