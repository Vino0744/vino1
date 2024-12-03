/*************************************************************************
	> File Name: 1.output_html.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Nov 2024 03:12:54 PM CST
 ************************************************************************/

#include<iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class HtmlBuilder;
class HtmlElemnent;

class HtmlElemnent {
public:
    static HtmlBuilder *build(string);
private:
    typedef HtmlElemnent Self;
    HtmlElemnent(string name, string text) : name(name), text(text) {}
    string name, text;
    vector<HtmlElemnent> child;
    friend ostream &operator<<(ostream &out, const Self &obj) {
        out << "<" << obj.name << ">";
        out << obj.text;
        for (auto o : obj.child) {
            out << o;
        }
        cout << "</" << obj.name << ">" << endl;
        return out;
    }
    friend class HtmlBuilder;
};

class HtmlBuilder {
    typedef HtmlBuilder Self;
private:
    HtmlElemnent root;
public:
    HtmlBuilder(string root_name) : root(root_name, "") {}
    operator HtmlElemnent() { return root; }
    HtmlBuilder add_child(string name, string text) {
        root.child.push_back({name, text});
        return *this;
    }
    friend ostream &operator<<(ostream &out, const HtmlBuilder &obj) {
        out << obj.root;
        return out;
    }
};

HtmlBuilder *HtmlElemnent::build(string name) {
    return new HtmlBuilder(name);
}

int main() {
    // HtmlBuilder *h = HtmlElemnent::build("ul");
    HtmlElemnent e = HtmlElemnent::build("ul")
        ->add_child("li", "hello")
        .add_child("li", "world");
    cout << e << endl;

    return 0;
}
