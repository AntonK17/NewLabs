#include "Stacksimple.h" 

int Priority(char o)
{ 
	int Prt;
	switch (o) 
	{
	case '*':
	case '/': Prt = 3; break;
	case '+':
	case '-': Prt = 2; break;
	case '(': Prt = 1; break;
	case '=': Prt = 0; break;
	default: Prt = -1;
	}
	return Prt;
}

bool IsOperand(char n)
{
	switch (n)
	{
	default: return false;
	case '0': return true;
	case '1': return true;
	case '2': return true;
	case '3': return true;
	case '4': return true;
	case '5': return true;
	case '6': return true;
	case '7': return true;
	case '8': return true;
	case '9': return true;
	case ',': return true;
	case '.': return true;
	}
}

int IsOperation(char o)
{
	if (o == '+' || o == '-' || o == '*' || o == '/' || o == '=') return 1;
	else 
		return 0;
}


string ToPost(string &Infix)
{
	char ch, t;
	string tmp("");
	int pos(0), pos1(0);


	TStack <char> OperationStack(10);
	ch = Infix[pos];
	do
	{
		
		if (IsOperand(ch)) 
		{
			string operand;
			while ((pos < Infix.length()) && IsOperand(ch))
			{
				operand += Infix[pos];
				pos++;
				ch = Infix[pos];
			}
			tmp += " " + operand;
		}
		else if (ch == '(') {
			OperationStack.Push(ch); pos++;
		}
		else if (ch == ')')
		{
			while (1)
			{
				t = OperationStack.Pop();
				if (t == '(') 
				{
					break;
				}
				tmp += t; 
			}
			pos++;
		}

		else if (IsOperation(ch))
		{
			while (!OperationStack.IsEmpty())
			{
				t = OperationStack.Pop();
				if (Priority(ch) <= Priority(t)) tmp += t;
				else 
				{ 
					OperationStack.Push(t); 
					{ 
						break;
					} 
				}
			}
			OperationStack.Push(ch);
			pos++;
			
		}
		ch = Infix[pos];
	}
	while (ch != '=');


	while (!OperationStack.IsEmpty())
	{
		t = OperationStack.Pop();
		tmp += t;	
	};
	
	tmp += '=';
	return tmp;

}
 double Answer(string &tmp)
{ 
	TStack <double> CalcStack(25);


int pos1(0);
double op_r(0), op_l(0), rez(0);
char ch;
ch = tmp[pos1];
	do 
	{
		
		if (ch == ' ') pos1++;
	    if (IsOperand(ch)) {
			string operand;
			while ((pos1 < tmp.length()) && IsOperand(ch))
			{
				operand += tmp[pos1];
				ch = tmp[++pos1];
 			}
			
			double o = atof(operand.c_str());
			CalcStack.Push(o);
			
		}
		
		else if (IsOperation(ch)) {
			 
			op_r = CalcStack.Pop();
			op_l = CalcStack.Pop();

			switch (ch)
			{
			case '+':CalcStack.Push(op_l + op_r); break;
			case '-':CalcStack.Push(op_l - op_r); break;
			case '*':CalcStack.Push(op_l * op_r); break;
			case '/':CalcStack.Push(op_l / op_r); break;
			}
			pos1++;
		}

		ch = tmp[pos1];
	} while (ch != '=');
	 
	rez = CalcStack.Pop();
	return rez;

}