
# 🕵️‍♂️ Minesweeper Game in C 💣

This is a **text-based Minesweeper game** implemented in C. Test your logic and luck as you uncover cells while avoiding hidden mines in a 3x3 grid. The game is simple, engaging, and demonstrates core programming concepts like arrays, random number generation, and input validation.

## ✨ Features
- 🎲 **Randomized Mines Placement:** Mines are placed in unique positions on every run using a random number generator.
- 🧠 **Custom Logic:** Neighboring mines are calculated dynamically to update the grid hints.
- ❌ **Win or Lose:** The game ends if a mine is uncovered or all safe cells are revealed.
- 🎮 **Interactive Gameplay:** Players input cell locations (1–9) to uncover them step by step.

## 🛠️ How It Works
1. A 3x3 grid is initialized, with mines placed in random positions.
2. The game calculates the number of neighboring mines for each cell.
3. The player uncovers cells by entering a location (1–9).
4. The game provides visual feedback for uncovered cells:
   - Numbers indicate the count of adjacent mines.
   - `0` indicates no neighboring mines.
5. The game ends when:
   - A mine is uncovered (💥 you lose).
   - All non-mine cells are uncovered (🏆 you win).

## ⚙️ Setup and Compilation
1. Clone the repository:
   git clone https://github.com/bikesh19/Minesweeper
   
2. Compile the program using `gcc`:
   gcc -o minesweeper minesweeper.c -lm
   
4. Run the program:
   ./minesweeper

## 📚 Key Concepts Demonstrated
- 🎲 **Random Number Generation:** `rand()` is used for dynamic mine placement.
- 🔍 **Logical Conditions:** To calculate neighboring mines and validate input.
- 🗂️ **2D Arrays:** For managing the grid and its state.
- 🖥️ **User Interaction:** Accepts and processes player input.

## 🚀 Future Enhancements
- 📏 Expand grid size and difficulty levels.
- 🎨 Add a graphical interface for better visualization.
- ⏱️ Include a timer to challenge players further.

---

Feel free to contribute by submitting issues or pull requests to enhance this project. 😊
