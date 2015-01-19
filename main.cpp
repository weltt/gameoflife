#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#define FALSE 0
#define TRUE 1

using namespace std;

class board {
  public:
    bool point[84][26];
};

const char ALIVE = 'X';
const char DEAD = '_';

void intBRD(board &intb) {
  for(int i=0; i < 84; i++){
    for(int j=0; j < 25; j++){
      intb.point[i][j]=0;
    }
  }
}

// IN: board class by ref
// OUT: Screen print
void drawBRD(board &draw) { 
  for(int j=1; j < 23; j++) {
    for (int i=1; i < 81; i++) {
      if(draw.point[i][j]) {
        cout << ALIVE;
      } else {
        cout << DEAD;
      }
    }
      cout << endl;
  }
}

// IN: board class by reference
// OUT: updated values
board updBRD(board &upd, board &newbrd) {
  for(int j=0; j < 26; j++) {
    for(int i=0; i < 84; i++) {
      int l=0;
      int x=0,y=0;
      for(x=i-1; x<=i+1; x++) {
          for(y=j-1; y<=j+1; y++){
            if(!(x==i && y==j) && (x >= 0 && y >= 0) && (x <= 84 && y <= 26)){
              if(upd.point[x][y]) l++;
            }
          }
      }
      // LOGIC
      /*if (upd.point[i-1][j+1]) l++;
      if (upd.point[i-1][j]) l++;
      if (upd.point[i-1][j-1]) l++;
      if (upd.point[i][j+1]) l++;
      if (upd.point[i][j-1]) l++;
      if (upd.point[i+1][j+1]) l++;
      if (upd.point[i+1][j]) l++;
      if (upd.point[i+1][j-1]) l++;
      */
      // Rules
      // 1) Any cell with less than two neighbors dies, underpopulation.
      // 2) Any cell with two or three continues on.
      // q
      // 3) Any cell with more than 3, dies.
      // 4) Dead cell with three neighboards becomes alive.

      // Rule 1
      if (l<2) newbrd.point[i][j] = FALSE;
      // Rule 2 
      if ((l==2 || l==3) && upd.point[i][j]) newbrd.point[i][j]; 
      // Rule 3
      if (l>3) newbrd.point[i][j] = FALSE;
      // Rule 4 
      if (!upd.point[i][j] && l==3) newbrd.point[i][j] = TRUE;
      
      //upd.point[0][j]=0;
      //upd.point[81][j]=0;
      //newbrd.point[i][23]=0;
      //newbrd.point[i][0]=0;
    }
     //newbrd.point[0][j]=0;
     //newbrd.point[81][j]=0;
  }
}

void clnBRD(board &newbrd){
      for(int j=0; j < 26; j++) {
        for(int i=0; i < 84; i++) {
          if((j==0 || j>24) || (i == 0 || i >= 81)) {
              newbrd.point[i][j]=0;
            }
        }
      }
}

void rndBRD(board &rnd) {
  srand(time(NULL));
  int x=rand()%82+1, y=rand()%23+1;
  for(int i=1; i<=12; i++) {
    rnd.point[x+(rand()%i)][y+(rand()%i)]=TRUE;
  }
}

void cpBRD(board &old, board &newb) {
 for(int j=1; j < 26; j++) {
  for(int i=1; i < 84; i++) {
    newb.point[i][j]=old.point[i][j];
  }
 }
}

void insGLDR(board &brd) {
  char h;
  cout << "Enter a glider: (y or n)" << endl;
  cin >> h;
  if (h == 'y') {
  int x, y;
  cout << "Enter the coordinates";
    cin >> x >> y;
    brd.point[x][y+2]=1;
    brd.point[x+1][y]=1;
    brd.point[x+1][y+2]=1;
    brd.point[x+2][y+1]=1;
    brd.point[x+2][y+2]=1;
  }
}


// IN: board by ref
// OUT: print a glider cannon
void insCNN(board &brd) {
  char h;
  // clean the board
  intBRD(brd);
  cout << "Insert a cannon: (y or n)" << endl;
  cin >> h;
  if (h == 'y') {
    int x, y;
    cout << "Enter the coordinates";
    cin >> x >> y;
    x = x % 40;
    y = y % 10;
    brd.point[x+24][y]=1;
    brd.point[x+22][y+1]=1;
    brd.point[x+24][y+1]=1;
    brd.point[x+12][y+2]=1;
    brd.point[x+13][y+2]=1;
    brd.point[x+20][y+2]=1;
    brd.point[x+21][y+2]=1;
    brd.point[x+34][y+2]=1;
    brd.point[x+35][y+2]=1;
    brd.point[x+11][y+3]=1;
    brd.point[x+15][y+3]=1;
    brd.point[x+20][y+3]=1;
    brd.point[x+21][y+3]=1;
    brd.point[x+34][y+3]=1;
    brd.point[x+35][y+3]=1;
    brd.point[x][y+4]=1;
    brd.point[x+1][y+4]=1;
    brd.point[x+10][y+4]=1;
    brd.point[x+16][y+4]=1;
    brd.point[x+20][y+4]=1;
    brd.point[x+21][y+4]=1;
    brd.point[x][y+5]=1;
    brd.point[x+1][y+5]=1;
    brd.point[x+10][y+5]=1;
    brd.point[x+14][y+5]=1;
    brd.point[x+16][y+5]=1;
    brd.point[x+17][y+5]=1;
    brd.point[x+22][y+5]=1;
    brd.point[x+24][y+5]=1;
    brd.point[x+10][y+6]=1;
    brd.point[x+16][y+6]=1;
    brd.point[x+24][y+6]=1;
    brd.point[x+11][y+7]=1;
    brd.point[x+15][y+7]=1;
    brd.point[x+12][y+8]=1;
    brd.point[x+13][y+8]=1;
  }
}


int main(int argc, char *argv) {
  int c; // COUNT
  char ch; // CHOICE
  board gamebrd, newbrd;

  intBRD(gamebrd);
  intBRD(newbrd);
  drawBRD(gamebrd);
  insCNN(gamebrd);
  insGLDR(gamebrd);
  
  while(1) {
    cpBRD(gamebrd, newbrd);
    updBRD(gamebrd, newbrd);
    cpBRD(newbrd, gamebrd);
    drawBRD(gamebrd);
    c++;
    if(c>25) {
      c=0;
      cout << "Press s to stop, n for new random board , g for glider, c for cannon, other key to continue" << endl;
      ch=getchar();
      if (ch == 's') {
       exit(1);
      } else if (ch == 'n') {
        intBRD(gamebrd);
        intBRD(newbrd);
        rndBRD(gamebrd);
        drawBRD(gamebrd);
      } else if (ch == 'g') {
        insGLDR(gamebrd);
      } else if (ch == 'c') {
        insCNN(gamebrd);
      } else {
      }
    }
    clnBRD(gamebrd);
    usleep(20000);
    system("clear");
  } 
}
