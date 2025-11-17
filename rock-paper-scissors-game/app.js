const options = ["rock", "paper", "scissor"];

function getRandomInt() {
  return Math.floor(Math.random() * 3);
}

const btns = document.querySelectorAll(".options button");
btns.forEach((btn) => {
  btn.addEventListener("click", () => {
    const playerA = btn.innerText;
    const playerB = options[getRandomInt()];
    compare(playerA, playerB);
  });
});

function compare(player, computer) {
  const won = "YOU WON";
  const lose = "YOU LOST";
  const resultEl = document.querySelector(".hands .result");

  if (player == computer) {
    console.log(`${player} is equal to ${computer}`);
    update(player, computer);
    resultEl.innerText = "DRAW";
  } else if (player == "rock" && computer == "scissor") {
    console.log(`${player} defeats ${computer}`);
    update(player, computer);
    resultEl.innerText = won;
  } else if (player == "rock" && computer == "paper") {
    console.log(`${player} loses to ${computer}`);
    update(player, computer);
    resultEl.innerText = lose;
  } else if (player == "paper" && computer == "scissor") {
    console.log(`${player} loses to ${computer}`);
    update(player, computer);
    resultEl.innerText = lose;
  } else if (player == "paper" && computer == "rock") {
    console.log(`${player} defeats ${computer}`);
    update(player, computer);
    resultEl.innerText = won;
  } else if (player == "scissor" && computer == "rock") {
    console.log(`${player} loses to ${computer}`);
    update(player, computer);
    resultEl.innerText = lose;
  } else if (player == "scissor" && computer == "paper") {
    console.log(`${player} defeats ${computer}`);
    update(player, computer);
    resultEl.innerText = won;
  }
}
function update(player, computer) {
  const rock = "rock.png";
  const paper = "paper.png";
  const scissor = "scissor.png";

  const playerHand = document.querySelector(".hands .player-hand");
  const computerHand = document.querySelector(".hands .computer-hand");

  // playerHand
  if (player == "rock") {
    playerHand.src = rock;
  } else if (player == "paper") {
    playerHand.src = paper;
  } else if (player == "scissor") {
    playerHand.src = scissor;
  }

  // computerHand
  if (computer == "rock") {
    computerHand.src = rock;
  } else if (computer == "paper") {
    computerHand.src = paper;
  } else if (computer == "scissor") {
    computerHand.src = scissor;
  }
}
// // Mapping
// // 0 -> rock, 1->paper, 2->scissor
// const options = ["rock", "paper", "scissor"];

// // number
// /**
//  *
//  * @param {number} player1Choice
//  * @param {number} player2Choice
//  * return string player1, player2, draw
//  */
// function whoWon(player1Choice, player2Choice) {
//   /**
//    * 0, 0 => draw
//    * 0, 1 => rock
//    * 0, 2 => scissor
//    * 1, 0 => rock
//    * 1, 1 => draw
//    * 1, 2
//    * 2, 0
//    * 2, 1
//    * 2, 2 => draw
//    */
// }

// function generateComputerChoice() {
//   let a = options[getRandomInt(3)];
//   console.log(a);
// }
// generateComputerChoice();

// function getRandomInt(max) {
//   return Math.floor(Math.random() * max);
// }
