

#include"pushman.h"



PushMan::PushMan(int x,int y)
{
	move_x=x;move_y=y;  //������� �ʱ�ȭ
}
PushMan::~PushMan(){}

void PushMan:: findPushman(int map[10][10]){          //Ǫ�ø��� ���� ��ġ ã��
 for(int i=0;i<10;i++)
  for(int j=0;j<10;j++)
   if(map[i][j]==3||map[i][j]==6){
  
	oldx=j;//Ǫ�ø��� ������ġ��
	oldy=i;//  ����
    }
}

  void PushMan:: moveRight()//������
{
 move_x=1;
 move_y=0;

}

void PushMan:: moveLeft()//����
{
 move_x=-1;
 move_y=0;

}

void PushMan:: moveUp()//��
{
 move_x=0;
 move_y=-1;

}

void  PushMan::moveDown()//�Ʒ�
{

 move_x=0;
 move_y=1;
}


void PushMan::WorkPushman(int map[10][10],int &work)//Ǫ�ø��� ������ �̵� �����ִ� �Լ�

{
 if(map[oldy][oldx]==3)//ĳ���Ͱ� ����� ���� ������
 {
  if(map[oldy+move_y][oldx+move_x]==0)//���� ������ ������� ���
  {
   map[oldy+move_y][oldx+move_x]=3;
   map[oldy][oldx]=0;
   work++;//������ 1����
  }
  else if(map[oldy+move_y][oldx+move_x]==2)//���� ���⿡ ���� ���� ���
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//���տ� ���̳� ���̳� �������� ������
   {

    return;


   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//�� �տ� ���� ���� ���
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=0;
	work++;//������ 1����
   }
   else
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=0;
	work++;//������ 1����

   }

  }

  else if(map[oldy+move_y][oldx+move_x]==1)//���� ���⿡ ���� ���� ���
  { 
   
   return;
  }
  else if(map[oldy+move_y][oldx+move_x]==5)//���� ���⿡ �������� �������
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==0)//������ ���� ������� ���� ���
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=0;
	work++;//������ 1����
   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//������տ� ���̳� ���̳� �������� ������
   {
   
    return;

   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//������ �տ� ���� �������
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=0;
	work++;//������ 1����
   }
  }
  else if(map[oldy+move_y][oldx+move_x]==4)//���� ������ ���� ���
  {
   map[oldy+move_y][oldx+move_x]=6;
   map[oldy][oldx]=0;
   work++;//������ 1����

  }

 }

 else if(map[oldy][oldx]==6)
 {
  if(map[oldy+move_y][oldx+move_x]==0)//���� ������ ������� ���
  {
   map[oldy+move_y][oldx+move_x]=3;
   map[oldy][oldx]=4;
   work++;//������ 1����
  }
  else if(map[oldy+move_y][oldx+move_x]==2)//���� ���⿡ ���� ���� ���
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//���տ� ���̳� ���̳� �������� ������
   {
   
    return;

   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//�� �տ� ���� ���� ���
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=4;
	work++;//������ 1����
   }
   else
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=4;
	work++;//������ 1����

   }

  }

  else if(map[oldy+move_y][oldx+move_x]==7)//���� ���⿡ ���� ���� ���
  { 
   
   return;
  }
  else if(map[oldy+move_y][oldx+move_x]==5)//���� ���⿡ �������� �������
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==0)//������ ���� ������� ���� ���
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=4;
	work++;//������ 1����
   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//������տ� ���̳� ���̳� �������� ������
   {

    return;

   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//������ �տ� ���� �������
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=4;
	work++;//������ 1����
   }
  }
  else if(map[oldy+move_y][oldx+move_x]==4)//���� ������ ���� ���
  {
   map[oldy+move_y][oldx+move_x]=6;
   map[oldy][oldx]=4;
   work++;//������ 1����
  }

 }
 move_x=0;   // ����Ű�� �ƴ� �ٸ�Ű�� ��������
 move_y=0;   // ĳ���Ͱ� �������� �ʵ��� 0���� �ٽ� �ʱ�ȭ 

}




