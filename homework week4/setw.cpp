#include <iostream>
#include <iomanip>  // setw 함수를 사용하기 위한 헤더

using namespace std;

int main()
{
    // 헤더 출력
    cout << setw(10) << "Value"
        << setw(15) << "Square" << endl;
    cout << setw(10) << "-----"
        << setw(15) << "------" << endl;

    // 1부터 100까지 반복하며 값과 제곱값 출력
    for (int i = 1; i <= 100; i++)
    {
        cout << setw(10) << i
            << setw(15) << i * i << endl;
    }

    return 0;
}
