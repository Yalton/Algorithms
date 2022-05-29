#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// A struct to represent a preference list
struct PreferenceList
{
    vector<string> preferences;
};

// A struct to represent a person
struct Person
{
    string name;
    PreferenceList preferenceList;
};

// A struct to represent a pairing
struct Pairing
{
    Person person1;
    Person person2;
};

// A struct to represent a stable matching
struct StableMatching
{
    vector<Pairing> pairings;
};

// Checks if a given matching is stable
bool isStable(vector<Person> persons, StableMatching matching)
{
    // YOUR CODE HERE
}

// Finds a stable matching using the Gale-Shapley algorithm
StableMatching galeShapley(vector<Person> persons)
{
    // YOUR CODE HERE
}

int main()
{
    // Read in the data
    int numPersons;
    cin >> numPersons;

    vector<Person> persons;
    for (int i = 0; i < numPersons; i++)
    {
        Person person;
        cin >> person.name;

        int numPreferences;
        cin >> numPreferences;

        for (int j = 0; j < numPreferences; j++)
        {
            string preference;
            cin >> preference;
            person.preferenceList.preferences.push_back(preference);
        }

        persons.push_back(person);
    }

    // Find the stable matching
    StableMatching matching = galeShapley(persons);

    // Print the matching
    for (Pairing pairing : matching.pairings)
    {
        cout << pairing.person1.name << " " << pairing.person2.name << endl;
    }

    return 0;
}