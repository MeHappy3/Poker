#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <wchar.h>
#include <Windows.h>
#include <math.h>
#include <stdio.h>

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
// afisaze
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
// cazuri
int carte_mare(int* x, int* y)
{
	int m1, m2;
	if (x[0] % 13 == 0 || x[1] % 13 == 0)
		m1 = 13;
	else if (x[1] % 13 > x[0] % 13)
		m1 = x[1] % 13;
	else
		m1 = x[0] % 13;
	if (y[0] % 13 == 0 || y[1] % 13 == 0)
		m2 = 13;
	else if (y[1] % 13 > y[0] % 13)
		m2 = y[1] % 13;
	else
		m2 = y[0] % 13;
	if (m1 > m2)
		return 1;
	else if (m2 > m1)
		return -1;
	return 0;
}
int xPair(int carte, int* masa)
{
	int i = 0, k = 0;
	for (i = 0; i < 5; i++)
	{
		if (carte % 13 == masa[i] % 13)
			k++;
		
	}
	return k;
}
int pair(int* mana, int* masa, int* enemy)
{
	int i, k1, k2, k3, k4, mPP, mPE;
	k1 = xPair(mana[0], masa);
	k2 = xPair(mana[1], masa);
	k3 = xPair(enemy[0], masa);
	k4 = xPair(enemy[1], masa);
	if (k1 + k2 == 3)
		mPP = 4;
	else if ((k1 == k2&& k1!=0)&&mana[0]!=mana[1])
		mPP = 5;
	else if (k1 > k2)

		mPP = k1;
	else
		mPP = k2;
	if (k3 + k4 == 3)
		mPE = 5;
	else if ((k3 == k4&&k3!=0)&&enemy[1]!=enemy[0])
		mPE = 4;
	else if (k4 > k3)
		mPE = k4;
	else
		mPE = k3;
	
	if ((mPE == mPP)&&(mana[1]!=mana[0]&&enemy[0]!=enemy[1]))
	{
		return carte_mare(mana, enemy);
	}
	else if (mPE == 3 && mPP != 3)
		return -4;
	else if (mPP == 3 && mPE != 3)
		return 4;
	else if (mPP > mPE)
		return mPP+1;
	return -mPE-1;
}
int straight(int* mana, int* masa, int* enemy)
{
	int i, k, carti_player[7], carti_enemy[7], contor_p = 0, contor_e = 0;

	for (i = 0; i < 2; i++)
	{
		if (enemy[i] % 13 != 0)
			carti_enemy[i] = enemy[i] % 13;
		else
			carti_enemy[i] = 13;
		if (mana[i] % 13 != 0)
			carti_player[i] = mana[i] % 13;
		else
			carti_player[i] = 13;
		
	}
	for (i = 0; i < 5; i++)
	{
		if (masa[i] % 13 != 0)
			carti_player[i + 2] = carti_enemy[i + 2] = masa[i] % 13;
		else
			carti_enemy[i + 2] = carti_player[i + 2] = 13;
	}
	do {
		k = 1;
		for (i = 1; i < 7; i++)
			if (carti_enemy[i - 1] > carti_enemy[i])
			{
				carti_enemy[i] = carti_enemy[i] ^ carti_enemy[i - 1];
				carti_enemy[i - 1] = carti_enemy[i - 1] ^ carti_enemy[i];
				carti_enemy[i] = carti_enemy[i] ^ carti_enemy[i - 1];
				k = 0;
			}
	} while (!k);
	do {
		k = 1;
		for (i = 1; i < 7; i++)
			if (carti_player[i - 1] > carti_player[i])
			{
				carti_player[i] = carti_player[i] ^ carti_player[i - 1];
				carti_player[i - 1] = carti_player[i - 1] ^ carti_player[i];
				carti_player[i] = carti_player[i] ^ carti_player[i - 1];
				k = 0;
			}
	} while (!k);

	for (i = 0; i < 7; i++)
	{
		if (carti_enemy[i]  == carti_enemy[i + 1] - 1)
			contor_e++;
		if (carti_player[i] == carti_player[i + 1] - 1)
			contor_p++;
	}
	if (contor_e >= 5 && contor_p < 5)
		return -7;
	else if (contor_e < 5 && contor_p >= 5)
		return 7;
	return pair(mana, masa, enemy);

}
int fflush(int* mana, int* masa, int* enemy)
{
	int i, k, carti_player[7], carti_enemy[7], contor_p[4][1], contor_e[4][1], f_e = 0 , f_p=0;
	for (i = 0; i < 4; i++)
	{
		contor_p[i][0] = 0;
		contor_e[i][0] = 0;
	}
	for (i = 0; i < 2; i++)
	{
	
			carti_enemy[i] = enemy[i];
			carti_player[i] = mana[i];

	}
	for (i = 0; i < 5; i++)
	{
			carti_player[i + 2] = carti_enemy[i + 2] = masa[i];
	}
	do {
		k = 1;
		for (i = 1; i < 7; i++)
			if (carti_enemy[i - 1] > carti_enemy[i])
			{
				carti_enemy[i] = carti_enemy[i] ^ carti_enemy[i - 1];
				carti_enemy[i - 1] = carti_enemy[i - 1] ^ carti_enemy[i];
				carti_enemy[i] = carti_enemy[i] ^ carti_enemy[i - 1];
				k = 0;
			}
	} while (!k);
	for (i = 0; i < 7; i++)
	{
		contor_e[carti_enemy[i] / 13][0]++;
		contor_p[carti_player[i] / 13][0]++;
		if (contor_e[carti_enemy[i] / 13] == 5)
			f_e = 1;
		if (contor_p[carti_player[i] / 13] == 5)
			f_p = 1;
	}
	if (f_e == 1 && f_p != 0)
		return -8;
	else if (f_p == 1 && f_e != 1)
		return 8;
	return straight(mana, masa, enemy);
}
int straight_flush(int* mana, int* masa, int* enemy)
{
	if (fflush(mana, masa, enemy) == 8 && straight(mana, masa, enemy) == 7)
		return 9;
	else if (fflush(mana, masa, enemy) == -8 && straight(mana, masa, enemy) == -7)
		return -9;
	return fflush(mana, masa, enemy);
}
int royal_flush(int* mana, int* masa, int* enemy)
{
	int i, carti_enemy[7], carti_player[7], k;
	if(straight(mana,masa,enemy)==7)
	{for (i = 0; i < 2; i++)
	{
		if (mana[i] % 13 != 0)
			carti_player[i] = mana[i] % 13;
		else
			carti_player[i] = 13;
	}
	for (i = 0; i < 5; i++)
	{
		if (masa[i] % 13 != 0)
			carti_player[i + 2] = masa[i] % 13;
		else
			carti_player[i + 2] = 13;
	}
	do {
		k = 1;
		for (i = 1; i < 7; i++)
			if (carti_player[i - 1] > carti_player[i])
			{
				carti_player[i] = carti_player[i] ^ carti_player[i - 1];
				carti_player[i - 1] = carti_player[i - 1] ^ carti_player[i];
				carti_player[i] = carti_player[i] ^ carti_player[i - 1];
				k = 0;
			}
	} while (!k);
	k = 0;
	for (i = 0; i < 7; i++)
	{
		if (k == 0 && carti_player[i] == 9)
			k++;
		else if (k == 1 && carti_player[i] == 10)
			k++;
		else if (k == 2 && carti_player[i] == 11)
			k++;
		else if (k == 3 && carti_player[i] == 12)
			k++;
		else if (k == 4 && carti_player[i] == 13)
			k++;
	}
	if (k == 5)
		return 10;
}
	else if (straight(mana, masa, enemy) == -7)
	{
		for (i = 0; i < 2; i++)
		{
			if (enemy[i] % 13 != 0)
				carti_enemy[i] = enemy[i] % 13;
			else
				carti_enemy[i] = 13;
		}

		for (i = 0; i < 5; i++)
		{
			if (masa[i] % 13 != 0)
				carti_enemy[i + 2] = masa[i] % 13;
			else
				carti_enemy[i + 2] = 13;
		}
		do {
			k = 1;
			for (i = 1; i < 7; i++)
				if (carti_enemy[i - 1] > carti_enemy[i])
				{
					carti_enemy[i] = carti_enemy[i] ^ carti_enemy[i - 1];
					carti_enemy[i - 1] = carti_enemy[i - 1] ^ carti_enemy[i];
					carti_enemy[i] = carti_enemy[i] ^ carti_enemy[i - 1];
					k = 0;
				}
		} while (!k);
		k = 0;
		for (i = 0; i < 7; i++)
		{
			if (k == 0 && carti_enemy[i] == 9)
				k++;
			else if (k == 1 && carti_enemy[i] == 10)
				k++;
			else if (k == 2 && carti_enemy[i] == 11)
				k++;
			else if (k == 3 && carti_enemy[i] == 12)
				k++;
			else if (k == 4 && carti_enemy[i] == 13)
				k++;
		}
		if (k == 5)
			return -10;
	}
	return straight_flush(mana, masa, enemy);
}
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int i, a, k, mana[2], masa[5], folosit[9], enemy[2], carti_enemy[7], carti_player[7];
	char opt;
	srand(time(NULL));
	do
	{	for (i = 0; i < 5; i++)
	{
		carte(masa, 0);
		if (i < 2)
		{
			mana[i] = random(folosit, i);
			enemy[i] = random(folosit, i + 2);
		}
		carte2(mana, enemy, i + 1, 1);
		Sleep(1000);

		system("cls");
	}
	for (i = 0; i < 5; i++)
	{
		system("cls");
		masa[i] = random(folosit, i + 4);
		carte(masa, i + 1);

		carte2(mana, enemy, 5, 1);

		Sleep(1000);

	}
	system("cls");
	carte(masa, 5);
	carte2(mana, enemy, 5, 0);
	a = royal_flush(mana, masa, enemy);
	if (a > 0)
		wprintf(L"\nAi castigat cu ");
	else if (a < 0)
		wprintf(L"\nCalculatorul a castigat cu ");
	switch (abs(a))
	{
	case 1: wprintf(L"carte mare"); break;
	case 0: wprintf(L"Remiza!"); break;
	case 2: wprintf(L"2 of a kind "); break;
	case 3: wprintf(L"3 of a kind "); break;
	case 4:wprintf(L"4 of a kind"); break;
	case 5:wprintf(L"2 pairs"); break;
	case 6: wprintf(L"full house"); break;
	case 7: wprintf(L"chinta"); break;
	case 8: wprintf(L"flush"); break;
	case 9: wprintf(L"chinta flush"); break;
	case 10: wprintf(L"royal flush"); break;
	default: wprintf(L"ceva nu a mers..."); break;
	}
	wprintf(L"\nPlay again ? (1/0) : ");
		scanf(" %c", &opt);
		switch (opt) {
		case '1': system("CLS"); break;
		case '0': continue;
		default: wprintf(L"Nu este o optiune");
		}
	
	} while (opt != '0');
		
		return 0;

}