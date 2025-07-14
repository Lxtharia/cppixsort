#include <bits/std_thread.h>
#include <vector>
using std::vector;

struct Pixel {
    int r;
    int g;
    int b;
};

class Pixelsorter {
private:
    bool m_inverse;
public:
    Pixelsorter(bool inverse = false)
        : m_inverse(inverse)
    {}
    ~Pixelsorter() {}

    void sort(int w, int h, vector<int>);
};
