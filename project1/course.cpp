#include "course.h"

course::course(string nam){
	this->name = nam;
	completed = false;
}

course::~course(){
	// for (int i = 0; i < prereqs.size(); ++i)
	// {
	// 	delete prereqs[i];
	// }
}