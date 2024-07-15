// polymorphsim?
// 부모 및 상속 받은 클래스에서 각자의 기능을 수행할 수 있게 하는 것

#include <iostream>
#include <vector>

class Person {
public:
    Person() {
    }

    virtual void printInfo() {
        std::cout << "my_id: " << this->my_id << std::endl;
        std::cout << "my_name: " << this->my_name << std::endl;
    }

protected:
    int my_id = 10;
    std::string my_name = "Gunther";


};

class Student : public Person {
public:
    Student() {
    }

    void printInfo() override {
        std::cout << "my_id: " << my_id << std::endl;
        std::cout << "my_name: " << my_name << std::endl;
        std::cout << "class_name: " << this->class_name << std::endl;
    }

private:
    std::string class_name = "english";

};


int main() {
    std::vector<Person> people;
    Person person;
    Student student;

    people.push_back(person);
    people.push_back(student);

    // person.printInfo();
    // student.printInfo();
    for(Person person : people) {
        person.printInfo(); // 이렇게 해주면 Student 클래스의 calss_name을 제대로 출력하지 못함
    }

    std::vector<Person*> peoplePtr;
    peoplePtr.push_back(&person);
    peoplePtr.push_back(&student);

    std::cout << "==========================\n";
    // 단 여기에서 포인터로 만들어야지 제대로 작동한다.
    for(Person* person : peoplePtr) {
        person->printInfo();
    }
    // 부모 클래스의 type으로 다른 상속받은 클래스들의 각자 기능을 수행할 수 있게 된다. 
}