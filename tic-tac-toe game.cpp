#include<iostream>
#include<ctime>
#include<random>

using namespace std;
char board[9] = {' ' , ' ', ' ',' ', ' ',' ',' ',' ',' '};
void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

int main(){

    int mode;
    cout<<"1. computer vs Player"<<endl;
    cout<<"2. Player vs Player"<<endl;
    cout<<"Select Game Mode" <<endl;
    cin>> mode;

    switch(mode){
        case 1: 
        computer_vs_player();
        break;
        case 2:
        player_vs_player();
        break;
        default:
        cout<<"Please select Valid Game Mode"<<endl;
        break;
    }

    return 0;
}

void computer_vs_player(){
    string player_name;
    cout<<"Enter your Name: ";
    cin>>player_name;

    while(true){
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')){
            cout<< player_name << "'s Turn."<<endl;
            get_x_player_choice();
        }
        else{
            get_computer_choice();
        }
        char winner= check_winner();
        if(winner == 'X'){
            system("cls");
            show_board();
            cout<<player_name<<"Win the Game."<<endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            show_board();
            cout<<"Computer WON the Game"<<endl;
        }
        else if(winner == 'D'){
            cout<<"Game is Draw"<<endl;
            break;
        }

    }
}

void get_computer_choice(){
    srand(time(0));
    int choice;
    do{
        choice = rand() % 10;

    }while(board[choice] != ' ');
    board[choice] = '0';

}

void get_x_player_choice(){
    while(true){
        cout<<"select your Position(1-9) : ";
        int choice;
        cin>>choice;
        choice--;
        if(choice<0 || choice>8){
            cout<<"Please check your choice"<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"please select an empty position "<<endl;
        }
        else{
            board[choice] = 'X';
            break;
        }
    }
}

void get_o_player_choice(){
    while(true){
        cout<<"select your Position(1-9) : ";
        int choice;
        cin>>choice;
        choice--;
        if(choice<0 || choice>8){
            cout<<"Please check your choice"<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"please select an empty position "<<endl;
        }
        else{
            board[choice] = 'O';
            break;
        }
    }
}

void player_vs_player(){
    string x_player_name, o_player_name;
    cout<<"Enter X player name: ";
    cin>>x_player_name;
    cout<<"Enter O player name: ";
    cin>>o_player_name;
    while(true){
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')){
            cout<<x_player_name<< " 's Turn."<<endl;
            get_x_player_choice;
        }

        else{
            cout<<o_player_name<< "'s Turn."<<endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if(winner == 'X'){
            system("cls");
            show_board();
            cout<<x_player_name<<"won the Game"<<endl;
            break;
        }
        else if(winner == 'O'){
            system("cls");
            show_board();
            cout<<o_player_name<<"won the Game"<<endl;
            break;
        }
        else if(winner == 'D'){
            cout<<"Game is Draw"<<endl;
            break;
        }
    }
}


int count_board(char symbol){
    int total = 0;
    for(int i = 0 ; i<9; i++){
        if(board[i] == symbol)
        total += 1;
    }
    return total;
}
char check_winner(){
    //check winner in horizontal
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    return board[6];

    //check winner in vertical
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    return board[1];
    if(board[2] == board[5] && board[3] == board[8] && board[2] != ' ')
    return board[2];

    //check winner in diagonal
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    return board[2];

    if(count_board('X') + count_board('O')<9)
    return 'C';
    else 
    return 'D';
}
void show_board() {
    cout<<" " << "  |  " <<"  |  "<<endl;
    cout<<" "<<board[0] << " |  " <<board[1]<<" |  "<<board[2] << endl;
    
    cout<<"-------------"<<endl;

    cout<<" " << "  |  " <<"  |  "<<endl;
    cout<<" "<<board[3] << " |  " <<board[4]<<" |  "<<board[5] << endl;
    
     cout<<"------------"<<endl;

    cout<<" " << "  |  " <<"  |  "<<endl;
    cout<<" "<<board[6] << " |  " <<board[7]<<" |  "<<board[8] << endl;

     cout<<"-------------"<<endl;
}
