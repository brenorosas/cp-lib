#include <bits/stdc++.h>
using namespace std;

namespace 
{
static std::mt19937& random_engine()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}

template<typename T>
static T rand_int(const T& a, const T& b)
{
    std::uniform_int_distribution<T> dis(a, b);
    return dis(random_engine());
}

template<typename Container>
static auto rand_elem(const Container& container)
    -> typename Container::value_type
{
    assert(container.size() > 0);
    return container[rand_int(0, (int)container.size() - 1)];
}

static string rand_string(const string& charset, int size)
{
    string s(size, '0');
    for(int i = 0; i < size; ++i)
        s[i] = rand_elem(charset);
    return s;
}
}

signed main(int argc, char* argv[])
{
    const bool is_big_input = (argc > 1);
    const int n = is_big_input? 100 : rand_int(1, 100);

    cout << n << endl;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << rand_int(1, 100) << ' ';
        cout << endl;
    }

    cout << rand_int(0, n-1) << ' ' << rand_int(0, n-1) << endl;
}
