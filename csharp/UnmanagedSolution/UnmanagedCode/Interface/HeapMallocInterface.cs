using System;
using System.Runtime.InteropServices;

namespace UnmanagedCode.Interface {
	class HeapMallocInterface {
		unsafe public static IntPtr HeapAllocate(int size) {
				if (size <= 0) {
					return IntPtr.Zero;
				}

				return Marshal.AllocHGlobal(size);
		}

		public static void HeapFree(IntPtr pointer) {
				Marshal.FreeHGlobal(pointer);
		}
	}
}
