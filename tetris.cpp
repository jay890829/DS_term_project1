#include <bits/stdc++.h>
#include "tetris.hpp"
#include "Blocks.hpp"
using namespace std;

tetris::tetris(int r,int c)
{
    this->r=r;
    this->c=c;
    int* _table = new int[(r+4)*c];
    table = new int*[r+4];
    for (int i=0;i<r+4;i++)
        table[i]=&_table[c*i];
    for (int i=0;i<r+4;i++)
    {
        for (int j=0;j<c;j++)
            table[i][j]=0;
    }
}

void tetris::run()
{
    extern fstream input;
    extern fstream output;
    string block_type="Start";
    int column;
    bool failure=0;
    while (!failure)
    {
        input >> block_type;
        if (block_type=="End")
            break;
        input >> column;
        generate_block(block_type,column-1);
        eliminate();
        failure = failure_checking();
        /*if (failure)
            output << "Lose!!\n";*/
    }
    for (int i=4;i<r+4;i++)
    {
        for (int j=0;j<c;j++)
            output << table[i][j];
        output << '\n';
    }
}

void tetris::generate_block(string block_type,int column)
{
    Blocks* b = new Blocks(column,block_type,this);
    b->fall();
    delete b;
}


void tetris::eliminate()
{
    int n=0;
    for (int i=4;i<r+4;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (table[i][j]==1)
                n++;
        }
        if (n==c)
        {
            for (int j=0;j<c;j++)
                table[i][j]=0;
            fall_after_elimination(i);
            i--;
        }
        n=0;
    }
}

void tetris::print()
{
    for (int i=4;i<r+4;i++)
    {
        for (int j=0;j<c;j++)
            cout << table[i][j];
        cout << '\n';
    }
}

void tetris::fall_after_elimination(int r)
{
    int* _new_table = new int[(this->r+4)*c];
    int** new_table = new int*[this->r+4];
    for (int i=0;i<this->r+4;i++)
        new_table[i] = &_new_table[i*c];
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<c;j++)
        {
            new_table[i][j]=0;
        }
    }
    for (int i=this->r+3;i>=r+1;i--)
    {
        for (int j=0;j<c;j++)
            new_table[i][j]=table[i][j];
    }
    for (int i=r;i>3;i--)
    {
        for (int j=0;j<c;j++)
        {
            new_table[i][j]=table[i-1][j];
        }
    }
    delete [] table;
    table=new_table;
}

bool tetris::failure_checking()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (table[i][j]==1)
                return 1;
        }
    }
    return 0;
}
