#include "common.h"

class String {
private:
    char *m_Buffer;
    unsigned int m_Size;
public:
    String(const char *string) {
        m_Size = sizeof(string);
        m_Buffer = new char[m_Size + 1];
        // memcpy(m_Buffer, string, m_Size + 1);
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    //重写拷贝构造函数，进行深拷贝
    String(const String &other)
            : m_Size(other.m_Size) {
        m_Buffer = new char(m_Size + 1);
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String() {
        delete[] m_Buffer;
    }

    //重载索引操作符
    char &operator[](unsigned int index) {
        return m_Buffer[index];
    }

    //友元函数可以访问私有成员
    friend std::ostream &operator<<(std::ostream &stream, String string);
};

std::ostream &operator<<(std::ostream &stream, String string) {
    stream << string.m_Buffer;
    return stream;
}

int main() {
    String string("Cherno");
    //浅拷贝，复制的是m_Buffer的地址和m_Size的值，当string析构之后，second无法进行再次释放
    //也就是说，浅拷贝拷贝的是指针，两个字符串对象指向同一个内存缓冲区
    //复制了但没完全复制
    String second = string;
    second[2] = 'a';
    cout << string << endl;
    cout << second << endl;
    return 0;
}