#include "sprites.cpp"
#include "events.cpp"
#include "PokeCenter.cpp"
#include <cstdio>
#define isDown(b) input->buttons[b].isDown
#define isPressed(b) (input->buttons[b].isDown && input->buttons[b].changed)
#define released(b) (!input->buttons[b].isDown && input->buttons[b].changed)

float posy, posx, vely, velx = 0.f;
float arenaHSx = 95, arenaHSy = 50;
float pHSx = 2.5, pHSy = 2.5;
int choice = 0;
int timer = 0;
int cycle = 0;
int direction = 2;
unsigned int color = 0x0ff00f;
floorTiles ground;
backWall wall;
Player satoshi;
Alphabet letter;
Menu popUp;
internal void
simulateGame(Input* input, float dt) {
    float accely, accelx = 0.f;
    // for (int i = 35; i<35*5; i -=16) {
    //     for (int j = -100; j < 100; j += 16) {

    //     }
    // }
    // ground.printTile(-100,35,1);
    // ground.printTile(-84,35,1);
    // ground.printTile(-68,35,1);
    // ground.printTile(-52,35,1);
wall.printWall();

if (popUp.isOpen() == false) {
    if (isDown(BUTTON_8)) {
        accely += 750;
        direction = 0;
        timer++;
    }
    if (isDown(BUTTON_5)) {
        accely -= 750;
        direction = 2;
        timer++;
    }
    accely -= vely * 10.f;
    vely += accely*dt;
    posy += vely * dt + accely *dt *dt * .5f;

    if (isDown(BUTTON_4)) {
        accelx -= 750;
        direction = 1;
        timer++;
    }
    if (isDown(BUTTON_6)) {
        accelx += 750;
        direction = 3;
        timer++;
    }

    if (timer > 100){
        cycle++;
        timer = 0;
      if (cycle > 3) {
        cycle = 0;
    }
    }



    accelx -= velx *10.f;
    velx += accelx*dt;
    posx += velx * dt + accelx*dt*dt * .5f;

    if(posx + pHSx + 9*(1.75) > arenaHSx) {
        posx = arenaHSx - pHSx -9*(1.75);
        velx *= 0;
    }
    else if(posx - pHSx -2*(1.75)< -arenaHSx) {
        posx = -arenaHSx + pHSx + 2*(1.75);
        velx *= 0;
    }
    else if(posy + pHSy + 1.75 > arenaHSy) {
        posy = arenaHSy - pHSy - 1.75;
        vely *= 0;
    }else if(posy - pHSy - 9.05*(1.75)< -arenaHSy) {
        posy = -arenaHSy + pHSy + 9.05*(1.75);
        vely *= 0;
    }
    if (isPressed(BUTTON_9)) {
        popUp.toggleMenu();
    }
    if (isDown(BUTTON_7)) {
    }
    if(isDown(BUTTON_RETURN)) {

        if (popUp.isOpen() == true)
        {
            popUp.toggleMenu();
        }
    }
    if (released(BUTTON_8)  || released(BUTTON_4) || released(BUTTON_6)) {
        cycle = 0;
        accelx = 0;
        accely = 0;
        velx = 0;
        vely = 0;
    }
    if (released(BUTTON_5)) {
        cycle = 0;
        accelx = 0;
        accely = 0;
        velx = 0;
        vely = 0;}

}else {
    if (isPressed(BUTTON_8)) {
        if (choice <= 0) {
            choice = 6;
        }else {
            choice--;
        }
    }
    if (isPressed(BUTTON_5)) {
        if (choice >= 6) {
            choice = 0;
        }else {
            choice++;
        }
    }
    if (isDown(BUTTON_7)) {
        switch (choice)
        {
        case 0:
            /* code */
            break;
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            popUp.toggleMenu();
            break;
        default:
            break;
        }
    }
    if (isPressed(BUTTON_9)) {
        popUp.toggleMenu();
    }
    if(isDown(BUTTON_RETURN)) {
        if (popUp.isOpen() == true)
        {
            popUp.toggleMenu();
        }
    }
    }
    satoshi.drawPlayer(posx,posy,cycle,direction);

    if (popUp.isOpen() == true)
    {
        popUp.drawMenu(choice);
    }
}



