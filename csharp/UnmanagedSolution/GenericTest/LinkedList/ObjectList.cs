using System;
using System.Collections;

namespace GenericTest.LinkedList {
	class ObjectListNode {
		public object Value_ {get; private set;}
		public ObjectListNode Previous_ {get; internal set;}
		public ObjectListNode Next_ {get; internal set;}

		public ObjectListNode(object value) {
			Value_ = value;

			Previous_ = null;
			Next_ = null;
		}
	}


	class ObjectList: IEnumerable {
		public ObjectListNode Head_ {get; private set;}
		public ObjectListNode Last_ {get; private set;}

		public ObjectList() {
			Head_ = Last_ = null;
		}

		public bool AddObject(object newobject) {
			var node = new ObjectListNode(newobject);

			if (Last_ == null) {
				if (Head_ != null) {
					Console.WriteLine("List error! Last is null, head is not null");
					return false;
				}

				Head_ = node;
				Last_ = node;
			} else {
				// last_ must to be null
				if (Last_.Next_!= null) {
					Console.WriteLine("Cannot insert into a list!");
					return false;
				}

				Last_.Next_= node;
				node.Previous_ = Last_;
				Last_ = node;
			}

			return true;
		}

		public IEnumerator GetEnumerator() {
			ObjectListNode node = Head_;
			while (node != null) {
				yield return node.Value_;
				node = node.Next_;
			}
		}
	}
}
