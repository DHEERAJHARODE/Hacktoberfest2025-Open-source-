
var btn1 = document.querySelector("." + "p");
btn1.addEventListener("click", function () {
    var audio = new Audio("key01.mp3");
    audio.play();
    btn1.classList.add("pressed");
    setTimeout(() => {
        btn1.classList.remove("pressed")
    }, 105);
});
var btn2 = document.querySelector("."+"i");
btn2.addEventListener("click",function () {
    var audio = new Audio ("key02.mp3");
    audio.play();
    setTimeout(() => {
        btn2.classList.remove("pressed")
    }, 105);
});
var btn3 = document.querySelector("."+"a");
btn3.addEventListener("click",function () {
    var audio = new Audio ("key03.mp3");
    audio.play();
    setTimeout(() => {
        btn3.classList.remove("pressed")
    }, 105);
});
var btn4 = document.querySelector("."+"n");
btn4.addEventListener("click",function () {
    var audio = new Audio ("key04.mp3");
    audio.play();
    setTimeout(() => {
        btn4.classList.remove("pressed")
    }, 105);
});
var btn5 = document.querySelector("."+"o");
btn5.addEventListener("click",function () {
    var audio = new Audio ("key05.mp3");
    audio.play();
    setTimeout(() => {
        btn5.classList.remove("pressed")
    }, 105);
});
var btn6 = document.querySelector("."+"q");
btn6.addEventListener("click",function () {
    var audio = new Audio ("key6.mp3");
    audio.play();
    setTimeout(() => {
        btn6.classList.remove("pressed")
    }, 105);
});
var btn7 = document.querySelector("."+"w");
btn7.addEventListener("click",function () {
    var audio = new Audio ("key07.mp3");
    audio.play();
    setTimeout(() => {
        btn7.classList.remove("pressed")
    }, 105);
});
var btn8 = document.querySelector("."+"e");
btn8.addEventListener("click",function () {
    var audio = new Audio ("key08.mp3");
    audio.play();
    setTimeout(() => {
        btn8.classList.remove("pressed")
    }, 105);
});
var btn9 = document.querySelector("."+"r");
btn9.addEventListener("click",function () {
    var audio = new Audio ("key09.mp3");
    audio.play();
    setTimeout(() => {
        btn9.classList.remove("pressed")
    }, 105);
});
var btn10 = document.querySelector("."+"t");
btn10.addEventListener("click",function () {
    var audio = new Audio ("key10.mp3");
    audio.play();
    setTimeout(() => {
        btn10.classList.remove("pressed")
    }, 105);
});
var btn11 = document.querySelector("."+"y");
btn11.addEventListener("click",function () {
    var audio = new Audio ("key11.mp3");
    audio.play();
    setTimeout(() => {
        btn11.classList.remove("pressed")
    }, 105);
});
var btn12 = document.querySelector("."+"u");
btn12.addEventListener("click",function () {
    var audio = new Audio ("key12.mp3");
    audio.play();
    setTimeout(() => {
        btn12.classList.remove("pressed")
    }, 105);
});
var btn13 = document.querySelector("."+"s");
btn13.addEventListener("click",function () {
    var audio = new Audio ("key13.mp3");
    audio.play();
    setTimeout(() => {
        btn13.classList.remove("pressed")
    }, 105);
});
var btn14 = document.querySelector("."+"d");
btn14.addEventListener("click",function () {
    var audio = new Audio ("key14.mp3");
    audio.play();
    setTimeout(() => {
        btn14.classList.remove("pressed")
    }, 105);
});
var btn15 = document.querySelector("."+"f");
btn15.addEventListener("click",function () {
    var audio = new Audio ("key15.mp3");
    audio.play();
    setTimeout(() => {
        btn15.classList.remove("pressed")
    }, 105);
});
var btn16 = document.querySelector("."+"g");
btn16.addEventListener("click",function () {
    var audio = new Audio ("key16.mp3");
    audio.play();
    setTimeout(() => {
        btn16.classList.remove("pressed")
    }, 105);
});
var btn17 = document.querySelector("."+"h");
btn17.addEventListener("click",function () {
    var audio = new Audio ("key17.mp3");
    audio.play();
    setTimeout(() => {
        btn17.classList.remove("pressed")
    }, 105);
});
var btn18 = document.querySelector("."+"j");
btn18.addEventListener("click",function () {
    var audio = new Audio ("key18.mp3");
    audio.play();
    setTimeout(() => {
        btn18.classList.remove("pressed")
    }, 105);
});
var btn19 = document.querySelector("."+"k");
btn19.addEventListener("click",function () {
    var audio = new Audio ("key19.mp3");
    audio.play();
    setTimeout(() => {
        btn19.classList.remove("pressed")
    }, 105);
});
var btn20 = document.querySelector("."+"l");
btn20.addEventListener("click",function () {
    var audio = new Audio ("key20.mp3");
    audio.play();
    setTimeout(() => {
        btn20.classList.remove("pressed")
    }, 105);
});
var btn21 = document.querySelector("."+"z");
btn21.addEventListener("click",function () {
    var audio = new Audio ("key21.mp3");
    audio.play();
    setTimeout(() => {
        btn21.classList.remove("pressed")
    }, 105);
});
var btn22 = document.querySelector("."+"x");
btn22.addEventListener("click",function () {
    var audio = new Audio ("key22.mp3");
    audio.play();
    setTimeout(() => {
        btn22.classList.remove("pressed")
    }, 105);
});
var btn23 = document.querySelector("."+"c");
btn23.addEventListener("click",function () {
    var audio = new Audio ("key23.mp3");
    audio.play();
    setTimeout(() => {
        btn23.classList.remove("pressed")
    }, 105);
});
var btn24 = document.querySelector("."+"v");
btn24.addEventListener("click",function () {
    var audio = new Audio ("key24.mp3");
    audio.play();
    setTimeout(() => {
        btn24.classList.remove("pressed")
    }, 105);
});




































