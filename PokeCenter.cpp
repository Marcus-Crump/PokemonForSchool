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

    public:void printTile(float x, float y, float px) {
        // float y0 = y;
    for (int i = 0; i < 16; i++){
        float x0 = x;
        for (int j = 0; j < 16; j++) {
            drawRect(x0,y,px/2,px/2,colors[tile[i][j]]);
            x0+= px;

        }
        y += px;
    }
    }
};

struct doormat
{
    /* data */
};

struct chair
{
    /* data */
};

struct pokePC
{
    /* data */
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

struct chairsBoy
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

