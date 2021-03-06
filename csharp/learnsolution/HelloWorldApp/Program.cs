﻿using System;

namespace HelloWorldApp
{
	struct TestRectangle {
		public int Width {get; set;}
		public int Length {get; set;}

		public string OutPutInfo() => $"test rectangle value width:{Width}, length:{Length}";
	}

	partial class TestRectangleClass {
		public int Width {get; set;}
		public int Length {get; set;}

		public string OutPutInfo() => $"test rectangle value width:{Width}, length:{Length}";
	}

	partial class TestRectangleClass {
		public string OutputInfo2() => $"test rectangle value width:{Width}";
	}

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

		public int Order {get; set;}

		public int ID {get; private set;}

		public void ChangeUserName(string name) {
			Name = name;
		}

		public TestStudent(int sid, string name, int order = 0) {
			ID = sid;
			Name = name;
			Order = order;
		}

		public TestStudent(string name): this(name: name, sid: 0, order: 0) {
		}

		public string toString() => $"Student {Name}({ID})";
	}

	class Program
	{
		static void TestRef(ref TestRectangle a) {
			a.Width = 3;
			a.Length = 5;
		}

		static void TestValue(TestRectangle a) {
			a.Width = 3;
			a.Length = 5;
		}

		static void TestClassRef(ref TestRectangleClass a) {
			Console.WriteLine($"ref class type is {a.GetType()}");

			a = new TestRectangleClass();
			a.Width = 3;
			a.Length = 5;
		}

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
			var student_a = new TestStudent(name: "Normal", sid: 1, order: 1);
			Console.WriteLine(student_a.toString());

			TestRectangle test_rectangle = new TestRectangle();
			test_rectangle.Width = 10;
			test_rectangle.Length = 10;

			// output initial data
			Console.WriteLine(test_rectangle.OutPutInfo());

			// use value
			TestValue(test_rectangle);
			Console.WriteLine("after change value");
			Console.WriteLine(test_rectangle.OutPutInfo());

			// use ref
			TestRef(ref test_rectangle);
			Console.WriteLine("after change value by ref");
			Console.WriteLine(test_rectangle.OutPutInfo());

			TestRectangleClass test_rec2 = new TestRectangleClass();
			test_rec2.Width = 10;
			test_rec2.Length = 10;

			TestClassRef(ref test_rec2);
			Console.WriteLine(test_rec2.OutPutInfo());

			Console.WriteLine($"rectangle type is {test_rec2.GetType()}");

			ref var test_type = ref test_rec2;
			Console.WriteLine($"type is {test_type.GetType()}");

			string test_string = "i am a boy. And I am a handsome boy";
			Console.WriteLine($"strign word count is {test_string.GetWordCount()}");

			var player = new PlayerAvatar();
			var enemy = new MonsterAvatar();
			Entity entity = player;

			Console.WriteLine(entity.TellSelf());

			IBankAccount test_account = new TestBank2() as IBankAccount;
			Console.WriteLine(test_account.OutPutInfo());
			test_account.PayIn((decimal)3478.5);
			Console.WriteLine(test_account.OutPutInfo());
			test_account.Withdraw((decimal)545.786);
			Console.WriteLine(test_account.OutPutInfo());

			WeakReference weak_entity = new WeakReference(entity);
			if (weak_entity.IsAlive) {
				Entity a = weak_entity.Target as Entity;
				if (a != null) {
					Console.WriteLine(a.TellSelf());
				}
			}

			TestUnsafe();
			TestMallocHeap();

			Console.WriteLine("Let's test stack alloc");
			Console.ReadLine();
			for (int i = 0; i < 100; i++) {
				TestStackalloc();
			}

			Console.WriteLine("Let's test heap leak");
			Console.ReadLine();
			for (int i = 0; i < 100; i++) {
				TestHeapalloc();
			}
			Console.ReadLine();

			Console.WriteLine("Enter any key to end process");
			Console.ReadLine();
		}

		unsafe static private void TestUnsafe() {
			UnsafeTest test_obj = new UnsafeTest();
			test_obj.SizeofTest();
		}

		unsafe static private void TestStackalloc() {
			char *p = stackalloc char[1024*100];
			p[0] = '1';
			return;
		}

		unsafe static private void TestHeapalloc() {
			// let's leak here
			char *p = (char *)UnsafeTest.NewHeap(sizeof(char) * 1024 * 100);
			p[0] = '1';
			return;
		}

		unsafe static private void TestMallocHeap() {
			Console.WriteLine("Enter any key to start to malloc heap memory");
			Console.ReadLine();
			int* p = (int *)UnsafeTest.NewHeap(sizeof(int) * 1024 * 10000);	
			// watch the memory in debugger
			Console.WriteLine("Enter any key to start to free heap memory");
			Console.ReadLine();
			UnsafeTest.FreeHeap(p);
			Console.WriteLine("Enter any key to end");
			Console.ReadLine();
		}
	}

	static public class StringExtendClass {
		public static int GetWordCount(this string line) => line.Split().Length;
	}
}
