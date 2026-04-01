/*setw를 고정값으로 사용할 때 발생하는 문제
1부터 1000까지 제곱값을 계산하면 최대값은 1, 000, 000 (7자리)입니다
기존 코드에서 setw(15)를 그대로 두면 이 경우에는 아직 충분하지만, 만약 setw
값이 작게 고정되어 있다면 열 정렬이 깨지는 현상이 발생합니다
즉, 범위를 변경할 때마다 수동으로 setw 인수를 바꿔야 하는 유지보수 문제가 생깁니다.*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const int MAX_VALUE = 1000;

    // 최대값과 최대 제곱값의 자릿수로 열 너비 계산
    long long maxSquare = static_cast<long long>(MAX_VALUE * MAX_VALUE);
    int valueWidth = static_cast<int>(log10(MAX_VALUE)) + 4;
    int squareWidth = static_cast<int>(log10(maxSquare)) + 4;

    // 헤더 출력
    cout << setw(valueWidth) << "Value"
        << setw(squareWidth) << "Square" << endl;
    cout << setw(valueWidth) << "-----"
        << setw(squareWidth) << "------" << endl;

    // 값과 제곱값 출력
    for (int i = 1; i <= MAX_VALUE; i++)
    {
        cout << setw(valueWidth) << i
            << setw(squareWidth) << static_cast<long long>(i * i) << endl;
    }

    return 0;
}
