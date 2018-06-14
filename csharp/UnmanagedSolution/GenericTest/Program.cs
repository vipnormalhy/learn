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
	}
}
