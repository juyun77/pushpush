#ifndef PUSHMAN_H
#define PUSHMAN_H

class PushMan{
	
	int move_x,move_y; 
	int oldx,oldy;

	public:
		PushMan(int x,int y);
		~PushMan();


void findPushman(int map[10][10]);//Ǫ�ø��� ���� ��ġ ã��
void moveRight();//������
void moveLeft(); //����
void moveUp();   //��
void moveDown(); //�Ʒ�
void WorkPushman(int map[10][10],int &work);//Ǫ�ø��� ������ �̵� �����ִ� �Լ�
};

#endif