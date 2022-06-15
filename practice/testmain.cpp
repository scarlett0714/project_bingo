#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <utility>
#include <map>
using namespace std;

class Shape
{
public:
	void Move(double x, double y);
	void Draw() const;
	Shape() = default;
	Shape(double x, double y);
protected:
	double _x, _y;
};
void Shape::Move(double x, double y)
{
	_x = x;
	_y = y;
}
void Shape::Draw() const
{
	cout << "[Shape] Position = ( " << _x << ", " << _y << ")\n";
}

Shape::Shape(double x, double y) : _x(x), _y(y)
{
}

// 사각형을 상징하는 클래스
class Rectangle : public Shape
{
public:
	void Draw() const;
	void Resize(double width, double height);
	Rectangle() = default;
	Rectangle(double x, double y, double width, double height);
protected:
	double _width;
	double _height;
};
void Rectangle::Draw() const
{
	cout << "[Rectangle] Position = ( " << _x << ", " << _y << ") "
		"Size = ( " << _width << ", " << _height << ")\n";
}

void Rectangle::Resize(double width, double height)
{
	_width = width;
	_height = height;
}

Rectangle::Rectangle(double x, double y, double width, double height)
	: Shape(x,y), _width(width), _height(height)
{
}

// 원을 상징하는 클래스
class Circle : public Shape
{
public:
	void Draw() const;
	void SetRadius(double radius);
	Circle() = default;
	Circle(double x, double y, double radius);
protected:
	double _radius;
};
void Circle::Draw() const
{
	cout << "[Circle] Position = ( " << _x << ", " << _y << ") "
		"Radius = " << _radius << "\n";
}

void Circle::SetRadius(double radius)
{
	_radius = radius;
}

Circle::Circle(double x, double y, double radius) : Shape(x, y), _radius(radius)
{
}

int main()
{
	// 도형 객체 생성 및 그리기
	Shape s;
	s.Move(100, 100);
	s.Draw(); //Shape Draw()

	// 사각형 객체 생성 및 그리기
	Rectangle r;
	r.Move(200, 100);
	r.Resize(50, 50);
	r.Draw(); //Rectangle Draw()

	// 원 객체 생성 및 그리기
	Circle c;
	c.Move(300, 100);
	c.SetRadius(30);
	c.Draw(); //Circle Draw();

	//도형 클래스의 객체들을 배열에 담아서 사용하는 예
	Shape* shapes[5] = { nullptr }; //빈 방 포인터 배열
	//부모는 자식을 가리킬 수 있음 : 업캐스팅
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);
	for (int i = 0; i < 5; ++i)
		shapes[i]->Draw();
	//P : 정적바인딩 -> Shape의 Draw() 호출
	//S : 동적바인딩
	for (int i = 0; i < 5; ++i) {
		delete shapes[i];
		shapes[i] = NULL;
	}

	/*vector<int> scores;
	while (true) {
		cout << "Enter score (-1 to stop): ";
		int temp;
		cin >> temp;
		if (temp == -1) break;
		scores.push_back(temp);
	}

	for (size_t i = 0; i < scores.size(); i++) {
		cout << scores[i] << endl;
	}*/

	/*vector<int> scores = { 1,2,3,4,5,6 };
	vector<int>::const_reverse_iterator it;
	for (it = scores.crbegin(); it != scores.crend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = scores.crbegin(); it != scores.crend(); ++it) {
		cout << *it << " ";
	}*/

	/*vector<string> vec;
	vec.emplace_back(5, 'a');
	vec.emplace_back(4, 'b');
	vec.emplace_back(3, 'c');
	vec.emplace_back(2, 'd');
	vec.emplace_back(1, 'f');

	string* pstr = vec.data();
	pstr[2] = "greenjoa";
	for (auto& s : vec) {
		cout << s << endl;
	}*/

	/*array<int, 3> arr1;
	array<int, 3> arr2 = { 1,2,3 };
	cout << arr1.size();

	cout << arr2.size() << endl;

	for (const auto& i : arr2) {
		cout << i << " ";
	}
	cout << endl;
	for (auto it = arr2.begin(); it != arr2.end(); ++it) {
		cout << *it << " ";
	}*/

	//deque<int> dq;
	//dq.push_back(99); //99
	//dq.push_back(1); //99 1
	//dq.push_front(35); //35 99 1
	//dq.push_front(67); //67 35 99 1

	//dq.at(1);

	//for (int i = 0; i < dq.size(); i++) {
	//	cout << dq[i] << " "; //67 35 99 1
	//}
	//cout << endl;

	//dq.pop_back(); //67 35 99
	//dq.pop_front(); //35 99
	//for (int i = 0; i < dq.size(); i++) {
	//	cout << dq[i] << " "; //35 99
	//}

	//list<string> name1 = { "aa", "bb", "ca", "bb", "bb", "cb" };
	//list<string> name2 = { "aa", "bb", "ca" };

	//name1.remove("bb"); //aa ca cb
	//name1.unique(); //aa bb ca bb cb

	//name1.sort(); //aa bb bb ca cb
	//name2.sort(); //aa bb ca
	//name1.merge(name2); //name1 : aa aa bb bb bb ca ca cb

	//name1.reverse(); //cb ca ca bb bb bb aa aa

	//pair<string, int> pair1("greenjoa1", 10);
	//pair<string, int> pair2;
	//pair2.first = "greenjoa2";
	//pair2.second = 30;

	//pair<string, int> pair3(pair2);
	//pair<string, int> pair4 = make_pair("greenjoa", 20);
	//auto pair5 = make_pair("greenjoa", 20);
	
	map<string, int> scores;
	scores["greenjoa1"] = 85; //map[key] : value 대입 가능
	scores["greenjoa2"] = 90;

	scores.insert(pair<string, int>("greenjoa3", 50)); //인자 : pair
	scores.insert({ "greenjoa4", 90 }); //이니셜라이즈

	//pair<iterator, bool>
	/*pair<map<string, int>::iterator, bool> ret1 = scores.insert({ "greenjoa3", 90 });
	if (ret1.second) {
		cout << ret1.first->second << " insert succeeded!" << endl;
	}
	else {
		cout << "insert failed" << endl;
	}

	auto ret2 = scores.insert(make_pair("greenjoa3", 90));
	if (ret2.second) {
		cout << ret2.first->second << " insert succeeded!" << endl;
	}
	else {
		cout << "insert failed" << endl;
	}*/


	auto it = scores.find("greenjoa2");
	if (it != scores.end()) {
		//it->first로 key값 점근 가능 but key값은 변경X
		it->second = 100; //value변경
	}
	
	for (const auto& p : scores) {
		cout << p.first << " : " << p.second << endl;
	}

	scores.erase("greenjoa3");
	cout << scores.count("greenjoa3") << "with key greenjoa3" << endl;

	auto extractnode = scores.extract("greenjoa2");
	cout << extractnode.key() << ", " << extractnode.mapped() << endl;

	map<string, int> scores2 = { {"bluejoa1", 70}, {"bluejoa2", 60} };
	scores.merge(scores2);
}

