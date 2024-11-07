/* LIBRARIES */
#include <raylib.h>


#include <imgui.h>
#include <imgui_impl_raylib.h>
#include <rlImGui.h>


#include <nlohmann/json.hpp>
using json = nlohmann::json;

/* STD */
#include <string>
#include <fstream>


/* IM DEFINES */
#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
#define IM_MAX(A, B)            (((A) >= (B)) ? (A) : (B))
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))
/* PROTOTYPES */
void shutdown();



//------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------
    const int screenWidth = 720;
    const int screenHeight = 1280;


    std::string helloMessage = "Hello World!";

    //JSON PARSE test ===> IF PARSING IS WORKING, "Hello World!" will become "Hello Wacky World!"
    std::ifstream f("resources/test.json");
    json data = json::parse(f);
    helloMessage = data["message"];


    //SETUP WINDOW--------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Raylib Template A");
    SetTargetFPS(60);

    rlImGuiSetup(true);// sets up ImGui with ether a dark or light default theme
    //--------------------------------------------------------------------------


    // Main game loop
    while (!WindowShouldClose()){
      //  UPDATE ---------------------------------------------------------------


      // DRAW ------------------------------------------------------------------
      BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText(helloMessage.c_str(), 190, 200, 20, DARKGRAY);
        
        rlImGuiBegin();
            ImGui::ShowDemoWindow();
        rlImGuiEnd();


      EndDrawing();
      //------------------------------------------------------------------------
    }


    shutdown();
    return 0;
}

void shutdown(){
  // De-Initialization
  //----------------------------------------------------------------------------
  rlImGuiShutdown();		// cleans up ImGui
  CloseWindow();        // Close window and OpenGL context
  //----------------------------------------------------------------------------

}
