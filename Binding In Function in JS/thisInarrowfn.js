//arrow function doesn't have their own binding to "this". It actually look-up for outer-scope for "this".

function Arrow(name) {
    this.name = name;
    console.log(this);
    // OUTPUT : "this" will refer to Arrow constructor.
    setTimeout(() => {
        console.log(this);
    // OUTPUT : Unlike regular function in arrow function "this" will refer to Arrow constructor by looking for an outer-scope for "this".
    }, 1000);

}