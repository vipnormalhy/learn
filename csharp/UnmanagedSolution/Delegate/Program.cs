﻿using System;
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
		}
	}
}
