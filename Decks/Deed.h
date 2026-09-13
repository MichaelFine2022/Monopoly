#pragma once

class Deed {
    public:
    virtual int getRent();
    virtual int getCost();
    protected:
    int rent;
    int cost;
};
