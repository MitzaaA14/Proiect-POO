#ifndef OOP_COMMON_H
#define OOP_COMMON_H

#include <string>

class Nume {
    private:
        int id;
        std::string nume;
    public:
        Nume() {}
        Nume(const std::string& nume) : id(0), nume(nume) {}

        virtual ~Nume() {}

        void setNume(const std::string& setnume) { this->nume = setnume; }
        const std::string& getNume() const { return nume; }

        void setId(const int setid) { this->id = setid; }
        int getId() const { return id; }

        virtual void print() = 0;

        bool operator<(const Nume& altul) const {
            return getId() < altul.getId();
        }

        bool operator==(const Nume& altul) const {
            return getId() == altul.getId();
        }        
};

#endif