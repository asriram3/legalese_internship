var stack = function() {

	this._size = 0
	this._storage = {}

	this.push = function(item){
		this._size++
		this._storage[this._size] = item
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


var mystack = new stack()
mystack.push("Burger")
mystack.push(34)
mystack.push(true)
mystack.push("LMAO")

for (var i = mystack._size; i > 0; i--) {
	console.log(mystack.pop())
};