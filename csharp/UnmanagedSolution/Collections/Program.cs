using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collections
{
	class Program {
		static void Main(string[] args) {
			ArrayTest();
			JaggedTest();
		}

		static void JaggedTest() {
			int[][] a = new int[3][];
			a[0] = new int[3] {1, 2, 3};
			a[1] = new int[4] {4, 5, 7, 9};

			foreach (var i in a) {
				Console.WriteLine($"value is {i}");
			}
		}

		static void ArrayTest() {
			int[] a = new int[3] {1, 2, 3};

			foreach (int i in a) {
				System.Console.WriteLine($"value is {i}");
			}

			int[,] b = new int[3, 3] {{1,2,3},{4,5,6},{7,8,9}};

			foreach (var i in b) {
				Console.WriteLine($"value is {i}");
			}

			Console.WriteLine($"value length is {b.Length}");
			// Console.WriteLine($"value[5] is ${b[5]}"); // Don't Support
		}
	}
}
