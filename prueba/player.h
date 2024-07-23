#pragma once
#include "Library/Game.h"

class Player : public Game{
public:
void start() override;
void update() override;
void draw() override;
void deleteDraw() override;
};