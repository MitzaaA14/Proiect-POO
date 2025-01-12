#ifndef OOP_COMMON_H
#define OOP_COMMON_H

#include <string>

class Nume {
private:
    int id;
    std::string nume;
public:
    Nume() {}

    Nume(std::string nume) : nume(nume) {}

    virtual ~Nume() {}

    void setNume(std::string nume) { this->nume = nume; }

    std::string getNume() const { return nume; }

    void setId(const int id) { this->id = id; }

    int getId() const { return id; }

    virtual void print() = 0;
};
#endif