#include<iostream>
#include"score.h"

	void Score::TotalScore(int scorework)//�Ѱ������� ���� ������ �������
	{
		if(290<=scorework&&scorework<300)
			cout<<"100�� �Դϴ�.";
		else if(320<=scorework&&scorework<330)
			cout<<"95�� �Դϴ�.";
		else if(330<=scorework&&scorework<340)
			cout<<"90�� �Դϴ�.";
		else if(340<=scorework&&scorework<350)
			cout<<"85�� �Դϴ�.";
		else if(350<=scorework&&scorework<360)
			cout<<"80�� �Դϴ�.";
		else if(360<=scorework&&scorework<370)
			cout<<"75�� �Դϴ�.";
		else if(370<=scorework&&scorework<380)
			cout<<"70�� �Դϴ�.";
		else if(380<=scorework&&scorework<390)
			cout<<"65�� �Դϴ�.";
		else if(390<=scorework&&scorework<400)
		    cout<<"60�� �Դϴ�.";
		else
			 cout<<"50�� �Դϴ�.";

	}
