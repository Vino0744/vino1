/*************************************************************************
	> File Name: pai.cc
	> Author: 
	> Mail: 
	> Created Time: Wed 22 May 2024 02:51:04 PM CST
 ************************************************************************/

#include "pai.h"

#define MAX_N 18

//static全局数组使得只有源文件可以访问到当前数组
static string name[MAX_N + 5] = {
    "", "", "", "3", "4", "5", "6", "7", "8", "9", "10", 
    "J", "Q", "K", "Ace", "2", "joker", "JOKER"
}; 

PAI::PAI(PAI_TYPE type) : type(type) {}
PASS::PASS() : PAI(PAI_TYPE::PASS_TYPE) {}

ostream &PASS::output() {
    return cout << "PASS";
}
void PASS::take(int *arr) { return ; }
void PASS::back(int *arr) { return ; }
vector<PAI *> PASS::get(int *arr) {
    vector<PAI *> ret;
    ret.push_back(new PASS());
    return ret;
}
bool PASS::operator>(PAI *pre) {
    return pre->type != PAI_TYPE::PASS_TYPE;
}

DAN::DAN(int x) : PAI(PAI_TYPE::DAN_TYPE), x(x) {}
ostream &DAN::output() {
    cout << "DAN : " << name[x];
    return cout;
}
void DAN::take(int *arr) { arr[x] -= 1; }
void DAN::back(int *arr) { arr[x] += 1; }
vector<PAI *> DAN::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i] == 0) continue;
        ret.push_back(new DAN(i));
    }
    return ret;
}
bool DAN::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::DAN_TYPE : {
            DAN *pre_ = dynamic_cast<DAN *>(pre);
            return this->x > pre_->x;
        } break;
        default : return false;
    }
    return false;
}

DUIZI::DUIZI(int x) : PAI(PAI_TYPE::DUIZI_TYPE), x(x) {}
ostream &DUIZI::output() {
    cout << "DUIZI : " << name[x];
    return cout;
}
void DUIZI::take(int *arr) { arr[x] -= 2; }
void DUIZI::back(int *arr) { arr[x] += 2; }
vector<PAI *> DUIZI::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i] <= 1) continue;
        ret.push_back(new DUIZI(i));
    }
    return ret;
}
bool DUIZI::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::DUIZI_TYPE : {
            DUIZI *pre_ = dynamic_cast<DUIZI *>(pre);
            return this->x > pre_->x;
        } break;
        default : return false;
    }
    return false;
}

SHUNZI::SHUNZI(int start, int end) : PAI(PAI_TYPE::SHUNZI_TYPE), start(start), end(end) {}
ostream &SHUNZI::output() {
    cout << "SHUNZI : ";
    for (int i = start; i <= end; i++) cout << name[i] << " ";
    return cout;
}
void SHUNZI::take(int *arr) {
    for (int i = start; i <= end; i++) arr[i] -= 1;
}
void SHUNZI::back(int *arr) {  
    for (int i = start; i <= end; i++) arr[i] += 1;
}
vector<PAI *> SHUNZI::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i <= 10; i++) {
        if (arr[i] == 0) continue;
        int cnt = 1;
        for (int j = i + 1; j <= 14; j++) {
            if (arr[j] == 0) break;
            cnt += 1;
            if (cnt >= 5) ret.push_back(new SHUNZI(i, j));
        }
    }
    return ret;
}
bool SHUNZI::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::SHUNZI_TYPE : {
            SHUNZI *pre_ = dynamic_cast<SHUNZI *>(pre);
            return (this->end - this->start == pre_->end - pre_->start) && (this->start > pre_->start);
        } break;
        default : return false;
    }
    return false;
}


