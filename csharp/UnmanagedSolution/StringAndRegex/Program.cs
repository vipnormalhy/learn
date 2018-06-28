using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringAndRegex {
	class Program {
		static void Main(string[] args) {
			StringAndRegex.StringTest.StringTest testobj = new StringAndRegex.StringTest.StringTest();

			testobj.Test();
			testobj.TestStringBuilder();

			StringAndRegex.RegexTest.RegexTest testobj2 = new StringAndRegex.RegexTest.RegexTest();
			testobj2.Test();
		}
	}
}
