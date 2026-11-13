# 💧 Water Sort Puzzle

A console-based **Water Sort Puzzle game** developed using **C programming language** as part of the CSE207: Data Structures course at East West University.

The objective is to sort randomly distributed colored liquids into separate tubes so that each tube contains only one color.

## 🎮 Project Overview

The game consists of 6 tubes, 4 different colors, and a maximum capacity of 4 units per tube. Initially, 4 tubes contain randomly distributed colors, while the remaining 2 tubes are empty.

Players must transfer colors between tubes while following specific rules until all colors are successfully sorted.

## ✨ Features

- **Randomized Puzzle Generation:** Generates a random initial puzzle using the Fisher-Yates shuffle algorithm.
- **Move Validation:** Prevents invalid moves based on tube capacity and color-matching rules.
- **Stack-Based Operations:** Uses stack principles to manage color transfers.
- **Undo Functionality:** Allows players to restore the previous game state.
- **Restart Functionality:** Restarts the game with a new randomized puzzle.
- **Win Condition Detection:** Automatically detects when the puzzle is successfully completed.
- **Interactive Console Interface:** Allows users to interact with the game through console commands.

## 🧩 Game Rules

1. A player can transfer colors from one tube to another.
2. The destination tube must be empty or contain the same topmost color as the source tube.
3. The destination tube must have enough available space.
4. A tube is considered sorted when it contains only one color.
5. The game is completed when all tubes are either empty or contain a single uniform color.

## 🛠️ Technologies & Concepts

| Category | Technologies / Concepts |
|---|---|
| Programming Language | C |
| Data Structures | Arrays, Stacks |
| User-Defined Data Types | Structures (`struct`), Enumerations (`enum`) |
| Algorithm | Fisher-Yates Shuffle |
| Core Concepts | Stack Operations, Memory Management, State Tracking, Time Complexity |

## 📚 Data Structures Used

| Data Structure | Purpose |
|---|---|
| Array | Stores tube contents, colors, and game states |
| Stack | Manages color transfers and undo history |

**Note:** Linked Lists and Queues were not used in this implementation because the puzzle uses fixed-size tubes and stack-based operations.

## 🎯 Game Controls

| Command | Action |
|---|---|
| Source and destination tube numbers | Transfers colors between tubes |
| `undo` | Restores the previous game state |
| `restart` | Starts a new randomized puzzle |

## 🧪 Testing

The project was tested with the following scenarios:

- Valid move
- Invalid move
- Win condition
- Undo operation
- Restart functionality
- Undo beyond the initial game state

All documented test cases passed.

## ⏱️ Time Complexity

The overall game loop has a time complexity of **O(M)**, where `M` represents the number of user moves during gameplay.

Most individual operations have constant-time complexity because the puzzle uses fixed-size arrays and a fixed number of tubes.

## ⚠️ Challenges & Limitations

### Challenges

- Ensuring that randomly generated puzzle configurations are solvable.
- Maintaining a user-friendly interface using text-based interaction.
- Managing memory for undo history and preventing memory leaks.

### Limitations

- The puzzle does not guarantee that every randomly generated initial configuration is solvable.
- The undo history is limited to 1000 states.
- The game uses a text-based console interface without graphical visualization.

## 🚀 Future Improvements

- Implement a solvability check for randomized puzzles.
- Introduce a graphical user interface.
- Improve the visual representation of colored liquids.
- Expand the puzzle with additional levels and difficulty settings.

## 👥 Team

**Group Name:** Under The Ocean  
**Course:** CSE207 – Data Structures  
**Section:** 06  
**Semester:** Spring 2025  
**Institution:** East West University

| Team Member | Contribution |
|---|---:|
| Fabiha Shajjad Synthia | 40% |
| Nurtaz Reza | 30% |
| Sadia Afrin | 30% |

---

*Developed as an academic project for the CSE207: Data Structures course, Spring 2025.*