LIANDUI::LIANDUI(int start, int end) : PAI(PAI_TYPE::LIANDUI_TYPE), start(start), end(end) {}
ostream &LIANDUI::output() {
    cout << "LIANDUI : ";
    for (int i = start; i <= end; i++) cout << name[i] << " ";
    return cout;
}
bool LIANDUI::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::PASS_TYPE: return true;
        case PAI_TYPE::LIANDUI_TYPE: {
            LIANDUI *pre_ = dynamic_cast<LIANDUI *>(pre);
            if (pre_->end - pre_->start != this->end - this->start) return false;
            return (this->start > pre_->start);
        } break;
        default: return false;
    }
    return false;
}
void LIANDUI::take(int *arr) {
    for (int i = start; i <= end; i++) arr[i] -= 2;
    return ;
}
void LIANDUI::back(int *arr) {
    for (int i = start; i <= end; i++) arr[i] += 2;
    return ;
}
vector<PAI *> LIANDUI::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i <= 12; i++) {
        if (arr[i] < 2) continue;
        int cnt = 1;
        for (int j = i + 1; j <= 14; j++) {
            if (arr[j] < 2) break;
            cnt += 1;
            if (cnt >= 3) ret.push_back(new LIANDUI(i, j));
        }
    }
    return ret;
}

SANDAI::SANDAI(int san, PAI *dai) : PAI(PAI_TYPE::SANDAI_TYPE), san(san), dai(dai){}
ostream &SANDAI::output() {
    cout << "SANDAI : SAN " << name[san] << " DAI ";
    dai->output();
    return cout;
}
void SANDAI::take(int *arr) {
    arr[san] -= 3;
    dai->take(arr);
    return ;
}
void SANDAI::back(int *arr) {  
    arr[san] += 3;
    dai->back(arr);
    return ;
}
vector<PAI *> SANDAI::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i <= 15; i++) {
        if (arr[i] < 3) continue;
        ret.push_back(new SANDAI(i, new PASS()));
        for (int j = 3; j < MAX_N; j++) {
            if (arr[j] == 0 || j == i) continue;
            if (arr[j] == 1) {
                ret.push_back(new SANDAI(i, new DAN(j)));
            } else {
                ret.push_back(new SANDAI(i, new DAN(j)));
                ret.push_back(new SANDAI(i, new DUIZI(j)));
            }
        }
    }
    return ret;
}
bool SANDAI::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::SANDAI_TYPE : {
            SANDAI *pre_ = dynamic_cast<SANDAI *>(pre);
            if (pre_->dai->type != this->dai->type) return false;
            return this->san > pre_->san;
        } break;
        default : return false;
    }
    return false;
}

/*************
FEIJI::FEIJI(vector<PAI *> feiji) : PAI(PAI_TYPE::FEIJI_TYPE), feiji(feiji) {}
ostream &FEIJI::output() {
    cout << "FEIJI : ";
    for (auto x : feiji) cout << x->output();
    return cout;
}
bool FEIJI::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::PASS_TYPE: return true;
        case PAI_TYPE::FEIJI_TYPE: {
            FEIJI *pre_ = dynamic_cast<FEIJI *>(pre);
            if (pre_->feiji.size != this->feiji.size()) return false;
            return this->feiji[0]->operator>(pre_);
        } break;
        default: return false;
    }
    return false;
}
void FEIJI::take(int *arr) {
    for (auto x : feiji) {
        x->take(arr);
    }
    return ;
}
void FEIJI::back(int *arr) {
    for (auto x : feiji) {
        x->back(arr);
    }
    return ;
}
vector<PAI *> FEIJI::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i <= 14; i++) {
        if (arr[i] < 3) continue;
        int flag = 0;
        vector<PAI *> feiji;
         
    }
}
********************/

SIDAI::SIDAI(int si, PAI *dai1, PAI *dai2) : PAI(PAI_TYPE::SIDAI_TYPE), si(si), dai1(dai1), dai2(dai2) {}
ostream &SIDAI::output() {
    cout << "SIDAI : SI " << si << " DAI ";
    dai1->output();
    dai2->output();
    return cout;
}
bool SIDAI::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::PASS_TYPE : return true;
        case PAI_TYPE::SIDAI_TYPE: {
            SIDAI *pre_ = dynamic_cast<SIDAI *>(pre);
            if (pre_->dai1->type != this->dai1->type) return false;
            return this->si > pre_->si;
        } break;
        default: return false;
    }
    return false;
}
void SIDAI::take(int *arr) {
    arr[si] -= 4;
    dai1->take(arr);
    dai2->take(arr);
    return ;
}
void SIDAI::back(int *arr) {
    arr[si] += 4;
    dai1->back(arr);
    dai2->back(arr);
    return ;
}
vector<PAI *> SIDAI::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i <= 15; i++) {
        if (arr[i] < 4) continue;
        ret.push_back(new SIDAI(i, new PASS(), new PASS()));
        for (int j = 3; j <= 15; j++) {
            if (arr[j] < 2 || j == i) continue;
            for (int k = j + 1; k <= 15; k++) {
                if (arr[k] < 2) continue;
                ret.push_back(new SIDAI(i, new DUIZI(j), new DUIZI(k)));
            }
        }
        for (int j = 3; j < MAX_N; j++) {
            if (arr[j] < 1 || j == i) continue;
            if (arr[j] >= 2) ret.push_back(new SIDAI(i, new DAN(j), new DAN(j)));
            for (int k = j + 1; k < MAX_N; k++) {
                if (arr[k] < 1) continue;
                ret.push_back(new SIDAI(i, new DAN(j), new DAN(k)));
            }
        }
    }
    return ret;
}

