/*************************************************************************
	> File Name: 2.groovy.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 04 Nov 2024 06:09:50 PM CST
 ************************************************************************/

//宇宙构造法：使用{}构造
//groovy方便构造具有树形结构逻辑的数据

#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Tag {
public:
    string name;
    string text;
    vector<Tag> child;
    vector<pair<string, string>> attribute; // 属性和属性值之间的映射
    friend ostream &operator<<(ostream &out, const Tag &obj) {
        out << "<" << obj.name << " ";
        for (auto attr : obj.attribute) {
            out << attr.first << "=" << "\"" << attr.second << "\" ";
        }
        out << ">";
        out << obj.text;
        for (auto ch : obj.child) {
            out << ch << endl;
        }
        out << "</" << obj.name << ">";
        return out;
    }
};

class P : public Tag {
public:
    explicit P(string text) : Tag{"p", text} {}
    P(initializer_list<Tag> child) : 
    Tag{"p", "", child} {}
};

class UL : public Tag {
public:
    UL(initializer_list<Tag> child) : 
    Tag{"ul", "", child} {}

};

class LI : public Tag {
public:
    explicit LI(string text) : Tag{"li", text} {}

};

class IMG : public Tag {
public:
    IMG(string url) : Tag{"img", ""} {
        attribute.push_back({"src", url});
    }
};

int main() {
    cout << 
    P {
        P{"hello world"},
        UL {
            LI("hello"),
            LI("world")
        },
        IMG {"./hug.jpg"}
    } << endl;


    return 0;
}
