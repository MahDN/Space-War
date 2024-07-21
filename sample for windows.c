#include <windows.h>
#include <stdio.h>

#define PLAYER1_UP 'W'
#define PLAYER1_DOWN 'S'
#define PLAYER1_LEFT 'A'
#define PLAYER1_RIGHT 'D'
#define PLAYER1_SHOOT 'C'

#define PLAYER2_UP 'I'
#define PLAYER2_DOWN 'K'
#define PLAYER2_LEFT 'J'
#define PLAYER2_RIGHT 'L'
#define PLAYER2_SHOOT 'N'

//COORD structure represents the coordinates of a character cell in the console screen buffer
COORD moveDirection(COORD position, int dx, int dy) {
    position.X += dx;
    position.Y += dy;
    return position;
}

BOOL keyPressed(int key) {
    //This function returns a short integer that indicates whether a particular key is pressed or not.
    return GetAsyncKeyState(key);
    //returns a non-zero value if the key is currently pressed. If not, it will return 0.
}

int main() {
    char map[10][40] = { 0 };
    COORD player1_pos = { 10, 5 };
    COORD player2_pos = { 20, 5 };
    COORD player1_bullet = { -1, -1 };
    COORD player2_bullet = { -1, -1 };

    //DWORD stands for “Double Word” and is used to represent 32-bit unsigned integers
    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    while (1) {
        // Clear screen
        system("cls");

        // Input handling for Player 1
        if (keyPressed(PLAYER1_UP)) player1_pos = moveDirection(player1_pos, 0, -1);
        if (keyPressed(PLAYER1_DOWN)) player1_pos = moveDirection(player1_pos, 0, 1);
        if (keyPressed(PLAYER1_LEFT)) player1_pos = moveDirection(player1_pos, -1, 0);
        if (keyPressed(PLAYER1_RIGHT)) player1_pos = moveDirection(player1_pos, 1, 0);
        if (keyPressed(PLAYER1_SHOOT)) player1_bullet = player1_pos;

        // Input handling for Player 2
        if (keyPressed(PLAYER2_UP)) player2_pos = moveDirection(player2_pos, 0, -1);
        if (keyPressed(PLAYER2_DOWN)) player2_pos = moveDirection(player2_pos, 0, 1);
        if (keyPressed(PLAYER2_LEFT)) player2_pos = moveDirection(player2_pos, -1, 0);
        if (keyPressed(PLAYER2_RIGHT)) player2_pos = moveDirection(player2_pos, 1, 0);
        if (keyPressed(PLAYER2_SHOOT)) player2_bullet = player2_pos;

        // Update bullet positions
        if (player1_bullet.X != -1) player1_bullet.X++;
        if (player2_bullet.X != -1) player2_bullet.X--;

        // Draw map
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 40; x++) {
                map[y][x] = ' ';
            }
        }

        // Draw players
        map[player1_pos.Y][player1_pos.X] = '1';
        map[player2_pos.Y][player2_pos.X] = '2';

        // Draw bullets
        if (player1_bullet.X < 40 && player1_bullet.X != -1) map[player1_bullet.Y][player1_bullet.X] = '.';
        if (player2_bullet.X < 40 && player2_bullet.X != -1) map[player2_bullet.Y][player2_bullet.X] = '.';

        // Output to console
        for (int y = 0; y < 10; y++) {
            COORD place;
            place.X = 0;
            place.Y = y;
            WriteConsoleOutputCharacterA(hStdout, map[y], 40, place, &bytes_written);
            //WriteConsoleOutputCharacterA is a function in the Windows Console API that writes a string of characters to a console screen buffer at a specified location.
            //The first parameter identifies where to write the characters
            //The second parameter is a C-style string or an array of characters that you want to write to the screen buffer.
            //The third parameter specifies how many characters from the string should be written to the screen buffer.
            //The fourth parameter specifies the coordinates (given as a COORD structure) of the first cell in the console screen buffer where writing will begin.
            //The fifth parameter is a pointer to a variable that receives the number of characters actually written to the console screen buffer.

        }

        // Game tick delay
        Sleep(100);
    }

    return 0;
}
