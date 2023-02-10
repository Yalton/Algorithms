#include <iostream>
#include <vector>
#include <string>

using namespace std;

// A struct to represent an entry in the hashmap
struct Entry
{
    string key;
    string value;
};

// A class to represent a hashmap
class HashMap
{
public:
    HashMap(int numBuckets);
    void put(string key, string value);
    string get(string key);
    void remove(string key);

private:
    int numBuckets;
    vector<vector<Entry>> buckets;
};

HashMap::HashMap(int numBuckets)
{
    this->numBuckets = numBuckets;
    this->buckets.resize(numBuckets);
}

void HashMap::put(string key, string value)
{
    // YOUR CODE HERE
}

string HashMap::get(string key)
{
    // YOUR CODE HERE
}

void HashMap::remove(string key)
{
    // YOUR CODE HERE
}

int main()
{
    HashMap hashmap(10);

    hashmap.put("key1", "value1");
    hashmap.put("key2", "value2");
    hashmap.put("key3", "value3");

    cout << hashmap.get("key1") << endl;
    cout << hashmap.get("key2") << endl;
    cout << hashmap.get("key3") << endl;

    hashmap.remove("key2");

    cout << hashmap.get("key1") << endl;
    cout << hashmap.get("key2") << endl;
    cout << hashmap.get("key3") << endl;

    return 0;
}