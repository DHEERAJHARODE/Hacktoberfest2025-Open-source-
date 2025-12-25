'use strict';
const p1 = document.querySelector('.player--0');
const p2 = document.querySelector('.player--1');
const scoreP1 = document.getElementById('score--0');
const currentScoreP1 = document.getElementById('current--0');
const scoreP2 = document.getElementById('score--1');
const currentScoreP2 = document.getElementById('current--1');
const dice = document.querySelector('.dice');
const btnRoll = document.querySelector('.btn--roll');
const btnHold = document.querySelector('.btn--hold');
const btnNew = document.querySelector('.btn--new');

let scores, currentScore, activePlayer, playing;

const init = function () {
  scores = [0, 0];
  currentScore = 0;
  activePlayer = 0;
  playing = true;

  scoreP1.textContent = 0;
  scoreP2.textContent = 0;
  currentScoreP1.textContent = 0;
  currentScoreP2.textContent = 0;

  p1.classList.remove('player--winner');
  p2.classList.remove('player--winner');
  p1.classList.add('player--active');
  p2.classList.remove('player--active');
  dice.classList.add('hidden');
};
init();

function playerSwap() {
  currentScore = 0;
  document.getElementById(`current--${activePlayer}`).textContent =
    currentScore;
  activePlayer = activePlayer === 0 ? 1 : 0;
  p1.classList.toggle('player--active');
  p2.classList.toggle('player--active');
}

btnRoll.addEventListener('click', function () {
  if (playing) {
    const roll = Math.trunc(Math.random() * 6 + 1);
    dice.classList.remove('hidden');
    dice.src = `dice-${roll}.png`;
    if (roll !== 1) {
      currentScore += roll;
      document.getElementById(`current--${activePlayer}`).textContent =
        currentScore;
    } else {
      playerSwap();
    }
  }
});

btnHold.addEventListener('click', function () {
  if (playing) {
    scores[activePlayer] += currentScore;
    scoreP1.textContent = scores[0];
    scoreP2.textContent = scores[1];

    if (scores[activePlayer] >= 100) {
      playing = false;
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.remove('player--active');
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.add('player--winner');
      dice.classList.add('hidden');
      return;
    }
    playerSwap();
  }
});

btnNew.addEventListener('click', init);
