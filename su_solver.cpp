#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
//defining macros
#define DASH "-------------------------------------"
#define SPACE " "
#define BLANK 0
#define MESH_FULL make_pair(9,9)

pair<int, int> find_empty_loc(int mesh[9][9]){
		for(int r = 0;r<9;r++){
				for(int c=0;c<9;c++){
						if(mesh[r][c]==BLANK){
							return make_pair(r,c); //MAKES PAIRS OF THE ARRAY WHICH IS FOUND EMPTY
						}
				}
		}
		return MESH_FULL;
}

bool pres_row(int mesh[9][9],int row, int i){ //traverse through columns
	for(int col=0;col<9;col++){
		if(mesh[row][col]==i){
			return true;
		}
	}
	return false;
	
}

bool pres_col(int mesh[9][9],int col, int i){ //traverse through columns
	for(int row=0;row<9;row++){
		if(mesh[row][col]==i){
			return true;
		}
	}
	return false;
	
}

bool pres_box(int mesh[9][9],int box_row, int box_col, int i){ //traverse through cells in box (assume 3x3)
	for(int row=0;row<3;row++){
		for(int col=0;col<3;col++){
			if(mesh[row + box_row][col+box_col]==i){
				return true;
			}
		}
	}
	return false;
}

bool num_valid(int mesh[9][9], int row,int col,int i){
	//return negation if the number is present in either row, col, or box
	return !((pres_row(mesh,row,i)||pres_col(mesh,col,i)||pres_box(mesh,row-row%3,col-col%3,i)));
}

void print_mesh(int mesh[9][9]){ //if image is taken from python?
	for(int i=0;i<9;i++){
		cout<<SPACE<<SPACE<<SPACE<<SPACE<<endl;
		cout<<DASH<<endl;
		
		for(int j=0;j<9;j++){
			
			if(mesh[i][j] == BLANK){
				cout<<SPACE;
			}
			else{
				cout<<mesh[i][j];
			}
			cout<<SPACE;
			cout<<"|";
		}
	}
		cout<<endl<<DASH<<endl<<endl;
	
}
	
bool sudoku_solver(int mesh[9][9]){
	if(MESH_FULL == find_empty_loc(mesh)){ //return as soon as it reaches the last pair(9,9)
		return true;
	}
	pair <int,int> loc = find_empty_loc(mesh); //finds the next empty location which is balnk
	int row=loc.first;
	int col=loc.second;
	for(int i=1;i<=9;i++){
		if(num_valid(mesh,row,col,i)){ //search if any number is valid in order( 1 to 9 )
			mesh[row][col]=i;
			if(sudoku_solver(mesh)){
				return true;
			}
			mesh[row][col]=BLANK;//if nothing fits in backtracking 
		}
	}
	return false;
}
			
int main(){
	cout<<"WELCOME TO SUDOKU SOLVER"<<endl;
	int mesh[9][9] = {{ 0, 9, 0, 0, 0, 0, 8, 5, 3 },
						   { 0, 0, 0, 8, 0, 0, 0, 0, 4 },
						   { 0, 0, 8, 2, 0, 3, 0, 6, 9 },
						   { 5, 7, 4, 0, 0, 2, 0, 0, 0 },
						   { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						   { 0, 0, 0, 9, 0, 0, 6, 3, 7 },
						   { 9, 4, 0, 1, 0, 8, 5, 0, 0 },
						   { 7, 0, 0, 0, 0, 6, 0, 0, 0 },
						   { 6, 8, 2, 0, 0, 0, 0, 9, 0 }};
	print_mesh(mesh);
	if(true == sudoku_solver(mesh)){
		print_mesh(mesh);
	}
	else{
		cout<<"SUDOKU can't be solved for the given input"<<endl;
	}
	return 0;
}
	
