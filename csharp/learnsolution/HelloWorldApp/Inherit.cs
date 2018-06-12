using System;

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
}
