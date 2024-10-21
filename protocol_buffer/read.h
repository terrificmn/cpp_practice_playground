#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"

// iterates though all people in the AddressBook and prints info about them
void ListPeople(const tutorial::AddressBook& address_book) {
    for(int i=0; i< address_book.people_size(); ++i) {
        const tutorial::Person& person = address_book.people(i);

        std::cout << "Person ID: " << person.id() << std::endl;
        std::cout << " Name: " << person.name() << std::endl;

        //proto 2에서는 has_...()에 해당하는게 optional 이였던거 같은데 proto3는 연구해봐야겠음.  has_..()없음
        // if(person.has_email())
        std::cout << "email address: " << person.email() << std::endl;
    
        for(int j= 0; j < person.phones_size(); j++) {
            const tutorial::Person::PhoneNumber& phone_number = person.phones(j);
            
            // repeated로 처리된 배열은 phones(i)로 받아온 후 . 이하 계속 접근이 가능
            // 예 phone_number.type(), phone_number.number()
            switch(phone_number.type()) {
                case tutorial::Person::PHONE_TYPE_MOBILE:
                    std::cout << " Mobile phone #: ";
                    break;

                case tutorial::Person::PHONE_TYPE_HOME:
                    std::cout << " Home phone #: ";
                    break;

                case tutorial::Person::PHONE_TYPE_WORK:
                    std::cout << " Work phone #: ";
                    break;
                
                default:
                    break;
            }
            std::cout << phone_number.number() << std::endl;
        }
    }
}
