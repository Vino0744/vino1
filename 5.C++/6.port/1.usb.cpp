/*************************************************************************
	> File Name: 1.usb.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 10:14:21 AM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

//定义接口
class USB_interface {
public:
    virtual string get() = 0;
    virtual void set(string) = 0;
};

class KeyBoard : public USB_interface {
public:
    string get() {
        return "this massage come from key board";
    }
    void set(string msg) {
        cout << "key board recevie msg : " << msg << endl;
        return ;
    }
};
class Mouse : public USB_interface {
public:
    string get() {
        return "this mouse dida dida di";
    }
    void set(string msg) {
        cout << "mouse recevie msg : " << msg << endl;
        return ;
    }
};

int main() {
    srand(time(0));
    USB_interface *usb[2];
    int ind = rand() % 2;
    usb[ind] = new KeyBoard();
    usb[1 - ind] = new Mouse();
    for (int i = 0; i < 2; i++) {
        cout << "USB #" << i << " : " << endl;
        cout << usb[i]->get() << endl;
        usb[i]->set("over done");
        cout << endl;
    }
    return 0;
}
