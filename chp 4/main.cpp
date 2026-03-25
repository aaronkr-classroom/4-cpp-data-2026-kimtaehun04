#include <algorithm> // sort()
#include <ios>
#include <iostream>
#include <iomanip> // setprecision()
#include <string>
#include <stdexcept> // istream& 위해
#include <vector>

using namespace std;

typedef vector<double>::size_type vec_sz;
//함수 원형문
istream& read_hw(istream&, vector<double>&); //함수 원형 정의문

double grade(double mid, double fin, const vector<double>&);

double grade(double, double, double);

double median(vector<double>);

// 학생 정보를 저장할 구조체 정의
struct student_info {
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

int main(void) {
	//새로운 구조 자료형 선언
	vector<student_info> students;
	student_info record;
	string::size_type maxlen = 0;


	// 학생의 이름을 묻고 읽음
	cout << "Fist name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// 중간고사와 기말고사 점수를 묻고 읽음
	cout << "Midterm + Final grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// 과제 점수를 묻고 읽음
	cout << "Enter all HW grades, then EOF: ";
	vector<double> homework; // 과제 점수들을 저장할 벡터

	// NEW 함수 read_hw()를 사용하여 과제 점수들을 읽음
	read_hw(cin, homework); // 사실 객체 필요해서 참조로 보냄

	//종합 점수를 계산해 생성
	double final_grade = grade(midterm, final, homework); //NEW 계산하는 함수 grade()
	streamsize prec = cout.precision(); // 소수점 이하 자릿수 저장
	cout << "Your final grade is ";
	cout << setprecision(3) << final_grade << setprecision(prec) << endl;



	return 0;
}
//입력 스트림에서 과제 점수를 읽어서 vecotor<double>에 넣음
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		// 이전 내용을 제거
		hw.clear();

		// 과제 점수를 읽어서 벡터에 추가
		double x;

		while (in >> x) {
			hw.push_back(x);
		}

		//다음 학생의 점수 입력 작업을 고려해 입력 스트림을 지움
		in.clear();
	}
	return in; // NEW 함수 read_hw()의 구현은 생략
}
//중간고사 점수, 기말고사 점수, 과제 점수의 벡터로 학생의 종합
//점수를 구함. 이 함수는 인수를 복사하지 않고 median 함수가
//해당 작업을 실행

double grade(double mid, double fin, const vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("Student has done no homework!");
	}
	// return 0.2 * mid + 0.4 * fin + 0.4 * (hw1 + hw2 ...) / hw.size())
	// NEW grade() 함수
	return grade(mid, fin, median(hw));
}

// 계산하는 grade() 함수
double grade(double midterm, double final, double homework) {
	return midterm * 0.2 + final * 0.4 + homework * 0.4;
}
// vector<double>의 중앙값을 구함
// 함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec) {
	vec_sz size = vec.size();
	if (size == 0) {
		throw domain_error("median of an empty vector!");
		return 1;
	}

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 //조건
		? (vec[mid] + vec[mid - 1]) / 2 // 참일 때 반환
		: vec[mid]; // 거짓일 때 반환
}
