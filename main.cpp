#include <bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
using namespace std;

void setupen(char a[10][10])
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            a[i][j]=' ';
        }
    }
}

void creatspider(int &p, int &q)
{
    p=rand()%(9-1+1)+1;
    q=rand()%(9-1+1)+1;
}

void up(int &x, int &y)
{
    x=x;
    y=y-1;
}

void down(int &x, int &y)
{
    x=x;
    y=y+1;
}

void right(int &x, int &y)
{
    y=y;
    x=x+1;
}

void left(int &x, int &y)
{
    x=x-1;
    y=y;
}

void display(const int &x,const int &y, char a[10][10], const int &d, const int &p, const int &q);

void tail(const int &x, const int &y, int &z, int b[10][10], int &l,const int &d, char a[10][10], int &ad)
{
    l++;
    b[y][x]=l;
    if (l>d+1)
    {
        for (int i=0; i<10; i++)
        {
        for (int j=0; j<10; j++)
            {
                if (b[i][j]==z)
                {
                    a[i][j]=' ';
                    b[i][j]=0;
                }
            }
        }
        if (ad==d)
        {
            z++;
        }
        ad=d;
    }
}
int main()
{
    int x=1, y=1, d=0, l=1, ad=0;
    char dk;
    int p, q, z=0;
    char a[10][10];
    int b[10][10];
    setupen(a);
    display(x, y, a, d, p, q);
    srand(time(NULL));
    dk = getch();
    creatspider(p, q);
    while (x<10 && x>0 && y<10 && y>0)
    {
        switch (dk)
        {
            case 'w':
            {
                while (dk=='w' && x<10 && x>0 && y<10 && y>0)
                {
                    if (kbhit())
                        dk = getch();
                    else
                    {
                        usleep(100000);
                        up(x, y);
                        if (x==q && y==p)
                        {
                            d++;
                            creatspider(p, q);
                        }
                        tail(x, y, z, b, l, d, a, ad);
                        display(x, y, a, d, p, q);
                    }
                }
                break;
            }
            case 's':
            {
                while (dk=='s' && x<10 && x>0 && y<10 && y>0)
                {
                    if (kbhit())
                        dk = getch();
                    else
                    {
                        usleep(100000);
                        down(x, y);
                        if (x==q && y==p)
                        {
                            d++;
                            creatspider(p, q);
                        }
                        tail(x, y, z, b, l, d, a, ad);
                        display(x, y, a, d, p, q);
                    }
                }
                break;
            }
            case 'a':
            {
                while (dk=='a' && x<10 && x>0 && y<10 && y>0)
                {
                    if (kbhit())
                        dk = getch();
                    else
                    {
                        usleep(100000);
                        left(x, y);
                        if (x==q && y==p)
                        {
                            d++;
                            creatspider(p, q);
                        }
                        tail(x, y, z, b, l, d, a, ad);
                        display(x, y, a, d, p, q);
                    }
                }
                break;
            }
            case 'd':
            {
                while (dk=='d' && x<10 && x>0 && y<10 && y>0)
                {
                    if (kbhit())
                        dk = getch();
                    else
                    {
                        usleep(100000);
                        right(x, y);
                        if (x==q && y==p)
                        {
                            d++;
                            creatspider(p, q);
                        }
                        tail(x, y, z, b, l, d, a, ad);
                        display(x, y, a, d, p, q);
                    }
                }
                break;
            }
        }
    }
}
void display(const int &x,const int &y, char a[10][10], const int &d, const int &p, const int &q)
{
    system("cls");
    cout << "Diem: " << d << endl << endl << endl;
    if (x==10 || y==10 || x==0 || y==0)
    {
        a[y][x]=' ';
        cout << "----------";
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
            cout << a[i][j];
            }
            cout << endl;
        }
        cout << "----------" << endl;
        cout << "ban da thua!";
        exit(0);
    }
    else
    {
        a[y][x]='*';
        if (p>=1 && p<=9 && q>=1 && q<=9)
        {
            a[p][q]='o';
        }
        cout << "----------";
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << "----------" << endl;
        usleep(70000);
    }
}
