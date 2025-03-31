#include "raylib.h"
#include "../updategame/updategame.h"
#include <stdio.h>

void InitFinal()
{
    float       TimePlayed = 0.0f, AcmPosition = 100, BalloonPosition = 0;
    int         EndGame = 0;
    
    /* Init music */
    InitAudioDevice();
    Music       FinalMusic = LoadMusicStream("../res/audio/endgame/Final.mp3");
    PlayMusicStream(FinalMusic);

    /* Draw map and player*/
    Image       MapImage = LoadImage("../res/images/endgame/FinalMap.png"),
                DownMovImage = LoadImage("../res/images/ingame/MovDown.png"),
                CollaboratorsImage = LoadImage("../res/images/endgame/Collaborators.png"),
                AcmImage = LoadImage("../res/images/endgame/Acm.png"),
                BalloonImage = LoadImage("../res/images/endgame/Balloon.png"),  
                CreditsImage = LoadImage("../res/images/endgame/Credits.png");

    Texture2D   MapTexture = LoadTextureFromImage(MapImage),
                DownMovTexture = LoadTextureFromImage(DownMovImage),
                CollaboratorsTexture = LoadTextureFromImage(CollaboratorsImage),
                AcmTexture = LoadTextureFromImage(AcmImage),
                BalloonTexture = LoadTextureFromImage(BalloonImage),
                CreditsTexture = LoadTextureFromImage(CreditsImage);
    
    /* Unload images */
    UnloadImage(MapImage);
    UnloadImage(DownMovImage);
    UnloadImage(CollaboratorsImage);
    UnloadImage(AcmImage);
    UnloadImage(BalloonImage);
    UnloadImage(CreditsImage);

    /* Final scene and credits */
    while(EndGame == 0)
    {
        
        BeginDrawing();

        UpdateMusicStream(FinalMusic);
        TimePlayed = GetMusicTimePlayed(FinalMusic) / GetMusicTimeLength(FinalMusic);

        /* Close game */
        if (TimePlayed > 0.965f)
        {
            EndGame = 1;
        }

        /* Draw credits scene */
        else if (TimePlayed > 0.2675f && TimePlayed < 1.0f)
        {
    
            DrawTexture(CollaboratorsTexture, 0, 0, WHITE);
            DrawTexture(CreditsTexture, 400, 0, WHITE);
        
        }
        
        /* Draw final scene */
        else if (TimePlayed < 0.2675f)
        {
        
        DrawTexture(MapTexture, 0, 0, WHITE);
        DrawTexture(DownMovTexture, 370, 70, WHITE);
        DrawTexture(BalloonTexture, 370, BalloonPosition, WHITE);
        DrawTexture(AcmTexture, 355, AcmPosition, WHITE);
        
        AcmPosition += 0.3f;
        BalloonPosition += 0.3f;
        
        }
        
        EndDrawing();

    }

    /* Unload textures */
    UnloadTexture(MapTexture);
    UnloadTexture(DownMovTexture);
    UnloadTexture(CollaboratorsTexture);
    UnloadTexture(AcmTexture);
    UnloadTexture(BalloonTexture);
    UnloadTexture(CreditsTexture);

    /* Stop music */
    StopMusicStream(FinalMusic);
    UnloadMusicStream(FinalMusic);
    CloseAudioDevice();

    /* Close window */
    CloseWindow();
}