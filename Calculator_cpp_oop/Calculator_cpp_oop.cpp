
#include <iostream>
#include <vector>
#include <cmath>
//#include <math.h>
#include <iomanip> // Include iomanip for setw
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

enum Operations {
	Add = 1,
	Subtract,
	Multiply,
	Div,
	Mod,
	Pow,
	Sqrt,
	Ln,
	Log10,
	Sin,
	Cos,
	Tan,
	ArcSin,
	ArcCos,
	ArcTan,
	Sinh,
	Cosh,
	Tanh,
	Clear,
	Exist
};

class clsCalculator {
private:
	double _pi = M_PI;
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
	double ConvertRadiansToDegrees(double Num) {
		return Num * (_pi / 180);
	}
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
	void Divide(double Num) {
		_LastNumber = Num;
		_perviseResult = _result;
		if (Num == 0) {
			cout << "YOU CAN'T DIVIDE ON ZERO" << endl;
		}
		else {
			_result /= Num;
		}
		_ChangeOperation("Divide");
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

	void PerformOperation(Operations op, double num = 0) {
		switch (op) {
		case Operations::Add: Add(num); break;
		case Operations::Subtract: Subtract(num); break;
		case Operations::Multiply: Multiply(num); break;
		case Operations::Div: Divide(num); break;
		case Operations::Mod: Mod(num); break;
		case Operations::Pow: Pow(num); break;
		case Operations::Sqrt: Sqrt(); break;
		case Operations::Ln: Ln(); break;
		case Operations::Log10: Log10(); break;
		case Operations::Sin: Sin(); break;
		case Operations::Cos: Cos(); break;
		case Operations::Tan: Tan(); break;
		case Operations::ArcSin: ArcSin(); break;
		case Operations::ArcCos: ArcCos(); break;
		case Operations::ArcTan: ArcTan(); break;
		case Operations::Sinh: Sinh(); break;
		case Operations::Cosh: Cosh(); break;
		case Operations::Tanh: Tanh(); break;
		case Operations::Clear: Clear(); break;
		default: cout << "Invalid operation!" << endl; break;
		}
	}

	static void ShowOperations() {
		using std::setw;
		using std::left;
		using std::cout;
		using std::endl;

		cout << left;
		cout << setw(5) << "1." << setw(10) << "Add" << setw(5) << "2." << setw(10) << "Subtract" << setw(5) << "3." << "Multiply" << endl;
		cout << setw(5) << "4." << setw(10) << "Divide" << setw(5) << "5." << setw(10) << "Mod" << setw(5) << "6." << "Pow" << endl;
		cout << setw(5) << "7." << setw(10) << "Sqrt" << setw(5) << "8." << setw(10) << "Ln" << setw(5) << "9." << "Log10" << endl;
		cout << setw(5) << "10." << setw(10) << "Sin" << setw(5) << "11." << setw(10) << "Cos" << setw(5) << "12." << "Tan" << endl;
		cout << setw(5) << "13." << setw(10) << "ArcSin" << setw(5) << "14." << setw(10) << "ArcCos" << setw(5) << "15." << "ArcTan" << endl;
		cout << setw(5) << "16." << setw(10) << "Sinh" << setw(5) << "17." << setw(10) << "Cosh" << setw(5) << "18." << "Tanh" << endl;
		cout << setw(5) << "19." << setw(10) << "Clear" << setw(5) << "20." << setw(10) << "Exist" << endl;
	}

};

void StartCalculator() {
	cout << "============================================" << endl;
	cout << "                 Calculator                 " << endl;
	cout << "============================================" << endl;
	clsCalculator Calculator;
	int operation;
	double num;

	clsCalculator::ShowOperations(); // Show operations at the start
	cout << "Enter the number: ";
	cin >> num;
	Calculator.SetNumber(num);
	while (true) {
		cout << "Enter the operation number: ";
		cin >> operation;
		if (operation == Exist) {
			cout << "============================================" << endl;
			cout << "End Calculator:(" << endl;
			cout << "============================================" << endl;
			exit(0);
		}

		if (operation == Clear || operation == Sqrt || operation == Ln || operation == Log10 || operation == Sin || operation == Cos || operation == Tan || operation == ArcSin || operation == ArcCos || operation == ArcTan || operation == Sinh || operation == Cosh || operation == Tanh) {
			Calculator.PerformOperation(static_cast<Operations>(operation));
		}
		else {
			cout << "Enter the number: ";
			cin >> num;
			Calculator.PerformOperation(static_cast<Operations>(operation), num);
		}

		if (operation == Clear) {
			system("cls");
			StartCalculator();
		}

		Calculator.PrintResult();
	}

}
int main() {
	StartCalculator();
	return 0;
}

void ExampleCaculator()
{
	clsCalculator Calculator;
	Calculator.Add(100);
	Calculator.PrintResult();

	Calculator.Subtract(10);
	Calculator.PrintResult();

	Calculator.Multiply(10);
	Calculator.PrintResult();

	Calculator.Divide(10);
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