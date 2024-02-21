 #include<iostream>
 #include<cstdlib>
 #include<ctime>
 using namespace std;
 int main(){
    cout<<" -------Welcome in Number Gussing Game-----------"<<endl;
    cout<<"Guess number between 1 to 9 "<<endl;

    srand(time(0));
    int randNumber = (rand() % 10) + 1;
    cout<<"Total 5 Chances "<<endl;
    int Chanceleft = 5;
    int input;
    for(
        input = 1; input<=5 ; input++
    ){
        cout<<"enter number: " <<endl;
        cin >> input;
        if(input == randNumber){
            cout<<"Nice!You Guessed it right ";
            break;
        }
        else{
            cout<<"Sorry! Try another Time";
        }
    }
 }