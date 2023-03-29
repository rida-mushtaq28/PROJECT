#include <iostream>
#include <windows.h>
using namespace std;
  //player character
char box=219;
char tank1[6]={box, box ,box, '-', '-', '>'};
char tank2[6]={'0',' ','0' ,' ',' ',' '};

// enemy Character
char enemy1[6]={' ',' ',' ','-','-','-'};
char enemy2[6]={'<','=','=','(','-',')'};
char enemy3[6]={' ',' ',' ','\\','@','/'};
char enemy4[6]={' ',' ',' ','*','*','*'};

 //player coordinates

int tankX=5;
int  tankY=5;

 //enemy Coordinates
int enemyX=30;
int enemyY=10;

 //Player Bullets
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount=0; 

int score=0;

void gotoxy(int x,int y);
char getCharAtxy(short int x,short int y);
void addScore();
void printScore();
void printMaze();
void printTank();
void printEnemy();
void moveTankDown();
void moveTankUp();
void moveTankLeft();
void moveTankRight();
void moveEnemy();
void generateBullet();
void moveBullet();
void printBullet(int x,int y);
void eraseBullet(int x,int y);
void makeBulletInactive(int idx);
void bulletCollisionWithEnemy();

main()
{
    bool gamerunning=true;
    system("cls");
    printMaze();
    printTank();
    printEnemy();
    while(gamerunning)
    {
        int timer=0;
        printScore();
        if(GetAsyncKeyState(VK_RIGHT))
         {
            moveTankRight();
         }

         if(GetAsyncKeyState(VK_LEFT))
         {
            moveTankLeft();
         }

         if(GetAsyncKeyState(VK_UP))
         {
            moveTankUp();
         }

         if(GetAsyncKeyState(VK_DOWN))
         {
            moveTankDown();
         }
         if(GetAsyncKeyState(VK_SPACE))
         {
            generateBullet();
         }
         if(timer==3)
          {
            moveEnemy();
            timer=0;
          }
        moveBullet();
        bulletCollisionWithEnemy();
        timer++;
        Sleep(90);

    }
    

}
void gotoxy(int x,int y)
{
 COORD coordinates;
 coordinates.X =x;
 coordinates.Y =y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
char getCharAtxy(short int x,short int y)
{
    CHAR_INFO ci;
    COORD xy = {0,0};
    SMALL_RECT rect={x,y,x,y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void addScore()
 {
    score++;
 }

void printScore()
 {
    gotoxy(87,2);
    cout << "Score: " << score;
 }
void printTank()
{
    gotoxy(tankX,tankY);
    for (int idx =0; idx < 6 ;idx++)
     {
        cout <<tank1[idx];
     }
     gotoxy(tankX,tankY+1);
     for (int idx=0;idx < 6 ;idx++)
      {
        cout << tank2[idx];
      }
     
}
void printEnemy()
{
    gotoxy(enemyX,enemyY);
    for (int idx =0; idx < 6 ;idx++)
     {
        cout <<enemy1[idx];
     }
     gotoxy(enemyX,enemyY+1);
     for (int idx=0;idx < 6 ;idx++)
      {
        cout << enemy2[idx];
      }
      gotoxy(enemyX,enemyY+2);
     for (int idx=0;idx < 6 ;idx++)
      {
        cout << enemy3[idx];
      }
      gotoxy(enemyX,enemyY+3);
     for (int idx=0;idx < 6 ;idx++)
      {
        cout << enemy4[idx];
      }
}


void printMaze()
{
    cout <<"####################################################################################"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"#                                                                                  #"<<endl;
    cout <<"####################################################################################"<<endl;
}
void eraseTank()
{
    gotoxy(tankX,tankY);
    for(int idx=0; idx < 6 ; idx++)
     {
        cout << " ";
     }
     gotoxy(tankX,tankY+1);
     for (int idx =0; idx < 6; idx++)
      {
        cout << " ";
      }
}
void eraseEnemy()
{
    gotoxy(enemyX,enemyY);
    for(int idx=0; idx < 6 ; idx++)
     {
        cout << " ";
     }
     gotoxy(enemyX,enemyY+1);
     for (int idx =0; idx < 6; idx++)
      {
        cout << " ";
      }
     gotoxy(enemyX,enemyY+2);
     for (int idx =0; idx < 6; idx++)
      {
        cout << " ";
      } 
     gotoxy(enemyX,enemyY+3);
     for (int idx =0; idx < 6; idx++)
      {
        cout << " ";
      }  
}


void moveTankRight()
{
    char next = getCharAtxy( tankX+6 , tankY );
    if(next == ' ')
     {
        eraseTank();
        tankX = tankX + 1;
        printTank();
     }
}
void moveTankLeft()
{
    char next = getCharAtxy( tankX-1 , tankY );
    if(next == ' ')
     {
        eraseTank();
        tankX = tankX - 1;
        printTank();
     }
}
void moveTankUp()
{
    char next = getCharAtxy( tankX , tankY - 1 );
    if(next == ' ')
     {
        eraseTank();
        tankY = tankY - 1;
        printTank();
     }
}
void moveTankDown()
{
    char next = getCharAtxy( tankX , tankY + 2 );
    if(next == ' ')
     {
        eraseTank();
        tankY = tankY + 1;
        printTank();
     }
}

 // Enemy Movement

void moveEnemy()
{
    string enemyDirection = "Up";
    if(enemyDirection== "Up")
     {
        char next = getCharAtxy(enemyX,enemyY - 1);
        if(next== ' ')
         {
            eraseEnemy();
            enemyY--;
            printEnemy();
         }
        if(next== '#') 
         {
            enemyDirection = "Down";
         }
     }
    if(enemyDirection== "Down")
     {
        char next = getCharAtxy(enemyX,enemyY + 4);
        if(next== ' ')
         {
            eraseEnemy();
            enemyY++;
            printEnemy();
         }
        if(next== '#') 
         {
            enemyDirection = "Up";
         }
     }


}

void printBullet(int x,int y)
 {
    gotoxy(x,y);
    cout << ".";
 }
void eraseBullet(int x,int y)
 {
    gotoxy(x,y);
    cout << " ";
 }

void generateBullet()
 {
    bulletX[bulletCount]=tankX+7;
    bulletY[bulletCount]=tankY;
    isBulletActive[bulletCount]= true;
    gotoxy(tankX+7,tankY);
    cout << ".";
    bulletCount++;
 }

void makeBulletInactive(int idx)
 {
    isBulletActive[idx] = false;
 } 
void moveBullet()
 {
    for (int x =0 ; x < bulletCount ; x++)
     {
          if(isBulletActive[x] == true)
           {
               char next = getCharAtxy(bulletX[x] + 1,bulletY[x]);
                if(next != ' ')
                 {
                    eraseBullet(bulletX[x],bulletY[x]);
                    makeBulletInactive(x);
                 }
                 else
                 {
                    eraseBullet(bulletX[x],bulletY[x]);
                    bulletX[x]=bulletX[x]+1;
                    printBullet(bulletX[x],bulletY[x]);
                 }
           }
     }
 }

void bulletCollisionWithEnemy()
 {
     for (int x = 0; x < bulletCount; x++)
      {
         if (isBulletActive[x] == true)
          {
                if (bulletX[x] + 1 == enemyX && bulletY[x] == enemyY || bulletY[x] == enemyY + 2 || bulletY[x] == enemyY + 3 )
                 {
                   addScore(); 
                 }
                if(enemyX - 1 == bulletX[x] && enemyY + 1 == bulletY[x])
                {
                    addScore();
                }
          }
      }
 }



