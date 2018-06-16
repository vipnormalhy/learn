using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collections
{
	class Vector {
		public int X_ {get; set;}
		public int Y_ {get; set;}
		public int Z_ {get; set;}

		public Vector(int x, int y, int z) {
			X_ = x;
			Y_ = y;
			Z_ = z;
		}

		public static Vector operator +(Vector first, Vector second) {
			first.X_ += second.X_;
			first.Y_ += second.Y_;
			first.Z_ += second.Z_;
			return first;
		}

		public static bool operator ==(Vector first, Vector second) => (first.X_ == second.X_ &&
				first.Y_ == second.Y_ && first.Z_ == second.Z_);

		public static bool operator !=(Vector first, Vector second) => !(first == second);

		public override bool Equals(object obj) {
			if (obj == null) {
				return false;
			} else {
				if (obj is Vector) {
					return this == obj as Vector;
				} else {
					return false;
				}
			}
		}

		public override int GetHashCode() {
			return 1;
		}

		public int this[string index] {
			get {
				switch(index) {
					case "x":
						return X_;
					case "y":
						return Y_;
					case "z":
						return Z_;
					default:
						return 0;
				}
			}
			set {
				switch(index) {
					case "x":
						X_ = value;
						break;
					case "y":
						Y_ = value;
						break;
					case "z":
						Z_ = value;
						break;
					default:
						break;
				}
			}
		}
	}

	class Program {
		static void Main(string[] args) {
			ArrayTest();
			JaggedTest();
			CreateArray();
			TestCompare();
			TestCheck();
			TestNull();
			TestOperator();
		}

		static void TestOperator() {
			Vector a = new Vector(1, 2, 3);
			Vector b = new Vector(4, 5, 6);

			a += b;
			Console.WriteLine($"a is {a.X_}, {a.Y_} {a.Z_}");

			int x = a["x"];
			Console.WriteLine($"index 'a' is {x}");
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

		static void TestCheck() {
			byte a = 255;
			checked {
				unchecked {
					a++;
				}
			}

			Console.WriteLine($"value {nameof(a)} is {a}");
		}
		
		static void TestNull() {
			int? a = null;
			int b = 3;
			int c = a??3 + b;
			int[] a2 = null;

			c = a2?[0] ?? 3 + 8;
			Console.WriteLine($"value is {c}");

			if (a + b >= 0) {
				Console.WriteLine("a + b >= 0");
			} else if (a + b <= 0) {
				Console.WriteLine("a + b <= 0");
			} else {
				Console.WriteLine("elseeeeeeee");
			}

			Console.WriteLine($"value is {a}");
			a = a??10;
			Console.WriteLine($"value is {a}");
		}
	}
}
