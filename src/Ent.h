#pragma once

class Ent
{
protected:
    int id; // TODO: getters and setters

public:
    Ent(const int id = 0) : id(id) {}

    virtual ~Ent() {}

    virtual void run(float dt) = 0;

    virtual void draw() = 0;
};
