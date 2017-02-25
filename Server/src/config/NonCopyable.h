/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: NonCopyable.h
Date: 2016-11-28
Description: 观察者模式
**************************************************/

#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

class CNoCopyable {
protected:
    CNoCopyable() = default;
    ~CNoCopyable() = default;
    CNoCopyable(const CNoCopyable &) = delete;
    CNoCopyable &operator = (const CNoCopyable &) = delete;
};

template<typename Func>
class CEvents : CNoCopyable {
public:
    CEvents() {}
    ~CEvents() {}

    //注册观察者
    int connect(Func &&fun) {
        return assgin(fun);
    }

    int connect(const Func &fun) {
        return assgin(fun);
    }

    void disconnect(int key) {
        m_connections.erase((key));
    }

    //广播
    template<typename... Args>
    void notify(Args&&... args) {
        for (const auto &it : m_connections) {
            it.second(std::forward<Args>(args)...);
        }
    }
private:
    //保存观察者并分配编号
    template<typename F>
    int assgin(F &&fun) {
        int _key = (++m_observerId);
        m_connections.emplace(_key, std::forward<F>(fun));
        return _key;
    }
    int m_observerId = 0; //观察者id
    std::unordered_map<int, Func> m_connections; //观察者列表
};

#endif // NONCOPYABLE_H_