#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector <string> prior = {"*/", "+-", "("};

int getPrior(char op) {
	for (int i = 0; i < prior.size(); i++)
		for (int j = 0; j < prior[i].length(); j++)
			if (prior[i][j] == op)
				return i;
	return -1;
}

bool isOp(char c) {
	return getPrior(c) != -1;
}
bool isNumChar(char c) {
	return isdigit(c) || c == '.';
}

double getOpRes(double a, double b, char op) {
	switch (op)
	{
	case '+': return a + b;
	case '*': return a * b;
	case '/': return a / b;
	case '-': return a - b;
	default:
		break;
	}
}

void procOp(stack <double> & nums, stack <char> & ops) {
	double b = nums.top(); nums.pop();
	double a = nums.top(); nums.pop();
	nums.push(getOpRes(a, b, ops.top()));
	ops.pop();
}

double calculate(string expression) {
	if (expression == "")
		return 0;
	string s = expression;
	stack <double> nums;
	stack <char> ops;

	for (int i = 0; i < s.length(); i++) {
		while (s[i] == ' ') i++;
		if (s[i] == '(')
			ops.push(s[i]);
		else if (s[i] == ')') {
			while (ops.top() != '(')
				procOp(nums, ops);
			ops.pop();
		}
		else if (isOp(s[i])) {
			int nowprior = getPrior(s[i]);
			while (!ops.empty() && getPrior(ops.top()) <= nowprior)
				procOp(nums, ops);
			ops.push(s[i]);
		}
		else {
			string t = "";
			for (; i < s.length() && isNumChar(s[i]); i++)
				t += s[i];
			i--;
			nums.push(stod(t));
		}
	}
	while (!ops.empty())
		procOp(nums, ops);
	return nums.top();
}

int main() {
	cout << "Calculator only for right mathematical expressions (\"exit\" to exit)" << endl;
	string expression;
	while (getline(cin, expression), expression != "exit")
		cout << calculate(expression) << endl;
}
