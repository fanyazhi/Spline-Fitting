/*
 *  main.cpp
 *  SplineFitting
 *  This file contains an Raylib integrated example usage of the spline fitting method 
 */

#include <iostream>
#include <vector>

#include "../src/CRSmatrix.h"
#include "../src/cubicSpline.h"
#include "../src/secondDerivativeTest.h"
#include "debugapi.h"
#include "raylib.h"

int main() {
    // initialize RAYLIB window
    //--------------------------------------------------------------------------------------

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Cubic Spline Fitting");

    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

    bool newInput = false;  // this is the initial state of the game

    // initialize anchor points and interpolated points
    //--------------------------------------------------------------------------------------
    vector<double> x;
    vector<double> y;
    int points = 1000;
    vector<double> qx(points);
    vector<double> qy(points);

    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        // text prompts
        DrawText("Use Left mouse button to set anchor points", 10, 10, 20, DARKGRAY);
        DrawText("Press Enter to reset", 10, 50, 20, DARKGRAY);

        // let player input anchor points
        if (newInput) {
            // calculate the spline curve interpolated points after getting over 3 anchor points
            if (x.size() > 3) {
                cubicSpline(x, y, qx, qy);
            }
            newInput = false;
        } else {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 pos = GetMousePosition();
                x.push_back(pos.x);
                y.push_back(pos.y);
                newInput = true;
            }
        }

        // reset everything
        if (IsKeyPressed(KEY_ENTER)) {
            x.clear();
            y.clear();
            std::fill(qx.begin(), qx.end(), 0);
            std::fill(qy.begin(), qy.end(), 0);
            newInput = false;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        // Draw interpolated points if there are more than 3 anchor points
        // Otherwise, draw anchor points
        if (x.size() > 3) {
            for (int i = 0; i < points; i++) {
                DrawCircle(qx[i], qy[i], 2, RED);
            }
        } else {
            for (int i = 0; i < x.size(); i++) {
                DrawCircle(x[i], y[i], 2, RED);
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}