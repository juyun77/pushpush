#ifndef COLOR_H
#define COLOR_H
#include<iostream>
#include"Consola.h"
using namespace std;
class Color{

public:
	


	void colorblock(int x,int y,char *str,int color)
	{
		gotoxy((x*2)+25,(y+5));
		textcolor(color);
		cout<<str;

	}

	void MapEdge(int x1,int x2,int y1,int y2,int color)
	{
	    Width(x1,x2,y1,color);
		Width(x1,x2+1,y2,color);
	    Height(x1,y1,y2,color);
	    Height(x2,y1,y2,color);
	}

	void Width(int x1,int x2,int y,int color)
	{
		textbackground(color);
		for(;x1<x2;x1++)
		{
			gotoxy(x1,y);
			
			cout<<" ";
		}
	
	}
	
	void Height(int x,int y1,int y2,int color)
	{
		textbackground(color);
		for(;y1<y2;y1++)
		{
			gotoxy(x,y1);
			
			cout<<" ";
		}
	
	}
};

#endif