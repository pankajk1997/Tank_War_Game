/*________________________Program By One And Only Pankaj_____________________*/

#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<fstream.h>
#include<process.h>
#include<stdlib.h>

 int x=1,q=0,count=0,spi_health=620,tan_health=620;
 char ch,choice;

void intro_screen()
{
	 cleardevice();

	 cout<<" \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	 cout<<" \n\t PRESS '1' TO START GAME";
	 cout<<" \n\t PRESS '2' TO SEE CONTROLS GAME";
	 cout<<" \n\t PRESS '3' TO TO SAVE GAME";
	 cout<<" \n\t PRESS '4' TO TO LOAD GAME";
	 cout<<" \n\t PRESS '5' TO QUIT FROM GAME";

	 setcolor(GREEN);
	 settextstyle(1,HORIZ_DIR,1);

	 outtextxy(20,90,"Our World Is Attacked By Aliens");
	 outtextxy(20,110,"Pankaj a Professional Scientist");
	 outtextxy(20,130,"Have Invented An Effective TANK");
	 outtextxy(20,150,"To Wipe The Enemies Out");
	 outtextxy(20,170,"To protect our motherland");
	 outtextxy(20,190,"For The Sake of survival of mankind");

	 setcolor(RED);
	 settextstyle(8,HORIZ_DIR,2);
	 outtextxy(60,40,"** MAIN MENU **");

}

void control_screen()
{
	 cleardevice();

	 cout<<" \n\n\n\n\n\n \t RETURNING TO MAIN MENU \n LOADING... ";

	 setcolor(GREEN);
	 settextstyle(7,HORIZ_DIR,1);

	 outtextxy(20,40,"Press 'w' To Fire");
	 outtextxy(20,60,"Press 'a' To Move Left");
	 outtextxy(20,80,"Press 'd' To Move Right");
	 outtextxy(20,100,"Press 'Backspace' To Pause");

	 delay(8000);
	 intro_screen();
}


void spider()
{
	  setcolor(YELLOW);
	  arc(x,187,0, 180,50);
	  arc(x,178,0,180,90);
	  arc(x,160,0,180,90);
	  arc(x,215,0,180,10);
	  arc(x,200,0,180,90);

	  setcolor(BROWN);
	  circle(x,130, 75);

	  setcolor(WHITE);
	  circle(x-15,180,10);
	  circle(x+15,180,10);

	  setcolor(BLUE);
	  line(1000,475,0,475);
}

void tank()
{
	  setcolor(WHITE);
	  rectangle(30+q,470,60+q,455);
	  rectangle(40+q,455,50+q,440);
				   //Limiting The View Of Tank In Screen
	{ if((30+q)>640)
	  q=-30;

	  if((30+q)<0)
	  q=600;
	}

}

void win_message()
{
  cleardevice();

  setcolor(GREEN);               //printing ending screen for victory
  settextstyle(3, HORIZ_DIR,3);

  outtextxy(20,80,"** Thankyou **");
  outtextxy(20,100,"** You destroyed the spider monster  **");
  outtextxy(20,120,"** You saved the world from **");
  outtextxy(20,142,"** Miseries  **");
  outtextxy(20,160,"** Humiliation **");

  gotoxy(20,20);
  cout<<"\n PROGRAM BY ONE & ONLY \n\t ->PANKAJ \n\t -> CLASS XII C \n\n\n\t";

  delay(20000);
  exit(1);
}

void death_message()
{
  cleardevice();

  setcolor(GREEN);
  settextstyle(3, HORIZ_DIR,3);

  outtextxy(20,80,"** You are dead ! TRY AGAIN **");
  outtextxy(20,100,"** You didn't destroyed spider monster  **");
  outtextxy(20,120,"** You left the world from **");
  outtextxy(20,142,"** Miseries  **");
  outtextxy(20,160,"** Humiliation **");

  gotoxy(20,20);
  cout<<"\n PROGRAM BY ONE & ONLY \n\t ->PANKAJ \n\t -> CLASS XII C \n\n\n\t ";

  delay(20000);
  exit(2);
}

void health()
{

	  setcolor(WHITE);
	  settextstyle(2,HORIZ_DIR,6);
	  outtextxy(5,5,"SPIDER'S HEALTH ------------>");

	  setcolor(RED);
	  line(340,10,spi_health,10);
	    line(340,11,spi_health,11);
	      line(340,12,spi_health,12);
		line(340,13,spi_health,13);
		  line(340,14,spi_health,14);
		    line(340,15,spi_health,15);
		      line(340,16,spi_health,16);
			line(340,17,spi_health,17);
			  line(340,18,spi_health,18);
			    line(340,19,spi_health,19);
			      line(340,20,spi_health,20);

	  setcolor(WHITE);
	  settextstyle(2,HORIZ_DIR,6);
	  outtextxy(5,20,"TANK'S HEALTH ------------>");

	  setcolor(RED);
	  line(340,30,tan_health,30);
	    line(340,31,tan_health,31);
	      line(340,32,tan_health,32);
		line(340,33,tan_health,33);
		  line(340,34,tan_health,34);
		    line(340,35,tan_health,35);
		      line(340,36,tan_health,36);
			line(340,37,tan_health,37);
			  line(340,38,tan_health,38);
			    line(340,39,tan_health,39);
			      line(340,40,tan_health,40);


	  setcolor(YELLOW);
	  rectangle(340,10,620,20);
	  rectangle(340,30,620,40);

}
void check_win()
{

   if(tan_health<=340)
    death_message();

   else if(spi_health<=395)
    win_message();
}

