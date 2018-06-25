using System;

namespace Delegate.DelegateClass {
	delegate int CalcNumDelegate(int a, int b);
	class DelegateTest {
		int CalcNum(int a, int b) {
			return a + b;
		}

		public void Test() {
			CalcNumDelegate call = new CalcNumDelegate(CalcNum);
			
			int result = call.Invoke(3, 4);
			System.Console.WriteLine($"calc result is {result}");

			CalcNumDelegate call2 = CalcNum;
			int result2 = call2.Invoke(5, 8);
			System.Console.WriteLine($"calc result is {result2}");
		}
	}
}
