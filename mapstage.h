
int mapstage[5][10][10]={          ////// 1:배경
 {
   1,1,1,1,1 ,1,1,1,1,1,            //////2:공
   1,1,1,1,1 ,1,1,1,1,1,
   1,1,1,1,1 ,1,1,1,1,1,           ////// 3:캐릭터
   7,7,7,7,7 ,7,7,7,7,1,
   7,0,2,0,0 ,0,0,4,7,1,           ////// 4:방

   7,3,2,0,0 ,0,0,4,7,1,           ////// 5:공이들어있는방
   7,0,2,0,0 ,0,0,4,7,1,
   7,7,7,7,7 ,7,7,7,7,1,           
   1,1,1,1,1 ,1,1,1,1,1,           ////// 6:방위에있는 캐릭터 
   1,1,1,1,1 ,1,1,1,1,1           /////7:벽
 },
 {
   1,1,1,1,1, 1,1,1,1,1,
   7,7,7,7,7, 1,1,1,1,1,
   7,3,0,0,7, 1,1,1,1,1,
   7,0,2,2,7, 1,7,7,7,1,
   7,0,2,0,7, 1,7,4,7,1,

   7,7,7,0,7, 7,7,4,7,1,
   7,0,0,0,0, 0,0,4,7,1,
   7,0,0,0,0, 7,0,0,7,1,
   7,0,0,0,0, 7,7,7,7,1,
   7,7,7,7,7, 7,1,1,1,1
  },
  {
    1,1,1,1,1, 1,1,1,1,1,
    1,7,7,7,7, 1,1,1,1,1,
    1,7,3,0,7, 7,7,1,1,1,
    1,7,0,2,0, 0,7,1,1,1,
    7,7,7,0,7, 0,7,7,1,1,

    7,4,7,0,7, 0,0,7,1,1,
    7,4,2,0,0, 7,0,7,1,1,
    7,4,0,0,0, 2,0,7,1,1,
    7,7,7,7,7, 7,7,7,1,1,
    1,1,1,1,1, 1,1,1,1,1,

  },
  {
    7,7,7,7,7, 7,7,7,7,7,
    7,4,4,0,0, 0,0,3,0,7,
    7,4,4,2,0, 0,7,0,0,7,
    7,0,0,7,2, 7,7,0,7,7,
    7,0,2,0,0, 0,0,0,7,1,

    7,7,7,7,7, 0,7,0,7,1,
    1,1,7,0,2, 0,0,0,7,1,
    1,1,7,0,0, 0,0,0,7,1,
    1,1,7,7,7, 7,7,7,7,1,
    1,1,1,1,1, 1,1,1,1,1
   },
   {
     1,1,1,1,1, 1,1,1,1,1,
     1,1,7,7,7, 7,7,7,1,1,
     1,1,7,0,0, 0,0,7,1,1,
     7,7,7,2,2, 2,0,7,1,1,
     7,3,0,2,4, 4,0,7,1,1,
     7,0,2,4,4, 4,7,7,1,1,
     7,7,7,7,0, 0,7,1,1,1,
     1,1,1,7,7, 7,7,1,1,1,
     1,1,1,1,1, 1,1,1,1,1
   }
};

