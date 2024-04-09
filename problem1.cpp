#include <iostream>
#include <string>

const int MAX_STUDENTS = 3;
enum ContestResult
{
    WIN,
    LOSE,
    TIE
};

// The Student class has the following common attributes:
// - name: string
// - social: int (default: 0)
// - energy: int (default: 100)
// However, each student has different attributes according to their type. This is called 'special attribute'
//   Scientist - knowledge: int (default: 0, can be negative)
//   Athlete - health: int (default: 0, can be negative)
//   Artist - creativity: int (default: 0, can be negative)
// These attributes are only accessible by the derived classes and itself.
// They are not accessible by any other function outside the class.
// Implement the getters if needed!
class Student
{
public:
    Student(std::string name)
    {
        this->name = name;
        this->social = 0;
        this->energy = 100;
        this->knowledge = 0;
        this->health = 0;
        this->creativity = 0;
    }
    virtual ~Student() {}

    void rest()
    {
        // 1. Resting increases energy by 50
        // 2. Display the status of the student
        this->energy += 50;
        showStatus();
    }

    void meetFriends()
    {
        // 1. If energy is greater than or equal to 15, increase social by 20 and decrease energy by 15
        // 2. If energy is less than 15, display a message "${StudentName} is too tired to meet friends."
        // 3. Display the status of the student
        // *There is no case of overflow
        if (this->energy >= 15)
        {
            this->social += 20;
            this->energy -= 15;
        }
        else
        {
            std::cout << this->name << " is too tired to meet friends." << std::endl;
        }
        showStatus();
    }

    // There are three types of students: Scientist, Athlete, and Artist
    // Each student has different activities to do and different effects on their stats
    // Override this method in the derived classes
    // Scientist: Study
    //  - If energy is greater than or equal to 15, incerase knowledge by 20 and decrease energy by 15
    //  - If energy is less than 15, display a message "${StudentName} is too tired to study."
    //  - Display the status of the student
    // Athlete: Exercise
    //  - If energy is greater than or equal to 15, increase health by 20 and decrease energy by 15
    //  - If energy is less than 15, display a message "${StudentName} is too tired to exercise."
    //  - Display the status of the student
    // Artist: Work on art
    //  - If energy is greater than or equal to 15, increase creativity by 20 and decrease energy by 15
    //  - If energy is less than 15, display a message "${StudentName} is too tired to work on art."
    //  - Display the status of the student
    // *There is no case of overflow
    virtual void doActivity()
    {
        if (this->type == "Scientist")
        {
            if (this->energy >= 15)
            {
                this->knowledge += 20;
                this->energy -= 15;
            }
            else
            {
                std::cout << this->name << " is too tired to study." << std::endl;
            }
            showStatus();
        }
        else if (this->type == "Athlete")
        {
            if (this->energy >= 15)
            {
                this->health += 20;
                this->energy -= 15;
            }
            else
            {
                std::cout << this->name << " is too tired to exercise." << std::endl;
            }
            showStatus();
        }
        else if (this->type == "Artist")
        {
            if (this->energy >= 15)
            {
                this->creativity += 20;
                this->energy -= 15;
            }
            else
            {
                std::cout << this->name << " is too tired to work on art." << std::endl;
            }
            showStatus();
        }
    };

    // Return the sum of the special attribute and social and energy
    virtual int getStats()
    {
        if (this->type == "Scientist")
        {
            return this->knowledge + this->social + this->energy;
        }
        else if (this->type == "Athlete")
        {
            return this->health + this->social + this->energy;
        }
        else if (this->type == "Artist")
        {
            return this->creativity + this->social + this->energy;
        }
        else
        {
            return 0;
        }
    };

    // 1. If the result is WIN, increase special attribute by 10
    // 2. If the result is LOSE, decrease energy by 15
    // 3. If the result is TIE, decrease energy by 10
    // 4. Display the status of the student
    // *There is no case of overflow/underflow
    virtual void updateAfterContest(ContestResult result)
    {
        if (result == WIN)
        {
            if (this->type == "Scientist")
            {
                this->knowledge += 10;
            }
            else if (this->type == "Athlete")
            {
                this->health += 10;
            }
            else if (this->type == "Artist")
            {
                this->creativity += 10;
            }
        }
        else if (result == LOSE)
        {
            this->energy -= 15;
        }
        else if (result == TIE)
        {
            this->energy -= 10;
        }
        showStatus();
    };

    // Display the status of the student
    // For example, if the name is "John" and its type is Scientist, with knowledge: 0, social: 0, energy: 0,
    // print "Status of John: Knowledge: 0, Social: 0, Energy: 0"
    virtual void showStatus()
    {
        if (this->type == "Scientist")
        {
            std::cout << "Status of " << this->name << ": Knowledge: " << this->knowledge << ", Social: " << this->social << ", Energy: " << this->energy << std::endl;
        }
        else if (this->type == "Athlete")
        {
            std::cout << "Status of " << this->name << ": Health: " << this->health << ", Social: " << this->social << ", Energy: " << this->energy << std::endl;
        }
        else if (this->type == "Artist")
        {
            std::cout << "Status of " << this->name << ": Creativity: " << this->creativity << ", Social: " << this->social << ", Energy: " << this->energy << std::endl;
        }
    };

    // Getters
    std::string getName()
    {
        return this->name;
    };

    std::string getType()
    {
        return this->type;
    }

    int getSocial()
    {
        return this->social;
    };

    int getEnergy()
    {
        return this->energy;
    };

    // Setters
    void setSocial(int social)
    {
        this->social = social;
    };

