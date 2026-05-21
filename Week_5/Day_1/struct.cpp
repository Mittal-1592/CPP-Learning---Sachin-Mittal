#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    struct Student{
        string name;
        int points;
    };

    std::array<Student, 8> arr{
        { { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 }, // Dan has the most points (8).
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 } }
        };

    auto maxMin = [](Student s1, Student s2){
        return s1.points < s2.points;
    };
    auto best = max_element(arr.begin(),arr.end(),maxMin);
    cout << best->name;

    for (auto i : arr){
        cout << i.name << "  " << i.points << endl;
    }
    return 0;
}