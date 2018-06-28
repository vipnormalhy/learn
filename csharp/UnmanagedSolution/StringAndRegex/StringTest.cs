using System;

namespace StringAndRegex.StringTest {
	class StringTest {
		public void Test() {
			string test_string = "Hello from all the guys at Wrox Press";
			test_string += "We do hope you enjoy the book as much as we enjoyed writing it";

			for (char c = 'a'; c <= 'z'; c++) {
				char old_c = (char)c;
				char new_c = (char)(c + 1);
				test_string = test_string.Replace(old_c, new_c);
			}

			for (char c = 'A'; c <= 'Z'; c++) {
				char old_c = (char)c;
				char new_c = (char)(c + 1);
				test_string = test_string.Replace(old_c, new_c);
			}

			Console.WriteLine($"test string is {test_string}");

			int x = 0, y = 1;

			string test_string2 = $"test string is {x} + {y} = {x + y}";
			Console.WriteLine($"......{test_string2}......");

			var date = new DateTime(2025, 3, 4);
			Console.WriteLine($"{date:d}");
			Console.WriteLine($"{date:D}");
			Console.WriteLine($"{date:yyyy-MM-dd HH:mm:ss}");

			int test_int = 3456;

			Console.WriteLine($"{test_int:n}, {test_int:x}, {test_int:c}, {test_int:e}");
			Console.WriteLine($"{test_int:####.#####}");
		}

		public void TestStringBuilder() {
			System.Text.StringBuilder test_string = new System.Text.StringBuilder("Hello from all the guys at Wrox Press", 300);

			Console.WriteLine($"string builder length {test_string.Length} capacity {test_string.Capacity}");

			test_string.Append("We do hope you enjoy the book as much as we enjoyed writing it");
			Console.WriteLine($"string builder length {test_string.Length} capacity {test_string.Capacity}");
		}
	}
}
