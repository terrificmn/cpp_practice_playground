#include <iostream>
#include <memory>

struct Status {
    int backup_status = 0;
    int current_status = 0;
};

int main() {

    std::shared_ptr<Status> ptrStatus = std::make_shared<Status>();

    /// 1. status 변경
    ptrStatus->current_status = 1;
    std::cout << "1. current status: " << ptrStatus->current_status << std::endl;
    std::cout << "1. backup_status: " << ptrStatus->backup_status << std::endl;
    std::cout << "use count :" << ptrStatus.use_count() << std::endl;

    /// 2. 다른 곳에서 만들고 backup 만 변경 후 출력
    {
        std::cout << std::endl;
        /// IMPORTANT: prtStatus2 를 prtStatus 로 쉐어? 해준다. 
        std::shared_ptr<Status> ptrStatus2 = std::make_shared<Status>();
        ptrStatus2 = ptrStatus;

        ptrStatus2->backup_status = 10;
        /// current 는 변경 안했지만 잘 연동이 된다.
        std::cout << "2. current status: " << ptrStatus2->current_status << std::endl;
        std::cout << "2. current backup_status: " << ptrStatus2->backup_status << std::endl;
        std::cout << "2 use count :" << ptrStatus2.use_count() << std::endl;

        ///// IMPORTANT: 작업이 끝나면 다시 원래 쓰려고 하는 원 데이터인 ptrStatus 에 다시 넘겨준다.
        ptrStatus = ptrStatus2;

    }
    
    //// 이런식으로 하는 것이 shared ptr 를 사용하는 방법 중에는 하나 인 듯 하다. 서로 주고 받지 않으면 데이터는 게속 업데이트 되지 않고 따로따로 놀게(?) 된다.
    /// 문론 그냥 하나 만들고 그냥 그 데이터만 집어서 예를 들어 ptrStatus->current_status 만 바꿔준거나 이런식으로 하는게 더 나을 듯 도 하지만
    /// 흠.. 데이터 자체를 만들고 서로 주고 받고 하면서 데이터가 공유되는 것을 해보고 싶었다. 

    /// 3. 공유했을 경우 결과
    std::cout << std::endl;
    std::cout << "1. current status: " << ptrStatus->current_status << std::endl;
    std::cout << "1. current backup_status: " << ptrStatus->backup_status << std::endl;
    std::cout << "1 use count :" << ptrStatus.use_count() << std::endl;


    return 0;
}


// g++ -std=c++17 -o shared_ptr_test shared_ptr_test.cpp 