struct floorTiles
{
    int colors[3] = {0,0xff9ed3,0xffffff};
    // float px = 1;
    int tile[16][16] = {
        {2,1,1,1,1,1,1,2,2,1,1,1,1,1,1,2},
        {1,2,1,1,1,1,2,1,1,2,1,1,1,1,2,1},
        {1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1},
        {1,1,1,2,2,1,1,1,1,1,1,2,2,1,1,1},
        {1,1,1,2,2,1,1,1,1,1,1,2,2,1,1,1},
        {1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1},
        {1,2,1,1,1,1,2,1,1,2,1,1,1,1,2,1},
        {2,1,1,1,1,1,1,2,2,1,1,1,1,1,1,2},
        {2,1,1,1,1,1,1,2,2,1,1,1,1,1,1,2},
        {1,2,1,1,1,1,2,1,1,2,1,1,1,1,2,1},
        {1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1},
        {1,1,1,2,2,1,1,1,1,1,1,2,2,1,1,1},
        {1,1,1,2,2,1,1,1,1,1,1,2,2,1,1,1},
        {1,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1},
        {1,2,1,1,1,1,2,1,1,2,1,1,1,1,2,1},
        {2,1,1,1,1,1,1,2,2,1,1,1,1,1,1,2},
    };

    void printTile(float x, float y, float px,int c[]) {
        float y0 = y;
    for (int i = 0; i < 16; i++){
        float x0 = x;
        for (int j = 0; j < 16; j++) {
            drawRect(x0,y,px/2,px/2,c[tile[i][j]]);
            x0+= px;

        }
        y += px;
    }

    }

    public:void printFloor() {
        for (int y = 34; y > (-16)*8; y-=16) {
            for (float x = -113.5; x <(16)*12; x +=16) {
                printTile(x,y-.5,1,colors);
            }
        }
    }

    public:void printShadowFloor(float y0, float x0, float tileNum) {
        int shadowColors[3] = {0,0xf33a25,0xff8eaa};
            for (float x = x0; x <x0+(16)*tileNum; x +=16) {
                printTile(x,y0-.5,1,shadowColors);
            }

    }
};

struct doormat//l = 32, w = 12
{
    int colors[3] = {0xff001f,0xff9ed3,0xffffff};
    int pattern[15] = {2,0,1,0,0,0,0,0,0,0,0,0,1,0,2};

    public:void makeCarpet(float x, float y) {
        float x0 = x - 16;
        float y0 = y + (15/2);
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 15; j++) {
                drawRect(x0+i,y0-j,.5,.5,colors[pattern[j]]);
            }
        }
    }
};

struct chair//16x16
{//0xd3b01b
    int colors[4] = {0,0xffff63,0xf37f10,0x392e10};
    int chair [16][16] = {
        {0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0},
        {0,3,2,1,1,1,1,1,1,1,1,1,1,2,3,0},
        {3,2,1,1,1,1,1,1,1,1,1,1,1,1,2,3},
        {3,2,1,1,1,1,1,1,1,1,1,1,1,1,2,3},
        {3,2,1,1,1,1,1,1,2,1,1,1,1,1,2,3},
        {3,2,1,1,1,1,2,2,2,2,1,1,1,1,2,3},
        {3,2,1,1,1,1,1,2,1,1,1,1,1,1,2,3},
        {3,2,1,1,1,1,1,1,1,1,1,1,1,1,2,3},
        {3,2,1,1,1,1,1,1,1,1,1,1,1,1,2,3},
        {3,2,2,1,1,1,1,1,1,1,1,1,1,2,2,3},
        {3,2,2,2,1,1,1,1,1,1,1,1,2,2,2,3},
        {3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
        {3,3,2,2,2,3,3,3,3,3,3,2,2,2,3,3},
        {3,1,3,3,3,2,3,3,3,3,2,3,3,3,2,3},
        {0,3,1,2,2,3,3,3,3,3,3,2,2,2,3,0},
        {0,0,3,3,3,0,0,0,0,0,0,3,3,3,0,0}
    };

    public:void printChair(float y, float x) {
        float y0 = y;
        for (int i=0; i<16; i++) {
            float x0 = x;
            for (int j =0; j<16; j++) {
                if (chair[i][j] != 0){
                drawRect(x0,y0,.4,.4,colors[chair[i][j]]);
                }
                x0 += .8;
            }
        y0 -= .8;
        }
    }
};

struct pokePC
{                    //black   shading  pc color  grey      dark shading
    int colors[5] = {0x343233, 0x9e9d98, 0xf9f3e7, 0x646d68, 0x676566};

