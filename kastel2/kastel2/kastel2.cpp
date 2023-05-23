
#include <iostream>
#include<stdlib.h>////تابع rand
#include<time.h>
#include<string.h>
#include<string>
using namespace std;


int score1 = 0, score2 = 0;

////////////////////////////////// Functions ////////////////////////////////////////////////////////

int makerand(int a, int b)//////تابع ساخت عدد رندوم
{
	int x;
	x = rand() % (b - a + 1) + a;
	return x;

}

int countscore(string front1[10], int cfront1)/////////// تابع  حساب کردن امتیازات
{
	int cm = 0, ck = 0, cg = 0,b;
	bool state1 = true;
	string a;
	
	int	scr1 = 0;


	for (int i = 0; i <= cfront1; i++)/// front1 /// بررسی داشتن هر سه نوع کارت
	{
		if (front1[i][0] == 'k')ck++;
		else if (front1[i][0] == 'm')cm++;
		else if (front1[i][0] == 'g')cg++;
	}
	if (cg == 0 || cm == 0 || ck == 0)
	{		
		state1 = false;
	}

	cm = 0; ck = 0; cg = 0;	

	/////////////////////////////////////////////////////////////////  محاسبه امتیازات

	if (state1 == true)
	{
		for (int i = 0; i <= cfront1; i++)
		{
			a = front1[i][2];

			string c = "";

			if ((a.compare(c)==0))
			{
				a = front1[i][1];
				b = stoi(a);
				scr1 += (b * 10);
				a = front1[i][2];
				b = stoi(a);
				scr1 += b;
			}
			else
			{
				a = front1[i][1];
				b = stoi(a);
				scr1 += b;
			}			
		}
	}

	
	return scr1;

}



