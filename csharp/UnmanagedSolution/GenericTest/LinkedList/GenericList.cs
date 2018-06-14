using System;
using System.Collections;
using System.Collections.Generic;


namespace GenericTest.LinkedList {
	class GenericListNode<T> {
		public T Value_ {get; private set;}

		public GenericListNode<T> Previous_ {get; internal set;}
		public GenericListNode<T> Next_ {get; internal set;}

		public GenericListNode(T value) {
			Value_ = value;

			Previous_ = null;
			Next_ = null;
		}
	}

	class GenericList<T>: IEnumerable<T> {
		private GenericListNode<T> Head_ {get; set;}
		private GenericListNode<T> Last_ {get; set;}

		public bool AddItem(T value) {
			var node = new GenericListNode<T>(value);

			if (Head_ == null) {
				Head_ = node;
				Last_ = node;
				return true;
			}

			if (Last_ == null) {
				Console.WriteLine("List error. Last is empty, Head is not null");
				return false;
			}

			Last_.Next_ = node;
			node.Previous_ = Last_;
			Last_ = node;

			return true;
		}

		public IEnumerator<T> GetEnumerator() {
			var node = Head_;
			while(node != null) {
				yield return node.Value_;
				node = node.Next_;
			}
		}

		// IEnumerator<T> IEnumerable<T>.GetEnumerator() => GetEnumerator();
		IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
	}
}
