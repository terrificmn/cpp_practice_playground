
Document로 먼저 json을 받은 후에 
아마도 Document["body"] 이렇게 생긴 놈이 rapidjson::Value 였던거 같음;; 확실하지는 않음


키만 필요할 경우 아래처럼 추춯할 수 있다. 
void extractKeyFromUnMap(rapidjson::Value* rapid_value_ptr, std::string key) {
    // key를 받아서 rapid Value에서 뽑을 수 있다.

    std::vector<std::string> v_key_names;

    for(rapidjson::Value::ConstMemberIterator itr = rapid_value_ptr->MemberBegin(); itr != rapid_value_ptr->MemberEnd(); ++itr) {
        v_key_names.push_back(itr->name.GetString());
    }
    //이렇게 하면 키 만 벡터로 만들 수 있다. (key의 스트링)
}

