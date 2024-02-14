#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace :: std;

void question1();
void question2();
void question3();
void question4();


int main() {
    question4();
    return 0;
}

void load(vector<int> &nums){
    ifstream fin("numbers.txt");
    if(fin){
        int num;
        while(!fin.eof()){
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
}
    else {
    cout << "Error loading" << endl;
    }
}

void load(list<int> &nums){
    ifstream fin("numbers.txt");
    if(fin){
        int num;
        while(!fin.eof()){
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
    } else {
        cout << "Error" << endl;
    }
}

void display(const vector<int> &numbers){
    for(int i = 0; i < numbers.size(); i++){
        if(i!=0){
            cout << ", ";

        }
        cout << numbers.at(i);
    }
}

void question1(){
    vector<int> nums;
    load(nums);
    display(nums);
//    ifstream fin("numbers.txt");
//    if(fin){
//        int num;
//        while(!fin.eof()){
//            fin >> num;
//            nums.push_back(num);
//        }

//        for(int i = 0; i < nums.size(); i++){
//            if(i!=0){
//                cout << ", ";
//                cout << nums.at(i);
//            }

            int key;
            cin >> key;
            bool found = false;
            for(int i=0; i< nums.size(); i++){
                if(nums[i] == key){
                    found = true;
                    cout << key << " found at position " << i;
                    break;
                }
            }
            if(!found){
                cout << key << " not found.";
        }
    }

void question2(){
    list<int> numbers;
    ifstream fin("numbers.txt");
    if(fin){
        int num;
        while(!fin.eof()){
            fin >> num;
            numbers.push_back(num);
        }
        cout << "[" ;
        for(auto iter = numbers.begin(); iter != numbers.end(); iter++){
            if(iter != numbers.begin()){
                cout << ", ";
            }
            cout << *iter;
            cout << "]";
            cout << "Enter a number to find" << endl;
            int key;
            bool found = false;
            cin >> key;
            int pos = 0;
            for(int i : numbers){
                if(i== key){
                    found = true;
                    cout << key << " found at position " << i << endl;
                }
                pos++;
            }
            if(!found){
                cout << key << " not found" << endl;
            }
        }
    }
    else{
        cout << "Error opening file" << endl;
    }
}
void question3(){
    vector<int> numbers;
    load(numbers);
    display(numbers);
    sort(numbers.begin(), numbers.end());
    cout << "\n";
    display(numbers);
    cout << "\n";
    auto func = [](int x, int y) {return x >y;};
    sort(numbers.begin(), numbers.end(), func);
    display(numbers);
}
void question4(){
    vector<string> words {"Hey", "Bomb", "Lentilka", "Money"};
    auto func = [](string s1, string s2){return s1.size() > s2.size();};
    for(int i = 0; i< words.size(); i++){
        if(i!=0){
            cout << ", ";
        }
        cout << words.at(i);
    }
    cout << endl;
    sort(words.begin(), words.end(), func);

    for(int i = 0; i< words.size(); i++){
        if(i!=0){
            cout << ", ";
        }
        cout << words.at(i);
    }

}
