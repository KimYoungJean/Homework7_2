#include <iostream>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

char frontNumber[10];
char backNumber[10];


char year[5];
char monthDay[5];
int yearINT;
int month;
int day;
int sex;

int count = 0;

void main()
{
	srand(time(NULL));

	cout << "�ֹε�Ϲ�ȣ �����⸦ �����մϴ�." << endl;
	cout << "�¾�� ������ �Է����ּ���" << endl;
	cin >> year;

	for (int i = 0; i <= 5; i++)
	{
		if (year[i] != NULL)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	switch (count)
	{
	case 2:
		yearINT = (year[0] - '0') * 10 + (year[1] - '0');
		frontNumber[0] = year[0];
		frontNumber[1] = year[1];
		if (yearINT <= 50)
		{
			yearINT = 2000 + yearINT;
		}
		else
		{
			yearINT = 1900 + yearINT;
		}
		break;

	case 4:
		yearINT = (year[0] - '0') * 1000 + (year[1] - '0') * 100 + (year[2] - '0') * 10 + (year[3] - '0');
		frontNumber[0] = year[2];
		frontNumber[1] = year[3];
		break;
	default:
		break;
	}
tryAgain:
	cout << " �¾�� ���� �� �Է����ּ���.";
	cin >> monthDay;

	count = 0;
	for (int i = 0; i <= 5; i++)
	{
		if (monthDay[i] != NULL)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	switch (count)
	{
	case 2:
		frontNumber[2] = '0';
		frontNumber[3] = monthDay[0];
		frontNumber[4] = '0';
		frontNumber[5] = monthDay[1];
		break;
	case 3:
		month = (monthDay[0] - '0') * 10 + (monthDay[1] - '0');
		if (month > 12)
		{
			cout << "�ϳ��� 12������ �ֽ��ϴ�." << endl;
			goto tryAgain;
		}

		frontNumber[2] = monthDay[0];
		frontNumber[3] = monthDay[1];
		frontNumber[4] = '0';
		frontNumber[5] = monthDay[2];
		break;

	case 4:
		month = (monthDay[0] - '0') * 10 + (monthDay[1] - '0');
		if (month > 12)
		{
			cout << "�ϳ��� 12������ �ֽ��ϴ�." << endl;
			goto tryAgain;
		}
		day = (monthDay[2] - '0') * 10 + (monthDay[3] - '0');
		if (month == 2)
		{
			if (yearINT % 4 == 0 && (yearINT % 100 == 0 || yearINT % 400 == 0))
			{
				if (day > 29)
				{
					cout << yearINT << "��" << month << "���� 29�ϱ��� �ֽ��ϴ�." << endl;
					goto tryAgain;
				}
			}
			else
			{
				if (day > 28)
				{
					cout << yearINT << "��" << month << "���� 28�ϱ��� �ֽ��ϴ�." << endl;
					goto tryAgain;
				}
			}
		}
		if ((month >= 8 && month % 2 == 0) || (month < 8 && month % 2 == 1))
		{
			if (day > 31)
			{
				cout << month << "���� 31�ϱ��� �ֽ��ϴ�." << endl;
				goto tryAgain;
			}
		}
		else
		{
			if (day > 30)
			{
				cout << month << "���� 30�ϱ��� �ֽ��ϴ�." << endl;
				goto tryAgain;
			}
		}
		frontNumber[2] = monthDay[0];
		frontNumber[3] = monthDay[1];
		frontNumber[4] = monthDay[2];
		frontNumber[5] = monthDay[3];
		break;
	default:
		break;
	}

	cout << "������ �Է����ּ���" << endl;
	cout << "1. ���� 2. ����" << endl;
	cin >> sex;


	switch (sex)
	{
	case 1:
		if (yearINT <= 2000)
			backNumber[0] = '1';
		else
			backNumber[0] = '3';
		break;
	case 2:
		if (yearINT <= 2000)
			backNumber[0] = '2';
		else
			backNumber[0] = '4';
		break;
	}

	for (int i = 1; i <= 6; i++)
	{

		backNumber[i] = '0' + rand() % 9 + 1;
	}

	cout << " ������ �ֹε�� ��ȣ�� �Ʒ��� �����ϴ�." << endl;
	cout << frontNumber << "-" << backNumber[0];
	for (int i = 1; i <= 6; i++) 
	{
		cout << backNumber[i];
	}

}