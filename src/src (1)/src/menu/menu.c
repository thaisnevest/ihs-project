#include "raylib.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <omp.h>

// lib com as funções da placa
#include "../../../include/ioctl_cmds.h"


#define WIDTH 900
#define HEIGHT 570

/* Initializing */
Image MenuImage, InstructionsImage;
Texture2D MenuTexture, InstructionsTexture;
Music MenuMusic;

/* Audio initialization */
void InitMusic()
{
    InitAudioDevice();
    MenuMusic = LoadMusicStream("../res/audio/menu/Menu.mp3");
    PlayMusicStream(MenuMusic);    
    SetMusicVolume(MenuMusic, 1.0);
}

/* Texture initialization */
void InitImage()
{
    InitWindow(WIDTH, HEIGHT, "TESEU E O ACMINOTAURO");
    MenuImage = LoadImage("../res/images/menu/Menu.png");
    InstructionsImage = LoadImage("../res/images/menu/Instructions.png");
    MenuTexture = LoadTextureFromImage(MenuImage);
    InstructionsTexture = LoadTextureFromImage(InstructionsImage);
}

/* Displays main menu texture */
void MainMenu()
{
    DrawTexture(MenuTexture, 0, 0, WHITE);
}

/* Displays instructions menu texture */
void InstructionsMenu()
{
    DrawTexture(InstructionsTexture, 0, 0, WHITE);
}

/* Update music stream */
void UpdateMusics(float* TimePlayed)
{
    *TimePlayed = GetMusicTimePlayed(MenuMusic) / GetMusicTimeLength(MenuMusic);
    if (*TimePlayed > 1.0f) *TimePlayed = 1.0f;
}

/* Update image */
void UpdateImage(int fd, char* CurWindow)
{
    BeginDrawing();

    int key;
    ioctl(fd, RD_SWITCHES);
    read(fd, &key, 4);
    /* Enter key pressed */
    if(key == 1)
    {   
        /* Go to game */ 
        if(*CurWindow == 'm')
        {
            *CurWindow = 'g';
        }
	
    }

     if(key==4){

        /* Change to main menu */ 
        if(*CurWindow == 'i')
        {
            *CurWindow = 'm';
            MainMenu();
        }
    }

    /* Tab key pressed in main menu */ 
    else if(key == 2 && *CurWindow == 'm')
    {
        *CurWindow = 'i';
        InstructionsMenu();
    }
    
    /* Maintain Textures */
    else
    {
        if(*CurWindow == 'i')
        {
            InstructionsMenu();
        }
        else
        {
            MainMenu();
        }
    }

    EndDrawing();
}

/* Unloads Image */
void EndImage()
{
    UnloadImage(MenuImage);
    UnloadImage(InstructionsImage);    
    UnloadTexture(InstructionsTexture);
    UnloadTexture(MenuTexture);   
    CloseWindow();
}

/* Stop music */
void EndMusic()
{
    UnloadMusicStream(MenuMusic);
    CloseAudioDevice();
}

/* Initializing menu */
void InitMenu(int fd)
{

    /* Music */
    float TimePlayed = 0.0f;
    
    /* Window situation */
    char CurWindow = 'm';   /*
                            m = main menu
                            i = instructions menu
                            g = game 
                            */
    /* Open window */
    InitImage();
    InitMusic();

    /* Menu Loop */
//    #pragma omp parallel 
 //   {   
	//#pragma omp sections
	//{
		//#pragma omp section
	//	{
			//	int thread_id = omp_get_thread_num();
				// printf("id da thread atual: %d\n\n\n\n\n\n\n\n\n\n\n\n", thread_id);
   	 		while(CurWindow != 'g')
			{
			 	/* Rebooting song */
	      	  		UpdateMusicStream(MenuMusic);   
				UpdateMusics(&TimePlayed);

			        /* Switch screen */
			        UpdateImage(fd, &CurWindow);
				
		//}
	//	#pragma omp section
		//{
				unsigned int data = 0x0;
				ioctl(fd, WR_GREEN_LEDS);
				write(fd, &data, sizeof(data));
				
				sleep(1);

				data = 0xFFFFFFFF;
				ioctl(fd, WR_GREEN_LEDS);
				write(fd, &data, sizeof(data));
				sleep(1);
				
				data = 0x0;
				ioctl(fd, WR_GREEN_LEDS);
				write(fd, &data, sizeof(data));

				data = 0xFFFFFFFF;
				ioctl(fd, WR_RED_LEDS);
				write(fd, &data, sizeof(data));

				sleep(1);
				
				data = 0x0;
				ioctl(fd, WR_RED_LEDS);
				write(fd, &data, sizeof(data));

				
				data = 0x0;
				ioctl(fd, WR_L_DISPLAY);
				write(fd, &data, sizeof(data));

				sleep(1);
				
				data = 0xFFFFFFFF;
				ioctl(fd, WR_L_DISPLAY);
				write(fd, &data, sizeof(data));
				
				data = 0x0;
				ioctl(fd, WR_R_DISPLAY);
				write(fd, &data, sizeof(data));

				sleep(1);
				
				data = 0xFFFFFFFF;
				ioctl(fd, WR_R_DISPLAY);
				write(fd, &data, sizeof(data));
			}
	//	}
	//}    

 //   }

    /* Stopping Music and Video */
    EndImage();
    EndMusic();

}
