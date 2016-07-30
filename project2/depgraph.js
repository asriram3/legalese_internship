var course = function(course_name){
	this._name = course_name
	this.prereqs = []
	this.completed = false
	this.isbeingtaken = false

	this.addPrereq = function(course){
		this.prereqs.push(course)
	}
}
var stack = function() {

	this._size = 0
	this._storage = {}

	this.push = function(item){
		this._size++
		this._storage[this._size] = item
	}

	this.top = function(){
		return this._storage[this._size]
	}

	this.pop = function(){
		if(this._size>0){
			var val = this._storage[this._size]

			delete this._storage[this._size]
			this._size--
			return val
		}
	}
}



var courses = fill_courses()

get_order(courses)

function get_order(courses){
	var courses_stack = new stack()

	for(var i = 0; i<courses.length; i++){
		courses_stack.push(courses[i])
	}

	var mystack = new stack()

	do{
		if(mystack._size==0){
			mystack.push(courses_stack.pop())
			continue
		}

		var curr = mystack.top()

		if(curr.completed){
			mystack.pop()
			continue
		}

		if(curr.prereqs.length == 0){
			console.log(curr._name)

			curr.completed = true
			mystack.pop()
			continue
		}

		for(var i = 0; i < curr.prereqs.length; i++){
			if(curr.prereqs[i].completed==false){
				mystack.push(curr.prereqs[i])
			}
		}

		if(mystack.top() == curr){
			//all prereqs were completed so none were pushed on the stack

			console.log(curr._name)

			curr.completed = true
			mystack.pop()
			continue
		}



	}while(mystack._size>0 || courses_stack._size>0)
	// }while(false)

}

function fill_courses(){
	var cs125 = new course("CS 125 - Intro to Computer Science")

	var cs173 = new course("CS 173 - Discrete Structures")
	cs173.prereqs.push(cs125)

	var cs225 = new course("CS 225 - Data Structures")
	cs225.addPrereq(cs125)
	cs225.addPrereq(cs173)

	var cs233 = new course("CS 233 - Computer Architecture")
	cs233.addPrereq(cs225)

	var cs241 = new course("CS 241 - System Programmimg")
	cs241.addPrereq(cs233)

	var cs374 = new course("CS 374 - Introduction to Algorithms and Models of Computation")
	cs374.addPrereq(cs173)
	cs374.addPrereq(cs225)

	var cs421 = new course("CS 421 - Programmimg languages and compilers")
	cs421.addPrereq(cs233)
	cs421.addPrereq(cs374)

	var cs422 = new course("CS 422 - Programmimg languages design")
	cs422.addPrereq(cs421)

	var cs426 = new course("CS 426 - Compiler Construction")
	cs426.addPrereq(cs421)

	var cs475 = new course("CS 475 - Formal Models of Computation")
	cs475.addPrereq(cs374)

	var cs476 = new course("CS 476 - Program Verification")
	cs476.addPrereq(cs225)
	cs476.addPrereq(cs374)

	var cs477 = new course("CS 477 - Formal Software Development Methods")
	cs477.addPrereq(cs225)
	cs477.addPrereq(cs374)

	var arr = [cs125, cs173, cs225, cs374, cs233, cs241, cs421, cs422, cs426, cs475, cs476, cs477]
	shuffle(arr)
	return arr
}

function shuffle(array) {
  var currentIndex = array.length, temporaryValue, randomIndex;

  // While there remain elements to shuffle...
  while (0 !== currentIndex) {

    // Pick a remaining element...
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex -= 1;

    // And swap it with the current element.
    temporaryValue = array[currentIndex];
    array[currentIndex] = array[randomIndex];
    array[randomIndex] = temporaryValue;
  }

  return array;
}