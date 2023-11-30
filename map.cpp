#include<iostream>
#include"Consola.h"
#include"map.h"

using namespace std;



Map::Map(){};
Map::~Map(){};

void Map::changeBlock(int i,int j,int type)// ���ڷε��ִ� ���� Ư�����ڷ� �����Ͽ� ������
{
	
	switch(type)
	{
	case 0:colorblock(i,j," ",WHITE) ; break;   //�����
	case 1:colorblock(i,j,"��",BLUE); break;//���
	case 2:colorblock(i,j,"��",BLACK); break;   //��
	case 3:colorblock(i,j,"��",GREEN); break;  //ĳ����
	case 4:colorblock(i,j,"��",LIGHTBLUE); break;//��
	case 5:colorblock(i,j,"��",YELLOW); break;//�濡 �� ��
	case 6:colorblock(i,j,"��",GREEN); break;    //�������ִ� ĳ����
	case 7:colorblock(i,j,"��",MAGENTA); break;//��

	}
	
}

void Map::displayMap(int map[10][10])//���� �����ֱ� ���� �Լ�. �迭�� �ش��ϴ� ������ changeBlock�� �Ѱ���.

{
	int type;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{ 
			type=map[j][i];
			changeBlock(i,j,type);
		
		}
}

	void Map::colorblock(int x,int y,char *str,int color) //�ʿ� ���� �����ִ� �Լ�
	{
		gotoxy((x*2)+25,(y+5));
		textcolor(color);
		cout<<str;
		//textcolor(BLACK);

	}

	void Map::MapEdge(int x1,int x2,int y1,int y2,int color)//���� �׵θ��� �׷��ִ� �Լ�
	{
		 Width(x1,x2,y1,color);
		Width(x1,x2+1,y2,color);
	    Height(x1,y1,y2,color);
	    Height(x2,y1,y2,color);
	}


	void Map::Width(int x1,int x2,int y,int color) //x1���� x2���� y��ǥ ��ġ�� ���� �׷��ִ� �Լ�
	{
		textbackground(color);

		for(int i=x1;i<x2;i++)
		{
			gotoxy(i,y);
			cout<<" ";
		}
	
	}
	
	void Map::Height(int x,int y1,int y2,int color)//y1���� y2���� x��ǥ ��ġ�� �׷��ִ� �Լ�
	{
		textbackground(color);
		for(int j=y1;j<y2;j++)
		{
			gotoxy(x,j);
			cout<<" ";
		}
	
	}