    void setEnergy(int energy)
    {
        this->energy = energy;
    };

    void setType(std::string type)
    {
        this->type = type;
    }

private:
    std::string name;
    std::string type;
    int social;
    int energy;

    // special attribute
    int knowledge;
    int health;
    int creativity;
};

class Game
{
private:
    Student *students[MAX_STUDENTS];
    int studentCount;
    std::string input;

public:
    Game()
    {
        studentCount = 0;
    }
    ~Game()
    {
    }

    Student *getStudent(std::string name)
    {
        // Return the student whose name is {name}
        // *There is no case where two students have the same name
        // *There is no case where the student with the given name does not exist

        for (int i = 0; i < studentCount; i++)
        {
            if (students[i]->getName() == name)
            {
                return students[i];
            }
        }

        return nullptr;
    }

    void trainStudent()
    {
        // 1. Ask the user to enter the student name
        // 2. Display the training menu and ask user to choose an activity
        // 3. Process the chosen activity (refer to example text file)
        // 4. Repeat until the user chooses to exit(5)
        // *There is no case where the student with the given name does not exist
        // *There is no case where the user enters an invalid choice

        std::cout << "Enter student name: ";
        getline(std::cin, input);
        std::string name = input;
        Student *student = getStudent(name);

        trainStudentWithObj(student);
    }

    void trainStudentWithObj(Student *student)
    {

        std::cout << "--- Training Menu ---" << std::endl;
        std::cout << "1. Do Activity" << std::endl;
        std::cout << "2. Meet Friends" << std::endl;
        std::cout << "3. Rest" << std::endl;
        std::cout << "4. Show Status" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        getline(std::cin, input);
        int choice = std::stoi(input);
        std::cout << "----------------------" << std::endl;

        if (choice == 1)
        {
            student->doActivity();
        }
        else if (choice == 2)
        {
            student->meetFriends();
        }
        else if (choice == 3)
        {
            student->rest();
        }
        else if (choice == 4)
        {
            student->showStatus();
        }
        else if (choice == 5)
        {
            this->run();
        }

        if (choice != 5)
        {
            this->trainStudentWithObj(student);
        }
    }

    void addStudent()
    {
        // 1. Ask the user to enter the student type and name
        // 2. Create a new student object according to the given type and add it to the students array
        // *There is no case where the user enters an invalid student type or the name of an existing student
        // *There is no case where the student count exceeds MAX_STUDENTS
        std::cout << "Enter student type (Scientist, Athlete, Artist): ";
        getline(std::cin, input);
        std::string type = input;
        std::cout << "Enter student name: ";
        getline(std::cin, input);
        std::string name = input;

        students[studentCount] = new Student(name);
        students[studentCount]->setType(type);
        studentCount++;

        this->run();
    }

    void contestStudents()
    {
        // 1. Ask the user to enter the names of two students
        // 2. If the energy of any student is less than 15, display a message "${StudentName} is too tired to contest."
        // 3. Contest the two students
        //  - The student with higher stats wins
        //  - If the stats are equal, it's a tie
        //  - Display the result
        //    - If it is not a tie, display "${StudentName} wins!"
        //    - If it is a tie, display "It's a tie!"
        // 4. Update the stats of the students according to the result
        // *There is no case where the user enters the name of a non-existing student or the same name for both student
        std::cout << "Enter first student name for the contest: ";
        getline(std::cin, input);
        std::string name1 = input;
        std::cout << "Enter second student name for the contest: ";
        getline(std::cin, input);
        std::string name2 = input;

        Student *student1 = getStudent(name1);
        Student *student2 = getStudent(name2);

        if (student1->getEnergy() < 15)
        {
            std::cout << student1->getName() << " is too tired to contest." << std::endl;
        }
        if (student2->getEnergy() < 15)
        {
            std::cout << student2->getName() << " is too tired to contest." << std::endl;
        }

        std::cout << "Contesting " << student1->getName() << " vs. " << student2->getName() << std::endl;

        if (student1->getStats() > student2->getStats())
        {
            std::cout << student1->getName() << " wins!" << std::endl;
            student1->updateAfterContest(WIN);
            student2->updateAfterContest(LOSE);
        }
        else if (student1->getStats() < student2->getStats())
        {
            std::cout << student2->getName() << " wins!" << std::endl;
            student1->updateAfterContest(LOSE);
            student2->updateAfterContest(WIN);
        }
        else
        {
            std::cout << "It's a tie!" << std::endl;
            student1->updateAfterContest(TIE);
            student2->updateAfterContest(TIE);
        }

        this->run();
    }

    void showStatus()
    {
        // Display the status of all students
        for (int i = 0; i < studentCount; i++)
        {
            students[i]->showStatus();
        }

        this->run();
    }

    void run()
    {
        // 1. Display the main menu and ask user to choose an activity
        // 2. Process the chosen activity (refer to example text file)
        // 3. Repeat until the user chooses to exit(5)
        std::cout << "--- Main Menu ---" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Train Student" << std::endl;
        std::cout << "3. Contest Students" << std::endl;
        std::cout << "4. Students Status" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        getline(std::cin, input);
        std::cout << "----------------------" << std::endl;

        if (input == "1")
        {
            addStudent();
        }
        else if (input == "2")
        {
            trainStudent();
        }
        else if (input == "3")
        {
            contestStudents();
        }
        else if (input == "4")
        {
            showStatus();
        }
        else if (input == "5")
        {
            return;
        }
        else
        {
            return;
        }
    }
};

int main()
{
    // Good Luck! :)
    Game game;
    game.run();
    return 0;
}