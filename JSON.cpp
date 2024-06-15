#include <string>
#include <list>
#include <stdbool.h>
#include <iterator>

#define JSON_CPP

// A JSON key value pair
class JSONKeyValuePair {
public:
    JSONKeyValuePair(std::string key, void *value = NULL) {
        if(key.empty()) {
            // std::cout << "[JSON.cpp - class JSONKeyValuePair - constructor()]: ERROR! Key cannot be an empty String!" << std::endl;
            delete this;
            return;
        }
        _key.append(key);
        _value = value;
    }
    // get the value
    void *value() {
        return _value;
    }
    // get the key
    std::string key() {
        return _key;
    }
    // returns the new value
    // This will NOT delete/free the memory of the old value ofc
    void *setValue(void *newValue) {
        _value = newValue;
        return newValue;
    }

private:
    std::string _key = "";
    void *_value = NULL;
};

class JSONObject {
public:
    int addKeyValuePair(JSONKeyValuePair *pair) {
        if(pair == NULL) {
            // std::cout << "[JSON.cpp - class JSONObject - addKeyValuePair()]: ERROR! KeyValuePair cannot be NULL!" << std::endl;
            return -1;
        }
        if(keyExists((*pair).key())) {
            // std::cout << "[JSON.cpp - class JSONObject - addKeyValuePair()]: ERROR! KeyValuePair already exists!" << std::endl;
            return -2;
        }
        _keyValuePairs.push_back(pair);
        return 0;
    }
    bool keyExists(std::string key) {
        std::list<JSONKeyValuePair*>::iterator it;
        for (it = _keyValuePairs.begin(); it != _keyValuePairs.end(); ++it) {
            if((*it)->key() == key) {
                return true;
            }
        }
        return false;
    }
    int removeKeyValuePair(std::string key) {
        std::list<JSONKeyValuePair*>::iterator it;
        for (it = _keyValuePairs.begin(); it != _keyValuePairs.end(); ++it) {
            if((*it)->key() == key) {
                _keyValuePairs.erase(it);
                return 0;
            }
        }
        return 1;
    }
    JSONKeyValuePair *getKeyValuePair(std::string key) {
        if(!keyExists(key)) {
            return NULL;
        }
        std::list<JSONKeyValuePair*>::iterator it;
        for (it = _keyValuePairs.begin(); it != _keyValuePairs.end(); ++it) {
            if((*it)->key() == key) {
                return (*it);
            }
        }
        return NULL;
    }
private:
    std::list<JSONKeyValuePair*> _keyValuePairs{};
};