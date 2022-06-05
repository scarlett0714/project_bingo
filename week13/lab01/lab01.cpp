#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;
int main() {
	cout << "202110547 Ȳ����" << endl;

    //stack
    stack <int> num;

    string s;
    getline(cin, s);

    stringstream ss(s);
    ss.str(s);

    string word;
    while (ss >> word) {
        if (word == "+" || word == "-" || word == "*" || word == "/") {
            if (!num.empty()) {
                int a = num.top();
                num.pop();

                if (!num.empty()) {
                    int b = num.top();
                    num.pop();

                    if (word == "+") {
                        num.push(a + b);
                    }
                    else if (word == "-") {
                        num.push(a - b);
                    }
                    else if (word == "*") {
                        num.push(a * b);
                    }
                    else {
                        num.push(a / b);
                    }
                }
                else {
                    cout << "������� �ٽ� �Է��ϼ���." << endl;
                    return 0;
                }
                
            }
            else {
                cout << "������� �ٽ� �Է��ϼ���." << endl;
                return 0;
            }
        }
        else {
            num.push(stoi(word));
        }
    }

    cout << num.top() << endl;
}