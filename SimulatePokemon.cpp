#include "sprites.cpp"
#include "events.cpp"
#include <cstdio>
#define isDown(b) input->buttons[b].isDown
#define isPressed(b) (input->buttons[b].isDown && input->buttons[b].changed)
#define released(b) (!input->buttons[b].isDown && input->buttons[b].changed)

float posy, posx, vely, velx = 0.f;
float arenaHSx = 95, arenaHSy = 50;
float pHSx = 2.5, pHSy = 2.5;
int choice = 0;
unsigned int color = 0x0ff00f;
Player satoshi;
Alphabet letter;
Menu popUp;
internal void
simulateGame(Input* input, float dt) {
    float accely, accelx = 0.f;

if (popUp.isOpen() == false) {
    if (isDown(BUTTON_8)) {
        accely += 1350;
    }
    if (isDown(BUTTON_5)) {
        accely -= 1350;
    }
    accely -= vely * 10.f;
    vely += accely*dt;
    posy += vely * dt + accely *dt *dt * .5f;
    satoshi.setYpos(posy);

    if (isDown(BUTTON_4)) {
        accelx -= 1350;
    }
    if (isDown(BUTTON_6)) {
        accelx += 1350;
    }


    accelx -= velx *10.f;
    velx += accelx*dt;
    posx += velx * dt + accelx*dt*dt * .5f;
    satoshi.setXpos(posx);


    if(posx + pHSx > arenaHSx) {
        posx = arenaHSx - pHSx;
        velx *= 0;
    }
    else if(posx - pHSx < -arenaHSx) {
        posx = -arenaHSx + pHSx;
        velx *= 0;
    }
    else if(posy + pHSy > arenaHSy) {
        posy = arenaHSy - pHSy;
        vely *= 0;
    }else if(posy - pHSy < -arenaHSy) {
        posy = -arenaHSy + pHSy;
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
    Japanese kana;
    for (int i = 0; i < 64; i++){
    kana.printKatakana(i%16,-80+(float(i)*3.5),45,.25);
    }
    drawRect(-80, 30, 10,10,0xffff00);
    drawRect(80, 30, 10,10,0x00ff00);
    drawRect(-80, -30, 10,10,0x0000ff);
    drawRect(80, -30, 10,10,0xff00ff);
    satoshi.drawPlayer();
    if (popUp.isOpen() == true)
    {
        popUp.drawMenu(choice);
    }
}