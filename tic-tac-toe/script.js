const cells = document.querySelectorAll('.cell');
const statusDiv = document.getElementById('status');
const restartBtn = document.getElementById('restart');
let board = Array(9).fill('');
let currentPlayer = 'X';
let gameActive = true;

const winPatterns = [
    [0,1,2], [3,4,5], [6,7,8], // rows
    [0,3,6], [1,4,7], [2,5,8], // cols
    [0,4,8], [2,4,6]           // diags
];

function checkWinner() {
    for (let pattern of winPatterns) {
        const [a, b, c] = pattern;
        if (board[a] && board[a] === board[b] && board[a] === board[c]) {
            return board[a];
        }
    }
    return board.includes('') ? null : 'draw';
}

function handleClick(e) {
    const idx = +e.target.dataset.index;
    if (!gameActive || board[idx]) return;
    board[idx] = currentPlayer;
    e.target.textContent = currentPlayer;
    const winner = checkWinner();
    if (winner) {
        gameActive = false;
        if (winner === 'draw') {
            statusDiv.textContent = "It's a draw!";
        } else {
            statusDiv.textContent = `Player ${winner} wins!`;
        }
    } else {
        currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
        statusDiv.textContent = `Player ${currentPlayer}'s turn`;
    }
}

function restartGame() {
    board = Array(9).fill('');
    currentPlayer = 'X';
    gameActive = true;
    cells.forEach(cell => cell.textContent = '');
    statusDiv.textContent = `Player X's turn`;
}

cells.forEach(cell => cell.addEventListener('click', handleClick));
restartBtn.addEventListener('click', restartGame);
statusDiv.textContent = `Player X's turn`;