document.addEventListener("keydown", function (event) {
    console.log(event.key);
    pressedkey(event.key);
    animatedbtn(event.key);
});





function pressedkey(key) {
    switch (key) {
        case "p":
            var audio = new Audio("key01.mp3");
            audio.play();
            break;
        case "i":
            var audio = new Audio("key02.mp3");
            audio.play();
            break;
        case "a":
            var audio = new Audio("key03.mp3");
            audio.play();
            break;
        case "n":
            var audio = new Audio("key04.mp3");
            audio.play();
            break;
        case "o":
            var audio = new Audio("key05.mp3");
            audio.play();
            break;
        case "q":
            var audio = new Audio("key6.mp3");
            audio.play();
            break;
        case "w":
            var audio = new Audio("key07.mp3");
            audio.play();
            break;
        case "e":
            var audio = new Audio("key08.mp3");
            audio.play();
            break;
        case "r":
            var audio = new Audio("key09.mp3");
            audio.play();
            break;
        case "t":
            var audio = new Audio("key10.mp3");
            audio.play();
            break;
        case "y":
            var audio = new Audio("key11.mp3");
            audio.play();
            break;
        case "u":
            var audio = new Audio("key12.mp3");
            audio.play();
            break;
        case "s":
            var audio = new Audio("key13.mp3");
            audio.play();
            break;
        case "d":
            var audio = new Audio("key14.mp3");
            audio.play();
            break;
        case "f":
            var audio = new Audio("key15.mp3");
            audio.play();
            break;
        case "g":
            var audio = new Audio("key16.mp3");
            audio.play();
            break;
        case "h":
            var audio = new Audio("key17.mp3");
            audio.play();
            break;
        case "j":
            var audio = new Audio("key18.mp3");
            audio.play();
            break;
        case "k":
            var audio = new Audio("key19.mp3");
            audio.play();
            break;
        case "l":
            var audio = new Audio("key20.mp3");
            audio.play();
            break;
        case "z":
            var audio = new Audio("key21.mp3");
            audio.play();
            break;
        case "x":
            var audio = new Audio("key22.mp3");
            audio.play();
            break;
        case "c":
            var audio = new Audio("key23.mp3");
            audio.play();
            break;
        case "v":
            var audio = new Audio("key24.mp3");
            audio.play();
            break;
        default: console.log("Not found");

    }

}
function animatedbtn(currentkey) {
    var active = document.querySelector("." + currentkey);
    active.classList.add("pressed");
    setTimeout(() => {
        active.classList.remove("pressed");
    }, 100);
}





