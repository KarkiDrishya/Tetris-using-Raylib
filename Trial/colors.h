//this files holds all the values/definitions for colors that are being used in blocks and grid classes

#pragma once
#include<raylib.h>
#include<vector>

extern const Color darkGrey;    //using the extern keyword allows us to declare variable in one file and use it in another file  aswell making it easier to share data across the program
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

std::vector<Color>GetCellColors();