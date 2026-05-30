#include <string>
#include <iostream>
#include <forward_list>

class Observer {
public:
    Observer(std::string name): m_name(name) {
    }

    void OnNotify() {
        std::cout << " hello from " << m_name << std::endl;
    }

private:
    std::string m_name;
};

class Subject {
public:
    void AddObserver(Observer* observer) {
        m_observers.push_front(observer);
    }

    void RemoveObserver(Observer* observer) {
        m_observers.remove(observer);
    }

    void NotifyAll() {
        for(auto& o: m_observers) {
            o->OnNotify();
        }
    }

private:
    std::forward_list<Observer*> m_observers;
};


int main() {
    Subject subject;
    Observer ob1("observer1");
    Observer ob2("observer2");
    Observer ob3("observer3");

    subject.AddObserver(&ob1);
    subject.AddObserver(&ob2);
    subject.AddObserver(&ob3);

    subject.NotifyAll();

    ///
    std::cout << "---\n";
    subject.RemoveObserver(&ob1);
    subject.NotifyAll();

    return 0;
}

// g++ -std=c++17 -g -Wall observer.cpp -o observer
/// Observer 는 subscriber 이기도 하고 
/// Subject 는 publisher 로 불리기도 한다. 
/// Subject 1 - Many Observers 로 구성이 될 수가 있다. 

