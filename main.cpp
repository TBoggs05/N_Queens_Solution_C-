#include <iostream>
#define SIZE 8
using namespace std;
bool check_left_up(int board[SIZE][SIZE], int col, int row){
//left one, up one
     int i = col-1;
     int j = row-1;
    for(; i >= 0 && j >= 0; i--){
        if(board[j][i] == 1)
            return true;
        j--;
    }
    return false;
}
bool check_right_up(int board[SIZE][SIZE], int col, int row){
  //right one, up one
     int i = col+1;
     int j = row-1;
     for(; i < SIZE && j >= 0; i++){
        if(board[j][i] == 1)
            return true;
        j--;
    }
    return false;
}
bool check_left_down(int board[SIZE][SIZE], int col, int row){
   //left one, down one
     int i = col-1;
     int j = row+1;
     for(; i >= 0 && j < SIZE; i--){
        if(board[j][i] == 1)
            return true;
        j++;
    }
    return false;
}
bool check_right_down(int board[SIZE][SIZE], int col, int row){
     //right one, down one
     int i = col+1;
     int j = row+1;
     for(; i < SIZE && j < SIZE; i++){
            if(board[j][i] == 1)
                return true;
            j++;
        }
        return false;
}
bool isThreatened(int board[SIZE][SIZE], int col, int row){
    for(int c = 0; c < SIZE; c++){
        //check the row and col of the given tile
        if(board[row][c] == 1 || board[c][col] == 1)
            return true;
    }
    //check diagonals on standard tile
    if(row != 0 && col != 0 && row < SIZE && col < SIZE){
    if(check_left_up(board, col, row)){return true;}
    if(check_right_up(board, col, row)){return true;}
    if(check_right_down(board, col, row)){return true;}
    if(check_left_down(board, col, row)){return true;}
    }
    //border tile cases
    else{
    if(row == 0){
        if(col == 0){
            if(check_right_down(board, col, row)){return true;}
        }
        else if(col == SIZE-1){
            if(check_left_down(board, col, row)){return true;}
        }
        else{
        if(check_right_down(board, col, row)){return true;}
        if(check_left_down(board, col, row)){return true;}
            }
    }
    else if(col == 0){
        if(row == SIZE-1){
             if(check_right_up(board, col, row)){return true;}
        }
        else{
            if(check_right_up(board, col, row)){return true;}
            if(check_right_down(board, col, row)){return true;}
        }
    }
    else if(row == SIZE-1){
            if(col == SIZE-1){
                if(check_left_up(board, col, row)){return true;}
            }
            else{
                if(check_left_up(board, col, row)){return true;}
                if(check_right_up(board, col, row)){return true;}
            }
    }
    else{
            if(check_left_up(board, col, row)){return true;}
            if(check_left_down(board, col, row)){return true;}
    }
    }
    return false;
}
void print_Queens(int board[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int c = 0; c < SIZE; c++){
            cout<<board[i][c]<<" ";
        }
            cout<<endl;
    }


}
bool place_Queens(int board[SIZE][SIZE], int num_queens){
if(num_queens == 0){
    //call place function, once it completes, call it again with the last queen moved down one.
    print_Queens(board);
    cout<<endl;
    return true;
}
    else{
    int curr_col = abs(num_queens-SIZE);
    bool placed = false;
        //loop through curr_col
        for(int i = 0; i < SIZE; i++){
                //if square is found that is not threatened:
            if(!(isThreatened(board, curr_col, i))){
                //place queen in square
                board[i][curr_col] = 1;
                placed = true;
                    //try the next column
                    if(!place_Queens(board, num_queens-1)){//if(recursion fails)->no queen is possible in next number
                        placed = false;
                        for(int i = 0; i < SIZE; i++){board[i][curr_col] =0;}//clear last row
                    }
                    //if recursion succeeds, return true.
                    else{
                    return true;
                    }
            }
        }
        return false;
    }
}
int main(){
cout<<"8 Queens Solution: "<<endl;
int board[SIZE][SIZE] = {0};

place_Queens(board, SIZE);


return 0;
}
