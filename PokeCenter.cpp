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

    void printTile(float x, float y, float px) {
        float y0 = y;
    for (int i = 0; i < 16; i++){
        float x0 = x;
        for (int j = 0; j < 16; j++) {
            drawRect(x0,y,px/2,px/2,colors[tile[i][j]]);
            x0+= px;

        }
        y += px;
    }
    }

    public:void printFloor() {
        for (int y = 35; y > (-16)*7; y-=16) {
            for (int x = -95; x <(16)*11; x +=16) {
                printTile(x,y-.5,1);
            }
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
{                    //black   shading  pc color  grey
    int colors[4] = {0x343233, 0x666261, 0xf9f3e7, 0x646d68};
    
};

struct stairs
{
    /* data */
};

struct nurseJoy
{
    /* data */
};

struct PCboy
{
    /* data */
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
{
    /* data */
};

struct deskPC
{
    /* data */
};

struct deskFront
{
    /* data */
};

struct DeskSide
{
    /* data */
};

struct PokeHealer
{
    /* data */
};

struct PokehealerPC
{
    /* data */
};

