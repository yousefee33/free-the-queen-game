#include<iostream>
#include <conio.h>
using namespace std;

void drawbackground(char x[][120])
{
    for (int r = 0; r < 40; r++)
    {
        for (int c = 0; c < 120; c++)
        {
            x[r][c] = ' ';
        }
    }

    for (int r = 0; r < 40; r++)   ///boarder
    {
        x[r][0] = 186;
        x[r][119] = 186;
    }
    for (int c = 0; c < 120; c++)
    {
        x[0][c] = 205;
        x[39][c] = 205;
    }
    ////Corners
    x[0][0] = 201;
    x[39][0] = 200;
    x[0][119] = 187;
    x[39][119] = 188;
}
void drawPlatform(char x[][120])     /////levels
{
    for (int c = 1; c < 119; c++)
    {
        x[9][c] = 205;
        x[19][c] = 205;
        x[29][c] = 205;
    }
}
void Hero(char x[][120], int r, int c)
{
    x[r + 4][c - 2] = '|';
    x[r + 4][c] = '|';
    x[r + 3][c - 2] = '//';
    x[r + 3][c] = '\\';
    x[r + 2][c - 2] = '(';
    x[r + 2][c - 1] = '|';
    x[r + 2][c] = ')';
    x[r + 1][c - 2] = '\\';
    x[r + 1][c] = '/';
    x[r + 1][c - 1] = 205;
    x[r][c - 1] = '0';
    x[r][c - 2] = '/';
    x[r][c] = '\\';
}
void ladder2(char x[][120])
{
    for (int r = 9; r < 19; r++)
    {
        x[r][4] = '|';
        x[r][9] = '|';
        for (int c = 5; c < 9; c++)
        {
            x[r][c] = '-';
        }
    }
}
void movehero(char x[][120], int& r, int& c, char p, int& flag, int& flag1)
{
    if (p == 'w')
    {
        if (x[r + 5][c - 2] != ' ')
        {
            r--;
        }
    }
    if (p == 's')
    {
        if (x[r + 5][c - 2] != '*')
        {
            r++;


        }
    }
    if (p == 'd')
    {
        if (x[r + 4][c + 1] != '*')
        {
            c++;
        }
    }
    if (p == 'a')
    {
        if (x[r + 4][c - 3] != '*')
        {
            c--;
        }
    }
    if (p == 'e')  // jump right
    {
        if (x[r + 5][c - 2] != ' ')
        {
            r -= 4;
            c += 6;
        }
    }
    if (p == 'q') // jump left
    {
        if (x[r + 5][c - 2] != ' ')
        {
            r -= 4;
            c -= 6;
        }
    }
    if (p == 'b')
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    if (p == 'l')
    {
        flag1 = 1;
    }


}
void ladder(char x[][120])
{
    for (int r = 30; r < 39; r++)
    {
        x[r][20] = '|';
        x[r][25] = '|';
        for (int c = 21; c < 25; c++)
        {
            x[r][c] = '-';
        }
    }
}
void drawkey(char x[][120], int& flagKey, int r, int c)
{
    x[33][33] = 'c';
    x[33][34] = 205;
    if (r == 33 && c == 34)
    {
        flagKey = 1;
    }
}
void drawDoor(char x[][120])
{
    for (int c = 60; c < 71; c++)
    {
        x[29][c] = 220;
        x[38][c] = 220;
    }
    for (int r = 30; r < 39; r++)
    {
        x[r][60] = 219;
        x[r][70] = 219;
    }
}
void drawOkra(char x[][120])
{
    x[34][62] = 'O';
}
void drawGun(char x[][120], int& FlagTakeGun, int rh, int ch)
{
    x[36][79] = 'G';
    x[36][80] = 'U';
    x[36][81] = 'N';

    if (rh + 2 == 36 && ch + 1 == 79)
    {
        FlagTakeGun = 1;
    }

}
void BrokenLadder(char x[][120])
{
    for (int r = 24; r < 29; r++)
    {
        x[r][16] = '|';
        x[r][9] = '|';
        for (int c = 10; c < 16; c++)
        {
            x[r][c] = '-';
        }
    }
    for (int r = 20; r < 22; r++)
    {
        x[r][16] = '|';
        x[r][9] = '|';
        for (int c = 10; c < 16; c++)
        {
            x[r][c] = '-';
        }
    }
}
void Thorn(char x[][120])
{
    for (int r = 28; r < 29; r++)
    {
        for (int c = 30; c < 33; c++)
        {
            x[r][c] = '+';
        }
    }
    for (int r = 28; r < 29; r++)
    {
        for (int c = 70; c < 73; c++)
        {
            x[r][c] = '+';
        }
    }
}
void drawrobot(char x[][120], int r, int c, int& flag, int b[20]) ////enemy 2
{

    x[r + 5][c + 1] = '{';
    x[r + 5][c + 3] = '}';
    x[r + 4][c + 2] = '|';
    x[r + 3][c + 2] = '|';
    x[r + 2][c + 2] = '|';
    x[r + 1][c + 2] = '|';
    x[r + 1][c + 1] = '{';
    x[r + 1][c + 3] = '}';

    for (int col = c; col < c + 5; col++)
    {
        x[r][col] = '~';
    }


    x[r - 2][c - 1] = 'A';
    x[r - 1][c - 1] = 'A';

    x[r - 2][c + 5] = 'A';
    x[r - 1][c + 5] = 'A';
    for (int rr = r - 3; rr < r - 2; rr++)
    {
        for (int cc = c; cc < c + 5; cc++)
        {
            x[rr][cc] = '~';
        }
    }
    x[r - 2][c + 1] = 'X';
    x[r - 2][c + 3] = 'X';
    x[r - 1][c + 2] = '-';

    for (int raw = r - 3; raw < r + 5; raw++)
    {
        for (int col = c - 2; col < c + 7; col++)
        {
            for (int i = 0; i < 200; i += 2)
            {
                if (raw + 3 == b[i] && col + 3 == b[i + 1])
                {
                    flag = 1;
                }
            }
        }
    }
}
void MoveRobot(int& r, int& c, int& dirRobot)
{
    if (c == 60)
    {
        dirRobot = 1;
    }
    if (dirRobot == 1)
    {
        c++;
    }
    if (c == 119)
    {
        dirRobot = -1;
    }
    if (dirRobot == -1)
    {
        c--;
    }
}
void Elvator(char x[][120], int re, int ce)
{

    for (int c = ce; c < ce + 10; c++)
    {
        x[re][c + 1] = '-';
    }

}
void moveelvator(int& r, int& c, int& dir, int& rh, int& ch, int& flagElvatorHero)
{
    if (dir == 1)
    {
        r--;
        c -= 2;
        if (rh + 3 == r && ch - 2 >= 105 && ch - 2 <= c + 150)    /////regl el hero 3la el elvator
        {
            rh -= 4;
            ch--;
            flagElvatorHero = 1;
        }
        else
        {
            flagElvatorHero = 0;
        }
    }
    if (r == 18)
    {
        dir = -1;
    }
    if (dir == -1)
    {
        r++;
        c += 2;
        if (rh + 3 == r && ch - 2 >= 105 && ch - 2 <= c + 150) /////regl el hero 3la el elvator
        {
            rh++;
            ch++;
            flagElvatorHero = 1;
        }
        else
        {
            flagElvatorHero = 0;
        }
    }
    if (r == 29)
    {
        dir = 1;
    }
}
void enemy(char x[][120], int r, int c)
{
    x[r][c] = '|';
    x[r][c + 2] = '|';
    x[r - 1][c + 1] = 205;
    x[r - 2][c] = 'X';
    x[r - 2][c + 2] = 'X';

}
void moveenemy(int& c, int& dir)
{
    if (c == 107)
    {
        dir = 1;
    }
    if (dir == 1)
    {
        c++;
    }
    if (c == 118)
    {
        dir = -1;
    }
    if (dir == -1)
    {
        c--;
    }
}
void BoxOfLaser(char x[][120])
{
    for (int r = 17; r < 19; r++)
    {
        x[r][40] = '~';
        x[r][50] = '~';
    }
    for (int c = 41; c < 50; c++)
    {
        x[16][c] = '~';
    }
}
void laserGun(char x[][120], int& FlagTakeLaser, int rh, int ch)
{
    x[18][44] = 175;
    x[18][45] = 175;
    x[18][46] = 175;
    x[18][47] = 175;

    if (rh + 4 == 18 && ch - 3 == 44 || rh + 4 == 18 && ch + 1 == 44)
    {
        FlagTakeLaser = 1;
    }
}
void BigBoss(char x[][120], int r, int c, int b[20], int& flag)
{

    x[r][c] = '|';
    x[r + 1][c] = '|';
    x[r][c + 7] = '|';
    x[r + 1][c + 7] = '|';

    x[r - 1][c + 1] = '-';
    x[r - 1][c + 2] = '-';
    x[r - 1][c + 3] = '-';
    x[r - 1][c + 4] = '-';
    x[r - 1][c + 5] = '-';
    x[r - 1][c + 6] = '-';

    x[r + 2][c + 1] = '-';
    x[r + 2][c + 2] = '-';
    x[r + 2][c + 3] = '-';
    x[r + 2][c + 4] = '-';
    x[r + 2][c + 5] = '-';
    x[r + 2][c + 6] = '-';

    x[r][c + 2] = '0';
    x[r][c + 5] = '0';

    x[r + 1][c + 4] = '_';


    x[r + 3][c + 4] = '|';
    x[r + 4][c + 4] = '|';

    x[r + 4][c + 3] = 92;
    x[r + 4][c + 5] = '/';

    x[r + 5][c + 4] = '|';

    for (int raw = r - 1; raw < r + 4; raw++)
    {

        for (int col = c - 1; col < c + 8; col++)
        {
            for (int i = 0; i < 200; i += 2)
            {
                if (raw + 3 == b[i] && col + 2 == b[i - 1] || x[raw + 3][col + 2] == '=')
                {
                    flag = 1;
                }
            }
        }
    }

}
void MoveBigBoss(char x[][120], int& RowBigBoss, int& CBigBoss, int& flag)
{
    if (CBigBoss == 10)
    {
        flag = 1;
    }
    if (flag == 1)
    {
        CBigBoss++;
    }
    if (CBigBoss == 70)
    {
        flag = -1;
    }
    if (flag == -1)
    {
        CBigBoss--;
    }
}
void KeyofJail(char x[][120], int& flag, int rhero, int chero)
{
    x[4][80] = 'O';
    x[4][81] = '-';
    x[4][82] = 16;

    if (rhero == 4 && chero == 80)
    {
        flag = 1;
    }
}
void Queen(char x[][120], int r, int c)
{
    x[r][c] = 1;
    x[r + 1][c + 1] = ')';
    x[r + 1][c - 1] = '(';
    x[r + 2][c] = 'O';
}
void prison(char x[][120])
{
    for (int r = 1; r < 9; r++)
    {
        for (int c = 95; c < 119; c += 2)
        {
            x[r][c] = '|';
        }
    }
    for (int r = 7; r < 9; r++)
    {
        for (int c = 95; c < 119; c += 2)
        {
            x[r][c] = '~';
        }
    }
}
void shoot(char x[][120], int b[200], int Rh, int Ch)  /////postion of each bullet
{
    for (int i = 0; i < 200; i += 2)
    {
        if (b[i] == -9)
        {
            b[i] = Rh + 2;
            b[i + 1] = Ch + 2;


            break;
        }
    }


}
void Movebullet(char x[][120], int b[200], int Rh, int Ch, int r, int c, int& FlagDeadEnemy)
{


    for (int i = 0; i < 200; i += 2)
    {

        if (b[i] != -9)
        {
            if (x[b[i]][b[i + 1] + 1] != ' ')
            {

                for (int i = 0; i < 200; i += 2)
                {
                    if (r - 2 == b[i] && c + 2 == b[i + 1])
                    {
                        FlagDeadEnemy = 1;


                    }
                }
                b[i] = -9;
                b[i + 1] = -9;
            }
            else
            {
                x[b[i]][b[i + 1]] = '>';
                b[i + 1] += 1;
            }
        }
    }
}


