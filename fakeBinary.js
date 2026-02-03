// Given a string of digits, you should replace any digit below 5 with '0' and any digit 5 and above with '1'. Return the resulting string.

// SOLUTION v1

const fakeBin = (x) => { 
    let newArr = [];
    let parseArr = x.split(""); 
    parseArr.forEach(function replaceDigits(d) {
        if (d < 5) {
            newArr.push(0)
        } else if (d >= 5) {
            newArr.push(1)
        }
    });
    let newStr = newArr.join("")
    return newStr
}


// SOLUTION v2:: Refactored with ternary and function shorthand on the forEach callback 

const fakeBin = (x) => { 
    let newArr = [];
    let parseArr = x.split(""); 
    parseArr.forEach(d => {
        d < 5 ? newArr.push(0) : newArr.push(1)
    });
    return newStr = newArr.join("")
}

// SOLUTION v3:: Refactored with chaining and declaring variable within the arguments of function 
// p.s. Note to self - it feels so good to go back and be able tear apart and condense your old code.. Like a pro :D  

const fakeBin = (x, newArr = []) => { 
    x.split("").forEach(d => d < 5 ? newArr.push(0) : newArr.push(1))
    return newArr.join("")
}

// And for the magnificent one-liner.. 

const fakeBin = (x, ar = []) => { x.split("").forEach(d => d < 5 ? ar.push(0) : ar.push(1)); return ar.join("") }


// AND FOR THE MOST condensed elegant one-liner madness.. 

const fakeBin = (x) => { return x.replace(/\d/g, d => d < 5 ? 0 : 1) }