/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: NonCopyable.h
Date: 2016-11-28
Description: �۲���ģʽ
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

    //ע��۲���
    int connect(Func &&fun) {
        return assgin(fun);
    }

    int connect(const Func &fun) {
        return assgin(fun);
    }

    void disconnect(int key) {
        m_connections.erase((key));
    }

    //�㲥
    template<typename... Args>
    void notify(Args&&... args) {
        for (const auto &it : m_connections) {
            it.second(std::forward<Args>(args)...);
        }
    }
private:
    //����۲��߲�������
    template<typename F>
    int assgin(F &&fun) {
        int _key = (++m_observerId);
        m_connections.emplace(_key, std::forward<F>(fun));
        return _key;
    }
    int m_observerId = 0; //�۲���id
    std::unordered_map<int, Func> m_connections; //�۲����б�
};

#endif // NONCOPYABLE_H_