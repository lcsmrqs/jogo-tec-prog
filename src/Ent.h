#pragma once

class Ent
{
protected:
    int id;

public:
    Ent(const int _id = -1) : id(_id) {}

    virtual ~Ent() {}

    virtual void run(float dt) = 0;
    virtual void draw() = 0;

    const int getId() const { return id; }
};
