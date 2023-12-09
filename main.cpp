#include <iostream>
#include <locale.h>
using namespace std;
// Proc32 Boolean14 Integer26


void InvDigits();				//Proc9  
bool CheckDigit(int& K);		//Функція для перевірки 0 < K < 10000
void SwapDigits(int& K);

void Boolean19();							//Boolean19
int CheckDig(int A, int B, int C);		//Функція перевірки чисел на коректність
bool SameOpposite(int A, int B, int C);		//Функція вирішення Boolean19

void Integer20();							//Integer20
int EnterInteger();							//Функція вводу даних
int Solving(int N);							//Функція вирішення задачі Integer20
void cOutInteger(int hours);					//Функція виводу даних



int main()
{
	setlocale(LC_ALL, "Ukrainian");
	int choice = 0;
	cout << "Оберіть задачу для вирішення: "
		"\n1.InvDigits"
		"\n2.Boolean19"
		"\n3.Integer20" << endl;
	cin >> choice;

	switch (choice) //Меню
	{
	case 1: {
		InvDigits();
		break;
	}
	case 2: {
		Boolean19();
		break;
	}
	case 3: {
		Integer20();
		break;
	}
	default:
	{
		cout << "Такого варіанту немає";
	}
	}
}
void InvDigits()					//Proс9
{
	int K1, K2, K3, K4, K5;
	cout << "Введіть число: ";
	cin >> K1;
	if (CheckDigit(K1))
	{
		SwapDigits(K1);
	}

	cout << "Введіть число: ";
	cin >> K2;
	if (CheckDigit(K2))
	{
		SwapDigits(K2);
	}

	cout << "Введіть число: ";
	cin >> K3;
	if (CheckDigit(K3))
	{
		SwapDigits(K3);
	}

	cout << "Введіть число: ";
	cin >> K4;
	if (CheckDigit(K4))
	{
		SwapDigits(K4);
	}

	cout << "Введіть число: ";
	cin >> K5;
	if (CheckDigit(K5))
	{
		SwapDigits(K5);
	}

}

bool CheckDigit(int& K)
{
	if(K > 0 && K < 10000)
	{
		return K;
	}
	else
	{
		cout << "K більше за 10000 або менше за 0" << endl;
		exit(0);
	}
}

void SwapDigits(int& K)
{
	int thousands = K / 1000;
	int hundreds = (K % 1000)/100;
	int tens = ((K % 1000) % 100)/10;
	int numbers = (((K % 1000) % 100) %10);

	int temp1 = numbers;
	int temp2 = hundreds;

	numbers = thousands;
	hundreds = tens;
	tens = temp2;
	thousands = temp1;

	cout << "Зворотнє число: " << thousands << hundreds << tens << numbers << endl;

}

void Boolean19()					//Boolean19
{
	int A, B, C;

	cout << "Введiть A: ";
	cin >> A;

	cout << "Введiть B: ";
	cin >> B;

	cout << "Введiть C: ";
	cin >> C;

	CheckDig(A, B, C);

	cout << "Серед трьох даних цілих чисел є хоча б одна пара взаємно протилежних: " << boolalpha << SameOpposite(A, B, C);
}

int CheckDig(int A, int B, int C)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nПомилка";
		exit(0);
	}
	return 0;
}

bool SameOpposite(int A, int B, int C)
{
	bool SameOpposite = (C == A*-1 || B == A*-1 || C == B*-1);
	return SameOpposite;
}

void Integer20()					//Integer20
{

	int N = EnterInteger();
	int hours = Solving(N);
	cOutInteger(hours);
}

int EnterInteger()
{
	int N = 0;
	cout << "Введіть час у секундах: ";
	cin >> N;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nПомилка";
		exit(0);
	}
	while (!cin.fail())
	{
		if (N > 0 && N < 86401)
		{
			break;
		}
		else
		{
			cout << "не входить у діапазон 0-86401";
			exit(0);
		}
	}
	return N;
}

int Solving(int N)
{
	int hours = N / 3600;
	return hours;
}

void cOutInteger(int hours)
{
	cout << "Часів у секундах: " << hours;
}