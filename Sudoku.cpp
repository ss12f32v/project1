#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string> 
#include <time.h>   
#include "Sudoku.h"
using namespace std;

    
    int a[10][10],b[10][10],ans,TIME;
    Sudoku::Sudoku()
    {
        ans=0;
        TIME=0;
    }
    void Sudoku::printBoard(){
        int i,j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                cout << a[i][j];
                if (j < 8)
                    cout << " ";
            }
            cout << endl;
        }    
    }
    void Sudoku::giveQuestion()
    {
        srand(time(NULL));
        int j;
        string print;
        string q = ("064001020000894030030520004041000800200000490800305000009000706005070001600008200");
        string w = ("520000109800951000016200080000062370063010002200709001002006895008320600650000030");
        string e = ("000250907048600030907108000002065090093002005050017040200500870680000509100090403");
        string r = ("090708014207006508080453009359071806010804700804030921400307190035100402901042080");
        string t = ("070000920008200003090300670000000000700654390400000501000030000003160200000900007");
        string y = ("000010000010007569506400080028005170005003090000100000200000003087000000000008010");
        string u = ("000500760000002800000081000000000000840050010000900507004010070605000009000470380");
        string i = ("837020000602009300004000000400008009000040038500100000000030000008490000000680041");
        string o = ("060000000000960085000704000673000000890000100001000360040000500000007009732809006");
        string p = ("090500001210734000400020005060100008000000090000460000900005007300000006040019000");
        string z = ("360200045000530690087000100000120960003605800028094000001000480075063000240009057");
        //cout << "mother fucker" << endl;
        int rand_seed = rand() % 11;
        if( rand_seed == 0 ) print = q;
        else if( rand_seed == 1 ) print = w;
        else if( rand_seed == 2 ) print = e;
        else if( rand_seed == 3 ) print = r;
        else if( rand_seed == 4 ) print = t;
        else if( rand_seed == 5 ) print = y;
        else if( rand_seed == 6 ) print = u;
        else if( rand_seed == 7 ) print = i;
        else if( rand_seed == 8 ) print = o;
        else if( rand_seed == 9 ) print = p;
        else if( rand_seed == 10 ) print = z;
        for (int j=0;j<81;j++){
            cout << print[j];
            if ( ( j % 9 ) == 8 ) cout << endl ;
            else cout << " " ;
        }
    }
    void Sudoku::readIn()
    {
        int i,j;
        for(i=0;i<9;i++)
            for(j=0;j<9;j++){
                a[i][j] = 0;
                b[i][j] = 0;
            }

        for(i=0;i<9;i++)
        {
            for(j=0;j< 9;j++)
            {
                cin >> a[i][j];
            }
        }
    }
    void Sudoku::changeNum(int digit1,int digit2 ){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j] == digit1)
                a[i][j] = digit2 ;
            else if(a[i][j] == digit2)
                a[i][j] = digit1;
            }
        }
    }
    void Sudoku::changeRow(int row_a, int row_b){
        int tmp = 0;
        if((row_a == 0 && row_b==1) || (row_a==1 && row_b==0)){
            for(int i=0;i<9;i++){
                for(int j=0;j<3;j++){
                    tmp = a[i][j];
                    a[i][j] = a[i+3][j];
                    a[i+3][j] = tmp;
                }
            }
        }
        else if((row_a==0 && row_b==2) || (row_a==2 && row_b==0)){
            for(int j=0;j<9;j++){
                for(int i=0;i<3;i++){
                    tmp = a[i][j];
                    a[i][j] = a[i+6][j];
                    a[i+6][j] = tmp;
                }
            }         
        }
        else if((row_a==1 && row_b==2) || (row_a==2 && row_b==1)){
            for(int j=0;j<9;j++){
                for(int i=3;i<6;i++){
                    tmp = a[i][j];
                    a[i][j] = a[i+3][j];
                    a[i+3][j] = tmp;
                }
            }                      
        }
    }
    void Sudoku::changeCol(int col_a, int col_b){
        int tmp = 0;
        if((col_a == 0 && col_b==1) || (col_a==1 && col_b==0)){
            for(int i=0;i<9;i++){
                for(int j=0;j<3;j++){
                    tmp = a[i][j];
                    a[i][j] = a[i][j+3];
                    a[i][j+3] = tmp;
                }
            }
        }
        else if((col_a==0 && col_b==2) || (col_a==2 && col_b==0)){
            for(int i=0;i<9;i++){
                for(int j=0;j<3;j++){
                    tmp = a[i][j];
                    a[i][j] = a[i][j+6];
                    a[i][j+6] = tmp;
                }
            }         
        }
        else if((col_a==1 && col_b==2) || (col_a==2 && col_b==1)){
            for(int i=0;i<9;i++){
                for(int j=3;j<6;j++){
                    tmp = a[i][j];
                    a[i][j] = a[i][j+3];
                    a[i][j+3] = tmp;
                }
            }                      
        }
    }

    void Sudoku::rotate(int n){
        int tmp[9][9]={0};
        int number=n%4;
        for(int k=0;k<number;k++){
            for(int i=0;i<9;i++)
                for(int j=0;j<9;j++)
                    tmp[i][8 - j] = a[i][j]; 
        }                        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                 a[i][j]=tmp[i][j];
            }
        }
    }
    void Sudoku::flip(int n){
    int tmp[9][9]={0};
            if(n==0){
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        tmp[i][j]=a[8 - i][j];
                    }
                }
            }
            else if(n==1){
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        tmp[i][j]=a[i][8 - j];
                    }
                }
            }
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    a[i][j]=tmp[i][j];
                }
            }
 
    }

    void  Sudoku::transform(){
        change();
        printBoard();
    }
    void Sudoku::change(){
        srand(time(NULL));
        changeNum(rand()%9+1,rand()%9+1);
        changeRow(rand()%3,rand()%3);
        changeCol(rand()%3,rand()%3);
        rotate(rand()%101);
        flip(rand()%2);

    }
    void Sudoku::solve()
    {
        struct timespec yohua;
        yohua.tv_sec = 0;
        yohua.tv_nsec = 2000;
        int num,i,j,m,n,zero=0,zerox=0,zero_save;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(a[i][j] == 0)
                {
                    zero++;
                }
            }
        }
        if(TIME == 0)
        {
            zero_save = zero ;
            TIME++;
        }
        if( zero == 0 )
        {
            ans++;
            if(ans > 1)
            {
                cout << "2";
                exit(0);
            }
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    b[i][j] = a[i][j];
                }
            }
            return ;
        }
        string str1; 
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(a[i][j] == 0)
                {

                    for(num=1;num<=9;num++)
                    {
                        nanosleep(&yohua,NULL);
                        if( check(num,i,j) == 0 )
                        {
                            a[i][j] = num;
                            solve();
                            a[i][j] = 0;
                        }
                    }
                    for(m=0;m<9;m++)
                    {
                        for(n=0;n<9;n++)
                        {
                            if(a[m][n] == 0)
                            {
                                zerox ++;
                            }
                        }
                    }
                    if(zerox == zero_save)
                    {
                        if(ans == 1)
                        {
                            cout << "1" << endl ;
                            for(i=0;i<9;i++)
                            {
                                for(j=0;j<9;j++)
                                {
                                    cout << b[i][j];
                                    if (j < 8)
                                    {
                                        cout << " ";
                                    }
                                }
                                cout << endl;
                            }
                        }
                        else if ( ans == 0)
                        {
                            cout << "0" << endl;
                        }
                    }
                    return; /////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                }
            }
        }
    }

    int Sudoku::check(int num,int i,int j)
    {
        int m,n;
        for(m=0;m<9;m++)
        {
            if(num == a[i][m]) return 1;
        }
        for(m=0;m<9;m++)
        {
            if(num == a[m][j]) return 1;
        }
        if(j == 0 || j == 3 || j == 6 )
        {
            for(n=j+1;n<=j+2;n++)
            {
                if(i == 0 || i == 3 || i == 6 )
                {
                    for(m=i+1;m<=i+2;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
                if(i == 1 || i == 4 || i == 8 )
                {
                    if(num == a[i+1][n]) return 1;
                    if(num == a[i-1][n]) return 1;
                }
                if(i == 2 || i == 5 || i == 8  )
                {
                    for(m=i-2;m<=i-1;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
            }
        }
        if(j == 1 || j == 4 || j == 7 )
        {
            if(i == 0 || i == 3 || i == 6 )
            {
                for(m=i+1;m<=i+2;m++)
                {
                    if(num == a[m][j-1]) return 1;
                    if(num == a[m][j+1]) return 1;
                }
            }
            if(i == 1 || i == 4 || i == 7 )
            {
                if(num == a[i-1][j-1]) return 1;
                if(num == a[i-1][j+1]) return 1;
                if(num == a[i+1][j-1]) return 1;
                if(num == a[i+1][j+1]) return 1;
            }
             if(i == 2 || i == 5 || i ==8 )
            {
                for(m=i-2;m<=i-1;m++)
                {
                    if(num == a[m][j-1]) return 1;
                    if(num == a[m][j+1]) return 1;
                }
            }
        }
        if(j == 2 || j == 5 || j == 8 )
        {
            for(n=j-2;n<=j-1;n++)
            {
                if(i == 0 || i == 3 || i == 6 )
                {
                    for(m=i+1;m<=i+2;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
                if(i == 1 || i == 4 || i == 7 )
                {
                    if(num == a[i+1][n]) return 1;
                    if(num == a[i-1][n]) return 1;
                }
                if(i == 2 || i == 5 || i == 8 )
                {
                    for(m=i-2;m<=i-1;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
            }
        }
         return 0;
    }