#define CHEAT 1


/*

����2. �ζ� ��÷��

- ��÷ ��ȣ 6�� + ���ʽ� ��ȣ 1��

- 6�� �Է�

- 1�� : ��÷ ��ȣ 6���� ���� �Է��� 6���� ���ڰ� ������.

- 2�� : ��÷ ��ȣ 5�� + ���ʽ���ȣ 1���� ���� �Է��� 6�� ���ڰ� ��ġ�Ҷ�

- 3�� : ��÷ ��ȣ 5���� ���� �Է��� 5���� ���ڰ� ������

- 4�� : ��÷��ȣ 4���� ���� �Է��� 4���� ���ڰ� ������

- 5�� : ��÷��ȣ 3���� ���� �Է��� 3���� ���ڰ� ������

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
	cout << "�ζ� ������ �����մϴ�." << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << (i + 1);
		cout << "��° �ζǸ� �Է��ϼ���:";
		cin >> lotto[i];
		if (lotto[i] > 45)
		{
			cout << "45������ ���ڸ� �Է� �����մϴ�" << endl;
			i--;
			continue;
		}
		for(int j = 0; j < i; j++)
		{
			if (lotto[i] == lotto[j])
			{
				cout << "�ߺ��� ���ڴ� �Է��� �Ұ��� �մϴ�." << endl;
				i--;
				continue;
			}
		}
	}
#endif
	cout << "�ζ� ���� �Է��� �����մϴ�:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << (i + 1);
		cout << "��° ���ڸ� �Է��ϼ���:";
		cin >> user[i];
		if (user[i] > 45)
		{
			cout << "45������ ���ڸ� �Է� �����մϴ�" << endl;
			i--;
			continue;
		}
		for (int j = 0; j < i; j++)
		{
			if (user[i] == user[j])
			{
				cout << "�ߺ��� ���ڴ� �Է��� �Ұ��� �մϴ�." << endl;
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
	cout << "��÷Ƚ����" << count << "ȸ�̰�" << endl;
	if (lotto[6] = user[6])
	{
		cout << "���ʽ� ���� ��÷ �Ǽ̽��ϴ�." << endl; 
		bonus = 1;
	}
	else
	{
		cout << "���ʽ� ���� �� ������ ���ϼ̽��ϴ�." << endl;
	}
	
	switch(bonus)
	{
		case 1:
			
			if (count == 5)
			{
				cout << "2��!" << endl;
			}
			break;

		case 0:
			if (count == 6)
			{
				cout << "1��!" << endl;
			}
			else if (count == 5)
			{
				cout << "3��!" << endl;
			}
			else if (count == 4)
			{
				cout << "4��!" << endl;
			}
			else if (count == 3)
			{
				cout << "5��!" << endl;
			}
			break;
	}
}
