using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericTest
{
	class Program {
		static void Main(string[] args) {
			TestLinkedList();
			TestGenericLinkedList();
		}
		
		static void TestLinkedList() {
			var obj_list = new LinkedList.ObjectList();

			obj_list.AddObject(1);
			obj_list.AddObject("dd");
			obj_list.AddObject(obj_list);

			int index = 0;
			foreach (object data in obj_list) {
				Console.WriteLine($"Item {index}'s type is {data.GetType()}");
				index += 1;
			}
		}

		static void TestGenericLinkedList() {
			var data_list = new LinkedList.GenericList<int>();
			data_list.AddItem(1);
			data_list.AddItem(2);
			data_list.AddItem(3);

			int index = 0;
			foreach (int i in data_list) {
				Console.WriteLine($"Item {index}'s type is {i.GetType()}, value is {i}");
				index += 1;
			}
		}
	}
}
