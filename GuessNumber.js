const randomNumber = Math.floor(Math.random() * 100) + 1;
let attempts = 0;

while (true) {
    const guess = prompt('Guess a number between 1 and 100:');
    attempts++;

    if (guess === null) {
        alert('Game over. You quit.');
        break;
    }

    const guessNum = parseInt(guess);

    if (isNaN(guessNum) || guessNum < 1 || guessNum > 100) {
        alert('Please enter a valid number between 1 and 100.');
    } else if (guessNum === randomNumber) {
        alert(`Congratulations! You guessed the correct number (${randomNumber}) in ${attempts} attempts.`);
        break;
    } else if (guessNum < randomNumber) {
        alert('Try a higher number.');
    } else {
        alert('Try a lower number.');
    }
}