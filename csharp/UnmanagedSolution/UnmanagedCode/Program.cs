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
			TestGCUnsafe();
		}

		static void Test() {
			TestCode.TestCase testcase = new TestCode.TestCase();

			// test heap malloc
			testcase.TestHeapLeak(1000);
			testcase.TestHeapUse();

			Console.WriteLine("Press any key to exit Heap test");
			Console.ReadLine();
		}

		static void TestGCUnsafe() {
			TestCode.TestCase testcase = new TestCode.TestCase();

			testcase.TestGCUnsafe();
			Console.WriteLine("Press any key to exit unmanaged memory test");
			Console.ReadLine();
		}
	}
}
