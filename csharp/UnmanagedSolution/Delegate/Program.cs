using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegate
{
	class Program {
		static void Main(string[] args) {
			DelegateTestFunc();
		}

		static void DelegateTestFunc() {
			Delegate.DelegateClass.DelegateTest testobj = new Delegate.DelegateClass.DelegateTest();

			testobj.Test();
			testobj.Test2();
			testobj.TestCluster();

			Delegate.EventTest.CarDeal event_testobj = new Delegate.EventTest.CarDeal();
			event_testobj.Test();
		}
	}
}
