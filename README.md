# Tic-Tac-Toe: Dual-Engine Edition 🎮

A cross-platform software engineering project showcasing modular system design. This repository features two independent versions of Tic-Tac-Toe engineered using identical core structural logic but deployed across entirely different environments.

## 📁 Repository Architecture
```text
Tic-Tac-Toe/
├── cpp-version/          # Native C++ core engine with Raylib GUI
│   ├── main.cpp          # App entry point & Raylib window lifecycle tracking
│   ├── board.h / .cpp    # Matrix board layout & cell evaluation constraints
│   ├── game.h / .cpp     # Game loop runner & active player switching 
│   └── player.h / .cpp   # Parameter initialization for player tokens
└── web-version/          # Dynamic web deployment
    └── index.html        # Responsive frontend built with HTML5, CSS3 Grid, & JavaScript

🛠️ Deep Tech Stacks
1. Object-Oriented C++ & Raylib Graphic Engine
Decoupled System Architecture: The application splits its responsibilities strictly across decoupled header (.h) and implementation (.cpp) files to maintain loose coupling.

Vector Memory Matrices: Replaced raw arrays with dynamic standard template library vectors (std::vector<char>) to track game board elements safely.

Real-time Pixel Translation: Integrates the Raylib library to run a continuous 60 FPS graphics loop, calculating mouse click coordinates and translating raw screen data into grid matrix positions.

2. Scalable Web Frontend
Dynamic Grid Sizing: Ported core validation concepts into a JavaScript engine capable of scaling beyond standard sizes up to 4x4 or 5x5 boards dynamically.

Responsive Visuals: Employs advanced HTML5 styling with custom CSS grids, animations, and backdrop-filter glassmorphism overlays for the game UI.

🚀 How to Run the Code
C++ Graphical Version
Ensure you have a C++ compiler installed (like MinGW) and the Raylib development library configured.

Compile the source files:

Bash
g++ main.cpp board.cpp game.cpp player.cpp -lraylib -lopengl32 -lgdi32 -lwinmm -o TicTacToe
Run the executable:

Bash
./TicTacToe
Web Deluxe Version
Simply open the index.html file inside the web-version/ folder with any modern web browser to play instantly!    