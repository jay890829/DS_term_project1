#include <bits/stdc++.h>
#ifndef _blocks
#define _blocks

using namespace std;
class tetris;
class Blocks
{
private:
    int central_r,central_c;
    string block_type;
    int block_table[4][4];
    tetris* t;
public:
    Blocks(int c,string type,tetris* tt);
    void fall();
    bool valid();
    void put_to_tetris_table();
};


#endif // _blocks
