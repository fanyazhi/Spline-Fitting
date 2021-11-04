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

    InitWindow(screenWidth, screenHeight, "raylib");

    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        // Spline code
        //--------------------------------------------------------------------------------------
        DrawText("Use Left mouse button to set anchor points", 10, 10, 20, DARKGRAY);
        DrawText("Press Enter to draw spline curve", 10, 50, 20, DARKGRAY);
        DrawText("Press R to reset", 10, 90, 20, DARKGRAY);

        // //read the given x and y points
        vector<double> x{10, 20, 30, 40, 50, 60, 500, 700};
        vector<double> y{10, 30, 40, 60, 80, 120, 200, 400};

        // //initialize qx and qy for extraction
        int points = 50;
        vector<double> qx(points);
        vector<double> qy(points);

        // cout << "calculating spline..." << endl;
        // //call cubic spline
        cubicSpline(x, y, qx, qy);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //DrawCircle(int centerX, int centerY, float radius, Color color);
        for (int i = 0; i < points; i++) {
            DrawCircle(qx[i], qy[i], 2, RED);
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