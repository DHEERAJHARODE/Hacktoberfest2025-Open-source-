// In regular function "this" doesn't look for outer-scope.

function Regular(name) {
    this.name = name;
    console.log(this);
    // OUTPUT : "this" will refer to Arrow constructor.
    setTimeout(function(){
        console.log(this);
    // OUTPUT : In regular function "this" doesn't look for outer-scope and hence here "this" will refer to window object.
    }, 1000);

}