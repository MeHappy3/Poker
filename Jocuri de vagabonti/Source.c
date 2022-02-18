
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <wchar.h>
#include <Windows.h>
#include <math.h>

void rnd()
{
	wprintf(L"\n");
}
int random(int* folosit, int n)
{

	int r = rand() % 52, ok = 1, k;
	for (int i = 0; i < n; i++)
		if (*(folosit + i) == r)
			ok = 0;
	if (ok == 1)
	{
		folosit[n] = r;
		return r;
	}
	else
		return random(folosit, n);
}
void spc()
{
	wprintf(L"             ");
}
void carte2(int* x, int* y, int n, int a)
{
	int i = 0, k;
	for (i = 0; i < n; i++)
	{

		if (i == 2)
			spc();
		else
			wprintf(L"  ┌─────────┐");
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i < 2)
			k = *(x + i);
		else
			k = *(y + i - 3);
		if (i == 2)
			spc();
		else {
			if (i > 2 && a == 1)
				wprintf(L"  │░░░░░░░░░│");
			else
			{
				wprintf(L"  │");
				switch (k % 13)
				{
				case 0: wprintf(L"A"); break;
				case 10: wprintf(L"J"); break;
				case 11: wprintf(L"Q"); break;
				case 12: wprintf(L"K"); break;
				default: wprintf(L"%d", k % 13 + 1);
					break;
				}
				switch (k / 13)
				{
				case 0:if (k % 13 == 9)
					wprintf(L"\x2660      │");
					  else
					wprintf(L"\x2660       │");
					break;
				case 1: if (k % 13 == 9)
					wprintf(L"\x2663      │");
					  else
					wprintf(L"\x2663       │");
					break;
				case 2: if (k % 13 == 9)
					wprintf(L"\x2665      │");
					  else
					wprintf(L"\x2665       │");
					break;
				case 3: if (k % 13 == 9)
					wprintf(L"\x2666      │");
					  else
					wprintf(L"\x2666       │");
					break;
				default:
					break;
				}
			}
		}
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i == 2)
			spc();
		else if (i > 2 && a == 1)
			wprintf(L"  │░░░░░░░░░│");
		else
			wprintf(L"  │         │");
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i == 2)
			spc();
		else if (i > 2 && a == 1)
			wprintf(L"  │░░░░░░░░░│");
		else
			wprintf(L"  │         │");
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i == 2)
			spc();
		else {
			if (i < 2)
				k = *(i + x);
			else
				k = *(i - 3 + y);
			if (i > 2 && a == 1)
				wprintf(L"  │░░░░░░░░░│");
			else
				switch (k / 13)
				{
				case 0: wprintf(L"  │    \x2660    │"); break;
				case 1: wprintf(L"  │    \x2663    │"); break;
				case 2: wprintf(L"  │    \x2665    │"); break;
				case 3: wprintf(L"  │    \x2666    │"); break;
				default:
					break;
				}
		}
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i == 2)
			spc();
		else if (i > 2 && a == 1)
			wprintf(L"  │░░░░░░░░░│");
		else
			wprintf(L"  │         │");
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i == 2)
			spc();
		else if (i > 2 && a == 1)
			wprintf(L"  │░░░░░░░░░│");
		else
			wprintf(L"  │         │");
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i < 2)
			k = *(x + i);
		else
			k = *(y + i - 3);
		if (i == 2)
			spc();
		else if (i > 2 && a == 1)
			wprintf(L"  │░░░░░░░░░│");
		else
		{
			if (k % 13 == 9)
				wprintf(L"  │      ");
			else
				wprintf(L"  │       ");
			switch (k % 13)
			{
			case 0: wprintf(L"A"); break;
			case 10: wprintf(L"J"); break;
			case 11: wprintf(L"Q"); break;
			case 12: wprintf(L"K"); break;
			default: wprintf(L"%d", k % 13 + 1);
				break;
			}
			switch (k / 13)
			{
			case 0:wprintf(L"\x2660│"); break;
			case 1:wprintf(L"\x2663│"); break;
			case 2:wprintf(L"\x2665│"); break;
			case 3:wprintf(L"\x2666│"); break;
			default:
				break;
			}
		}
	}
	rnd();
	for (i = 0; i < n; i++)
	{
		if (i == 2)
			spc();
		else
			wprintf(L"  └─────────┘");
	}
	rnd();
}
void carte(int* x, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		wprintf(L"  ┌─────────┐");

	}
	rnd();
	for (i = 0; i < n; i++)
	{
		wprintf(L"  │");
		switch (*(x + i) % 13)
		{
		case 0: wprintf(L"A"); break;
		case 10: wprintf(L"J"); break;
		case 11: wprintf(L"Q"); break;
		case 12: wprintf(L"K"); break;
		default: wprintf(L"%d", *(x + i) % 13 + 1);
			break;
		}
		switch (*(x + i) / 13)
		{
		case 0:if (*(x + i) % 13 == 9)
			wprintf(L"\x2660      │");
			  else
			wprintf(L"\x2660       │");
			break;
		case 1: if (*(x + i) % 13 == 9)
			wprintf(L"\x2663      │");
			  else
			wprintf(L"\x2663       │");
			break;
		case 2: if (*(x + i) % 13 == 9)
			wprintf(L"\x2665      │");
			  else
			wprintf(L"\x2665       │");
			break;
		case 3: if (*(x + i) % 13 == 9)
			wprintf(L"\x2666      │");
			  else
			wprintf(L"\x2666       │");
			break;
		default:
			break;
		}
	}
	rnd();
	for (i = 0; i < n; i++)
		wprintf(L"  │         │");
	rnd();
	for (i = 0; i < n; i++)
		wprintf(L"  │         │");
	rnd();
	for (i = 0; i < n; i++)
		switch (*(x + i) / 13)
		{
		case 0: wprintf(L"  │    \x2660    │"); break;
		case 1: wprintf(L"  │    \x2663    │"); break;
		case 2: wprintf(L"  │    \x2665    │"); break;
		case 3: wprintf(L"  │    \x2666    │"); break;
		default:
			break;
		}
	rnd();
	for (int j = 0; j < 2; j++)
	{
		for (i = 0; i < n; i++)
			wprintf(L"  │         │");
		rnd();
	}

	for (i = 0; i < n; i++)
	{
		if (*(x + i) % 13 == 9)
			wprintf(L"  │      ");
		else
			wprintf(L"  │       ");
		switch (*(x + i) % 13)
		{
		case 0: wprintf(L"A"); break;
		case 10: wprintf(L"J"); break;
		case 11: wprintf(L"Q"); break;
		case 12: wprintf(L"K"); break;
		default: wprintf(L"%d", *(x + i) % 13 + 1);
			break;
		}
		switch (*(x + i) / 13)
		{
		case 0:wprintf(L"\x2660│"); break;
		case 1:wprintf(L"\x2663│"); break;
		case 2:wprintf(L"\x2665│"); break;
		case 3:wprintf(L"\x2666│"); break;
		default:
			break;
		}
	}
	rnd();
	for (i = 0; i < n; i++)
		wprintf(L"  └─────────┘");
	rnd();
}
void carte_mare(int* mana, int* enemy)
{
	int m, n;

	if (mana[1] > mana[0])
		m = mana[1];
	else
		m = mana[0];
	if (enemy[0] > enemy[1])
		n = enemy[0];
	else
		n = enemy[1];
	if (m > n)
		wprintf(L"Ai castigat cu carte mare");
	else if (n > m)
		wprintf(L"Inamicul a castigat cu carte mare");
	else
		if (mana[0] > enemy[0])
			wprintf(L"Ai castigat cu carte mare");
		else
			wprintf(L"Inamicul a castigat cu carte mare");

}
void Kind1(int m)
{
	wprintf(L"Ai castigat cu un %d of a kind", m);
}
void Kind2(int m, int n)
{
	wprintf(L"Ai castigat cu un %d of a kind si un %d of a kind", m, n);
}

