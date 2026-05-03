# 🧩 SudokuX — Console Sudoku Engine in C++

> *A fully playable, auto-solvable Sudoku game built from scratch using core C++ — no libraries, no shortcuts, just pure logic.*

---

## 📌 Table of Contents

- [About the Project](#-about-the-project)
- [Features](#-features)
- [How It Works](#-how-it-works)
- [Installation & Run Instructions](#-installation--run-instructions)
- [Usage Guide](#-usage-guide)
- [Code Structure Overview](#-code-structure-overview)
- [Sample Output](#-sample-output)
- [Future Improvements](#-future-improvements)
- [Technologies Used](#-technologies-used)
- [Author](#-author)

---

## 📖 About the Project

**SudokuX** is a console-based Sudoku game written entirely in **C++** using fundamental programming concepts — no external libraries or game engines involved. It offers two distinct experiences:

1. **Play Mode** — You take the wheel. Enter numbers into the puzzle, erase mistakes, and challenge your logic.
2. **Auto-Solve Mode** — Watch the computer crack the puzzle using a **recursive backtracking algorithm**, one of the classic techniques in computer science.

This project demonstrates the practical application of:
- 2D arrays for grid management
- Recursive algorithms for problem solving
- Input validation and constraint checking
- Clean console UI design

Whether you're a beginner trying to understand recursion or a developer looking for a well-structured portfolio project, SudokuX is a great reference.

---

## ✨ Features

### 🎮 Gameplay
- **Two Modes**: Choose between manual play or watching the AI solve the puzzle
- **9×9 Sudoku Board**: Standard Sudoku layout with 3×3 sub-grids
- **Protected Cells**: Pre-filled (fixed) cells cannot be overwritten — just like a real Sudoku game
- **Erase Support**: Enter `0` for a cell to erase a previously placed number
- **Exit Anytime**: Enter `-1 -1 -1` to quit the game gracefully

### 🔍 Validation System
- ✅ **Row Validation** — No duplicate numbers allowed in any row
- ✅ **Column Validation** — No duplicate numbers allowed in any column
- ✅ **3×3 Box Validation** — No duplicate numbers allowed in each sub-grid
- ✅ **Fixed Cell Protection** — Prevents overwriting pre-filled puzzle values

### 🤖 Auto-Solver
- Solves any valid Sudoku puzzle using **recursive backtracking**
- Displays the fully solved board upon completion
- Handles even the most difficult puzzles

### 🖥️ UI & Display
- Clean, formatted console grid with borders and separators
- Empty cells displayed as `.` for readability
- Clear prompts and error messages for an intuitive experience

---

## 🧠 How It Works

### 🔄 Backtracking Algorithm — Explained Simply

Think of backtracking like solving a maze by trial and error:

1. **Find** the first empty cell (represented as `0` internally).
2. **Try** placing a number from `1` to `9` in that cell.
3. **Check** if the number is valid — does it already appear in the same row, column, or 3×3 box?
4. If **valid** → move on to the next empty cell and repeat.
5. If **no number works** → go *back* (backtrack) to the previous cell and try the next number there.
6. Repeat until the entire board is filled correctly — or determined unsolvable.

This approach guarantees a solution for any valid Sudoku puzzle, though it may explore thousands of possibilities in the worst case.

```
Start → Place number → Valid? → Move forward
                     ↓ No
              Backtrack → Try next number → Still no options? → Backtrack further
```

**Time Complexity**: O(9^(n)) in the worst case, where `n` is the number of empty cells — but constraint checking prunes most branches early, making it extremely fast in practice.

---

## 🛠️ Installation & Run Instructions

### ✅ Prerequisites

Make sure you have a C++ compiler installed:

| Platform | Compiler |
|----------|----------|
| Windows  | [MinGW / g++](https://www.mingw-w64.org/) or MSVC |
| Linux    | `g++` (usually pre-installed) |
| macOS    | `clang++` via Xcode Command Line Tools |

Check if `g++` is available:
```bash
g++ --version
```

---

### 📥 Clone the Repository

```bash
git clone https://github.com/vaishviagrawal06/Sudoku-Game.git
cd sudokux
```

---

### 🔨 Compile the Code

```bash
g++ -o sudoku main.cpp
```

For Windows (using MinGW):
```bash
g++ -o sudoku.exe main.cpp
```

---

### ▶️ Run the Game

**Linux / macOS:**
```bash
./sudoku
```

**Windows:**
```bash
sudoku.exe
```

---

## 🎮 Usage Guide

### 🏁 Starting the Game

When you launch SudokuX, you'll be greeted with the main menu:

```
============================
      Welcome to SudokuX
============================
Select Mode:
  1. Play Mode
  2. Auto-Solve Mode
Enter choice: _
```

---

### 🕹️ Play Mode

1. The Sudoku board will be displayed with pre-filled numbers and `.` for empty cells.
2. You'll be prompted to enter your move in this format:

```
Enter row (1-9), column (1-9), number (1-9): 
```

3. **To place a number**: Enter `row col number`
   ```
   > 3 5 7
   ```

4. **To erase a number**: Enter `0` as the number
   ```
   > 3 5 0
   ```

5. **To quit the game**: Enter `-1 -1 -1`
   ```
   > -1 -1 -1
   ```

6. If your input violates any Sudoku rule, you'll see an error message and be prompted again.

7. The game ends when all cells are correctly filled — congratulations screen displayed! 🎉

---

### 🤖 Auto-Solve Mode

1. Select option `2` from the main menu.
2. The original puzzle is displayed.
3. Press Enter to watch the solver run.
4. The fully solved board is printed instantly.

```
Solving puzzle...

✅ Puzzle Solved Successfully!

[Solved board displayed here]
```

---

## 🗂️ Code Structure Overview

| Function | Description |
|----------|-------------|
| `printBoard()` | Renders the 9×9 Sudoku grid with borders and separators to the console |
| `isValidRow()` | Checks if placing a number in a given row violates the row constraint |
| `isValidCol()` | Checks if placing a number in a given column violates the column constraint |
| `isValidBox()` | Checks if placing a number in its 3×3 sub-grid violates the box constraint |
| `isValid()` | Master validation — calls row, column, and box checks together |
| `solve()` | Recursive backtracking function that solves the puzzle automatically |
| `isFixed()` | Returns `true` if a cell is a pre-filled (protected) puzzle cell |
| `isBoardComplete()` | Checks whether all cells are filled, signaling game completion |
| `playMode()` | Handles the interactive play loop — input, validation, and board updates |
| `main()` | Entry point — displays menu and routes to play or solve mode |

---

## 🖥️ Sample Output

### Board Display
```
╔═══════╦═══════╦═══════╗
║ 5 3 . ║ . 7 . ║ . . . ║
║ 6 . . ║ 1 9 5 ║ . . . ║
║ . 9 8 ║ . . . ║ . 6 . ║
╠═══════╬═══════╬═══════╣
║ 8 . . ║ . 6 . ║ . . 3 ║
║ 4 . . ║ 8 . 3 ║ . . 1 ║
║ 7 . . ║ . 2 . ║ . . 6 ║
╠═══════╬═══════╬═══════╣
║ . 6 . ║ . . . ║ 2 8 . ║
║ . . . ║ 4 1 9 ║ . . 5 ║
║ . . . ║ . 8 . ║ . 7 9 ║
╚═══════╩═══════╩═══════╝
```

### Valid Move
```
Enter row (1-9), col (1-9), number (1-9): 1 3 4

✅ Placed 4 at (1, 3)
```

### Invalid Move
```
Enter row (1-9), col (1-9), number (1-9): 1 3 5

❌ Invalid move! 5 already exists in this row/column/box. Try again.
```

### Fixed Cell Attempt
```
Enter row (1-9), col (1-9), number (1-9): 1 1 9

⚠️  Cannot modify a fixed cell! Choose an empty cell.
```

### Auto-Solve Output
```
Solving puzzle...

✅ Puzzle Solved Successfully!

╔═══════╦═══════╦═══════╗
║ 5 3 4 ║ 6 7 8 ║ 9 1 2 ║
║ 6 7 2 ║ 1 9 5 ║ 3 4 8 ║
║ 1 9 8 ║ 3 4 2 ║ 5 6 7 ║
╠═══════╬═══════╬═══════╣
║ 8 5 9 ║ 7 6 1 ║ 4 2 3 ║
║ 4 2 6 ║ 8 5 3 ║ 7 9 1 ║
║ 7 1 3 ║ 9 2 4 ║ 8 5 6 ║
╠═══════╬═══════╬═══════╣
║ 9 6 1 ║ 5 3 7 ║ 2 8 4 ║
║ 2 8 7 ║ 4 1 9 ║ 6 3 5 ║
║ 3 4 5 ║ 2 8 6 ║ 1 7 9 ║
╚═══════╩═══════╩═══════╝
```

---

## 🚀 Future Improvements

Here are some exciting features that could take SudokuX to the next level:

| Feature | Description |
|--------|-------------|
| 🎯 **Difficulty Levels** | Add Easy, Medium, Hard, and Expert puzzle presets with varying numbers of pre-filled cells |
| ⏱️ **Timer** | Track how long the player takes to solve the puzzle |
| 💾 **Save & Load** | Allow players to save progress to a file and resume later |
| 🎲 **Puzzle Generator** | Randomly generate valid Sudoku puzzles instead of using hardcoded boards |
| ↩️ **Undo Feature** | Let players undo their last move(s) using a stack |
| 💡 **Hint System** | Reveal one correct cell when the player is stuck |
| 🌈 **Colored Output** | Use ANSI color codes to highlight fixed cells, player input, and errors |
| 📊 **Score System** | Track attempts, errors, and time to calculate a final score |
| 🔢 **Multiple Puzzles** | Build a bank of puzzles the player can choose from |
| 🖥️ **GUI Version** | Port the game to a graphical interface using SFML or Qt |

---

## 💻 Technologies Used

| Technology | Purpose |
|------------|---------|
| **C++** | Core programming language |
| **2D Arrays** | Representing the 9×9 Sudoku grid |
| **Recursion** | Powering the backtracking solver |
| **Functions** | Modularizing validation, display, and game logic |
| **Loops** | Iterating through cells, rows, and columns |
| **Console I/O** | `cin` / `cout` for input and output |

> No external libraries or dependencies required. Pure C++ standard library only.

---

## 👤 Author

**Vaishvi Agrawal**  
📧 vaishviagrawal06@gmail.com  
🐙 [GitHub](https://github.com/vaishviagrawal06)  
💼 [LinkedIn](https://www.linkedin.com/in/vaishvi-agrawal-792407331/)

---

> ⭐ If you found this project helpful or interesting, consider giving it a star on GitHub!  
> Feedback and contributions are always welcome. 🙌

---

<p align="center">
  Built with 💙 and C++ | SudokuX © 2025
</p>
