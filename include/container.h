#ifndef OOP_CONTAINER_H
#define OOP_CONTAINER_H

#include <vector>
#include <type_traits>
#include <optional>
#include <algorithm>
#include <iostream>

#include "common.h"

template <typename T>
concept DerivatDinNume = std::is_base_of_v<Nume, T>;

template <DerivatDinNume T>
class Container {
private:
    std::vector<T> data;
    size_t index = 0;
    size_t current_id = 0;

public:
    Container<T>& operator<<(const T& element) {
        const_cast<T&>(element).setId(++current_id);

        data.push_back(element);
        return *this;
    }

    bool operator>>(T& element) {
        if (index < data.size()) {
            element = data[index++];
            return true;
        }
        return false;
    }

    void resetIterator() {
        index = 0;
    }

    std::optional<T> cautaNume(const std::string& name) const {
        auto it = std::find_if(data.begin(), data.end(), [&name](const T& item) {
            return item.getNume() == name;
        });

        if (it != data.end()) {
            return *it;
        }
        return std::nullopt;
    }

    std::optional<T> cautaId(int id) const {
        auto it = std::find_if(data.begin(), data.end(), [&id](const T& item) {
            return item.getId() == id;
        });

        if (it != data.end()) {
            return *it;
        }
        return std::nullopt;
    }

    void print() const {
        for(auto item : data) {
            item.print();
        }
    }

    int size() {
        return data.size();
    }
};

#endif // OOP_CONTAINER_H