
#ifndef MAP_H
#define MAP_H

class Map{


public: 
   Map();
  ~Map();

  
void changeBlock(int i,int j,int type);// ���ڷε��ִ� ���� Ư�����ڷ� �����Ͽ� ������
void displayMap(int map[10][10]);///���� �����ֱ� ���� �Լ�. �迭�� �ش��ϴ� ������ changeBlock�� �Ѱ���.
void colorblock(int x,int y,char *str,int color);//�ʿ� ���� �����ִ� �Լ�
void MapEdge(int x1,int x2,int y1,int y2,int color);//���� �׵θ��� �׷��ִ� �Լ�
void Height(int x,int y1,int y2,int color);//y1���� y2���� x��ǥ ��ġ�� �׷��ִ� �Լ�
void Width(int x1,int x2,int y,int color);//x1���� x2���� y��ǥ ��ġ�� �׷��ִ� �Լ�

};


#endif