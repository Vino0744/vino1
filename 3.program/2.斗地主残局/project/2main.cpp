/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 08:42:21 AM CST
 ************************************************************************/

#include "pai.h"

void usage(int max_num) {
    if (max_num >= 1) printf("1 : DAN\n");
    if (max_num >= 2) printf("2 : DUIZI\n");
    if (max_num >= 3) printf("3 : SHUNZI\n");
    if (max_num >= 4) printf("4 : SANDAI\n");
    if (max_num >= 5) printf("5 : ZHADAN\n");
    if (max_num >= 6) printf("6 : WANGZHA\n");
    if (max_num >= 7) printf("7 : PASS\n");
    printf("input : ");
    return ;
}

PAI *read_pai(int max_num) {
    PAI *ret;
    int choice, x, y;
    while (1) {
        usage(max_num);
        cin >> choice;
        switch(choice) {
            case 1: {
                cin >> x;
                ret = new DAN(x);
            } break;
            case 2: {
                cin >> x;
                ret = new DUIZI(x);
            } break;
            case 3: {
                cin >> x >> y;
                ret = new SHUNZI(x, y);
            } break;
            case 4: {
                cin >> x;
                PAI *dai = read_pai(2);
                ret = new SANDAI(x, dai);
            } break;
            case 5: {
                cin >> x;
                ret = new ZHADAN(x);
            } break;
            case 6: {
                ret = new WANGZHA();
            } break;
            case 7: {
                ret = new PASS();
            }
        }
        break;
    }
    return ret;
}

int main() {
    #define MAX_N 18
    int arr[MAX_N + 5] = {0};
    int x;
    while (cin >> x) {
        if (x == 0) break;
        arr[x] += 1;
    }
    PAI *pai = read_pai(7);
    pai->output << endl;
    cout << "==========" << endl;
    vector<PAI *> temp = PAI::getLegalPai(arr, pai);
    for (auto x : temp) x->output() << endl;
    return 0;
}
