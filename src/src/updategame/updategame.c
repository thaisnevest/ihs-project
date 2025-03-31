#include "raylib.h"
#include "updategame.h"
#include "../collisions/collisions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// da placa
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "../../../include/ioctl_cmds.h"


#define tamanho_tile 32 // tamanho do tile do mapa
#define tamanho_neblina 2 // tamanho da neblina

typedef struct{
    int tilesX;            // tiles x
    int tilesY;            // tiles y
    char *tileIds;         //
    char *tileNeblina;     // estilo da neblina( meia neblina ou neblina completa )
} Map;

/* Initializing */
Vector2 PlayerPosition = { 400, 240 };
Music InGameMusic, MonitorMusic, FinalMusic;
Sound MovSound;
Texture2D MapTexture, UpMovTexture, LeftMovTexture, DownMovTexture, RightMovTexture, Monitor1Texture, Monitor2Texture, Monitor3Texture, Monitor4Texture;
Image MapImage, UpMovImage, LeftMovImage, DownMovImage, RightMovImage, Monitor1Image, Monitor2Image, Monitor3Image, Monitor4Image;

/* Texture Initializing */
void InitImages(){
    
    MapImage = LoadImage("../res/images/ingame/MainMap.png");
    MapTexture = LoadTextureFromImage(MapImage);

    RightMovImage = LoadImage("../res/images/ingame/MovRight.png");
    RightMovTexture = LoadTextureFromImage(RightMovImage);
    
    LeftMovImage = LoadImage("../res/images/ingame/MovLeft.png");
    LeftMovTexture = LoadTextureFromImage(LeftMovImage);
    
    UpMovImage = LoadImage("../res/images/ingame/MovUp.png");
    UpMovTexture = LoadTextureFromImage(UpMovImage);
    
    DownMovImage = LoadImage("../res/images/ingame/MovDown.png");
    DownMovTexture = LoadTextureFromImage(DownMovImage);
    
    Monitor1Image = LoadImage("../res/images/ingame/Monitor1.png");
    Monitor1Texture = LoadTextureFromImage(Monitor1Image);
    
    Monitor2Image = LoadImage("../res/images/ingame/Monitor2.png");
    Monitor2Texture = LoadTextureFromImage(Monitor2Image);
    
    Monitor3Image = LoadImage("../res/images/ingame/Monitor3.png");
    Monitor3Texture = LoadTextureFromImage(Monitor3Image);
    
    Monitor4Image = LoadImage("../res/images/ingame/Monitor4.png");
    Monitor4Texture = LoadTextureFromImage(Monitor4Image);
    
    BeginDrawing();
    DrawTexture(UpMovTexture, PlayerPosition.x, PlayerPosition.y, WHITE);
    EndDrawing();
}

void EndImages(){

    UnloadImage(LeftMovImage);
    UnloadImage(RightMovImage);
    UnloadImage(Monitor1Image);
    UnloadImage(Monitor2Image);
    UnloadImage(Monitor3Image);
    UnloadImage(Monitor4Image);
    UnloadImage(MapImage);
    UnloadImage(DownMovImage);
    UnloadImage(UpMovImage);

    UnloadTexture(LeftMovTexture);
    UnloadTexture(RightMovTexture);
    UnloadTexture(Monitor1Texture);
    UnloadTexture(Monitor2Texture);
    UnloadTexture(Monitor3Texture);
    UnloadTexture(Monitor4Texture);
    UnloadTexture(MapTexture);
    UnloadTexture(DownMovTexture);
    UnloadTexture(UpMovTexture);
}

// movimentação do player
void MovRight(){
    PlayerPosition.x += 1.5f;
}

void MovLeft(){
    PlayerPosition.x -= 1.5f;
}

void MovUp(){
    PlayerPosition.y -= 1.5f;
}

void MovDown(){
    PlayerPosition.y += 1.5f;
}