void normal_tank_attack()
{
   setcolor(RED);
   rectangle((55+q)-10,440,(55+q)-12,1);

   delay(150);

   if( ( (30+q)>(x-75) )&&( (30+q)<(x+75) ) )
   spi_health-=1;

}

void normal_spider_attack()
{
   setcolor(WHITE);

   for(int v=225;v<600;++v)
   arc(x,v,0,180,10);

   delay(150);

   if( ( x>(10+q) )&&( x<(60+q) ) )
   tan_health-=5;

}

void super_nova_attack()
{
  tank();
  spider();
  health();

  setcolor(GREEN);
  outtextxy(20,60,"SUPER-NOVA ATTACK");

  setcolor(YELLOW);
  for(int v=225;v<600;++v)
  arc(x,v+x,0,180,10+x);

  delay(150);
  tan_health-=10;

}


void thunder_and_lightening_attack()
{
  tank();
  spider();
  health();

	  setcolor(GREEN);
	  outtextxy(20,60,"THUNDER & LIGHTENING ATTACK");

			      //printing yellow thunder attack
	  setcolor(YELLOW);
	  line(45+q,445,x-120,320);
	  line(x-120,320,x+50,130);
	  line(45+q,445,x-70,150);
	  line(45+q,445,x+70,270);
	  line(x+70,270,x,80);        //branches of thunder
	  line(45+q,445,x+20,200);
	  line(x+20,200,x-50,80);
	  line(x+20,220,x+40,80);

	  delay(150);

	  spi_health-=5;

}

void spider_attack()
{
	    count+=1;

	    if(((count%19)==0)&&((x%3)==0))
	    super_nova_attack();	 //Super-Nova Fire Choosen

	    else if(((count%2)==0)&&((x%7)==0))
	    normal_spider_attack();      //Normal Puny Fire Choosen

}

void tank_attack()
{

	  if(((count%5)==0)&&((q%3)==0))
	  thunder_and_lightening_attack();
				//Thunder And Lightening Fire Choosen
	  else
	  normal_tank_attack();
				  //Normal Puny Fire Choosen
}

void pause_screen();

void game_run()
{

 mov_spider:       //Determinig Spider's Initial Position

 while(!kbhit())
  {
  if(x<640)
   {
   mov_tank:

   cleardevice();

   x+=5;

   spider();
   health();
   spider_attack();
   tank();
   check_win();

   delay(90);
   }

  else
  x=1;

  }

 ch=getche();         //Asking User For Type Of Movement Of Tank

 if(ch=='d')          //Tank Moves Right
{ q+=10;
  goto mov_tank;
}

 else if(ch=='a')     //Tank Moves Left
{ q-=10;
  goto mov_tank;
}

 else if(ch=='w')     //Tank Fires
{ tank_attack();
  goto mov_tank;
}

else if(ch=='\b')
pause_screen();

}

void save_game()
{
 int a1=x,a2=q,spi_health1=spi_health,tan_health1=tan_health;

  ofstream tw;
  tw.open("TW.dat",ios::out);
  tw<<a1<<" "<<a2<<" "<<spi_health1<<" "<<tan_health1;

  cleardevice();

  health();
  cout<<"GAME SAVED ";
  cout<<"\nLOADING...";

  tw.close();

  delay(6000);

  game_run();
}

void load_game()
{
 int a1,a2,spi_health1,tan_health1;

  ifstream tw;
  tw.open("TW.dat",ios::in);
  tw.seekg(0);
  tw>>a1>>a2>>spi_health1>>tan_health1;

  x=a1;q=a2;spi_health=spi_health1;tan_health=tan_health1;

  cleardevice();
  health();
  cout<<"GAME RELOADED \n Current Position Of:- tank: "<<(x+q)<<"  spider: "<<(x);
  cout<<"\nLOADING...";


  tw.close();

  delay(6000);

  game_run();
}

void pause_screen()
{
	 cleardevice();

	 setcolor(GREEN);
	 settextstyle(7,HORIZ_DIR,1);

	 outtextxy(20,20,"Press '1' To Resume");
	 outtextxy(20,40,"Press '2' To Restart Game");
	 outtextxy(20,60,"Press '3' To Save Game");
	 outtextxy(20,80,"Press '4' To Load Game");

	 choice=getche();

	 if(choice=='1')
	 game_run();

	 if(choice=='2')
	 {
	  x=1;q=0;count=0;spi_health=620;tan_health=620;
	  game_run();
	 }

	 else if(choice=='3')
	 save_game();

	 else if(choice=='4')
	 load_game();

}

void main()
{
			 // Initializing Graphics
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");

intro_screen();                //Story Page i.e Introduction Viewed
choice=getche();   	       //Asking User To Choose From MAIN MENU

if(choice=='5')
exit(0);

else if(choice=='4')
load_game();

else if(choice=='3')
save_game();

else if(choice=='2')
control_screen();

else if(choice=='1')
game_run();

 getch();

}
