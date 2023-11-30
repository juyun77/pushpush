
#ifndef MAP_H
#define MAP_H

class Map{


public: 
   Map();
  ~Map();

  
void changeBlock(int i,int j,int type);// 숫자로되있는 블럭을 특수문자로 변경하여 보여줌
void displayMap(int map[10][10]);///맵을 보여주기 위한 함수. 배열에 해당하는 값들을 changeBlock로 넘겨줌.
void colorblock(int x,int y,char *str,int color);//맵에 색을 입혀주는 함수
void MapEdge(int x1,int x2,int y1,int y2,int color);//맵의 테두리를 그려주는 함수
void Height(int x,int y1,int y2,int color);//y1부터 y2까지 x좌표 위치에 그려주는 함수
void Width(int x1,int x2,int y,int color);//x1부터 x2까지 y좌표 위치에 그려주는 함수

};


#endif