#include <bits/stdc++.h>
#include "blocks.hpp"
#include "tetris.hpp"
using namespace std;

fstream input;
fstream output;
int main()
{

    input.open("tetris.data",ios::in);
    output.open("tetris.final",ios::out);
    int r,c;
    input >> r >> c;
    tetris t(r,c);
    t.run();
}
