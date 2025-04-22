// [A] C++ Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

// Base class
class Base {
public:
    enum class eType {
        ANIMAL,
        DIGIMON
    };

    virtual ~Base() = default;
    virtual void Read(std::ostream& ostream, std::istream& istream);
    virtual void Write(std::ostream& ostream);
    virtual std::string GetName() { return m_name; }
    virtual eType GetType() const = 0;

protected:
    std::string m_name;
};

void Base::Read(std::ostream& ostream, std::istream& istream) {
    ostream << "Enter name: ";
    istream >> m_name;
}

void Base::Write(std::ostream& ostream) {
    ostream << "Name: " << m_name << std::endl;
}

// Animal class
class Animal : public Base {
public:
    enum class eAnimalType {
        MAMMAL,
        REPTILE,
        BIRD
    };

    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    eType GetType() const override { return eType::ANIMAL; }

private:
    int m_speed;
    eAnimalType m_animalType;
};

void Animal::Read(std::ostream& ostream, std::istream& istream) {
    Base::Read(ostream, istream);
    ostream << "Enter speed: ";
    istream >> m_speed;
}

void Animal::Write(std::ostream& ostream) {
    Base::Write(ostream);
    ostream << "Speed: " << m_speed << std::endl;
}

// Digimon class
class Digimon : public Base {
public:
    enum class eDigimonType {
        INSECT,
        MACHINE,
        BEAST
    };

    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    eType GetType() const override { return eType::DIGIMON; }

private:
    std::string m_level;
    eDigimonType m_digimonType;
};

void Digimon::Read(std::ostream& ostream, std::istream& istream) {
    Base::Read(ostream, istream);
    ostream << "Enter Level: ";
    istream >> m_level;
}

void Digimon::Write(std::ostream& ostream) {
    Base::Write(ostream);
    ostream << "Level: " << m_level << std::endl;
}

// Database class
class Database {
public:
    Database() {}
    ~Database();

    void Create(Base::eType type);
    void DisplayAll();
    void Display(const std::string& name);
    void Display(Base::eType type);

private:
    std::vector<Base*> m_objects;
};

Database::~Database() {
    for (auto object : m_objects) {
        delete object;
    }
}

void Database::Create(Base::eType type) {
    Base* newObj = nullptr;
    switch (type) {
    case Base::eType::ANIMAL:
        newObj = new Animal;
        break;
    case Base::eType::DIGIMON:
        newObj = new Digimon;
        break;
    default:
        std::cout << "Invalid type\n";
        return; // Return if type is invalid
    }
    if (newObj) {
        newObj->Read(std::cout, std::cin);
        m_objects.push_back(newObj);
    }
}

void Database::DisplayAll() {
    for (auto object : m_objects) {
        object->Write(std::cout);
    }
}

void Database::Display(const std::string& name) {
    for (auto object : m_objects) {
        if (object->GetName() == name) {
            object->Write(std::cout);
        }
    }
}

void Database::Display(Base::eType type) {
    for (auto object : m_objects) {
        if (object->GetType() == type) {
            object->Write(std::cout);
        }
    }
}

int main() {
    Database database;
    bool quit = false;
    while (!quit) {
        std::cout << "1 - Create\n"
            "2 - Display All\n"
            "3 - Display Name\n"
            "4 - Display Type\n"
            "5 - Quit\n"
            "Enter choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "1) Animal\n"
                "2) Digimon\n"
                "Enter type: ";
            int type;
            std::cin >> type;
            database.Create(static_cast<Base::eType>(type - 1));
            break;
        }
        case 2:
            database.DisplayAll();
            break;
        case 3: {
            std::string name;
            std::cout << "Enter name: ";
            std::cin >> name;
            database.Display(name);
            break;
        }
        case 4: {
            std::cout << "1) Animal\n"
                "2) Digimon\n"
                "Enter type: ";
            int type;
            std::cin >> type;
            database.Display(static_cast<Base::eType>(type - 1));
            break;
        }
        case 5:
            quit = true;
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    }
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
