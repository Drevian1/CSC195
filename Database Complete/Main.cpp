#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <algorithm>
#include <fstream>
#include <limits>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Base {
public:
    enum class eType {
        ANIMAL,
        DIGIMON
    };

    virtual ~Base() = default;
    virtual void Read(std::ostream& ostream, std::istream& istream);
    virtual void Write(std::ostream& ostream);
    virtual void Serialize(std::ostream& ostream);
    virtual void Deserialize(std::istream& istream);
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

void Base::Serialize(std::ostream& ostream) {
    ostream << m_name << std::endl;
}

void Base::Deserialize(std::istream& istream) {
    istream >> m_name;
}

class Animal : public Base {
public:
    enum class eAnimalType {
        MAMMAL,
        REPTILE,
        BIRD
    };

    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    void Serialize(std::ostream& ostream) override;
    void Deserialize(std::istream& istream) override;
    eType GetType() const override { return eType::ANIMAL; }

private:
    int m_speed;
    eAnimalType m_animalType;
};

void Animal::Read(std::ostream& ostream, std::istream& istream) {
    Base::Read(ostream, istream);
    while (true) {
        ostream << "Enter speed: ";
        istream >> m_speed;
        if (istream.fail()) {
            istream.clear();
            istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ostream << "Invalid input. Please enter a numeric value for speed.\n";
        }
        else {
            istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

void Animal::Write(std::ostream& ostream) {
    Base::Write(ostream);
    ostream << "Speed: " << m_speed << std::endl;
}

void Animal::Serialize(std::ostream& ostream) {
    Base::Serialize(ostream);
    ostream << m_speed << std::endl;
}

void Animal::Deserialize(std::istream& istream) {
    Base::Deserialize(istream);
    istream >> m_speed;
    istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Digimon : public Base {
public:
    enum class eDigimonType {
        INSECT,
        MACHINE,
        BEAST
    };

    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    void Serialize(std::ostream& ostream) override;
    void Deserialize(std::istream& istream) override;
    eType GetType() const override { return eType::DIGIMON; }

private:
    std::string m_level;
    eDigimonType m_digimonType;
};

void Digimon::Read(std::ostream& ostream, std::istream& istream) {
    Base::Read(ostream, istream);
    ostream << "Enter Level: ";
    istream >> m_level;
    istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Digimon::Write(std::ostream& ostream) {
    Base::Write(ostream);
    ostream << "Level: " << m_level << std::endl;
}

void Digimon::Serialize(std::ostream& ostream) {
    Base::Serialize(ostream);
    ostream << m_level << std::endl;
}

void Digimon::Deserialize(std::istream& istream) {
    Base::Deserialize(istream);
    istream >> m_level;
    istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Database {
public:
    Database() {}
    ~Database();

    std::unique_ptr<Base> Create(Base::eType type);
    void DisplayAll();
    void Display(const std::string& name);
    void Display(Base::eType type);
    void Remove(const std::string& name);
    void Remove(Base::eType type);
    void Save(const std::string& filename);
    void Load(const std::string& filename);

private:
    std::list<std::unique_ptr<Base>> m_objects;
};

Database::~Database() {}

std::unique_ptr<Base> Database::Create(Base::eType type) {
    std::unique_ptr<Base> newObj;
    switch (type) {
    case Base::eType::ANIMAL:
        newObj = std::make_unique<Animal>();
        break;
    case Base::eType::DIGIMON:
        newObj = std::make_unique<Digimon>();
        break;
    }
    if (newObj) {
        newObj->Read(std::cout, std::cin);
        m_objects.push_back(std::move(newObj));
    }
    return newObj;
}

void Database::DisplayAll() {
    std::cout << "Displaying all objects in the database:\n";
    for (auto& object : m_objects) {
        object->Write(std::cout);
    }
}

void Database::Display(const std::string& name) {
    std::cout << "Displaying objects with name \"" << name << "\":\n";
    for (auto& object : m_objects) {
        if (object->GetName() == name) {
            object->Write(std::cout);
        }
    }
}

void Database::Display(Base::eType type) {
    std::cout << "Displaying objects of type ";
    if (type == Base::eType::ANIMAL)
        std::cout << "Animal:\n";
    else
        std::cout << "Digimon:\n";
    for (auto& object : m_objects) {
        if (object->GetType() == type) {
            object->Write(std::cout);
        }
    }
}

void Database::Remove(const std::string& name) {
    auto iter = m_objects.begin();
    while (iter != m_objects.end()) {
        if ((*iter)->GetName() == name) {
            iter = m_objects.erase(iter);
        }
        else {
            ++iter;
        }
    }
}

void Database::Remove(Base::eType type) {
    auto iter = m_objects.begin();
    while (iter != m_objects.end()) {
        if ((*iter)->GetType() == type) {
            iter = m_objects.erase(iter);
        }
        else {
            ++iter;
        }
    }
}

void Database::Save(const std::string& filename) {
    std::ofstream file(filename, std::ios::out);
    if (file.is_open()) {
        for (auto& object : m_objects) {
            file << static_cast<int>(object->GetType()) << std::endl;
            object->Serialize(file);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for saving\n";
    }
}

void Database::Load(const std::string& filename) {
    std::ifstream file(filename, std::ios::in);
    if (file.is_open()) {
        m_objects.clear();
        while (!file.eof()) {
            int type;
            file >> type;
            if (file.eof()) break;
            std::unique_ptr<Base> obj;
            switch (static_cast<Base::eType>(type)) {
            case Base::eType::ANIMAL:
                obj = std::make_unique<Animal>();
                break;
            case Base::eType::DIGIMON:
                obj = std::make_unique<Digimon>();
                break;
            }
            if (obj) {
                obj->Deserialize(file);
                m_objects.push_back(std::move(obj));
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file for loading\n";
    }
}

int main() {
    Database* database = new Database;
    bool quit = false;
    while (!quit) {
        std::cout << "\n1 - Create\n"
            "2 - Display All\n"
            "3 - Display Name\n"
            "4 - Display Type\n"
            "5 - Remove by Name\n"
            "6 - Remove by Type\n"
            "7 - Save Database\n"
            "8 - Load Database\n"
            "9 - Quit\n"
            "Enter choice: ";
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            std::cout << "1) Animal\n"
                "2) Digimon\n"
                "Enter type: ";
            int type;
            std::cin >> type;
            if (std::cin.fail() || (type != 1 && type != 2)) {
                std::cin.clear();
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid type. Please enter 1 for Animal or 2 for Digimon.\n";
                continue;
            }
            database->Create(static_cast<Base::eType>(type - 1));
            break;
        }
        case 2:
            database->DisplayAll();
            break;
        case 3: {
            std::string name;
            std::cout << "Enter name: ";
            std::cin >> name;
            database->Display(name);
            break;
        }
        case 4: {
            std::cout << "1) Animal\n"
                "2) Digimon\n"
                "Enter type: ";
            int type;
            std::cin >> type;
            if (std::cin.fail() || (type != 1 && type != 2)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid type. Please enter 1 for Animal or 2 for Digimon.\n";
                continue;
            }
            database->Display(static_cast<Base::eType>(type - 1));
            break;
        }
        case 5: {
            std::string name;
            std::cout << "Enter name to remove: ";
            std::cin >> name;
            database->Remove(name);
            break;
        }
        case 6: {
            std::cout << "1) Animal\n"
                "2) Digimon\n"
                "Enter type to remove: ";
            int type;
            std::cin >> type;
            if (std::cin.fail() || (type != 1 && type != 2)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid type. Please enter 1 for Animal or 2 for Digimon.\n";
                continue;
            }
            database->Remove(static_cast<Base::eType>(type - 1));
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            database->Save(filename);
            break;
        }
        case 8: {
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            database->Load(filename);
            break;
        }
        case 9:
            quit = true;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
            break;
        }
    }
    delete database;
    _CrtDumpMemoryLeaks();
    return 0;
}