int flush(int* mana, int* masa)
{
	int i = 0, ok = 0;
	if (mana[0] / 13 == mana[1] / 13)
	{
		for (i = 0; i < 5; i++)
			if (masa[i] / 13 == mana[0] / 13)
			{
				ok++;
			}
		if (ok == 4)
			return mana[0] / 13;
	}
	else
		for (int j = 0; j < 2; j++)
		{
			for (i = 0; i < 5; i++)
				if (masa[i] / 13 == mana[j] / 13)
					ok++;
			if (ok == 4)
				return mana[0] / 13;
			ok = 0;
		}
	return 0;
}
int straight(int* mana, int* masa)
{
	int  i = 0, ok1 = 0, ok2 = 0;
	for (int i = 0; i < 5; i++)
	{
		if (*(mana) / 13 == *(masa + i) / 13)
			ok1++;
		if (*(mana) / 13 == *(masa + i) / 13)
			ok2++;
	}
	if (ok1 == 4 || ok2 == 4)
		return 1;
	return 0;
}
void royal_flush(int* mana, int* enemy, int* masa)
{
	int ok1 = 0, ok2=0, flushc;
	flushc = flush(mana, masa);
	if (flush >=0 && straight(mana, masa) == 0)
	{
		if ((*(mana) % 13 == 0 || *(mana + 1) == 0))
			ok1++;

		if (*(mana) % 13 == 12 || *(mana + 1) == 12)
			ok2++;
		if (ok1==1&&ok2==1)
			wprintf(L"Ai castigat cu Royal Flush");

	}
}
void xKind(int* mana, int* enemy, int* masa)
{
	int i, ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0, okm1, okm2, okn1, okn2;
	for (i = 0; i < 5; i++)
	{
		if (masa[i] == mana[0])
			ok1++;
		if (masa[i] == mana[1])
			ok2++;
		if (masa[i] == enemy[0])
			ok3++;
		if (masa[i] == enemy[1])
			ok4++;
	}
	if (ok1 > ok2)
	{
		okm1 = ok1;
		okn1 = ok2;
	}
	else
	{
		okm1 = ok2;
		okn1 = ok1;
	}
	if (ok3 > ok4)
	{
		okm2 = ok3;
		okn2 = ok4;
	}
	else
	{
		okm2 = ok4;
		okn2 = ok3;
	}
	if (ok1 + ok2 > ok3 + ok4)
		if (ok1 > 0 && ok2 > 0)
			Kind2(ok1, ok2);
		else
			if (ok1 > 0)
				Kind1(ok1);
			else
				Kind1(ok2);
	else if (ok1 + ok2 < ok3 + ok4)
		if (ok3 > 0 && ok4 > 0)
			Kind2(ok3, ok4);
		else
			if (ok3 > 0)
				Kind1(ok3);
			else
				Kind1(ok4);
	else
		if (okm1 > okm2)
			Kind1(okm1);
		else
			if (okm1 < okm2)
				Kind1(okm2);
			else
				if (okn1 > okn2)
					Kind1(okn1, okm1);
				else
					if (okn2 > okn1)
						Kind2(okn2, okm2);
					else
						carte_mare(mana, enemy);
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int i, mana[2], masa[5], folosit[9], enemy[2], mm[7], me[7];
	char x;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		carte(masa, 0);
		if (i < 2)
		{
			mana[i] = random(folosit, i);
			enemy[i] = random(folosit, i + 7);
		}
		carte2(mana, enemy, i + 1, 1);
		Sleep(1000);
		
		system("cls");
	}
	for (i = 0; i < 5; i++)
	{
		system("cls");
		masa[i] = random(folosit, i + 2);
		carte(masa, i + 1);

		carte2(mana, enemy, 5, 1);

		Sleep(1000);
		
	}
	system("cls");
	carte(masa, 5);
	carte2(mana, enemy, 5, 0);
	for (i = 0; i < 7; i++)
		mm[i] = folosit[i];
	for (i = 0; i < 7; i++)
		me[i] = folosit[i + 2];
	return 0;

}