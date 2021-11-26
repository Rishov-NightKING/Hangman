#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
#include<iostream>
char lastKey = 0;
int x1=20;
int z1=600;
int i;
int index;
int flag;
char output_char[2];
char * output_str;
char * str;
char ch;
int error=0;
int curlev=0;
int trans=0;
int correct=0;
int point=0;

//random word selection from file
char *readword()
{
	FILE *fp;

	switch (curlev)
	{
		case 1:	fp=fopen("word1.txt","r"); break;
		case 2:	fp=fopen("word2.txt","r"); break;
		case 3: fp=fopen("word3.txt","r"); break;
		default: return "";
	}
	char *buf=(char*)malloc(100*sizeof(char));
	int count=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s",buf);
		count++;
	}
	fseek(fp,0,SEEK_SET);
	int r=rand()%count;
	for(i=0;i<r;i++)
	{
		fscanf(fp,"%s",buf);
	}
	return buf;
	fclose(fp);
}
void print_keyboard()
{
	for(i=0;i<401;i+=50)
	{
		iRectangle(x1+i,z1,50,50);

	}
		for(i=0;i<401;i+=50)
	{
		iRectangle(x1+i,z1-50,50,50);
	}
	for(i=0;i<351;i+=50)
	{
		iRectangle(x1+i,z1-100,50,50);
	}
	int len=strlen(str);
	for(i=0;i<(len-1)*50+1;i+=50)
	{
		iRectangle(x1+20+i,50,50,50);
	}
	for(i=0;i<len;i++)
	{
		output_char[0]=output_str[i];
		iText(x1+30+50*i,65,output_char,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//first row of keyboard
	iText(x1+12,z1+13,"A",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+62,z1+13,"B",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+112,z1+13,"C",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+162,z1+13,"D",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+212,z1+13,"E",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+262,z1+13,"F",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+312,z1+13,"G",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+362,z1+13,"H",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+412,z1+13,"I",GLUT_BITMAP_TIMES_ROMAN_24);
	//2nd row of keyboard
	iText(x1+12,z1+13-50,"J",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+62,z1+13-50,"K",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+112,z1+13-50,"L",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+162,z1+13-50,"M",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+212,z1+13-50,"N",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+262,z1+13-50,"O",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+312,z1+13-50,"P",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+362,z1+13-50,"Q",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+412,z1+13-50,"R",GLUT_BITMAP_TIMES_ROMAN_24);
	//3rd row
	iText(x1+12,z1+13-100,"S",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+62,z1+13-100,"T",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+112,z1+13-100,"U",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+162,z1+13-100,"V",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+212,z1+13-100,"W",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+262,z1+13-100,"X",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+312,z1+13-100,"Y",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(x1+362,z1+13-100,"Z",GLUT_BITMAP_TIMES_ROMAN_24);
}
void printhangman()
{
	if(error==1)
	{
		iShowBMP(680,170,"f1.bmp");
	}
	else if(error==2)
	{
		iShowBMP(680,170,"f1.bmp");
		iShowBMP(680,175,"f2.bmp");
	}
	else if(error==3)
	{
		iShowBMP(680,170,"f1.bmp");
		iShowBMP(680,175,"f2.bmp");
		iShowBMP(680,550,"f3.bmp");
	}
	else if(error==4)
	{
		iShowBMP(680,170,"f1.bmp");
		iShowBMP(680,175,"f2.bmp");
		iShowBMP(680,550,"f3.bmp");
		iShowBMP(750,480,"f4.bmp");
	}
	else if(error==5)
	{
		iShowBMP(680,170,"f1.bmp");
		iShowBMP(680,175,"f2.bmp");
		iShowBMP(680,550,"f3.bmp");
		iShowBMP(750,425,"f5.bmp");
	}
	else if(error==6)
	{
		iShowBMP(680,170,"f1.bmp");
		iShowBMP(680,175,"f2.bmp");
		iShowBMP(680,550,"f3.bmp");
		iShowBMP(750,350,"f6.bmp");
	}
}


void iDraw() {
	//place your drawing codes here
	iClear();
	if(curlev==0)
	{
		iShowBMP(0,0,"cover.bmp");
		return;
	}
	if(curlev==1||curlev==2||curlev==3)
	{
		iClear();
		iShowBMP(0,0,"gamebody.bmp");

		print_keyboard();
		printhangman();

		//int match =0;

		int* point_ara=(int*)malloc(sizeof(int));
		point_ara[0]=point;
		point_ara[1]='\0';

		char pnt[100];
		itoa(point, pnt, 10);
		iText(880,650,"Point:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(950,650,pnt,GLUT_BITMAP_TIMES_ROMAN_24);

		char errstr[5];
		itoa(error, errstr, 10);
		iText(880,625,"Error:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(950, 625, errstr ,GLUT_BITMAP_TIMES_ROMAN_24);

		if (trans && curlev>0&&curlev<3)
		{
			iText(100,400,"You won. Click anywhere to proceed to next level",GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (curlev==5)
	{
		iClear();
		iShowBMP(0,0,"lastpage.bmp");
		iSetColor(255,255,255);
		iText(200,200,"Sorry you have failed....better luck next time.",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200,100,"Your score is:",GLUT_BITMAP_TIMES_ROMAN_24);
		int* point_ara=(int*)malloc(sizeof(int));
		point_ara[0]=point;
		point_ara[1]='\0';

		char pnt[100];
		itoa(point, pnt, 10);
		iText(340,100,pnt,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200,50,"The correct word is:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400,50, str,GLUT_BITMAP_HELVETICA_18);
		iShowBMP(680,170,"f1.bmp");
		iShowBMP(680,175,"f2.bmp");
		iShowBMP(680,550,"f3.bmp");
		iShowBMP(750,280,"f7.bmp");
		return;
	}

	if(curlev==1)
	{
		iText(880,600,"Level: 1",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(curlev==2)
	{
		iText(880,600,"Level: 2",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(curlev==3)
	{
		iText(880,600,"Level: 3",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(curlev==6)
	{
		iShowBMP(0,0,"credit.bmp");
	}

	if(curlev==4)
	{
		iShowBMP(0,0,"congo.bmp");
	}
	if(curlev==7)
	{
		iShowBMP(0,0,"howtoplay.bmp");
	}
}




/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (curlev==4)
	{
		if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			if((mx>=(845))&&(mx<=(991))&&(my>=(6))&&(my<=(50)))
		    exit(0);
		}
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			if((mx>=(12))&&(mx<=(280))&&(my>=(6))&&(my<=(50)))
			curlev=0;
			point=0;
		}
		return;
	}
	if (curlev==5)
	{
		if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			if((mx>=(704))&&(mx<=(887))&&(my>=(560))&&(my<=(626)))
		    exit(0);
		}
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			if((mx>=(100))&&(mx<=(318))&&(my>=(548))&&(my<=(619)))
			curlev=0;
			point=0;
		}
		return;
	}
	if(curlev==6)
	{
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
		    if((mx>=754&&mx<=1000)&&(my>=140&&my<=200))
			curlev=0;
		}
	}
	if(curlev==7)
	{
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
		    if((mx>=720&&mx<=965)&&(my>=103&&my<=170))
			curlev=0;
		}
	}


	if (curlev==0)
	{
		if((mx>=(x1+450))&&(mx<=(x1+631))&&(my>=(170))&&(my<=(210)))
			trans=1;
	}
	if(curlev==0)
	{
		if((mx>=(710))&&(mx<=(883))&&(my>=(179))&&(my<=(222)))
			curlev=6;
		if((mx>=(474))&&(mx<=(651))&&(my>=(126))&&(my<=(171)))
			curlev=7;
	}
	if (trans)
	{
		if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			trans=0;
			curlev++;
			str=readword();
			correct=0;
			error=0;

			output_str= (char *)malloc(sizeof(char)*100);
			for (int i=0; i<99; i++)
				output_str[i]=' ';
			output_str[99]='\0';
		}
	return;
	}
	if(curlev==1||curlev==2||curlev==3)
	{
		if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	    {

			if((mx>=(x1))&&(mx<=(x1+50))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='A';
			}
			else if((mx>=(x1+50))&&(mx<=(x1+100))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='B';
			}
			else if((mx>=(x1+100))&&(mx<=(x1+150))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='C';
			}
			else if((mx>=(x1+150))&&(mx<=(x1+200))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='D';
			}
			else if((mx>=(x1+200))&&(mx<=(x1+250))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='E';
			}
			else if((mx>=(x1+250))&&(mx<=(x1+300))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='F';
			}
			else if((mx>=(x1+300))&&(mx<=(x1+350))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='G';
			}
			else if((mx>=(x1+350))&&(mx<=(x1+400))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='H';
			}
			else if((mx>=(x1+400))&&(mx<=(x1+450))&&(my>=(z1))&&(my<=(z1+50)))
			{
				ch='I';
			}
			//2nd row
			else if((mx>=(x1))&&(mx<=(x1+50))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='J';
			}
			else if((mx>=(x1+50))&&(mx<=(x1+100))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='K';
			}
			else if((mx>=(x1+100))&&(mx<=(x1+150))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='L';
			}
			else if((mx>=(x1+150))&&(mx<=(x1+200))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='M';
			}
			else if((mx>=(x1+200))&&(mx<=(x1+250))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='N';
			}
			else if((mx>=(x1+250))&&(mx<=(x1+300))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='O';
			}
			else if((mx>=(x1+300))&&(mx<=(x1+350))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='P';
			}
			else if((mx>=(x1+350))&&(mx<=(x1+400))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='Q';
			}
			else if((mx>=(x1+400))&&(mx<=(x1+450))&&(my>=(z1-50))&&(my<=(z1)))
			{
				ch='R';
			}
			//3rd row
			else if((mx>=(x1))&&(mx<=(x1+50))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='S';
			}
			else if((mx>=(x1+50))&&(mx<=(x1+100))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='T';
			}
			else if((mx>=(x1+100))&&(mx<=(x1+150))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='U';
			}
			else if((mx>=(x1+150))&&(mx<=(x1+200))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='V';
			}
			else if((mx>=(x1+200))&&(mx<=(x1+250))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='W';
			}
			else if((mx>=(x1+250))&&(mx<=(x1+300))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='X';
			}
			else if((mx>=(x1+300))&&(mx<=(x1+350))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='Y';
			}
			else if((mx>=(x1+350))&&(mx<=(x1+400))&&(my>=(z1-100))&&(my<=(z1-50)))
			{
				ch='Z';
			}
	 }
	else
		return;


	int match =0;

	//error=0;
	int len=strlen(str);

	for(i=0;i<len;i++)
	{
		//printf("This is working\n");
		char c=str[i];
		if(c==ch)
		{
			if (str[i]!=output_str[i])
			{
				output_str[i]=str[i];
				correct++;
				point+=50;
			}
			match++;
		}
	}
	if(match==0)
	{
		//printf("error: %d \n",error);
		printf("\nWRONG: %c\n", ch);
		error++;
		point-=20;
	}

	if (correct==len)
	{
		trans=1;
	}


	if (error>=7)
	{
		curlev=5;
	}
  }

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	/*static int c=0;
	if (key == 'q') {
		exit(0);
	}
	else if(lastKey == key){
            c++;
	}
	else{
        printf("lastKey:%c  %d times\n",lastKey,c);
        c = 0;
        lastKey = key;
	}*/

        //printf("%c\n",key);
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	/*if (key == GLUT_KEY_END) {
		exit(0);
	}*/
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.
	srand(time(NULL));
	str=readword();
	output_str= (char *)malloc(sizeof(char)*100);

	for (int i=0; i<99; i++)
		output_str[i]=' ';
	output_str[99]='\0';
	output_char[1]='\0';

	iInitialize(1000, 700, "HANGMAN");
	return 0;

}
