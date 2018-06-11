using System;

namespace HelloWorldApp
{
	class TestStudent {
		private string _name;

		public string Name {
			get {
				return _name;
			}
			private set {
				_name = value;
			}
		}

		public int ID {get; private set;}

		public void ChangeUserName(string name) {
			Name = name;
		}

		public TestStudent(int sid, string name) {
			ID = sid;
			Name = name;
		}

		public string toString() => $"Student {Name}({ID})";
	}

	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");

			var name = "Test string";
			var age = 25;
			var is_bool = true;
			Type name_type = name.GetType();
			Type age_type = age.GetType();
			Type bool_type = is_bool.GetType();

			Console.WriteLine($"name type is {name_type}");
			Console.WriteLine($"age type is {age_type}");
			Console.WriteLine($"bool type is {bool_type}");

			for (int i = 0; i < args.Length; i++) {
				Console.WriteLine("args: " + args[i]);
			}

			// Init one student
			var student_a = new TestStudent(1, "Normal");
			Console.WriteLine(student_a.toString());
		}
	}
}