ZHADAN::ZHADAN(int x) : PAI(PAI_TYPE::ZHADAN_TYPE), x(x) {}
ostream &ZHADAN::output() {
    cout << "ZHADAN : " << name[x];
    return cout;
}
void ZHADAN::take(int *arr) {
    arr[x] -= 4;
    return ;
}
void ZHADAN::back(int *arr) {  
    arr[x] += 4;
    return ;
}
vector<PAI *> ZHADAN::get(int *arr) {
    vector<PAI *> ret;
    for (int i = 3; i <= 15; i++) {
        if (arr[i] == 4) ret.push_back(new ZHADAN(i));
    }
    return ret;
}
bool ZHADAN::operator>(PAI *pre) {
    switch(pre->type) {
        case PAI_TYPE::WANGZHA_TYPE: return false;
        case PAI_TYPE::ZHADAN_TYPE : {
            ZHADAN *pre_ = dynamic_cast<ZHADAN *>(pre);
            return this->x > pre_->x;
        } break;
        default : return true;
    }
    return false;
}

WANGZHA::WANGZHA() : PAI(PAI_TYPE::WANGZHA_TYPE) {}
ostream &WANGZHA::output() {
    return cout << "WANG ZHA";
}
void WANGZHA::take(int *arr) {
    arr[16] -= 1;
    arr[17] -= 1;
    return ;
}
void WANGZHA::back(int *arr) {  
    arr[16] += 1;
    arr[17] += 1;
    return ;
}
vector<PAI *> WANGZHA::get(int *arr) {
    vector<PAI *> ret;
    if (arr[16] && arr[17]) ret.push_back(new WANGZHA());
    return ret;
}
bool WANGZHA::operator>(PAI *pre) {
    return true;
}

void PAI::output_arr(int *arr) {
    for (int i = 3; i < MAX_N; i++) {
        if (arr[i] == 0) continue;
        cout << name[i] << "*" << arr[i] << " ";
    }
    cout << endl;
    return ;
}

vector<PAI *> PAI::getPai(int *arr) {
    vector<PAI *> ret;
    vector<PAI *> temp1 = DAN::get(arr);
    for (auto x : temp1) ret.push_back(x);
    vector<PAI *> temp2 = DUIZI::get(arr);
    for (auto x : temp2) ret.push_back(x);
    vector<PAI *> temp3 = SHUNZI::get(arr);
    for (auto x : temp3) ret.push_back(x);
    vector<PAI *> temp4 = SANDAI::get(arr);
    for (auto x : temp4) ret.push_back(x);
    vector<PAI *> temp5 = ZHADAN::get(arr);
    for (auto x : temp5) ret.push_back(x);
    vector<PAI *> temp6 = WANGZHA::get(arr);
    for (auto x : temp6) ret.push_back(x);
    vector<PAI *> temp7 = LIANDUI::get(arr);
    for (auto x : temp7) ret.push_back(x);
    vector<PAI *> temp8 = SIDAI::get(arr);
    for (auto x : temp8) ret.push_back(x);
    vector<PAI *> temp9 = PASS::get(arr);
    for (auto x : temp9) ret.push_back(x);

    return ret;
}

vector<PAI *> PAI::getLegalPai(int *arr, PAI *pai) {
    vector<PAI *> temp = PAI::getPai(arr);
    vector<PAI *> ret;
    for (auto x : temp) {
        if (x->operator>(pai)) ret.push_back(x);
        else {
            delete x;
        }
    }
    return ret;
}

