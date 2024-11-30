// #include "renderer.cpp"
struct Player
{
    public:float xPOS;
    public:float yPOS;
    int pxSize = 5;
    public:int color = 0xff0000;

    void drawPlayer() {
        drawRect(xPOS,yPOS,pxSize,pxSize,color);
    }

    public:void setXpos(float x) {
        xPOS = x;
    }
    public:void setYpos(float y) {
        yPOS = y;
    }
    float getX() {
        return xPOS;
    }
    float getY() {
        return yPOS;
    }
};

struct Alphabet
{
    int colors[2] = {0,0x000000};
    int alphabet[26][7][5]=
                 {{{0,1,1,1,0},//A
                   {1,1,1,1,1},
                   {1,0,0,0,1},
                   {1,1,1,1,1},
                   {1,1,1,1,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1}
                   },
                  {{1,1,1,1,0},//B
                   {1,0,0,1,1},
                   {1,0,0,1,1},
                   {1,1,1,1,0},
                   {1,0,0,1,1},
                   {1,0,0,1,1},
                   {1,1,1,1,0}
                   },
                  {{0,1,1,1,0},//C
                   {1,1,0,1,1},
                   {1,0,0,0,0},
                   {1,0,0,0,0},
                   {1,0,0,0,1},
                   {1,1,0,1,1},
                   {0,1,1,1,0}
                   },
                  {{1,1,1,1,0},//D
                   {1,1,0,1,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,1,0,1,1},
                   {1,1,1,1,0}
                   },
                  {{1,1,1,1,1},//E
                   {1,1,1,1,1},
                   {1,0,0,0,0},
                   {1,1,1,1,1},
                   {1,0,0,0,0},
                   {1,1,1,1,1},
                   {1,1,1,1,1}
                   },
                  {{1,1,1,1,1},//F
                   {1,1,1,1,1},
                   {1,1,0,0,0},
                   {1,1,1,1,1},
                   {1,1,0,0,0},
                   {1,1,0,0,0},
                   {1,1,0,0,0}
                   },
                  {{0,1,1,1,0},//G
                   {1,0,0,1,1},
                   {1,0,0,0,0},
                   {1,0,1,1,1},
                   {1,0,0,1,1},
                   {1,0,0,1,1},
                   {0,1,1,0,0},
                   },
                  {{1,0,0,0,1},//H
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,0,1,1,1},
                   {1,1,1,1,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   },
                  {{1,1,1,1,1},//I
                   {1,1,1,1,1},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {1,1,1,1,1},
                   {1,1,1,1,1}
                   },
                  {{1,1,1,1,1},//J
                   {1,1,1,1,1},
                   {0,0,0,1,0},
                   {0,0,0,1,1},
                   {1,1,0,1,1},
                   {1,1,0,1,1},
                   {1,1,1,1,1}
                   },
                  {{1,1,0,0,1},//K
                   {1,1,0,1,0},
                   {1,1,1,0,0},
                   {1,1,0,0,0},
                   {1,1,1,0,0},
                   {1,1,0,1,0},
                   {1,1,0,1,1}
                   },
                  {{1,0,0,0,0},//L
                   {1,0,0,0,0},
                   {1,0,0,0,0},
                   {1,0,0,0,0},
                   {1,0,0,0,0},
                   {1,1,1,1,1},
                   {1,1,1,1,1}
                   },
                  {{1,0,0,0,1},//M
                   {1,1,0,1,1},
                   {1,1,1,1,1},
                   {1,0,1,0,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1}
                   },
                  {{1,0,0,0,1},//N
                   {1,1,0,0,1},
                   {1,1,0,0,1},
                   {1,0,1,0,1},
                   {1,0,1,1,1},
                   {1,0,0,1,1},
                   {1,0,0,0,1}
                   },
                  {{0,1,1,1,0},//O
                   {1,1,1,1,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,1,1,1,1},
                   {0,1,1,1,0}
                   },
                  {{1,1,1,1,0},//P
                   {1,0,0,1,1},
                   {1,0,0,1,1},
                   {1,1,1,1,0},
                   {1,0,0,0,0},
                   {1,0,0,0,0},
                   {1,0,0,0,0},
                   },
                  {{0,1,1,1,0},//Q
                   {1,1,1,1,1},
                   {1,0,0,0,1},
                   {1,1,0,0,1},
                   {1,0,1,0,1},
                   {1,1,1,1,0},
                   {0,1,1,0,1}
                   },
                  {{1,1,1,0,0},//R
                   {1,0,0,1,1},
                   {1,0,0,1,1},
                   {1,1,1,0,0},
                   {1,0,1,0,0},
                   {1,0,0,1,0},
                   {1,0,0,0,1},
                   },
                  {{0,1,1,1,0},//S
                   {1,1,0,1,1},
                   {1,1,0,0,0},
                   {0,1,1,0,0},
                   {0,0,1,1,1},
                   {1,0,0,1,1},
                   {1,1,1,1,0}
                   },
                  {{1,1,1,1,1},//T
                   {1,1,1,1,1},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   },
                  {{1,0,0,0,1},//U
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,1,1,1,1},
                   {0,1,1,1,0}
                   },
                  {{1,1,0,1,1},//V
                   {1,1,0,1,1},
                   {1,1,0,1,1},
                   {1,1,0,1,1},
                   {1,1,0,1,1},
                   {0,1,1,1,0},
                   {0,0,1,0,0}
                   },
                  {{1,0,0,0,1},//W
                   {1,0,0,0,1},
                   {1,0,0,0,1},
                   {1,0,1,0,1},
                   {1,1,1,1,1},
                   {1,1,0,1,1},
                   {1,0,0,0,1}
                   },
                  {{1,0,0,0,1},//X
                   {0,1,0,1,0},
                   {0,1,1,1,0},
                   {0,0,1,0,0},
                   {0,1,1,1,0},
                   {0,1,0,1,0},
                   {1,0,0,0,1},
                   },
                  {{1,0,0,0,1},//Y
                   {0,1,1,1,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   },
                  {{1,1,1,1,1},//Z
                   {1,1,1,1,1},
                   {0,1,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,1,1},
                   {1,1,1,1,1},
                   {0,0,1,1,1},
                   }
                   };

