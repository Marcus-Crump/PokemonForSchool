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
    bool open = false;
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

        int titles[][4] ={{21,6,63,0},{}};
        std::string tags[7] = {"pokedex","pokemon","bag","player","save","settings","exit"};
        int kanaType [] = {true,false,false,false,false,true,true};
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
        if (i != 0) {
        Text line(tags[counter],loc[0]-20, (loc[1]+31.5)-(i*10),.2);
        }else {
            for (int j = 0; j<4;j++){
        printer.printKana(titles[0][j],kanaType[0],(loc[1]+31.5)+(j*4.2),loc[0]-18.5,.30);
            }
        }
        counter++;
        }
    }
};

struct PokemonParty
{
    int size;
    std::string names[6] = {};


};

