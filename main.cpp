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
void question6();
void question7();


int main() {
    question7();
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
void print(string &s,const vector<string> &strs){
    cout << s << "[" ;
    for(auto iter = strs.begin(); iter != strs.end(); iter ++){
        if(iter != strs.begin()){
            cout << ", ";
        }
        cout << *iter;
    }
    cout << "]" << endl;
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
void question6(){
    vector<string> strs {"apple", "orange"};
    auto func = [](string s1, string s2){
        if(s1.size() == s2.size()){
            return s1 >s2;
        }
        return s1.size() < s2.size();
    };
    sort(strs.begin(), strs.end(), func);
    string s = "My strings";
    print(s, strs);
}
void question7(){
    vector<string> mths{"Jan", "Apr", "May", "Sept", "Nov", "Dec"};
    vector<string>::iterator iter = mths.begin();
    iter++;
    iter = mths.insert(iter, "Mar");
    iter = mths.insert(iter, "Feb");
    iter +=4;
    iter = mths.insert(iter, "Aug");
    iter = mths.insert(iter, "July");
    iter = mths.insert(iter, "June");
    iter+=4;
    iter = mths.insert(iter, "Oct");
    string s = "Months";
    print(s, mths);
}

int areSameUntil(const vector<int> &vec1,  const vector<int> &vec2){
    int pos = 0;
    int min = vec1.size()<vec2.size()?vec1.size():vec2.size();
    for(int i = 0; i< min; i++){
        if(vec1[i] != vec2[i]){
            return i-1;
        }
    }
    return min-1;
}