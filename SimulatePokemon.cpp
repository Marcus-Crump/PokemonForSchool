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
doormat carpet;
Player satoshi;
Alphabet letter;
chair chairs;
pokePC pc;
deskFront frontDesk;
Menu popUp;
bowlThing ball;
DeskSide sideDesk;
nurseJoy joy;
PokehealerPC right;
internal void
simulateGame(Input* input, float dt) {
    float accely, accelx = 0.f;
    ground.printFloor();
    ground.printShadowFloor(26,-97.5,15);
    ground.printShadowFloor(-6,-105.5,8);
    ground.printShadowFloor(14,82.5,1);
    wall.printWall();
    carpet.makeCarpet(-11,-42.5);
    chairs.printChair(-37.5,35);
    chairs.printChair(-37.5,47.5);
    chairs.printChair(-12.5,35);
    chairs.printChair(-12.5,47.5);
    joy.printNurseJoy(-28,40);
    pc.printPC();
    right.printPokeHealerRight(-45,50);
    frontDesk.printDesk();
    sideDesk.drawDeskSide(5,45);
    ball.printBowls();

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

    if (timer > 20){
        cycle++;
        timer = 0;
      if (cycle > 3) {
        cycle = 0;
    }
    }



    accelx -= velx *10.f;
    velx += accelx*dt;
    posx += velx * dt + accelx*dt*dt * .5f;

    if(posx + pHSx  > arenaHSx) {
        posx = arenaHSx - pHSx ;
        velx *= 0;
    }else if(posx + pHSx  > arenaHSx-14){//PC x len
        if(posy + pHSy + 9 > arenaHSy-12){//PC y len
            posy = arenaHSy - pHSy - 21 ;
            vely *= 0;
        }else if(posy - pHSy - 4.5 < -arenaHSy) {
        posy = -arenaHSy + pHSy + 4.5;
        vely *= 0;
        }
    }
    else if(posx - pHSx - 6 < -arenaHSx) {
        posx = -arenaHSx + pHSx + 6;
        velx *= 0;
    }else if(posx - pHSx - 6 < -arenaHSx + 118) {//Desk X len
        if(posy + pHSy + 9 > arenaHSy-30){//desk y len
            posy = arenaHSy - pHSy - 39 ;
            vely *= 0;
        }else if(posy - pHSy - 4.5 < -arenaHSy) {
        posy = -arenaHSy + pHSy + 4.5;
        vely *= 0;
        }
    }else if(posy + pHSy + 9 > arenaHSy) {
        posy = arenaHSy - pHSy - 9 ;
        vely *= 0;
    }else if (posy + pHSy + 9 > arenaHSy - 30) {//Desk y len
        if (posy + pHSy + 9 > arenaHSy-14) { //PC y len
            if (posx + pHSx > arenaHSx - 15) {//pc x len
                posx = arenaHSx - pHSx - 15;
                velx *= 0;
            }
        }
        if (posx - pHSx - 6 < -arenaHSx + 120) {//desk x len
            posx = -arenaHSx + pHSx + 126;
            velx *= 0;
        }

    }
    else if(posy - pHSy - 4.5 < -arenaHSy) {
        posy = -arenaHSy + pHSy + 4.5;
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
            choice = 0;
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
            choice = 0;
        }
    }
    }
    satoshi.drawPlayer(posx,posy,cycle,direction);

    if (popUp.isOpen() == true)
    {
        popUp.drawMenu(choice);
    }
}



