#include <iostream>
#include "functions.h"

using namespace std;

float absolute(const float &a);
bool RunTest(int testnum, float result, float expected);

int main() {
    int tests_passed, test_count;
    tests_passed = test_count = 0;
    float result, expected;
    // test AreaOfCircle
    tests_passed += RunTest(++test_count, AreaOfCircle(1.0), 3.1416);
    tests_passed += RunTest(++test_count, AreaOfCircle(3.0), 28.2744);
    tests_passed += RunTest(++test_count, AreaOfCircle(5.5), 95.0334);
    // test AreaOfTriangle
    tests_passed += RunTest(++test_count, AreaOfTriangle(1.0, 1.0), 0.5);
    tests_passed += RunTest(++test_count, AreaOfTriangle(6.0, 3.0), 9.0);
    tests_passed += RunTest(++test_count, AreaOfTriangle(3.14, 26.2), 41.134);
    // test AreaOfRectangle
    tests_passed += RunTest(++test_count, AreaOfRectangle(1.0, 1.0), 1.0);
    tests_passed += RunTest(++test_count, AreaOfRectangle(7.0, 4.0), 28.0);
    tests_passed += RunTest(++test_count, AreaOfRectangle(3.65, 17.0), 62.05);
    // test VolumeOfSphere
    tests_passed += RunTest(++test_count, VolumeOfSphere(1.0), 4.1889);
    tests_passed += RunTest(++test_count, VolumeOfSphere(4.0), 268.0832);
    tests_passed += RunTest(++test_count, VolumeOfSphere(3.1416), 129.88);
    // test VolumeOfCone
    tests_passed += RunTest(++test_count, VolumeOfCone(1.0, 1.0), 1.0467);
    tests_passed += RunTest(++test_count, VolumeOfCone(7.1, 5.2), 274.5046);
    tests_passed += RunTest(++test_count, VolumeOfCone(5.2, 7.1), 201.0456);
    // test VolumeOfBox
    tests_passed += RunTest(++test_count, VolumeOfBox(1.0, 1.0, 1.0), 1.0);
    tests_passed += RunTest(++test_count, VolumeOfBox(24.0, 7.0, 52.0), 8736.0);
    tests_passed += RunTest(++test_count, VolumeOfBox(1.2, 2.3, 3.4), 9.384);
    cout << "Passed " << tests_passed << "/" << test_count << " tests." << endl;

    return 0;
}

float absolute(const float &a) {
    return a < 0 ? -a : a;
}

bool RunTest(int testnum, float result, float expected) {
    if (absolute(result - expected) > 0.05) {
        cout << "Failed test #" << testnum
             << ", expected " << expected << " but got " << result << endl;
        return false;
    }
    return true;
}
