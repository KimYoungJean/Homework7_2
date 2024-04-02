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

	cout << "주민등록번호 생성기를 실행합니다." << endl;
	cout << "태어나신 연도를 입력해주세요" << endl;
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
	cout << " 태어나신 월일 을 입력해주세요.";
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
			cout << "일년은 12월까지 있습니다." << endl;
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
			cout << "일년은 12월까지 있습니다." << endl;
			goto tryAgain;
		}
		day = (monthDay[2] - '0') * 10 + (monthDay[3] - '0');
		if (month == 2)
		{
			if (yearINT % 4 == 0 && (yearINT % 100 == 0 || yearINT % 400 == 0))
			{
				if (day > 29)
				{
					cout << yearINT << "년" << month << "월은 29일까지 있습니다." << endl;
					goto tryAgain;
				}
			}
			else
			{
				if (day > 28)
				{
					cout << yearINT << "년" << month << "월은 28일까지 있습니다." << endl;
					goto tryAgain;
				}
			}
		}
		if ((month >= 8 && month % 2 == 0) || (month < 8 && month % 2 == 1))
		{
			if (day > 31)
			{
				cout << month << "월은 31일까지 있습니다." << endl;
				goto tryAgain;
			}
		}
		else
		{
			if (day > 30)
			{
				cout << month << "월은 30일까지 있습니다." << endl;
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

	cout << "성별을 입력해주세요" << endl;
	cout << "1. 남자 2. 여자" << endl;
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

	cout << " 생성된 주민등록 번호는 아래와 같습니다." << endl;
	cout << frontNumber << "-" << backNumber[0];
	for (int i = 1; i <= 6; i++) 
	{
		cout << backNumber[i];
	}

}