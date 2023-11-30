

#include"pushman.h"



PushMan::PushMan(int x,int y)
{
	move_x=x;move_y=y;  //멤버변수 초기화
}
PushMan::~PushMan(){}

void PushMan:: findPushman(int map[10][10]){          //푸시맨의 현재 위치 찾기
 for(int i=0;i<10;i++)
  for(int j=0;j<10;j++)
   if(map[i][j]==3||map[i][j]==6){
  
	oldx=j;//푸시맨의 현재위치를
	oldy=i;//  저장
    }
}

  void PushMan:: moveRight()//오른쪽
{
 move_x=1;
 move_y=0;

}

void PushMan:: moveLeft()//왼쪽
{
 move_x=-1;
 move_y=0;

}

void PushMan:: moveUp()//위
{
 move_x=0;
 move_y=-1;

}

void  PushMan::moveDown()//아래
{

 move_x=0;
 move_y=1;
}


void PushMan::WorkPushman(int map[10][10],int &work)//푸시맨을 실제로 이동 시켜주는 함수

{
 if(map[oldy][oldx]==3)//캐릭터가 빈공간 위에 있을때
 {
  if(map[oldy+move_y][oldx+move_x]==0)//가는 방향이 빈공간일 경우
  {
   map[oldy+move_y][oldx+move_x]=3;
   map[oldy][oldx]=0;
   work++;//걸음수 1증가
  }
  else if(map[oldy+move_y][oldx+move_x]==2)//가는 방향에 공이 있을 경우
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//공앞에 벽이나 공이나 꽉찬방이 있을때
   {

    return;


   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//공 앞에 방이 있을 경우
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=0;
	work++;//걸음수 1증가
   }
   else
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=0;
	work++;//걸음수 1증가

   }

  }

  else if(map[oldy+move_y][oldx+move_x]==1)//가는 방향에 벽이 있을 경우
  { 
   
   return;
  }
  else if(map[oldy+move_y][oldx+move_x]==5)//가는 방향에 꽉찬방이 있을경우
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==0)//꽉찬방 앞이 빈공간이 있을 경우
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=0;
	work++;//걸음수 1증가
   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//꽉찬방앞에 벽이나 공이나 꽉찬방이 있을때
   {
   
    return;

   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//꽉찬방 앞에 방이 있을경우
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=0;
	work++;//걸음수 1증가
   }
  }
  else if(map[oldy+move_y][oldx+move_x]==4)//가는 방향이 방일 경우
  {
   map[oldy+move_y][oldx+move_x]=6;
   map[oldy][oldx]=0;
   work++;//걸음수 1증가

  }

 }

 else if(map[oldy][oldx]==6)
 {
  if(map[oldy+move_y][oldx+move_x]==0)//가는 방향이 빈공간일 경우
  {
   map[oldy+move_y][oldx+move_x]=3;
   map[oldy][oldx]=4;
   work++;//걸음수 1증가
  }
  else if(map[oldy+move_y][oldx+move_x]==2)//가는 방향에 공이 있을 경우
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//공앞에 벽이나 공이나 꽉찬방이 있을때
   {
   
    return;

   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//공 앞에 방이 있을 경우
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=4;
	work++;//걸음수 1증가
   }
   else
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=3;
    map[oldy][oldx]=4;
	work++;//걸음수 1증가

   }

  }

  else if(map[oldy+move_y][oldx+move_x]==7)//가는 방향에 벽이 있을 경우
  { 
   
   return;
  }
  else if(map[oldy+move_y][oldx+move_x]==5)//가는 방향에 꽉찬방이 있을경우
  {
   if(map[oldy+move_y*2][oldx+move_x*2]==0)//꽉찬방 앞이 빈공간이 있을 경우
   {
    map[oldy+move_y*2][oldx+move_x*2]=2;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=4;
	work++;//걸음수 1증가
   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==7||map[oldy+move_y*2][oldx+move_x*2]==2||map[oldy+move_y*2][oldx+move_x*2]==5)//꽉찬방앞에 벽이나 공이나 꽉찬방이 있을때
   {

    return;

   }
   else if(map[oldy+move_y*2][oldx+move_x*2]==4)//꽉찬방 앞에 방이 있을경우
   {
    map[oldy+move_y*2][oldx+move_x*2]=5;
    map[oldy+move_y][oldx+move_x]=6;
    map[oldy][oldx]=4;
	work++;//걸음수 1증가
   }
  }
  else if(map[oldy+move_y][oldx+move_x]==4)//가는 방향이 방일 경우
  {
   map[oldy+move_y][oldx+move_x]=6;
   map[oldy][oldx]=4;
   work++;//걸음수 1증가
  }

 }
 move_x=0;   // 방향키가 아닌 다른키가 눌렸을때
 move_y=0;   // 캐릭터가 움직이지 않도록 0으로 다시 초기화 

}




