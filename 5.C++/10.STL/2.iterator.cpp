/*************************************************************************
	> File Name: 2.iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Oct 2024 09:51:12 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <set>
#include <deque>
#include <ctime>
using namespace std;

// 迭代器的萃取工具iterator_traits<>
// 通过萃取工具去获得类型
// 有五种种类需要定义

template<typename _iTerator>
void __random_forward(_iTerator &iter, int n, std::input_iterator_tag) {
    n = rand() % n + 1;
    while (n--) ++iter;
    return ;
}

template<typename _iTerator>
void __random_forward(_iTerator &iter, int n, std::random_access_iterator_tag) {
    n = rand() % n + 1;
    iter += n;
    return ;
}

template<typename _iTerator>
void random_forward(_iTerator &iter, int n) {
    typedef typename std::iterator_traits<_iTerator>::iterator_category _Category;
    __random_forward(iter, n, _Category());
    return ;
}

int main() {
    srand(time(0));
    vector<int> vec;
    set<int> s;
    deque<int> q;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    
    vector<int>::iterator vec_iter = vec.begin();
    set<int>::iterator s_iter = s.begin();
    deque<int>::iterator q_iter = q.begin();

    random_forward(vec_iter, 4);
    random_forward(s_iter, 4);
    random_forward(q_iter, 4);

    cout << *vec_iter << " " << *s_iter << " " << *q_iter << endl;
    cout << distance(vec.begin(), vec_iter) << " " 
    << distance(s.begin(), s_iter) << " " 
    << distance(q.begin(), q_iter) << endl;

    return 0;
}
