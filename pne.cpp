#include<iostream.h>
#include<stdlib.h>
#include<time.h>

char pitch[10][10]=
	{
		'3','3','3','3','3','3','3','3','3','3',
		'3','3','3','5','5','5','5','3','3','3',
		'3','3','5','5','5','5','5','5','3','3',
		'3','5','5','5','5','5','5','5','5','3',
		'3','3','5','7','9','9','7','5','3','3',
		'3','3','5','7','9','9','7','5','3','3',
		'3','5','5','5','5','5','5','5','5','3',
		'3','3','5','5','5','5','5','5','3','3',
		'3','3','3','3','3','3','3','3','3','3',
		'3','3','3','3','3','3','3','3','3','3'
	};

int main();

class board
{
private:
	int x;
	int y;
	int totscore;
	int throwscore;
	int tosses;
public:
	void intro();
	void generation();
	void scoring();
	void showboard();
	void wait();
	void outro();
	void reset();
}playerone;

void board::reset()
{
	playerone.x=0;
	playerone.y=0;
	playerone.totscore=0;
	playerone.throwscore=0;
	playerone.tosses=0;
}

void board::intro()
{
	cout<<" ________________________________________________________ "<<endl;
	cout<<"| Welcome to Penny Pitch                                 |"<<endl;
	cout<<"|--------------------------------------------------------|"<<endl;
	cout<<"| Simply press any key to throw a penny.                 |"<<endl;
	cout<<"| A penny will appear on the board randomly.             |"<<endl;
	cout<<"| You will be given the point value of where it landed.  |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"| You will have 5 tosses to rack up the highest score.   |"<<endl;
	cout<<"| Certain scores win different prizes.                   |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"| Good luck                                              |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;
	system("pause");
}

void board::generation()
{
	srand(time(0));

	if (playerone.tosses<5)
	{
		playerone.x=rand()%10;
		playerone.y=rand()%10;

		if (pitch[playerone.y][playerone.x]=='P')
		{
			generation();
		}
		else
		{
			system("cls");
			scoring();
			pitch[playerone.y][playerone.x]='P';
			playerone.tosses++;
			showboard();
			cout<<"Score for that throw "<<playerone.throwscore<<endl;
			cout<<"Number of tosses "<<playerone.tosses<<"/5"<<endl;
			wait();
			system("pause");
			generation();
		}
	}
	else
	{
		system("cls");
	}

}

void board::scoring()
{
	if (pitch[playerone.y][playerone.x]=='3')
	{
		playerone.totscore=playerone.totscore+3;
		playerone.throwscore=3;
	}
	else if (pitch[playerone.y][playerone.x]=='5')
	{
		playerone.totscore=playerone.totscore+5;
		playerone.throwscore=5;
	}
	else if (pitch[playerone.y][playerone.x]=='7')
	{
		playerone.totscore=playerone.totscore+7;
		playerone.throwscore=7;
	}
	else //(pitch[playerone.y][playerone.x]=='9')
	{
		playerone.totscore=playerone.totscore+9;
		playerone.throwscore=9;
	}
}


void board::showboard()
{
	for (int a=0;a<10;a++)
	{
		for (int b=0;b<10;b++)
		{
			cout<<pitch[a][b]<<"  ";
		}
		cout<<endl;
	}
}

void board::wait()
{
	clock_t endwait;
	endwait=clock()+1*CLK_TCK;
	while (clock()<endwait){}
}

void board::outro()
{
	cout<<"You have finished the game"<<endl;
	cout<<"Total score "<<playerone.totscore<<endl;

	if (playerone.totscore>=25 && playerone.totscore<30)
	{
		cout<<"You win a free game."<<endl;
		system("pause");
		system("cls");
		main();
	}
	else if(playerone.totscore>=30)
	{
		cout<<"You win a Mr. Duck";
	}

	else //(playerone.totscore<25)
	{
		cout<<"Thanks for playing.";
	}

	cout<<endl;
}


int main()
{
	board thisboard;
	thisboard.reset();
	thisboard.intro();
	thisboard.generation();
	thisboard.outro();

	return 0;
}