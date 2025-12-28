const score=document.querySelector(".score");
const startScreen= document.querySelector(".startScreen");
const gameArea=document.querySelector(".gameArea");
let player={speed:5,score:0};
// let keyW=Event.68;
// let key={Enter:false,Space:false}
let keys={ArrowUp:false,ArrowDown:false,ArrowLeft:false,ArrowRight:false,keyW:false,keyA:false,keyS:false,keyD:false};
startScreen.addEventListener("click",start);
// startScreen.addEventListener("keyup",function(event){
//     if(event.keyCode===13)
// startScreen.addEventListener(start);

//     // event.preventDefault();

// });

document.addEventListener("keydown",pressOn);
document.addEventListener("keyup",pressOff);

function  moveLines()
{
    let lines1= document.querySelectorAll(".line1");
    lines1.forEach(function(item){
     //console.log(item.y);
     if(item.y>750){
         item.y-=750;
     }
     item.y+=player.speed;
     item.style.top = item.y+ "px";

    })
    let lines2= document.querySelectorAll(".line2");
    lines2.forEach(function(item){
     //console.log(item.y);
     if(item.y>750){
         item.y-=750;
     }
     item.y+=player.speed;
     item.style.top = item.y+ "px";

    })
    let lines3= document.querySelectorAll(".line3");
    lines3.forEach(function(item){
     //console.log(item.y);
     if(item.y>750){
         item.y-=750;
     }
     item.y+=player.speed;
     item.style.top = item.y+ "px";

    })
}
function isCollide(a,b){
    let aRect=a.getBoundingClientRect();
    let bRect=b.getBoundingClientRect();
    return !(
        (aRect.bottom< bRect.top)||(aRect.top >bRect.bottom)||(aRect.right < bRect.left)||(aRect.left >bRect.right)
    )
}
function  moveEnemy(car)
{
    let ele= document.querySelectorAll(".enemy");
    ele.forEach(function(item){
       if(isCollide(car,item)){console.log("HIT");
       endGame();
    }
     console.log(item.y);
     if(item.y>700){
         item.y-=700;
         item.style.left= Math.floor(Math.random()*400)+"px";
     }
     item.y+=player.speed;
     item.style.top = item.y-100+ "px";

    })
}


function playGame(){
    //console.log("inplay");
    let car=document.querySelector(".car");

    moveLines();
    moveEnemy(car);
    let road=gameArea.getBoundingClientRect();
    console.log(player);
    if(player.start){
    //if(keys.start){
        if((keys.ArrowUp||keys.keyW) && player.y >road.top-150){player.y-=player.speed;}
        if(keys.ArrowDown&& player.y < road.bottom-450){player.y+=player.speed;}
        if(keys.ArrowLeft&&player.x>10){player.x-=player.speed;}
        if(keys.ArrowRight&& player.x< (road.width-80)){player.x+=player.speed;}

      
    car.style.left=player.x+'px';
    car.style.top = player.y+'px';
    window.requestAnimationFrame(playGame);
    player.score++;
    score.innerText="Score : "  +(player.score);
    }

}
function pressOn(e){
    e.preventDefault();
    keys[e.key]=true;
    //console.log(keys);
}
function pressOff(e){
    e.preventDefault();
    keys[e.key]=false;
    //console.log(keys);
}

function endGame(){
    player.start=false;
    score.innerHTML="Game Over<br>Score was "+player.score;
    startScreen.classList.remove("hide");

}
function start(){
    //console.log("click");
    startScreen.classList.add("hide");
    //gameArea.classList.remove("hide");
    gameArea.innerHTML="";
    player.start= true;
    player.score=0;
    for(let x=0;x<5;x++){
        let div= document.createElement("div");
        div.classList.add("line1");
        div.y = x*150;
        div.style.top=(x*150)+"px";
        gameArea.appendChild(div);

    }
    for(let x=0;x<5;x++){
        let div= document.createElement("div");
        div.classList.add("line2");
        div.y = x*150;

        div.style.top=(x*150)+"px";
        gameArea.appendChild(div);

    }
    for(let x=0;x<5;x++){
        let div= document.createElement("div");
        div.classList.add("line3");
        div.y = x*150;

        div.style.top=(x*150)+"px";
        gameArea.appendChild(div);

    }

    for(let x=0;x<2;x++){
        let enemy= document.createElement("enemy");
        enemy.classList.add("enemy");
        enemy.y = ((x+1)*300)-1;
        enemy.style.top=enemy.y+"px";
        enemy.style.left=Math.floor(Math.random()*400)+"px";


        enemy.style.backgroundColor = "black";
        gameArea.appendChild(enemy);
    }
    window.requestAnimationFrame(playGame);
    let car=document.createElement("div");
    // car.innerText="car";
    car.setAttribute("class","car");
    gameArea.appendChild(car);
    player.x=car.offsetLeft;

    player.y=car.offsetTop;
    //console.log(player);

}