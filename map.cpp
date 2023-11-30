#include<iostream>
#include"Consola.h"
#include"map.h"

using namespace std;



Map::Map(){};
Map::~Map(){};

void Map::changeBlock(int i,int j,int type)// 숫자로되있는 블럭을 특수문자로 변경하여 보여줌
{
	
	switch(type)
	{
	case 0:colorblock(i,j," ",WHITE) ; break;   //빈공간
	case 1:colorblock(i,j,"〓",BLUE); break;//배경
	case 2:colorblock(i,j,"☆",BLACK); break;   //공
	case 3:colorblock(i,j,"♣",GREEN); break;  //캐릭터
	case 4:colorblock(i,j,"○",LIGHTBLUE); break;//방
	case 5:colorblock(i,j,"★",YELLOW); break;//방에 들어간 공
	case 6:colorblock(i,j,"♣",GREEN); break;    //방위에있는 캐릭터
	case 7:colorblock(i,j,"▩",MAGENTA); break;//벽

	}
	
}

void Map::displayMap(int map[10][10])//맵을 보여주기 위한 함수. 배열에 해당하는 값들을 changeBlock로 넘겨줌.

{
	int type;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{ 
			type=map[j][i];
			changeBlock(i,j,type);
		
		}
}

	void Map::colorblock(int x,int y,char *str,int color) //맵에 색을 입혀주는 함수
	{
		gotoxy((x*2)+25,(y+5));
		textcolor(color);
		cout<<str;
		//textcolor(BLACK);

	}

	void Map::MapEdge(int x1,int x2,int y1,int y2,int color)//맵의 테두리를 그려주는 함수
	{
		 Width(x1,x2,y1,color);
		Width(x1,x2+1,y2,color);
	    Height(x1,y1,y2,color);
	    Height(x2,y1,y2,color);
	}


	void Map::Width(int x1,int x2,int y,int color) //x1부터 x2까지 y좌표 위치에 색을 그려주는 함수
	{
		textbackground(color);

		for(int i=x1;i<x2;i++)
		{
			gotoxy(i,y);
			cout<<" ";
		}
	
	}
	
	void Map::Height(int x,int y1,int y2,int color)//y1부터 y2까지 x좌표 위치에 그려주는 함수
	{
		textbackground(color);
		for(int j=y1;j<y2;j++)
		{
			gotoxy(x,j);
			cout<<" ";
		}
	
	}