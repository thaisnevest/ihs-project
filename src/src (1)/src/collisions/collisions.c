#include "raylib.h"
#include "collisions.h"
bool colisoes_paredes(float *position_x, float *position_y){
    Rectangle borders;
    borders.x = 16;
    borders.y = 395;
    borders.width = 800;
    borders.height = 16;

    Rectangle aux1borders;
    aux1borders.x = 110;
    aux1borders.y = 380;
    aux1borders.width = 16;
    aux1borders.height = 16;

    Rectangle aux2borders;
    aux2borders.x = 382;
    aux2borders.y = 346;
    aux2borders.width = 16;
    aux2borders.height = 48;

    Rectangle aux3borders;
    aux3borders.x = 430;
    aux3borders.y = 362;
    aux3borders.width = 16;
    aux3borders.height = 32;
    
    Rectangle aux4borders;
    aux4borders.x = 528;
    aux4borders.y = 362;
    aux4borders.width = 16;
    aux4borders.height = 32;

    Rectangle aux5borders;
    aux5borders.x = 638;
    aux5borders.y = 362;
    aux5borders.width = 16;
    aux5borders.height = 32;

    Rectangle rtree1;
    rtree1.x = 734;
    rtree1.y = 326;
    rtree1.width = 16;
    rtree1.height = 64;

    Rectangle rtree2;
    rtree2.x = 684;
    rtree2.y = 298;
    rtree2.width = 16;
    rtree2.height = 64;

    Rectangle rtree3;
    rtree3.x = 700;
    rtree3.y = 312;
    rtree3.width = 64;
    rtree3.height = 16;

    Rectangle rtree4;
    rtree4.x = 750;
    rtree4.y = 208;
    rtree4.width = 16;
    rtree4.height = 96;

    Rectangle rtree5;
    rtree5.x = 718;
    rtree5.y = 266;
    rtree5.width = 32;
    rtree5.height = 16;
    
    Rectangle rtree6;
    rtree6.x = 718;
    rtree6.y = 138;
    rtree6.width = 16;
    rtree6.height = 128;

    Rectangle rtree7;
    rtree7.x = 734;
    rtree7.y = 138;
    rtree7.width = 32;
    rtree7.height = 16;

    Rectangle rtree8;
    rtree8.x = 750;
    rtree8.y = 106;
    rtree8.width = 16;
    rtree8.height = 32;

    Rectangle rtree9;
    rtree9.x = 672;
    rtree9.y = 186;
    rtree9.width = 48;
    rtree9.height = 16;

    Rectangle rtree10;
    rtree10.x = 672;
    rtree10.y = 154;
    rtree10.width = 16;
    rtree10.height = 32;

    Rectangle rtree11;
    rtree11.x = 654;
    rtree11.y = 154;
    rtree11.width = 16;
    rtree11.height = 16;

    Rectangle rtree12;
    rtree12.x = 636;
    rtree12.y = 154;
    rtree12.width = 16;
    rtree12.height = 48;

    Rectangle rtree13;
    rtree13.x = 526;
    rtree13.y = 186;
    rtree13.width = 112;
    rtree13.height = 16;

    Rectangle rtree14;
    rtree14.x = 526;
    rtree14.y = 90;
    rtree14.width = 16;
    rtree14.height = 96;

    Rectangle rtree15;
    rtree15.x = 542;
    rtree15.y = 90;
    rtree15.width = 32;
    rtree15.height = 16;

    Rectangle rtree16;
    rtree16.x = 638;
    rtree16.y = 234;
    rtree16.width = 48;
    rtree16.height = 16;

    Rectangle rtree17;
    rtree17.x = 526;
    rtree17.y = 234;
    rtree17.width = 80;
    rtree17.height = 16;

    Rectangle rtree18;
    rtree18.x = 526;
    rtree18.y = 250;
    rtree18.width = 16;
    rtree18.height = 80;

    Rectangle rtree19;
    rtree19.x = 544;
    rtree19.y = 314;
    rtree19.width = 112;
    rtree19.height = 16;

    Rectangle rtree20;
    rtree20.x = 590;
    rtree20.y = 330;
    rtree20.width = 16;
    rtree20.height = 32;

    Rectangle rtree21;
    rtree21.x = 478;
    rtree21.y = 266;
    rtree21.width = 16;
    rtree21.height = 64;

    Rectangle rtree22;
    rtree22.x = 430;
    rtree22.y = 314;
    rtree22.width = 48;
    rtree22.height = 16;

    Rectangle rtree23;
    rtree23.x = 478;
    rtree23.y = 170;
    rtree23.width = 16;
    rtree23.height = 64;

    Rectangle rtree24;
    rtree24.x = 430;
    rtree24.y = 170;
    rtree24.width = 48;
    rtree24.height = 16;

    Rectangle rtree25;
    rtree25.x = 350;
    rtree25.y = 122;
    rtree25.width = 176;
    rtree25.height = 16;

    Rectangle rtree26;
    rtree26.x = 350;
    rtree26.y = 74;
    rtree26.width = 16;
    rtree26.height = 48;

    Rectangle rtree27;
    rtree27.x = 414;
    rtree27.y = 58;
    rtree27.width = 352;
    rtree27.height = 16;

    Rectangle rtree28;
    rtree28.x = 670;
    rtree28.y = 74;
    rtree28.width = 16;
    rtree28.height = 48;

    Rectangle rtree29;
    rtree29.x = 590;
    rtree29.y = 106;
    rtree29.width = 80;
    rtree29.height = 16;

    Rectangle rtree30;
    rtree30.x = 750;
    rtree30.y = 42;
    rtree30.width = 16;
    rtree30.height = 16;

    Rectangle rtree31;
    rtree31.x = 750;
    rtree31.y = 10;
    rtree31.width = 48;
    rtree31.height = 32;

    Rectangle rtree32;
    rtree32.x = 750;
    rtree32.y = 10;
    rtree32.width = 48;
    rtree32.height = 32;

    Rectangle bordert;
    bordert.x = 14;
    bordert.y = 10;
    bordert.width = 800;
    bordert.height = 16;

    Rectangle borderl;
    borderl.x = 14;
    borderl.y = 10;
    borderl.width = 16;
    borderl.height = 400;   
    
    Rectangle upCorner;
    upCorner.x = 30;
    upCorner.y = 26;
    upCorner.width = 32;
    upCorner.height = 32;

    Rectangle upRight;
    upRight.x = 30;
    upRight.y = 74;
    upRight.width = 16;
    upRight.height = 16;

    Rectangle rightMiddle;
    rightMiddle.x = 78;
    rightMiddle.y = 58;
    rightMiddle.width = 304;
    rightMiddle.height = 16;

    Rectangle secondUpRight;
    secondUpRight.x = 78;
    secondUpRight.y = 74;
    secondUpRight.width = 16;
    secondUpRight.height = 16;

    Rectangle leftCorner;
    leftCorner.x = 62;
    leftCorner.y = 90;
    leftCorner.width = 16;
    leftCorner.height = 96;

    Rectangle leftBottomCorner;
    leftBottomCorner.x = 110;
    leftBottomCorner.y = 138;
    leftBottomCorner.width = 16;
    leftBottomCorner.height = 176;

    Rectangle leftMiddleCorner;
    leftMiddleCorner.x = 142;
    leftMiddleCorner.y = 138;
    leftMiddleCorner.width = 16;
    leftMiddleCorner.height = 144;

    Rectangle twoSquares;
    twoSquares.x = 78;
    twoSquares.y = 170;
    twoSquares.width = 32;
    twoSquares.height = 16;

    Rectangle fourLeftTopX;
    fourLeftTopX.x = 110;
    fourLeftTopX.y = 122;
    fourLeftTopX.width = 64;
    fourLeftTopX.height = 16;

    Rectangle fourLeftTopY;
    fourLeftTopY.x = 190;
    fourLeftTopY.y = 74;
    fourLeftTopY.width = 16;
    fourLeftTopY.height = 64;

    Rectangle middleTopX;
    middleTopX.x = 206;
    middleTopX.y = 122;
    middleTopX.width = 112;
    middleTopX.height = 16;

    Rectangle twoTopY;
    twoTopY.x = 302;
    twoTopY.y = 90;
    twoTopY.width = 16;
    twoTopY.height = 32;

    Rectangle centerX;
    centerX.x = 302;
    centerX.y = 170;
    centerX.width = 96;
    centerX.height = 16;

    Rectangle centerY;
    centerY.x = 334;
    centerY.y = 186;
    centerY.width = 16;
    centerY.height = 48;

    Rectangle lonelyLeftCenter;
    lonelyLeftCenter.x = 190;
    lonelyLeftCenter.y = 218;
    lonelyLeftCenter.width = 16;
    lonelyLeftCenter.height = 16;

    Rectangle leftCenterY;
    leftCenterY.x = 206;
    leftCenterY.y = 138;
    leftCenterY.width = 16;
    leftCenterY.height = 96;

    Rectangle nextCenterY;
    nextCenterY.x = 254;
    nextCenterY.y = 218;
    nextCenterY.width = 48;
    nextCenterY.height = 16;

    Rectangle nextCenterX;
    nextCenterX.x = 240;
    nextCenterX.y = 170;
    nextCenterX.width = 16;
    nextCenterX.height = 64;

    Rectangle leftBottomX;
    leftBottomX.x = 30;
    leftBottomX.y = 298;
    leftBottomX.width = 32;
    leftBottomX.height = 16;

    Rectangle leftBottomY;
    leftBottomY.x = 62;
    leftBottomY.y = 218;
    leftBottomY.width = 16;
    leftBottomY.height = 144;

    Rectangle centerBottomFourY;
    centerBottomFourY.x = 334;
    centerBottomFourY.y = 266;
    centerBottomFourY.width = 16;
    centerBottomFourY.height = 64;

    Rectangle centerBottomThreeY;
    centerBottomThreeY.x = 350;
    centerBottomThreeY.y = 314;
    centerBottomThreeY.width = 16;
    centerBottomThreeY.height = 48;

    Rectangle centerBottomX;
    centerBottomX.x = 366;
    centerBottomX.y = 314;
    centerBottomX.width = 32;
    centerBottomX.height = 16;
    
    Rectangle leftMiddleVertical;
    leftMiddleVertical.x = 142;
    leftMiddleVertical.y = 138;
    leftMiddleVertical.width = 16;
    leftMiddleVertical.height = 128;

    Rectangle leftMiddleHorizontal;
    leftMiddleHorizontal.x = 142;
    leftMiddleHorizontal.y = 262;
    leftMiddleHorizontal.width = 80;
    leftMiddleHorizontal.height = 16;

    Rectangle leftBottomVertical;
    leftBottomVertical.x = 302;
    leftBottomVertical.y = 298;
    leftBottomVertical.width = 16;
    leftBottomVertical.height = 80;

    Rectangle leftBottomHorizontal;
    leftBottomHorizontal.x = 110;
    leftBottomHorizontal.y = 344;
    leftBottomHorizontal.width = 192;
    leftBottomHorizontal.height = 16;

    Rectangle leftBottomSeven;
    leftBottomSeven.x = 110;
    leftBottomSeven.y = 310;
    leftBottomSeven.width = 112;
    leftBottomSeven.height = 16;

    Rectangle leftBottomTwo;
    leftBottomTwo.x = 224;
    leftBottomTwo.y = 294;
    leftBottomTwo.width = 16;
    leftBottomTwo.height = 32;

    Rectangle borderr;
    borderr.x = 794;
    borderr.y = 10;
    borderr.width = 16;
    borderr.height = 400;
    
    Rectangle recplayer;
    recplayer.x = *position_x;
    recplayer.y = *position_y;
    recplayer.width = 12;
    recplayer.height = 12;

    if(CheckCollisionRecs(borders, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(aux1borders, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(aux2borders, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(aux3borders, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(borderr, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(aux4borders, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(aux5borders, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree1, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree2, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree3, recplayer)){
        return true; 
    }
    
    if(CheckCollisionRecs(rtree4, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree5, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree6, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree7, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree8, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree9, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree10, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree11, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree12, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree13, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree14, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree15, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree16, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree17, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree18, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree19, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree20, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree21, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree22, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree23, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree24, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree25, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree26, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree27, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree28, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree29, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree30, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree31, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rtree32, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(borderl, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(bordert, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(bordert, recplayer)){
        return true; 
    }
    if(CheckCollisionRecs(upCorner, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(upRight, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(rightMiddle, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(secondUpRight, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftCorner, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftBottomCorner, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftMiddleCorner, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(twoSquares, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(fourLeftTopX, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(fourLeftTopY, recplayer)){
        return true; 
    }
    
    if(CheckCollisionRecs(middleTopX, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(twoTopY, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(centerX, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(centerY, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(lonelyLeftCenter, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftCenterY, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(nextCenterY, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(nextCenterX, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftBottomX, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftBottomY, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(centerBottomFourY, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(centerBottomThreeY, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(centerBottomX, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftMiddleVertical, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftMiddleHorizontal, recplayer)){
        return true; 
    }
    
    if(CheckCollisionRecs(leftBottomVertical, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftBottomHorizontal, recplayer)){
        return true; 
    }

    if(CheckCollisionRecs(leftBottomSeven, recplayer)){
        return true; 
    }
    
    if(CheckCollisionRecs(leftBottomTwo, recplayer)){
        return true; 
    }
}

int colisoes_triggers(float *position_x, float *position_y){

    Rectangle monitor1, monitor2, monitor3, monitor4, recplayer, final;
    monitor1.x = 690;
    monitor1.y = 320;
    monitor1.width = 30;
    monitor1.height = 30;

    monitor2.x = 15;
    monitor2.y = 300;
    monitor2.width = 30;
    monitor2.height = 30;

    monitor3.x = 70;
    monitor3.y = 110;
    monitor3.width = 25;
    monitor3.height = 44;

    monitor4.x = 753;
    monitor4.y = 20;
    monitor4.width = 30;
    monitor4.height = 40;

    recplayer.x = *position_x;
    recplayer.y = *position_y;
    recplayer.width = 12;
    recplayer.height = 12;

    final.x = 745;
    final.y = 330;
    final.width = 50;
    final.height = 50;
    
    if (CheckCollisionRecs(monitor1, recplayer)){
        return 1;
    }
    else if (CheckCollisionRecs(monitor2, recplayer)){
        return 2;
    }
    else if (CheckCollisionRecs(monitor3, recplayer)){
        return 3;
    }
    else if (CheckCollisionRecs(monitor4, recplayer)){
        return 4;
    }
    else if (CheckCollisionRecs(final, recplayer)){
        return 5;
    }
    else
        return 0;
}