#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

template<class T>
class Vect
{
private:
    vector<T> vec;
public:
    void operator+(int kst)
    {
        vec.resize(kst);
    }

    void operator<<(const string& filename)
    {
        ofstream file(filename);
        for (auto it = vec.begin(); it != vec.end(); it++)
            file << *it << " ";
        file.close();
    }

    void operator>>(const string& filename)
    {
        ifstream file(filename);
        T a;
        while (file >> a)
            vec.push_back(a);
        file.close();
    }

    void operator-(const string& filename)
    {
        if (filename.empty())
        {
            for (auto it = vec.begin(); it != vec.end(); it++)
                cout << *it << " ";
        }
        (*this) << filename;
    }

    T& operator[](int index)
    {
        return vec[index];
    }
};

int main()
{
    system("chcp 1251");

    Vect<char> vec;
    //vec + 10;
    vec >> "D:\\lab_7.txt";
    //vec[1] = 75;
    //vec[3] = 250;
    cout << vec[1] << " " << vec[3] << endl;
    //vec << "D:\\lab_7(1).txt";
    vec - "D:\\lab_7(1).txt";

    return 0;
}