void gravity(char x[][120], int& r, int c, int flagElvatorHero)
{
    if (flagElvatorHero == 0)
    {
        if (x[r + 5][c - 2] == ' ')
        {
            r++;
        }
    }
}
void openDoor(int flagKey, int rhero, int chero, int& flag)
{
    if (flagKey == 1 && rhero == 34 && chero == 61)
    {
        flag = 1;
    }
}
void diehero(char x[][120], int rh, int ch, int& flagDieHero, int re, int ce, int rbos, int cbos, int rrobot, int crobot)
{
    if (re - 2 == rh + 2 && ce == ch + 1 || re - 2 == rh + 3 && ce == ch + 1)  ////enemy
    {
        flagDieHero = 1;
    }

    if (rh + 5 == 22 && ch > 10 && ch < 16 || rh + 5 == 23 && ch>10 && ch < 16 || rh + 4 == 22 && ch>10 && ch < 16 || rh + 4 == 23 && ch>10 && ch < 16) ///ladder
    {
        flagDieHero = 1;
    }

    if (rbos + 3 == rh + 2 && cbos + 4 == ch - 3 || rbos + 3 == rh + 2 && cbos + 4 == ch + 2)  ////boss
    {
        flagDieHero = 1;
    }

    if (rrobot + 3 == rh + 2 && crobot + 2 == ch + 1 || rrobot + 3 == rh + 3 && crobot - 2 == ch + 1)  ////robot
    {
        flagDieHero = 1;
    }
}
void Cube(char x[][120])
{
    x[28][85] = '*';
    x[27][86] = '*';
    x[26][87] = '*';
    x[25][88] = '*';
    x[24][89] = '*';

    x[28][84] = '*';
    x[27][85] = '*';
    x[26][86] = '*';
    x[25][87] = '*';
    x[24][88] = '*';

    x[24][90] = '*';
    x[25][91] = '*';
    x[26][92] = '*';
    x[27][93] = '*';
    x[28][94] = '*';

    x[24][91] = '*';
    x[25][92] = '*';
    x[26][93] = '*';
    x[27][94] = '*';
    x[28][95] = '*';
}
void display(char x[][120])
{
    for (int i = 0; i < 99999992; i++)
    {
        if (i == 99999991)
        {
            system("cls");
        }
    }
    for (int r = 0; r < 40; r++)
    {
        for (int c = 0; c < 120; c++)
        {
            cout << x[r][c];
        }
    }

}
void main()
{
    char x[40][120];
    int rhero = 34, chero = 15;
    int renemy = 38, cenemy = 90, direnemy = 1;
    int relvator = 27, celvator = 105, dirElvator = 1;
    int rqueen = 6, cqueen = 100;
    int  dirRobot = 1;
    int Tal2a[200] = { -9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 ,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9,-9 };
    int flagBullet = 0;
    int flagLazer = 0;
    int flagKey = 0;
    int clazer;
    int rlazer;
    int flagElvatorHero = 0;
    int FlagDeadEnemy = 0;
    int FlagDeadrobot = 0;
    int flagOpenDoor = 0;
    int flagDieHero = 0;
    int flagBoss = 1;
    int rbos = 3, cbos = 40;
    int rRobot = 13, cRobot = 90;
    int FlagDeadBoss = 0;
    int rRope = 9;
    int cRope = 9;
    int flagwin = 0;
    int keyPrison = 0;
    int FlagTakeGun = 0;
    int ct = 0;
    int flagTakeLaser = 0;
    int ctm = 0;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0, f10 = 0, f9 = 0;
    for (;;)
    {
        for (; !_kbhit();)
        {
            drawbackground(x);
            drawPlatform(x);
            ladder(x);
            if (flagKey == 0)
            {
                drawkey(x, flagKey, rhero, chero);
            }
            openDoor(flagKey, rhero, chero, flagOpenDoor);
            if (flagOpenDoor == 0)
            {
                drawDoor(x);
                drawOkra(x);
            }
            if (FlagTakeGun == 0)
            {
                drawGun(x, FlagTakeGun, rhero, chero);
            }
            else
            {
                Movebullet(x, Tal2a, rhero, chero, renemy, cenemy, FlagDeadEnemy);
            }
            BrokenLadder(x);
            Cube(x);

            Thorn(x);

            if (flagTakeLaser == 0)
            {
                laserGun(x, flagTakeLaser, rhero, chero);
                BoxOfLaser(x);
            }
            diehero(x, rhero, chero, flagDieHero, renemy, cenemy, rbos, cbos, rRobot, cRobot);
            ladder2(x);
            if (keyPrison == 0)
            {
                KeyofJail(x, keyPrison, rhero, chero);
                prison(x);
            }
            else
            {
                flagwin = 1;
            }
            Queen(x, rqueen, cqueen);
            Elvator(x, relvator, celvator);
            moveelvator(relvator, celvator, dirElvator, rhero, chero, flagElvatorHero);
            if (flagTakeLaser == 1)
            {
                if (flagLazer == 1)
                {
                    clazer = chero;
                    rlazer = rhero;
                    for (int i = clazer + 2; ; i++)
                    {
                        if (x[rlazer + 2][clazer + 4] == ' ')
                        {
                            clazer++;
                            x[rlazer + 2][clazer + 3] = '=';

                        }
                        else
                        {
                            x[rlazer + 2][clazer - 3] = ' ';
                            flagLazer = 0;
                            break;
                        }
                    }
                }
            }
            if (FlagDeadrobot == 0)
            {
                drawrobot(x, rRobot, cRobot, FlagDeadrobot, Tal2a);
                MoveRobot(rRobot, cRobot, dirRobot);
            }
            else
            {
                rRobot = 0;
                cRobot = 0;
            }
            if (FlagDeadBoss == 0)
            {
                BigBoss(x, rbos, cbos, Tal2a, FlagDeadBoss);
                MoveBigBoss(x, rbos, cbos, flagBoss);
            }
            else
            {
                rbos = 0;
                cbos = 0;
            }
            if (FlagDeadEnemy == 0)
            {
                enemy(x, renemy, cenemy);
                moveenemy(cenemy, direnemy);

            }
            else
            {
                renemy = 0;
                cenemy = 0;
            }


            gravity(x, rhero, chero, flagElvatorHero);
            Hero(x, rhero, chero);
            display(x);
        }

        char p = _getch();
        movehero(x, rhero, chero, p, flagBullet, flagLazer);
        if (flagBullet == 1)
        {
            shoot(x, Tal2a, rhero, chero);
        }

        if (flagDieHero == 1)
        {
            break;
        }
        if (flagwin == 1)
        {
            break;
        }
        Hero(x, rhero, chero);
    }
    system("cls");
    if (flagDieHero == 1)
    {

        cout << "Game Over";
    }
    if (flagwin == 1)
    {
        cout << "Hello Winner, wait I am gonna take you yo a new Level but after my final 3>";
    }
}
