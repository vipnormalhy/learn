using System;

namespace UnmanagedCode.Interface {
	class UnmanagedResource: IDisposable {
		private IntPtr _students = IntPtr.Zero;
		private bool _disposed = false;

		~UnmanagedResource() {
			Dispose(false);
			Console.WriteLine("function \"Finalize\" called");
		}

		public virtual void Dispose() {
			Console.WriteLine("function \"Dispose\" called!");
			Dispose(true);
			GC.SuppressFinalize(this);
		}

		protected virtual void Dispose(bool disposing) {
			if (_disposed) {
				return;
			}

			// explicit
			if (disposing) {
			}

			if (_students != IntPtr.Zero) {
				HeapMallocInterface.HeapFree(_students);
			}

			_disposed = true;
		}

		private int CalculateStudentMemory() {
			return sizeof(int) + sizeof(char) * 20;
		}

		public void InitStudentsContainer(int student_cnt) {
			if (_students != IntPtr.Zero) {
				Console.WriteLine("Reallocate students container");
				return;
			}

			_students = HeapMallocInterface.HeapAllocate(student_cnt * CalculateStudentMemory());
			if (_students == IntPtr.Zero) {
				Console.WriteLine("failed to allocate memory for students");
				return;
			}
		}
	}
}
