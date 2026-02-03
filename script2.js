var player1 = 'X';
var player2 = 'O';

var curPlayer='X';
var gameWin;
var playerWon;

function changePlayer(){ //change player turn button
	if(curPlayer=='X')
	{curPlayer='O'
	 document.getElementById("playerx").setAttribute("class","btn btn-dark turn");
	 document.getElementById("playero").setAttribute("class","btn btn-success turn");
    }
	else{
	curPlayer='X'
	document.getElementById("playerx").setAttribute("class","btn btn-success turn");
	 document.getElementById("playero").setAttribute("class","btn btn-dark turn");
	}
}

function checkWin(){//check for Win
    let b11 = document.getElementById('r1c1').innerText;
    let b12 = document.getElementById('r1c2').innerText;
    let b13 = document.getElementById('r1c3').innerText;
    let b21 = document.getElementById('r2c1').innerText;
    let b22 = document.getElementById('r2c2').innerText;
    let b23 = document.getElementById('r2c3').innerText;
    let b31 = document.getElementById('r3c1').innerText;
    let b32 = document.getElementById('r3c2').innerText;
    let b33 = document.getElementById('r3c3').innerText;
	checkDraw();

	if(b11==b12&&b12==b13&&b11!="")
	{
		gameWin=1;
		playerWon=b11;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
	if(b21==b22&&b22==b23&&b21!="")
	{
		gameWin=1;
		playerWon=b21;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
	if(b31==b32&&b32==b33&&b31!="")
	{
		gameWin=1;
		playerWon=b31;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
	if(b11==b21&&b21==b31&&b11!="")
	{
		gameWin=1;
		playerWon=b11;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
	if(b12==b22&&b22==b32&&b12!="")
	{
		gameWin=1;
		playerWon=b12;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
	if(b13==b23&&b23==b33&&b13!="")
	{
		gameWin=1;
		playerWon=b13;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
	if(b11==b22&&b22==b33&&b11!="")
	{
		gameWin=1;
		playerWon=b11;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
	if(b13==b22&&b22==b31&&b13!="")
	{
		gameWin=1;
		playerWon=b22;
		document.getElementById("staticBackdropLabel").innerText=`Player ${playerWon} Won `;
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
}

function checkDraw(){
	let b11 = document.getElementById('r1c1').innerText;
    let b12 = document.getElementById('r1c2').innerText;
    let b13 = document.getElementById('r1c3').innerText;
    let b21 = document.getElementById('r2c1').innerText;
    let b22 = document.getElementById('r2c2').innerText;
    let b23 = document.getElementById('r2c3').innerText;
    let b31 = document.getElementById('r3c1').innerText;
    let b32 = document.getElementById('r3c2').innerText;
    let b33 = document.getElementById('r3c3').innerText;

	if(b11!=""&&b12!=""&&b13!=""&&b21!=""&&b22!=""&&b23!=""&&b31!=""&&b31!=""&&b32!=""&&b33!="")
	{
		document.getElementById("staticBackdropLabel").innerText="Game Draw";
	    let myModal = new bootstrap.Modal(document.getElementById('staticBackdrop'), {})
        myModal.show()
	}
}

function reset(){
	location.reload();
}

document.getElementById('reset').addEventListener("click",reset);
document.getElementById('resetModal').addEventListener("click",reset);

document.getElementById("r1c1").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r1c2").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r1c3").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r2c1").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r2c2").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r2c3").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r3c1").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r3c2").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});

document.getElementById("r3c3").addEventListener("click",function(){
	this.innerText= `${curPlayer}`;
	this.style.pointerEvents="none";
	
	checkWin();
	changePlayer();
});