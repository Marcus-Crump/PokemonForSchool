#include <vector>


class Text {
    public:Text(std::string line, float x, float y, float px) {
        std::vector<int> alph = {};
        alph.reserve(53);
        float x0 = x;
        float y0 = y;
        Alphabet text;
        int count = 0;
        for (char c : "abcdefghijklmnopqrstuvwxyz"){
            alph[int(c)%53] = count;
            count++;
        }

        for (char c : line) {
            if (int(c) != 32){
        text.printLetter(alph[int(c)%53], x0, y0, px);
            }
            x0 += px*12;
        }
    }
};
struct Menu
{
    int width = 50;
    int length = 75;
    int color = 0xa7a7a7;
    public:bool open = false;
    float loc[2] = {50,0};
    float cellLen = 45.f;
    float cellHigh = 5.f;
    void toggleMenu() {
        if (open == true) {
            open = false;
        } else{
            open = true;
        }
    }

    bool isOpen() {
        return open;
    }

    void drawMenu(int selected) {

        int titles[][5] ={
            {21,6,69,0},
            {49,12,60,69,0},
            {42,11,0,0,0},
            {49,64,2,66,70},
            {22,70,48,0,0},
            {22,30,32,2,0},
            {18,59,63,0,0}};
        std::string tags[7] = {"pokedex","pokemon","bag","player","save","settings","exit"};
        int kanaType[] = {true,false,false,false,false,true,true};
        int small[][5] = {
            {false,false,false,false,false},
            {false,false,false,false,false},
            {false,false,false,false,false},
            {false,false,false,false,false},
            {false,false,false,false,false},
            {false,true,false,false,false},
            {false,false,false,false,false},            
        };
        drawRect(loc[0], loc[1], (width/2)+1, (length/2)+1, 0x050047);
        drawRect(loc[0], loc[1], (width/2)+.5, (length/2)+.5, 0x7bbfff);
        drawRect(loc[0], loc[1], (width/2)-1, (length/2)-1, 0xa6baca);
        int counter = 0;
        Japanese printer;
        for (int i = 0; i < 7; i++) {
            if (selected == counter) {
        drawRect(loc[0], (loc[1]+30)-(i*10), (cellLen/2)+1, (cellHigh/2)+1, 0xf0ff00);
        drawRect(loc[0], (loc[1]+30)-(i*10), (cellLen/2), (cellHigh/2)+.2, 0xa6baca);
            }else {
        drawRect(loc[0], (loc[1]+30)-(i*10), (cellLen/2)+1, (cellHigh/2)+1, 0xa6baca);
            }
            for (int j = 0; j<5;j++){
                if (titles[i][j] != 0){
                    if (small[i][j] != true) {
                        printer.printKana(titles[i][j],kanaType[i],(loc[1]+31.5)+(j*4.5),(loc[0]-18.5)-(10*i),.30);

                    }else {
                        printer.printKana(titles[i][j],kanaType[i],(loc[1]+31.5)+(j*4.5)+.75,(loc[0]-18.5)-(10*i)-1,.20);
                    }
                }
            }
        counter++;
        }
    }
};

struct BallCorners {
    int colors[4] = {0,0,0xdf342a, 0xffffff};
    int ball[7][8] = {
        {0,0,0,3,3,0,0,0},
        {0,0,3,1,1,3,0,0},
        {0,3,1,3,2,1,3,0},
        {3,1,2,2,2,2,1,3},
        {0,3,1,3,3,1,3,0},
        {0,0,3,1,1,3,0,0},
        {0,0,0,3,3,0,0,0},
    };
    public:void printBall(float x, float y) {
        float y0 = y + (.5*7);
        for (int i = 0; i < 7; i++) {
            float x0 = x-(.5*7);
            for (int j = 0; j < 8; j++) {
                if (ball[i][j] != 0) {
                    drawRect(x0,y0,.5,.5,colors[ball[i][j]]);
                }
                x0++;
            }
            y0--;
        }
    }
};

struct TextBox
{   int y = -30;
    int width = 15;
    int length = 88;
    BallCorners corners;
    Japanese kana;

