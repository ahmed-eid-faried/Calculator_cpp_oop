
#include <iostream>
#include <vector>
using namespace std;

class clsCalculator {
private:
	double _result = 0;
	double _LastNumber = 0;
	double _perviseResult = 0;
	string _LastOperation = "Add";
	string _PreviousOperation = "Add";
	vector<string> _PreviousOperations;

	void _ChangeOperation(string Operation) {
		_PreviousOperation = _LastOperation;
		_PreviousOperations.push_back(Operation);
		_LastOperation = Operation;
	}



public:
	void CancelLastOperation() {
		_PreviousOperations.pop_back();
		_LastOperation = _PreviousOperation;
		_PreviousOperation = _PreviousOperations[_PreviousOperations.size() - 1];
	}
	void PrintResult() {
		cout << "Result After " << _LastOperation << " " << _LastNumber << " is:" << _result << endl;
	}
	void SetNumber(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;
		_result = Num;
		_ChangeOperation("SetNumber");
	}
	void Clear() {
		_LastNumber = 0;
		_perviseResult = _result;
		_result = 0;
		_ChangeOperation("Clear");
	}
	void Add(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;
		_result += Num;
		_ChangeOperation("Add");
	}
	void Subtract(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;
		_result -= Num;
		_ChangeOperation("Subtract");
	}
	void Multiply(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;

		_result *= Num;
		_ChangeOperation("Multiply");
	}
	void Divede(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;
		if (Num == 0) {
			cout << "YOU CAN'T DIVIDE ON ZERO" << endl;
		}
		else {
			_result /= Num;
		}
		_ChangeOperation("Divede");
	}
	void Mod(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;
		_result = (int)_result % (int)Num;
		_ChangeOperation("Mod");
	}
	void Pow(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;
		_result = pow(_result, Num);
		_ChangeOperation("Pow");
	}
	void Sqrt() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = sqrt(_result);
		_ChangeOperation("Sqrt");
	}
	void Ln() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = log(_result);
		_ChangeOperation("Ln");
	}
	void Log10() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = log10(_result);
		_ChangeOperation("Log10");
	}
	void Sin() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = sin(_result);
		_ChangeOperation("Sin");
	}
	void Cos() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = cos(_result);
		_ChangeOperation("Cos");
	}
	void Tan() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = tan(_result);
		_ChangeOperation("Tan");
	}
	void ArcSin() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = asin(_result);
		_ChangeOperation("ArcSin");
	}
	void ArcCos() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = acos(_result);
		_ChangeOperation("ArcCos");
	}
	void ArcTan() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = atan(_result);
		_ChangeOperation("ArcTan");
	}
	void Sinh() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = sinh(_result);
		_ChangeOperation("Sinh");
	}
	void Cosh() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = cosh(_result);
		_ChangeOperation("Cosh");
	}
	void Tanh() {
		_LastNumber = _result;
		_perviseResult = _result;
		_result = tanh(_result);
		_ChangeOperation("Tanh");
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

	Calculator.CancelLastOperation();
	Calculator.PrintResult();

	Calculator.SetNumber(10);
	Calculator.Sin();
	Calculator.PrintResult();

	Calculator.Cos();
	Calculator.PrintResult();

	Calculator.Tan();
	Calculator.PrintResult();

	Calculator.SetNumber(0.5);
	Calculator.ArcSin();
	Calculator.PrintResult();

	Calculator.ArcCos();
	Calculator.PrintResult();

	Calculator.ArcTan();
	Calculator.PrintResult();

	Calculator.SetNumber(1);
	Calculator.Sinh();
	Calculator.PrintResult();

	Calculator.Cosh();
	Calculator.PrintResult();

	Calculator.Tanh();
	Calculator.PrintResult();

	Calculator.SetNumber(2.71828);
	Calculator.Ln();
	Calculator.PrintResult();

	Calculator.SetNumber(1000);
	Calculator.Log10();
	Calculator.PrintResult();
}