// Movimentação do Player
char ReadMovement(char *LastMovement, int fd){
	int key;
	ioctl(fd, RD_PBUTTONS);
	read(fd, &key, 1);
		
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D) ||key == 14 ){
	//ioctl(fd,WR_GREEN_LEDS);
	//write(fd, &data_um,sizeof(data_um));

        MovRight();
        if(!IsSoundPlaying(MovSound)) PlaySound(MovSound);
        *LastMovement = 'd';
        return *LastMovement;
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A) || key == 7){
	//ioctl(fd,WR_GREEN_LEDS);
	// write(fd, &data_dois,sizeof(data_dois));

        MovLeft();
        if(!IsSoundPlaying(MovSound)) PlaySound(MovSound);
        *LastMovement = 'a';
        return *LastMovement;
    }
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || key == 13){
	//ioctl(fd,WR_GREEN_LEDS);
	//write(fd, &data_tres,sizeof(data_tres));

	MovUp();
        if(!IsSoundPlaying(MovSound)) PlaySound(MovSound);
        *LastMovement = 'w';
        return *LastMovement;
    }
    else if (IsKeyDown(KEY_DOWN)|| IsKeyDown(KEY_S) || key == 11){
//	ioctl(fd,WR_GREEN_LEDS);
	//write(fd, &data_quatro,sizeof(data_quatro));

        MovDown();
        if(!IsSoundPlaying(MovSound)) PlaySound(MovSound);
        *LastMovement = 's';
        return *LastMovement;
    }
}

// Draw Player
void DrawPlayer(char *LastMovement){
    if(*LastMovement == 'w'){
        DrawTexture(UpMovTexture, PlayerPosition.x-20, PlayerPosition.y-25, WHITE); // Fator de correção da neblina
    }
    else if(*LastMovement == 'a'){
        DrawTexture(LeftMovTexture, PlayerPosition.x-20, PlayerPosition.y-25, WHITE);
    }
    else if(*LastMovement == 's'){
        DrawTexture(DownMovTexture, PlayerPosition.x-20, PlayerPosition.y-25, WHITE);
    }
    else if(*LastMovement == 'd'){
        DrawTexture(RightMovTexture, PlayerPosition.x - 20, PlayerPosition.y - 25, WHITE);
    }
    else{
        DrawTexture(DownMovTexture, PlayerPosition.x-20, PlayerPosition.y-25, WHITE);
    }
}

// inicia os sound devices usados no código
void InitSound(){
    InitAudioDevice();
    MonitorMusic = LoadMusicStream("../res/audio/ingame/Monitor4.mp3");
    InGameMusic = LoadMusicStream("../res/audio/ingame/InGame.mp3");
    SetMusicVolume(InGameMusic, 0.75);
    PlayMusicStream(InGameMusic);
    MovSound = LoadSound("../res/audio/ingame/Walk.ogg");
    SetSoundVolume(MovSound, 0.05);
}

// Unload no sonoro
void EndSound(){ 
    UnloadMusicStream(InGameMusic);
    UnloadMusicStream(FinalMusic);
    UnloadMusicStream(MonitorMusic);
    UnloadSound(MovSound);
    CloseAudioDevice();
}

// update na musica
float UpdateSounds(Music music, float *timePlayed){
    UpdateMusicStream(music);
    *timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);
    if (*timePlayed > 1.0f) *timePlayed = 1.0f;
    return *timePlayed;
}

// esperando interação com os monitores ou fim do jogo
int search(){
    if(colisoes_triggers(&PlayerPosition.x, &PlayerPosition.y) == 5){
        return 1;
    }
    // Se encontrar o primeiro monitor
    else if(colisoes_triggers(&PlayerPosition.x, &PlayerPosition.y) == 1){
        DrawTexture(Monitor1Texture, 0, 0, WHITE);
        DrawText("Ei boy, tas perdido visse", 50, 300, 50, BLACK);
    }
    else if(colisoes_triggers(&PlayerPosition.x, &PlayerPosition.y) == 2){
        DrawTexture(Monitor2Texture, 0, 0, WHITE);
        DrawText("Não é esse o caminho galera", 30, 300, 50, RED);
    }
    else if(colisoes_triggers(&PlayerPosition.x, &PlayerPosition.y) == 3){
        DrawTexture(Monitor3Texture, 0, 0, WHITE);
        DrawText("Calma que eu não sou encarregada do inferno não", 15, 300, 30, BLACK);
    }
    else if(colisoes_triggers(&PlayerPosition.x, &PlayerPosition.y) == 4){
        
        float timePlayedchurras = 0.0f;
        PlayMusicStream(MonitorMusic);
        timePlayedchurras = UpdateSounds(MonitorMusic, &timePlayedchurras);
        DrawTexture(Monitor4Texture, 0, 0, WHITE);
        DrawText("É o xurras :)", 15, 200, 50, BLUE);
    }
}

