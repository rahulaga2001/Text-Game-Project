#include<iostream>
#include<cmath>
#include<random>
#include<string>
#include<ctime>
#include <fstream>
#include "avatars.h"
#include "instructions.h"
using namespace std;
int hp=0,fear=0, level=1,damage=0;
int power,luck,speed,courage;
int critical_chance;
int enemies_eliminated=0;
void rules() 
{
    cout<<"\nHere are the rules of the game stone seeker!\n"<<endl;
    cout<<"\nYou'll have to enter the following to choose your weapon : \n\t1 - Crossbow \n\t2 - Phoenix Wand \n\t3 - Zeus' Thunderbolt \n\t4 - Vipertooth Trident\n\n"<<endl;
    ifstream file1;
      file1.open("Weapon.txt"); //Text file containing details about weapons
      string line1;
      if(file1.is_open())
      {
        while (getline(file1,line1))
        {
          cout << line1 <<endl;
        }
      }
      file1.close();
      cout << "\nOpponent Information: " << endl;
      ifstream file2;
      file2.open("Opponent.txt"); //Text file containing opponent information
      string line2;
      if(file2.is_open())
      {
        while (getline(file2,line2))
        {
          cout << line2 <<"\n"<<endl;
        }
      }
      file2.close();
    cout << "\nKey: \n\tH - HP\n\tF - Fear\n" << endl;
    cout << "Total number of levels = 4\n\nDefeat your enemy at the end of every level and win the game\nThe same enemy can rise again to take revenge!" << endl;
    cout << "\nLosing criteria:\n\tH < 0\n\tF > 20" << endl;

}
int character()
{
  int avat;
  cout<<"\nLET'S EMBARK ON THIS PERILOUS JOUNREY TO THE STONE OF IMMORTALITY!\n"<<endl;

  //Displaying Player's Character Options
  cout<<"Choose your character"<<endl;
  cout<<"1 : Wizard"<<endl;   
  cout<<"\t"<< "Power = 10";
  cout<<"\t" <<"Speed =6";
  cout<<"\t"<< "Luck = 4";
  cout<<"\t"<< "Courage = 5"<<endl;
  cout<<"2 : Centaur"<<endl;
  cout<<"\t"<< "Power = 6";
  cout<<"\t"<< "Speed =10";
  cout<<"\t"<< "Luck = 4";
  cout<<"\t"<< "Courage = 3"<<endl;
  cout<<"3 : Goblin"<<endl;
  cout<<"\t"<< "Power = 4";
  cout<<"\t"<< "Speed =4";
  cout<<"\t"<< "Luck = 8";
  cout<<"\t"<< "Courage = 6"<<endl;
  cout<<"4 : Elf"<<endl;
  cout<<"\t"<< "Power = 6";
  cout<<"\t"<< "Speed = 6";
  cout<<"\t"<< "Luck = 6";
  cout<<"\t"<< "Courage = 10"<<endl;
  cin>>avat;
  return avat;
}
int main()
{
  fstream fout;
  string name[]={};
  int num_of_enemies=0;
  int hp=0,fear=0,level=1,p=0,avatar,enemy_hp,damage;
  int *weapon;
  string choice;
  srand(time(0));
  rules();  //to display the rules of the game
  avatar=character(); //to assign character

  //assigning values to the variables using value of avatar
  if(avatar==1)
    power=10,speed=6,luck=4,courage=5;
  if(avatar==2)
    power=6,speed=10,luck=4,courage=3;
  if(avatar==3)
    power=4,speed=4,luck=8,courage=6;
  if(avatar==4)
    power=6,speed=6,luck=6,courage=10;

  fear= 0; //initial value of fear
  hp=power*2 + speed; //initial value of health points
  ::hp=hp;
  ::fear=fear;

  cout<<"\t CURRENT STATS\n"<<endl; //initial stats
  cout<<"\t Level : "<<::level<<endl;
  cout<<"\t H     : "<<::hp<<endl;
  cout<<"\t F     : "<<::fear<<endl;

  cout<<"\nFind the stone before time runs out!\n"<<endl;
  string name_enemy[4]={};
  ifstream fin;
  fin.open("Opponents.txt"); //Text file containing names of opponents
  string line;
  if(fin.is_open())
  {
      int i=0;
      while (getline(fin,line))
      {
        name_enemy[i]=line;
        i++;
      }
  }
  fin.close(); 
  int flag=0;

  int quiz=rand()%4;
  int ans;
  string elim[4]={};
  while(level<5 && flag==0)
  {
    cout << "CURRENT LEVEL: " << level << endl;
    int enemy=rand()%4;                   //deciding the enemy
    int hp_enemy=(enemy+1)*2*level; 
    int health_damage=0;
    int fear_damage=0;
    //Pop-Up Mystery Quiz
    if(level==(quiz+1)) 
    {
      cout << "\n\tTHE GATEKEEPER HAS FOUND YOU!\n\nANSWER THIS QUESTION TO ESCAPE HIM\n\n";
      cout << "\nWhich Weapon in your arsenal belongs to an Olympian God? Enter the number";
      cout << "\n\t1 - Crossbow \n\t2 - Wand \n\t3 - Thunderbolt \n\t4 - Trident\n";
      cin >> ans;
      if(ans==3)
      {
        cout <<"Well done seeker! You have escaped the GATEKEEPER\n";
        cout <<"You have been rewarded\nA part of your health has been regenerated"<<endl;
        hp+=3;
      }
      else
      {
        cout <<"Wrong Answer\nYou have been attacked by the GATEKEEPER\nYou have lost a part of your HP\n";
        hp-=3;
        if(hp<=0 || fear>=20)
          {
            cout<<"THE FORCES PROTECTING THE STONE HAVE WON\n\n\t GAME OVER"<<endl;
            flag=1;
            break;
          }

      }
    }
    cout << "\nBattle it out with the ";

    //Displaying Enemy's Name for the given Level
    if(enemy==0)
    {
        cout << name_enemy[0]<< endl;
        cout << "\nExtremely dangerous enemy whose flames can reach to about 50 feet" << endl;
        fear_damage=1;
        health_damage=3+level;
    }
    if(enemy==1)
    {
        cout << name_enemy[1]<< endl;
        cout << "\nLightning quick and almost unconquerable beast capable of devouring any being." << endl;
        fear_damage=3;
        health_damage=3+level;
    }
    if(enemy==2)
    {
        cout <<  name_enemy[2] << endl;
        cout << "\nVenomous creature with moderate speed." << endl;
        fear_damage=5;
        health_damage=2+level;
    }
    if(enemy==3)
    {
        cout<< name_enemy[3]<< endl;
        cout << "\nMysterious giant serpent bred by the darkest of wizards."<<endl;
        fear_damage = 1;
        health_damage=8+level;
    }
    while(hp_enemy>0 && flag==0) //works until the player gives up or the enemy is defeated
    {
        cout<<"\n\tH   : "<< hp <<endl;
        cout<<"\tF   : "<< fear << "\n\n";
        cout<<"What do you choose to do?\n\n\t";
        cout<<"1. Attack\n\t";
        cout<<"2. Run Away\n";
        int action;
        cin >> action;
        if(action==1) //attack
        {
          cout<<"\nYou have the following weapons:\n\n\t";
          cout << "1: Hungarian Crossbow\n\t";
          cout << "2: Phoenix Wand\n\t";
          cout << "3: Zeus' Thunderbolt\n\t";
          cout << "4: Vipertooth Trident\n\t"<<endl;
          cout << "What's your weapon going to be? Input the number" << endl;
          weapon = new int;
          cin >> *weapon; //player's choice of weapon for the enemy
        
          //calculating damage and other stats depending upon the enemy and weapon used
          if(enemy==0 && *weapon != 1)
          {
            damage=(rand() %(power+speed)+5)+3;
            critical_chance=rand() % luck+1;
            if(critical_chance>3)
            {
                damage*=2;
            }
          }
          else if(enemy==1 && *weapon != 2)
          {
            damage=(rand() %(power+speed)+5)-3;
            critical_chance=rand() % luck+1;
            fear--;
            if(critical_chance>3)
            {
                damage*=2;
            }
          }
          else if(enemy==2 && *weapon != 3)
          {
            damage=rand() %(power+speed)+2;
            critical_chance=rand() % luck+1;
            if(critical_chance>3)
            {
            damage*=2;
            }
          }
          else if(enemy==3 && *weapon != 4)
          {
            damage=(rand() %(power+speed)+5)-5;
            critical_chance=rand() % luck+1;
            if(critical_chance>3)
            {
            damage*=2;
            }
          }
          else
          {
            damage=(rand() %(power+speed)+5);
            critical_chance=rand() % luck+1;
            if(critical_chance>3)
            {
            cout << "Critical hit!" << endl;
            damage*=2;
            }
          }

          //updating player's HP and fear and the enemy's hp
          hp_enemy-=damage;
          cout << damage << " Damage done to the enemy\n" << endl;
          cout<<health_damage<<" Damage inflicted upon you\n"<<endl;
          hp=hp-health_damage;
          fear+=fear_damage;

          //if player's HP equals or falls below 0 or Fear goes over 20 i.e. the player stands defeated
          if(hp<=0 || fear>=20)
          {
            cout<<"THE FORCES PROTECTING THE STONE HAVE WON\n\n\t GAME OVER"<<endl;
            flag=1;
          }

          //if enemy's HP equals or falls below zero i.e. the enemy for the level stands defeated
          if(hp_enemy<=0)
          {
            cout<<"You have slain the monster\n"<<endl;
            hp+=level*2+enemies_eliminated;
            cout<<"A part of your health has been regenerated\n\n\t";
            elim[num_of_enemies]=name_enemy[enemy];
            enemies_eliminated++;
            num_of_enemies++;
          }
          if (enemies_eliminated!=0)
          {
            level++;
            cout << "You have leveled up!\n\n";
            hp=power*2 + speed + level*2;
            enemies_eliminated=0;
          }
        }

        //if the player decides to give up
        if(action==2)
        {
          hp=hp-health_damage;
          fear+=fear_damage;
          cout<<"\t\tTHE STONE BELONGS ONLY TO THE BRAVE! GAME OVER"<<endl;
          flag=1;
        }
    }
  }
  if(flag==0)
  {
    cout<<"\n\t\tTHE WORLD BENDS THE KNEE TO YOU!\n\tTHE STONE OF IMMORTALITY IS YOURS SEEKER\n"<<endl;
  }
  ofstream outputfile;
  outputfile.open("Statistics.txt");
  outputfile << "\n\nENEMIES DEFEATED = " << num_of_enemies << " " << endl; //writing final stats to the file
  outputfile << "\nNAME OF ENEMIES : \n"<<endl;
  for (int j=0; j<4; j++)
      outputfile << elim[j] << endl;
  outputfile.close();
  ifstream file;
  file.open("Statistics.txt");
  string line2;
  if(file.is_open())
  {
      int i=0;
      while (getline(file,line2)) //displaying final stats
      {
        cout << line2 <<endl;
      }
  }
  file.close();

  delete weapon;
  weapon=0;

  return 0;
}

  
