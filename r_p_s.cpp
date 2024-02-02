//ROCK-PAPER-SCISSOR GAME

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;



char computers_turn(){
    srand(time(NULL));
    int answer=rand()%3;
    
    if (answer==0)
        return 'r';
    else if (answer==1)
        return 'p';
    else
        return 's';
}


int getResult(char answer1,char answer2){
    if (answer1=='r' && answer2=='p')
        return -1;
    else if (answer1=='r' && answer2=='s')
        return 1;
    else if (answer1=='p' && answer2=='r')
        return 1;
    else if (answer1=='p' && answer2=='s')
        return -1;
    else if (answer1=='s' && answer2=='p')
        return 1;
    else if (answer1=='s' && answer2=='r')
        return -1;
}


int main(){

char answer1,answer2;
int points1=0,points2=0,result,rounds;
cout<<"How many rounds would you like to play?"<<endl;
cin>>rounds;
cout<<ceil(rounds/2.0)<<endl;

while ( points1!=ceil(rounds/2.0) &&  points2!=ceil(rounds/2.0) ){
    cout<<"Give your answer"<<endl;
    cin>>answer1;
    answer2=computers_turn();
    cout<<"Computers answer was: "<<answer2<<endl;

    result=getResult(answer1,answer2);
    if (result==1){
        points1++;
        cout<<"You got 1 point!"<<endl;
    }
    else{
        points2++;
        cout<<"Computer got 1 point"<<endl;
    }
    cout<<points1<<" "<<points2<<endl;
}

if (points1==ceil(rounds/2))
    cout<<"Congratulations! You won. "<<endl;
else
    cout<<"You lost. "<<endl;

}