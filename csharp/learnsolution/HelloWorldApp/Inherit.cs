using System;
using System.Runtime.InteropServices;

namespace HelloWorldApp {
	abstract class Entity {
		public int HP {get; set;}
		public int MP {get; set;}

		abstract public string TellSelf();
	}

	class PlayerAvatar: Entity {
		public int[] Skills {get; set;}

		public override string TellSelf() => "I am Player";

		public PlayerAvatar(): base() {
		}
	}

	class MonsterAvatar: Entity {
		public void OnDemage(int damage) {
			HP -= damage;
		}

		// hide base method
		// new public string TellSelf() => "I am Monster";
		
		public override string TellSelf() => "I am Monster";
	}

	public interface IBankAccount {
		decimal Currency {get;}
		bool Withdraw(decimal delta);
		bool PayIn(decimal delta);
		string OutPutInfo();
	}

	public class TestBank: IBankAccount {
		private decimal _balance;

		public decimal Currency {
			get {
				return _balance;
			}
		}

		public bool Withdraw(decimal delta) {
			if (delta <= 0) {
				return false;
			}

			if (delta > Currency) {
				return false;
			}

			_balance -= delta;
			return true;
		}

		public bool PayIn(decimal delta) {
			if (delta <= 0) {
				return false;
			}

			_balance += delta;
			return true;
		}

		virtual public string OutPutInfo() => $"Balance is ${Currency}";
	}

	public class TestBank2: TestBank {
		override public string OutPutInfo() => $"Balance is ${Currency, 6:C}";
	}

	unsafe class UnsafeTest {
		public void SizeofTest() {
			int *p_int = null;
			double *p_double = null;

			Console.WriteLine($"sizeof int pointer is {sizeof(int *)}, sizeof double pointer is {sizeof(double *)}");

			// start pos
			Console.WriteLine($"int pointer starts pos 0x{(ulong)p_int:X}");
			Console.WriteLine($"double pointer starts pos 0x{(ulong)p_double:X}");

			p_int += 1;
			p_double += 1;
			Console.WriteLine($"int pointer next pos 0x{(ulong)p_int:X}");
			Console.WriteLine($"double pointer next pos 0x{(ulong)p_double:X}");
		}
		
		public static void* NewHeap(int allocate_size) {
			return Marshal.AllocHGlobal(allocate_size).ToPointer();
		}

		public static void FreeHeap(void *pointer) {
			Marshal.FreeHGlobal((IntPtr)pointer);
		}
	}

	// static unsafe class Unmanaged
	// {
	// 	public static void* New<T>(int elementCount) 
	// 	where T : struct
	// 	{
	// 		return Marshal.AllocHGlobal(sizeof(T) * elementCount).ToPointer();
	// 	}

	// 	public static void* NewAndInit<T>(int elementCount)
	// 	where T : struct
	// 	{
	// 		int newSizeInBytes = sizeof(T) * elementCount;
	// 		byte* newArrayPointer = (byte*) Marshal.AllocHGlobal(newSizeInBytes).ToPointer();

	// 		for (int i = 0; i < newSizeInBytes; i++)
	// 			*(newArrayPointer + i) = 0;

	// 		return (void*) newArrayPointer;
	// 	}

	// 	public static void Free(void* pointerToUnmanagedMemory)
	// 	{
	// 		Marshal.FreeHGlobal(new IntPtr(pointerToUnmanagedMemory));
	// 	}

	// 	public static void* Resize<T>(void* oldPointer, int newElementCount) 
	// 	where T : struct
	// 	{
	// 		return (Marshal.ReAllocHGlobal(new IntPtr(oldPointer),
	// 			new IntPtr(sizeof(T)) * newElementCount))).ToPointer();
	// 	}
	// }
}
