/*************************************************************************
	> File Name: pai.h
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 08:45:30 AM CST
 ************************************************************************/

#ifndef _PAI_H
#define _PAI_H

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 18

enum class PAI_TYPE {
    DAN_TYPE,
    DUIZI_TYPE,
    SHUNZI_TYPE,
    SANDAI_TYPE,
    ZHADAN_TYPE,
    WANGZHA_TYPE,
    LIANDUI_TYPE,
    FEIJI_TYPE,
    SIDAI_TYPE,
    PASS_TYPE
};

class PAI {
public:
    PAI(PAI_TYPE type);
    static void output_arr(int *);
    static vector<PAI *> getPai(int *);
    static vector<PAI *> getLegalPai(int *, PAI *);
    virtual ostream &output() = 0;
    virtual bool operator>(PAI *) = 0;
    virtual void take(int *) = 0;
    virtual void back(int *) = 0;
    PAI_TYPE type;
    virtual ~PAI() = default;
};

class PASS : public PAI {
public:
    PASS();
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
};

class DAN : public PAI {
public:
    DAN(int x);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
private:
    int x;
};

class DUIZI : public PAI {
public:
    DUIZI(int x);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
private:
    int x;
};

class SHUNZI : public PAI {
public:
    SHUNZI(int start, int end);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
    int start, end;
};

class LIANDUI : public PAI {
public:
    LIANDUI(int start, int end);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
    int start, end;
};

class SANDAI : public PAI {
public:
    SANDAI(int san, PAI *dai);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
private:
    int san;
    PAI *dai;
};

/************
class FEIJI : public PAI {
public:
    FEIJI(vector<PAI *>);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
private:
    vector<PAI *> feiji;
};
**************/

class SIDAI : public PAI {
public:
    SIDAI(int si, PAI *dai1, PAI *dai2);
    ostream &output() override;
    bool operator>(PAI *) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
private:
    int si;
    PAI *dai1, *dai2;
};

class ZHADAN : public PAI {
public:
    ZHADAN(int x);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
private:
    int x;
};

class WANGZHA : public PAI {
public :
    WANGZHA();
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
};


#endif
