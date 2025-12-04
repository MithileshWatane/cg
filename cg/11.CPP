#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dos.h>

#define MAX_OBS 3
#define GAP_HEIGHT 120
#define OBSTACLE_WIDTH 40
#define OBSTACLE_SPACING 250
#define INITIAL_SPEED 3
#define SCORE_TO_SPEED_UP 5

#define HELO_X 120
#define HELO_W 40
#define HELO_H 20
#define GRAVITY 1
#define THRUST -8

typedef enum { MENU, PLAYING, GAME_OVER } GameState;

typedef struct {
    int x;
    int gapY;
    int active;
} Obstacle;

void drawHelicopter(int x, int y, int frame) {
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(x - HELO_W / 2, y - HELO_H / 2, x + HELO_W / 2, y + HELO_H / 2);
    setcolor(WHITE);
    if (frame % 2 == 0) {
        line(x - HELO_W, y - HELO_H / 2, x + HELO_W, y - HELO_H / 2);
        line(x, y - HELO_H / 2, x, y - HELO_H / 2 - 5);
    } else {
        line(x - HELO_W + 5, y - HELO_H / 2 - 2, x + HELO_W - 5, y - HELO_H / 2 + 2);
        line(x, y - HELO_H / 2, x, y - HELO_H / 2 - 5);
    }
    line(x - HELO_W / 2, y, x - HELO_W, y - 5);
    line(x - HELO_W / 2, y, x - HELO_W, y + 5);
    setfillstyle(SOLID_FILL, CYAN);
    fillellipse(x + HELO_W / 4, y, 8, 8);
}

void drawObstacle(Obstacle* o, int maxy) {
    setfillstyle(HATCH_FILL, RED);
    bar(o->x, 0, o->x + OBSTACLE_WIDTH, o->gapY);
    bar(o->x, o->gapY + GAP_HEIGHT, o->x + OBSTACLE_WIDTH, maxy);
    setcolor(WHITE);
    rectangle(o->x, 0, o->x + OBSTACLE_WIDTH, o->gapY);
    rectangle(o->x, o->gapY + GAP_HEIGHT, o->x + OBSTACLE_WIDTH, maxy);
}

void drawHUD(int score, int high, int speed) {
    char buf[100];
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    sprintf(buf, "Score: %d  High: %d  Speed: %d", score, high, speed);
    outtextxy(10, 10, buf);
}

int checkCollision(Obstacle* o, int heloY) {
    int helotop = heloY - HELO_H / 2;
    int helobottom = heloY + HELO_H / 2;
    if (o->x < HELO_X + HELO_W / 2 && o->x + OBSTACLE_WIDTH > HELO_X - HELO_W / 2) {
        if (helotop < o->gapY || helobottom > o->gapY + GAP_HEIGHT)
            return 1;
    }
    return 0;
}

void initializeGame(Obstacle obs[], int* heloY, int* velocity, int* score, int* speed, int maxx, int maxy) {
    *heloY = maxy / 2;
    *velocity = 0;
    *score = 0;
    *speed = INITIAL_SPEED;
    for (int i = 0; i < MAX_OBS; i++) {
        obs[i].x = maxx + i * OBSTACLE_SPACING;
        obs[i].gapY = 60 + rand() % (maxy - GAP_HEIGHT - 120);
        obs[i].active = 1;
    }
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int maxx = getmaxx();
    int maxy = getmaxy();
    int heloY, velocity, speed, score = 0, high = 0;
    int rotorFrame = 0;
    char buf[100];
    Obstacle obs[MAX_OBS];
    GameState state = MENU;

    srand((unsigned)time(NULL));

    while (1) {
        cleardevice();

        if (state == MENU) {
            setcolor(YELLOW);
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
            outtextxy(maxx / 2 - 150, maxy / 2 - 50, "Copter Game");
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            outtextxy(maxx / 2 - 180, maxy / 2 + 20, "Press SPACE to Start");
            outtextxy(maxx / 2 - 150, maxy / 2 + 50, "Press ESC to Exit");

            if (kbhit()) {
                char ch = getch();
                if (ch == ' ') {
                    state = PLAYING;
                    initializeGame(obs, &heloY, &velocity, &score, &speed, maxx, maxy);
                } else if (ch == 27) break;
            }
        } 
        else if (state == PLAYING) {
            if (kbhit()) {
                char ch = getch();
                if (ch == ' ') {
                    velocity = THRUST;
                    sound(800);
                    delay(10);
                    nosound();
                } else if (ch == 27) break;
            }

            velocity += GRAVITY;
            heloY += velocity;
            rotorFrame++;

            if (heloY < HELO_H / 2) { heloY = HELO_H / 2; velocity = 0; }
            if (heloY > maxy - HELO_H / 2) { heloY = maxy - HELO_H / 2; velocity = 0; }

            for (int i = 0; i < MAX_OBS; i++) {
                obs[i].x -= speed;
                if (obs[i].x + OBSTACLE_WIDTH < 0) {
                    obs[i].x = maxx + OBSTACLE_SPACING / 2;
                    obs[i].gapY = 60 + rand() % (maxy - GAP_HEIGHT - 120);
                    obs[i].active = 1;
                }
                if (obs[i].active && obs[i].x + OBSTACLE_WIDTH < HELO_X - HELO_W / 2) {
                    score++;
                    obs[i].active = 0;
                    if (score > high) high = score;
                    if (score % SCORE_TO_SPEED_UP == 0) speed++;
                }
            }

	    for (int ij = 0; ij < MAX_OBS; ij++) drawObstacle(&obs[ij], maxy);
            drawHelicopter(HELO_X, heloY, rotorFrame);
            drawHUD(score, high, speed);
	    rectangle(0, 0, maxx - 1, maxy - 1);

	    for (int ik = 0; ik < MAX_OBS; ik++) {
		if (checkCollision(&obs[ik], heloY)) {
                    state = GAME_OVER;
                    sound(150);
                    delay(300);
                    nosound();
                }
            }
        } 
        else if (state == GAME_OVER) {
            setcolor(RED);
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
            outtextxy(maxx / 2 - 120, maxy / 2 - 50, "GAME OVER");
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            sprintf(buf, "Your Score: %d", score);
            outtextxy(maxx / 2 - 100, maxy / 2 + 10, buf);
            outtextxy(maxx / 2 - 200, maxy / 2 + 50, "Press 'R' to Restart");

            if (kbhit()) {
                char ch = getch();
                if (ch == 'r' || ch == 'R') {
                    state = PLAYING;
                    initializeGame(obs, &heloY, &velocity, &score, &speed, maxx, maxy);
                } else if (ch == 27) break;
            }
        }

        delay(30);
    }

    closegraph();
}
