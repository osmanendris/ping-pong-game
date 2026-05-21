#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <windows.h>
using namespace std;

// Function to draw start screen
void drawStartScreen(int screenWidth, int screenHeight)
{
    cleardevice();

    int centerX = screenWidth / 2;
    int y = screenHeight / 2 - 120;

    // Title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    setcolor(YELLOW);
    outtextxy(centerX - 80, y, (char*)"PONG GAME");
    y += 70;

    // Level / Score target info
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(CYAN);
    outtextxy(centerX - 110, y, (char*)"FIRST TO 3 POINTS WINS");
    y += 40;

    // Ball speed info
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(LIGHTGRAY);
    outtextxy(centerX - 140, y, (char*)"Ball speed increases with each hit!");
    y += 50;

    // Menu options title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(centerX - 70, y, (char*)"OPTIONS:");
    y += 40;

    // Start option
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(centerX - 70, y, (char*)"[S] - START GAME");
    y += 40;

    // About option
    setcolor(CYAN);
    outtextxy(centerX - 70, y, (char*)"[A] - ABOUT / CONTROLS");
    y += 40;

    // Exit option
    setcolor(RED);
    outtextxy(centerX - 70, y, (char*)"[ESC] - EXIT");
}

// Function to show About/Controls screen
void showAboutScreen(int screenWidth, int screenHeight)
{
    cleardevice();  // Clear everything first

    int centerX = screenWidth / 2;
    int y = 20;

    // Title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(YELLOW);
    outtextxy(centerX - 100, y, (char*)"=== ABOUT & CONTROLS ===");
    y += 45;

    // Line separator
    setcolor(WHITE);
    line(50, y, screenWidth - 50, y);
    y += 25;

    // Game Information Section
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(CYAN);
    outtextxy(50, y, (char*)"GAME INFORMATION:");
    y += 28;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(70, y, (char*)"Pong is a classic arcade game that simulates table tennis.");
    y += 20;
    outtextxy(70, y, (char*)"First player to reach 3 points wins the game.");
    y += 20;
    outtextxy(70, y, (char*)"Ball speed increases with each successful hit.");
    y += 35;

    // Controls Section
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(CYAN);
    outtextxy(50, y, (char*)"CONTROLS:");
    y += 28;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(LIGHTGREEN);
    outtextxy(70, y, (char*)"LEFT PADDLE (Player 1):");
    y += 20;
    setcolor(WHITE);
    outtextxy(90, y, (char*)"W = Move UP");
    y += 18;
    outtextxy(90, y, (char*)"S = Move DOWN");
    y += 28;

    setcolor(LIGHTGREEN);
    outtextxy(70, y, (char*)"RIGHT PADDLE (Player 2):");
    y += 20;
    setcolor(WHITE);
    outtextxy(90, y, (char*)"UP ARROW = Move UP");
    y += 18;
    outtextxy(90, y, (char*)"DOWN ARROW = Move DOWN");
    y += 28;

    setcolor(LIGHTGREEN);
    outtextxy(70, y, (char*)"GAME CONTROLS:");
    y += 20;
    setcolor(WHITE);
    outtextxy(90, y, (char*)"M = Toggle AI / Two-Player Mode");
    y += 18;
    outtextxy(90, y, (char*)"ESC = Exit Game");
    y += 18;
    outtextxy(90, y, (char*)"S = Start Game (from Start Screen)");
    y += 18;
    outtextxy(90, y, (char*)"C = Continue (after Game Over)");
    y += 28;

    // Features Section
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(CYAN);
    outtextxy(50, y, (char*)"FEATURES:");
    y += 28;

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(70, y, (char*)"- Progressive ball speed (increases with each hit)");
    y += 20;
    outtextxy(70, y, (char*)"- Sound effects for wall hits, paddle hits, and scoring");
    y += 20;
    outtextxy(70, y, (char*)"- AI opponent with adaptive difficulty");
    y += 20;
    outtextxy(70, y, (char*)"- Two-Player mode support (play with a friend)");
    y += 20;
    outtextxy(70, y, (char*)"- Score tracking with win condition (first to 3)");
    y += 40;

    // Back instruction
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(centerX - 100, screenHeight - 40, (char*)"PRESS 'B' TO GO BACK");
}

