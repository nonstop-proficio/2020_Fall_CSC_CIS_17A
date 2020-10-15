#ifndef PIECES_H
#define PIECES_H

//Stores information used to display pieces
struct Piece {
	string name;
	string letters;
	int value;
	bool dead;
	int row;
	int col;
	string color;
};

//Stores information used to move pieces
struct Ply {
    int pRow; //Current piece row
    int pCol; //Current piece column
    int dRow; //Destination row
    int dCol; //Destination column
};

#endif 