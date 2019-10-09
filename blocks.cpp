#include "tetris.hpp"
#include "blocks.hpp"

Blocks::Blocks(int c,string type,tetris* tt)
{
    central_c=c;
    central_r=3;
    block_type=type;
    t=tt;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            block_table[i][j]=0;
    }
    if (type=="T1")
    {
        block_table[0][1]=1;
        block_table[1][0]=1;
        block_table[1][1]=1;
        block_table[1][2]=1;
    }
    else if (type=="T2")
    {
        block_table[0][1]=1;
        block_table[1][0]=1;
        block_table[1][1]=1;
        block_table[2][1]=1;
    }
    else if (type=="T3")
    {
        block_table[0][0]=1;
        block_table[0][1]=1;
        block_table[0][2]=1;
        block_table[1][1]=1;
    }
    else if (type=="T4")
    {
        block_table[0][0]=1;
        block_table[1][0]=1;
        block_table[2][0]=1;
        block_table[1][1]=1;
    }
    else if (type=="L1")
    {
        block_table[0][0]=1;
        block_table[1][0]=1;
        block_table[2][0]=1;
        block_table[0][1]=1;
    }
    else if (type=="L2")
    {
        block_table[0][0]=1;
        block_table[1][0]=1;
        block_table[1][1]=1;
        block_table[1][2]=1;
    }
    else if (type=="L3")
    {
        block_table[2][0]=1;
        block_table[2][1]=1;
        block_table[1][1]=1;
        block_table[0][1]=1;
    }
    else if (type=="L4")
    {
        block_table[0][0]=1;
        block_table[0][1]=1;
        block_table[0][2]=1;
        block_table[1][2]=1;
    }
    else if (type=="J1")
    {
        block_table[0][0]=1;
        block_table[0][1]=1;
        block_table[1][1]=1;
        block_table[2][1]=1;
    }
    else if (type=="J2")
    {
        block_table[0][0]=1;
        block_table[0][1]=1;
        block_table[0][2]=1;
        block_table[1][0]=1;
    }
    else if (type=="J3")
    {
        block_table[0][0]=1;
        block_table[1][0]=1;
        block_table[2][0]=1;
        block_table[2][1]=1;
    }
    else if (type=="J4")
    {
        block_table[1][0]=1;
        block_table[1][1]=1;
        block_table[1][2]=1;
        block_table[0][2]=1;
    }
    else if (type=="S1")
    {
        block_table[0][0]=1;
        block_table[0][1]=1;
        block_table[1][1]=1;
        block_table[1][2]=1;
    }
    else if (type=="S2")
    {
        block_table[1][0]=1;
        block_table[2][0]=1;
        block_table[1][1]=1;
        block_table[0][1]=1;
    }
    else if (type=="Z1")
    {
        block_table[1][0]=1;
        block_table[1][1]=1;
        block_table[0][1]=1;
        block_table[0][2]=1;
    }
    else if (type=="Z2")
    {
        block_table[0][0]=1;
        block_table[1][0]=1;
        block_table[1][1]=1;
        block_table[2][1]=1;
    }
    else if (type=="I1")
    {
        block_table[0][0]=1;
        block_table[1][0]=1;
        block_table[2][0]=1;
        block_table[3][0]=1;
    }
    else if (type=="I2")
    {
        block_table[0][0]=1;
        block_table[0][1]=1;
        block_table[0][2]=1;
        block_table[0][3]=1;
    }
    else if (type=="O")
    {
        block_table[0][1]=1;
        block_table[1][0]=1;
        block_table[1][1]=1;
        block_table[0][0]=1;
    }
}

bool Blocks::valid()
{
    if (block_type=="T1")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r][central_c]==1 || t->table[central_r+1][central_c+1]==1 || t->table[central_r][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="T2")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r][central_c]==1 || t->table[central_r+1][central_c+1]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="T3")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1 || t->table[central_r+1][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="T4")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r][central_c+1]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="L1")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="L2")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r][central_c+1]==1 || t->table[central_r][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="L3")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r-1][central_c]==1 || t->table[central_r+1][central_c+1]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="L4")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1 || t->table[central_r+1][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="J1")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="J2")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1 || t->table[central_r+1][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="J3")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r-1][central_c+1]==1 )
            return false;
        else
            return true;
    }
    else if (block_type=="J4")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r][central_c]==1 || t->table[central_r][central_c+1]==1 || t->table[central_r+1][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="S1")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1 || t->table[central_r][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="S2")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r][central_c]==1 || t->table[central_r+1][central_c+1]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="Z1")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r][central_c]==1 || t->table[central_r+1][central_c+1]==1 || t->table[central_r+1][central_c+2]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="Z2")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r][central_c+1]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="I1")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1)
            return false;
        else
            return true;
    }
    else if (block_type=="I2")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1 || t->table[central_r+1][central_c+2]==1 || t->table[central_r+1][central_c+3])
            return false;
        else
            return true;
    }
    else if (block_type=="O")
    {
        if (central_r >= t->r+3) return false;
        else if (t->table[central_r+1][central_c]==1 || t->table[central_r+1][central_c+1]==1)
            return false;
        else
            return true;
    }

}

void Blocks::put_to_tetris_table()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (block_table[i][j]==1)
                t->table[central_r-i][central_c+j]=1;
        }
    }
}

void Blocks::fall()
{
    while (valid())
    {
        central_r++;
    }
    put_to_tetris_table();
}