// Function to show game over screen
bool showGameOverScreen(int screenWidth, int screenHeight, int score1, int score2)
{
    cleardevice();

    int centerX = screenWidth / 2;
    int y = screenHeight / 2 - 80;

    // Game over sound
    Beep(300, 200);
    Beep(200, 200);

    // Game Over Title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(RED);
    outtextxy(centerX - 70, y, (char*)"GAME OVER");
    y += 50;

    // Final Score
    char final[50];
    sprintf(final, "FINAL SCORE: %d   -   %d", score1, score2);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(centerX - 110, y, final);
    y += 40;

    // Level progress display
    char levelInfo[50];
    sprintf(levelInfo, "PLAYER 1: %d/3         PLAYER 2: %d/3", score1, score2);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(CYAN);
    outtextxy(centerX - 160, y, levelInfo);
    y += 35;

    // Target info
    char targetInfo[50];
    sprintf(targetInfo, "TARGET: FIRST TO 3 POINTS");
    setcolor(YELLOW);
    outtextxy(centerX - 130, y, targetInfo);
    y += 50;

    // Winner announcement
    if(score1 >= 3)
    {
        setcolor(GREEN);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(centerX - 80, y, (char*)"PLAYER 1 WINS!");
        Beep(1000, 300);
        Beep(1200, 300);
        Beep(1400, 300);
    }
    else if(score2 >= 3)
    {
        setcolor(GREEN);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(centerX - 80, y, (char*)"PLAYER 2 WINS!");
        Beep(1000, 300);
        Beep(1200, 300);
        Beep(1400, 300);
    }
    y += 60;

    // Continue option
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(YELLOW);
    outtextxy(centerX - 110, y, (char*)"PRESS 'C' TO CONTINUE");
    y += 35;

    // Exit option
    setcolor(LIGHTGRAY);
    outtextxy(centerX - 70, y, (char*)"ESC TO EXIT");

    while(true)
    {
        if(kbhit())
        {
            char key = getch();
            if(key == 'c' || key == 'C') return true;
            if(key == 27) return false;
        }
    }
}

