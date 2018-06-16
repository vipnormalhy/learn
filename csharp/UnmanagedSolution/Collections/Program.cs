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
			CreateArray();
			TestCompare();
		}

		static void CreateArray() {
			Array a = Array.CreateInstance(typeof(int), 10);
			a.SetValue(1, 0);

			foreach (var i in a) {
				Console.WriteLine($"value is {i}");
			}
		}

		static void JaggedTest() {
			int[][] a = new int[3][];
			a[0] = new int[3] {1, 2, 3};
			a[1] = new int[4] {4, 5, 7, 9};

			foreach (var i in a) {
				Console.WriteLine($"value is {i}");
			}

			Console.WriteLine($"array range is {a.Rank}");
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
			Console.WriteLine($"array range is {a.Rank}, array b's range is {b.Rank}");
		}

		class Person: IComparable<Person> {
			public string name_;

			public Person(string name) {
				name_ = name;
			}

			public int CompareTo(Person other) {
				if (other == null) {
					return -1;
				}

				return name_.CompareTo(other.name_);
			}
		}

		static void TestCompare() {
			Person[] persons = new Person[] {
				new Person("bca"), new Person("bbbbb"), new Person("acb"),
			};

			Array.Sort(persons);

			Console.WriteLine($"data is {persons}");

			foreach (var i in persons) {
				Console.WriteLine($"data is {i.name_}");
			}
		}
	}
}
