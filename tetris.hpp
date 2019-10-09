#include <bits/stdc++.h>
#ifndef _tetris
#define _tetris

using namespace std;
class Blocks;

class tetris
{
friend class Blocks;
private:
    int** table;
    int r,c;
public:
    tetris(int r,int c);
    void run();
    void generate_block(string block_type,int column);
    void eliminate();
    void print();
    void fall_after_elimination(int c);
    bool failure_checking();
};

#endif //_tetris
