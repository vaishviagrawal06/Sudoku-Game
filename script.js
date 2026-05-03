let grid = document.getElementById("grid");
let board = Array.from({ length: 9 }, () => Array(9).fill(0));

for (let i = 0; i < 81; i++) {
    let input = document.createElement("input");
    input.maxLength = 1;

    input.oninput = function () {
        let row = Math.floor(i / 9);
        let col = i % 9;
        let val = parseInt(input.value) || 0;

        let temp = board[row][col];
        board[row][col] = 0;

        if (val === 0 || isValid(row, col, val)) {
            board[row][col] = val;
        } else {
            board[row][col] = temp;
            input.value = "";
            alert("Invalid move ❌");
        }
    };

    grid.appendChild(input);
}

function isValid(row, col, num) {
    for (let i = 0; i < 9; i++)
        if (i !== col && board[row][i] === num) return false;

    for (let i = 0; i < 9; i++)
        if (i !== row && board[i][col] === num) return false;

    let sr = row - row % 3;
    let sc = col - col % 3;

    for (let i = 0; i < 3; i++)
        for (let j = 0; j < 3; j++) {
            let r = sr + i;
            let c = sc + j;
            if ((r !== row || c !== col) && board[r][c] === num)
                return false;
        }

    return true;
}

function solveSudoku() {
    for (let row = 0; row < 9; row++) {
        for (let col = 0; col < 9; col++) {
            if (board[row][col] === 0) {
                for (let num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku()) return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

function solve() {
    if (solveSudoku()) {
        let inputs = document.querySelectorAll("input");
        inputs.forEach((input, i) => {
            let r = Math.floor(i / 9);
            let c = i % 9;
            input.value = board[r][c];
        });
    } else {
        alert("No solution ❌");
    }
}