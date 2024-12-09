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
PCboy boy1;
PokehealerPC right;
PokeHealer healer;
TextBox textOutput;
Pokedex dex;
Party party;
int returnVal = 0;
bool displayTextBox = false;
bool inPath = false;

int sl = 0;
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
    joy.printNurseJoy(-35.5,36.5);
    pc.printPC();
    right.printPokeHealerRight(-63,50);
    healer.printPokeHealer(-95,51);
    frontDesk.printDesk();
    sideDesk.drawDeskSide(4.5,45);
    ball.printBowls();
    boy1.printBoySprite(67,37,0);
    satoshi.drawPlayer(posx,posy,cycle,direction);

if (!popUp.isOpen() && !displayTextBox) {
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
    }else if(posx + pHSx  > arenaHSx-30){//PC x len
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
            if (posx + pHSx > arenaHSx - 32) {//pc x len
                posx = arenaHSx - pHSx - 32;
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

    if (posy == arenaHSy - pHSy - 39 &&
        direction == 0 &&
        posx > -29-6 && posx < -29+6
        && isPressed(BUTTON_7)) {
            displayTextBox = true;
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

}else if (popUp.isOpen()){
    popUp.drawMenu(choice);
    if(!inPath) {
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
            dex.toggleDex();
            inPath = true;
            break;
        case 1:
            party.toggleParty();
            inPath = true;
            break;
        case 2:
            /*code*/
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
            returnVal = 0;
            break;
        default:
            break;
        }
    }

    if (isPressed(BUTTON_9)) {//close menu by hitting menu key
        popUp.toggleMenu();
    }
    if(isDown(BUTTON_RETURN)) {//close menu by hitting "b" buttong
        if (popUp.isOpen() == true)
        {
            popUp.toggleMenu();
            choice = 0;
        }
    }
    }if (dex.isOpen()) {
        dex.displayDex();
        if (isPressed(BUTTON_RETURN)) {
            dex.toggleDex();
            inPath = false;
        }
    }else if (party.isOpen() && inPath) {
        party.displayParty();
        if (isPressed(BUTTON_RETURN)) {
            party.toggleParty();
            inPath = false;
        }
    }   
    }
    
    
    
    if (displayTextBox == true) {
        if (isPressed(BUTTON_RETURN) || sl >= joy.lines) {
            displayTextBox = false;
            sl = 0;
        }else if (isPressed(BUTTON_7)) {
            sl++;
        }
        BallCorners corner;
        textOutput.displayBox(joy.script[sl],joy.state[sl],joy.small[sl],joy.len[sl]);
        corner.printBall(-86,-18);
        corner.printBall(86,-18);
        corner.printBall(86,-22*2);
        corner.printBall(-86,-22*2);
    }

}



// internal int
// simulatePokedex(Input* input, float dt) {
//     clearScreen(0x000000);
//     if(isPressed(BUTTON_RETURN)) {
//         returnVal = 0;
//         popUp.open = true;
//         return returnVal;
//     }
//     return 1;
// }