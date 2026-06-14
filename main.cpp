#include <iostream>
#include <vector>
#include <string>
#include "board.h"
#include "game.h"
#include "player.h"
#include "raylib.h"

using namespace std;

int main() {
    char replayChoice = 'y';

    cout << "\n\n----- Game starting ----- \n\n" << endl;
    
    // Gather users information via console
    string name1, name2;
    char symbol1, symbol2;

    cout << "    PLAYER 1     " << endl;
    cout << "Name : ";
    cin >> name1;
    cout << "Symbol(O/X) : ";
    cin >> symbol1;

    cout << "    PLAYER 2     " << endl;
    cout << "Name : ";
    cin >> name2;
    cout << "Symbol(O/X) : ";
    cin >> symbol2;

    while (symbol2 == symbol1) {
        cout << "Caution!!\nThis symbol is already in use you cannot use it.\nKindly use other: ";
        cin >> symbol2;   
    }

    // Rematch / replay loop
    while (replayChoice == 'y' || replayChoice == 'Y') {
        // Instantiate your core game objects to keep your class architecture intact
        Player p1(name1, symbol1);
        Player p2(name2, symbol2);
        Game currentMatch(p1, p2); 

        // Spin up a fresh board instance for this graphical window match
        Board myBoard; 
        char currentSymbol = symbol1;
        string currentName = name1;
        bool gameOver = false;
        string statusText = currentName + "'s Turn (" + currentSymbol + ")";

        // Initialize GUI Window (600x600 pixels allocation)
        const int screenWidth = 600;
        const int screenHeight = 600;
        InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe - Graphical Edition");
        SetTargetFPS(60);

        // --- GRAPHICAL INTERACTIVE ENGINE LOOP ---
        while (!WindowShouldClose()) {
            
            // Handle Player Grid Clicks
            if (!gameOver && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Vector2 mousePos = GetMousePosition();
                
                // Translate raw coordinate pixels into 0, 1, or 2 index regions
                int col = mousePos.x / 200;
                int row = mousePos.y / 200;
                
                // Translate grid region directly into your 1-9 system
                int position = (row * 3 + col) + 1;
                int index = position - 1;

                // Validate if selection space is clear using your methods
                if (index >= 0 && index < 9 && myBoard.isSpaceFree(index)) {
                    myBoard.updateSpace(position, currentSymbol);

                    // Compute Game States using your backend logic functions
                    if (myBoard.checkWin()) {
                        statusText = currentName + " WINS!";
                        gameOver = true;
                    } else if (myBoard.isBoardFull()) {
                        statusText = "It's a Draw!";
                        gameOver = true;
                    } else {
                        // Cycle turns back and forth dynamically based on choices
                        if (currentSymbol == symbol1) {
                            currentSymbol = symbol2;
                            currentName = name2;
                        } else {
                            currentSymbol = symbol1;
                            currentName = name1;
                        }
                        statusText = currentName + "'s Turn (" + currentSymbol + ")";
                    }
                }
            }

            // --- RENDER VISUAL FRONTEND ---
            BeginDrawing();
            ClearBackground(RAYWHITE);

            // Draw clean box segments for the 3x3 play space grid
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    DrawRectangleLines(j * 200, i * 200, 200, 200, DARKGRAY);
                }
            }

            // Read live values straight out of your tracking array vector
            for (int i = 0; i < 9; i++) {
                int row = i / 3;
                int col = i % 3;
                int centerX = col * 200 + 100;
                int centerY = row * 200 + 100;

                // Dynamically matches whatever structural symbol player 1 picked
                if (myBoard.grid[i] == symbol1) {
                    DrawLine(centerX - 45, centerY - 45, centerX + 45, centerY + 45, BLUE);
                    DrawLine(centerX + 45, centerY - 45, centerX - 45, centerY + 45, BLUE);
                } 
                // Dynamically matches whatever structural symbol player 2 picked
                else if (myBoard.grid[i] == symbol2) {
                    DrawCircleLines(centerX, centerY, 50, RED);
                }
            }

            // Dark premium banner overlay printed on match completion 
            if (gameOver) {
                DrawRectangle(0, 240, 600, 120, Fade(BLACK, 0.85f));
                DrawText(statusText.c_str(), 300 - MeasureText(statusText.c_str(), 32) / 2, 285, 32, GREEN);
            }

            EndDrawing();
        }

        // Close graphics engine window mapping cleanly
        CloseWindow();

        // System returns directly back here to ask for a console rematch
        cout << "\nMatch window closed. Would you like to play another match? (y/n): ";
        cin >> replayChoice;
        cout << endl;
    }

    cout << "Thanks for playing! Have a great day." << endl;
    return 0;
}


