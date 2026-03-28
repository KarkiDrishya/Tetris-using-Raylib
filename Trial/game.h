#pragma once
#include"grid.h"
#include"blocks.cpp"
class Game
{
    public:
    Game();
    ~Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockDown();
    void MoveBlockRight();
    // handles the input that the player provides
    Grid grid;
    bool gameOver; 
    int score;
    Music music;

private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownpoints);
    std::vector<Block>blocks;
    Block currentBlock;
    Block nextBlock;
    Sound clearSound;
    Sound move;
};