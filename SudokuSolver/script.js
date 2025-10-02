const gridElement = document.querySelector(".grid");
for (let i = 1; i <= 81; i++) {
  let input = document.createElement("input");
  input.type = "text";
  input.maxLength = 1;
  input.classList.add("cell");
  gridElement.appendChild(input);
}

let cells = document.querySelectorAll(".cell");
cells.forEach((cell, index) => {
  let row = Math.floor(index / 9) + 1;
  let col = (index % 9) + 1;
  cell.dataset.row = row;
  cell.dataset.col = col;
});

gridElement.addEventListener("keydown", (e) => {
  if (e.target.classList.contains("cell")) {
    let current = e.target;
    let row = Number(current.dataset.row);
    let col = Number(current.dataset.col);

    // console.log(current);
    
    let newRow = row;
    let newCol = col;

    switch (e.key) {
      case "ArrowUp":
        newRow = row - 1;
        break;
      case "ArrowDown":
        newRow = row + 1;
        break;
      case "ArrowLeft":
        newCol = col - 1;
        break;
      case "ArrowRight":
        newCol = col + 1;
        break;
      default:
        return;
    }

    e.preventDefault();
    let nextCell = document.querySelector(
      `.cell[data-row="${newRow}"][data-col="${newCol}"]`
    );
    if (nextCell) {
      nextCell.focus();
      nextCell.select();
    }
  }
});

function isValidInitialGrid(gridValues) {
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      let num = gridValues[i][j];
      if (num !== 0) {
        
        gridValues[i][j] = 0;
        if (!isValidElement(gridValues, i, j, num)) {
          gridValues[i][j] = num;
          return false; 
        }
        gridValues[i][j] = num; 
      }
    }
  }
  return true;
}


function handleClick() {
  let gridValues = [];

  for (let i = 1; i <= 9; i++) {
    let rowCells = document.querySelectorAll(`.cell[data-row="${i}"]`);
    let values = [];
    rowCells.forEach((cell) => {
      if(cell.value)
      {
        cell.classList.add('given')
      }
      else
      {
        cell.classList.remove("given")
      }
      values.push(Number(cell.value) || 0);
    });
    gridValues.push(values);
  }

  // console.log(gridValues);

  if (!isValidInitialGrid(gridValues)) {
    alert("Invalid puzzle! Duplicate values found in row, column, or subgrid.");
    return;
  }
  
  if (solve(gridValues)) {
    // console.log( gridValues);
    updateGrid(gridValues);
  } else {
    alert("No solution exists!");
  }
}


function solve(gridValues) {
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (gridValues[i][j] === 0) {
        for (let k = 1; k <= 9; k++) {
          if (isValidElement(gridValues, i, j, k)) {
            gridValues[i][j] = k;
            if (solve(gridValues)) {
              return true;
            }
            gridValues[i][j] = 0;
          }
        }
        return false;
      }
    }
  }
  return true; 
}


function isValidElement(gridValues, i, j, k) {

  for (let col = 0; col < 9; col++) {
    if (gridValues[i][col] === k) return false;
  }
  
  for (let row = 0; row < 9; row++) {
    if (gridValues[row][j] === k) return false;
  }
  
  let startRow = Math.floor(i / 3) * 3;
  let startCol = Math.floor(j / 3) * 3;
  for (let r = 0; r < 3; r++) {
    for (let c = 0; c < 3; c++) {
      if (gridValues[startRow + r][startCol + c] === k) return false;
    }
  }
  return true;
}


function updateGrid(gridValues) {
  gridValues.forEach((row, i) => {
    row.forEach((val, j) => {
      let cell = document.querySelector(
        `.cell[data-row="${i + 1}"][data-col="${j + 1}"]`
      );
      if(!cell.classList.contains("given"))
      {
        cell.classList.add("solved")
      }
      else
      {
        cell.classList.remove("solved")
      }
      cell.value = val;
    });
  });
}


function clearGrid() {
  cells.forEach((cell) => (cell.value = ""));
}