    int pc[24][15] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,4,4,4,4,4,4,4,4,4,0,0,0},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,0,0},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,0,0},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,2,1,0,2,2,0,0,0,0,0,0,1,4,0},
        {0,2,1,0,2,0,0,0,0,0,0,0,1,4,0},
        {0,2,1,0,0,0,0,0,0,0,0,0,1,4,0},
        {0,2,1,1,1,1,1,1,1,1,1,1,1,4,0},
        {0,2,0,0,4,4,4,4,4,4,4,0,0,4,0},
        {0,2,0,3,2,3,2,3,3,3,3,3,0,4,0},
        {0,2,0,3,3,3,3,3,0,3,0,3,0,1,0},
        {0,2,2,0,0,0,0,0,0,0,0,0,2,2,0},
        {0,2,0,4,0,4,0,4,0,4,3,3,0,2,0},
        {0,2,0,1,1,1,4,1,4,1,4,1,0,2,0},
        {0,2,0,4,2,2,4,2,2,2,2,3,0,1,0},
        {0,1,1,0,4,4,4,4,4,4,4,0,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,4,4,4,0,4,0,0,0,0,0,4,4,4,0},
        {0,4,4,4,0,4,4,4,4,4,0,4,4,4,0},
        {0,4,0,3,4,0,4,4,4,0,4,0,3,4,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    public:void printPC() {
        float y0 = 44.5;
        for (int i = 0; i <24; i++) {
            float x0 = 82.5;
            for (int j = 0; j <15; j++) {
                drawRect(x0,y0,.5,.5,colors[pc[i][j]]);
                x0++;
            }
            y0--;
        }
    }

};

struct stairs
{
    /* data */
};

