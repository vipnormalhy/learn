using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnmanagedCode
{
	class Program {
		static void Main(string[] args) {
			// test
			Test();
		}

		static void Test() {
			TestCode.TestCase testcase = new TestCode.TestCase();

			testcase.TestHeapLeak(1000);
			testcase.TestHeapUse();
			Console.WriteLine("Press any key to exit");
			Console.ReadLine();
		}
	}
}
