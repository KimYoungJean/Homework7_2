#define CHEAT 1


/*

과제2. 로또 당첨기

- 당첨 번호 6개 + 보너스 번호 1개

- 6개 입력

- 1등 : 당첨 번호 6개와 내가 입력한 6개의 숫자가 같을때.

- 2등 : 당첨 번호 5개 + 보너스번호 1개와 내가 입력한 6개 숫자가 일치할때

- 3등 : 당첨 번호 5개와 내가 입력한 5개의 숫자가 같을때

- 4등 : 당첨번호 4개와 내가 입력한 4개의 숫자가 같을때

- 5등 : 당첨번호 3개와 내가 입력한 3개의 숫자가 같을때

*/

#include <iostream>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

int lotto[7] = { 0,0,0,0,0,0,0 };
int user[7];
int count = 0;
bool bonus = 0;
void main()
{
	srand(time(NULL));
#if(CHEAT==0)	
	for (int i = 0; i < 7; i++)
	{
		lotto[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (lotto[i] == lotto[j])
			{
				i--;
				continue;
			}
		}
	}
#endif
#if(CHEAT==1)	
	cout << "로또 조작을 시작합니다." << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << (i + 1);
		cout << "번째 로또를 입력하세요:";
		cin >> lotto[i];
		if (lotto[i] > 45)
		{
			cout << "45이하의 숫자만 입력 가능합니다" << endl;
			i--;
			continue;
		}
		for(int j = 0; j < i; j++)
		{
			if (lotto[i] == lotto[j])
			{
				cout << "중복된 숫자는 입력이 불가능 합니다." << endl;
				i--;
				continue;
			}
		}
	}
#endif
	cout << "로또 용지 입력을 시작합니다:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << (i + 1);
		cout << "번째 숫자를 입력하세요:";
		cin >> user[i];
		if (user[i] > 45)
		{
			cout << "45이하의 숫자만 입력 가능합니다" << endl;
			i--;
			continue;
		}
		for (int j = 0; j < i; j++)
		{
			if (user[i] == user[j])
			{
				cout << "중복된 숫자는 입력이 불가능 합니다." << endl;
				i--;
				continue;
			}
		}
	}
	for (int n= 0; n<6;n++)
	{
		for (int m = 0; m < 6; m++)
		{
			if (user[n] == lotto[m])
			{
				count++;
				lotto[m] = 0;
			}
		}
	}
	cout << "당첨횟수는" << count << "회이고" << endl;
	if (lotto[6] = user[6])
	{
		cout << "보너스 숫자 당첨 되셨습니다." << endl; 
		bonus = 1;
	}
	else
	{
		cout << "보너스 숫자 는 맞추지 못하셨습니다." << endl;
	}
	
	switch(bonus)
	{
		case 1:
			
			if (count == 5)
			{
				cout << "2등!" << endl;
			}
			break;

		case 0:
			if (count == 6)
			{
				cout << "1등!" << endl;
			}
			else if (count == 5)
			{
				cout << "3등!" << endl;
			}
			else if (count == 4)
			{
				cout << "4등!" << endl;
			}
			else if (count == 3)
			{
				cout << "5등!" << endl;
			}
			break;
	}
}