struct nurseJoy
{                 //  black      peach     red       mouth
    int colors[5] = {0,0x050412, 0xeda776, 0xdd3741, 0xd47255};
    int nurseJoy[16][14] = {
        {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
        {0,0,1,2,2,2,1,1,2,2,2,1,0,0},
        {0,0,1,2,2,1,1,1,1,2,2,1,0,0},
        {0,0,1,2,2,1,1,1,1,2,2,1,0,0},
        {0,0,1,1,2,2,1,1,2,2,1,1,0,0},
        {0,1,3,1,1,1,1,1,1,1,1,3,1,0},
        {0,1,1,2,2,1,2,2,1,2,2,1,1,0},
        {0,1,1,2,2,1,2,2,1,2,2,1,1,0},
        {1,3,3,1,2,2,4,4,2,2,1,3,3,1},
        {1,3,3,3,1,1,1,1,1,1,3,3,3,1},
        {1,3,3,1,2,1,1,1,1,2,1,3,3,1},
        {0,1,1,2,1,2,2,2,2,1,2,1,1,0},
        {0,0,1,1,2,2,2,2,2,2,1,1,0,0},
        {0,0,0,1,1,2,2,2,2,1,1,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,1,1,1,1,0,0,0,0,0}
    };

    public:void printNurseJoy(float x, float y) {
        for (int i = 0; i < 16; i++) {
            float x0 = x;
            for (int j = 0; j < 14; j ++) {
                if (nurseJoy[i][j] != 0) {
                    drawRect(x0,y,.5,.5,colors[nurseJoy[i][j]]);
                }
                x0++;
            }
            y--;
        }
    }
};

struct PCboy
{                   //  black    skin      red       mouth      white
    int colors[6] = {0, 0x000000, 0xec8b78, 0xdf342a, 0xd47255, 0xffffff};
    int sprite[2][16][14] = {
        {
                {0,0,0,0,0,1,1,1,1,0,0,0,0,0},
                {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
                {0,0,1,1,1,1,1,1,1,1,1,1,0,0},
                {0,0,1,1,1,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,1,1,1,1,1,1,1,0},
                {0,1,1,1,1,1,2,2,1,1,1,1,1,1},
                {1,2,1,2,1,2,2,2,2,1,2,1,2,1},
                {1,2,2,2,2,1,2,2,1,2,2,2,2,1},
                {1,1,2,2,2,1,2,2,1,2,2,2,1,1},
                {0,1,1,2,2,2,4,4,2,2,2,1,1,0},
                {1,2,2,1,1,1,1,1,1,1,1,2,2,1},
                {1,2,2,1,3,4,4,4,4,3,1,2,2,1},
                {0,1,1,3,3,3,3,3,3,3,3,1,1,0},
                {0,0,1,1,1,1,1,1,1,1,1,1,0,0},
                {0,1,5,1,1,1,1,1,1,1,1,5,1,0},
                {0,1,1,1,1,1,0,0,1,1,1,1,1,0},
            },
            {
            {0,0,0,0,0,1,1,1,1,1,1,0,0,0},
            {0,0,0,0,1,1,1,1,1,1,1,1,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,1,1,0},
            {0,0,0,1,1,1,1,1,1,1,1,1,1,1},
            {0,0,0,1,1,1,1,1,1,1,1,1,1,1},
            {0,0,0,1,1,1,1,1,1,1,1,1,1,1},
            {0,0,0,3,3,3,3,3,3,2,3,2,1,1},
            {0,0,0,3,3,2,2,3,2,2,3,2,3,0},
            {0,0,0,0,3,2,2,2,2,2,2,2,3,0},
            {0,0,0,3,1,3,3,2,2,2,1,3,0,0},
            {0,0,0,3,1,1,3,3,3,3,3,0,0,0},
            {0,0,0,3,1,3,2,2,3,3,0,0,0,0},
            {0,0,0,3,1,3,2,2,3,3,0,0,0,0},
            {0,0,0,0,3,3,3,3,1,1,3,0,0,0},
            {0,0,0,0,0,3,1,1,1,1,3,0,0,0},
            {0,0,0,0,0,0,3,3,3,3,0,0,0,0},
        },
        // {
        //     {0,0,0,0,0,3,3,3,3,3,3,0,0,0},
        //     {0,0,0,0,3,1,1,1,1,1,1,3,0,0},
        //     {0,0,0,3,1,1,1,1,1,1,1,1,3,0},
        //     {0,3,3,4,1,1,1,1,1,1,1,1,3,0},
        //     {3,4,4,4,1,1,1,1,1,1,1,3,3,0},
        //     {0,3,3,3,3,3,3,3,1,1,1,1,3,0},
        //     {0,0,0,3,3,3,3,3,3,2,3,2,3,0},
        //     {0,0,0,3,3,2,2,3,2,2,3,2,3,0},
        //     {0,0,0,0,3,2,2,2,2,2,2,2,3,0},
        //     {0,0,0,3,1,3,3,2,2,2,1,3,0,0},
        //     {0,0,0,3,1,1,3,3,3,3,3,0,0,0},
        //     {0,0,0,3,1,3,2,2,3,3,0,0,0,0},
        //     {0,0,0,3,1,3,2,2,3,3,0,0,0,0},
        //     {0,0,0,0,3,3,3,3,1,1,3,0,0,0},
        //     {0,0,0,0,0,3,1,1,1,1,3,0,0,0},
        //     {0,0,0,0,0,0,3,3,3,3,0,0,0,0},
        // },
    };

    public:void printBoySprite(float x, float y, int state) {
        for (int i = 0; i < 16; i++) {
            float x0 = x;
            for (int j = 0; j < 14; j++) {
                if (sprite[state][i][j] != 0) {
                drawRect(x0,y,.5,.5,colors[sprite[state][i][j]]);
                }
                x0++;
            }
            y--;
        }
    }
};

struct chairBoy
{
    /* data */
};

struct hatman
{
    /* data */
};


struct backWall
{
    int colors[2] = {0x6d6d6d,0x2c2c2c};
    public:void printWall() {
        int y0 = 50;
        for (int i = 0; i <16; i++) {
            drawRect(0,y0,100,.5,colors[i%2]);
            y0 -= 1;
    }
    }
};

struct bowlThing
{                        //white   black    grey
    int colors[4]  = {0,0xfff3ea,0x30261c,0x7e727c};
    int bowl[6][7] = {
        {0,0,2,2,2,0,0},
        {0,2,2,1,2,2,0},
        {2,1,2,2,2,1,2},
        {2,3,1,1,1,3,2},
        {0,2,3,3,3,2,0},
        {0,0,2,2,2,0,0}
    };