// função principal
void updategame(int fd){
    // para dar draw só no ultimo movimento
    char LastMovement;
    // proporções da tela
    float screenWidth = 800;
    float screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "TESEU E O ACMINOTAURO");

    // declarando a quantidade de tiles para a neblina
    Map map;
    map.tilesX = 25;
    map.tilesY = 15;

    // alocação para a neblina do mapa 
    map.tileIds = (char *)calloc(map.tilesX*map.tilesY, sizeof(char));
    map.tileNeblina = (char *)calloc(map.tilesX*map.tilesY, sizeof(char));

    // coordenada da tile que o jogador se encontra
    int playerTileX = 0;
    int playerTileY = 0;

    // load na neblina
    RenderTexture2D neblina = LoadRenderTexture(map.tilesX, map.tilesY);
    SetTextureFilter(neblina.texture, TEXTURE_FILTER_BILINEAR);
    
    // desenho inicial do personagem e chamando imagens
    InitImages();

    // iniciando audiodevice e setando som e volume
    InitSound();
    float timePlayed = 0.0f;  
    
    // Salvando a última posição do player para as colisões
    float lastx, lasty;

    // Flag para endgame
    int endgame = 0;
    
    // Game loop para o início do jogo
    while (endgame == 0){

        //update na musica
        timePlayed = UpdateSounds(InGameMusic, &timePlayed);

        // Salvando a última posição do player
        lastx = PlayerPosition.x;
        lasty = PlayerPosition.y;

        // movimentacao_player
        LastMovement = ReadMovement(&LastMovement, fd);

        // colisao nas paredes
        if (colisoes_paredes(&PlayerPosition.x, &PlayerPosition.y)){
            PlayerPosition.x = lastx;
            PlayerPosition.y = lasty;
        }

        // Apagar a neblina fora do range do boneco
        for (int i = 0; i < map.tilesX*map.tilesY; i++) if (map.tileNeblina[i] == 1) map.tileNeblina[i] = 0;

        // Pegando a posição do tile do player
        playerTileX = (int)((PlayerPosition.x + tamanho_tile/2)/tamanho_tile);
        playerTileY = (int)((PlayerPosition.y + tamanho_tile/2)/tamanho_tile);

        // Checando visibilidade da neblina e tiles fora dos limites do mapa para evitar processamento excessivo
        for (int y = (playerTileY - tamanho_neblina); y < (playerTileY + tamanho_neblina); y++)
            for (int x = (playerTileX - tamanho_neblina); x < (playerTileX + tamanho_neblina); x++)
                if ((x >= 0) && (x < (int)map.tilesX) && (y >= 0) && (y < (int)map.tilesY)) map.tileNeblina[y*map.tilesX + x] = 1;
        
        // Setando os pontos de neblina no mapa
        BeginTextureMode(neblina);
        ClearBackground(BLANK);
        for (int y = 0; y < map.tilesY; y++)
            for (int x = 0; x < map.tilesX; x++)
                if (map.tileNeblina[y*map.tilesX + x] == 0)
                    DrawRectangle(x, y, 1, 1, Fade(BLACK, 1.0f));
                else if (map.tileNeblina[y*map.tilesX + x] == 2)
                    DrawRectangle(x, y, 1, 1, BLACK);
        EndTextureMode();

        // Desenhando o mapa
        BeginDrawing();
        DrawTexture(MapTexture, 0, 0, WHITE);

        // Desenhando o jogador
        DrawPlayer(&LastMovement);
        
        // Desenhando a neblina no mapa
        DrawTexturePro(neblina.texture, (Rectangle){ 0, 0, (float)neblina.texture.width, (float)-neblina.texture.height },
                        (Rectangle){ 0, 0, (float)map.tilesX*tamanho_tile, (float)map.tilesY*tamanho_tile },
                        (Vector2){ 0, 0 }, 0.0f, WHITE);

        // Checando colisões com os triggers
        // Se chegar no fim do labirinto
        endgame = search();

        if(IsKeyDown(KEY_E))
            endgame = 1;

        EndDrawing();
    }
    
    free(map.tileIds);      // free nos tileids
    free(map.tileNeblina);      // free na neblina

    // unload DownMovTexture
    EndImages();

    // unload nas músicas
    EndSound();
    
    UnloadRenderTexture(neblina);  // Unload na textura da neblina
}
