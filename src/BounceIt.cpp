#include<iostream>
#include<raylib.h>
using namespace std;

int Player_1 = 0;
int Player_2 = 0;

bool gameOver = false;

struct Ball{
public:
    const int width = 1280;
    const int height = 720;
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw(){
        DrawCircle(x, y, radius, YELLOW);
    }

    void Change(){
        x = x + speed_x * 3;
        y = y + speed_y * 3;

        if(y + radius >= GetScreenHeight() || y - radius <= 0){
            speed_y = speed_y * -1;
        }
        if(x + radius >= GetScreenWidth()){
            x = width / 2;
            
            Player_2++;
        }
        if(x + radius <= 0){
            x = width / 2;
            y = height / 2;
            Player_1++;
        }
    }
};

struct Paddle1{
protected:
    void Limiter(){
        if(y >= GetScreenHeight() - height){
            y = GetScreenHeight() - height;
        }
        if(y <= 0){
            y = 0;
        }
    }
public:
    float x, y;
    float width, height;
    int speed;

    void Draw(){
        DrawRectangle(x, y, width, height, BROWN);
    }

    void Change(){

        if(IsKeyDown(KEY_UP)){
            y = y - speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            y = y + speed;
        }

        Limiter();  
    }

};

struct Paddle2 : public Paddle1{
public:
    void Draw(){
        DrawRectangle(x, y, width, height, BROWN);
    }

    void Change(){

        if(IsKeyDown(KEY_W)){
            y = y - speed;
        }
        if(IsKeyDown(KEY_S)){
            y = y + speed;
        }

        Limiter();  
    }
};

int main() {
    Ball ball;
    Paddle1 p1;
    Paddle2 p2;

    const int s_width = 1280;
    const int s_height = 720;

    InitWindow(s_width, s_height, "BounceIt v.0");
    SetTargetFPS(120);

    ball.x = s_width / 2;
    ball.y = s_height / 2;
    ball.radius = 15;
    ball.speed_x = 30;
    ball.speed_y = 30;

    p1.x = s_width - 30 - 20;
    p1.y = s_height / 2 - 50;
    p1.width = 30;
    p1.height = 150;
    p1.speed = 8;

    p2.x = 20;
    p2.y = s_height / 2 - 50;
    p2.width = 30;
    p2.height = 150;
    p2.speed = 8;

    while (WindowShouldClose() == false) {
        BeginDrawing();

        if(gameOver == false){
        ClearBackground(BLACK);

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{p1.x, p1.y, p1.width, p1.height})) {
            ball.speed_x *= -1;
        }

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{p2.x, p2.y, p2.width, p2.height})) {
            ball.speed_x *= -1;
        }

        DrawText(TextFormat("%d", Player_2), s_width / 4, 30, 40, RED);
        DrawText(TextFormat("%d", Player_1), s_width * 3 / 4, 30, 40, RED);

        ball.Change();
        p1.Change();
        p2.Change();

        DrawLine(s_width / 2, 0, s_width / 2, s_height, WHITE);
        ball.Draw();
        p2.Draw();
        p1.Draw();
    }
    else 

    if(gameOver == true){
        if(Player_1 == 10){
        ClearBackground(WHITE);
        DrawText("Player 1 Wins!!", s_width / 2 - 100, s_height / 2 - 30, 60, GREEN);
        }
        if(Player_2 == 10){
        ClearBackground(WHITE);
        DrawText("Player 2 Wins!!", s_width / 2 - 100, s_height / 2 - 30, 60, GREEN);    
        }
    }

    if (Player_1 == 10 || Player_2 == 10) {
            gameOver = true;
        }

        EndDrawing();
    }
    CloseWindow();
}