    void drawBowl(float x0, float y) {
        for (int i=0; i < 6; i++) {
            float x = x0;
            for (int j=0; j<7; j++) {
                if (colors[bowl[i][j]] != 0) {
                drawRect(x,y,.5,.5,colors[bowl[i][j]]);
                }
                x++;
            }
            y--;
        }
    }
    public:void printBowls() {
        for (int i = 0; i < 3; i++) {
            float x = 0;
            switch (i)
            {
            case 0:
                x = -63;
                break;
            case 1:
                x = -55;
                break;
            case 2:
                x = -2.5;
                break;
            default:
                break;
            }
            drawBowl(x,16);
        }
    }
};

struct deskFront//len 80
{                   //black    white     grey    blue   dark blue
    int colors[5] = {0x37322f,0xfcf3e2,0x827a77,0x4c35ff,0x5d4e8f};
    int pattern[15] = {0,2,1,1,1,1,1,1,4,1,3,3,3,3,0};



    public:void printDesk() {
    int y0 = 50 -(16*2);
    for (int i = 0; i < 15; i++)  {
        drawRect(-50,y0,55,.5,colors[pattern[i]]);
        y0--;
    };
    }


};

struct DeskSide
{                   //black    white     grey    blue   dark blue  light blue
    int colors[6] = {0x37322f,0xfcf3e2,0x827a77,0x4c35ff,0x5d4e8f, 0x897dff};
    int sideDesk[42][18] = {
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,9,9,9,9,9,9,0,4,1,1,1,1,1,1,1,5},
        {9,9,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,5},
        {9,0,2,1,1,1,4,1,1,4,4,4,4,1,1,1,1,5},
        {0,2,1,1,1,4,1,1,1,1,1,1,1,4,4,1,1,5},
        {0,2,1,1,4,5,5,1,1,1,1,1,1,1,1,4,1,5},
        {0,2,1,4,4,1,1,5,5,1,1,1,1,1,5,5,4,5},
        {0,2,1,4,3,0,1,1,1,5,5,1,1,1,5,5,4,5},
        {0,2,1,4,3,0,0,0,1,1,1,5,5,5,5,5,4,5},
        {0,2,1,4,3,0,0,0,0,0,1,1,5,3,5,5,4,5},
        {0,2,1,4,3,0,0,0,0,0,0,0,5,3,5,5,4,5},
        {0,2,1,4,3,0,0,0,0,0,1,0,5,3,5,5,4,5},
        {0,2,1,4,3,3,0,0,0,0,0,0,5,3,5,5,4,5},
        {0,2,1,4,3,3,3,3,0,0,0,0,5,3,5,5,4,5},
        {0,2,1,4,3,3,3,3,3,3,0,0,5,3,5,5,4,5},
        {0,2,1,4,3,3,3,3,3,3,3,3,5,3,5,5,4,5},
        {0,2,1,2,4,3,3,3,3,3,3,3,5,3,5,4,1,5},
        {0,2,1,2,2,2,4,4,3,3,3,3,5,3,4,2,1,5},
        {0,2,1,1,1,2,2,2,4,4,3,3,5,4,2,1,1,5},
        {0,2,1,1,1,1,1,2,2,2,4,4,4,2,1,1,1,5},
        {0,2,1,1,1,1,1,1,1,2,2,2,2,1,1,1,5,0},
        {0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,4,0},
        {0,4,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
        {0,1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5,0},
        {0,1,1,1,1,5,1,5,5,5,5,5,5,5,5,5,5,0},
        {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0},
        {0,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
        {0,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
        {0,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
        {0,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
        {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    public:void drawDeskSide(float x, float y) {
        for (int i = 0; i < 42; i++) {
            float x0 = x;
            for (int j = 0; j < 18; j++) {
                if (sideDesk[i][j] < 6) {
                    drawRect(x0,y,.5,.5,colors[sideDesk[i][j]]);
                }
                x0++;
            }
            y--;
        }
    }

};

struct PokeHealer
{                  //   black     gray     light gray  white     green    lightgrn  darkgrn  darkestgrn   red     navy
    int colors[11] = {0,0x25211e, 0x73726e, 0xa6a2a1, 0xfbf5f5, 0x86a142, 0xaacf66, 0x46640e, 0x213414, 0xdf342a, 0x302c3a};
    int n = 10;
    int pokeHealer[35][32] = {
        {1,1,1,1,1,1,1,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,1,1,1,1,1,1,1},
        {1,2,2,2,2,2,2,8,8,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,8,2,2,2,2,2,2,1},
        {1,2,2,2,2,2,2,8,8,5,5,5,5,5,5,5,5,5,5,5,5,5,5,8,8,2,2,2,2,2,2,1},
        {1,2,2,1,1,1,1,3,8,5,8,8,8,8,8,8,8,8,8,8,8,8,5,8,3,1,1,1,1,2,2,1},
        {1,2,1,4,2,4,2,4,8,5,8,7,7,6,7,7,7,7,6,7,7,8,5,8,4,2,4,2,4,1,2,1},
        {1,1,1,4,2,4,2,4,8,5,8,7,6,7,6,6,6,6,7,7,7,8,5,8,4,2,4,2,4,1,1,1},
        {1,1,4,2,1,1,1,3,8,5,8,8,8,8,8,8,8,8,8,8,8,8,5,8,3,1,1,1,2,4,1,1},
        {1,1,4,3,1,1,2,1,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,1,2,1,1,3,4,1,1},
        {2,1,2,1,2,1,1,1,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,1,1,1,2,1,2,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,1,1,2,1,1,1,2,2},
        {2,2,2,1,1,1,2,2,2,1,2,2,3,3,4,4,4,4,3,3,2,2,1,2,2,2,1,1,1,2,2,2},
        {2,2,1,2,4,4,3,3,1,2,n,n,n,3,3,3,3,3,3,n,n,n,2,1,3,3,4,4,2,1,2,2},
        {2,1,3,3,4,4,1,1,1,1,n,n,n,1,1,1,1,1,1,n,n,n,1,1,1,1,4,4,3,2,1,2},
        {1,2,3,3,4,4,1,4,1,1,n,n,n,1,1,1,1,1,1,n,n,n,1,1,4,1,4,4,3,3,2,1},
        {1,2,3,3,4,4,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,4,4,3,3,2,1},
        {1,2,3,3,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,3,3,2,1},
        {1,2,3,3,4,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,4,4,3,3,2,1},
        {1,2,3,3,4,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,4,4,3,3,2,1},
        {1,2,3,3,4,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,4,4,3,3,2,1},
        {1,2,3,3,4,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,4,4,3,3,2,1},
        {1,2,3,3,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,3,3,2,1},
        {1,2,3,3,4,4,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,4,4,3,3,2,1},
        {1,2,3,3,4,4,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,4,4,3,3,2,1},
        {1,2,3,3,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,3,3,2,1},
        {1,2,3,3,4,4,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,4,4,3,3,2,1},
        {1,2,3,3,3,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,3,3,3,2,1},
        {1,2,3,3,3,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,3,3,3,2,1},
        {1,2,2,1,1,1,1,1,4,4,4,1,4,4,4,9,9,4,4,4,1,4,4,4,1,1,1,1,1,2,2,1},
        {1,2,1,1,1,1,4,4,4,4,4,1,4,9,9,9,9,9,9,4,1,4,4,4,4,4,1,1,1,1,2,1},
        {1,2,1,1,1,4,4,4,4,4,4,1,4,9,9,9,9,9,9,4,1,4,4,4,4,4,4,1,1,1,2,1},
        {2,1,1,1,4,1,1,1,4,4,4,1,4,9,9,9,9,9,9,4,1,4,4,4,1,1,1,4,1,1,1,2},
        {2,2,1,4,4,1,1,1,4,4,4,1,4,4,4,9,9,4,4,4,1,4,4,4,1,1,1,4,4,1,2,2},
        {2,2,1,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,4,4,4,1,2,2},
        {2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    public:void printPokeHealer(float x, float y) {

        for (int i = 0; i < 35; i++) {
            float x0 = x;
            for (int j = 0; j < 32; j++) {
                if (pokeHealer[i][j] != 0) {
                    drawRect(x0,y,.5,.5,colors[pokeHealer[i][j]]);

                }
                x0++;
            }
             y--;
        }
    }
};

struct PokehealerPC
{                // Dark Blue   blue     white     black     gray     light gray  light blue
    int colors[8] {0, 0x2a1f85,0x544ac4 , 0xfbf5f5, 0x25211e, 0x73726e, 0xa6a2a1, 0x7f73fb};
    int rightSidePokehealer[32][16] = {
        {0,0,3,2,1,4,4,4,4,1,2,7,2,1,0,0},
        {0,2,3,1,1,1,3,3,3,7,7,1,1,3,2,0},
        {1,7,1,7,3,7,7,7,7,7,7,7,7,1,3,1},
        {1,2,7,3,7,7,7,7,7,7,7,7,7,7,2,1},
        {1,2,7,7,7,7,7,7,7,7,7,7,7,7,2,1},
        {1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1},
        {1,2,1,7,7,7,7,7,3,3,3,7,3,1,2,1},
        {1,2,1,7,7,7,7,3,3,3,7,3,7,1,2,1},
        {1,2,1,7,7,7,3,3,3,7,3,7,7,1,2,1},
        {1,2,1,7,7,3,3,3,7,3,7,7,7,1,2,1},
        {1,2,1,7,3,3,3,7,3,7,7,7,7,1,2,1},
        {1,2,1,3,3,3,7,3,7,7,7,7,7,1,2,1},
        {1,2,2,1,1,1,1,1,1,1,1,1,1,2,2,1},
        {1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
        {4,4,1,1,1,1,1,1,1,1,1,1,1,1,4,4},
        {4,5,4,4,4,4,4,4,4,4,5,4,4,4,5,4},
        {4,5,4,3,3,3,3,3,4,5,5,3,5,3,5,4},
        {4,5,4,3,3,3,3,3,4,5,5,5,5,5,5,4},
        {4,5,4,3,3,3,3,3,4,5,5,3,5,3,5,4},
        {4,5,4,3,3,3,3,3,4,5,5,5,5,3,5,4},
        {4,5,4,3,3,3,3,3,4,5,5,3,5,3,5,4},
        {4,5,4,3,3,3,3,3,4,5,5,5,5,3,5,4},
        {4,4,4,3,3,3,3,3,4,5,5,3,5,5,5,4},
        {4,4,4,4,4,4,4,4,4,5,5,3,3,3,5,4},
        {4,5,4,6,4,3,5,4,4,4,4,4,4,4,4,4},
        {4,5,4,6,6,6,6,6,6,6,6,6,6,6,6,4},
        {4,5,4,5,5,5,5,5,5,5,5,5,5,5,5,4},
        {4,5,4,6,6,6,6,6,6,6,6,6,6,6,6,4},
        {4,5,4,5,5,5,5,5,5,5,5,5,5,5,5,4},
        {4,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4},
        {4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4},
        {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
    };

    public:void printPokeHealerRight(float x, float y) {

        for (int i = 0; i < 32; i++) {
            float x0 = x;
            for (int j = 0; j < 16; j++) {
                if (rightSidePokehealer[i][j] != 0) {
                    drawRect(x0,y,.5,.5,colors[rightSidePokehealer[i][j]]);

                }
                x0++;
            }
             y--;
        }
    }
};

