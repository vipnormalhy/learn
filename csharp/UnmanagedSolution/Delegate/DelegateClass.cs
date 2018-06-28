using System;

namespace Delegate.DelegateClass {

	delegate int CalcNumDelegate(int a, int b);

	class DelegateTest {
		int CalcNum(int a, int b) {
			System.Console.WriteLine("enter calc num");
			return a + b;
		}

		int CalcNum2(int a, int b) {
			System.Console.WriteLine("enter calc num2");
			return a + b;
		}

		int CalcNum3(int a, int b) {
			System.Console.WriteLine("enter calc num3");
			// throw new Exception("throw an exception");
			return a + b;
		}

		int CalcNum4(int a, int b) {
			System.Console.WriteLine("enter calc num4");
			return a + b;
		}

		public void Test() {
			CalcNumDelegate call = new CalcNumDelegate(CalcNum);
			
			int result = call.Invoke(3, 4);
			System.Console.WriteLine($"calc result is {result}");

			CalcNumDelegate call2 = CalcNum;
			int result2 = call2.Invoke(5, 8);
			System.Console.WriteLine($"calc result is {result2}");

			Func<int, int, int> call3 = CalcNum;
			int result3 = call3.Invoke(10, 9);
			System.Console.WriteLine($"calc result is {result3}");

			Func<int, int, int> call4 = CalcNum;
			call4 += CalcNum2;
			call4 += CalcNum3;
			call4 += CalcNum4;

			call4.Invoke(10, 10);
		}

		public void Test2() {
			Action<int, int> call5 = delegate(int a, int b) {
				System.Console.WriteLine("enter delegate action");
				int c = a + b;
				System.Console.WriteLine($"result is {c}");
			};

			call5.Invoke(5, 6);

			Action<int, int> call6 = (a, b) => {
				System.Console.WriteLine("enter lambda action");
				int c = a + b;
				System.Console.WriteLine($"calculate result is {c}");
				return;
			};

			call6.Invoke(8, 9);
		}

		public void TestCluster() {
			int test_value = 3;

			// Action<int, int> call7 = delegate(int a, int b) {
			Action<int, int> call7 = (a, b) => {
				System.Console.WriteLine("enter test cluster");
				System.Console.WriteLine($"out value test value is {test_value}");
			};

			System.Console.WriteLine($"out lambda is {test_value}");
			call7.Invoke(1, 2);
			test_value = 10;
			System.Console.WriteLine($"out lambda is {test_value}");
			call7.Invoke(1, 2);
		}
	}
}