////////////////////////////////// Functions ////////////////////////////////////////////////////////
int main()
{
	/////////////// ENTERY //////////////////////

	cout << "Please enter any key to start.......";

	char e;
	cin >> e;
	system("cls");

	////////////////////////  gorbegoor   ///////////////////////////////////////

	string card[100], front1[10], front2[10], p1[5], p2[5];
	string temp1, temp2, temp3;

	int counter = 0;
	int cfront1 = -1 ; int cfront2 = -1 ; //counter of front cards of 1&2
	int a = 0, b = 89;
	int x, y, z, l, m, n, p = 0;
	int dast1 = 0, dast2 = 0;//برای نوع جایگذاری کارت توسط بازیکن


	for (int i = 0; i < 90; i++)
	{
		if (i < 9)
		{
			card[i] = "g";
			card[i] += i + 49;
		}

		else if (i >= 9 && i < 15)
		{
			card[i] = "g";
			card[i] += 49;
			card[i] += i - 9 + 48;
		}

		else if (i >= 15 && i < 30)
		{
			card[i] = card[i - 15];
		}

		///////////////// moomiaii   //////////////////

		else if (i >= 30 && i < 39)
		{
			card[i] = "m";
			card[i] += i - 30 + 49;
		}

		else if (i >= 39 && i < 45)
		{
			card[i] = "m";
			card[i] += 49;
			card[i] += i - 39 + 48;
		}

		else if (i >= 45 && i < 60)
		{
			card[i] = card[i - 15];
		}

		//////////////  kadoooo  ////////////////////

		else if (i >= 60 && i < 69)
		{
			card[i] = "k";
			card[i] += i - 60 + 49;
		}

		else if (i >= 69 && i < 75)
		{
			card[i] = "k";
			card[i] += 49;
			card[i] += i - 69 + 48;
		}

		else if (i >= 75 && i < 90)
		{
			card[i] = card[i - 15];
		}
	}

	///////////////////////    Player1      ///////////////////////////////////////////

	srand(time(0));

	x = makerand(a, b);
	y = makerand(a, b);
	z = makerand(a, b);

	p1[0] = card[x];
	p1[1] = card[y];
	p1[2] = card[z];

	card[x] = "";
	card[y] = "";
	card[z] = "";



player1:


	cout << "*** Player 1 ***  :" << endl << endl;

	cout << "In Hand Cards : ";

	cout << "( " << p1[0] << "," << p1[1] << "," << p1[2] << " )";

	cout << endl << endl << "Opponent front cards : ";

	for (int i = 0; i <= cfront2; i++)
	{
		cout << front2[i] << " , ";
	}

		cout << endl << endl << "your front card : ";

		for (int i = 0; i <= cfront1; i++)
		{
			cout << front1[i] << ", ";
		}
	

	if (dast1 == 0)
		cout << endl << endl << "Enter 1 to put a card infront of yourself or 2 to put infront of your opponent :";

	else
	{
		cout << endl << endl << "Enter 3 to put a card on your opponent card or 2 to put beside....";

	}

	cin >> p;

	///////////////////////////////////////////////////	

	if (p == 1)
	{
		system("cls");

		cout << "Which card  ? : ";

		cfront1++;

		cin >> front1[cfront1];

		if (p1[0] == front1[cfront1])
		{
			card[x] = "";
			srand(time(0));

			counter = 0;
			while (card[x] == "")
			{
				if (counter == 120)
					break;
				x = makerand(a, b);

				if (card[x] != "")
				{
					p1[0] = card[x];
					card[x] = "";
					counter++;
					break;
				}
				counter++;
			}

		}
		else if (p1[1] == front1[cfront1])
		{
			card[y] = "";
			srand(time(0));

			counter = 0;
			while (card[y] == "")
			{
				if (counter == 120)
					break;
				y = makerand(a, b);

				if (card[y] != "")
				{
					p1[1] = card[y];
					card[y] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		else if (p1[2] == front1[cfront1])
		{
			card[z] = "";
			srand(time(0));

			counter = 0;
			while (card[z] == "")
			{
				if (counter == 120)
					break;
				z = makerand(a, b);

				if (card[z] != "")
				{
					p1[2] = card[z];
					card[z] = "";
					counter++;
					break;
				}
				counter++;
			}
		}


	}
	/////////////////////////////////////////////////

	else if (p == 2)
	{

		system("cls");

		cout << "which card ?";

		cfront2++;

		cin >> front2[cfront2];


		if (p1[0] == front2[cfront2]) /////////////جایگزینی کارت جدید 
		{
			card[x] = "";
			srand(time(0));

			counter = 0;
			while (card[x] == "")
			{
				if (counter == 120)
					break;
				x = makerand(a, b);

				if (card[x] != "")
				{
					p1[0] = card[x];
					card[x] = "";
					break;
				}
				counter++;
			}

		}
		else if (p1[1] == front2[cfront2])
		{
			card[y] = "";
			srand(time(0));

			counter = 0;
			while (card[y] == "")
			{
				if (counter == 120)
					break;
				y = makerand(a, b);

				if (card[y] != "")
				{
					p1[1] = card[y];
					card[y] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		else if (p1[2] == front2[cfront2])
		{
			card[z] = "";
			srand(time(0));

			counter = 0;
			while (card[z] == "")
			{
				if (counter == 120)
					break;
				z = makerand(a, b);

				if (card[z] != "")
				{
					p1[2] = card[z];
					card[z] = "";
					counter++;
					break;
				}
				counter++;
			}
		}



		for (int i = 0; i <= cfront2 - 1; i++)  //////////بررسی برابر بودن عدد کارت با بقیه 
		{
			if (front2[cfront2][1] == front2[i][1] && front2[cfront2][2] == front2[i][2])
			{
					front2[i] = front2[cfront2];

					front2[cfront2] = "";

					cfront2--;
					break;
				
			}
		}


	}
	//////////////////////////////////////////////////

	else if (p == 3)
	{
		system("cls");

		cout << "on which opponent front card do you want to put ?";

		cin >> temp2;

		cout << endl << "which card do you choose ?";

		cin >> temp1;

		if (p1[0] == temp1)  ///////////جایگزین کردن کارت جدید
		{
			card[x] = "";
			srand(time(0));

			counter = 0;
			while (card[x] == "")
			{
				if (counter == 120)
					break;
				x = makerand(a, b);

				if (card[x] != "")
				{
					p1[0] = card[x];
					card[x] = "";
					counter++;
					break;
				}
				counter++;
			}

		}
		else if (p1[1] == temp1)
		{
			card[y] = "";
			srand(time(0));

			counter = 0;
			while (card[y] == "")
			{
				if (counter == 120)
					break;
				y = makerand(a, b);

				if (card[y] != "")
				{
					p1[1] = card[y];
					card[y] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		else if (p1[2] == temp1)
		{
			card[z] = "";
			srand(time(0));

			counter = 0;
			while (card[z] == "")
			{
				if (counter == 120)
					break;
				z = makerand(a, b);

				if (card[z] != "")
				{
					p1[2] = card[z];
					card[z] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		for (int i = 0; i <= cfront2; i++)  //////////بررسی برابر بودن عدد کارت با بقیه 
		{
			if (temp1[1] == front2[i][1] && temp1[2] == front2[i][2])
			{
				for (int j = 0; j <= cfront2; j++)
				{
					if (temp2 == front2[j])
					{
						front2[j] = front2[cfront2];

						front2[cfront2] = "";

						cfront2--; 

						break;

					}
				}
			}
		}

		/////////////////////////////////////// اگر عددها  برابر نبودند

		for (int i = 0; i <= cfront2; i++)
		{
			if (temp2 == front2[i])
			{
				front2[i] = temp1;
			}
		}

	}



	//////////////////////////////////////////////// بررسی پایان یک دور

	 if (dast1 != 1)
	{
		if (cfront1 == 5 || cfront2 == 5) ///بررسی 6تا شدن ستون ها
		{
	     score1+= countscore(front1, cfront1);
		  score2 += countscore(front2, cfront2);

			system("cls");

			cout << "Round finished . " << endl;

			cout << "Score 1 : " << score1 << " , " << "Score2 :" << score2;

			cin >> e;

			/////////////////////////////////////////////////////////////////////////////بررسی پایان بازی

			if (score1 >= 150 || score2 >= 150)
			{
				system("cls");

				cout << "Game has been ended ....." << endl << endl << "Winner is : ";

				if (score1 > score2)
				{
					cout << "Player 1.";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
					cin >> e;
					exit(0);
				}
				if (score2 > score1)
				{
					cout << "Player 2.";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
					cin >> e;
					exit(0);
				}
				else
				{
					cout << "no one !!! .";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
					cin >> e;
					exit(0);
				}
			}

			system("cls");

			main();
		}

		else
		{
			if (p1[0] == "" && p1[1] == "" && p1[2] == "" && p2[0] == "" && p2[1] == "" && p2[2] == "") /////بررسی تمام شدن کارتهای در دست
			{
				score1 += countscore(front1, cfront1);
				score2 += countscore(front2, cfront2);
	 
				system("cls");

				cout << "Round finished . " << endl;

				cout << "Score 1 : " << score1 << " , " << "Score2 :" << score2;

				cin >> e;

				/////////////////////////////////////////////////////////////////////////////بررسی پایان بازی



				if (score1 >= 150 || score2 >= 150)
				{
					system("cls");

					cout << "Game has been ended ....." << endl << endl << "Winner is : ";

					if (score1 > score2)
					{
						cout << "Player 1.";
						cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
						cin >> e;
						exit(0);
					}
					if (score2 > score1)
					{
						cout << "Player 2.";
						cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
						cin >> e;
						exit(0);
					}
					else
					{
						cout << "no one !!! .";
						cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
						cin >> e;
						exit(0);
					}
				}
				system("cls");

				main();
			}
		}
	}

	dast1++;
	system("cls");

	
	


	if (dast2 != 0)
		goto player22;
	else 
	{
		goto player21;
	}

	////////////////////////// PLAYER 2 ////////////////////////////////////////////////////

player21:

	srand(time(0));

	l = makerand(a, b);
	while(card[l]=="")
		l = makerand(a, b);
	m = makerand(a, b);
	while (card[m] == "")
		m = makerand(a, b);
	n = makerand(a, b);
	while (card[n] == "")
		n = makerand(a, b);

	p2[0] = card[l];
	p2[1] = card[m];
	p2[2] = card[n];

	card[l] = "";
	card[m] = "";
	card[n] = "";


player22:



	cout << "*** Player 2 ***  :" << endl << endl;

	cout << "In Hand Cards : ";

	cout << "( " << p2[0] << "," << p2[1] << "," << p2[2] << " )";

	cout << endl << endl << "Opponent front cards : ";

	for (int i = 0; i <= cfront1; i++)
	{
		cout << front1[i] << " , ";
	}




		cout << endl << "your front cards : ";

		for (int i = 0; i <= cfront2; i++)
		{
			cout << front2[i] << ", ";
		}
	
	if (dast2 == 0)
		cout << endl << endl << "Enter 1 to put a card infront of yourself or 2 to put infront of your opponent :";

	else
	{
		cout << endl << endl << "Enter 3 to put a card on your opponent card or 2 to put beside...";
	}

	cin >> p;


	if (p == 1)
	{
		system("cls");

		cout << "Which card  ? : ";

		cfront2++;

		cin >> front2[cfront2];

		if (p2[0] == front2[cfront2])
		{
			card[l] = "";
			srand(time(0));

			counter = 0;
			while (card[l] == "")
			{
				if (counter == 120)
					break;
				
					l = makerand(a, b);

			    if (card[l] != "")
				{
					p2[0] = card[l];
					card[l] = "";
					counter++;
					break;
				}
				counter++;
			}

		}

		else if (p2[1] == front2[cfront2])
		{
			card[m] = "";
			srand(time(0));
			counter = 0;
			while (card[m] == "")
			{
				if (counter == 120)
					break;
				m = makerand(a, b);

				if (card[m] != "")
				{
					p2[1] = card[m];
					card[m] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		else if (p2[2] == front2[cfront2])
		{
			card[n] = "";
			srand(time(0));

			counter = 0;
			while (card[n] == "")
			{
				if (counter == 120)
					break;
				n = makerand(a, b);

				if (card[n] != "")
				{
					p2[2] = card[n];
					card[n] = "";
					counter++;
					break;
				}
				counter++;
			}
		}
	}

	else if (p == 2)
	{

		system("cls");

		cout << "which card ?";

		cfront1++;

		cin >> front1[cfront1];

		if (p2[0] == front1[cfront1]) ////// حذف و جایگزینی  کارت انتخاب شده 
		{
			card[l] = "";
			srand(time(0));

			counter = 0;
			while (card[l] == "")
			{
				if (counter == 120)
					break;
				l = makerand(a, b);

				if (card[l] != "")
				{
					p2[0] = card[l];
					card[l] = "";
					counter++;
					break;
				}
				counter++;
			}

		}

		else if (p2[1] == front1[cfront1])
		{
			card[m] = "";
			srand(time(0));
			counter = 0;
			while (card[m] == "")
			{
				if (counter == 120)
					break;
				m = makerand(a, b);

				if (card[m] != "")
				{

					p2[1] = card[m];
					card[m] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		else if (p2[2] == front1[cfront1])
		{
			card[n] = "";
			srand(time(0));

			counter = 0;
			while (card[n] == "")
			{
				if (counter == 120)
					break;
				n = makerand(a, b);

				if (card[n] != "")
				{
					p2[2] = card[n];
					card[n] = "";
					counter++;
					break;
				}
				counter++;
			}
		}


		for (int i = 0; i <= cfront1 - 1; i++)  //////////بررسی برابر بودن عدد کارت با بقیه 
		{
			if (front1[cfront1][1] == front1[i][1] && front1[cfront1][2] == front1[i][2])
			{
				
					front1[i] = front1[cfront1];

					front1[cfront1] = "";

					cfront1--;
					break;
			}
		}



	}

	if (p == 3)
	{
		system("cls");

		cout << "on which opponent front card do you want to put ?";

		cin >> temp2;

		cout << endl << "which card do you choose ?";

		cin >> temp1;

		if (p2[0] == temp1) ////// حذف و جایگزینی  کارت انتخاب شده 
		{
			card[l] = "";
			srand(time(0));

			counter = 0;
			while (card[l] == "")
			{
				if (counter == 120)
					break;
				l = makerand(a, b);

				if (card[l] != "")
				{
					p2[0] = card[l];
					card[l] = "";
					counter++;
					break;
				}
				counter++;
			}

		}

		else if (p2[1] == temp1)
		{
			card[m] = "";
			srand(time(0));
			counter = 0;
			while (card[m] == "")
			{
				if (counter == 120)
					break;
				m = makerand(a, b);

				if (card[m] != "")
				{
					p2[1] = card[m];
					card[m] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		else if (p2[2] == temp1)
		{
			card[n] = "";
			srand(time(0));

			counter = 0;
			while (card[n] == "")
			{
				if (counter == 120)
					break;
				n = makerand(a, b);

				if (card[n] != "")
				{
					p2[2] = card[n];
					card[n] = "";
					counter++;
					break;
				}
				counter++;
			}
		}

		for (int i = 0; i <= cfront1; i++)  //////////بررسی برابر بودن عدد کارت با بقیه 
		{
			if (temp1[1] == front1[i][1] && temp1[2] == front1[i][2])
			{
				for (int j = 0; j <= cfront1; j++)
				{
					if (temp2 == front1[j])
					{
						front1[j] = front1[cfront1];

						front1[cfront1] = "";

						cfront1--;
						break;
					}
				}
			}
		}

		/////////////////////////////////////// اگر عددها  برابر نبودند

		for (int i = 0; i <= cfront1; i++)
		{
			if (temp2 == front1[i])
			{
				front1[i] = temp1;
			}
		}

	}



	/////////////////////////////////////////////////////////////////////// بررسی پایان یک دور

	if (dast1 != 1)
	{
		if (cfront1 == 5 || cfront2 == 5) ///بررسی  6تا شدن ستون ها
	{
			score1 += countscore(front1, cfront1);
			score2 += countscore(front2, cfront2);

			system("cls");

			cout << "Round finished . " << endl;

		cout << "Score 1 : " << score1 << " , " << "Score2 :" << score2;

			cin >> e;

			////////////////////////////////////////////////////////////////////////////// بررسی پایان بازی

			if (score1 >= 150 || score2 >= 150)
			{
				system("cls");

				cout << "Game has been ended ....." << endl << endl << "Winner is : ";

				if (score1 > score2)
				{
					cout << "Player 1.";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;

					cin >> e;
					exit(0);
				}
				if (score2 > score1)
				{
					cout << "Player 2.";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
					cin >> e;
					exit(0);
				}
				else
				{
					cout << "no one !!! .";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
					cin >> e;
					exit(0);
				}

			}

			system("cls");

			main();
		}

		else
		{
			if (p1[0] == "" && p1[1] == "" && p1[2] == "" && p2[0] == "" && p2[1] == "" && p2[2] == "") /////بررسی تمام شدن کارتهای در دست
			{

				score1 += countscore(front1, cfront1);
				score2 += countscore(front2, cfront2);
	              
				system("cls");

				cout << "Round finished . " << endl;

				cout << "Score 1 : " << score1 << " , " << "Score2 :" << score2;

			cin >> e;

			////////////////////////////////////////////////////////////////////////////// بررسی پایان بازی

			if (score1 >= 150 || score2 >= 150)
			{
				system("cls");

				cout << "Game has been ended ....." << endl << endl << "Winner is : ";

				if (score1 > score2)
				{
					cout << "Player 1.";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;

					cin >> e;
					exit(0);
				}
				if (score2 > score1)
				{
					cout << "Player 2.";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
					cin >> e;
					exit(0);
				}
				else
				{
					cout << "no one !!! .";
					cout << endl << "player1 score : " << score1 << " .  Player2 score : " << score2;
					cin >> e;
					exit(0);
				}

			}
				system("cls");

				main();
			}
		}
	}
	system("cls");
	dast2++;

	goto  player1;

}