int main()
{
    // Initialize graphics ONCE
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    srand(time(NULL));

    int screenWidth = getmaxx();
    int screenHeight = getmaxy();

    bool gameRunning = true;
    bool inGame = false;

    // Show start screen
    drawStartScreen(screenWidth, screenHeight);

    // Main menu loop
    while(gameRunning && !inGame)
    {
        if(kbhit())
        {
            char key = getch();

            if(key == 's' || key == 'S')
            {
                inGame = true;  // Exit menu loop, start game
                break;
            }
            else if(key == 'a' || key == 'A')
            {
                // Show about screen
                showAboutScreen(screenWidth, screenHeight);

                // Wait for 'B' to go back
                while(true)
                {
                    if(kbhit())
                    {
                        char backKey = getch();
                        if(backKey == 'b' || backKey == 'B')
                        {
                            // Redraw start screen
                            drawStartScreen(screenWidth, screenHeight);
                            break;
                        }
                        else if(backKey == 27)
                        {
                            closegraph();
                            return 0;
                        }
                    }
                }
            }
            else if(key == 27)
            {
                gameRunning = false;
                break;
            }
        }
    }

    // Game loop
    while(gameRunning && inGame)
    {
        // Game variables
        int paddle1X = 30;
        int paddle1Y = screenHeight / 2 - 60;
        int paddle2X = screenWidth - 45;
        int paddle2Y = screenHeight / 2 - 60;
        int paddleWidth = 15;
        int paddleHeight = 100;
        int paddle1Speed = 6;
        int paddle2Speed = 5;

        int ballX = screenWidth / 2;
        int ballY = screenHeight / 2;
        int ballRadius = 8;
        float ballSpeedX = 4.0f;
        float ballSpeedY = 3.0f;

        int hitCount = 0;
        int score1 = 0, score2 = 0;
        bool isPlayer2AI = true;

        // Game loop
        while(score1 < 3 && score2 < 3)
        {
            // INPUT
            if(kbhit())
            {
                char key = getch();
                if(key == 27)
                {
                    gameRunning = false;
                    inGame = false;
                    break;
                }
                if(key == 'w' && paddle1Y > 0) paddle1Y -= paddle1Speed;
                if(key == 's' && paddle1Y < screenHeight - paddleHeight) paddle1Y += paddle1Speed;
                if(!isPlayer2AI)
                {
                    if(key == 72 && paddle2Y > 0) paddle2Y -= 5;
                    if(key == 80 && paddle2Y < screenHeight - paddleHeight) paddle2Y += 5;
                }
                if(key == 'm') isPlayer2AI = !isPlayer2AI;
            }

            if(!gameRunning) break;

            // AI
            if(isPlayer2AI)
            {
                if(ballY < paddle2Y + paddleHeight/2 && paddle2Y > 0)
                    paddle2Y -= paddle2Speed;
                if(ballY > paddle2Y + paddleHeight/2 && paddle2Y < screenHeight - paddleHeight)
                    paddle2Y += paddle2Speed;
            }

            // Ball movement
            ballX += (int)ballSpeedX;
            ballY += (int)ballSpeedY;

            // Wall collision
            if(ballY - ballRadius <= 0)
            {
                ballY = ballRadius;
                ballSpeedY = -ballSpeedY;
                Beep(400, 30);
            }
            if(ballY + ballRadius >= screenHeight)
            {
                ballY = screenHeight - ballRadius;
                ballSpeedY = -ballSpeedY;
                Beep(400, 30);
            }

            // Paddle 1 collision
            if(ballX - ballRadius <= paddle1X + paddleWidth &&
               ballX + ballRadius >= paddle1X &&
               ballY + ballRadius >= paddle1Y &&
               ballY - ballRadius <= paddle1Y + paddleHeight)
            {
                ballX = paddle1X + paddleWidth + ballRadius;
                ballSpeedX = -ballSpeedX;
                Beep(800, 40);
                hitCount++;
                if(ballSpeedX > 0) ballSpeedX += 0.3f;
                else ballSpeedX -= 0.3f;
                if(ballSpeedX > 10) ballSpeedX = 10;
                if(ballSpeedX < -10) ballSpeedX = -10;
            }

            // Paddle 2 collision
            if(ballX + ballRadius >= paddle2X &&
               ballX - ballRadius <= paddle2X + paddleWidth &&
               ballY + ballRadius >= paddle2Y &&
               ballY - ballRadius <= paddle2Y + paddleHeight)
            {
                ballX = paddle2X - ballRadius;
                ballSpeedX = -ballSpeedX;
                Beep(800, 40);
                hitCount++;
                if(ballSpeedX > 0) ballSpeedX += 0.3f;
                else ballSpeedX -= 0.3f;
                if(ballSpeedX > 10) ballSpeedX = 10;
                if(ballSpeedX < -10) ballSpeedX = -10;
            }

            // Scoring
            if(ballX + ballRadius >= screenWidth)
            {
                score1++;
                Beep(1200, 100);
                ballX = screenWidth/2;
                ballY = screenHeight/2;
                ballSpeedX = 4;
                ballSpeedY = 3;
                hitCount = 0;
                delay(400);
            }

            if(ballX - ballRadius <= 0)
            {
                score2++;
                Beep(1200, 100);
                ballX = screenWidth/2;
                ballY = screenHeight/2;
                ballSpeedX = -4;
                ballSpeedY = 3;
                hitCount = 0;
                delay(400);
            }

            // DRAW EVERYTHING
            cleardevice();

            // Borders
            setcolor(WHITE);
            rectangle(1, 1, screenWidth-1, screenHeight-1);

            // Center line
            for(int i = 0; i < screenHeight; i += 20)
                line(screenWidth/2, i, screenWidth/2, i+10);

            // Paddles
            setfillstyle(SOLID_FILL, WHITE);
            bar(paddle1X, paddle1Y, paddle1X+paddleWidth, paddle1Y+paddleHeight);
            bar(paddle2X, paddle2Y, paddle2X+paddleWidth, paddle2Y+paddleHeight);

            // Ball
            fillellipse(ballX, ballY, ballRadius, ballRadius);

            // Scores
            char txt[30];
            sprintf(txt, "%d     -     %d", score1, score2);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
            outtextxy(screenWidth/2 - 70, 20, txt);

            // Target display
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
            setcolor(YELLOW);
            outtextxy(screenWidth/2 - 70, 70, (char*)"FIRST TO 3 POINTS");

            // Score progress
            char levelText[50];
            sprintf(levelText, "P1: %d/3        P2: %d/3", score1, score2);
            setcolor(CYAN);
            outtextxy(screenWidth/2 - 80, 90, levelText);

            // Game info
            sprintf(txt, "HITS: %d    SPEED: %.0f", hitCount, abs(ballSpeedX));
            setcolor(LIGHTGREEN);
            outtextxy(screenWidth/2 - 80, screenHeight - 50, txt);

            // Mode display
            char modeText[30];
            sprintf(modeText, "MODE: %s", isPlayer2AI ? "AI" : "2 PLAYER");
            setcolor(LIGHTMAGENTA);
            outtextxy(screenWidth/2 - 60, screenHeight - 35, modeText);

            // Controls hint
            setcolor(LIGHTGRAY);
            outtextxy(10, screenHeight - 25, (char*)"W/S");
            outtextxy(screenWidth - 80, screenHeight - 25, (char*)"M");
            outtextxy(screenWidth - 130, screenHeight - 25, (char*)"ESC");

            delay(16);
        }

        if(!gameRunning) break;

        // Show game over screen and ask to continue
        if(!showGameOverScreen(screenWidth, screenHeight, score1, score2))
        {
            gameRunning = false;
        }
        else
        {
            // Continue playing - redraw start screen
            drawStartScreen(screenWidth, screenHeight);

            // Wait for 'S' to start again
            while(true)
            {
                if(kbhit())
                {
                    char key = getch();
                    if(key == 's' || key == 'S')
                    {
                        break;  // Start new game
                    }
                    else if(key == 'a' || key == 'A')
                    {
                        showAboutScreen(screenWidth, screenHeight);
                        while(true)
                        {
                            if(kbhit())
                            {
                                char backKey = getch();
                                if(backKey == 'b' || backKey == 'B')
                                {
                                    drawStartScreen(screenWidth, screenHeight);
                                    break;
                                }
                            }
                        }
                    }
                    else if(key == 27)
                    {
                        gameRunning = false;
                        break;
                    }
                }
            }
        }
    }

    closegraph();
    return 0;
}
