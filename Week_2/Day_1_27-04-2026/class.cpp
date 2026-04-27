#include<iostream>
#include<list>
using namespace std;

class YouTubeChannel{
    public:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> VideoTitle;

        YouTubeChannel(string name, string ownerName){
            Name = name;
            OwnerName = ownerName;
            SubscribersCount = 0;
        }

        void GetInfo(){
            cout << "Name: " << Name << endl;
            cout << "OwnerName: " << OwnerName << endl;
            cout << "SubscribersCount: " << SubscribersCount << endl;
            cout << "Videos:" << endl;
            for(string videoTitle : VideoTitle){
                cout << videoTitle << endl;
            }
        }

};

int main(){
    YouTubeChannel ytChannel("IT TRAX","Sachin Mittal");
    ytChannel.VideoTitle.push_back("Kaise HO");
    ytChannel.VideoTitle.push_back("aaj nahi toh kab");
    ytChannel.VideoTitle.push_back("C++ Learning");

    ytChannel.GetInfo();

    int test;

    cout<< test;
    

    return 0;
}