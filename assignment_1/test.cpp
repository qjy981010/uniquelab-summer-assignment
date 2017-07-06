#include "set.h"
#include "llrb.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <time.h>
#include <set>

using namespace std;

int main() {
    std::set<double> std_set;
    Set custom_set;
    for (int i = 1; i != 1000; ++i) {
        long long num = (long long)rand()*1000;
        num %=i;
        cout << custom_set.count(num) << " " << std_set.count(num) << endl;
        custom_set.insert((double) i);
        std_set.insert((double) i);
        cout << "1: " << custom_set.size() << " " << std_set.size() << endl;
        custom_set.insert((double) (-i));
        std_set.insert((double) (-i));
        cout << "2: " << custom_set.size() << " " << std_set.size() << endl;
        custom_set.erase((double)(num));
        std_set.erase((double)(num));
        cout << "3: num="<< num << "   " << custom_set.size() << " " << std_set.size() << endl;
        cout << custom_set.count(num) << " " << std_set.count(num) << endl;
        cout << endl;
    }
    // ASSERT_EQ(std_set.size(), custom_set.size());
    // for (auto s:std_set) {
    //     custom_set.erase(s);
    // }
    // ASSERT_EQ(custom_set.size(), 0);
}
