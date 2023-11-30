#ifndef PUSHMAN_H
#define PUSHMAN_H

class PushMan{
	
	int move_x,move_y; 
	int oldx,oldy;

	public:
		PushMan(int x,int y);
		~PushMan();


void findPushman(int map[10][10]);//푸시맨의 현재 위치 찾기
void moveRight();//오른쪽
void moveLeft(); //왼쪽
void moveUp();   //위
void moveDown(); //아래
void WorkPushman(int map[10][10],int &work);//푸시맨을 실제로 이동 시켜주는 함수
};

#endif