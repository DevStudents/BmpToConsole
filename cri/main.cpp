#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>

using namespace std;
void colorlist()
{
    HANDLE ho;
    ho = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( ho , 0 | 4);
    cout << "0,0,0\n";
    SetConsoleTextAttribute( ho , 128);
    cout << "118,118,118\n";
    SetConsoleTextAttribute( ho , 16);
    cout << "0,55,218\n";
    SetConsoleTextAttribute( ho , 32);
    cout << "19,161,14\n";
    SetConsoleTextAttribute( ho , 64);
    cout << "197,15,31\n";
    SetConsoleTextAttribute( ho , 16 | 32);
    cout << "58,150,221\n";
    SetConsoleTextAttribute( ho , 16 | 64);
    cout << "136,23,152\n";
    SetConsoleTextAttribute( ho , 16 | 128);
    cout << "59,120,255\n";
    SetConsoleTextAttribute( ho , 16 | 32 | 64);
    cout << "204,204,204\n";
    SetConsoleTextAttribute( ho , 16 | 32 | 128);
    cout << "97,214,214\n";
    SetConsoleTextAttribute( ho , 16 | 64 | 128);
    cout << "180,0,158\n";
    SetConsoleTextAttribute( ho , 32 | 64);
    cout << "193,156,0\n";
    SetConsoleTextAttribute( ho , 32 | 128);
    cout << "22,198,30\n";
    SetConsoleTextAttribute( ho , 32 | 64 | 128);
    cout << "249,241,165\n";
    SetConsoleTextAttribute( ho , 64 | 128);
    cout << "231,72,86\n";
    SetConsoleTextAttribute( ho , 16 | 32 | 64 | 128);
    cout << "255,255,255\n";
    SetConsoleTextAttribute( ho , 16 | 32 | 64 | 128);
    cout << "255,255,255\n";
    SetConsoleTextAttribute( ho , 0 | 64);
    cout << "E";
    SetConsoleTextAttribute(ho , 0 | 4);
    cout << " - undefined color\n";

}
void draw(unsigned char RGB2 , unsigned char RGB1, unsigned char RGB0)
{
    HANDLE ho;
    ho = GetStdHandle( STD_OUTPUT_HANDLE );
    char q = ' ';
    if(RGB0==0 && RGB1==0 && RGB2==0)
    {
        SetConsoleTextAttribute( ho , 0 );
    }
    else if(RGB0==118 && RGB1==118 && RGB2==118)
    {
        SetConsoleTextAttribute( ho , 128 );
    }
    else if(RGB0==0 && RGB1==55 && RGB2==218)
    {
        SetConsoleTextAttribute( ho , 16 );
    }
    else if(RGB0==19 && RGB1==161 && RGB2==14)
    {
        SetConsoleTextAttribute( ho , 32 );
    }
    else if(RGB0==197 && RGB1==15 && RGB2==31)
    {
        SetConsoleTextAttribute( ho , 64 );
    }
    else if(RGB0==58 && RGB1==150 && RGB2==221)
    {
        SetConsoleTextAttribute( ho , 16 | 32 );
    }
    else if(RGB0==136 && RGB1==23 && RGB2==152)
    {
        SetConsoleTextAttribute( ho , 16 | 64 );
    }
    else if(RGB0==59 && RGB1==120 && RGB2==255)
    {
        SetConsoleTextAttribute( ho , 16 | 128 );
    }
    else if(RGB0==204 && RGB1==204 && RGB2==204)
    {
        SetConsoleTextAttribute( ho , 16 | 32 | 64 );
    }
    else if(RGB0==97 && RGB1==214 && RGB2==214)
    {
        SetConsoleTextAttribute( ho , 16 | 32 | 128  );
    }
    else if(RGB0==180 && RGB1==0 && RGB2==158)
    {
        SetConsoleTextAttribute( ho , 16 | 64 | 128 );
    }
    else if(RGB0==193 && RGB1==156 && RGB2==0)
    {
        SetConsoleTextAttribute( ho , 32 | 64 );
    }
    else if(RGB0==22 && RGB1==198 && RGB2==30)
    {
        SetConsoleTextAttribute( ho , 32 | 1288 );
    }
    else if(RGB0==249 && RGB1==241 && RGB2==165)
    {
        SetConsoleTextAttribute( ho , 32 | 64 | 128 );
    }
    else if(RGB0==231 && RGB1==72 && RGB2==86)
    {
        SetConsoleTextAttribute( ho , 64 | 128 );
    }
    else if(RGB0==255 && RGB1==255 && RGB2==255)
    {
        SetConsoleTextAttribute( ho , 16 | 32 | 64 | 128 );
    }
    else
    {
        SetConsoleTextAttribute(ho , 0 | 4);
        q='E';
    }
    cout << ""<< q << q;

}
int main()
{
    const int sizep=17;
    HANDLE ho;
    ho = GetStdHandle( STD_OUTPUT_HANDLE );
    unsigned char picture[sizep][sizep][3];
    fstream file;
    string cmd;
    while(true)
    {
        SetConsoleTextAttribute(ho , 4);
        cout << "Enter \"colorlist\" for show acceptable colorsRGB, or \"filename.bmp\": ";
        cin >> cmd;
        system("cls");
        if(cmd == "colorlist")
        {
            colorlist();
        }
        else
            break;
    }
    file.open(cmd.c_str() , ios::in);
    if(file.good() == 0)
    {
        cout << "Bad file";
        return 0;
    }
    char trash;
    for(int i=0; i<54; i++)
        file >> trash;
    int q[3];
    for(int i=0; i<sizep; i++)
    {
        for(int j=0; j<sizep-1; j++)
        {
            for(int c=0; c<3; c++)
            {
                file >> picture[i][j][c];
            }
            q[0] = picture[i][j][0];
            q[1] = picture[i][j][1];
            q[2] = picture[i][j][2];
        }
    }
    for(int i=sizep-2; i>-1; i--)
    {
        for(int j=0; j<sizep-1; j++)
        {
            draw(picture[i][j][0],picture[i][j][1],picture[i][j][2] );
        }
        cout << "\n";
    }

}
