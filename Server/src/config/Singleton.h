/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: Singleton.h
Date: 2016-11-23
Description: 多参数单例模板 注:非线程安全 只可在单线程下
**************************************************/

#ifndef SINGLETON_H_
#define SINGLETON_H_

template <typename T>
class CSingleton
{
public:
    template<typename... Args>
    static T *initInstance(Args&&... args) {
        if (m_pInstance == nullptr) {
            m_pInstance = new T(std::forward<Args>(args)...);
        }
        return m_pInstance;
    }

    static T *getInstance() {
        if (m_pInstance == nullptr) {
            throw std::logic_error("the instance is not init, please initialize the instance first");
        }
        return m_pInstance;
    }

    static void destroyInstance() {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
private:
    CSingleton(void);
    virtual ~CSingleton(void);
    CSingleton(const CSingleton&);
    CSingleton &operator = (const CSingleton&);
private:
    static T *m_pInstance;
};

template <class T> T *CSingleton<T>::m_pInstance = nullptr;

#endif // SINGLETON_H