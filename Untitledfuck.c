#include <stdio.h>
#include <unistd.h> 
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <windows.h>
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
void map_1();
COORD moveDirection(COORD position, int dx, int dy) {
    position.X += dx;
    position.Y += dy;
    return position;
}
BOOL keyPressed(int key) {
    return GetAsyncKeyState(key);
}
int main(){
    map_1();
}
void map_1(){
    char map[31][121] = { 0 };
    COORD player1_pos = { 16, 15 };
    COORD player2_pos = { 103, 15 };
    COORD player1_bullet = { -1, -1 };
    COORD player2_bullet = { -1, -1 };
    COORD player1_lastMove = { 0, 0 };
    COORD player2_lastMove = { 0, 0 };
    COORD portal1 = { 14,26 };
    COORD portal2 = { 105 , 26 };
    BOOL  MovingBullet1 = FALSE;
    BOOL  MovingBullet2 = FALSE;
    COORD bulletDirection1 = { 0, 0 };
    COORD bulletDirection2 = { 0, 0 };
     DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int a = 1;
    int health_1 = 3;
    int health_2 = 3;
    int didas = 0 ;
    while (health_1 != 0 && health_2 != 0) {
        system("cls");
        portal1 = (COORD){ 14,26 };
        portal2 = (COORD){ 105,26 };
        if (keyPressed(PLAYER1_UP)) {
                didas = 1 ;
            COORD nextPos = moveDirection(player1_pos, 0, -1);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player1_pos = nextPos;
                player1_lastMove = (COORD){ 0, -1 };

            }
        }
        if (keyPressed(PLAYER1_DOWN)) {
                didas = 1 ;
            COORD nextPos = moveDirection(player1_pos, 0, 1);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player1_pos = nextPos;
                player1_lastMove = (COORD){ 0, 1 };

            }
        }
        if (keyPressed(PLAYER1_LEFT)) {
                 didas = 1 ;
            COORD nextPos = moveDirection(player1_pos, -1, 0);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player1_pos = nextPos;
                player1_lastMove = (COORD){ -1, 0 };

            }
        }
        if (keyPressed(PLAYER1_RIGHT)) {
                 didas = 1 ;
            COORD nextPos = moveDirection(player1_pos, 1, 0);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player1_pos = nextPos;
                player1_lastMove = (COORD){ 1, 0 };

            }
        }
        if (keyPressed(PLAYER1_SHOOT)) {
                didas = 1 ;
            MovingBullet1 = TRUE;
            bulletDirection1 = player1_lastMove;
            player1_bullet = player1_pos;

        }
        if (keyPressed(PLAYER2_UP)) {
                didas = 1 ;
            COORD nextPos = moveDirection(player2_pos, 0, -1);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player2_pos = nextPos;
                player2_lastMove = (COORD){ 0, -1 };

            }
        }
        if (keyPressed(PLAYER2_DOWN)) {
                didas = 1 ;
            COORD nextPos = moveDirection(player2_pos, 0, 1);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player2_pos = nextPos;
                player2_lastMove = (COORD){ 0, 1 };

            }
        }
        if (keyPressed(PLAYER2_LEFT)) {
                didas = 1 ;
            COORD nextPos = moveDirection(player2_pos, -1, 0);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player2_pos = nextPos;
                player2_lastMove = (COORD){ -1, 0 };

            }
        }
        if (keyPressed(PLAYER2_RIGHT)) {
                didas = 1 ;
            COORD nextPos = moveDirection(player2_pos, 1, 0);
            char nextCell = map[nextPos.Y][nextPos.X];
            if (nextCell != 186 && nextCell != 219) {
                player2_pos = nextPos;
                player2_lastMove = (COORD){ 1, 0 };
            }
        }
        if (keyPressed(PLAYER2_SHOOT)) {
            didas = 1 ;
            MovingBullet2 = TRUE;
            bulletDirection2 = player2_lastMove;
            player2_bullet = player2_pos;
        }
        if (map[player1_pos.Y][player1_pos.X] == 'ì') {
            didas = 1 ;
            player1_pos = (COORD){ 16, 15 };
            player1_lastMove = (COORD){ 0, 0 };
            player1_bullet = (COORD){ -1, -1 };
            health_1--;
        }
        if (map[player2_pos.Y][player2_pos.X] == 'ì') {
            didas = 1 ;
            player2_pos = (COORD){ 103, 15 };
            player2_lastMove = (COORD){ 0, 0 };
            player2_bullet = (COORD){ -1, -1 };
            health_2--;
        }
        if (player1_pos.X == portal1.X && player1_pos.Y == portal1.Y) {
            didas = 1 ;
            player1_pos = portal2;
        }
        else if (player1_pos.X == portal2.X && player1_pos.Y == portal2.Y) {
            didas = 1 ;
            player1_pos = portal1;
        }
        if (player2_pos.X == portal2.X && player2_pos.Y == portal2.Y) {
            didas = 1 ;
            player2_pos = portal1;
        }
        else if (player2_pos.X == portal1.X && player2_pos.Y == portal1.Y) {
            didas = 1 ;
            player2_pos = portal2;
        }
        if (map[player1_pos.Y][player1_pos.X] == 186) {
            didas = 1 ;
            health_1 += 5;
            map[player1_pos.Y][player1_pos.X] == ' ';
            a = 0;
        }
        if (map[player2_pos.Y][player2_pos.X] == 186) {
            didas = 1 ;
            health_2 += 5;
            map[player2_pos.Y][player2_pos.X] == ' ';
            a = 0;
        }
        if (MovingBullet1) {
                didas = 1 ;
            player1_bullet = moveDirection(player1_bullet, bulletDirection1.X, bulletDirection1.Y);
        }
        if (MovingBullet2) {
            didas = 1 ;
            player2_bullet = moveDirection(player2_bullet, bulletDirection2.X, bulletDirection2.Y);
        }
        if (MovingBullet1) {
            didas = 1 ;
            if (map[player1_bullet.Y][player1_bullet.X] != ' ') {
                if (map[player1_bullet.Y][player1_bullet.X] == 219) {
                    bulletDirection1 = (COORD){ -bulletDirection1.X, -bulletDirection1.Y };
                }
                else if (map[player1_bullet.Y][player1_bullet.X] == '1') {
                    didas = 1 ;
                    health_1--;
                    player1_bullet = (COORD){ -1, -1 };
                }
                else if (map[player1_bullet.Y][player1_bullet.X] == '2') {
                    didas = 1 ;
                    health_2--;
                    player1_bullet = (COORD){ -1, -1 };
                }
                else
                {   didas = 1 ;
                    MovingBullet1 = FALSE;
                    player1_bullet = (COORD){ -1, -1 };
                }

            }
        }
            if (MovingBullet2) {
                    didas = 1 ;
                if (map[player2_bullet.Y][player2_bullet.X] != ' ') {
                    didas = 1 ;
                    if (map[player2_bullet.Y][player2_bullet.X] == 219) {
                        didas = 1 ;
                        // Bullet hit 'º', reverse its direction
                        bulletDirection2 = (COORD){ -bulletDirection2.X, -bulletDirection2.Y };
                    }
                    else if (map[player2_bullet.Y][player2_bullet.X] == '1') {
                        didas = 1 ;
                        health_1--;
                        player2_bullet = (COORD){ -1, -1 };
                    }
                    else if (map[player2_bullet.Y][player2_bullet.X] == '2') {
                        didas = 1 ;
                        health_2--;
                        player2_bullet = (COORD){ -1, -1 };
                    }
                    else
                    {   didas = 1 ;
                        MovingBullet2 = FALSE;
                        player2_bullet = (COORD){ -1, -1 };
                    }
                }
            }
            for (int i = 0; i < 31; i++)
            {
                for (int j = 0; j < 121; j++)
                {
                    if (i == 0 || j == 0 || i == 30 || j == 120 || (i <= 22 && 16 <= i && j == 60) || (i <= 13 && 8 <= i && j == 60) || (i == 9 && j <= 76 && 67 <= j) || (i == 21 && j <= 52 && 43 <= j) || (j == 83 && i <= 6 && 3 <= i)
                        || (j == 36 && i <= 27 && 24 <= i) || (j == 36 && i <= 6 && 3 <= i) || (j == 83 && i <= 27 && 24 <= i) || (i <= 23 && 7 <= i && j == 97) || (i <= 23 && 7 <= i && j == 22) || (j <= 103 && 98 <= j && i == 7) || (j <= 103 && 98 <= j && i == 23) || (j <= 21 && 16 <= j && i == 7) || (j <= 21 && 16 <= j && i == 23)) {
                        map[i][j] = 219;
            didas = 1 ;

                    }
                    else if ((i == 14 && j == 60) || (i == 15 && j == 60) || (j == 82 && i <= 27 && 24 <= i) || (j == 37 && i <= 6 && 3 <= i) || (i <= 11 && 8 <= i && j == 23) || (i <= 22 && 19 <= i && j == 23) || (i <= 11 && 8 <= i && j == 96) || (i <= 22 && 19 <= i && j == 96)) {
                        map[i][j] = 186;
                        didas = 1 ;

                    }
                    else if (i == 5 && j == 60) {
                            didas = 1 ;
                        if (a == 1) {
                            map[i][j] = 3;
                        }
                        else {
                            map[i][j] = ' ';

                        }
                    }
                    else if ((i == 6 && j == 90) || (i == 24 && j == 29)) {
                            didas = 1 ;
                        map[i][j] = 236;
                    }
                    else if ((i == 26 && j == 105) || (i == 26 && j == 14)) {
                        didas = 1 ;
                        map[i][j] = 15;
                    }
                    else {  didas = 1 ;
                        map[i][j] = ' ';

                    }
                }
            }
            map[player1_pos.Y][player1_pos.X] = '1';
            map[player2_pos.Y][player2_pos.X] = '2';
            if (player1_bullet.X < 121 && player1_bullet.X != -1) {
                    didas = 1 ;
                    map[player1_bullet.Y][player1_bullet.X] = '.';
            }
            if (player2_bullet.X < 121 && player2_bullet.X != -1) {
                    didas = 1 ;
                    map[player2_bullet.Y][player2_bullet.X] = '.';
            }

            if (didas == 1) {
                for (int y = 0; y < 31; y++) {
                    COORD place;
                    place.X = 0;
                    place.Y = y;
                    WriteConsoleOutputCharacterA(hStdout, map[y], 121, place, &bytes_written);

                }
            }
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer 1 Health: %d", health_1);
        printf("\t\t\t\tPlayer 2 Health: %d\n", health_2);
       Sleep(45);
    }
    system("cls");
}    