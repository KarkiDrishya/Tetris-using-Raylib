// basically this file is the file which contains the outer blocks of the main inside blocks(more in the presentaion)
#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
using namespace std;

class Block
{ // Block made for inheritance of other 8 big blocks
public:
    Block();
    void Draw(int offsetX, int offsetY);

    void Draw(); // Declartion of draw function fro block.cpp

    void Move(int rows, int columns);

    std::vector<Position> GetCellPositions();

    void Rotate(); //Used to rotate the blocks

    void UndoRotation(); //Used to undo rotation

    int id;

    map<int, vector<Position>> cells; // this is the map function which uses key-value pair, syntax : map<int(rotation state, eg : 0,1,2,3), value(the list of vector which holds the 4 co ordinates, (0,1)(1,0)...)

private:
    int cellSize;

    int rotationState;

    std::vector<Color> colors;

    int rowOffset;

    int columnOffset;

};