    public:void outputText(int script[], bool state[], bool small[], int len, float x, float y) {
        int s = 0;
        float x0 = x;
        for (int i = 0; i < len; i++ ) {
            if (script[i] == -2) {
                s++;
            }else if (script[i] == -1) {
                x0 = x;
                y-= 2*6.5;
                s++;
            }else if (script[i] == 0){
                s++;
                x0+= 4*2.5;
            }else {
                if (small[i]) {
                    kana.printKana(script[i], state[s], x0-1, y-2.25,.5/2);
                    x0+= 2*2;
                }else {
                    kana.printKana(script[i], state[s], x0, y,.5);
                    x0+= 2*4;
                }
                
            }
        }
    }

    public:void displayBox(int script[], bool state[], bool small[], int len) {
        drawRect(0,y,length,width,0);
        drawRect(0,y,length-1,width-1,0xffffff);
        drawRect(0,y,length-2,width-2,0);
        drawRect(0,y,length-3,width-4,0xffffff);
        outputText(script,state, small,len,(-1*length)+7,y+9);
}


};


struct Pokedex
{
    bool open = false;

    public:bool isOpen() {
        return open;
    }
    public:void toggleDex() {
        if (isOpen()) {
            open = false;
        } else {
            open = true;
        }
    }
    public:void displayDex(){
        clearScreen(0);
        drawRect(0,0,47,47,0xffffff);
        drawRect(0,0,46.5,46.5,0);
        drawRect(0,0,46,46,0x9da9bd);
        drawRect(0,0,44,44,0x494f67);
        drawRect(0,0,42,42,0);
        drawRect(0,0,41.75,41.75,0xb5471d);


    }
};

struct Party
{
    bool open = false;
    int name[4] = {13,69,7,70};
    int lv[3] = {1,0,0};
    Japanese kana;
    Alphabet let;
    Numbers nums;
    bool openPage = false;
    int colors [5] = {0,0x670274,0xffffff,0xba3202,0};
    int genar[10][14] = {
        {0,1,1,0,0,1,0,0,1,0,0,1,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,2,4,1,1,4,2,1,1,0,0},
        {0,1,1,1,2,2,1,1,2,2,1,1,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {1,1,1,2,2,3,2,2,3,2,2,1,1,1},
        {1,1,1,1,2,3,2,2,3,2,1,1,1,1},
        {0,1,1,1,1,3,2,2,3,1,1,1,1,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,1,1,0,0,0,0,1,1,0,0,0}

    };

    public:bool isOpen() {
        return open;
    }
    bool isPage() {
        return openPage;
    }
    public:void toggleParty() {
        if (isOpen()) {
            open = false;
        } else {
            open = true;
        }
    }

    public:void togglePage() {
        if (isPage()) {
            openPage = false;
        } else {
            openPage = true;
        }
    }
    public:void displayParty(){
        clearScreen(0);
        drawRect(0,0,47,47,0xffffff);
        drawRect(0,0,46.5,46.5,0);
        drawRect(0,0,46,46,0x9da9bd);
        drawRect(0,0,44,44,0x494f67);
        drawRect(0,0,42,42,0);
        drawRect(0,0,41.75,41.75,0xffffff);
        if(!openPage) {
        drawCell(1);

        }else {
            drawPage();
        }
    }

    void drawCell(int num) {
        drawRect(0,30,40,7,0xffff00);
        drawRect(16,29.7,17,1,0);
        drawRect(-3,29.7,2,1,0xff0000);
        drawRect(14,30,15,.75,0xffffff);
        drawRect(14,30,15,.5,0x00ff00);
        float y = 35;
        for (int i = 0; i <10; i++) {
            float x = -35;
            for (int j = 0; j <14; j++) {
                if (genar[i][j] != 0) {
                    drawRect(x,y,.3,.3,colors[genar[i][j]]);
                }
                x += .45;
            }
            y -= .6;
        }
        for (int i = 0; i < 4; i++) {
            kana.printKana(name[i],false,-20+(i*5),34,.25);
        }
        
    }

    public:void drawPage() {
        clearScreen(0);
        drawRect(0,0,47,47,0xffffff);
        drawRect(0,0,46.5,46.5,0);
        drawRect(0,0,46,46,0x9da9bd);
        drawRect(0,0,44,44,0x494f67);
        drawRect(0,0,42,42,0);
        drawRect(0,0,41.75,41.75,0xffffff);
        
        float y = 35;
        for (int i = 0; i <10; i++) {
            float x = -35;
            for (int j = 0; j <14; j++) {
                if (genar[i][j] != 0) {
                    drawRect(x,y,1,1,colors[genar[i][j]]);
                }
                x += 1.5;
            }
            y -= 2;
        }
    }

};

