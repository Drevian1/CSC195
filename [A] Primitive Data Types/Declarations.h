#pragma once
enum Meat
{
    Pastrami,
    Chicken,
    Pork,
    Prawns
};

class Sandwich
{
public:
    Meat meat;
    float weight;

    void heatSandwich();
    
private:
    bool isHot;
};