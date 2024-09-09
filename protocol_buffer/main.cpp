#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
#include "read.h"

// This function fills in a Person message based on user input.
void PromptForAddress(tutorial::Person* person) {
    std::cout << "Enter person ID number: ";
    int id;
    std::cin >> id;
    person->set_id(id);
    std::cin.ignore(256, '\n');

    std::cout << "Enter your name: ";
    std::getline(std::cin, *person->mutable_name());

    std::cout << "Enter email address (blank for none): ";
    std::string email;
    std::getline(std::cin, email);
    if(!email.empty()) {
        person->set_email(email);
    }


    while(true) {
        std::cout << "Enter a phone number (or leave black to finish): ";
        std::string number;
        std::getline(std::cin, number);
        if(number.empty()) {
            break;
        }

        tutorial::Person::PhoneNumber* phone_number = person->add_phones();
        phone_number->set_number(number);

        std::cout << "Is this a mobile, home, or work phone? ";
        std::string type;
        std::getline(std::cin, type);
        if(type == "mobile") {
            phone_number->set_type(tutorial::Person::PHONE_TYPE_MOBILE);
        } else if(type == "home") {
            phone_number->set_type(tutorial::Person::PHONE_TYPE_HOME);
        } else if(type == "work") {
            phone_number->set_type(tutorial::Person::PHONE_TYPE_WORK);
        } else {
            std::cout << "Unknown phone type. Using default." << std::endl;
        }

    }
}


//  Main function:  Reads the entire address book from a file,
//  adds one person based on user input, then writes it back out to the same file.
int main(int argc, char** argv) {
    // verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <write || read>  <ADDRESS_BOOK_FILE>" << std::endl;
        return -1;
    }

    tutorial::AddressBook address_book;
    std::string argv_str = argv[1];
    {
        /// TODO: 파라미터 받아서 처리하는 부분이랑 같은 내용이라서 수정이 필요할 듯 하다.
        if(argv_str == "read") {
            std::cout << "yes 'read' selected.\n";
            // Read the existing address book. // 저장된 파일이 있다면 읽는다.
            std::fstream input(argv[2], std::ios::in | std::ios::binary);
            if (!address_book.ParseFromIstream(&input)) {
                std::cerr << "Failed to parse address book." << std::endl;
                return -1;
            }

            ListPeople(address_book);
        
        } else if(argv_str == "write") {
            std::cout << "yes 'write' selected.\n";
            // Read the existing address book.
            std::fstream input(argv[2], std::ios::in | std::ios::binary);
            if(!input) {
                std::cout << argv[2] << ": file not Found. Creating a new file." << std::endl;
            } else if(!address_book.ParseFromIstream(&input)) {
                std::cerr << "Failed to parse adderss book." << std::endl;
                return -1;
            }

            // ADD an address
            PromptForAddress(address_book.add_people());
            {
                // Write the new address book back to disk  // 2번째 파라미터로 온 파일명으로 build 디렉토리(현재 디렉토리)에 저장
                std::fstream output(argv[2], std::ios::out | std::ios::trunc | std::ios::binary);
                if(!address_book.SerializeToOstream(&output)) {
                    std::cerr << "Failed to write address book." << std::endl;
                    return -1;
                }
            }

        } else {
            std::cerr << "first parameter wrong: <write || read>\n";
            return -1;
        }
    }

    // optional Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}

/*
mkdir build
cd build
cmake ..
make

이후 build 디렉토리에서 실행파일 실행 및 파라미터 2번째 이름으로 생성된 파일을 쓰거나 읽을 수 있음.

예:
./protocol_buffer write addressbook
./protocol_buffer read addressbook
*/