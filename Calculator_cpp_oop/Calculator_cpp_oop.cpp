
#include <iostream>
using namespace std;

class clsCalculator {
private:
	double _num = 0;
	double InputNum = 0;
	string _role = "Add";

public:
	void PrintResult() {
		cout << "Result After " << _role << " " << InputNum << " is:" << _num << endl;
	}
	void SetNumber(double Num) {
		_num = Num;
		_role = "SetNumber";
	}
	void Clear() {
		InputNum = _num;
		_num = 0;
		_role = "Clear";
	}
	void Add(double Num) {
		_num += Num;
		InputNum = Num;
		_role = "Add";
	}
	void Subtract(double Num) {
		_num -= Num;
		InputNum = Num;
		_role = "Subtract";
	}
	void Multiply(double Num) {
		_num *= Num;
		InputNum = Num;
		_role = "Multiply";
	}
	void Divede(double Num) {
		_num /= Num;
		InputNum = Num;
		_role = "Divede";
	}
	void Mod(double Num) {
		_num = (int)_num % (int)Num;
		InputNum = Num;
		_role = "Mod";
	}
	void Pow(double Num) {
		_num = pow(_num, Num);
		InputNum = Num;
		_role = "Pow";
	}
	void Sqrt() {
		InputNum = _num;
		_num = sqrt(_num);
		_role = "Sqrt";
	}

};
int main()
{
	clsCalculator Calculator;
	Calculator.Add(100);
	Calculator.PrintResult();

	Calculator.Subtract(10);
	Calculator.PrintResult();

	Calculator.Multiply(10);
	Calculator.PrintResult();

	Calculator.Divede(10);
	Calculator.PrintResult();

	Calculator.Mod(10);
	Calculator.PrintResult();

	Calculator.Clear();
	Calculator.PrintResult();

	Calculator.Add(100);
	Calculator.PrintResult();

	Calculator.Mod(6);
	Calculator.PrintResult();

	Calculator.Pow(3);
	Calculator.PrintResult();

	Calculator.Clear();
	Calculator.PrintResult();

	Calculator.SetNumber(25);
	Calculator.PrintResult();

	Calculator.Sqrt();
	Calculator.PrintResult();
}