    void printLetter(int choice, float x, float y, float pxSize) {
        switch (choice)
        {
        case 0:

            drawLetter(alphabet[0],colors, 7,5,x,y,pxSize);
            break;
        case 1:

            drawLetter(alphabet[1],colors, 7,5,x,y,pxSize);
            break;
        case 2:

            drawLetter(alphabet[2],colors, 7,5,x,y,pxSize);
            break;
        case 3:
            drawLetter(alphabet[3],colors, 7,5,x,y,pxSize);

            break;
        case 4:
            drawLetter(alphabet[4],colors, 7,5,x,y,pxSize);

            break;
        case 5:
            drawLetter(alphabet[5],colors, 7,5,x,y,pxSize);

            break;
        case 6:
            drawLetter(alphabet[6],colors, 7,5,x,y,pxSize);

            break;
        case 7:
            drawLetter(alphabet[7],colors, 7,5,x,y,pxSize);

            break;
        case 8:
            drawLetter(alphabet[8],colors, 7,5,x,y,pxSize);

            break;
        case 9:
            drawLetter(alphabet[9],colors, 7,5,x,y,pxSize);

            break;
        case 10:
            drawLetter(alphabet[10],colors, 7,5,x,y,pxSize);

            break;
        case 11:
            drawLetter(alphabet[11],colors, 7,5,x,y,pxSize);

            break;
        case 12:
            drawLetter(alphabet[12],colors, 7,5,x,y,pxSize);

            break;
        case 13:
            drawLetter(alphabet[13],colors, 7,5,x,y,pxSize);

            break;
        case 14:
            drawLetter(alphabet[14],colors, 7,5,x,y,pxSize);

            break;
        case 15:
            drawLetter(alphabet[15],colors, 7,5,x,y,pxSize);

            break;
        case 16:
            drawLetter(alphabet[16],colors, 7,5,x,y,pxSize);

            break;
        case 17:
            drawLetter(alphabet[17],colors, 7,5,x,y,pxSize);

            break;
        case 18:
            drawLetter(alphabet[18],colors, 7,5,x,y,pxSize);

            break;
        case 19:
            drawLetter(alphabet[19],colors, 7,5,x,y,pxSize);

            break;
        case 20:
            drawLetter(alphabet[20],colors, 7,5,x,y,pxSize);

            break;
        case 21:
            drawLetter(alphabet[21],colors, 7,5,x,y,pxSize);

            break;
        case 22:
            drawLetter(alphabet[22],colors, 7,5,x,y,pxSize);

            break;
        case 23:
            drawLetter(alphabet[23],colors, 7,5,x,y,pxSize);

            break;
        case 24:
            drawLetter(alphabet[24],colors, 7,5,x,y,pxSize);

            break;
        case 25:
            drawLetter(alphabet[25],colors, 7,5,x,y,pxSize);

            break;
        default:
            break;
        }
    }

};
